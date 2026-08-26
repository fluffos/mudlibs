inherit NPC_OBJ;

#include <tasks.h>

object trainer;

#define DODGE "fighting.combat.dodging.melee"
#define PARRY "fighting.combat.parry.melee"

#define PERSON_DODGE_FAILURE "As the dummy spins around, an arm swings towards you and hits you before you can dodge out of the way!\n"
#define ROOM_DODGE_FAILURE " isn't fast enough to dodge a spinning arm!  Ouch!\n"
#define PERSON_DODGE_SUCESS "As the dummy spins around, an arm swings towards you but you see it in time and dodge it.\n"
#define ROOM_DODGE_SUCESS " dodges the arm of the wooden training dummy.\n"
#define PERSON_PARRY_FAILURE "As the dummy spins around, an arm swings towards you but you are unable to block it!\n"
#define ROOM_PARRY_FAILURE " isn't fast enough to avoid the training dummy! Ouch!\n"
#define PERSON_PARRY_SUCCESS "As the dummy spins around, an arm swings towards you but you see it in time and block it.\n"
#define ROOM_PARRY_SUCCESS " parries the training dummy.\n"

#define DIFF 15
#define MOD 10

void setup() {
  set_name( "dummy" );
  add_adjective( ({"wood", "wooden", "training"}) );
  //  add_property( "determinate", "A" );
  set_short( "training dummy" );
  set_long( "A fighters dummy.  It is looking pretty worn from having "+
     "all the stuffing knocked out of it all day.\n");
  set_race( "human" );
  set_class( "fighter" );
  set_gender( 0 );
  set_level( 0 );
  add_property( "run away", -1 );
  set_dex(6);
  set_str(6);
  set_con(6);
  set_int(6);
  set_wis(6);
  remove_ac("sharp");
  remove_ac("pierce");
  remove_ac("blunt");
  tactics("response parry");
  tactics("parry both");
} /* setup() */

object query_trainer() { return trainer; }
object set_trainer( object thing ) { return trainer = thing; }

int attack_by( object thing ) {
  int ret;

  if ( trainer )
    if ( ( environment( trainer ) == environment() ) &&
         !trainer->query_fighting() )
      ret = (int)trainer->check_attack( thing );

  if(ret)
    call_out("spin_arm", 0, thing);
  return ret;
}

void spin_arm(object thing) {
  int diff, which, failed;

  if(environment(thing) != environment(this_object()))
     return;
     
  switch(thing->query_tactics()[0]) {
  case "offensive":
    diff = DIFF + MOD;
    break;
  case "defensive":
    diff = DIFF - MOD;
    break;
  default:
    diff = DIFF;
  }

  switch (thing->query_combat_response() ) {
  case "dodge" :
    which = 1;
    break;
  case "parry":
    which = 0;
    break;
  default:
    which = random(2);
  }

  if(which) {
    switch (TASKER->perform_task(thing, DODGE, diff, TM_FIXED)) {
    case FAIL :
      if(thing->query_skill(DODGE) >= 5 ||
         random(3*(thing->query_skill(DODGE))) ||
         !thing->add_skill_level(DODGE, 1, 1)) {
        tell_object(thing,PERSON_DODGE_FAILURE);
        tell_room(environment(thing),thing->one_short() + ROOM_DODGE_FAILURE,({thing}));
        failed = 1;
        break;
      }
    case AWARD :
      tell_object(thing,"%^YELLOW%^You feel better at dodging "
                  "things.%^RESET%^\n");
    case SUCCEED :
      tell_object(thing,PERSON_DODGE_SUCESS);
      tell_room(environment(thing), thing->one_short() + ROOM_DODGE_SUCESS, ({thing}));
      break;
    }
  } else {
    switch (TASKER->perform_task(thing, PARRY, diff, TM_FIXED)) {
    case FAIL :
      if(thing->query_skill(PARRY) >= 5 ||
         random(3*(thing->query_skill(PARRY))) ||
         !thing->add_skill_level(PARRY, 1, 1)) {
        tell_object(thing,PERSON_PARRY_FAILURE);
        tell_room(environment(thing), thing->one_short() + ROOM_PARRY_FAILURE,({thing}));
        failed = 1;
        break;
      }
    case AWARD :
      tell_object(thing,"%^YELLOW%^You feel better at parrying things."
                  "%^RESET%^\n");
    case SUCCEED :
      tell_object(thing,PERSON_PARRY_SUCCESS);
      tell_room(environment(thing), thing->one_short() + ROOM_PARRY_SUCCESS, ({thing}));
      break;
    }
  }
  if(trainer && failed)
    trainer->failed_parry(thing);
  return;
} /* attack_by() */

void attack_ob( object thing ) { return; }

int adjust_hp( int number, object player ) {
  if ( number > -1 || !player)
    return ::adjust_hp( number, player);
  
  if ( trainer && ( environment( trainer ) == environment() ) &&
       !trainer->query_fighting() )
    return (int)trainer->analyse_attack( -number, player);
  return 1;
} /* adjust_hp() */
