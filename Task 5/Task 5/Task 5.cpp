#include <iostream>
#include <iomanip>
#include "PlaneFigure.h"

using namespace std;

void printPlaneFigure(PlaneFigure p);

int main()
{
    float segment1 = 2.72;
    float segment2 = 5.31;
    float segment3 = 6.59;

    PlaneFigure triangle1;
    triangle1.setSegmentLength1(segment1);
    triangle1.setSegmentLength2(segment2);
    triangle1.setSegmentLength3(segment3);

    segment1 = 3.00;
    segment2 = 4.00;
    segment3 = 5.00;
    PlaneFigure triangle2(segment1, segment2, segment3);

    segment1 = 1.51;
    segment2 = 2.10;
    segment3 = 3.94;
    PlaneFigure triangle3(segment1, segment2, segment3);
    
    printPlaneFigure(triangle1);
    printPlaneFigure(triangle2);
    printPlaneFigure(triangle3);
    
    return 0;
}

void printPlaneFigure(PlaneFigure p) {
    cout << fixed << setprecision(2) << "Segments: " << 
        p.getSegmentLength1() << ", " <<
        p.getSegmentLength2() << ", " << 
        p.getSegmentLength3() << endl;
    cout << "Is it a triangle? " << (p.isTriangle() ? "Yes" : "No") << endl;
    cout << "Is it a right triangle? " << (p.isRightTriangle() ? "Yes" : "No") << endl;
    cout << fixed << setprecision(2) << "Perimeter: " << p.getPerimeter() << endl;
    cout << fixed << setprecision(2) << "Area: " << p.getArea() << endl;
    cout << endl;
}