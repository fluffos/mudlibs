#include <tasks.h>

#define COST 25
#define BONUS 250
#define SWORD_SKILL "fighting.combat.melee.sharp"
#define SPECIAL_SKILL "fighting.combat.special"

inherit WEAPON_OBJ;

void setup() {
    set_name( "sabre" );
    set_short( "fine sabre" );
    add_adjective( "fine" );
    set_main_plural( "fine sabres" );
    set_long( "This is one of the fabled sabres made in the frozen caverns "+
      "of the Hub.  Each blade can take up to five years to forge on "+
      "account of the incredible edge they have.  They are so sharp you "+
      "could cut the wind with them.  The only drawback is that they "+
      "are quite fragile and in unskilled hands could easily break.\n" );
    set_weight( 40 );
    set_value( 50000 );
    new_weapon( 5120 );
    set_damage_chance( 10 );
    add_attack( "slice", 88, ({ 32, 5, 15 }), "sharp", "sharp", 0 );
    add_attack( "stab", 21, ({ 50, 5, 50 }), "pierce", "sharp",
      "check_skill" );
    add_property( "no recycling", 1 );
} /* setup() */

void check_skill( int damage, object him, object me, string a_type,
  string a_name ) {
    if ( random( BONUS ) > (int)me->query_skill_bonus( SWORD_SKILL ) )
        this_object()->break_me();
} /* check_skill() */

void init() {
    this_player()->add_command( "flick", this_object(), "%D 'at' %I" );
} /* init() */

int do_flick( object *things ) {
    int ac, damage;
    if ( query_wielded() != this_player() ) {
        this_player()->add_failed_mess( this_object(), "You need to be "+
          "wielding $D to flick it at someone.\n", ({ }) );
        return 0;
    }
    if ( sizeof( things ) > 2 ) {
        this_player()->add_failed_mess( this_object(), "You can only flick $D "+
          "at one thing at a time.\n", ({ }) );
        return 0;
    }
    if ( member_array( things[ 0 ],
        (object *)this_player()->query_attacker_list() ) == -1 ) {
        this_player()->add_failed_mess( this_object(), "You are not fighting "+
          "$I!\n", things );
        return 0;
    }
    if ( !this_player()->query_special_manoeuvre() ) {
        this_player()->add_failed_mess( this_object(), "You are not able to "+
          "concentrate sufficiently to flick $D at $I.\n", things );
        return 0;
    }
    if ( (int)this_player()->query_specific_gp( "fighting" ) < COST ) {
        this_player()->add_failed_mess( this_object(), "You can't muster "+
          "the energy to flick $D at $I.\n", things );
        return 0;
    }
    this_player()->adjust_gp( -COST );
    switch ( (int)TASKER->attempt_task( BONUS,
        (int)this_player()->query_skill( SPECIAL_SKILL ), 50 ) ) {
    case AWARD :
      if(this_player()->add_skill_level( SPECIAL_SKILL, 1 ))
        write( ({ "%^YELLOW%^%^BOLD%^You impress yourself with your movements."
            ".%^RESET%^\n", "%^YELLOW%^%^BOLD%^You execute a manoeuvre worthy "
            "of Heric himself!%^RESET%^\n", "%^YELLOW%^%^BOLD%^Your sudden show of "
            "skill surprises you.%^RESET%^\n" })[ random( 3 ) ] );
    case SUCCEED :
        this_player()->add_succeeded_mess( this_object(), "$N $V $D at $I, "+
          "scoring a hit on the hand.\n", things );
        damage = roll_MdN( 5, 25 );
        ac = (int)things[ 0 ]->query_ac( "sharp", damage, "hands" );
        call_out( "do_damage", 0, "sharp", ac );
        damage -= ac;
        if ( damage > 0 )
            things[ 0 ]->adjust_hp( -damage, this_player() );
        break;
    default :
        if ( random( (int)this_player()->query_dex() ) < 8 ) {
            this_player()->add_succeeded_mess( this_object(), "$N attempt$s "+
              "to flick $D at $I, but manage$s to flick the weapon "+
              "out of $p hand instead.\n", things );
            this_object()->move( environment( this_player() ) );
        } else
            this_player()->add_succeeded_mess( this_object(), "$N attempt$s "+
              "to flick $D at $I, but fail$s.\n", things );
        break;
    }
    this_player()->reset_special_manoeuvre();
    return 1;
} /* do_flick() */
