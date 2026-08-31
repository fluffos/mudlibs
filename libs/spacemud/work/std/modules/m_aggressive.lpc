/* Do not remove the headers from this file! see /USAGE for more info. */

// aggressive.c
// Inheritable for aggressive monsters
// Onyx@Red Dragon
// NOTE: Someone who understands Lima vanilla combat should edit the
// line I indicated to make this compat.
// 12 May, 1998: Iizuka updated to support the new adversary code.
// 27 June, 2020: Tsath updated to not use hooks since they're already in adversary.

//: MODULE
// Module for agressive monsters that will attack players given a specific chance to do so.
// Module will check if player is a wizard, and not attack the wizard.
//
// .. TAGS: RST

void start_fight(object who);

private
int aggression_chance = 100;
private
int attack_delay = 5;
private
void behavior_hooks();

//: FUNCTION aggressively_attack
// void aggressively_attack();
// Start the fight.
void aggressively_attack(object who)
{
   if (who)
      if (wizardp(who) && environment(this_object()) && environment(this_object())->contains(who))
         who->targetted_action("$N $vwould have been attacked by $t, but $n1 reconsidered.", this_object());
      else
         call_out("start_fight", (1 + random(attack_delay)), who);
}

//: FUNCTION handle_attack
// By default, this compares a random number to aggression_chance
// and starts attacking based upon them. This function might be
// overloaded to perform racial checks or something though.
// This function checks for whether combat is allowed in the room as well.
protected
void handle_attack(object who)
{
   if (random(100) < aggression_chance && who->is_visible() && who->is_body() && environment() &&
       !environment()->query_combat_forbidden())
      call_out("aggressively_attack", (1 + random(attack_delay)), who);
}

// It checks to see which objects in the room are players and attacks them.
void i_met(object who)
{
   object item;
   if (who == this_object())
      foreach (item in all_inventory(environment()))
      {
         if (item->attackable() && item != this_object())
            handle_attack(item);
      }
   else
      handle_attack(who);
}

//: FUNCTION set_aggressive
// This function is used to set the aggression chance of a monster in the
// range 0 (never aggressive) to 100 (completely aggressive).
void set_aggressive(int a)
{
   call_out("behavior_hooks", 1);
   aggression_chance = a;
}

//: FUNCTION query_aggressive
// This function returns 0 for unaggressive monsters, or the chance of
// aggression for aggressive monsters.
int query_aggressive()
{
   return aggression_chance;
}
