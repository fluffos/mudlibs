// Basic room school by Avelan
// April 2001
// room #2

/*
* NOTE: If you want to see this same file without
* the comments in the code, take the exit 'example'.
* I'd suggest you do that anyway after you have read
* this file through.
*/


/*
* The next line will include the file called 'defs.h'
* which is in the same directory as this file.
* That file contains definitions for filepaths, so i
* don't have to write absolute paths anywhere here.
* There will be more info about this later in the file.
*/
#include "defs.h";

/*
* The next line inherits the file /std/room/basic_room.
* So, ROOM_OBJ == /std/room/basic_room, why, you ask?
* Help global defines gives you a list of things that
* are defined everywhere automatically.  And the real
* advantage of inheriting ROOM_OBJ instead of the 
* absolute path/filename, is that if that file called
* basic_room is decided to be transferred to some other
* directory, all you have to do is make a simple alteration
* in the global defines and all the rooms that inherited
* ROOM_OBJ would work, but the ones that inherited it using
* the absolute path would not because they would point
* to a file that isn't there.
*/

inherit ROOM_OBJ;

/*
* Ok, now to the coding part.  The next function actually
* overrides the one in basic_room using the arguments you
* put in there.  So, setup() determines all the basic stuff
* a room needs to have in order for it to be a proper room.
* This might sound a bit hard but it really isn't. :)
*/
void setup(){

    // The next line determines the light level of the room.
    set_light(100);

    /* Next one will be the short description for the room, 
    * ie. the thing you see when you glance at a room or walk in
    * it in brief mode.
    * The short desc should be two-three words long, it's not meant
    * to describe the room.
    */
    set_short("basic room school");

    /* The next sets the determinate the room has.
    * Notice the space after it.
    * This is used in messages like:
    * 'Avelan gets a womble from the basic room school.'
    */
    set_determinate("the ");

    /* Ok, then the actual room description. The long description
    * should normally have atleast 4-5 lines or the room would seem
    * quite empty.  There are many things which determine a good
    * room desc, for example, descs should never contain words like
    * you or yours, let the player decide what they make of the things
    * they see.  But this is something you will learn through experience,
    * so i won't babble about for longer.
    * Notice at the end there is '\n' , that let's the players
    * client take care of the newline needed at the end.
    */
    set_long("This is a room which describes how a very"
      " basic room is built.  The room is quite small and"
      " rather empty since there is only a table and a small"
      " chair standing in the middle of the room.  There is"
      " some writing on the table probably made by a bored"
      " apprentice creator trying to learn things.\n");

    /* Ok, next the add_items for the room.
    * Any room should have an add_item for every
    * thing the player could try to take a look at.
    * Every noun in the long_desc _should_ have an add_item.
    * Do help add_item to learn more about the function.
    */

    add_item("room","The room looks quite empty.");

    /* The next add_item matches to more than one
    * word, that's why the words are inside brackets.
    */
    add_item(({"creator","apprentice","apprentice creator"}),
      "They are the ones that are learning new stuff, this room"
      " is built for them.");

    add_item("thing","There are many things to learn here.");

    /* Ok, the next ones for the table and the chair are a bit
    * more complicated.  They make it possible for the players
    * to sit or stand on the items too.
    * Again, do help add_item to get more help on it.
    */
    add_item("chair",({ "long","The chair is old and worn"
        " out, it's been under heavy use.","position","the chair"}));
    add_item("table",({ "long","The table is an ordinary, round,"
        " wooden table, it has some writing on it.",
        "position","the table"}));

    /* The next one gives a new option to add_item, read.
    * The player will see the text when they do 'read writings'.
    */
    add_item("writing",({ "long","There is some writing on the"
        " table, You could read it if you want to.",
        "read","I'm so booooreeed!\n" }));

    /* Okies, then the last thing a VERY basic room needs,
    * the exits.
    * Notice the ROOMSC in the middle there.  This is just
    * the thing that i talked about in the beginning.  The word
    * ROOMSC is defined in defs.h to point to
* '/d/learning/school/room_school/room_basic/'.
    * So i only wrote ROOMSC "filename" there, now if i decide to
    * move the file it points to in a different directory, i only need
    * to edit defs.h and make ROOMSC point to the right directory.
    * Very handy wouldn't you say? :)
    */
    add_exit("backward",ROOMSC "room_school01","path");
    add_exit("forward",ROOMSC "room_school03","path");
    add_exit("example",ROOMSC "example01","path");

} /* setup */
