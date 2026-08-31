---
name: http-client
description: Create HTTP client daemons for Oxidus. Covers inheriting STD_HTTP_CLIENT, making requests (GET/POST/PUT/DELETE etc.), the callback lifecycle, redirect handling, TLS/HTTPS, response processing, and the HTTPC_D fetch wrapper.
---

# HTTP Client Skill

You are helping create or modify HTTP client daemons for Oxidus. These are LPC daemons that make outbound HTTP requests to external services. Follow the `lpc-coding-style` skill for all formatting.

## Architecture Overview

```
STD_DAEMON + EXT_HTTP
  └── STD_HTTP_CLIENT (std/daemon/http_client.lpc) — base HTTP client
        └── Your daemon (e.g., adm/daemons/my_api.lpc)
```

- **`STD_HTTP_CLIENT`** (`#define STD_HTTP_CLIENT DIR_STD "daemon/http_client"`) — base class providing socket management, request sending, response parsing, redirect following, and caching.
- **`EXT_HTTP`** (`std/ext/http.lpc`) — shared module for URL parsing, header parsing, body parsing, URL encoding/decoding, and caching utilities. Inherited by `STD_HTTP_CLIENT` automatically.
- **`HTTPC_D`** (`adm/daemons/httpc.lpc`) — a ready-made wrapper daemon that adds a callback mechanism on top of `STD_HTTP_CLIENT`. Use this for simple fetch-and-callback patterns instead of writing your own daemon.

## Required Include

```c
#include <http.h>
```

This provides HTTP status codes, states, redirect codes, and content-type constants.

## Creating a Custom HTTP Client Daemon

Inherit `STD_HTTP_CLIENT` and implement callback functions:

```c
#include <http.h>

inherit STD_HTTP_CLIENT;

void setup() {
  set_log_prefix("(MY CLIENT)");
  set_log_level(0);
}

// Initiate a request
void do_fetch() {
  http_request("https://api.example.com/data", "GET", ([
    "Authorization" : "Bearer my-token",
    "Accept" : "application/json",
  ]), 0);
}

// Called when the connection fully shuts down and response is ready
void http_handle_shutdown(mapping server) {
  mapping response = server["response"];
  int status_code = response["status"]["code"];
  mixed body = response["body"];

  if(status_code == 200) {
    // body is auto-parsed based on content-type
    // JSON responses become LPC mappings/arrays
  }
}
```

## Core Function

### `http_request(url, method, headers, body)`

```c
varargs nomask mapping http_request(string url, string method, mapping headers, string body)
```

- **url** — Full URL including scheme (e.g., `"https://api.example.com/path?q=1"`)
- **method** — HTTP method: `"GET"`, `"POST"`, `"PUT"`, `"DELETE"`, `"OPTIONS"`, `"HEAD"`, `"PATCH"`, `"TRACE"`, `"CONNECT"`
- **headers** — Optional mapping of custom headers (merged with defaults)
- **body** — Optional request body string
- **Returns** — A mapping with parsed URL info (`host`, `port`, `path`, `method`, `start_time`, etc.), or `null` on parse failure

The request is dispatched asynchronously via `call_out_walltime`. Responses arrive through callback functions.

### Default Headers

These are sent automatically with every request (your custom headers are merged in):

```c
([
  "User-Agent"      : "FluffOS",
  "Connection"      : "close",
  "Accept-Charset"  : "utf-8",
])
```

If a body is provided, `Content-Length` and `Content-Type` (with charset) are added automatically.

## Callback Lifecycle

Implement any of these functions in your daemon to handle events. All receive a `mapping server` argument containing connection state:

| Callback | When Called |
|---|---|
| `http_handle_resolve_error(mapping server)` | DNS resolution failed |
| `http_handle_connecting(mapping server)` | Starting to connect |
| `http_handle_connection_error(mapping server)` | Connection failed |
| `http_handle_connected(mapping server)` | TCP connection established |
| `http_handle_ready(mapping server)` | Socket ready, about to send |
| `http_handle_sending(mapping server)` | Request being sent |
| `http_handle_response(mapping server)` | Response body received (Content-Length matched) |
| `http_handle_redirect(mapping server)` | Redirect detected (301/302/303/307/308) |
| `http_handle_closed(mapping server)` | Socket closed by remote |
| `http_handle_shutdown(mapping server)` | Connection fully shut down — **this is the main callback for processing responses** |

