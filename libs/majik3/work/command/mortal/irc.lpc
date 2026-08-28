// DESCRIPTION : interface for internet relay chat
// CODER       : namhas

#include <socket.h>

int
main (string str)
{
  string nickname;
  object ob;

  if (!str)
    {
      notify_fail ("Usage: irc <on / off> [nickname]\n");
      return 0;
    }

  sscanf (str, "%s %s", str, nickname);

  if (str == "on")
    {
      ob = new("/obj/irc_ob");
      ob->set_name ("irc_object");
      ob->set_invis (1);
      ob->set_no_autoload (1);
      ob->set_no_clean_up (1);
      ob->move (THIS);
      ob->main (THIS, nickname);
    }
  else if (str == "off")
    {
      ob = present("irc_object");

      if (ob);
        destruct (ob);

      write ("Channel irc is now disabled.\n");
      THIS->disable_channel("irc");
    }
  else
    {
      write ("You have to turn irc on using command '^c1irc on^c0' first.\n");  
    }

  return 1;
}

query_author ()
{
  return "namhas";
}

query_synopsis ()
{
  return "irc <on/off> [name]";
}

query_help ()
{
  return "This commands sends you to the IRC (Internet Relay Chat), " +
   "please read help page irc(0) for more information.";
}

query_see_also ()
{
  return "irc(0)";
}

query_position ()
{
  return POS_RESTING;
}

