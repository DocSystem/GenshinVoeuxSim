import random

curr = 0
estGaranti5 = False
estGaranti4 = False
currPity5 = 0
currPity4 = 0

nonFocus5stars = ["Jean", "Diluc", "Qiqi", "Keqing", "Mona"]
focus5stars = "Hu Tao"

focus4stars = ["Thomas", "Sayu", "Diona"]
characters4stars = ["Kujou Sara", "Sayu", "Yanfei", "Rosalia", "Xinyan", "Diona", "Sucrose", "Chongyun", "Noëlle", "Bennett", "Fischl", "Ningguang", "Xingqiu", "Beidou", "Xiangling", "Razor", "Barbara", "Thomas"]
weapons4stars = ["Arc rouillé", "Arc rituel", "Dernière corde", "Arc de chasse de Favonius", "Oeil de la perception", "Mémoires des rituels", "Mouvement vagabon", "Code de Favonius", "Lance de Favonius", "Fléau du dragon", "Fluorescence", "Espadon rituel", "Epée-horloge", "Espadon de Favonius", "Rugissement du lion", "Epée rituel", "Flute", "Epée de Favonius"]
nonFocus4stars = []
for p in characters4stars:
    if p not in focus4stars:
        nonFocus4stars.append(p)

continuePull = True

while continuePull:
    for i in range(10):
        curr += 1
        currPity5 += 1
        currPity4 += 1
        luck = random.randint(0, 100000)/1000
        if luck <= 0.6 or currPity5 >= 90:
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
        elif luck <= 5.1 or currPity4 >= 10:
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
        else:
            print(str(curr) + ". 3 stars - Pity : " + str(currPity5))
    try:
        input()

    except:
        exit()