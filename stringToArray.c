//
// Created by hugol on 28/03/2023.
//

#include "stringToArray.h"

unsigned int countStringArrayElements(const char *array, const char *delimiter) {
    unsigned int count = 1;
    size_t delimiterLength = strlen(delimiter);
    char const *temporary = array;
    while (*temporary != '\0') {
        if (strncmp(temporary, delimiter, delimiterLength) == 0) {
            count++;
            temporary += delimiterLength;
        } else {
            temporary++;
        }
    }
    return count;
}

void copySubString(char *destination, const char *source, size_t length) {
    for (int i = 0; i < length; i++) {
        destination[i] = source[i];
    }
    destination[length] = '\0';
}

StringArray splitStringToArray(const char *stringToSplit, const char *delimiter) {
    StringArray result;
    size_t delimiterLength = strlen(delimiter);

    result.size = countStringArrayElements(stringToSplit, delimiter);
    result.array = (char **) malloc(sizeof(char *) * result.size);
    if (result.array == NULL) {
        result.size = 0;
    } else {
        unsigned int lineIndex = 0;
        const char *temporary = stringToSplit;
        const char *temporaryStart = stringToSplit;
        while ((*temporary != '\0') && (lineIndex < result.size)) {
            if (strncmp(temporary, delimiter, delimiterLength) == 0) {
                size_t subStringLength = temporary - temporaryStart;
                result.array[lineIndex] = (char *) malloc(sizeof(char) * (subStringLength + 1));
                copySubString(result.array[lineIndex], temporaryStart, subStringLength);
                lineIndex++;
                temporary += delimiterLength;
                temporaryStart = temporary;
            } else {
                temporary++;
            }
        }
        if (lineIndex < result.size) {
            size_t subStringLength = temporary - temporaryStart;
            result.array[lineIndex] = (char *) malloc(sizeof(char) * (subStringLength + 1));
            copySubString(result.array[lineIndex], temporaryStart, subStringLength);
        }
    }

    return result;
}