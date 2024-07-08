from vehicles import Vehicles, Car, Truck, Minivan
from order import Order
from client import Client
from geopy.distance import geodesic

def main():
    newCar1 = Car(1000, 100, "1GCEK14H2JZ207125", [10,10], True)
    newCar2 = Car(2000, 100, "2GCEK14H2JZ207125",[20,20], True)
    newCar3 = Car(3000, 100, "3GCEK14H2JZ207125",[21,21], True)
    
    newClient1 = Client('lucas', '11122233344', [10,10], '(55) 99999-0000', 'lucas@gmail.com')
    newClient2 = Client('lucas', '211.222.333-44', [10,10], '+55 55 999990000', 'lucas@gmail.com')
    
    newOrder = Order(newClient1, [20,20], [30, 30], 3000, 30.3, True)
    
    newDelivery = Delivery()
    for vehicle in newDelivery.vehiclesChoosed:
        print(vehicle)

class Delivery:
    numberDelivery = 0
    
    def __init__(self):
        self.order = Delivery.choosingOrder(self)
        self.client = self.order.client
        self.vehiclesChoosed = Delivery.choosingVehicles(self)
    
    @classmethod
    def calcDistance(self, coord1, coord2):
        return geodesic(coord1, coord2).kilometers
    
    def choosingOrder(self):
        Delivery.numberDelivery += 1
        if((Delivery.numberDelivery % 3) == 0):
            return Order.lowPriorityList.pop(0)
        else:
            return Order.highPriorityList.pop(0)
        
    def choosingVehicles(self):
        listOfVehicles = []
        if self.order.weight < 3001:
            listOfVehicles = Car.carList
        elif self.order.weight < 6001:
            listOfVehicles = Minivan.minivanList
        else:
            listOfVehicles = Truck.truckList
            
        vehicleChosed = None
        weightNeeded = self.order.weight
        orderVehicles = []
        while(weightNeeded > 0):
            shortestDistance = -1
            for vehicle in listOfVehicles:
                distance = Delivery.calcDistance(vehicle.location, self.order.pickupAdress)
                if shortestDistance == -1 or distance < shortestDistance:
                    shortestDistance = distance
                    vehicleChosed = vehicle
            weightNeeded = weightNeeded - vehicleChosed.weightCapacity
            orderVehicles.append(vehicleChosed)
            listOfVehicles.remove(vehicleChosed)
            for vehicle in orderVehicles:
                vehicle.availability = False
        return orderVehicles
    
if "__main__" == __name__:
    main()