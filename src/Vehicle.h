const size_t MAX_VEHICLE_LENGTH = 32;

struct Vehicle
{
    char LicensePlate[MAX_VEHICLE_LENGTH];
    unsigned long ArrivalTime;
};

const Vehicle EMPTY_VEHICLE = { '\0', 0 };