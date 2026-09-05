/* illusion shadow for visual illusion, and permanent illusion spells */

inherit "obj/shadows/shadow";
inherit "inherit/timer";

string illusion_name;
string illusion_short;
string illusion_long;
object who;

void illusion(object ob, string name, string short, string long) {
  who = ob;

  if (name != "") illusion_name = name;
  if (short != "") illusion_short = short;
  if (long != "") illusion_long = long;
  log_file("Illusions",
"Permanent illusion of " + (string)who->query_name(1) + ":" + file_name(who) +
"\n" + "  Caster: " + (string)this_player()->query_name(1) +
"\n" + "  Name: " + illusion_name +
"\n" + "  Short: " + illusion_short +
"\n" + "  Long: " + illusion_long + "\n");
  shadow_object(who);
}

string query_name(status arg) {
  if (arg) return (string)who->query_name(1);
  if (!illusion_name) return (string)who->query_name(arg);
  return illusion_name;
}

string short(status wiz, status true_sight) {
  if (!illusion_short) return (string)who->short(wiz);
  if (wiz || true_sight) {
    return "Illusion of " + illusion_short + " on " + (string)who->short(wiz);
  }
  return illusion_short;
}

void long(status wiz, status true_sight) {
  if (!illusion_long)
    who->long(wiz);
  else {
    if (wiz || true_sight) write("There is an illusion: \n");
    write(illusion_long + "\n");
    if (wiz || true_sight) {
      write("\nWhich is Really:\n");
      who->long(wiz);
    }
  }
}

status id(string str) {
  return str == query_name(0) ||
         str == "Illusion" ||
         (status)who->id(str);
}

object query_illusion_object() { return this_object(); }

void time_out() {
  tell_room(environment(who), "An Illusion of " + illusion_short +
            " dissapates to reveal " + (string)who->short() + ".\n");
  ::time_out();
}

void dispel_magic() { time_out(); }

