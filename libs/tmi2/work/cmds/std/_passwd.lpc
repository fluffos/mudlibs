// This is part of the TMI distribution mudlib.
// Please retain this header if you use this file.
// Written by Sulam (12-9-91)
// Help added by Brian (1/28/92)
// A security loop-hole found by Ellery and fixed by Pallando. (93/01/14)
// "Multithreading" added by Buddha (4/20/93)
// 93-08-15 Grendel@tmi-2 fixed to allow admins to change non-admins passwds

#include <mudlib.h>
#include <daemons.h>
#include <logs.h>

#define log( x ) log_file( "PASSWD_LOG", iwrap( "passwd " + ctime(time()) + " "+\
  identify( ({ this_object(), previous_object(), this_player(), x }) ) ) )
#define HACK log(0); notify_fail( "Sorry.  Password security problem.\n" );\
  return 0

inherit DAEMON ;

#define SYNTAX "usage: passwd [<player>]\n"

nomask int
cmd_passwd(string arg)
{
  string name;
  object link, ob;

  if( !this_player()
      || !userp( this_player() )
      || this_player() != this_player( 1 )
      || this_player() != previous_object() )
      { HACK; }

  name = geteuid(previous_object());
  if(arg && arg != "")
    {
      if(!user_exists(arg))
	{
	  notify_fail("passwd: no such user\n");
	  return 0;
	}
      if(!adminp(name) || member_group(arg))
	{
	  notify_fail("passwd: parmission denied\n");
	  return 0;
	}
      name = arg;
      ob = find_player(arg);
      if(ob)
	link = (object)ob->query_link();
      else
	link = (object)FINGER_D->restore_data(name);
      write("Changing password for "+name+" on " + mud_name() + "\n");
      write("New password:");
      input_to("newpass", 1, link);
    }
  else
    {
      link = (object)previous_object()->query_link();
      write("Old password:");
      input_to("oldpass", 1, link);
    }

  return 1;
}

protected nomask int
oldpass(string pass, object link)
{
  string password;

  write ("\n") ;
  if (!pass)
    {
      write ("The null string is not an acceptable password.\n") ;
      return 0 ;
    }
  password = (string)link->query("password") ;
  if (password != crypt(pass, password))
    {
      write ("Password incorrect.\n") ;
      return 0 ;
    }
  write("New password:");
  input_to("newpass", 1, link);
  return 1;
}

protected nomask int
newpass(string pass, object link)
{
  write ("\n") ;
  if (!pass || strlen(pass)<5)
    {
      write("Your new password must have more than 5 characters.\n");
      link->clean_up();
      return 0;
    }
  write("Again:");
  input_to("npass2", 1, pass, link);
  return 1;
}

protected nomask int
npass2(string pass, string tmp, object link)
{
  write ("\n") ;
  if (pass != tmp)
    {
      write("The passwords must match.\n");
      link->clean_up();
      return 0;
    }
  if (this_player(1) != this_player()) { HACK; } 

  pass = crypt(pass, 0);
  link->set("password", pass);
  link->save_data();
  link->clean_up();
  write ("passwd: password has been changed\n") ;
  return 1;
}

string help()
{
  return(SYNTAX +"\n"+ @HELP
This command changes your password.  You should do this immediately
if you suspect that someone knows your old one.

Admins can use this command to change the password of any non-admin.

See also: chfn
HELP
			  );
}

/* EOF */
