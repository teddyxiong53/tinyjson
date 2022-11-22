#ifndef __TINY_JSON_H__
#define __TINY_JSON_H__
/**
 * @brief tinyjson is a small json paramater read/write library based on cJSON.
 *
 */
#include <pthread.h>
#include "cJSON.h"

typedef struct {
    const char *filename;
    pthread_mutex_t lock;
} tj_handle_t;

tj_handle_t * tj_open(const char *filename);
/**
 * @brief
 *
 * @param key string like: "system.settings.volume"
 * @param value "50.0"
 * @return int
 */
int tj_set(tj_handle_t *handle, const char *key, const char *value);
char * tj_get(tj_handle_t * handle, const char *key);
void tj_close(tj_handle_t *handle);

#endif