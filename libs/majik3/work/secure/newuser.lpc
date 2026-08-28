/*
 * NEWUSER OBJECT - PART OF PLAYER OBJECT (/secure/newuser)
 *
 */

inherit "/inherit/receive";

#define PREV         previous_object()
#define pline(x)     message ("0", x, THIS);

int success;
string pass, name = "null";
object plob;

void prompt (string x)
{
  if (term == 5)
    message ("4", x + "\n", THIS);
  else
    message ("4", x, THIS);
}

int
valid_mail (string str)
{
  string user, host;

  if (sscanf (str, "%s@%s", user, host) == 2)
    return 1;
  else
    {
      pline ("\"" + str + "\" is not valid e-mail address.\n\n");
      return 0;
    }
}

int
valid_pass (string str)
{
  if (strlen(str) < 5)
    {
      pline ("The password was too short, minimum length is 5 characters.\n\n");
      return 0;
    }

  if (strlen(str) > 8)
    {
      pline ("The password was too long, maximum length is 8 characters.\n\n");
      return 0;
    }

  return 1;
}

int
valid_name (string str)
{
  if (strlen(str) < 3)
    {
      pline ("The name was too short, minimum length is 3 characters.\n\n");
      return 0;
    }

  if (strlen(str) > 16)
    {
      pline ("The name was too long, maximum length is 16 characters.\n\n");
      return 0;
    }

  if (file_size ("/data/player/" + str[0..0] + "/" + str + ".o") > 0)
    {
      pline ("The name is already in use.\n\n");
      return 0;
    }

  for (int i=0;i<strlen(str);i++)
    {
      if (str[i] < 'a' || str[i] > 'z')
        {
          pline ("The name contains character '"+str[i..i]+
            "' which is not acceptable.\n\n");

          return 0;
        }
    }

  return 1;
}

do_newuser (int login_real_term)
{
  term = login_real_term;
  prompt ("What name will your new character have? ");
  input_to ("ask_newuser");
}

ask_newuser (string str)
{
  str = lower_case(str);

  if (!str || str == "")
    {
      destruct (THOB);
      return;
    }

  if (!valid_name(str))
    {
      do_newuser();
      return;
    }

  name = str;

  plob = new ("/secure/player");

  ask_pass ();  
  return 0;
}

ask_pass ()
{
  prompt ("What will your password be, "+capitalize(name)+"? ");
  input_to ("get_pass", 1);
}

ask_retype ()
{
  prompt ("Please repeat your password: ");
  input_to ("get_retype", 1);
}

ask_ansi ()
{
  prompt ("Do you want colors? ");
  input_to ("get_ansi", 0);
}

ask_email ()
{
  prompt ("Please enter your email address: ");
  input_to ("get_email", 0);
}

ask_realname ()
{
  prompt ("Please enter your full realname: ");
  input_to ("get_realname", 0);
}

ask_gender ()
{
  prompt ("Do you want to be (m)ale or (f)emale? ");
  input_to ("get_gender", 0);
}

get_ansi (string str)
{
  if (!str || str == "")
    {
      pline ("Please answer yes or no.\n\n");
      ask_ansi();
      return;
    }

  if (lower_case(str)[0] != "n")
    {
      if (THIS->query ("term") == 5)
        plob->set ("term", 5);
      else
        plob->set ("term", 2);
    }
  else
    {
      plob->set ("term", 0);
    }

  ask_email();
}

get_email (string str)
{
  if (!str || str == "")
    {
      plob->set ("email", "no e-mail address");
    }

  if (!valid_mail(str))
    {
      ask_email();
      return;
    }

  plob->set("email", str);
  ask_realname();
}  

get_realname(string str)
{
  if (!str || str == "")
    {
      pline ("You need to have realname!\n\n");
      ask_realname();
      return;
    }

  plob->set("real_name", str);
  plob->set("creation_date", time());
  plob->set("creation_time", TIME_D->gtime());
  plob->set("name", name);

  ask_gender();
}

get_gender(string str)
{
  if (lower_case(str) == "m")
    plob->set("gender", 1);
  else
    plob->set("gender", 2);

  pline ("Character creation almost done. You can now look around.\n");
  pline ("Please read '^c1help alpha^c0' as soon as you can.\n");
  plob->set ("term", term);
  plob->save_me();
  destruct (plob);
  plob = new ("/secure/player");
  efun::exec (plob, this_object());
  plob->setup (name);
  success = 1;
  destruct (THOB);
  return 1;
}

get_pass (string str)
{
  pline ("\n");

  if (!str || str == "")
    {
      destruct (THOB);
      return 0;
    }  

  if (!valid_pass(str))
    {
      ask_pass();
      return 0;
    }

  pass = str;
  ask_retype();  
  return 0;
}

get_retype (string str)
{
  pline ("\n");

  if (str != pass)
    {
      pline ("They don't match; try again.\n\n");
      ask_pass ();
      return 0;
    }

  plob->set("password", crypt (str, "Os"));
  ask_ansi();
  return 0;
}

query_name() { return "("+name+")"; }
query_true_name() { return "("+name+")"; }
short() { return "("+name+")"; }
query_short() { return "("+name+")"; }
query_cap_name() { return "("+name+")"; }
