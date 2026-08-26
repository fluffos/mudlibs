/**
 * This handler contains special attack callback functions for
 * fighting commands and general combat action functions that
 * can be used to make NPCs use special attacks.
 * @author Sandoz, 30th August 2001
 */

#define TACTICS "fighting.combat.special.tactics"

/** @ignore yes */
void dest_me() {
    destruct(TO);
} /* dest_me() */

private object select_target( object me, object victim ) {
    object ob;

    if( !me || !victim || me == victim )
        return 0;

    if( !( ob = me->query_concentrating() ) || ENV(ob) != ENV(me) )
        me->concentrate( ({ ob = victim }) );

    return ob;

} /* select_target() */

/** @ignore yes */
void do_slash( object me, object victim ) {
    object ob;
    int chance;

    if( ( chance = me->query_skill_bonus(TACTICS) / 15 ) > 80 )
        chance = 80;

    if( ( ob = select_target( me, victim ) ) && random( 100 ) < chance )
        me->do_command("slash at "+file_name(victim)+" with weapon");

} /* do_slash() */

/** This method is used by pound_break(). */
private int test_bit( object ob, string bit ) {
    string race_ob;

    if( !race_ob = ob->query_race_ob() )
        return 0;

    return sizeof( filter( race_ob->query_possible_bits(),
        (: strsrch( $1, $2 ) != -1 :), bit ) );

} /* test_bit() */

/**
 * This is a callback function used by the 'pound' command.
 * It breaks limbs.
 * @param player the attacking player
 * @param target the target of the attack
 * @param weapon the weapon attacked with
 * @param damage the damage done to the target
 */
void pound_break( object player, object target, object weapon, int damage ) {
    int time;

    if( !objectp(target) || target->query_property("dead") )
        return;

    if( !objectp(player) || player->query_property("dead") )
        return;

    if( damage < 1 )
        return;

    /* damage ranges from 0 to about 700. */
    if( random( 30 ) < ( damage / 100 ) ) {
        /* duration based on damage done */
        time = roll_MdN( 6, damage );

        /* messages are gives in the effect */
        switch( random( 5 ) ) {
          case 0:
            if( !sizeof( target->effects_matching( "disease.injury.broken.ribcage") ) )
                target->add_effect("/std/effects/curses/broken_ribcage", time );
          return;
          case 1..2:
            if( !sizeof( target->effects_matching( "disease.injury.broken.leg") ) &&
                test_bit( target, "leg") )
                target->add_effect("/std/effects/curses/broken_leg", time );
          return;
          default:
            if( !sizeof( target->effects_matching( "disease.injury.broken.arm") ) &&
                test_bit( target, "hand") )
                target->add_effect("/std/effects/curses/broken_arm", time );
            return;
        }
    }
} /* pound_break() */
