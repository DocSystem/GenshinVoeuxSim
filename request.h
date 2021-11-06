#include "curl/curl.h"
#include "json-c/json.h"

// parse json from http get request response
json_object *parse_json_from_http_get_response(char *response) {
    json_object *json = json_tokener_parse(response);
    if (is_error(json)) {
        return NULL;
    }
    return json;
}

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

/*static size_t write_data(char *ptr, size_t size, size_t nmemb, void *user){

    // If you're expecting JSON as response: parse pointer
    json_object *res = json_tokener_parse(ptr);
    printf("%s\n", json_object_to_json_string(res));
    return size * nmemb;
}*/

// parse json from https get request
json_object *parse_json_from_https_get_request(char *url) {
    CURL *curl;
    CURLcode res;
    char *response;
    json_object *json;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
            return NULL;
        }
        json = parse_json_from_http_get_response(response);
        curl_easy_cleanup(curl);
    }
    return json;
}



/*json_object *parse_json_from_http_get(char *url) {
    CURL *curl;
    CURLcode res;
    char *response;
    json_object *json;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, parse_json_from_http_get_response);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
            return NULL;
        }
        json = parse_json_from_http_get_response(response);
        curl_easy_cleanup(curl);
    }
    return json;
}*/
