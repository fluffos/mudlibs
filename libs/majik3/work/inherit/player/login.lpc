// NAME        : /secure/login.c
// DESCRIPTION : login object
// CODER       : namhas

#include <config.h>

int tries;
string password, tmp_name, name = "(null)";

int
valid_name (string str)
{
  int ret = 1;

  if (strlen(str) < 3)
    {
      efun::write ("Your name ("+str+") was too small, minimum length is 3.\n");
      return 0;
    }

  if (strlen(str) > 16)
    {
      efun::write ("Your name ("+str+") was too long, maximum length is 16.\n");
      return 0;
    }

  for (int i=0;i<strlen(str);i++)
    {
      if (str[i] < 'a' || str[i] > 'z')
        {
          efun::write ("Your name ("+str+") contains character '"+str[i..i]+
            "' which is not acceptable.\n");

          ret = 0;
        }
    }

  return ret;
}

void
logon ()
{
  object ob;

  if (query_ip_name(THOB) == "norssi.pc.helsinki.fi")
    {
      efun::write ("Sorry. We don't allow users from your site. Blame lihis@norssi.pc.helsinki.fi\n");
      ob = find_player("namhas");
      if (ob)
      tell_object (ob, "siteban from norssi.pc.helsinki.fi.\n");
      destruct (THOB);
      return;
    }

  if (query_ip_name(THOB) == "kirjasto.kirjasto.kaarina.fi")
    {
      efun::write ("Sorry. We don't allow users from your site. Blame cendor@kirjasto.kirjasto.kaarina.fi\n"); 
      ob = find_player("namhas");
      if (ob)
      tell_object (ob, "siteban from kirjasto.kirjasto.kaarina.fi.\n");
      destruct (THOB);
      return;
    }

if (query_ip_name(THOB) == "platon.sgic.fi")
{
      efun::write ("Sorry. We don't allow users from your site. Blame flamie@platon.sgic.fi\n");
      ob = find_player("namhas");
      if (ob)
        tell_object (ob, "siteban from platon.sgic.fi.\n");
      destruct (THOB);
      return;
}

  efun::write ("\033[H\033[J");
  efun::write(read_file(WELCOME_FILE));

  efun::write ("\nEnter name of your character: ");

  call_out ("do_timeout", 300);	/* 5 minutes */
  input_to ("get_name");
}

do_timeout1 ()
{
  write_file ("/log/login", ctime (time ()) + " :: timed out! (" +
	      query_ip_name (this_object ()) + ")\n");
  efun::write ("Timeout limit reached - closing connection.\n");
  destruct (this_object ());
  return 0;
}

get_name (string str)
{
  object user;

  str = lower_case(str);

  if (!str || str == "" || !valid_name (str))
    {
      if (tries > 3)
	{
	  write_file ("/log/login", ctime (time ()) + " :: too many login failures! (" +
		      query_ip_name (this_object ()) + ")\n");
	  efun::write ("Too many login failures - closing connection.\n");
	  destruct (this_object ());
	  return 0;
	}

      input_to ("get_name");
      efun::write ("Enter name of your character: ");
      tries++;
      return 0;
    }
  str = lower_case (str);
  tmp_name = str;
  tries = 0;

  if (file_size ("/data/player/" + str[0..0] + "/" + str + ".o") <= 0)
    {
      write_file ("/log/login", ctime (time ()) + " :: new user (" + str + ") from " +
		  query_ip_name (this_object ()) + "\n");
      cat (NEWUSER_FILE);
      user = new ("/secure/newuser");
      efun::exec(user, this_object());
      user->do_newuser (str);
      destruct (this_object ());
    }
  else
    {
      if (restore_object ("/data/player/" + str[0..0] + "/" + str))
	{
	  efun::write ("Password: ");
	  input_to ("check_password", 1);
	}
      else
	{
	  write_file ("/log/login", ctime (time ()) + " :: this should not happen from " + str + "@" +
		      query_ip_name (this_object ()) + "\n");
	  efun::write ("ALERT: This should not happen, please report!\a\n");
	  efun::write ("Disconnecting...\n");
	  destruct (this_object ());
	}
    }
}

check_password (string str)
{
  object user;
  write ("\n");
  if (!password || password == "")
    write ("You have no password! Please, set it with the 'password' command.\n");
  else if (crypt (str, password) != password)
    {
      efun::write ("Wrong Password!\a\n");
      write_file ("/log/login", ctime (time ()) + " :: password failure from " + name +"@" +
		  query_ip_name (this_object ()) + "\n");
      destruct (this_object ());
      return 0;
    }

  if (name && user = find_player (name))
    {
      write_file ("/log/enter", ctime (time ()) + " :: " + capitalize (name) +
		  " reconnected from " + query_ip_name () + "\n");
      efun::write ("Recovering character...\n");
      if (interactive (user))
        {
          efun::write ("You take over your own body which was already in use!\a\n");
          if (ENV(user))
            tell_room (ENV(user), user->query_cap_name() + " suddenly keels over in pain, surrounded by a white aura...\n"+user->query_cap_name() + "'s body has been taken over by a new spirit!\n", ({ THOB, user }));
          tell_object (user, "You keel over in pain as another spirit takes your body.\n");
          user->save_me();
          destruct (user);
          user = new ("/secure/player");
          user->setup (name);
        }
      user->reconnect ();
      efun::exec(user, this_object());
      destruct (this_object ());
    }
  else
    {
      write_file ("/log/enter", ctime (time ()) + " :: " + capitalize (name) +
		  " connected from " + query_ip_name () + "\n");
      user = new ("/secure/player");
      user->setup (name);
      efun::exec(user, this_object());
      destruct (this_object ());
    }
}

int
clean_up ()
{
  destruct (THOB);
  return 1;
}

string
query_name ()
{
  return "(null)";
}

string
query_cap_name ()
{
  return "(null)";
}

string
query_true_name ()
{
  return "(null)";
}

string
query_short ()
{
  return "(null)";
}

string
short ()
{
  return "(null)";
}
