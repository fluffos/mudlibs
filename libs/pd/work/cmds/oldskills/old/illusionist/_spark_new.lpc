//  9/24/00
// a dubgeonware.net production
 
#include <std.h>
 
inherit DAEMON;

int spell();
 
int cmd_spark(string str) {
 
 object tp;
 int time, attack;
 
    tp = this_player();
    tp->set_magic_round();

    if(tp->query_ghost()) return notify_fail("Your voice is hollow.\n");
    if(environment(tp)->query_property("no magic")) return
       notify_fail("Something seems to be blocking your concentration.\n");
    if(tp->query_casting()) return 1;
    if((int)tp->query_mp() < 100) return notify_fail("Too low on magic power.\n");
    tp->add_mp(-80+random(30));
  attack += tp->query_skill("magic attack")/3;
  attack += tp->query_stats("wisdom")/2;
  attack += tp->query_skill("illusion")/3;
  attack += random(tp->query_stats("dexterity")/2);
    if(attack < 5) attack = 5;
 if(attack > 60) attack=4*attack/5;
 if(attack > 100) attack=3*attack/4;
 if(attack > 200) attack=2*attack/3;
 if(attack > 400) attack=400;
 time = tp->query_skill("illusion")/(7+random(5));
 time-=2;
 time=time+random(3)-random(3);
 if(time>5) time=5;
 message("info","%^BOLD%^%^YELLOW%^A thousand sparks form around you, swirling in mystical
patterns.%^RESET%^",this_player());
 message("info","%^BOLD%^%^YELLOW%^Little sparks of light begin to form around
"+this_player()->query_cap_name()+"'s
body.%^RESET%^",environment(this_player()),this_player());
 tp->set_paralyzed(3,"You are concentrating deeply on the sparks.");
 call_out("sparks",2,({attack,time,this_player()}));
 tp->add_skill_points("illusion",attack);
 tp->add_skill_points("magic attack",attack/2);
 tp->set_casting(attack + random(tp->query_level()));
 return 1;
}
 
void help() {
 message("help", "Syntax: <spark>\n"
  "Creates thousands of sparks of light to swirl around the caster "
  "and then fire away from the caster causing everyone in sight to be "
  "stung by the sparks.",
        this_player());
}
 
void sparks(mixed *arg) {
object *inv;
int i,x;
object tp;
x=0;
tp=arg[2];
 if(environment(tp)->query_property("no attack")) {
   message("info","%^BOLD%^%^YELLOW%^Many flashing sparks suddenly dull and fade out of view "
                  "around "+tp->query_cap_name()+".%^RESET%^",environment(tp));
 return;
 }
 message("info","%^BOLD%^%^YELLOW%^Sparks fly from around you streaking across the "
                "room.%^RESET%^",tp);
 message("info","%^BOLD%^%^YELLOW%^Sparks fly from "+tp->query_cap_name()+" and streak around "
                "the room.%^RESET%^",environment(tp),tp);
 tp->add_mp(-20);
  if(arg[0] < 5 || arg[1] < 2 || tp->query_mp() < 25) {
 message("info","%^ORANGE%^The sparks die out...%^RESET%^",environment(tp));
}
 else {
 inv = ({});
 inv=all_inventory(environment(tp));
 for(i=0;i<sizeof(inv);i++) {
if(!living(inv[i])) continue;
if(random(100) > tp->query_stats("wisdom") +
tp->query_stats("dexterity") + tp->query_stats("constitution")) continue;
 if(inv[i] == tp) {
  if(random(100) > tp->query_mp()) {
     tp->do_damage("head",arg[0/3]);
 message("info","%^BOLD%^%^YELLOW%^A stray spark flies back at you, stinging you "
                "painfully.%^RESET%^",tp);
    }
     continue;
  }
 message("info","%^BOLD%^%^YELLOW%^The sparks send shocks of electricity through your "
                "body.%^RESET%^",inv[i]);
 x=1;
 inv[i]->do_damage("none",arg[0]);
 inv[i]->kill_ob(tp,0);
 if(random(100) > 95) {
 message("info","%^BOLD%^%^YELLOW%^A spark crashes into you and EXPLODES "
                "violently.%^RESET%^",inv[i]);
 inv[i]->do_damage("torso",arg[0]);
 inv[i]->add_sp(-25);
 inv[i]->set_paralyze(2,"%^BOLD%^%^YELLOW%^You are stunned briefly by the sparks.%^RESET%^");
}
}
 if(x==1) message("info","%^BOLD%^%^YELLOW%^Sparks flash violently as they crash into "
                         "people...%^RESET%^",tp);
 call_out("sparks",3+random(3),({arg[0]-3-random(5),arg[1]-1,tp}));
}
}
int spell() {
   object o;
   o = this_player();
   if (o && o->query_subclass() == "illusionist" && o->query_level() >= 10)
     return 1;
}
