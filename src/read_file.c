#include "read_file.h"

char *read_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    char *buffer = malloc(size + 1);
    if (buffer == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }

    if (fread(buffer, 1, size, file) != size)
    {
        printf("Error reading file %s\n", filename);
        exit(1);
    }

    buffer[size] = '\0';
    fclose(file);

    return (buffer);
}