import wishes
import random

curr = 0
estGaranti5 = False
estGaranti4 = False
currPity5 = 0
currPity4 = 0
pities5 = wishes.get_5stars()
pities4 = wishes.get_4stars()

nonFocus5stars = ["Jean", "Diluc", "Qiqi", "Keqing", "Mona"]
focus5stars = "Hu Tao"
counter5stars = 0

focus4stars = ["Thomas", "Sayu", "Diona"]
characters4stars = ["Kujou Sara", "Sayu", "Yanfei", "Rosalia", "Xinyan", "Diona", "Sucrose", "Chongyun", "Noëlle", "Bennett", "Fischl", "Ningguang", "Xingqiu", "Beidou", "Xiangling", "Razor", "Barbara", "Thomas"]
weapons4stars = ["Arc rouillé", "Arc rituel", "Dernière corde", "Arc de chasse de Favonius", "Oeil de la perception", "Mémoires des rituels", "Mouvement vagabon", "Code de Favonius", "Lance de Favonius", "Fléau du dragon", "Fluorescence", "Espadon rituel", "Epée-horloge", "Espadon de Favonius", "Rugissement du lion", "Epée rituel", "Flute", "Epée de Favonius"]
nonFocus4stars = []
counter4stars = 0
for p in characters4stars:
    if p not in focus4stars:
        nonFocus4stars.append(p)

continuePull = True

while continuePull:
    for i in range(10):
        curr += 1
        currPity5 += 1
        currPity4 += 1
        luck = random.randint(0, 100000) / 1000
        if luck <= pities5[currPity5 - 1]["percentage"]:
            if not estGaranti5:
                if random.randint(1,2) == 1:
                    print("\033[93m" + str(curr) + ". " + focus5stars + " (5 stars - Focus 50/50) - Pity : " + str(currPity5) + "\033[0m")
                else:
                    print("\033[93m" + str(curr) + ". " + nonFocus5stars[random.randint(0, 4)] + " (5 stars - Non Focus 50/50) - Pity : " + str(currPity5) + "\033[0m")
                    estGaranti5 = True
            else:
                print("\033[93m" + str(curr) + ". " + focus5stars + " (5 stars - Garanti) - Pity : " + str(currPity5) + "\033[0m")
                estGaranti5 = False
            currPity5 = 0
            counter5stars += 1
        elif luck <= pities4[currPity4 - 1]["percentage"]:
            if not estGaranti4:
                if random.randint(1,2) == 1:
                    print("\033[95m" + str(curr) + ". " + focus4stars[random.randint(0, 2)] + " (4 stars - Focus 50/50) - Pity : " + str(currPity5) + "\033[0m")
                else:
                    if random.randint(1,2) == 1:
                        print("\033[95m" + str(curr) + ". " + nonFocus4stars[random.randint(0, len(nonFocus4stars) - 1)] + " (4 stars - Non Focus 50/50) - Pity : " + str(currPity5) + "\033[0m")
                    else:
                        print("\033[95m" + str(curr) + ". " + weapons4stars[random.randint(0, len(weapons4stars) - 1)] + " (4 stars - Non Focus 50/50) - Pity : " + str(currPity5) + "\033[0m")
                    estGaranti4 = True
            else:
                print("\033[95m" + str(curr) + ". " + focus4stars[random.randint(0, 2)] + " (4 stars - Garanti) - Pity : " + str(currPity5) + "\033[0m")
                estGaranti4 = False
            currPity4 = 0
            counter4stars += 1
        else:
            print(str(curr) + ". 3 stars - Pity : " + str(currPity5))
    try:
        input()
    except:
        print(" ")
        print("Vous avez eu :")
        print("- 5 stars : " + str(counter5stars))
        print("- 4 stars : " + str(counter4stars))
        exit()
