/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: skill_bonus.c,v 1.1 1998/01/06 04:36:51 ceres Exp $
 * $Log: skill_bonus.c,v $
 * Revision 1.1  1998/01/06 04:36:51  ceres
 * Initial revision
 * 
*/
/*
 * This is a generic shadow for increasing (or decreasing) skill bonuses.
 * Written by Jeremy 10-May-95
 */
inherit "/std/effect_shadow";

int query_skill_bonus(string skill) {
    int bonus;
    mapping bonuses;

    bonuses = (mapping)player->arg_of((int)player->sid_to_enum(id));
    bonus = player->query_skill_bonus(skill);
    bonus += bonuses[skill];
    if (bonus > 0) {
        return bonus;
    }
    return 0;
}
