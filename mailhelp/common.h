#ifndef COMMON_H
#define COMMON_H
#include <QObject>

#define GMAIL_CLIENT_ID "662287800555-0a5h4ii0e9hsbpq0mqtul7fja0jhf9uf.apps.googleusercontent.com"
#define LOCAL_REDIRECT_URI  "http://127.0.0.1:"
#define LOCAL_SERVER_PORT 12131 
enum ErrorCode
{
    EC_SUCCESS = 0,
    EC_ERROR = 400000,
    EC_UNKNOWN = 900000,
    EC_DB = 900002
};

#endif // COMMON_H
