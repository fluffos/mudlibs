// Updated Black Knight : 12-Mar-96 - Germ
// At each stage of the fight, the knight's level is reduced
// and exp is added to the attacker.  This prevents the knight
// from being "set up" for small players.
// Also, the conversations are improved using call_out's.
//

/* This doesn't really work ok. But it's here as an example,
 * if anyone's interested.
 */

#include <equipped_npc.h>
#include <areas.h>

int dropped_arms;
object tp, arm_leg;

void drop_left_arm();
void drop_left_leg();
void drop_right_arm();
void drop_right_leg();

create_monster()
{
    set_name("knight");
    set_short("Black Knight");
    set_level(19);
    set_hp(600);
    set_gender(G_MALE);
    set_dead_ob(this_object());
    set_long("He looks like John Cleese in a black armour.\
 He's wearing a black war mask.");
    set_spell_chance(20);
    set_spell_mess2("Black Knight kicks you on the forehead!");
    set_spell_mess1("Black Knight kicks his opponent on the forehead.");
    set_spell_dam(30);
    set_alignment(500);
    set_id("black knight");
#ifdef AREA_FROBOZZ_INN
    add_weapon( AREA_FROBOZZ_INN+"obj/python", "sword", 0, 3,
      "Knight takes the sword." );
#endif
    add_armour( 0, "war mask", ({ 
	({ "set_name", "war mask" }),
	({ "set_type", "mask" }),
	({ "set_short", "Black war mask" }),
	({ "set_long", "It smells awful." }),
	({ "set_ac", 1 }),
	({ "set_value", 500 }),
	({ "set_weight", 1 })
      }), 3, "Knight takes the mask." );
    set_wc(30);
    set_ac(15);
    add_block( "north","all", 0, 0,
      "The black knight blocks your way and says: None shall pass!",
      ":The black knight blocks %<him.name%>'s way.", 0,0 );
}

int
hit_player(int dam) 
{
    int h;
    h=query_hp();
    if(query_attack()) 
    {
	if(h<300 && dropped_arms<1) { 
	    drop_left_arm();
	    return 0;
	}
	if(h<150 && dropped_arms<2) {
	    drop_right_arm();
	    return 0;
	}
	if(h<100 && dropped_arms<3) {
	    drop_left_leg();
	    return 0;
	}
	if(h<60 && dropped_arms<4) {
	    drop_right_leg();
	    return 0;
	}
    }
    return ::hit_player(dam);
}

void attack_again( object attacker )
{
    environment()->tell_here("\n\n");
    if ( present( attacker, environment() ));
    attack_object( attacker );
}

status
monster_died( object knight )
{
    while ( remove_call_out("say_here") != -1 );
    return 0;
} 

void say_here(object attacker, string str )
{
    if ( !attacker )
    {
	environment()->tell_here(str);
	return;
    }
    if ( present( attacker, environment() ))
    {
	environment()->tell_here(attacker->query_name()+" says: "+str, attacker);
	attacker->tell_me("You say: "+str);
    }
    else
	while ( remove_call_out("say_here") != -1 );
}

void
drop_arm(string str) 
{
    dropped_arms++;
    if (!(tp=query_attack())) return;
    tp->tell_me("You skillfully cut off the Knight's "+str+".");
    environment()->tell_here("With a carefully placed hit "+tp->query_name()
      +" chops off the Knight's "+str+".",tp);
    tp->stop_fight();
    tp->stop_fight();
    stop_fight();
    stop_fight();
}

