// reused the code from shield
 
#include <std.h>

#define COL "%^BOLD%^%^CYAN%^"
#define UNCOL "%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <crystallize [whom]>\n\n"
    "This spell conjures a shielding of sharp icicles around the body "
    "of the target.",this_player());
}

int spell() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_subclass() == "blue" &&
        o->query_skill("magic defense") >= 4*35)
          return 1;
    return 0;
}

int cmd_crystallize(string str) {
    object ob;
    int defense, def;
    int cost, amount, time;
 
    if (!spell())
        return 0;

    if(!str)
      return notify_fail("Crystallize whom?\n");

    if(str == "me" || str == "myself") ob = this_player();
    else ob = present(str, environment(this_player()));
    if(!ob)
        return notify_fail("You don't see "+capitalize(str)+" here.\n");
        
    if (ob->query("crystallize_spell_wait")) {
        if( ob == this_player() )
            write("You are already covered in ice.\n");
        else
            write(ob->query_cap_name() + " is already covered in ice.");
        return 1;
    }

    if(!living(ob))
        return notify_fail("That is not alive!\n");

    if(environment(this_player())->query_property("no magic"))
        return notify_fail("Something is blocking your concentration.\n");

    defense = (int)this_player()->query_skill("magic defense");
    cost = defense + 50 + random(defense/4);

    if (this_player()->query_mp() < cost)
      return notify_fail("Too low on magic.\n");
    
    this_player()->set_magic_round(1);
    
    if (defense < 50) def = 1; else
    if (defense < 90) def = 2; else
    if (defense < 140) def = 3; else
    if (defense < 180) def = 4; else
    if (defense >= 180) def = 5; 
    amount = def+1;
    time = (def*20)+random(def*2);

    ob->add_magic_protection( ({ 0, amount , time }));
    ob->add_skill_bonus("attack", this_player()->query_skill("conjuring")/2, time);
    ob->set("crystallize_spell_wait",1);

    call_out("shield_off", time, ob);
    this_player()->set_disable();
    this_player()->add_skill_points("magic defense", random(defense/30));
    this_player()->add_skill_points("conjuring", random(defense/30));
    this_player()->add_mp(-(cost+random(20)));

    message("info", COL+"Icicles crystallize all around "+
                    ob->query_cap_name()+"."+RES, environment(ob), ob);
    message("info", COL+"Icicles crystallize all around you."+RES, ob);
    
    return 1;
}

void shield_off(object ob) {
    if( !ob )
        return;
    
    message("info", UNCOL+"The ice covering you shatters and melts away."+RES, ob);
    message("info", UNCOL+"The ice covering "+ob->query_cap_name()+
                    " shatters and melts away.", environment(ob), ob);
    ob->set("crystallize_spell_wait",0);
}
 
