/* stoneskin spell */

inherit "obj/shadows/shadow";

object who;
int counter;

void stoneskin(object ob, int i) {
  who = ob;
  counter = i;
  shadow_object(who);
}

int hit_player(int i) {
  if (--counter > 0) {
    i = 0;
  }
  else {
    tell_object(who, "Your stoneskin spell fades....\n");
    destruct(this_object());
  }
  return (int)who->hit_player(i);
}

object query_stoneskin_object() { return this_object(); }

