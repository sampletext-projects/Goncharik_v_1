#include <iostream>
#include <conio.h>
#include <math.h>
#include <iomanip>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Connection
{
protected:
	virtual double get_kbps()
	{
		return 0;
	}

public:
	double get_download_time(double file_size_gigs)
	{
		double speed = get_kbps();
		return file_size_gigs * 1024 * 1024 * 8 / speed; // gigs to gbit is * 8
	}
};

class DialUp : public Connection
{
	double get_kbps()
	{
		return 56;
	}
};

class ADSL : public Connection
{
	double get_kbps()
	{
		return 10. * 1024 / 8; // 10 mbit
	}
};

class G4 : public Connection
{
	double get_kbps()
	{
		return 100. * 1024 / 8; // 100 mbit
	}
};

int main()
{
	setlocale(LC_ALL, "russian");

	double file = 2;

	DialUp dialup = DialUp();
	ADSL adsl = ADSL();
	G4 g4 = G4();

	cout << "File Size is " << file << " Gb\n";

	double dialup_time = dialup.get_download_time(file);
	double adsl_time = adsl.get_download_time(file);
	double g4_time = g4.get_download_time(file);
	cout << "Dial-UP: " << dialup_time << " s\n";
	cout << "ADSL: " << adsl_time << " s\n";
	cout << "4G: " << g4_time << " s\n";
	if (dialup_time < adsl_time && dialup_time < g4_time)
	{
		cout << "Fastest is dial-up\n";
	}
	else if (adsl_time < dialup_time && adsl_time < g4_time)
	{
		cout << "Fastest is adsl\n";
	}
	else
	{
		cout << "Fastest is 4G\n";
	}

	system("pause");
	return 0;
}
