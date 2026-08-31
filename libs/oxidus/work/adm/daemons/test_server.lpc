// /adm/daemons/test_server.c
// This server is for testing responses.
//
// Created:     2024/07/04: Gesslar
// Last Change: 2024/07/04: Gesslar
//
// 2024/07/04: Gesslar - Created

#include <http.h>

inherit STD_HTTP_SERVER;

void setup() {
  set_log_level(4);
  set_log_prefix("(TEST SERVER)");

  if(!set_listen_port(6969))
    return;

  set_option("deflate", 1);
  // tls on a server will crash your driver. 2024-07-05
  // https://github.com/fluffos/fluffos/issues/1072
  set_option("tls", 1);

  start_server();
}

void http_handle_request(int fd, mapping client) {
  string body;

  body = @text
Hi there, this is a text response! And uhm, we're going to make it
compressed maybe? Who knows!

Enjoy!
text;

  client["http"]["response"] = ([
    "status": HTTP_STATUS_OK,
    "content-type": CONTENT_TYPE_TEXT_PLAIN,
    "body": body,
  ]);

  send_http_response(fd, client);
}
