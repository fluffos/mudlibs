#include <config.h>
#include <mudlib.h>

inherit OBJECT;

// victim stores an object pointer to the person who
// was bitten by the spider.
// This is needed because this_player() isn't defined
// in the call_out.
object victim;

// Do_effect is called after the delay period.
// It is the actul effect of the poison, for
// instance, take away some hit points.
int do_effect() {
    // define potion effect here
    return 1;      
}


// Do_wear_off is called when the poison wears
// off, after the effect time has expired.  Use
// it, for instance, to have the player throw up
// as the poison wears off .. :P
int do_wear_off()
{
}



// What to do to cause the initial effects.
// Don't change this.
int potion_effect() {
    do_effect();
    call_out ("wear_off", query("effect_time")) ;
    return 1;
}



// What to do to wear off, don't change this.
int wear_off()
{
    do_wear_off() ;
    remove();
    return 1;
}



// To poison the player, in the spider.c say something like:
//
// ob = clone("this/object");
// ob->poison(victim_player);
//
// 'delay' seconds later the poison_effect occurs
// 'effect_time' after that the wear_off effect occurs
//    and this object pops.
//
void create()
{
    // effect_time is the length of time the poison
    // is in effect.
    if (!query("effect_time"))
        set ("effect_time", 240); // seconds, 4 minutes
}



int poison_player(object player)
{
    int delay;

    // Do this before the call_out .. just in case
    // we're delayed before moving into the player.
    victim = player;

    // Choose a random delay to onset, from 5 to 20 seconds.
    delay = 5 + (random(15));
    call_out ("poison_effect", delay);

    // Don't want anyone messing with this while it's in effect.
    // this isn't the Right Way to do this but it's better than
    // any equally easy alternative.
    set ("id", ({ }) ) ;
    delete("short");
    move(VOID);
    delete("mass");
    delete("bulk");

    // All set .. here we go .. !!!
    move(player);

    return 1;
}