### The `server` Mapping

The `server` mapping passed to callbacks contains:

```c
([
  "state"          : HTTP_STATE_*,        // Current connection state
  "request"        : ([                   // Original request info
    "url"          : "https://...",
    "method"       : "GET",
    "host"         : "api.example.com",
    "port"         : 443,
    "path"         : "/data",
    "headers"      : ([ ... ]),
    "body"         : "...",
    "start_time"   : 1234567890.123,
    "secure"       : 1,
  ]),
  "response"       : ([                   // Populated after response arrives
    "status"       : ([
      "code"       : 200,
      "message"    : "OK",
    ]),
    "headers"      : ([                   // All header names lowercased
      "content-type"     : "application/json",
      "content-length"   : 1234,
      "connection"       : ({ "close" }),  // Array for multi-value headers
    ]),
    "body"         : mixed,               // Parsed body (mapping for JSON, string otherwise)
  ]),
  "redirects"      : 0,                   // Redirect count
  "received_total" : 5678,               // Total bytes received
  "received_body"  : 1234,               // Body bytes received
  "cache"          : "/tmp/http/123456",  // Cache file path
])
```

## HTTP States

Defined in `<http.h>`:

| Constant | Value | Meaning |
|---|---|---|
| `HTTP_STATE_RESOLVING` | 1 | DNS resolution in progress |
| `HTTP_STATE_CONNECTING` | 2 | TCP connection in progress |
| `HTTP_STATE_CONNECTED` | 3 | TCP connected |
| `HTTP_STATE_READY` | 4 | Socket ready for data |
| `HTTP_STATE_SENDING` | 5 | Sending request |
| `HTTP_STATE_RECEIVING` | 6 | Receiving response |
| `HTTP_STATE_COMPLETE` | 7 | Transfer complete |
| `HTTP_STATE_ERROR` | 100 | Error occurred |

## Configuration Options

Set in `setup()` or `mudlib_setup()`:

```c
set_option("cache", "/tmp/http/");   // Response cache directory (default)
set_option("deflate", 1);            // Enable deflate compression (Accept-Encoding: deflate)
set_option("tls", 1);               // Force TLS for all connections
set_max_redirects(10);               // Max redirect follows (default: 5)
set_log_level(2);                    // Logging verbosity (0=minimal, 4=verbose)
set_log_prefix("(MY CLIENT)");       // Log line prefix
```

## Redirect Handling

Redirects (301, 302, 303, 307, 308) are followed automatically up to `max_redirects` (default 5). The `http_handle_redirect` callback fires before each redirect. An `X-Redirect-Count` header tracks the count.

## TLS/HTTPS

HTTPS URLs are automatically handled via TLS sockets. The client:
- Creates a `STREAM_TLS_BINARY` socket
- Sets `SO_TLS_VERIFY_PEER` to verify server certificates
- Sets `SO_TLS_SNI_HOSTNAME` for Server Name Indication

You can also force TLS for all connections with `set_option("tls", 1)`.

## Response Processing

The base class handles:
- **Chunked transfer encoding** — reassembles chunks automatically
- **Content-Length responses** — validates expected vs received size
- **Body parsing** — JSON (`application/json`) is decoded to LPC mappings/arrays; form data (`application/x-www-form-urlencoded`) is decoded to mappings; other content types are returned as strings

## Using HTTPC_D (The Fetch Wrapper)

For simple request-and-callback patterns, use the pre-built `HTTPC_D` instead of writing a custom daemon:

```c
#include <daemons.h>

void do_fetch() {
  HTTPC_D->fetch(
    ({ this_object(), "handle_response" }),  // callback
    "GET",                                    // method
    "https://api.example.com/data",          // url
    ([ "Accept" : "application/json" ]),     // headers (optional)
    0                                         // body (optional)
  );
}

void handle_response(mapping response) {
  // response contains: status, headers, body
  int code = response["status"]["code"];
  mixed body = response["body"];
}
```

The callback receives the `server["response"]` mapping directly.

## Sending a POST with JSON Body

```c
void post_data(mapping data) {
  string json_body = json_encode(data);

  http_request("https://api.example.com/items", "POST", ([
    "Content-Type" : "application/json",
    "Authorization" : "Bearer my-token",
  ]), json_body);
}
```

## HTTP Status Code Constants

From `<http.h>`:

