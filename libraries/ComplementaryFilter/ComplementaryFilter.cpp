#include "ComplementaryFilter.h"

void ComplementaryFilter::UpdateWithFilter(int accelXInput, int accelYInput, int gyroXInput, int gyroYInput)
{
	LowPassFilter(accelXInput, accelYInput);
	HighPassFilter(gyroXInput, gyroYInput);
	pitch = (1 - ALPHA) * (pitch + filteredGyroX * DT) + (ALPHA * filteredAccX);
	roll = (1 - ALPHA) * (roll + filteredGyroY * DT) + (ALPHA * filteredAccY);
}

void ComplementaryFilter::LowPassFilter(int x, int y) // accelerometer values
{
	filteredAccX = (1 - ALPHA) * x + (ALPHA * filteredAccX);
	filteredAccY = (1 - ALPHA) * y + (ALPHA * filteredAccY);
}

void ComplementaryFilter::HighPassFilter(int x, int y) // gyroscope values
{
	filteredGyroX = (1 - ALPHA) * filteredGyroX + (1 - ALPHA) * (x - lastGyroXInput);
	filteredGyroY = (1 - ALPHA) * filteredGyroY + (1 - ALPHA) * (y - lastGyroYInput);
	lastGyroXInput = x;
	lastGyroYInput = y;
}

// https://sites.google.com/site/myimuestimationexperience/filters/complementary-filter