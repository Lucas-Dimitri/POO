import re
import client

def main():
    newClient = client.Client('lucas', '11122233344', 'Rua xxxx xxxx, xxx', '(55) 99999-0000', 'lucas@gmail.com')
    newOrder = Order(newClient, 'Adress xxx xxx, xx', 'Adress yyy yyy, yy', 5.5, 30.3, True)
    print(newOrder)

class Order:
    def __init__(self, client, pickupAdress, deliveryAdress, weight, volume, priority):
        self.client = client
        self.pickupAdress = pickupAdress
        self.deliveryAdress = deliveryAdress
        self.weight = weight
        self.volume = volume
        self.priority = priority
        
    def __str__(self):
        return f"Client Information:\n{self.client}\n\n######################\n\nOrder Information:\nPickup Adress: {self.pickupAdress}\nDelivery Adress: {self.deliveryAdress}\nWeight: {self.weight}\nVolume: {self.volume}\nPriority: {self.priority}"
    
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
        if value.strip() == "":
            raise ValueError("You didn't pass a valid pickup adress")
        self.__pickupAdress = value.strip()
        
    @property
    def deliveryAdress(self):
        return self.__deliveryAdress
    
    @deliveryAdress.setter
    def deliveryAdress(self, value):
        if value.strip() == "":
            raise ValueError("You didn't pass a valid delivery adress")
        self.__deliveryAdress = value.strip()
        
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
            raise ValueError("An order priority needs to be True of False.")
        self.__priority = value
    
if "__main__" == __name__:
    main()