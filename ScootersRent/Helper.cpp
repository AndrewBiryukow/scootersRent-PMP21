#include "Helper.h"
int  Helper::addCalculatedValuePercent(int value, int percent) {
	return	value + (value * percent / 100);
}
int  Helper::minusCalculatedValuePercent(int value, int percent) {
	return	value - (value * percent / 100);
}