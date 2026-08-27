/*
 * /doc/examples/poison/dagger.c
 *
 * Quis 920618
 */

inherit "/std/weapon";
#include <ss_types.h>
#include <wa_types.h>
#include <poison_types.h>

int poison_used;

create_weapon()
{

/* Set up the name of the dagger, etc. */

    set_name("dagger");
    set_short("small dagger"); /* Observe, not 'a small dagger' */
    set_long("@@long_desc");  /* This is VBFC to tell of the poison on the */
                            /* dagger. */
    set_adj("steel");
    add_adj("small");

/* Make it fairly ordinary */
    set_hit(12);
    set_pen(10);
    set_wt(W_KNIFE);

    set_dt(W_IMPALE);
    set_hands(W_ANYH);

/* the poison isn't used, upon creation */
    poison_used = 0;

}

string
long_desc()
{
    if(poison_used)
        return "You see nothing special about the dagger.\n"; 
    else
        return "You percieve a sheen of liquid on the blade.\n"; 
}

/*
 * We redefine did_hit() in order to actually poison the player.  We will
 * set it up so that the poison wears off the blade after a while.
 */

public varargs int
did_hit(int aid, string hdesc, int phurt, object enemy, int dt, int
phit)
{
    object poison;
/*
 * Now we create the poison.  For fun we will make it an anti-mage
 * poison.  After we clone it, we move it to the consuming living, 
 * then call the activating function, start_poison()
 */
    if(!poison_used && !random(5))
    {
        poison = clone_object("/std/poison_effect");
        if(poison) {
            if(random(2))
                poison_used = 1;
            poison->move(enemy);
            poison->set_time(500);
            poison->set_interval(60);
            poison->set_strength(40);
            poison->set_damage(({POISON_MANA, 100, POISON_STAT, SS_INT}));
            poison->start_poison();
            return 0;
        }
        else 
            write("Failed to load poison for some reason.\n"); 
    }
    return 0;
}

