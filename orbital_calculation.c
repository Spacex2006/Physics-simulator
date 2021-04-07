 /*PROGRAM Orbit

    General Description:
    ====================
        Orbit computes the orbit of a small mass about a much larger mass, 
        or it can be considered as computing the motion of the reduced mass 
        about the center of mass.
 
        "An Introduction to Modern Astrophysics", Appendix J
        Bradley W. Carroll and Dale A. Ostlie
        Second Edition, Addison Wesley, 2007
 
        Weber State University
        Ogden, UT
        modastro@weber.edu
 -------------------------------------------------------------------*/

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Constant.h"

using namespace std;

int main()
{
    using ModAstroConstants::G;
    using ModAstroConstants::AU;
    using ModAstroConstants::M_Sun;
    using ModAstroConstants::pi;
    using ModAstroConstants::two_pi;
    using ModAstroConstants::yr;
    using ModAstroConstants::radians_to_degrees;
    using ModAstroConstants::eps_dp;

//Open the output file
    char xpause;
    ofstream outdata;
    outdata.open("Orbit.txt", ios::out);
    if (outdata.fail()){
        cout << " Unable to open Orbit.txt --- Terminating calculation"  
            << "\n\n"
            << "Enter any character to quit: ";
        cin  >> xpause;
        exit(1);
    }

//Write introductory information for user
    cout <<  "     Orbit computes the orbit of a small mass about a much larger mass.\n" << endl;

    cout << "               Details of the code are described in: \n"
         << "               An Introduction to Modern Astrophysics \n"
         << "               Bradley W. Carroll and Dale A. Ostlie \n"
         << "                       Addison Wesley \n"
         << "                       copyright 2007\n\n" << endl;

//Get input from user
    double Mstrsun;
    cout << " Enter the mass of the parent star (in solar masses):  ";
    cin  >> Mstrsun;

    double aAU;
    cout << " Enter the semimajor axis of the orbit (in AU):        ";
    cin  >> aAU;

    double e;
    cout << " Enter the orbital eccentricity:                       ";
    cin  >> e;

//Convert entered values to conventional SI units
    double Mstar = Mstrsun*M_Sun;
    double a = aAU*AU;

//Calculate the orbital period in seconds using Kepler's Third Law (Eq. 2.37)
    double P = sqrt(4*pi*pi*a*a*a/(G*Mstar));

//Convert the orbital period to years and print the result
    cout << fixed << showpoint << setprecision(3) 
        << "\n The period of this orbit is " << P/yr << " yr" << endl;

//Enter the number of time steps and the time interval to be printed
    unsigned int n;
    cout << "\n\n"
         << "Please enter the number of time steps to be calculated and the \n"
         << "frequency with which you want time steps printed. \n\n"
         << "Note that taking too large a time step during the calculation \n"
         << "will produce inaccurate results. \n\n"
         << "Enter the number of time steps desired for the calculation: ";
    cin  >> n;
    n++;   //increment to include t=0 (initial) point
    
    unsigned kmax;
    cout << "\n\n"
         << "How often do you want time steps to be printed? \n"
         << "             1 = every time step \n"
         << "             2 = every second time step \n"
         << "             3 = every third time step \n"
         << "                         etc. \n\n"
         << "Frequency: ";
    cin  >> kmax;

//Print header information for output file
    outdata << fixed << showpoint << right << setprecision(3)
            << "                          Elliptical Orbit Data\n\n"
            << "                          Mstar = " << setw(10) << Mstrsun << " Msun\n"
            << "                          a     = " << setw(10) << aAU     << " AU\n"
            << "                          P     = " << setw(10) << P/yr    << " yr\n"
            << "                          e     = " << setw(10) << e       << endl;
    
    outdata << "\n\n"
            << "        t (yr)            r (AU)            theta (deg)            x (AU)            y (AU)\n"
            << "        ------            ------            -----------            ------            ------"
            << endl;

//Initialize print counter, angle, elapsed time, and time step.
    unsigned int    k = 1;              //printer counter
    double          theta = 0;          //angle from direction to perihelion (radians)
    double          t = 0;              //elapsed time (s)
    double          dt = P/(n-1);       //time step (s)
    double          delta = 2*eps_dp;   //allowable error at end of period

    double          r, LoM, dtheta;     //declare variables used inside loop

//Start main time step loop
    do {

        //Calculate the distance from the principal focus using Eq. (2.3); Kepler's First Law.
        r = a*(1 - e*e)/(1 + e*cos(theta));

        //If time to print, convert to cartesian coordinates.  Be sure to print last point also.
        if (k == 1) {
            outdata << fixed << showpoint << right << setprecision(3)
                << setw(14) << t/yr 
                << setw(18) << r/AU
                << setw(23) << theta*radians_to_degrees
                << setw(18) << r*cos(theta)/AU
                << setw(18) << r*sin(theta)/AU << endl;
        }

        //Prepare for the next time step:  Update the elapsed time.
        t += dt;

        //Calculate the angular momentum per unit mass, L/m (Eq. 2.30).
        LoM = sqrt(G*Mstar*a*(1 - e*e));

        //Compute the next value for theta using the fixed time step by combining
        //    Eq. (2.31) with Eq. (2.32), which is Kepler's Second Law.
        dtheta = LoM/(r*r)*dt;
        theta += dtheta;

        //Reset the print counter if necessary
        k++;
        if (k > kmax || (theta - two_pi)/two_pi > delta || (t - P)/P > delta) k = 1;
    } while ((theta - two_pi) < dtheta/2 && (t - P) < dt/2);

    cout << "\n\nThe calculation is finished and the data are in Orbit.txt\n\n" << endl;

    cout << "Enter any character and hit <enter> to exit:  ";
    cin  >> xpause;

    return 0;
}
