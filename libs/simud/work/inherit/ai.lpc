/** This object is designed to provide generic AI for mobs.
 * Well, not even AI, just give them something to do, really.
 * I imagine that it will be replaced by a real AI system in
 * the near future. But until now, I am going to use this
 * because I want to :P
 */

#include <emote.h>

int tickdelay;    // delay between ticks
string cact;      // action the mob is currently engaged in

object victim;    // current object of interest to the kitty
int boredom;      // current level of interest with current activity
mapping anger;    // kitty's displeasure versus various targets
mapping desire;   // various desires...

/// begin an activity
void start_act(string act) {
   debug(as_string(this_object()) + ": start_act, "+act,"ai");
   if (!function_exists("act_"+act,this_object())) {
      debug("bad activity in "+(string)this_object()+", "+act,"ai");
      call_out("on_tick",4);
      return;
   }
   cact = act;
   call_other( this_object(), "act_"+act );
}

/** event to be called every ~30 seconds that keeps the mob
 * doing stuff... only, it won't do anything, you should copy this
 * func into the specific ai program and go from there...
 */
void on_tick() {
  // debug("on_tick called in "+(string)this_object()+", cact = "+cact);
  // make sure we don't have more than one tick running
  remove_call_out("on_tick");

  // if busy, wait a few seconds
  if (cact != "waiting") {
    call_out("on_tick",4);
    return;
  }

  // if dead, stop ticking!
  if (this_object()->query_dead()) {
    remove_call_out("on_tick");
    return;
  }
}

/// clear the doing string
void end_act() {
  cact = "waiting";
}

/// start the tick
void start_ai() {
  debug("start_ai called in "+(string)this_object(),"ai");
  desire = ([]);
  if (clonep(this_object())) {
    remove_call_out("on_tick");
    cact = "waiting";
    call_out("on_tick", (tickdelay?tickdelay:30));
  }
}

/// set delay
void set_tick_delay(int x) { tickdelay = x; }
int query_tick_delay() { return tickdelay; }

int add_anger(string target, int amt) {
  if (!mappingp(anger))
    anger = ([]);
  anger[target] += amt;
  return anger[target];
}

mapping query_anger() { return anger; }

/** This function is called whenever the living is present for a soul
 * Generally, it should be overridden by a mob's specific ai.
 */
void on_soul(int attribute, object target, object actor, string soul) {
  if (target == this_object()) {
    int x;

    if (attribute & ATT_MEAN)
      x = 1;
    else if (attribute & ATT_NICE)
      x = -1;

    if (attribute & ATT_PHYSICAL)
      x *= 3;
    else if (attribute & ATT_AUDIBLE)
      x *= 2;

    if (actor) {
      string index = (string)actor;
      if (!mappingp(anger))
         anger = ([ ]);
      if (anger[index] > 0) {
         if (x < 0)
            x *= 2;
      } else if (x > 0)
         x *= 2;
      add_anger(index,x);
    }
  }
}

/// \return 1 if the object is hungry (below 50% food).
int is_hungry() {
   return (
      this_object()->query_food() < this_object()->query_food_capacity() / 2);
}
