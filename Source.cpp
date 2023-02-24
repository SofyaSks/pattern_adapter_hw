#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class DollarSensor {

public:
	float getDollarPrice() {
		float d = 120.54;
		return d;
	}
};

class Sensor {
public:
	 virtual ~Sensor() {}
	 virtual float getPrice() = 0;
};

class Adapter : public Sensor {

public:
	Adapter(DollarSensor* d) : d_sensor(d) {}
	~Adapter() {
		delete d_sensor;
	}
	float getPrice () {
		return (d_sensor->getDollarPrice() * 75.57);
	}

private:
	DollarSensor* d_sensor;
};




int main() {

	Sensor* s = new Adapter(new DollarSensor);
	cout << "Price in rubbles: " << s->getPrice() << endl;
	delete s;

	return 0;
}