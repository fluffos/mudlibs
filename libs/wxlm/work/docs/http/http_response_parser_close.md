---
layout: doc
title: sockets / http_response_parser_close
---
# http_response_parser_close

### NAME

    http_response_parser_close() - release an incremental HTTP response parser handle

### SYNOPSIS

    void http_response_parser_close(mixed parser);

### DESCRIPTION

    http_response_parser_close() releases the parser handle created by
    http_response_parser_create() and discards any buffered data held by that
    parser.

### EXAMPLE

    mixed parser = http_response_parser_create();
    http_response_parser_close(parser);

### SEE ALSO

    http_response_parser_create(3), http_response_parser_feed(3)
