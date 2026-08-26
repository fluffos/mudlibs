/* Example of a basic NPC, written by Hobbes, updated by Sandoz */

inherit NPC_OBJ;
      /* NPC_OBJ is a large but needed file and holds the advanced npc
       * handling stuff which you don't have to think about. Inheriting this
       * saves memory and you don't have to write it again for your npc.
       * (Why invent the wheel twice?)
       */
#include <armoury.h>
      /* This file is needed if you want to add clothes, weapons and armoury
       * from /obj/clothes, /obj/weapons and /obj/armoury respectively.
       */
object comb;
      /* If you want to equip your NPC from other directories, you need to
       * define the objects and clone them separately.  See below.
       */

void setup() {
    set_name( "ralph" );
      /* set_name() is the name the npc will be refered with.  It's almost
       * always a noun or a name from the short.  It's always in lowercase.
       */
    set_short( "Ralph the spotted giraffe" );
      /* set_short() is what the player will see when the npc is in the
       * same room.
       */
    add_property( "determinate", "" );
      /* This property also helps giving nice outputs.  Determinates such as
       * "a" and "an" are handled automatically without the property.  The
       * line above sets the determinate to none.  Unique npcs with names
       * should have the none determinate, while npcs like the librarian
       * should have "the " (note the space).
       */
    add_adjective( "spotted" );
      /* All relevant adjectives should be given using add_adjective.
       * Adjectives in the short _must_ be given since the player ought at
       * least be able to reference an object by its short, e.g. - , - ,
       * "old", "green", "blue", ({ "wooden", "wood" }), ({ "chocolate",
       * "choc" }), "short", "shiny".
       */
    set_main_plural("Ralph the spotted giraffes");
      /* This sets what you see when there are more than one of them in the
       * room.
       */
    add_plural(( { "ralphs", "giraffes" } ));
      /* Sets the plural which you can call them by.  Note that the system
       * automatically adds one plural for you: the plural of the name once
       * you have called set_name().
       * This may look weird in some cases though. A prime example for items
       * are the plural of "roof" is found to be "rooves", so the correct
       * plural must be given, e.g. add_plural( "roofs" );
       */
    add_alias(( { "giraffe", "Ralph" } ));
      /* This is simply another name which you can refer the NPC with.
       * Players can type "look ralph" as well as "look Ralph".
       */

   set_long( "This is Ralph the spotted giraffe.  He is just an example in "
             "this file so I won't describe him although I should.  Well, "
             "okay then... He's like any normal giraffe except for his cool "
             "black specs and mop fringe.  He is coolnes personified.\n" );
      /* The set_long() is what you see when you look at the NPC.  It should
       * be detailed and interesting.  Don't just describe what they are.
       * Describe what they look like as well.
       */
    add_property( "unique", 1 );
      /* The unique property does the following. First it lets you set the
       * NPCs own stats.  If you don't include this, it will use the race
       * object's numbers.  Second, an unique NPC gives reduced exp when killed
       * (it will be logged in /log/DEATHS, and be informed to the creators).
       * Third, the NPC will be on the bounty system.
       */
    basic_setup( "horse", 15, 1 );
      /* Sets the race, level and the gender for the NPC.
       * We'll use horse as there is no giraffe race at the moment.  Look
       * in /std/races/ for possible races to choose from.  The race handles
       * bits like attacks, stats and body parts.  A crocodile has a tail
       * while a a dwarf has not, for example.
       * By setting the level of the NPC we can roughly set how much experience
       * the NPC should give.
       * Finally, we set the gender of the NPC.  This can either be a number -
       * ( 0 = it, 1 = male, 2 = female ), or a word - "male", "female".
       */
    set_height( 300 );
      /* Height in centimeters. (This can usually be left out.)
       */
    set_weight( 1600 );
      /* 1 unit of weight is about equal to 50 grams or 1/9lb for all you hairy
       * wombles out there. (This can usually be left out.)
       */
    set_al( -500 );
      /* Sets the alignment of the NPC.  0 is neutral, the more positive number,
       * the more evil the NPC is.  Ralph is a really nice guy, so we set his
       * alignment to a negative number.
       */
    set_con(18);
    set_dex(18);
    set_str(16);
    set_wis(15);
    set_int(15);
      /* Well, this is the way to set the stats manually.  It will be the race's
       * default if you don't include these and the unique property.
       */
    add_move_zone( "Short" );
    add_move_zone( "Filigree" );
      /* This defines where Ralph is allowed to walk.  Short- and Filigree Street
       * have these 'set_zones()' respectively.
       */
    set_move_after( 50, 60 );
      /* This sets the time delay in seconds between when the monster wanders, in
       * this case: sometime between 50 and 60 seconds.
       */
    load_chat( 90, ({
        3, "@grin",
        3, "@high5 $lname$",
        2, "@bless $lname$",
        1, "@moonwalk",
        1, "'Far out man.",
        1, ({ "'Hey, if it isn't $lname$!",
              "'You're looking cool as usual!" }),
        1, ":tells you: Hey my man!  Watcha up to?",
        1, "'That's cool.",
        1, "'Chillin' out here, are we?",
        1, "@ruffle $lname$",
        1, "@wink $lname$",
        2, ":does a really complicated tap dance manoeuvre.",
        1, "'Let's do something wild and crazy...",
        1, ({ "'Yoho, how's it hangin'?",
              "'I'm in a darn good mood today!" }),
        1, ":tells you: Ouch man, where the heck did you find those clothes?"
        }) );
      /* This loads up the default chat messages.  The chance is the chance in
       * 1000 that one of the messages will show up every heart_beat whilst not
       * in combat.  The number infront of the chat is designed to allow you to
       * make some messages much more likely to be said than others.
       * The character the chat begins with defines the following:
       * @         Soul command
       * '         Say.
       * "         Loud say.
       * :         Emote.
       * default   echo.
       * $lname$   is a random player in the room.
       */
    load_a_chat( 100, ({
        1, "'Wait till Hobbes hears about this!",
        1, "'It's SO uncool to fight!",
        1, "@scream",
        1, "You can't believe you're fighting such a nice creature as Ralph.",
        1, ":seems to wish he was somewhere else."
        }) );
      /* Load_a_chat is just the same as load_chat above, except this is used
       * when the NPC is in combat.
       */
    ARMOURY->request_item("meat cleaver", 80+random(20))->move(this_object());
    ARMOURY->request_item("gigantic dog collar", 100)->move(this_object());
    ARMOURY->request_item("straw hat", 80)->move(this_object());
      /* These lines automatically clone stuff from the /obj/ directories.
       * You must have <armoury.h> included (see above).
       * The number sets the condition (percentage) of the object.
       * Notice that you don't need the underscores in the names and clothes
       * requested from the armoury.
       */
    comb = clone_object("/d/am/items/comb");
    comb->move( this_object() );
      /* And this clones and moves the the object we defined at the top of the
       * file.  If possible, always try to use the armoury.
       */
    init_equip();
      /* This makes the NPC equip the armoury he has been given.
       */
} /* setup() */

/* Most of the functions are explained further in help files, do
 * "help load_chat" for example.  See also "help setup".
 */
