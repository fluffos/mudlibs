---
layout: doc
title: sockets / http_build_response
---
# http_build_response

### NAME

    http_build_response() - build an HTTP/1.1 response string

### SYNOPSIS

    string http_build_response(int status, mapping headers, string body);

### DESCRIPTION

    http_build_response() assembles a complete HTTP/1.1 response message from
    a status code, header mapping, and body string.

    The efun automatically adds:

    - `Content-Length` when it is not already present
    - `Connection: close` when it is not already present
    - a standard reason phrase for common status codes

    Header values passed in `headers` are preserved as provided.

### RETURN VALUE

    Returns the full response string, including the status line, headers, the
    blank line, and the body.

### EXAMPLE

    string body = "{\"ok\":true}";
    string res = http_build_response(200, ([
        "content-type": "application/json; charset=UTF-8",
    ]), body);

### SEE ALSO

    http_parser_feed(3)
