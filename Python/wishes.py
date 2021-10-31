import json

def get_5stars():
    with open("CHARACTER_EVENT.json") as f:
        data = json.load(f)

    total = 0

    pities_o = data["countPerPity5Stars"]
    pities = []

    for p in pities_o:
        total += p["count"]

    for p in pities_o:
        pities.append({"pity": p["pity"], "percentage": p["count"] / total * 100})
        total -= p["count"]
    
    return pities

def get_4stars():
    with open("CHARACTER_EVENT.json") as f:
        data = json.load(f)

    total = 0

    pities_o = data["countPerPity4Stars"]
    pities = []

    for p in pities_o:
        total += p["count"]

    for p in pities_o:
        pities.append({"pity": p["pity"], "percentage": p["count"] / total * 100})
        total -= p["count"]
    
    return pities

if __name__ == "__main__":
    for i in get_5stars():
        print("Pity " + str(i["pity"]) + " : " + str(i["percentage"]) + "%")
