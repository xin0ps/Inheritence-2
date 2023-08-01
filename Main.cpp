#include <iostream>
#include <stack>
using namespace std;

class about
{
private:
	static int nextId;
	int id = 0;
	string model = "";
	string vendor = "";
	string engine = "";
public:
	about()
	{
		id = nextId++;
	}

	about(const string _model, const string _vendor, const string _engine) : model(_model), vendor(_vendor), engine(_engine)
	{
		id = nextId++;
	}

	int getId() const {
		return id;
	}

	string getModel() const {
		return model;
	}

	void setModel(const string& _model) {
		model = _model;
	}

	string getVendor() const {
		return vendor;
	}

	void setVendor(const string& _vendor) {
		vendor = _vendor;
	}

	string getEngine() const {
		return engine;
	}

	void setEngine(const string& _engine) {
		engine = _engine;
	}
};

int about::nextId = 0;

class Car : virtual public about
{
private:
	string hasSpoiler = "";
public:
	Car() = default;
	Car(const string _model, const string _vendor, const string _engine, const string _spoiler) : about(_model, _vendor, _engine)
	{
		this->hasSpoiler = _spoiler;
	}
	string getHasSpoiler() const {
		return hasSpoiler;
	}

	void setHasSpoiler(const string& _hasSpoiler) {
		hasSpoiler = _hasSpoiler;
	}
};

class Ship : virtual public about
{
private:
	string hasSail = "";
public:
	Ship() = default;
	Ship(const string _model, const string _vendor, const string _engine, const string _sail) : about(_model, _vendor, _engine)
	{
		this->hasSail = _sail;
	}
	string getHasSail() const {
		return hasSail;
	}

	void setHasSail(const string& _hasSail) {
		hasSail = _hasSail;
	}
};

class Airplane : virtual public about
{
private:
	int passengerCapacity = 0;
	int engineCount = 0;
public:
	Airplane() = default;
	Airplane(const string _model, const string _vendor, const string _engine, int _count, int _passenger) : about(_model, _vendor, _engine)
	{
		this->engineCount = _count;
		this->passengerCapacity = _passenger;
	}
	int getPassengerCapacity() const {
		return passengerCapacity;
	}

	void setPassengerCapacity(int _passengerCapacity) {
		passengerCapacity = _passengerCapacity;
	}

	int getEngineCount() const {
		return engineCount;
	}

	void setEngineCount(int _engineCount) {
		engineCount = _engineCount;
	}
};

class VehicleDepot
{
private:
	stack<Car> cars;
	stack<Ship> ships;
	stack<Airplane> airplanes;

public:
	void addCar(const Car& car)
	{
		cars.push(car);
	}

	void addShip(const Ship& ship)
	{
		ships.push(ship);
	}

	void addAirplane(const Airplane& airplane)
	{
		airplanes.push(airplane);
	}

	void showAllVehicles()
	{
		cout << "Cars:\n";
		while (!cars.empty())
		{
			Car car = cars.top();
			cout << "ID: " << car.getId() << ", Model: " << car.getModel() << ", Vendor: " << car.getVendor() << ", Engine: " << car.getEngine() << ", Spoiler: " << car.getHasSpoiler() << endl;
			cars.pop();
		}

		cout << "\nShips:\n";
		while (!ships.empty())
		{
			Ship ship = ships.top();
			cout << "ID: " << ship.getId() << ", Model: " << ship.getModel() << ", Vendor: " << ship.getVendor() << ", Engine: " << ship.getEngine() << ", Sail: " << ship.getHasSail() << endl;
			ships.pop();
		}

		cout << "\nAirplanes:\n";
		while (!airplanes.empty())
		{
			Airplane airplane = airplanes.top();
			cout << "ID: " << airplane.getId() << ", Model: " << airplane.getModel() << ", Vendor: " << airplane.getVendor() << ", Engine: " << airplane.getEngine() << ", Engine Count: " << airplane.getEngineCount() << ", Passenger Capacity: " << airplane.getPassengerCapacity() << endl;
			airplanes.pop();
		}
	}
};

int main()
{
	VehicleDepot depot;

	Car car1("Model 1", "Vendor 1", "Engine 1", "Yes");
	depot.addCar(car1);

	Car car2("Model 2", "Vendor 2", "Engine 2", "No");
	depot.addCar(car2);

	Ship ship1("Model 3", "Vendor 3", "Engine 3", "Yes");
	depot.addShip(ship1);

	Ship ship2("Model 4", "Vendor 4", "Engine 4", "No");
	depot.addShip(ship2);

	Airplane airplane1("Model 5", "Vendor 5", "Engine 5", 4, 200);
	depot.addAirplane(airplane1);

	Airplane airplane2("Model 6", "Vendor 6", "Engine 6", 2, 100);
	depot.addAirplane(airplane2);

	depot.showAllVehicles();

	return 0;
}
