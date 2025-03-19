#include <iostream>
#include <cmath>

using namespace std;

struct Point {
	float x, y;
};

void completePoints(Point* points, int amount);
void printPoints(Point* points, int amount);
float getAverageDistance(Point* points, int amount);
float getCircleRadius(Point* points, int amount);

int main() {
	int amount = 0;
	cout << "Enter the amount of points: ";
	cin >> amount;
	cout << endl;

	Point* points = new Point[amount];
	completePoints(points, amount);

	cout << "- - - Information about points - - -" << endl;
	printPoints(points, amount);
	cout << "Average distance of points to coordinate (0,0) is: " << getAverageDistance(points, amount) << endl;
	cout << "Circle radius starts from coordinate (0,0) is: " << getCircleRadius(points, amount) << endl;

	delete points;
	return 0;
}

void completePoints(Point* points, int amount) {
	float x, y;

	for (int i = 1; i <= amount; i++) {
		cout << "For the " << i << " enter X: ";
		cin >> x;
		cout << "For the " << i << " enter Y: ";
		cin >> y;
		cout << endl;
		points->x = x;
		points->y = y;
		points++;
	}
}

void printPoints(Point* points, int amount) {
	for (int i = 1; i <= amount; i++) {
		cout << "Point" << i << "(" << points->x << ", " << points->y << ");" << endl;
		points++;
	}
}

float getAverageDistance(Point* points, int amount) {
	float averageDistance, sumPoints = 0;
	Point* lastPoint = points + amount;

	while(points < lastPoint) {
		sumPoints += sqrt(pow(points->x, 2) + pow(points->y, 2));
		points++;
	}

	averageDistance = sumPoints / amount;

	return averageDistance;
}

float getCircleRadius(Point* points, int amount) {
	float maxRadius = sqrt(pow(points->x, 2) + pow(points->y, 2));
	points++;

	for (int i = 1; i < amount; i++) {
		float tempRadius = sqrt(pow(points->x, 2) + pow(points->y, 2));
		if (maxRadius < tempRadius) {
			maxRadius = tempRadius;
		}
		points++;
	}

	return maxRadius;
}