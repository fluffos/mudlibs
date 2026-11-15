---
layout: doc
title: sockets / http_response_parser_feed
---
# http_response_parser_feed

### NAME

    http_response_parser_feed() - feed raw bytes into an incremental HTTP response parser

### SYNOPSIS

    mapping http_response_parser_feed(mixed parser, string chunk);

### DESCRIPTION

    http_response_parser_feed() appends `chunk` to the parser's buffered data
    and returns a mapping with three keys:

    - `responses` : an array of zero or more complete response mappings
    - `error` : `0` on success, or an error mapping on parse failure
    - `need_more` : non-zero when more bytes are required to finish a response

    Each response mapping contains:

    - `version`
    - `status_code`
    - `reason`
    - `headers`
    - `body`

    Header names are normalized to lowercase.

    The parser currently supports:

    - responses framed by `Content-Length`
    - bodyless responses such as `1xx`, `204`, and `304`

    It does not implement `Transfer-Encoding: chunked`, gzip/deflate decoding,
    or close-delimited response bodies.

### RETURN VALUE

    Returns the result mapping described above.

### EXAMPLE

    mixed parser = http_response_parser_create();
    mapping result = http_response_parser_feed(parser,
        "HTTP/1.1 200 OK\r\n"
        "Content-Length: 2\r\n"
        "\r\n"
        "{}");

### SEE ALSO

    http_response_parser_create(3), http_response_parser_close(3)
