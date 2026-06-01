struct ParkingHandlerSettings
{
    float PricePerMinute;
    size_t MaxVehicles;

    ParkingHandlerSettings(float pricePerMinute = 2.0f, size_t maxVehicles = 100)
    : PricePerMinute(pricePerMinute)
    , MaxVehicles(maxVehicles)
    {}
};