#ifndef READER_H
#define READER_H

#include <vector>
#include <fstream>
#include <sstream>


#include "../clients/client.h"
#include "../orders/order.h"
#include "../vehicles/vehicle.h"
#include "../vehicles/truck.h"
#include "../manager/manager.hpp"
#include "../vehicles/manageVehicle.h"

class Reader{
    private:
        std::vector<std::string> split(const std::string &s, char delimiter);
    public:
        std::vector<std::vector<std::string>> read_csv(const std::string& filename);
};

#endif