#ifndef ComplementaryFilter_h
#define ComplementaryFilter_h

#define ALPHA 0.6
#define DT 0.074

class ComplementaryFilter
{
	public:
		void update_filter(int acc_x_input, int acc_y_input, int gyro_x_input, int gyro_y_input);
		float get_pitch() { return pitch; }
		float get_roll() { return -roll; }
	private:
		float pitch;
		float roll;
		float filtered_acc_x, filtered_acc_y;
		float filtered_gyro_x, filtered_gyro_y;
		float last_gyro_x_input, last_gyro_y_input;
		void low_pass_filter(int x, int y);
		void high_pass_filter(int x, int y);
};

#endif

// https://sites.google.com/site/myimuestimationexperience/filters/complementary-filter