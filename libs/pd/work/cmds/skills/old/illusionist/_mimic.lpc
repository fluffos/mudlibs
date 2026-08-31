#include <std.h>

inherit DAEMON;

int spell();

int cmd_mimic(string str) {
   object to, ob, env;
   int i;

   env = environment(this_player());
   if (!spell()) return
     notify_fail("Your powers are not strong enough to cast this.\n");
   if (env->query_property("no magic")) return notify_fail("A greater power prevents "
      "you from casting this spell here.\n");
   if (!str) return notify_fail("Mimic what?\n");
   if (!(to = present(str, this_player())))
     return notify_fail("You do not have that.\n");
   if (this_player()->query_mp() < 125) return notify_fail("Your magic is too weak at "
      "the moment.\n");
   if (to->is_armour())      { ob = new(ARMOUR); ob->set_ac(1);
                               ob->set_type(to->query_type());
                               ob->set_wear(to->query_wear());
                               ob->set_limbs(to->query_limbs()); }
   else if (to->is_weapon()) { ob = new(WEAPON); ob->set_wc(1);
                               ob->set_type(to->query_type());
                               ob->set_wield(to->query_wield());
                               ob->set_hands(to->query_hand()); }
   else ob = new(OBJECT);
   ob->set_weight(to->query_weight());
   ob->set_value(0);
   ob->set_id(to->query_id());
   ob->set_name(to->query_name());
   ob->set_long(to->query_long());
   ob->set_short(to->query_short());
   write("Using your powers of illusion, you form a mimic of "+to->query_short()+".");
   say(this_player()->query_cap_name()+" forms a copy of "+to->query_short()+".",
     this_player());
   this_player()->add_mp(-110);
   ob->move(this_player());
   return 1;
}

int spell() {
   object o;
   o = this_player();
   if (o->query_subclass() == "conjurer" && o->query_level() >= 48) return 1;
   if (o->query_subclass() == "illusionist" && o->query_level() >= 35) return 1;
}

void help() {
write(@ENDTEXT
Syntax: <mimic [object]>
This Illusionist and Conjurer spell is one of trickery. The caster
mimics an object in his or her inventory and makes a fake copy of that
item. Though the copy is not as good as the copied item, it makes a
good fake.
ENDTEXT);
}
