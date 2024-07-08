from order import Order
from client import Client
from geopy.geocoders import Nominatim
import csv

def main():
    arquivo = r'c:\Users\lucas\OneDrive\Documents\faculdade\terceiro semestre\POO\trabalho2\objects\mydata.csv'
    create_orders_from_csv(arquivo)
    for client in Client.clientList:
        print(client)
    for order in Order.highPriorityList:
        print(order)
    for order in Order.lowPriorityList:
        print(order)

def create_orders_from_csv(csvFile):
    with open(csvFile, newline='', encoding='utf-8') as csvfile:
        reader = csv.DictReader(csvfile)
        
        geolocator = Nominatim(user_agent="my_app")
        
        for row in reader:
            try:
                location = geolocator.geocode(row['adress'])
                
                newClient = Client(row['name'], row['cpf'], [location.latitude, location.longitude], row['phoneNumber'], row['email'])
                    
            except Exception as e:
                continue
                
        for row in reader:            
            try:
                if row['priority'] == "sim":
                    row['priority'] = True
                else:
                    row['priority'] = False
                    
                client
                for clientX in Client.clientList:
                    if clientX.cpf == row['cpf']:
                        client = clientX
                
                location1 = geolocator.geocode(row['pickupAdress'])
                location2 = geolocator.geocode(row['deliveryAdress'])
                
                newOrder = Order(client, [location1.latitude, location1.longitude], [location2.latitude, location2.longitude], float(row['weight']), float(row['volume']), row['priority'])
                
            except Exception as e:
                continue
           
if "__main__" == __name__:
    main()