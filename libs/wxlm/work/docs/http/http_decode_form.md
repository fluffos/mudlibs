---
layout: doc
title: sockets / http_decode_form
---
# http_decode_form

### NAME

    http_decode_form() - decode a form body into a mapping

### SYNOPSIS

    mapping http_decode_form(string body);

### DESCRIPTION

    http_decode_form() decodes an
    `application/x-www-form-urlencoded` body into a mapping.

    Its decoding rules match http_decode_query(): both keys and values are
    URL-decoded, empty values are preserved, and repeated keys keep the last
    value seen.

### RETURN VALUE

    Returns a mapping of decoded key/value pairs.

### EXAMPLE

    http_decode_form("file=%2Fadm%2Ffoo.c&name=hello+world")
    // returns ([ "file": "/adm/foo.c", "name": "hello world" ])

### SEE ALSO

    url_decode(3), http_decode_query(3), http_parser_feed(3)
