/*  -*- LPC -*-  */
#include <command.h>

int
main()
{
  object conn = this_player()->query_connection();
  object body = new(conn->query_body());
  object shell = new(conn->query_login_shell());
  object old_bod = this_player();
  string name = this_player()->query_name();

  if(!body || !shell) {
    if(body) destruct(body);
    if(shell) destruct(shell);
    return notify_fail("su: Couldn't clone your body or shell. Aborting.\n");
  }

  if(body->move(environment(this_player())) < 1) {
    destruct(body);
    return notify_fail("Couldn't move body to this environment.\n");
  }

  body->set_connection(conn);
  exec(body, old_bod);

  /* security -- set privs */

  old_bod->save_player();
  old_bod->set_connection(0);  // so we don't dest our conn.
  destruct(old_bod);

  body->init_player(name);
  if(!shell->shell_init(body)) {
    destruct(shell);
    return notify_fail("su: Couldn't init your shell.\n");
  }
  body->set_cap_name(conn->query_cap_name());
  body->set_gender(conn->query_gender());

  message("system", "su: exec() to new body succeeded.\n", this_player());
  return 1;
}
