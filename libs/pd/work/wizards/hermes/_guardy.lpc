#include <std.h>
inherit DAEMON;
int spell();
 
int cmd_guardy(string str) {
    object ob, tp;
    int defense;
    int cost;
   if (!spell()) {
      write("What?\n");
      return 1;
   }
   tp = this_player(); 
    this_player()->set_magic_round();
    if(!str) {
        notify_fail("Cast guard on whom?\n");
        return 0;
    }
    ob = present(str, environment(this_player()));
    if(!ob) {
        if(str == "me" || str == "myself") ob = this_player();
    }
    if(!ob) {
        notify_fail(capitalize(str)+" is not here.\n");
        return 0;
    }
    if(!living(ob)) {
        notify_fail(capitalize(str)+" could not possibly be safer. :P\n");
        return 0;
    }
    if (this_player()->query_disable())
       return notify_fail("You are busy.\n");
    if(environment(this_player())->query_property("no magic")) {
        notify_fail("Something is blocking your concentration.\n");
        return 0;
    }
    if(ob == this_player()) cost = 20 + random(40);
    else cost = 20 + random(20);
    if((int)this_player()->query_mp() < cost) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    defense = (int)this_player()->query_skill("magic defense");
    write (" " + defense);
    if (defense < 10) {
       write("You mutter words beyond understanding.");
       say(tp->query_cap_name()+" mutters words beyond understanding.", tp);
       return 1;
    }
    this_player()->add_mp(-cost);
    write("You cast a magical guard upon "+ob->query_cap_name()+".");
    tell_object(ob, this_player()->query_cap_name()+
      " casts a magical guard upon you.");
    say(this_player()->query_cap_name()+" casts a magical guard upon " 
      +ob->query_cap_name()+".", ob);
    write(" "+ random(defense/5));
    write(" " + random(defense/3));
    ob->add_magic_protection( ({ 0, random(defense/5)+3, random(defense/3)+3})
);
    this_player()->add_skill_points("magic defense", random(defense/20));
    this_player()->set_disable();
    return 1;
}
void help() {
  write("
Syntax: <guardy [target]>
This spell of protection brings a magical guard upon the target.
Although it is weaker than some other protection spells, guard is
a lower-level mage spell.
");
}
int spell() {
   object tp;
   tp = this_player();
   if (tp->query_level() < 1) return 0;
   if (!tp) return 0;
   if (tp->query_skill("magic defense") >= 5 && tp->query_class() == "mage")
   return 1;
}
