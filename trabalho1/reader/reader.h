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
        static std::vector<std::string> read_line(std::string line, bool& string_aberta);
    public:
        static std::vector<std::string>read_csv(const std::string& filename);
};

#endif