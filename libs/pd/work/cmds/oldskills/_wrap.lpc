//      _wrap.c
//      for dragons, by nightshade
 
#include <std.h>
inherit DAEMON;
 
int abil();
 
int cmd_wrap(string str) {
    object ob;
    int time;
 
    if (!abil())
        return 0;
    if(!str)
        time = 1;
    else
        if(sscanf(str,"%d",time) != 1) {
            notify_fail("Syntax: <wrap [time]>\n");
            return 0;
        }
    if(time > 20)
        time = 20;
    ob = this_player();
    if(!ob->query_current_attacker()) {
        notify_fail("You have no need to wrap yourself with your tail.\n");
        return 0;
    }
    if (ob->query_disable())
        return notify_fail("You are busy.\n");
    ob->add_magic_protection( ({ 0, ob->query_skill("tail")/20+random(2)+1, time}) );
    ob->add_skill_bonus("defense",ob->query_skill("tail"), time);
    write("You wrap your tail around you protectively.");
    say(this_player()->query_cap_name()+" wraps their tail around themselves.", this_player());
    ob->set_disable();
    call_out("end",time,ob);
    return 1;
}
void end(object tp) {
    message("info","You unwrap your tail from your body.",tp);
    message("info",tp->query_cap_name()+" unwraps their tail from their body.",environment(tp),tp);
}
 
void help() {
    write("Syntax: <wrap [time]>\n\nDragons are able to wrap their tail around their body, protecting them from attacks.
Unfortunately, they are unable to attack with their tail in the way.\n");
}
int abil() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_race() != "dragon")
     return 0;
   if (o->query_level() < 13) return 0;
   return 1;
}
