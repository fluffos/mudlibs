/**
 * @file /include/http.h
 *
 * Defines shared HTTP response statuses, connection states, redirect codes,
 * and media types used by the HTTP client and server implementations.
 */

#ifndef HTTP_CONSTANTS_H
#define HTTP_CONSTANTS_H

// Common HTTP Status Codes
#define HTTP_STATUS_OK "200 OK"
#define HTTP_STATUS_CREATED "201 Created"
#define HTTP_STATUS_ACCEPTED "202 Accepted"
#define HTTP_STATUS_NO_CONTENT "204 No Content"
#define HTTP_STATUS_MOVED_PERMANENTLY "301 Moved Permanently"
#define HTTP_STATUS_FOUND "302 Found"
#define HTTP_STATUS_NOT_MODIFIED "304 Not Modified"
#define HTTP_STATUS_BAD_REQUEST "400 Bad Request"
#define HTTP_STATUS_UNAUTHORIZED "401 Unauthorized"
#define HTTP_STATUS_FORBIDDEN "403 Forbidden"
#define HTTP_STATUS_NOT_FOUND "404 Not Found"
#define HTTP_STATUS_METHOD_NOT_ALLOWED "405 Method Not Allowed"
#define HTTP_STATUS_CONTENT_TOO_LARGE "413 Content Too Large"
#define HTTP_STATUS_INTERNAL_SERVER_ERROR "500 Internal Server Error"
#define HTTP_STATUS_NOT_IMPLEMENTED "501 Not Implemented"
#define HTTP_STATUS_BAD_GATEWAY "502 Bad Gateway"
#define HTTP_STATUS_SERVICE_UNAVAILABLE "503 Service Unavailable"

// HTTP States
#define HTTP_STATE_RESOLVING 1
#define HTTP_STATE_CONNECTING 2
#define HTTP_STATE_CONNECTED 3
#define HTTP_STATE_READY 4
#define HTTP_STATE_SENDING 5
#define HTTP_STATE_RECEIVING 6
#define HTTP_STATE_COMPLETE 7
#define HTTP_STATE_ERROR 100

#define HTTP_REDIRECT_CODES ({ \
    301, 302, 303, 307, 308, \
})

// Common Content-Types
#define CONTENT_TYPE_TEXT_PLAIN "text/plain"
#define CONTENT_TYPE_TEXT_HTML "text/html"
#define CONTENT_TYPE_TEXT_CSS "text/css"
#define CONTENT_TYPE_APPLICATION_JSON "application/json"
#define CONTENT_TYPE_APPLICATION_XML "application/xml"
#define CONTENT_TYPE_APPLICATION_FORM_URLENCODED "application/x-www-form-urlencoded"
#define CONTENT_TYPE_MULTIPART_FORM_DATA "multipart/form-data"
#define CONTENT_TYPE_IMAGE_JPEG "image/jpeg"
#define CONTENT_TYPE_IMAGE_PNG "image/png"
#define CONTENT_TYPE_IMAGE_GIF "image/gif"

#endif // HTTP_CONSTANTS_H
