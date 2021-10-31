[![C Build (Windows)](https://github.com/DocSystem/GenshinVoeuxSim/actions/workflows/c-win.yml/badge.svg)](https://github.com/DocSystem/GenshinVoeuxSim/actions/workflows/c-win.yml)[![C Build (Ubuntu)](https://github.com/DocSystem/GenshinVoeuxSim/actions/workflows/c-lin.yml/badge.svg)](https://github.com/DocSystem/GenshinVoeuxSim/actions/workflows/c-lin.yml)[![C Build (macOS)](https://github.com/DocSystem/GenshinVoeuxSim/actions/workflows/c-mac.yml/badge.svg)](https://github.com/DocSystem/GenshinVoeuxSim/actions/workflows/c-mac.yml)

# Simulateur de voeux Genshin Impact

## Version C

### Description

Ceci est un simulateur de voeux pour le jeu Genshin Impact.

Il simule le système de voeux du jeu avec les statistiques du site [Genshin Wishes](https://www.genshin-wishes.com/).

Il affiche aussi le pity actuel des 5 stars.

### Compiler

```bash
gcc simulator.c -o simulator
```

### Téléchargement

Une version pré-compilée est disponible [ici](https://github.com/DocSystem/GenshinVoeuxSim/releases/).

## Version Python

* Le fichier [simulator.py](Python/simulator.py) est la version Python du simulateur, elle fait exactement la même chose que la version C.
* Le fichier [wishes.py](Python/wishes.py) est le module qui contient les fonctions de calcul des voeux.
* Le fichier [simulator2.py](Python/Their%20stats/simulator2.py) est la version Python du simulateur avec les stats officielles du jeu.
