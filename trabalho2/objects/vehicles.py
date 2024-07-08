import re

def main():
    newCar1 = Car(1000, 100, "1GCEK14H2JZ207125", [10,10], True)
    newCar2 = Car(2000, 100, "2GCEK14H2JZ207125",[20,20], True)
    newCar3 = Car(3000, 100, "3GCEK14H2JZ207125",[21,21], True)
    for car in Car.carList:
        print(car)
        print('')

class Vehicles:
    
    vehicleList = []
    
    def __init__(self, weightCapacity=0, volumeCapacity=0, vin='',location=[0,0], availability=True):
        self.weightCapacity = weightCapacity
        self.volumeCapacity = volumeCapacity
        self.vin = vin # Vehicle identification number
        self.location = location
        self.availability = availability
        Vehicles.vehicleList.append(self)
    
    def __str__(self):
        return f"weight capacity: {self.weightCapacity}\nvolume capacity: {self.volumeCapacity}\nvin: {self.vin}\navailability: {self.availability}"
    
    def __eq__(self, other):
        return self.vin == other.vin
    
    def __ne__(self, other):
        return not self.__eq__(other)

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
        
    @property
    def location(self):
        return self.__location
    
    @location.setter
    def location(self, value):
        if value[0] < -90 or value[0] > 90:
            raise ValueError(f"You didn't pass a valid latitude:{value[1]}")
        if value[1] < -180 and value[1] > 180:
            raise ValueError(f"You didn't pass a valid longitude:{value[1]}")
        self.__location = value
        
    @property
    def availability(self):
        return self.__availability
    
    @availability.setter
    def availability(self, value):
        if value != True and value != False:
            raise ValueError("Availability needs to be True or False")
        self.__availability = value
        
    #####################
    # Funções da classe #
    #####################
    
    @classmethod
    def adicionar_elemento(cls, elemento):
        cls.vehicleList.append()

class Truck(Vehicles):
    
    truckList = []
    
    def __init__(self, weightCapacity=0, volumeCapacity=0, vin='',location=[0,0], availability=True):
        super().__init__(weightCapacity, volumeCapacity, vin, location, availability)
        Truck.truckList.append(self)
        
    @classmethod
    def removeFromList(vehicleVin):
        for truck in Truck.truckList:
            if truck.vin == vehicleVin:
                Truck.truckList.remove(truck)
                break
        
    @property
    def weightCapacity(self):
        return self.__weightCapacity
    
    @weightCapacity.setter
    def weightCapacity(self, value):
        if float(value) < 6001:
            raise ValueError("A truck weight capacity can't be less than 6001.")
        self.__weightCapacity = float(value)
        
class Minivan(Vehicles):
    
    minivanList = []
    
    @classmethod
    def removeFromList(vehicleVin):
        for minivan in Minivan.minivanList:
            if minivan.vin == vehicleVin:
                Minivan.minivanList.remove(minivan)
                break
    
    def __init__(self, weightCapacity=0, volumeCapacity=0, vin='',location=[0,0], availability=True):
        super().__init__(weightCapacity, volumeCapacity, vin, location, availability)
        Minivan.minivanList.append(self)
        
    @property
    def weightCapacity(self):
        return self.__weightCapacity
    
    @weightCapacity.setter
    def weightCapacity(self, value):
        if float(value) >= 6000 or float(value) < 3000:
            raise ValueError("A Minivan weight capacity can't be less than 3001 and more than 6000.")
        self.__weightCapacity = float(value)
        
class Car(Vehicles):
    
    carList = []
    
    @classmethod
    def removeFromList(vehicleVin):
        for car in Car.carList:
            if car.vin == vehicleVin:
                Car.carList.remove(car)
                break
    
    def __init__(self, weightCapacity=0, volumeCapacity=0, vin='',location=[0,0], availability=True):
        super().__init__(weightCapacity, volumeCapacity, vin, location, availability)
        
        Car.carList.append(self)
    
    @property
    def weightCapacity(self):
        return self.__weightCapacity
    
    @weightCapacity.setter
    def weightCapacity(self, value):
        if float(value) > 3000 or float(value) < 1:
            raise ValueError("A Car weight capacity can't be less than 1 and more than 2999.")
        self.__weightCapacity = float(value)

if "__main__" == __name__:
    main()