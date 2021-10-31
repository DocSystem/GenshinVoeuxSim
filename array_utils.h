int getSizeOfArray(char** array) {
    int i = 0;
    while (array[i] != '\0') {
        i++;
    }
    return i;
}

void removeIndexFromArray(char** array, int index) {
    int i;
    for (i = index; i < getSizeOfArray(array) - 1; i++) {
        array[i] = array[i + 1];
    }
    array[i] = '\0';
}

int getIndexOfElementInArray(char** array, char* element) {
    int i;
    for (i = 0; i < getSizeOfArray(array); i++) {
        if (strcmp(array[i], element) == 0) {
            return i;
        }
    }
    return -1;
}

void removeElementFromArray(char** array, char* element) {
    int index = getIndexOfElementInArray(array, element);
    removeIndexFromArray(array, index);
}
