#include "ComplementaryFilter.h"

void ComplementaryFilter::UpdateWithFilter(int gyroXInput, int gyroYInput, int accelYInput, int accelYInput)
{
	LowPassFilter(accelXInput, accelYInput);
	HighPassFilter(gyroXInput, gyroYInput);
	pitch = (1 - ALPHA) * (pitch + filteredGyroX * 0.01) + (ALPHA * filteredAccX);
	roll = (1 - ALPHA) * (roll + filteredGyroY * 0.01) + (ALPHA * filteredAccY);
}

void ComplementaryFilter::HighPassFilter(int x, int y) // gyroscope values
{
	filteredGyroX = (1 - ALPHA) * filteredGyroX + (1 - ALPHA) * (x - lastGyroXInput);
	filteredGyroY = (1 - ALPHA) * filteredGyroY + (1 - ALPHA) * (y - lastGyroYInput);
}

void ComplementaryFilter::LowPassFilter(int x, int y) // accelerometer values
{
	filteredAccX = (1 - ALPHA) * x + (ALPHA * filteredAccX);
	filteredAccY = (1 - ALPHA) * y + (ALPHA * filteredAccY);
}

// https://sites.google.com/site/myimuestimationexperience/filters/complementary-filter