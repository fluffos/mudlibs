---
name: http-server
description: Create HTTP server daemons for Oxidus. Covers inheriting STD_HTTP_SERVER, listening on ports, handling incoming requests, sending responses, TLS, deflate compression, and connection management.
---

# HTTP Server Skill

You are helping create or modify HTTP server daemons for Oxidus. These are LPC daemons that listen for and respond to incoming HTTP requests. Follow the `lpc-coding-style` skill for all formatting.

## Architecture Overview

```
STD_DAEMON + EXT_HTTP
  └── STD_HTTP_SERVER (std/daemon/http_server.lpc) — base HTTP server
        └── Your daemon (e.g., adm/daemons/my_server.lpc)
```

- **`STD_HTTP_SERVER`** (`#define STD_HTTP_SERVER DIR_STD "daemon/http_server"`) — base class providing socket binding, client connection management, request parsing, and response sending.
- **`EXT_HTTP`** (`std/ext/http.lpc`) — shared module for HTTP parsing utilities. Inherited automatically.

## Required Include

```c
#include <http.h>
```

## Creating an HTTP Server Daemon

Inherit `STD_HTTP_SERVER`, set the port, start listening, and implement `http_handle_request()`:

```c
#include <http.h>

inherit STD_HTTP_SERVER;

void setup() {
  set_log_prefix("(MY SERVER)");
  set_log_level(1);

  set_listen_port(8080);
  start_server();
}

void http_handle_request(int fd, mapping client) {
  mapping request = client["http"]["request"];
  string method = request["request"]["method"];
  string path = request["route"]["route"];
  mapping query = request["route"]["query"];
  mapping headers = request["headers"];
  mixed body = request["body"];

  // Route and respond
  switch(path) {
    case "/api/status":
      client["http"]["response"] = ([
        "status"       : HTTP_STATUS_OK,
        "content-type" : CONTENT_TYPE_APPLICATION_JSON,
        "body"         : json_encode(([ "status" : "running" ])),
      ]);
      break;
    default:
      client["http"]["response"] = ([
        "status"       : HTTP_STATUS_NOT_FOUND,
        "content-type" : CONTENT_TYPE_TEXT_PLAIN,
        "body"         : "Not found",
      ]);
      break;
  }

  send_http_response(fd, client);
}
```

## Core Functions

### Server Lifecycle

| Function | Description |
|---|---|
| `set_listen_port(int port)` | Set the port to listen on (1-65535, default 8080). Call before `start_server()`. |
| `query_listen_port()` | Returns the current listen port. |
| `start_server()` | Binds to the port and begins listening for connections. |
| `close_client_connection(int fd)` | Close a specific client connection. |
| `close_all_client_connections()` | Close all active client connections. |

### Response Sending

```c
protected nomask void send_http_response(int fd, mapping client)
```

Builds and sends an HTTP/1.1 response based on `client["http"]["response"]`. The response mapping must contain:

| Key | Type | Description |
|---|---|---|
| `"status"` | string | HTTP status string, e.g., `HTTP_STATUS_OK` (`"200 OK"`) |
| `"content-type"` | string | Content-Type header, e.g., `CONTENT_TYPE_APPLICATION_JSON` |
| `"body"` | string or buffer | Response body (optional — if omitted, the status message text is used) |

## The `client` Mapping

Each connected client is tracked in a mapping:

```c
([
  "host" : "192.168.1.100",          // Client IP
  "port" : 54321,                     // Client port
  "time" : 1234567890.123,           // Connection time
  "http" : ([
    "request" : ([                    // Populated after parsing
      "request" : ([                  // Request line
        "method"  : "GET",
        "path"    : "/api/data?q=foo",
        "version" : "1.1",
      ]),
      "route" : ([                    // Parsed route
        "route" : "/api/data",        // Path without query
        "query" : ([ "q" : "foo" ]),  // Parsed query parameters
      ]),
      "headers" : ([                  // All header names lowercased
        "host"            : "example.com",
        "content-type"    : "application/json",
        "connection"      : ({ "keep-alive" }),  // Array for multi-value
        "accept-encoding" : ({ "gzip", "deflate" }),
      ]),
      "body" : mixed,                // Parsed body (mapping for JSON/form, string otherwise)
    ]),
    "response" : ([                   // You populate this before sending
      "status"       : "200 OK",
      "content-type" : "text/plain",
      "body"         : "Hello",
    ]),
  ]),
])
```

