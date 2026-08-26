#include <weapon.h>

inherit NPC_OBJ;

int attack_dummy( );

object *greeters = ({ });

#define GREETINGS ({ \
   "Welcome to Combat Boot Camp, $name$.",\
   "This here course is set up to teach you the basics of fighting.",\
   "You can attack this here dummy and I'll tell ya how well ya done.",\
   "Arr!  You have the look of a fine fighter, $name$." \
})

int ability, counts, damage, told_attack, told_parry, last_damage;
object training, weapon;

void setup() {
  set_race( "human" );
  set_class( "fighter" );
  set_gender( 1 );
  set_level( 100 );
} /* setup() */

void whichone(string name) {
  switch(name) {
  case "xrazzicaz":
    set_name( "xrazzicaz" );
    add_alias( "xraz" );
    add_property( "determinate", "" );
    set_short( "Xrazzicaz" );
    set_long( "This is the ex-fighter's guild dummy.  After being replaced by "
              "the newer mechanical dummy, Xrazzicaz decided to stay on as an "
              "instructor.\n");
    break;
  case "zazzifraz":
  set_name( "zazzifraz" );
  add_alias( "zazz" );
  add_property( "determinate", "" );
  set_short( "Zazzifraz" );
  set_long( "This is Xrazzicaz' brother, an ex-fighter's guild dummy.  After "
            "being replaced by the newer mechanical dummy, Zazzifraz, like "
            "his brother, decided to stay on as an instructor.\n");
  break;
  case "john":
    set_name( "john" );
    add_property( "determinate", "" );
    set_short( "John" );
    set_long( "This is Xrazzicaz' other brother, John.  He was the fighters "
              "guild dummy in Ohulan Cutash until he was replaced by a "
              "mechanical dummy.  Like Xrazzicaz and Zazzifraz he got a "
              "job teaching after retirement.\n");
  }
}

int attack_by(object thing) {
  write(this_object()->the_short() + " glares at you before swiftly knocking you to the ground.\n");
  this_object()->stop_fight(thing);
  thing->stop_fight(this_object());
  return 0;
} /* attack_by() */

int attack_ob(object thing) {
  this_object()->stop_fight(thing);
  thing->stop_fight(this_object());
  return 0;
} /* attack_ob() */

void init() {
  if(!this_player()) {
    return;
  }
  if(environment() == find_object("/room/rubbish")) {
    return;
  }
  if(this_player()->query_property("dead")) {
    return;
  }
  if(!this_player()->query_visible(this_object())) {
    return;
  }
  if(!userp(this_player())) {
    return;
  }
  if(this_player()->query_property("player")) {
    greeters += ({this_player()});
    call_out("do_greeting", 1, this_player());
  }
  ::init();
  this_player()->add_command("attack", this_object(), "<indirect:object:here>", (: attack_dummy :));
  this_player()->add_command("kill", this_object(), "<indirect:object:here>", (: attack_dummy :));
} /* init() */

void do_greeting() {
  string str;
  
  if(!sizeof(greeters)) {
    return;
  }
  greeters = filter(greeters, 
    (: $1 && environment($1) == environment(this_object()) &&
     $1->query_visible(this_object()) :));
  uniq_array(greeters);
  foreach(str in GREETINGS) {
    str = replace(str, "$name$", query_multiple_short(greeters));
    do_command("'" + str);
  }
  greeters = ({ });
} /* do_greeting() */

int attack_dummy( ) {
  object dummy;

  dummy = present("dummy", environment());
  debug_printf("Attack_dummy called");
   if ( training ) {
     if((environment( training ) == environment()) &&
        interactive(training) && training->query_fighting()) {
       if(training == this_player()) {
         write("You are already using "+
               the_short() +".\n" );
         return 1;
       }
       write((string)training->one_short() +
             " is currently using "+ the_short() +
             ".\n" );
       return 1;
     }
     training = 0;
     weapon = 0;
     ability = 0;
     counts = 0;
     told_attack = 0;
     told_parry = 0;
   }
   this_player()->attack_ob( dummy );
   training = this_player();
   weapon = 0;
   ability = 0;
   counts = 0;
   write( "You attack "+ dummy->the_short() +".\n" );
   return 1;
} /* attack_dummy() */

