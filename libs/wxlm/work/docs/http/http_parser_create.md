---
layout: doc
title: sockets / http_parser_create
---
# http_parser_create

### NAME

    http_parser_create() - create an incremental HTTP request parser

### SYNOPSIS

    mixed http_parser_create();

### DESCRIPTION

    http_parser_create() creates a parser handle that can be passed to
    http_parser_feed() and http_parser_close().

    The handle keeps the parser's buffered byte stream between calls so LPC
    code can feed socket data incrementally.

### RETURN VALUE

    Returns a parser handle.

### EXAMPLE

    mixed parser = http_parser_create();

### SEE ALSO

    http_parser_feed(3), http_parser_close(3)
