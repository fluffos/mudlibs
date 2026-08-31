//      Stormy
//      Cleregy ability
#include <std.h>
inherit DAEMON;
int spell();
int cmd_sense(string str) {
    object ob;
   if (!spell()) {
       write("What?\n");
      return 1;
   }
    if(!str) {
       notify_fail("Sense whom?\n");
      return 0;
    }
    if (this_player()->query_disable())
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
    if (this_player()->query_skill("faith") < 10 + random(40)) {
       this_player()->add_mp(-20);
       return notify_fail("You fail to sense anything.\n");
    }
    say(this_player()->query_cap_name()+" mutters a prayer as "+this_player()->query_subjective()+" concentrates on "+(string)ob->query_cap_name()+".", this_player());
    this_player()->set_magic_round();
    this_player()->add_mp(-20);
    this_player()->add_skill_points("faith", random(10)+10);
    write((string)ob->query_cap_name()+" is "+capitalize(ob->query_al_title())+".");
    this_player()->set_disable();
    return 1;
}
void help() {
    write("Syntax: <sense [living]>\n\n"
        "Allows a clergy to sense anothers alignment.\n");
}
int spell() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_class() != "clergy") return 0;
   if (o->query_level() < 9) return 0;
   return 1;
}