void stop_them( object attacker, object dummy ) {
  tell_object( attacker, one_short() +" stops you attacking "+
               (string)dummy->the_short() +".\n" );
  tell_room( environment(), one_short() +" stops "+
             (string)attacker->the_short() +" attacking "+
             (string)dummy->the_short() +".\n", attacker );
  attacker->stop_fight( dummy );
  training = 0;
  weapon = 0;
  ability = 0;
  counts = 0;
  told_attack = 0;
  told_parry = 0;
} /* stop_them() */

int check_attack( object thing) {
  int number, *rating;
  string what, skill;
  object *weapons;
  mixed *attacks;
  
  if(!training)
    return 0;
  
  if(training != thing ) {
    if(previous_object())
      stop_them( thing, previous_object() );
    
    do_command( "say "+ convert_message( (string)training->the_short() +
            " is using the training dummy at the moment." ) );
    return 0;
  }

  if ( damage && weapon ) {
    rating = (int *)"/cmds/guild-race/other/judge"->calc_rating( weapon );
    number = ( ( 32 * damage ) / rating[ 0 ] +
               ( 15 * damage ) / rating[ 1 ] ) / 5;
    ability += number;
    if ( number > 14 )
      number = 14;
    do_command( "say That's "+ ({ "an atrocius", "an extremely poor",
            "a very poor", "a rather poor", "a poor", "a pretty poor",
            "quite a poor", "a reasonable", "quite a good", "a pretty good",
            "a good", "a rather good", "a very good", "an extremely good",
            "an excellent" })[ number ] +" attack for "+
            convert_message( (string)weapon->the_short() ) +"." );
  }
  weapons = (object *)thing->query_weapons();
  if ( !sizeof( weapons ) ) {
    stop_them( thing, previous_object() );
    do_command( "say You need a weapon!" );
    return 0;
   }
  if ( sizeof( weapons ) > 1 ) {
    stop_them( thing, previous_object() );
    do_command( "say Just use one weapon, I get confused if you use more "
                "than one!" );
    return 0;
  }
  if ( !weapon )
    weapon = weapons[ 0 ];
  if ( weapon != weapons[ 0 ] ) {
    stop_them( thing, previous_object() );
    do_command( "say You've changed weapons!" );
    return 0;
  }
  damage = 0;
  counts++;
  if(!last_damage && !told_attack &&
     thing->query_tactics()[0] != "offensive") {
    told_attack = 1;
    do_command("say You can improve your chances of hitting your opponent "
               "by setting your tactics to a more offensive attitude.");
  } else {
    // This hands out skill advances very generously up to lvl 5 then it
    // stops.
    attacks = weapon->query_attack_data();
    skill = attacks[random(sizeof(attacks) / W_ARRAY_SIZE) * W_ARRAY_SIZE +
                   W_SKILL];
    if(thing->query_skill("fighting.combat.melee." + skill) < 5 &&
       !random(3*(thing->query_skill("fighting.combat.melee." + skill))) &&
       thing->add_skill_level("fighting.combat.melee." + skill, 1, 1)) {
      tell_object(thing, "%^YELLOW%^You feel you've learned something about "
                  "using " + weapon->a_short() + ".%^RESET%^\n");
    }
  }
  
  if ( counts < 8 )
    return 1;
  number = ( 2 * ability + counts ) / ( 2 * counts );
  if(weapon)
    what = convert_message((string)weapon->the_short());
  else
    what = "whatever it was you were using";
  stop_them( thing, previous_object() );
  
  do_command( "think" );
  switch ( number ) {
  case 0 .. 1 :
    if(strsrch(what, "knife") == -1 && strsrch(what, "dagger") == -1)
      do_command( "say Well, you're rather hopeless with "+ what +
                  ", really.  A simpler weapon may help." );
    else
      do_command( "say Well, you're rather hopeless with "+ what +
                  ", really, but with practice you'll get better.");

         break;
  case 2 .. 3 :
    do_command( "say Hmmm... You have some skill with "+ what +
                ", at any rate, as you practice you'll get better." );

    break;
  case 4 .. 6 :
    do_command( "say You're getting there.  Keep training with "+
                what +" and you'll be pretty good with it soon." );
    break;
  default :
    do_command( "say I'd say you've more or less mastered "+ what +
                ".  Well done!" );
  }
  return 0;
}

int analyse_attack( int number, object thing ) {
  last_damage = number;
  damage += number;
   return 1;
} /* analyse_attack() */

void failed_parry(object thing) {
  if(training && training == thing) {
    if(thing->query_tactics()[0] != "defensive" && !told_parry) {
      told_parry = 1;
      do_command("say You can improve your chances of defending by setting "
                 "your tactics to a more defensive attitude.");
    }
  }
}
  
