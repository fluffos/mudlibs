---
layout: doc
title: sockets / http_response_parser_create
---
# http_response_parser_create

### NAME

    http_response_parser_create() - create an incremental HTTP response parser

### SYNOPSIS

    mixed http_response_parser_create();

### DESCRIPTION

    http_response_parser_create() creates a parser handle that can be passed to
    http_response_parser_feed() and http_response_parser_close().

    The returned handle is opaque to LPC code and keeps any partially received
    response bytes buffered between feed calls.

### RETURN VALUE

    Returns an opaque parser handle.

### EXAMPLE

    mixed parser = http_response_parser_create();

### SEE ALSO

    http_response_parser_feed(3), http_response_parser_close(3)
