import client

def main():
    newClient = client.Client('lucas', '11122233344', [10, 10], '(55) 99999-0000', 'lucas@gmail.com')
    newOrder = Order(newClient, [20,20], [30, 30], 5.5, 30.3, True)
    print(newOrder)

class Order:
    
    highPriorityList = []
    lowPriorityList = []
    def __init__(self, client, pickupAdress, deliveryAdress, weight, volume, priority):
        self.client = client
        self.pickupAdress = pickupAdress
        self.deliveryAdress = deliveryAdress
        self.weight = weight
        self.volume = volume
        self.priority = priority
        
        if self.priority == True:
            Order.highPriorityList.append(self)
        else:
            Order.lowPriorityList.append(self)
        
    def __str__(self):
        return f"Client Information:\n{self.client}\n\n######################\n\nOrder Information:\nPickup Adress: \n\tLatitude: {self.pickupAdress[0]}\n\tLongitude: {self.pickupAdress[1]}\nDelivery Adress:\n\tLatitude: {self.deliveryAdress[0]}\n\tLongitude: {self.deliveryAdress[1]}\nWeight: {self.weight}\nVolume: {self.volume}\nPriority: {self.priority}"
    
    @property
    def client(self):
        return self.__client
    
    @client.setter
    def client(self, value):
        if isinstance(self, client.Client):
            raise ValueError("You didn't pass a valid client")
        self.__client = value
    
    @property
    def pickupAdress(self):
        return self.__pickupAdress
    
    @pickupAdress.setter
    def pickupAdress(self, value):
        if value[0] < -90 and value[0] > 90:
            raise ValueError(f"You didn't pass a valid latitude:{value[0]}")
        if value[1] < -180 and value[1] > 180:
            raise ValueError(f"You didn't pass a valid longitude:{value[1]}")
        self.__pickupAdress = value
        
    @property
    def deliveryAdress(self):
        return self.__deliveryAdress
    
    @deliveryAdress.setter
    def deliveryAdress(self, value):
        if value[0] < -90 and value[0] > 90:
            raise ValueError(f"You didn't pass a valid latitude:{value[0]}")
        if value[1] < -180 and value[1] > 180:
            raise ValueError(f"You didn't pass a valid longitude:{value[1]}")
        self.__deliveryAdress = value
        
    @property
    def weight(self):
        return self.__weight
    
    @weight.setter
    def weight(self, value):
        if float(value) < 0:
            raise ValueError("An order weight can't be less than zero.")
        self.__weight = float(value)
        
    @property
    def volume(self):
        return self.__volume
    
    @volume.setter
    def volume(self, value):
        if float(value) < 0:
            raise ValueError("An order volume can't be less than zero.")
        self.__volume = float(value)
        
    @property
    def priority(self):
        return self.__priority
    
    @priority.setter
    def priority(self, value):
        if value != True and value != False:
            raise ValueError("An order priority needs to be True or False.")
        self.__priority = value
    
if "__main__" == __name__:
    main()