| Constant | Value |
|---|---|
| `HTTP_STATUS_OK` | `"200 OK"` |
| `HTTP_STATUS_CREATED` | `"201 Created"` |
| `HTTP_STATUS_ACCEPTED` | `"202 Accepted"` |
| `HTTP_STATUS_NO_CONTENT` | `"204 No Content"` |
| `HTTP_STATUS_MOVED_PERMANENTLY` | `"301 Moved Permanently"` |
| `HTTP_STATUS_FOUND` | `"302 Found"` |
| `HTTP_STATUS_NOT_MODIFIED` | `"304 Not Modified"` |
| `HTTP_STATUS_BAD_REQUEST` | `"400 Bad Request"` |
| `HTTP_STATUS_UNAUTHORIZED` | `"401 Unauthorized"` |
| `HTTP_STATUS_FORBIDDEN` | `"403 Forbidden"` |
| `HTTP_STATUS_NOT_FOUND` | `"404 Not Found"` |
| `HTTP_STATUS_METHOD_NOT_ALLOWED` | `"405 Method Not Allowed"` |
| `HTTP_STATUS_INTERNAL_SERVER_ERROR` | `"500 Internal Server Error"` |
| `HTTP_STATUS_NOT_IMPLEMENTED` | `"501 Not Implemented"` |
| `HTTP_STATUS_BAD_GATEWAY` | `"502 Bad Gateway"` |
| `HTTP_STATUS_SERVICE_UNAVAILABLE` | `"503 Service Unavailable"` |

## Content-Type Constants

From `<http.h>`:

| Constant | Value |
|---|---|
| `CONTENT_TYPE_TEXT_PLAIN` | `"text/plain"` |
| `CONTENT_TYPE_TEXT_HTML` | `"text/html"` |
| `CONTENT_TYPE_TEXT_CSS` | `"text/css"` |
| `CONTENT_TYPE_APPLICATION_JSON` | `"application/json"` |
| `CONTENT_TYPE_APPLICATION_XML` | `"application/xml"` |
| `CONTENT_TYPE_APPLICATION_FORM_URLENCODED` | `"application/x-www-form-urlencoded"` |
| `CONTENT_TYPE_MULTIPART_FORM_DATA` | `"multipart/form-data"` |

## URL Utility Functions (from EXT_HTTP)

These are available in any object inheriting `STD_HTTP_CLIENT`:

- `parse_url(string url)` — Returns mapping with `protocol`, `secure`, `host`, `port`, `path`
- `url_encode(string str)` — URL-encode a string
- `url_decode(string str)` — Decode a URL-encoded string

## Real-World Examples

### GitHub Issues Daemon (`adm/daemons/github_issues.lpc`)

Inherits `STD_HTTP_CLIENT`, POSTs to GitHub API to create issues with OAuth token authentication. Saves failed requests for retry.

### Zoho Daemon (`adm/daemons/zoho.lpc`)

Inherits `STD_HTTP_CLIENT`, implements OAuth2 token refresh flow and sends emails via Zoho Mail API.

### HTTPC Daemon (`adm/daemons/httpc.lpc`)

General-purpose fetch wrapper with callback tracking by serial number.

## Async Handlers

The client dispatches its lifecycle handlers with `call_if(this_object(), ...)`,
which returns the result unwrapped. That means an `async` handler works — it is
invoked, runs to its first `await`, and the promise it returns is simply
discarded by the client, which is ordinary fire-and-forget.

Two things follow:

- **Nothing observes the promise**, so an uncaught error inside the handler
  surfaces only as an unhandled-rejection line in the debug log, at
  deallocation, far from the cause. Wrap an async handler's body in `acatch`
  and log deliberately.
- **The client does not wait.** The connection proceeds as soon as the handler
  parks, so anything that must happen before the next lifecycle step has to be
  done *before* the first `await` — an async body runs synchronously up to that
  point.

```lpc
protected async void http_handle_response(object server, mapping response) {
  mixed err = acatch {
    await async_write(CACHE_FILE, response["body"], 0);
    note_cached(response["url"]);
  };

  if(err)
    debug_message(`http cache: ${err}\n`);
}
```

If a handler only needs a delay rather than real async work, `await
call_out_walltime(n)` inside it is the non-blocking pause; do not use a
callback-form `call_out`, which is not awaitable.

To fan several requests out and collect them, `promise_all_settled()` reports
each outcome without one failure spoiling the rest. See the `async-promises`
skill.
