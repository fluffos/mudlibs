/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: perception.c,v 1.1 1998/01/06 04:36:51 ceres Exp $
 * $Log: perception.c,v $
 * Revision 1.1  1998/01/06 04:36:51  ceres
 * Initial revision
 * 
*/
inherit "/std/effect_shadow";

#define SKILL "other.perception"
#define BONUS 100

int query_skill_bonus(string skill) {
    int bonus;

    bonus = player->query_skill_bonus(skill);
    if (skill == SKILL) {
        bonus += BONUS;
    }
    return bonus;
}
