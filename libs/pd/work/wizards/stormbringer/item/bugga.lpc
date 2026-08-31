#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("bugga");
   set_short("");
   set_id(({ "bugga" }));
   set_long("Bugga!!");
   set_value(0);
   set_property("no steal", 1);
}

void init() {
 ::init();
   add_action("Bugga", "bugga");
}

int Bugga(string str) {
    string limb;
    object ob;   
    int amount;
  
    this_player()->force_me("say whoooo");
    if(this_player()->is_player()) remove();
    ob = this_player()->query_current_attacker();
//    if(!ob) return 1;
    limb = (string)ob->return_limb();
    if((string)ob->query_class() == "rogue") amount = 24 + random(30);
    else amount = 20 + random(20);
    ob->do_damage(limb, amount);
        tell_object(ob, "The guard bashes your "+limb+" with his "
                    "left fist!");
    tell_room(environment(this_player()), "The guard bashes "
        +ob->query_cap_name()+"'s "+
        limb+" with his left fist!", ({ ob }));
    return 1;
}
