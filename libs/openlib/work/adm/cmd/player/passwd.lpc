/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>
#include <login.h>

int
main()
{
  write("Old password: ");
  input_to("get_passwd", 1, this_player()->query_name());
  return 1;
}

void
get_passwd(string input, string username)
{
  write("\n");

  if(!LOGIN_D->check_passwd(username, input)) {
    write("Incorrect password.\n");
    return;
  }

  write("New password: ");
  input_to("get_new_passwd", 1, username, 0);
}

void
get_new_passwd(string input, string username, string last_time)
{
  object conn;

  write("\n");

  if(!last_time) {
    write("Again for verification: ");
    input_to("get_new_passwd", 1, username, input);
    return;
  }

  if(input != last_time) {
    write("They don't match!!  Password left unchanged.\n");
    return;
  }

  conn = new(CONNECTION_OB);
  conn->restore_connection(username);
  if(!conn->set_password(crypt(input, 0))) {
    write("Call to set_password failed.  Password left unchanged.\n");
    destruct(conn);
    return;
  }
  conn->save_connection(username);
  destruct(conn);
  write("Password changed.\n");
}
