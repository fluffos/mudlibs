/*
     Generic poison object - Written by Llew
     Clone and call:
     begin_poison(object who, int strength, int ticksofdamage, int timeoftick)
*/

inherit "/obj/treasure";

#define DEFAULT_COUNT 5
#define DEFAULT_TIME 4
#define DEFAULT_STRENGTH 10

int strength, time, count;
object owner;

reset(arg) {
   if(arg) return;
   set_id("poison");
   set_weight(0);
   set_value(0);
}

long() {
   write("The black-green poison oozes out of the puss filled cut.\n");
}

begin_poison(object poisonee, int str, int length, int interval)
{
   if (!objectp(owner = poisonee)) return;
   if ((time = interval) < 1) time = DEFAULT_TIME;
   if ((count = length)  < 1) count = DEFAULT_COUNT;
   if ((strength = str)  < 1) strength = DEFAULT_STRENGTH;

   call_out("effect", time);
}

effect() {
   if (!owner) return;
   tell_object(owner, "You feel poison burning through your blood.\n");
   owner->hit_player(strength, "other|poison");

   if (!owner || owner->query_ghost()) destruct(this_object());

   count--;
   if (count == 0)
   {
      if (owner) tell_object(owner, "The poison has worn off.\n");
      destruct(this_object());
      return;
   }
   call_out("effect", time);
}

drop() { return 0; }
get() { return 1; }
can_put_and_get() { return 0; }

query_name() { return name; }
