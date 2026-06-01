#include <Arduino.h>
#include "ParkingHandlerSettings.h"
#include "Vehicle.h"

class ParkingHandler
{
    private:
        ParkingHandlerSettings _Settings;
        Vehicle* _Array;
        size_t _Lenght;
        unsigned long _LastResizeTime;

        float _CalculatePrice(unsigned long arrivalTime)
        {
            unsigned long currentTime = millis();
            unsigned long duration = currentTime - arrivalTime;

            return (duration / 60000.0f) * _Settings.PricePerMinute;
        }

        // Returns true if the vehicle was added successfully,
        // false if the parking lot is full
        bool _Add(char c[MAX_VEHICLE_LENGTH])
        {
            if (_Lenght < _Settings.MaxVehicles)
            {
                Vehicle vehicle = EMPTY_VEHICLE;
                strncpy(vehicle.LicensePlate, c, MAX_VEHICLE_LENGTH);
                vehicle.ArrivalTime = millis();

                _Array[_Lenght] = vehicle;
                _Lenght++;
                
                return true;
            }
            return false;
        }
        
        // Returns the price if the vehicle was removed,
        // -1 if the vehicle was not found
        float _Remove(char c[MAX_VEHICLE_LENGTH])
        {
            float price = -1;

            for (size_t i = 0; i < _Lenght; i++)
            {
                // Check if the license plate matches
                if (strncmp(_Array[i].LicensePlate, c, MAX_VEHICLE_LENGTH) == 0)
                {
                    price = _CalculatePrice(_Array[i].ArrivalTime);

                    // shift all the vehicles after the removed one to the left
                    for (size_t j = i; j < _Lenght - 1; j++)
                    {
                        _Array[j] = _Array[j + 1];
                    }
                    _Lenght--;
                    _Array[_Lenght] = EMPTY_VEHICLE;
                    break;
                }
            }
            return price;
        }

    public:
        ParkingHandler(ParkingHandlerSettings settings = ParkingHandlerSettings())
        : _Settings(settings)
        {
            _Lenght = 0;
            _LastResizeTime = 0;
            _Array = new Vehicle[_Settings.MaxVehicles];
            
            // Fill the array with empty vehicles
            for (size_t i = 0; i < _Settings.MaxVehicles; i++)
            {
                _Array[i] = EMPTY_VEHICLE;
            }
        }
        
        // Returns -1 if the vehicle was added,
        // the price if it was removed,
        // and -2 if the parking lot is full
        float HandleVehicle(char c[MAX_VEHICLE_LENGTH])
        {
            float price = _Remove(c);

            if (price == -1)
            {
                if (_Add(c))
                {
                    return -1; // Vehicle added successfully
                }
                else
                {
                    return -2; // Parking lot is full
                }
            }
            return price;
        }

        ~ParkingHandler()
        {
            delete[] _Array;
        }
};