#include "Map.h"









class CarMap


{
    
    
public:
    
    
    CarMap();       // Create an empty car map.
    
    
    
    
    
    
    
    bool addCar(std::string license){
        return arrCars.insert (license,0);
        
    }
    
    
    // If a car with the given license plate is not currently in the map,
    
    
    // and there is room in the map, add an entry for that car recording
    
    
    // that it has 0 gallons of gas in it, and return true.  Otherwise,
    
    
    // make no change to the map and return false.
    
    
    
    
    
    
    
    double gas(std::string license) const{
        double nGals=0;
        if (arrCars.contains(license)){
            arrCars.get(license,nGals);
            return nGals;
        }
        else{
            return -1;
        }
    }
    
    
    // If a car with the given license plate is in the map, return the
    
    
    // number of gallons of gas in its tank; otherwise, return -1.
    
    
    
    
    
    
    
    bool addGas(std::string license, double gallons){
        if (!arrCars.contains(license)||gallons<0){
            return false;
        }
        double fuelLevel=0;
        arrCars.get(license,fuelLevel);
        fuelLevel+=gallons;
        return arrCars.update(license, fuelLevel);
    }
    
    
    // If no car with the given license plate is in the map or if
    
    
    // gallons is negative, make no change to the map and return
    
    
    // false.  Otherwise, increase the number of gallons of gas in the
    
    
    // indicated car by the gallons parameter and return true.
    
    
    
    
    
    
    
    bool useGas(std::string license, double gallons){
        if (!arrCars.contains(license)||gallons<0||gallons>gas()){
            return false;
        }
    }
    
    
    // If no car with the given license plate is in the map or if
    
    
    // gallons is negative or if gallons > gas(), make no change to the
    
    
    // map and return false.  Otherwise, decrease the number of gallons
    
    
    // of gas in the indicated car by the gallons parameter and return
    
    
    // true.
    
    
    
    
    
    
    
    int fleetSize() const;  // Return the number of cars in the CarMap.
    
    
    
    
    
    
    
    void print() const;
    
    
    // Write to cout one line for every car in the map.  Each line
    
    
    // consists of the car's license plate, followed by one space,
    
    
    // followed by the number of gallons in that car's tank.  Write
    
    
    // no other text.
    
    
    
    
    
    
    
private:
    
    Map arrCars;
    // Some of your code goes here.
    
    
};


