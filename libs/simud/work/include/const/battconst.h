#ifndef _BATTCONST_H_
#define _BATTCONST_H_

#define REQ_TYPES	8
#define REQ_LEVEL	0
#define REQ_STR		1
#define REQ_DEX		2
#define REQ_CON		3
#define REQ_WIS		4
#define REQ_INT		5
#define REQ_WILL	6
#define REQ_SKILL	7

#define MINAC		-10
#define HIGHAC		20
#define MAXAC		50

#define MAX_READINESS	1000
#define MIN_READINESS	0
#define RMAX_READINESS	(MAX_READINESS*2)
#define RMIN_READINESS	(MAX_READINESS*-1)

#define ST_STANDING	0x0001
#define ST_SITTING	0x0002
#define ST_LYING	0x0004
#define ST_CROUCHING	0x0008
#define ST_JUMPING	0x0010
#define ST_FALLING	0x0020
#define ST_FLYING	0x0040
#define ST_UNBALANCED	0x0080
#define ST_ALL		0xFFFF

// Results of an action/reaction
#define RESULT_TYPE	0	// This element of the array is a string
/* Valid entries for RESULT_TYPE so far are:
   miss     The attack missed outright
   hit      The attack hit with no reaction
   block    The attack was blocked with a shield
   parry    The attack was parried with a weapon
   dodge    The attack was dodged
   immune   The target was somehow immune to the attack
   absorb   Some of the damage was somehow absorbed
   counter  The target delivered a counter-attack
   other    The target did something strange and unnatural... :)
*/

#define RESULT_MOD	1	// This element is an int or mapping
#define RESULT_MSG	2	// This element is a string, tacked on to msg
#define RESULT_BP	3	// body part struck (int)
#define RESULT_ARMOUR	4	// armour struck (object)

// Size of the (mixed) array returned
#define RESULT_SIZE	3

// Elements in the battle event array
// Readiness cost
#define B_RCOST         0
// File name
#define B_FNAME         1
// Target
#define B_TARGET        2
// Stance
#define B_STANCE        3
// Optional parameters
#define B_PARAM         4

#define ATT_NO_PARRY    0x00000001	// Attack may not be parried
#define ATT_NO_DODGE    0x00000002	// Attack may not be dodged
#define ATT_NO_BLOCK    0x00000004	// Attack may not be blocked (shield)
#define ATT_NO_MISS	0x00000008	// Attack will not miss
#define ATT_NO_COUNTER	0x00000016	// Attack may not be countered...

// Size of the battle event array
#define B_SIZE          5

#define FORMS_DIR       "/battle/forms/"

#define BATTLE_DAEMON	("/daemon/battle")

// A handy macro for building targeted verbs
#define BATTLE_ACTION(readiness, _form) \
int main( string param ) { \
   object target, *tlist; \
   mixed form = _form; \
   if( (stringp(form) && form != this_player()->query_form()) || \
       (pointerp(form) && member(form, this_player()->query_form()) < 0) ) \
      {  notify_fail("You are in no position to do that, your form is wrong.\n"); return 0; } \
   if( param ) tlist = all_present( param, environment(this_player()) ); \
   else tlist = 0; \
   if( tlist ) foreach(target : tlist) { \
      WALK_DAEMON->init_walk_action( WALK_DAEMON->shape_adjacent(), target->query_coord(), BATTLE_DAEMON->make_action(target,readiness) ); \
      if( catch("/bin/kill"->attack_target( target )) ) \
         this_player()->start_combat( target );\
   } else \
   if( this_player()->query_target() ) \
      WALK_DAEMON->init_walk_action( WALK_DAEMON->shape_adjacent(), -1, BATTLE_DAEMON->make_action(0,readiness) ); \
   else \
      msg("What are you trying to attack?"); \
   if( sizeof(this_player()->query_actions()) > 0 ) \
      command( "actions", this_player() ); \
   return 1; \
}

#endif
