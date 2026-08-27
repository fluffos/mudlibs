/*
   /doc/examples/poison/spider.c
   A demonstration of poison use in monsters.   The example is a spider
   which has paralysis venom only -- the venom will fatigue, not kill.
   Quis, 920620
*/

inherit "/std/creature";
inherit "/std/combat/unarmed";

#include <ss_types.h>
#include <wa_types.h>
#include <macros.h>
#include <stdproperties.h>
#include <poison_types.h>

#define A_BITE  0

#define H_BODY 0

create_creature() {

    if (!IS_CLONE)
	return;
    set_name("spider");
    set_race_name("spider"); 
    set_adj("dog-sized");
    add_adj("hairy");

    set_long("The spider looks creepy!\n");

    set_gender(G_NEUTER);
    set_stats(({ 10 + random(3), 10 + random(3), 10 + random(3), 1, 1, 1})); 
                  /* str, dex, con, int, wis, dis */

    set_skill(SS_DEFENCE, 20);

    add_prop(LIVE_I_NEVERKNOWN, 1);
    add_prop(OBJ_I_WEIGHT, 1000);
    add_prop(OBJ_I_VOLUME, 900);
    add_prop(OBJ_I_NO_INS, 1);

    /* Wep_type,   to_hit,   pen,   Dam_type,   %usage,   attack_desc */
    set_attack_unarmed(A_BITE,   18, 10, W_IMPALE, 100, "jaws");

    /* Hit_loc,   *Ac (impale/slash/bludgeon),   %hit,   hit_desc */
    set_hitloc_unarmed(H_BODY, ({  15,  15, 6 }), 100, "body");

}

/*
 * Function name: cr_did_hit
 * Description:   This function is called from the combat object to give
 *                appropriate messages.  We shall remain content to let 
 *                the default messages be sent, but we will give poison 
 *                to the hit creature.
 * Arguments:     aid:   The attack id
 *                hdesc: The hitlocation description.
 *                phurt: The %hurt made on the enemy
 *                enemy: The enemy who got hit
 *                dt:    The current damagetype
 *                phit:  The %success that we made with our weapon
 *                       If this is negative, it indicates fail
 */

int
cr_did_hit(int aid, string hdesc, int phurt, object enemy, int dt, int phit)
{
    object poison;

/* I believe the spider poisons the player each bite. it should of course
 * be harder to poison the player again and again, Nick */

    if(aid==A_BITE) {
        write("Your fangs bite deep!\n");
        tell_object(enemy, "The spider's fangs bite deep!\n");
        
        poison = clone_object("/std/poison_effect");
        if(poison) {
            poison->move(enemy);
            poison->set_time(1000);
            poison->set_interval(100);
            poison->set_strength(40);
            poison->set_damage(({POISON_FATIGUE, 100, POISON_STAT, SS_CON }));
            poison->start_poison();

        }
    }

    return 0;
}