## Standard Response Headers

These are sent automatically with every response:

| Header | Value |
|---|---|
| `Server` | `"Oxidus (FluffOS)"` |
| `Connection` | `"close"` |
| `Date` | Current GMT date string (RFC 7231 format) |
| `Content-Length` | Calculated from response body |
| `Content-Type` | From your response mapping |

## Configuration Options

```c
set_listen_port(8080);               // Port to listen on
set_option("deflate", 1);            // Enable deflate compression for clients that accept it
set_option("tls", 1);               // Enable TLS (requires cert files)
set_option("close", 1);             // Force-close connections after response
set_log_level(2);                    // Logging verbosity
set_log_prefix("(MY SERVER)");       // Log line prefix
```

## TLS/HTTPS

When TLS is enabled, the server:
- Creates a `STREAM_TLS_BINARY` socket
- Loads certificate from `adm/certs/cert.pem`
- Loads private key from `adm/certs/key.pem`

**Note:** There is a known FluffOS bug (#1072) where TLS on a server socket can crash the driver.

## Deflate Compression

When `set_option("deflate", 1)` is enabled and the client sends `Accept-Encoding: deflate`, the response body is automatically compressed using `compress()` and a `Content-Encoding: deflate` header is added.

## Connection Closure

Connections are closed when:
1. The client sends `Connection: close` in request headers
2. The server has `set_option("close", 1)` set
3. You explicitly call `close_client_connection(fd)`

## Request Parsing

The base class automatically:
- Parses the HTTP request line (method, path, version)
- Parses headers (names lowercased, multi-value headers like `connection` and `accept-encoding` split into arrays)
- Parses the route (separates path from query string)
- Parses query parameters into a mapping
- Parses the body based on Content-Type:
  - `application/json` — decoded to LPC mapping/array
  - `application/x-www-form-urlencoded` — decoded to mapping
  - Other — returned as raw string

If parsing fails, a `400 Bad Request` response is sent automatically.

If `http_handle_request()` is not defined, a `501 Not Implemented` response is sent.

## The `http_handle_request` Callback

```c
void http_handle_request(int fd, mapping client)
```

This is the main callback you implement. It receives:
- `fd` — The client's socket file descriptor (pass to `send_http_response`)
- `client` — The client mapping with parsed request data

You must:
1. Read the request from `client["http"]["request"]`
2. Set `client["http"]["response"]` with `status`, `content-type`, and optionally `body`
3. Call `send_http_response(fd, client)`

## Minimal Example

```c
#include <http.h>

inherit STD_HTTP_SERVER;

void setup() {
  set_listen_port(6969);
  start_server();
}

void http_handle_request(int fd, mapping client) {
  client["http"]["response"] = ([
    "status"       : HTTP_STATUS_OK,
    "content-type" : CONTENT_TYPE_TEXT_PLAIN,
    "body"         : "Hello from Oxidus!",
  ]);

  send_http_response(fd, client);
}
```

## JSON API Example

```c
#include <http.h>

inherit STD_HTTP_SERVER;

void setup() {
  set_listen_port(8080);
  set_option("deflate", 1);
  start_server();
}

void http_handle_request(int fd, mapping client) {
  string method = client["http"]["request"]["request"]["method"];
  string path = client["http"]["request"]["route"]["route"];

  if(method == "GET" && path == "/api/players") {
    object *players = users();
    string *names = map(players, (: $1->query_name() :));

    client["http"]["response"] = ([
      "status"       : HTTP_STATUS_OK,
      "content-type" : CONTENT_TYPE_APPLICATION_JSON,
      "body"         : json_encode(([ "players" : names, "count" : sizeof(names) ])),
    ]);
  } else {
    client["http"]["response"] = ([
      "status"       : HTTP_STATUS_NOT_FOUND,
      "content-type" : CONTENT_TYPE_APPLICATION_JSON,
      "body"         : json_encode(([ "error" : "Not found" ])),
    ]);
  }

  send_http_response(fd, client);
}
```

## HTTP Status and Content-Type Constants

See the `http-client` skill for the full table of `HTTP_STATUS_*` and `CONTENT_TYPE_*` constants from `<http.h>`.
