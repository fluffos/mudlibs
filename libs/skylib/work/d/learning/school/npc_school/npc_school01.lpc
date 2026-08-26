/**
 * Making a room clone and set up a basic NPC.
 * October '01 by Avelan
 */

#include "defs.h"

inherit ROOM_OBJ;

/*
 * Here we declare a (global) variable 'butterfly', that is an object.
 *
 * You could also just declare it inside a function, but you would then
 * have to declare it separately in every function you use it in.
 *
 * The main difference between a local variable (that is declared inside
 * a single function only) and a global variable (declared globally in
 * an object, such as this room) is that the value of a global variable
 * is stored and it can be used in every function in the object, whereas
 * a local variable only exists when the specific function is called,
 * and isn't stored in any way.
 *
 * We are using a global variable here, so that we can keep track of the
 * NPC that is cloned - when the NPC is cloned, we will assign the object
 * we created to this variable.  This variable will then be keeping the
 * value of the NPC object, and will be usable in any function of the room.
 */
object butterfly;

/*
 * Here we add a 'prototype' function called make_fly().
 * This is needed because the make_fly() function itself is in the end
 * of the file, while the setup function is trying to use it earlier.
 * Another way would be to move the make_fly code in front of the
 * setup function, that way the prototype wouldn't be needed (but I like
 * having setup as the first function in my rooms :) ).
 */
void make_fly();

void setup() {
    set_zone("npc_school");
    set_determinate("an ");
    set_short("NPC cloning room");
    set_light(100);
    set_long("This room explains how to clone an NPC without having to "
        "write a separate file for it.  This is the preferred way of "
        "creating simple NPCs that have no additional functionality "
        "besides chats.  It is preferable, because this way there won't "
        "be a 'master copy' of the NPC loaded into the memory at any "
        "time, but instead the room (or any object for that matter) sets "
        "up the properties for the NPC.\n"
        "Note - if you 'more' the NPC here, you will see the contents of "
        "the basic NPC object, since it doesn't have its own file.\n");

    add_item("master copy", "What is called a master copy in LPC, is in fact "
        "an object just like any other.  The difference between a clone an a "
        "master copy is subtle, yet important.  When a file is loaded into "
        "the memory by the mud, a master copy is created, which is then used "
        "to make clones from.  There are several ways to make out whether or "
        "not you're dealing with a master copy or a clone - the easiest of "
        "them probably being the 'pathof' command, which will return the "
        "object reference or file name of an object.  Master copies will "
        "always have the exact name of the file they were loaded from, while "
        "clones will have an object number tacked to the end of the file "
        "name.  For example 'pathof me' will give me /global/creator#33391, "
        "which means I have been cloned from an object called "
        "/global/creator, and 'pathof butterfly' will give me "
        "/std/npc#12947, which means the butterfly is a clone of /std/npc, "
        "which is the main NPC inheritable.  Rooms in most cases "
        "('pathof here') are all master copies, because there is really no "
        "need to make a clone of a room, because most rooms look rather "
        "different.");

    add_exit("forward", NPCSCHOOL+"npc_school02", "path");
    add_exit("back", NPCSCHOOL+"start", "path");

    /*
     * Here we make a butterfly right when the room loads.
     * This way the first person to enter and load the room will have
     * a butterfly here instantly, instead of waiting for the call out
     * in reset to execute.
     */
    make_fly();

} /* setup() */

/**
 * The reset function is called on each and every object
 * in the mud periodically by the mud driver.
 * This makes it the preferred way of checking whether
 * or not to clone NPCs.
 */
void reset() {
    /*
     * We could have the NPC made inside the reset()
     * but it's better to do anything crucial inside
     * another function, to 'spread the load', so to speak.
     * This is because reset() is called on a number of
     * objects at the same time, and it would lag the mud
     * considerably if each an every one of them tried to
     * execute some code all at the same time.
     */
    /*
     * This if statement checks whether or not there is already
     * an object assigned to the butterfly variable.
     * The exclamation mark basically means 'no' in LPC -
     * therefore if there is no butterfly, we will make a new one
     * with a call out to a function called make_fly, in 4 seconds.
     */
    if( !butterfly )
        call_out("make_fly", 4 );

} /* reset() */

/**
 * This is the function that will actually clone the NPC.
 */
void make_fly() {
    /*
     * Check once more for the existence of the NPC, just in case :)
     */
    if( !butterfly ) {
        /*
         * Here we clone the basic NPC object and assign the
         * created object to the 'butterfly' variable, and mold
         * it to our needs.  We give it everything we would in
         * a normal NPC file and then move it into the room.
         *
         * NOTE : This is the preferred way of cloning every
         * simple NPC, ie. the kind that don't do anything else
         * than just stand there chatting, waiting to be killed.
         */
        butterfly = clone_object(NPC_OBJ);
        butterfly->set_name("butterfly");
        butterfly->set_short("butterfly");
        butterfly->set_determinate("a ");
        butterfly->set_long("This is a beautiful butterfly fluttering about "
            "with spotted, colourful wings and sad little eyes.  The wings "
            "make an image that looks like the face of some larger "
            "creature.\n");
        butterfly->basic_setup("insect", 1 + random( 5 ), "male");
        butterfly->load_chat( 30, ({
            1, ":flutters about.",
            1, ":flutters closer to you.",
            1, ":lands to rest on a nearby flower.",
            1, ":makes no noise at all."
            }));
        butterfly->load_a_chat( 60, ({
            1, ":makes an effort to fly as far as possibly from you.",
            1, ":looks dazed.",
            1, ":flutters its wings threateningly."
            }));
        butterfly->move( TO, "$N flutter$s in from somewhere.");
    }

} /* make_fly() */
