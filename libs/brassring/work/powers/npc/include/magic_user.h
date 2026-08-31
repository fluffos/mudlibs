/*    /lib/powers/npc/include/npc_magic_user.h
 *    based on the Dead Souls mud library
 *    maintained by Cratylus http:www.dead-souls.net
 *
 *    created by lash (ccoker) for use in
 *    The Brass Ring mud
 *    last modified: 20/05/20
 */

#ifndef l_magic_user_h
#define l_magic_user_h

int SpellCombat(object ob);
void magic_missile(object ob);
void blindness(object ob);
void burning_hands(object ob);
void lightning_bolt (object ob);
void colour_spray (object ob);
void fireball(object ob);
void curse(object ob);
void energy_drain(object ob);
void sleep(object ob, object *targets);

#endif l_magic_user_h
