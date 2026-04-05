# імпортую клас datetime з бібліотеки datetime
from datetime import datetime 

# ініціалізація змінної зі значенням поточного року
currentYear = datetime.now().year 
N = 0 # ініціалізація змінної зі значенням 0

# with - відповідає за автоматичне вивільнення пам`яті i присвоєння open() до ofile
# "NAFTA" - файл, "w" - режим запису
with open("NAFTA", "w") as ofile: 
    while True: # нескінченний цикл while
        # отримання значення з клавіатури і запис в змінну
        rigName = input('Enter oil rig name (type "stop" when enough): ')
        # умова, прирівняння переведеного rigName в нижній регістр до рядка "stop" 
        if rigName.lower() == "stop":
            break # вихід з циклу
        
        # словник ключ-значення, присвоєння ключам відповідних значень введених з клавіатури
        oilRig = {"name": rigName,
            "year": int(input("Enter year when rig was made up: ")),
            "price": int(input("Enter price of oil per tonn: ")), 
            "extracted": int(input("Enter how much of oil was extracted: "))}

        # запис даних у файл
        ofile.write(f"{oilRig['name']} {oilRig['year']} {oilRig['price']} {oilRig['extracted']}\n") 
        N += 1 # зміна лічильника
        print("--[Now enter next oil rig info]--") # виведення тексту

print(f"\nWe know {N} oil rigs so far\n") # виведення тексту

# отримання вводу з клавіатури, переведення в тип int і запис в змінну Т
T = int(input("--[ How young can the oil rig be?\n $ ")) 
# отримання вводу з клавіатури, переведення в тип int і запис в змінну C
C = int(input("--[ What's the highest acceptable price?\n $ ")) 

mostExtractedRig = None # ініціалізація пустої змінної(як void)

# відкриття файлу NAFTA у режимі читання як ifile, відкриття файлу B1 в режимі запису як ofile
with open("NAFTA", "r") as ifile, open("B1", "w") as ofile: 
    # перевірка поки в ifile є рядки, і їх запис в line
    for line in ifile: 
        # ініціалізація змінної, і запис в неї розділеного на список line
        data = line.split() 
        if not data: # якщо data повертає 0
            continue # пропуск ітерації
            
        # присвоєння елементів списку відповідним ключам словника
        oilRig = {"name": data[0],
            "year": int(data[1]),
            "price": int(data[2]),
            "extracted": int(data[3])}
        
        # перевірка умови задачі, запис імені родовища дешевшого від C і одночацно старшого Т
        if oilRig["price"] < C and (currentYear - oilRig["year"]) > T:
            ofile.write(f"{oilRig['name']}\n") # запис імені родовища в файл B1
        
        # знаходження родовища, яке видобуло найбільше нафти
        if mostExtractedRig is None or oilRig["extracted"] > mostExtractedRig["extracted"]:
            mostExtractedRig = oilRig # присвоєння mostExtractedRig словника oilRig

# умова виконується, якщо mostExtractedRig містить якісь дані
if mostExtractedRig:
    # виведення тексту
    print(f"{mostExtractedRig['name']} extracted the most oil") 
