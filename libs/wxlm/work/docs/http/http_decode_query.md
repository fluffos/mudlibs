---
layout: doc
title: sockets / http_decode_query
---
# http_decode_query

### NAME

    http_decode_query() - decode a query string into a mapping

### SYNOPSIS

    mapping http_decode_query(string query);

### DESCRIPTION

    http_decode_query() decodes a query string such as `a=1&b=2` into a
    mapping.

    Both keys and values are URL-decoded. Empty values are preserved as empty
    strings. Repeated keys keep the last value seen.

    An empty input string returns an empty mapping.

### RETURN VALUE

    Returns a mapping of decoded key/value pairs.

### EXAMPLE

    http_decode_query("file=%2Fadm%2Ffoo.c&name=hello+world")
    // returns ([ "file": "/adm/foo.c", "name": "hello world" ])

### SEE ALSO

    url_decode(3), http_decode_form(3), http_parser_feed(3)
