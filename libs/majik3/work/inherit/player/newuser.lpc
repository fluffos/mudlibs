/*
 * NEWUSER OBJECT - PART OF PLAYER OBJECT (/secure/newuser)
 *
 */

inherit "/inherit/receive";

#define PREV         previous_object()
#define pline(x)     message ("0", x, THIS);
#define prompt(x)    message ("4", x, THIS);

int success;
string tmp, name;
object plob;

do_newuser (string str)
{
  if (str)
    name = str;

  prompt ("Are you ABSOLUTELY sure you want to create a new character (y/N): ");
  input_to ("ask_newuser");
  return 1;
}

ask_newuser (string str)
{
  if (lower_case(str) != "y") {
    destruct (THOB);
    return 1;
  }

  plob = new ("/secure/player");

  prompt ("Do you want ANSI colors (y/N): ");
  input_to ("ask_color");

  return 0;
}

ask_color (string str)
{
  if (lower_case(str) != "y")
    plob->set ("term", 0);
  else
    plob->set ("term", 2);

  prompt ("Pick a password: ");
  input_to ("ask_passwd", 1);

  return 0;
}

ask_passwd (string str)
{
  pline ("\n");

  if (!str || str == "")
    {
      pline ("Try again another time then.\n");
      destruct (THOB);
      return 0;
    }

  if (strlen (str) < 6)
    {
      pline ("The password MUST have at least 6 characters.\n");
      prompt ("Pick a password: ");
      input_to ("ask_passwd", 1);
      return 0;
    }

  if (!tmp)
    {
      prompt ("Retype the password: ");
      input_to ("ask_passwd", 1);
      tmp = str;
      return 0;
    }

  if (str != tmp)
    {
      write ("Password was different. Sorry.\n");
      success = 0;
      destruct (THOB);
      return 0;
    }

  plob->set("password", crypt (str, 0));

  prompt ("Please enter your e-mail address (user@host): ");
  input_to ("ask_email");
  return 1;
}

ask_email (string str)
{
  plob->set("email", str);
  prompt ("Enter your full real name in real life: ");
  input_to ("ask_realname");
  return 1;
}

ask_realname (string str)
{
  plob->set("real_name", str);
  plob->set("creation_date", time());
  plob->set("creation_time", TIME_D->gtime());
  plob->set("name", name);

  prompt ("Are you (m)ale or (f)emale: ");
  input_to ("ask_gender");
  return 1;
}

ask_gender (string str)
{
  if (lower_case(str) == "m")
    plob->set("gender", 1);
  else
    plob->set("gender", 2);

  pline ("Character creation almost done. You can now look around.\n");
  plob->save_me();
  destruct (plob);
  plob = new ("/secure/player");
  efun::exec (plob, this_object());
  plob->setup (name);
  success = 1;
  destruct (THOB);
  return 1;
}
