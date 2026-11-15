---
layout: doc
title: sockets / http_parser_close
---
# http_parser_close

### NAME

    http_parser_close() - release an incremental HTTP parser handle

### SYNOPSIS

    void http_parser_close(mixed parser);

### DESCRIPTION

    http_parser_close() releases the parser handle created by
    http_parser_create() and discards any buffered data held by that parser.

### EXAMPLE

    mixed parser = http_parser_create();
    http_parser_close(parser);

### SEE ALSO

    http_parser_create(3), http_parser_feed(3)
