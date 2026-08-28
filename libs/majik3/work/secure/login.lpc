/*
 * LOGIN OBJECT
 *
 */

/* function prototypes */

void logon();
void do_timeout();
void get_name (string);
void ask_name ();
void ask_pass ();
void get_pass (string);
void newuser ();
void logon_welcome ();

int test_user (string);

/* global variables */

int tries;
string password, name = "null";
string login_term = "unknown";
int login_rows = 24;
int login_columns = 80;
int login_real_term = 0;
int term_type_iterate = 0;
int use_ask_name_chain = 0;

void terminal_type (string term)
{
  write_file ("/log/telnet", "login: terminal_type received: "+term+"\n");
  login_term = lower_case(term);

  if (login_term[0..1] == "vt")
    login_real_term = 1;
  else if (login_term[0..4] == "linux" ||
           login_term[0..3] == "ansi" ||
           login_term[0..4] == "xterm" )
    login_real_term = 2;
  else if (login_term == "webclient")
    login_real_term = 5;
}

void window_size (mixed jotai1, mixed jotai2)
{
  write_file ("/log/telnet", "login: window_size: "+sprintf("%O, %O\n",
    jotai1, jotai2));

  login_columns = jotai1;
  login_rows = jotai2;
}

void
logon_welcome ()
{
  efun::write ("Terminal type: " + login_term + "\n");
  call_out ("do_timeout", 300);

  if (login_term == "webclient")
    efun::write (read_file("/data/config/welcome.webclient") + "\n");
  else
    efun::write (read_file("/data/config/welcome") + "\n");

  /*
   * We need to have a hack here, because the term type determination
   * logic relies on getting input to get_term_type with input_to(), but
   * input_to() callbacks cannot be removed and in some cases we get no
   * input to this callback, so we need to manually force the input to
   * the ask name chain in these cases.
   */
  use_ask_name_chain = 1;

  ask_name();
}

void
get_term_type (string str)
{
  if (use_ask_name_chain) {
    get_name (str);
    return;    
  }
  terminal_type (str);
  remove_call_out ("iterate_term_type");
  logon_welcome();
}

void
iterate_term_type ()
{
  term_type_iterate++;

  if (login_term == "unknown" && term_type_iterate < 5) {
    if (term_type_iterate == 1)
      efun::write ("\rDetermining terminal type...\n");
    call_out ("iterate_term_type", 1);
  } else
    logon_welcome();
}

void
logon ()
{
  input_to ("get_term_type", 0);
  call_out ("iterate_term_type", 0);

  write_file ("/log/logins", ctime() + " :: " + " connection\n");
}

void
ask_name ()
{
  if (login_real_term == 5)
    efun::write ("What is your character's name?\n");
  else
    efun::write ("What is your character's name? ");
  input_to ("get_name", 0);
}

void
ask_pass ()
{
  if (login_real_term == 5)
    efun::write ("Password:\n");
  else
    efun::write ("Password: ");
  input_to ("get_pass", 1);
}

void
do_timeout ()
{
  efun::write ("\nSorry. Timeout limit reached.\n\n");
  destruct (THOB);
}

int
test_user (string str)
{
  if (file_size ("/data/player/" + str[0..0] + "/" + str + ".o") > 0)
    return 1;
  else
    return 0;
}

void
get_name (string str)
{
  str = lower_case (str);

  write_file ("/log/logins", ctime() + " :: " + " login: " + str + "\n");

  if (str == "guest")
    str = ({ "guest1", "guest2", "guest3" })[random(3)];

  if (str == "guest1")
    {
      object o = new ("/secure/player");
      efun::exec (o, THOB);
      o->set ("term", login_real_term);
      o->move ("/world/misc/race");
      o->setup ("/daemon/guest"->next(), 1);
      destruct (THOB);
      return;
    }
  else if (str == "guest2")
    {
      object o = new ("/secure/player");
      efun::exec (o, THOB);
      o->set ("term", login_real_term);
      o->move ("/world/misc/race");
      o->setup ("/daemon/guest"->next(), 2);
      destruct (THOB);
      return;
    }
  else if (str == "guest3")
    {
      object o = new ("/secure/player");
      efun::exec (o, THOB);
      o->set ("term", login_real_term);
      o->move ("/world/misc/race");
      o->setup ("/daemon/guest"->next(), 3);
      destruct (THOB);
      return;
    }
  else if (str == "new")
    {
      efun::write (read_file("/data/config/newuser"));
      newuser();
      return;
    }
  else if (!test_user (str))
    {
      efun::write ("No character with that name exists.\n\n");
      efun::write ("To visit the game:\n");
      efun::write ("    please login as 'guest1', 'guest2' or 'guest3'.\n\n");
      efun::write ("To create a new character:\n");
      efun::write ("    please login as 'new'.\n\n");
      tries++;
    }
  else
    {
      name = str;
      ask_pass ();
      return;
    }

  if (tries > 2)
    {
      efun::write ("Too many login failures.\n\n");
      destruct (THOB);
    }

  ask_name ();
}

void
get_pass (string str)
{
  object o;

  if (restore_object ("/data/player/" + name[0..0] + "/" + name))
    {
      if (!password || password == "")
        {
          efun::write ("\nYou have no password.\n\n");
        }
      else if (crypt (str, "Os") != password)
        {
          efun::write ("\nLogin incorrect.\n\n");
          ask_name();
          return;
        }
    }
  else
    {
      efun::write ("\nError: Couldn't restore the object!\n\n");
      ask_name();
      return;
    }

  if (name)
    {
      o = find_player (name);

      if (o)
        {
          o->save_me();
          efun::write ("\nRecovering character...\n\n");

            if (interactive (o))
              {
                if (ENV(o))
                  act (o, "$n twiches briefly.");

                destruct (o);

                o = new ("/secure/player");
                o->setup (name);
              }

          o->reconnect ();
          efun::exec (o, THOB);
          destruct (THOB);
        }
      else
        {
          o = new ("/secure/player");
          o->setup (name);
          efun::exec (o, THOB);
          destruct (THOB);
        }
    }
}

void
newuser ()
{
  object o;

  o = new ("/secure/newuser");
  efun::exec(o, THOB);
  o->do_newuser (login_real_term);
  destruct (THOB);
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
  if (name)
    return "(" + name + ")";
  else
    return "(null)";
}

string
query_cap_name ()
{
  if (name)
    return "(" + name + ")";
  else
    return "(null)";
}

string
query_true_name ()
{
  if (name)
    return "(" + name + ")";
  else
    return "(null)";
}

string
query_short ()
{
  if (name)
    return "(" + name + ")";
  else
    return "(null)";
}

string
short ()
{
  if (name)
    return "(" + name + ")";
  else
    return "(null)";
}
