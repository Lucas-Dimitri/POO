import re

def main():
    newClient = Client('lucas', '11122233344', [10,10], '(55) 99999-0000', 'lucas@gmail.com')
    newClient = Client('lucas', '211.222.333-44', [10,10], '+55 55 999990000', 'lucas@gmail.com')
    for client in Client.clientList:
        print(client)
        print('')

class Client:
    clientList = []
    def __init__(self, name='', cpf='', adress=[0,0], phoneNumber='', email=''):
        self.name = name
        self.cpf = cpf
        self.adress = adress
        self.phoneNumber = phoneNumber
        self.email = email
        
        cpfcopies = []
        cpfcopies = [newclient for newclient in Client.clientList if cpf == newclient.cpf]
        if len(cpfcopies) > 0:
            raise ValueError("This CPF is already registered.")
        
        Client.clientList.append(self)
        
    def __str__(self):
        printClient = f"Name: {self.__name}\nCPF: {self.__cpf}\nAdress-> latitude: {self.adress[0]} longitude: {self.adress[1]}\nPhone Number: {self.__phoneNumber}\nEmail: {self.__email}"
        return printClient
 
        
    ###########################################
    ########### getters and setters ###########
    ###########################################
    
    @property
    def name(self):
        return self.__name
    
    @name.setter
    def name(self, value):
        if value == None:
            raise ValueError("You didn't pass a valid name")
        self.__name = value.strip()
        
    @property
    def cpf(self):
        return self.__cpf
    
    @cpf.setter
    def cpf(self, value):
        pattern = r'^\d{3}\.\d{3}\.\d{3}-\d{2}$|^\d{11}$'
        cpf_regex = re.compile(pattern)
        if not re.fullmatch(cpf_regex, value.strip()):
            raise ValueError("You didn't pass a valid cpf")
        cpf_pattern = re.sub(r'\D', '', value.strip())
        self.__cpf = cpf_pattern
        
    @property
    def adress(self):
        return self.__adress
    
    @adress.setter
    def adress(self, value):
        if value[0] < -90 or value[0] > 90:
            raise ValueError(f"You didn't pass a valid latitude:{value[1]}")
        if value[1] < -180 and value[1] > 180:
            raise ValueError(f"You didn't pass a valid longitude:{value[1]}")
        self.__adress = value
    
    @property
    def phoneNumber(self):
        return self.__phoneNumber
    
    @phoneNumber.setter
    def phoneNumber(self, value):
        
        #pattern = r'^(\+?\d{1,4}\s?\(?\d{2,3}\)?[\s-]?\d{4,5}[\s-]?\d{4})$'
        #phoneNumber_regex = re.compile(pattern)
        #if not re.fullmatch(phoneNumber_regex, value.strip()):
        #    raise ValueError("You didn't pass a valid phone number")
        
        self.__phoneNumber = value.strip()
        
    @property
    def email(self):
        return self.__email
    
    @email.setter
    def email(self, value):
        pattern = r'^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$'
        email_regex = re.compile(pattern)
        if not re.fullmatch(email_regex, value.strip()):
            raise ValueError("You didn't pass a valid email")
        self.__email = value.strip()
    
if "__main__" == __name__:
    main()