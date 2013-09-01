#include "ComplementaryFilter.h"
#include "Arduino.h"

ComplementaryFilter::ComplementaryFilter()
{
	lastGyroXInput = 0;
	lastGyroYInput = 0;
}

void ComplementaryFilter::UpdateWithFilter(int gXInput, int gYInput, int aXInput, int aYInput)
{
	LowPassFilter(aXInput, aYInput);
	HighPassFilter(gXInput, gYInput);
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
	filteredAccX = (1 - ALPHA) * (float)x + (ALPHA * filteredAccX);
	filteredAccY = (1 - ALPHA) * (float)y + (ALPHA * filteredAccY);
}

// https://sites.google.com/site/myimuestimationexperience/filters/complementary-filter