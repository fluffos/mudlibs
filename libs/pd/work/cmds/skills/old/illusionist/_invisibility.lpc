// a dungeonware.net messup. -00.06.10-

#include <std.h>
inherit DAEMON;
int spell();
 
int cmd_invisibility(string str) {
    object ob;
    int inv;
    int cost;
 
   if (!spell()) {
      notify_fail("Your powers are not strong enough.\n");
      return 0;
   }
    this_player()->set_magic_round();
    if(!str) {
        notify_fail("Cast a invisibility on whom?\n");
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
        notify_fail(capitalize(str)+" is not alive!\n");
        return 0;
    }
    if(ob->query_invis()) {
        notify_fail("Make the invisible invisible?\n");
}
    if(environment(this_player())->query_property("no magic")) {
	notify_fail("Something is blocking your concentration.\n");
	return 0;
    }
    if(ob == this_player()) cost = 50 + random(150);
    else cost = 50 + random(75);
    if((int)this_player()->query_mp() < cost) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
   inv = (int)this_player()->query_skill("conjuring");
   if(inv < 70) {
        write("You mutter words beyond your understanding.");
        say(this_player()->query_cap_name()+" mutters words beyond "+
          this_player()->query_possessive()+" understanding.", this_player());
        return 1;
    }
    if(!alignment_ok(this_player())) {
        write("You have betrayed the source of your powers.");
        return 1;
    }
    if (ob->query_invis())
      return notify_fail("That person is already invisible!!!!\n");
    this_player()->add_mp(-cost);
    write("You look at "+ob->query_cap_name()+" and call on your powers of illusion.");
    tell_object(ob, this_player()->query_cap_name()+
      " looks at you and calls on "+this_player()->query_possessive()+
      " powers of illusion.");
    say(this_player()->query_cap_name()+" looks at "+ob->query_cap_name()+
" and calls on "+this_player()->query_possessive()+" powers of illusion.",
      ob);
    if(random(101) > inv) {
        this_player()->add_skill_points("conjuring", random(10));
        return 1;
    }
if (!wizardp(this_player())) {
    ob->set_invis();
    call_out("take_off", inv/3+1, ob);
   } else 
     {
      ob->set_invis();
      call_out("take_off", 50, ob);
     }
    this_player()->set_magic_round();
    this_player()->add_skill_points("conjuring", random(inv/2));
    this_player()->add_exp(random(inv));
    return 1;
}

void help() {
write("Syntax: <invisibility [player]>\n\nA very powerful spell of invisiblity for the mighty.");
}

void take_off(object ob)
{
 if (ob->query_invis()) ob->set_invis();
}
int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_class() != "mage")
      return 0;
   if (tp->query_subclass() != "illusionist")
      return 0;
   if (tp->query_level() < 2) return 0;
   return 1;
}
