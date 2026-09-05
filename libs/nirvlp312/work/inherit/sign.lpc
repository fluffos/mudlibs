/*
 * A sign used in a room
 */

inherit "inherit/base/base_obj";

string read_language;

void reset(status arg) {
  if (arg) return;

  set_name("sign");
  set_short("A Sign");
  set_long("A sign.  Perhaps you should read it?\n");
}

string set_language(string str) { return read_language = str; }
string query_language()         { return read_language;       }

string set_message(string str)  { return read_msg = str;      }
string query_message()          { return read_msg;            }

status read(string str) {
  status flag;
  string tmp_msg;

  tmp_msg = read_msg;
  read_msg = 0;
  flag = ::read(str);
  read_msg = tmp_msg;
  if (flag) {
    if (read_language && !this_player()->query_language(read_language)) {
      write("The words on the " + query_name() + " don't make sense.\n" +
            "They appear to be written in a language you don't understand.\n");
      return 1;
    }
    write(read_msg);
  }
  if (!this_player()->query_stealth_on())
    say(this_player()->query_name() + " reads the sign.\n");
  return 1;
}

status get() { return 0; }
status drop() { return 0; }

