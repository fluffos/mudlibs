/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

int
main()
{
  object conn = this_player()->query_connection();
  object body = this_player();

  body->set_connection(0);  // so we don't dest it
  exec(conn, body);
  destruct(body);

  LOGIN_D->logon(1);
  return 1;
}
