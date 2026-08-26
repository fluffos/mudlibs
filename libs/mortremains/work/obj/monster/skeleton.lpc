/*
** File: skeleton.c
** Date: September 10th, 1997
** Purpose: An example of a monster.
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    // These first three lines are important. Any monster should
    // include them.
    ::create();
    seteuid(getuid());
    enable_commands() ;

    // This is the person who coded the monster. It is mandatory.
    // Make sure it is just the author's name, lower-cased.
    set("author", "nightmask");

    // "Short" is what you see in an inventory. The "short description".
    set("short", "a skeleton");

    // This is the text you get when you look at the monster.
    set ("long", @EndText
This is a skeleton; there is no flesh left on its body.
He looks back at you with hollow eyes.
EndText
    );   // EndText should be on a line all by itself, with NO SPACES

    // The 'id' is a list of all the things you can use to referance 
    // the monster.
    set("id", ({ "skeleton", "monster" }) );

    // Size is just what it sounds like, the size of the monster, 
    // in feet
    set_size(6);

    // This line tells the mud the actual name of the monster, for stuff
    // like combat and emotes.
    set_name("skeleton") ;

    // The is self-explanatory. Male, female, neuter...
    set("gender", "neuter");

    // 'Race' is the race of the monster. It can be whatever you like.
    set("race", "skeleton");

    // This tells the mud if the monster is alive or undead.
    // 1 = undead, 0 = still breathing.
    set("undead", 1);

    // This sets the combat damage a monster does without a weapon.
    // The first number is the minimum, the second is the maximum.
    set("damage", ({ 1,4 }) );

    // This is the name of the monster's barehanded weapon.
    set("weapon_name", "claws") ;

    // These are the verbs a monster uses when it attacks. They are
    // automatically conjugated in combat, so others will see
    // "Skeleton attacks", instead of just "attack"
    set_verbs( ({ "attack", "claw at", "swing at" }) ) ;

    // You only need set_verbs2() if your verbs will be grammatically incorrect
    // when you add an "s" to the end of the first word.  Normally, without
    // set_verbs2() being set, the verbs from set_verbs() just have an "s"
    // appended to the first word to make them grammatically correct.  
    // Since english is fucked up, not all words follow this rule, and that is
    // where set_verbs2() comes in.  Example
    // er.. Example:  You set verbs to be "punch at", "swing at", "attack"
    // The monster would see "punch at", "swing at", and "attack" while the
    // victim and onlookers would see "punchs at", "swings at", and "attacks"
    // Guess which is fucked up?  Punchs at.  Wrong-o.  It's one of those fun
    // words that needs the "es".  Well set it that way in set_verbs2()!
    // "punches at", "swings at", and "attacks" would go in your set_verbs2()
    // in this example.  In this file, however... the grammar works out
    // just fine without a set_verbs2().. so we won't use it. :)

    // This sets the chance that a monster will output a chat in any 
    // given second. Here, the skeleton has a 10% chance to chat per 
    // second.
    set ("chat_chance", 10);

    // This is the list of the monster's possible chats when not in
    // combat.
    set ("chat_output", ({
      "The skeleton stares at you through empty sockets.\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
      "The skeleton glares at you through empty sockets.\n",
    }) );

    // set_level() is one of Cyanide's brainstorms. what it does is 
    // basically everything, you need this line if you plan to make a 
    // working monster. It sets hp, xpv, stats, etc.
    // This should always be LAST in the create(), followed ONLT by
    // wear() and arm() statements.
    set_level(1);

    // Chronos' new arming monster function.. Easy!
    // This function will clone argument (in this case "/doc/examples/axe")
    // The wear() function works exactly the same.  These functions 
    // should always be called last in the create(), just after 
    // the set_level() statement, to make sure all the necessary 
    // properties for wielding have already been set. :D
    arm("/doc/examples/axe") ;
}

/* End of File */
