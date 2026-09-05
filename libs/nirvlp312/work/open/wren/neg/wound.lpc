/*  Poison type object for the claw attack on D-raptor. Idea is to 
    simulate an infected injury or just jagged injury. Wanting to 
    have some extra options for dealing with it. Should increase the
    popularity of healers with an infuse check to 'close' the wound
    will need help figuring that part out though.

    Code borrowed heavily from Feldegast's Venom obj. Its a solid working 
         piece so I don't have to worry about crashing things.  

*/

#define DAMAGE (15+random(10))
#define DELAY 5+random(20)
#define LONGEVITY 10+random(50)

int duration;

id(str) { return str=="wound"; }

reset(arg) {
  if(!arg) {
    duration=LONGEVITY;
    call_out("poison_player",DELAY);
  }
}

poison_player() {
  if(environment()) { 
    tell_object(environment(this_object()),
      "Blood and froth seep from the jagged wounds.\n");
    if(environment()->is_player())
      call_other(environment(),"add_hit_point",-DAMAGE);
    else /* For pets or kids */
      call_other(environment(),"heal_self",-DAMAGE);
    duration--;
    if(duration <= 0) {
      tell_object(environment(),"The bleeding slows and you feel stronger.\n");
      destruct(this_object());
    }
    call_out("poison_player",DELAY);
  }
  return 1; 
}

drop()  { return 1; } /* Cannot drop */
get()   { return 0; } /* Cannot get */

extra_look() {
  return environment()->query_name()+" bleeds from gaping claw marks.";
}
