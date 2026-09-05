#define ETO environment(this_object())
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("toxin2");
    set_weight(0);
    set_value(0);
call_out("poison_player",15);
}

query_auto_load() { return "/players/eurale/Keep/OBJ/poison2.c:"; }

poison_player() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(environment(this_object()),
      "You feel a burning sensation coursing through your veins...\n");
   /* changed to other|poison 6.8.01 verte */
    ETO->hit_player(20 + random(10), "other|poison");
    call_out("poison_player",30);
    return 1; }
  }
}

drop() {
if(environment()->is_dieing()) destruct(this_object());
else return 1; }
get()   { return 0; }
can_put_and_get()  { return 0; }

