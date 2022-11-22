#include <stdlib.h>
#include <stdio.h>

#include "tinyjson.h"
#include "mylog.h"

tj_handle_t* tj_open(const char* filename)
{
    FILE* fp;
    int len, ret;
    char* input = NULL;
    cJSON* temp;
    tj_handle_t *handle = calloc(sizeof(tj_handle_t));
    if (handle == NULL) {
        myloge("malloc tj_handle_t fail");
        return NULL;
    }
    if (NULL == filename) {
        return NULL;
    }
    fp = fopen(filename, "r+");
    if (fp == NULL) {
        myloge("cannot open the default json file %s\n", filename);
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    len = (int)ftell(fp);

    fseek(fp, 0, SEEK_SET);

    input = (char*)malloc(len + 10);
    if (input == NULL) {
        myloge( "Cannot malloc the address size = %d\n", len);
        fclose(fp);
        return NULL;
    }
    ret = fread(input, 1, len, fp);

    temp = cJSON_Parse(input);

    fclose(fp);
    free(input);
    return
}

int tj_set(tj_handle_t *handle, const char* key, const char* value)
{
}

char* tj_get(tj_handle_t *handle, const char* key)
{
}

void tj_close(tj_handle_t* handle)
{
}