/*
This is a general example of a poison object.  Move this onto the
player and they will be poisoned.
				-Feldegast
*/
#define DAMAGE (15+random(10))
#define DELAY 5+random(20)
#define LONGEVITY 10+random(50)

int duration;

id(str) { return str=="toxin"; }

reset(arg) {
  if(!arg) {
    duration=LONGEVITY;
    call_out("poison_player",DELAY);
  }
}

/*
This object must be loaded from your castle.c in order for it
to autoload.  Notice the colon at the end of the autoload string
here.
*/

query_auto_load() { return "/players/feldegast/obj/venom.c:"+duration; }

/*
This function receives the duration value when the item autoloads,
but it must be converted from type string to int.
*/

init_arg(str) {  sscanf(str,"%d",duration); }

poison_player() {
  if(environment()) { 
    tell_object(environment(this_object()),
      "You feel the spider's venom burning through your bloodstream.\n");
    if(environment()->is_player())
      call_other(environment(),"add_hit_point",-DAMAGE);
    else /* For pets or kids */
      call_other(environment(),"heal_self",-DAMAGE);
    duration--;
    if(duration <= 0) {
      tell_object(environment(),"You begin to feel a bit better.\n");
      destruct(this_object());
    }
    call_out("poison_player",DELAY);
  }
  return 1; 
}

drop()  { return 1; } /* Cannot drop */
get()   { return 0; } /* Cannot get */

extra_look() {
  return environment()->query_name()+" looks pale and sickly";
}