void
drop_left_arm() 
{
    drop_arm("left arm");
#ifdef AREA_FROBOZZ_INN
    arm_leg=clone_object(AREA_FROBOZZ_INN+"obj/arm_leg");
    arm_leg->side("left");
    arm_leg->member("arm");
    move_object(arm_leg,environment());
#endif
    environment()->tell_here("\n\n");
    if (!tp) return;
    tp->add_exp(10000);
    call_out("say_here",2,tp,"Now stand aside worthy adversary.");
    call_out("say_here",3,0,"Knight glances at his left shoulder.\n\
Knight says: 'Tis just a scratch.");
    call_out("say_here",4,tp,"A scratch? Your arm is off!");
    call_out("say_here",5,0,"Knight says: No it isn't.");
    call_out("say_here",6,tp,"What's that then?",tp);
    call_out("say_here",7,0,"Knight says: I've had worse.");
    call_out("say_here",8,tp,"You're a liar!",tp);
    call_out("say_here",9,0,"Knight says: Come on you pansy!");
    call_out("attack_again",10,tp );
}

void
drop_right_arm() 
{
    drop_arm("right arm");
#ifdef AREA_FROBOZZ_INN
    arm_leg=clone_object(AREA_FROBOZZ_INN+"obj/arm_leg");
    arm_leg->side("right");
    arm_leg->member("arm");
    move_object(arm_leg,environment());
    destruct(present("pythonsword", this_object()));
    move_object(clone_object(AREA_FROBOZZ_INN+"obj/python"), environment());
#endif
    set_wc(0, 1);
    set_level(10);
    if (!tp) return;
    tp->add_exp(5000);
    environment()->tell_here("\n\n");
    call_out("say_here",2,tp,"Victory is mine.");
    call_out("say_here",3,tp,"I thank thee O Lord that in thy...");
    call_out("say_here",4,0,"Knight kicks "+tp->query_name()
      +" hard on the side of "+tp->query_possessive()+" head.\n\
Knight says: Come on then.");
    call_out("say_here",5,tp,
      "What! You are indeed brave Sir Knight, but the fight is mine.");
    call_out("say_here",6,0,"Knight says: Had enough, eh?");
    call_out("say_here",7,tp,"You stupid bastard. You haven't got any arms left.");
    call_out("say_here",8,0,"Knight says: Course I have.");
    call_out("say_here",9,tp,"Look!");
    call_out("say_here",10,0,"Knight says: What! Just a flesh wound.\n\
Knight kicks "+tp->query_name()+".\n");
    call_out("say_here",11,tp,"Stop that.");
    call_out("say_here",12,0,"Knight says: Had enough?");
    call_out("say_here",13,tp,"I'll have your leg!");
    call_out("say_here",14,0,"Knight kicks "+tp->query_name()+".");
    call_out("say_here",15,tp,"Right!");
    call_out("attack_again",16,tp);
}
void
drop_left_leg() 
{
    drop_arm("left leg");
#ifdef AREA_FROBOZZ_INN
    arm_leg=clone_object(AREA_FROBOZZ_INN+"obj/arm_leg");
    arm_leg->side("left");
    arm_leg->member("leg");
    move_object(arm_leg,environment());
#endif
    set_level(5);
    if (!tp) return;
    tp->add_exp(1000);
    call_out("say_here",2,0,"\n\nKnight says: I'll do you for that!");
    call_out("say_here",3,tp,"You'll what?");
    call_out("say_here",4,0,"Knight says: Come here.");
    call_out("say_here",5,tp,"What are you going to do? Bleed on me?");
    call_out("say_here",6,0,"Knight says: I'm invincible.");
    call_out("say_here",7,tp,"You're a looney.");
    call_out("say_here",8,0,"Knight says: The Black Knight always triumphs. Have at you!");
    call_out("attack_again",9,tp);
}
void
drop_right_leg() 
{
    drop_arm("right leg");
#ifdef AREA_FROBOZZ_INN
    arm_leg=clone_object(AREA_FROBOZZ_INN+"obj/arm_leg");
    arm_leg->side("right");
    arm_leg->member("leg");
    move_object(arm_leg,environment());
#endif
    set_level(1);
    if (!tp) return;
    tp->add_exp(500);
    call_out("say_here",2,0,"\n\nKnight says: All right, we'll call it a draw.");
}
