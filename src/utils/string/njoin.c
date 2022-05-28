#include "njoin.h"

static size_t get_arr_content_len(const char **arr, size_t n)
{
    size_t arr_len = 0;

    for (size_t i = 0; arr[i] && i < n; i++) {
        arr_len += strlen(arr[i]);
    }
    return (arr_len);
}

static size_t get_arr_len(const char **arr, size_t n)
{
    size_t arr_len = 0;

    for (; arr[arr_len] && arr_len < n; arr_len++);
    return (arr_len);
}

char *njoin(const char **arr, const char *sep, size_t n)
{
    const size_t arr_len = get_arr_len(arr, n);
    const size_t sep_len = strlen(sep);
    size_t res_len = get_arr_content_len(arr, n) + arr_len * sep_len;
    char *res = malloc(sizeof(char) *  (res_len + 1));
    memset(res, 0, res_len + 1);

    for (size_t i = 0; i < n && arr[i]; i++) {
        strcat(res, arr[i]);
        strcat(res, sep);
    }
    res[res_len - sep_len] = 0;
    return (res);
}