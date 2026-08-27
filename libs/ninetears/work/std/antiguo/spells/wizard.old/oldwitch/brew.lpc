#include "spells.h"

mixed *actions;
string name;

start(s)
{
   string obs;
   int i, total;
   mixed *chants;
   object pot;

   if (sscanf(s, "on %s", obs) != 1) {
      notify_fail("You must use this technique on some sort of container.\n");
      return 0;
   }
   pot = find_match(obs, ({ environment(this_player()), this_player() }));
   if (sizeof(pot)) pot = pot[0];
   else {
      notify_fail("There is no " + obs + " here.\n");
      return 0;
   }

   if (0&&sizeof(this_player()->query_spell_effects_type("dancing"))) {
      notify_fail("You are currently dancing vigorously around a pot.  I fail "
         "to see how you can stir something at the same time.\n");
      return 0;
   }
   if (0&&sizeof(this_player()->query_spell_effects_type("brewing"))) {
      notify_fail("You are already stirring something, so either grow a few "
         "more arms, or be patient!\n");
      return 0;
   }
   chants = this_player()->query_spell_effects_type("chanting");
   if (0&&sizeof(chants)) {
      if (chants[0][SP_PARAM][0] != pot) {
         notify_fail("You are already chanting over a different pot!\n");
         return 0;
      }
   }

   if (!pot->query_property("liquid")) {
      notify_fail("The " + pot->short() + " couldn't hold liquid to be stirred if it "
         "tried.\n");
      return 0;
   }
   if (pot->query_volume() <= 0) {
      notify_fail("The " + pot->short() + " is bone dry!\n");
      return 0;
   }
   if (pot->query_max_volume() < 1000) {
      notify_fail("The " + pot->short() + " is much too small to stir.\n");
      return 0;
   }
   if (pot->query_volume() < 200) {
      notify_fail("There is hardly enough liquid in the " + pot->short() + 
         " to wet the sides, let alone stir.\n");
      return 0;
   }
   if (environment(pot) == this_player() &&
       pot->query_weight() > this_player()->query_strength() * 10) {
      notify_fail("You are not strong enough to carry the " + pot->short() + 
         " in one arm while you stir with the other, so perhaps you will have to put it down.\n");
      return 0;
   }
   this_object()->define_actions(pot);
   
   for (i = 0; i < sizeof(actions); i += 3) {
      total += actions[i];
   }

   this_player()->add_spell_effect(total, "brewing", name, this_object(), "do_action", 
      ({ pot, this_player() }) );
   write("You begin \"" + name + "\".\n");
   return 1;
}

define_actions()
{
   actions = ({ });
   name = "nothing brewing";
}

do_action(attackee, params, rnds)
{
   object pot, brewer;
   int i, done;

   done = rnds == 1;

   brewer = params[1];
   pot = params[0];

   for (i = sizeof(actions) - 3; i >= 0; i -= 3) {
      rnds -= actions[i];
      if (rnds < 0) return;   /* in a gap */
      if (rnds == 0) break;
   }

   handle_action(actions[i+1], actions[i+2], pot, brewer);
   if (done) {
      tell_object(brewer, "You complete \""+name+"\".\n");
      this_object()->completed();
   }
   return 0;
}


#define KWORD_NAME "NAME"
#define KWORD_POSS "POSS"
#define KWORD_POT "POT"

sub_bits_for_observer(s, pot, brewer)
{
   s = implode(explode(KWORD_NAME+s+KWORD_NAME, KWORD_NAME), brewer->short());
   s = implode(explode(KWORD_POSS+s+KWORD_POSS, KWORD_POSS), brewer->query_possessive());
   s = implode(explode(KWORD_POT+s+KWORD_POT, KWORD_POT), pot->short());
   return s;
}

handle_action(brewer_s, observer_s, pot, brewer)
{

   if (!observer_s) observer_s = brewer_s;
   tell_object(brewer, sub_bits_for_observer(brewer_s, pot, brewer));
   tell_room(environment(brewer), sub_bits_for_observer(observer_s, pot, brewer), brewer);
   return 0;
}
