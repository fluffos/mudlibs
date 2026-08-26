/* Do not remove the headers from this file! see /USAGE for more info. */

// Default busy for 4 seconds
#define BUSY_LENGTH 4
// If we're somehow busy for more than 10 seconds, ignore it
#define MAX_BUSY 10

nosave object *hunted = ({});
private
nosave int behavior_hooks = 0;
private
nosave object my_env;
nosave object busy_with;
nosave int busy_at = 0;
nosave string busy_func;
nosave string busy_action;
nosave int no_heals = 0;

void adversary_met(object who);
varargs void attacked_by(object who, int take_a_swing);
void dispatch_opponent();
void do_game_command(string str);
void behavior_hooks();
int query_level();
string badly_wounded();
string very_wounded();
varargs void targetted_action();
void add_hook(string tag, function hook);
void remove_hook(string tag, function hook);
void do_move_away();
nomask object query_link();

function adv_met_fn = ( : adversary_met:);

void add_hunted(object who)
{
   if (this_object()->is_body())
      return;
   behavior_hooks();
   if (member_array(who, hunted) == -1)
   {
      hunted += ({who});
   }
}

private
int not_busy()
{
   busy_at = 0;
   busy_with = 0;
   return 1;
}

void end_busy(mixed *args)
{
   int retvalue;
   if (busy_with && busy_func)
      retvalue = call_other(busy_with, busy_func, args);

   if (!retvalue)
   {
      tell(this_object(), "You fail at " + busy_action + ".\n");
   }
   not_busy();
}

//: FUNCTION busy_with
// int busy_with(object ob, string action, string function, mixed *args)
// Add a call back to a function and keep the player busy in the mean
// time. It's not possible to be busy with more than one thing at a time
// The action string is used for messaging like
//  You begin <action> ...
//  You are busy <action>!
// The function is called in the object given after BUSY_LENGTH with
// arguments args.
// BUSY_LENGTH is defined in /std/adversary/behaviors.
//
// This function returns 1 if the player was successfully set busy or
// 0 if it failed.
//
// The function is the object is called and if it returns 1, everything
// is assumed well, but on 0 a message of:
//  You fail at <action>.
// is sent to the adversary.
varargs int busy_with(object ob, string action, string bf, mixed args)
{
   if (time() - busy_at > MAX_BUSY || !busy_with)
   {
      tell(this_object(), "You begin " + action + " ...\n");
      busy_at = time();
      busy_with = ob;
      busy_func = bf;
      busy_action = action;
      call_out("end_busy", BUSY_LENGTH, args);
      return 1;
   }

   if (busy_action)
      tell(this_object(), "You are busy " + busy_action + "!\n");

   return 0;
}

void is_hunted_call(object who)
{
   if (member_array(who, hunted) != -1)
   {
      if (who->query_level() > query_level() && random(2) && present(who, environment()))
      {
         targetted_action("$N $vdo not like the looks of $t.", who);
         do_move_away();
      }
      else
      {
         if (random(2) && present(who, environment()))
         {
            targetted_action("$N $vrecognize $t!", who);
            attacked_by(who, 1);
         }
      }
   }
}

void i_met(object who)
{
   // Override me
}

//: FUNCTION adversary_met
// Function is called when this adversary meets someone or something.
// You can override it to add your own things when it meets things,
// but remember to call
//  ::adversary_met(who);.
// This function is only called for ADVERSARY, not if you are a player.
void adversary_met(object who)
{
   if (find_call_out("is_hunted_call") == -1)
   {
      call_out("is_hunted_call", 1 + random(2), who);
      i_met(who);
   }
   else
      i_met(who);
}

//: FUNCTION adversary_moved
// Function is called when this adversary moves. You can override
// it to add your own things when it moves, but remember to call
//  ::adversary_moved();
// This function is only called for ADVERSARY, not if you are a player.
void adversary_moved()
{
   if (my_env)
   {
      my_env->remove_hook("object_arrived", adv_met_fn);
   }

   my_env = environment();
   my_env->add_hook("object_arrived", adv_met_fn);
   foreach (object liv in filter_array(all_inventory(my_env), ( : $1->is_living() && $1 != this_object() :)))
      adversary_met(liv);
}

void behavior_hooks()
{
   if (!behavior_hooks)
   {
      add_hook("move", ( : adversary_moved:));
      adversary_moved();
      behavior_hooks = 1;
   }
}

object *query_hunts()
{
   return hunted;
}

void do_move_away();

//: FUNCTION flee
// Try to run away. Does nothing by default. Overload this function to
// modify the behavior of your monster when it panics.
void flee()
{
   //  do_move_away();
}

//: FUNCTION surrender
// Try to surrender. Does nothing by default. Overload this function to
// modify the behavior of your monster when it panicss.
void surrender()
{
}

//: FUNCTION try_heal
// Called when the adversary is in combat and under pressure. This function
// consumes food and alchohol from inventory to stay alive.
void try_heal()
{
   object *consumables = filter_array(all_inventory(this_object()), ( : $1->is_healing() :));
   object pick;
   string limb = very_wounded() || badly_wounded();

   if (sizeof(consumables))
      pick = choice(consumables);

   if (!pick)
   {
      no_heals = 1;
      return;
   }

   // Bit defensive code here since things are very interactive and can disappear
   // quickly.
   if (pick->is_bandage() && limb)
   {
      this_object()->do_game_command("apply bandage to " + limb);
   }
   else if (pick->is_food())
   {
      pick->do_eat(this_object());
   }
   else if (pick->is_drink())
   {
      pick->drink_it(this_object());
   }
}

//: FUNCTION panic
// Do something intelligent when we are about to die. Overload this
// to have your monster do something else when it's hp's get low.
// The default behavior is to randomly flee or surrender.
void panic()
{
   if (random(10) < 10 && !this_object()->is_body() && !no_heals)
      try_heal();
   if (random(10) < 3)
      flee();
   else
      surrender();
}

//: FUNCTION target_is_asleep
// Called with the person we are attacking is asleep or unconscious.
// Default behavior is to finish them off. Overload this function if you
// want your monster to do something other than killing its victims.
// Rob them, etc..
void target_is_asleep()
{
   dispatch_opponent();
}

//: FUNCTION do_move_away
// Moves through a random exit. Probable implementation of "flee"
void do_move_away()
{
   string *directions;
   string chosen_dir;
   string file;
   object dest;

   if (environment(this_object()))
      directions = environment(this_object())->query_exit_directions();

   /* Stop if there are no directions (this takes care of blue prints*/
   if (!sizeof(directions))
      return;

   chosen_dir = choice(directions);
   file = environment(this_object())->query_exit_destination(chosen_dir);

   /* If the file is null or a null string then give up */
   if (!file || file == "")
      return;

   /* If the destination is not loaded, do so */
   dest = load_object(file);

   /* If still no destination it won't load, try again next time */
   if (!dest)
      return;

   if (functionp("do_game_command"))
      do_game_command(sprintf("go %s", chosen_dir));
}
