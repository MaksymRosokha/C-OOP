#include <cmath>

class PlaneFigure
{
private:
	float segmentLength1;
	float segmentLength2;
	float segmentLength3;

public:
	PlaneFigure() {
		this->segmentLength1 = 0;
		this->segmentLength2 = 0;
		this->segmentLength3 = 0;
	}

	PlaneFigure(float segmentLength1, float segmentLength2, float segmentLength3) {
		this->segmentLength1 = segmentLength1;
		this->segmentLength2 = segmentLength2;
		this->segmentLength3 = segmentLength3;
	}

	~PlaneFigure() {
		this->segmentLength1 = 0;
		this->segmentLength2 = 0;
		this->segmentLength3 = 0;
	}

	float getSegmentLength1() {
		return this->segmentLength1;
	}

	float getSegmentLength2() {
		return this->segmentLength2;
	}

	float getSegmentLength3() {
		return this->segmentLength3;
	}

	void setSegmentLength1(float length) {
		this->segmentLength1 = length;
	}

	void setSegmentLength2(float length) {
		this->segmentLength2 = length;
	}

	void setSegmentLength3(float length) {
		this->segmentLength3 = length;
	}

	bool isTriangle() {
		if ((getSegmentLength1() + getSegmentLength2()) > getSegmentLength3() &&
			(getSegmentLength1() + getSegmentLength3()) > getSegmentLength2() &&
			(getSegmentLength2() + getSegmentLength3()) > getSegmentLength1()) {
			return true;
		}
		return false;
	}

	bool isRightTriangle() {
		float aPow = pow(getSegmentLength1(), 2);
		float bPow = pow(getSegmentLength2(), 2);
		float cPow = pow(getSegmentLength3(), 2);
		if (aPow + bPow == cPow ||
			aPow + cPow == bPow ||
			bPow + cPow == aPow) {
			return true;
		}
		return false;
	}

	float getPerimeter() {
		if (isTriangle()) {
			return getSegmentLength1() + getSegmentLength2() + getSegmentLength3();
		}
		return 0.0;
	}

	float getArea() {
		if (isTriangle()) {
			float s = (getSegmentLength1() + getSegmentLength2() + getSegmentLength3()) / 2;
			return sqrt(s *
				(s - getSegmentLength1()) *
				(s - getSegmentLength2()) *
				(s - getSegmentLength3()));
		}
		return 0.0;
	}
};

