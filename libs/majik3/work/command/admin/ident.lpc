// DESCRIPTION : interface for identd service
// CODER       : namhas

#include <socket.h>

object sock;
object gob;

string roina;

read_func (object socket, string data, string address)
{
  roina = data;
}

close_func ()
{
  string user, tmp1;
  int tmp2;

  /* clean-up the string */

  roina = replace_string(roina, "\n", "");
  roina = replace_string(roina, "\r", "");
  roina = replace_string(roina, " " , "");

  sscanf (roina, "%d,%d:%s:%s:%s", tmp2, tmp2, tmp1, tmp1, user);

  if (!user || user == "")
    gob->set_ident ("unknown");
  else
    gob->set_ident (user);
}

do_auth ()
{
  int port;

  sock = new (SOCKET, SKT_STYLE_CONNECT, query_ip_number(gob) + " 113",
         (: read_func :), (: close_func :));

  if (!sock)
    return;

  sscanf(socket_address(gob), "%s %d", roina, port);
  roina = "";

  sock->send (port+", "+(__PORT__)+"\r\n");
}

int
main (string str)
{
  gob = (str && find_player(str)) ? find_player(str) : previous_object();
  roina = "";

  if (!interactive(gob) || !gob)
    {
      write ("No such idiot online.\n");
      return 1;
    }

  do_auth ();
  return 1;
}
