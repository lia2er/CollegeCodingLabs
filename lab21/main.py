class Item:
    name: str
    price: float
    count: int
    
    # значення об`єкту при ініціалізації, self звертається до змінних класу
    def __init__(self, name="Nothing", price=0.0, count=0): # через = вказано значення за замовчуванням
        # присвоєння значень змінних з параметрів в власні змінні класу
        self.name = name
        self.price = price
        self.count = count

    # функція для зміни назви
    def SetName(self, newName):
        # присвоєння власній змінній name значення newName
        self.name = newName
    
    # функція для зміни ціни
    def SetPrice(self, newPrice):
        # присвоєння власній змінній price значення newPrice
        self.price = newPrice

    # функція для зміни кількості
    def SetCount(self, newCount):
        # присвоєння власній змінній count значення newCount
        self.count = newCount
    
    # функція для виведення даних класового об`єкту
    def Print(self):
        # виведення тексту і змінних через форматований рядок
        print(f"Item name: {self.name}\nCount: {self.count}\nPrice: {self.price:.2f}")

medicine = Item() # ініціалізація об`єкта класу Item з дефолтними значеннями __init__
medicine.Print() # виклик методу Print

cola = Item("Coca-cola", 16.3, 2) # задання даних через __init__
cola.Print() # виклик методу Print

medicine.SetName("Nurofen") # виклик методу SetName з параметром "Nurofen"
medicine.SetCount(34) # виклик методу SetCount з параметром 34
medicine.SetPrice(34.2) # виклик методу SetPrice з параметром 34.2
medicine.Print() # виклик методу Print

cola.SetName("Pepsi") # виклик методу SetName з параметром "Pepsi"
cola.SetCount(14) # виклик методу SetCount з параметром 14
cola.SetPrice(13.8) # виклик методу SetPrice з параметром 13.8
cola.Print() # виклик методу Print

drink = cola # ініціалізація drink з даними об`єкта cola
drink.Print() # виклик методу Print
