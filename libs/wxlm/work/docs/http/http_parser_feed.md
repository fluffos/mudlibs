---
layout: doc
title: sockets / http_parser_feed
---
# http_parser_feed

### NAME

    http_parser_feed() - feed raw bytes into an incremental HTTP parser

### SYNOPSIS

    mapping http_parser_feed(mixed parser, string chunk);

### DESCRIPTION

    http_parser_feed() appends `chunk` to the parser's buffered data and
    returns a mapping with three keys:

    - `requests` : an array of zero or more complete request mappings
    - `error` : `0` on success, or an error mapping on parse failure
    - `need_more` : non-zero when more bytes are required to finish a request

    Each request mapping contains:

    - `method`
    - `path`
    - `version`
    - `query_string`
    - `query`
    - `headers`
    - `body`
    - `form`

    Header names are normalized to lowercase.

    The parser currently supports request bodies framed by `Content-Length`.
    It does not implement `Transfer-Encoding: chunked`.

### RETURN VALUE

    Returns the result mapping described above.

### EXAMPLE

    mixed parser = http_parser_create();
    mapping result = http_parser_feed(parser,
        "GET /ping?name=codex HTTP/1.1\r\n"
        "Host: example.com\r\n"
        "\r\n");

### SEE ALSO

    http_parser_create(3), http_parser_close(3), http_decode_query(3),
    http_decode_form(3)
