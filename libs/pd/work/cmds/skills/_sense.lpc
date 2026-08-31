//      Stormy
//      Cleregy ability
#include <std.h>
inherit DAEMON;
int spell();
string type() {
  if (this_player() && this_player()->query_subclass() == "gypsy")
    return "conjuring";
  return "faith";
}
int cmd_sense(string str) {
    object ob;
    string skill, what;
   if (!spell()) {
       return 0;
   }
    if(!str) {
       notify_fail("Sense whom?\n");
      return 0;
    }
    if (this_player()->query_busy())
      return notify_fail("You are busy.\n");
    if(!(ob = present(lower_case(str), environment(this_player())))) {
       notify_fail("No "+capitalize(str)+" here.\n");
        return 0;
    }
    if(this_player()->query_mp() < 19) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if(!living(ob)) {
       write(capitalize(str)+" is not alive.");
        return 1;
    }
    if(environment(this_player())->query_property("no magic")) {
        notify_fail("A magic force prevents you from using your magic.\n");
        return 0;
    }
    if (this_player()->query_subclass() == "gypsy") {
      skill = "clairvoyance";
      what = "a spell";
    }
    else {
      skill = "faith";
      what = "a prayer";
    }
    if (this_player()->query_skill(skill) < 10 + random(40)) {
       this_player()->add_mp(-20);
       return notify_fail("You fail to sense anything.\n");
    }
    say(this_player()->query_cap_name()+" mutters "+what+" as "+this_player()->query_subjective()+" concentrates on "+(string)ob->query_cap_name()+".", this_player());
    this_player()->set_magic_round();
    this_player()->add_mp(-20);
    this_player()->add_skill_points(skill, random(10)+10);
    write((string)ob->query_cap_name()+" is "+capitalize(ob->query_al_title())+".");
    return 1;
}
void help() {
    write("Syntax: <sense [living]>\n\n"
        "Allows the user to sense another's alignment.\n");
}
int spell() {
   object o;
   o = this_player();
   if (o && o->query_level() >= 9 &&
      (o->query_class() == "clergy" || o->query_subclass() == "white" || o->query_subclass() == "gypsy"))
        return 1;
  return 0;
}
