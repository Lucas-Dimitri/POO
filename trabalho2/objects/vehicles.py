import re

def main():
    newVehicle = Vehicles(2, 2, ' 11111111111111111 ')
    print(newVehicle)

class Vehicles:
    
    instances = []
    
    def __init__(self, weightCapacity=0, volumeCapacity=0, vin=0):
        self.weightCapacity = weightCapacity
        self.volumeCapacity = volumeCapacity
        self.vin = vin # Vehicle identification number
        Vehicles.instances.appen(self)
    
    def __str__(self):
        return f"weight capacity: {self.__weightCapacity}\nvolume capacity: {self.__volumeCapacity}\nvin: {self.vin}"
    
    ###########################################
    ########### getters and setters ###########
    ###########################################
    
    @property
    def weightCapacity(self):
        return self.__weightCapacity
    
    @weightCapacity.setter
    def weightCapacity(self, value):
        if float(value) < 0:
            raise ValueError("A vehicle weight capacity can't be less than zero.")
        self.__weightCapacity = float(value)
        
    @property
    def volumeCapacity(self):
        return self.__volumeCapacity
    
    @volumeCapacity.setter
    def volumeCapacity(self, value):
        if float(value) < 0:
            raise ValueError("A vehicle volume capacity can't be less than zero.")
        self.__volumeCapacity = float(value)
        
    @property
    def vin(self):
        return self.__vin
    
    @vin.setter
    def vin(self, value):
        pattern = r'^[A-HJ-NPR-Z0-9]{17}$'
        vin_regex = re.compile(pattern)
        if not re.fullmatch(vin_regex, value.strip()):
            raise ValueError("The VIN you passed doesn't have the correct format.")
        self.__vin = value.strip()

class Truck(Vehicles):
    @property
    def weightCapacity(self):
        return self.__weightCapacity
    
    @weightCapacity.setter
    def weightCapacity(self, value):
        if float(value) < 0:
            raise ValueError("A truck weight capacity can't be less than zero.")
        self.__weightCapacity = float(value)

if "__main__" == __name__:
    main()