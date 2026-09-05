/* charisma object */

inherit "obj/shadows/shadow";
inherit "inherit/timer";

object who;
int charisma;

void shadow_charisma(object ob, int i) {
  who = ob;
  if (!who) {
    destruct(this_object());
    return;
  }
  charisma = i;
  shadow_object(who);
}

int query_charisma() { return charisma; }

object query_charisma_object() { return this_object(); }

void time_out() {
  tell_object(who, "You don't feel charismatic anymore...\n");
  ::time_out();
}

void dispel_magic() { time_out(); }

int query_old_charisma() { return (int)who->query_charisma(); }

