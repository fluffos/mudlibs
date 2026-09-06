/*--------------------------------------------------------------------------
 *  /p/school/examples/npc/basic.c --  Example NPC
 *
 *  Copyright (C) 1997 by One Step Beyond.
 *  All Rights Reserved.
 *  Permission granted for non-commercial use.
 *-------------------------------------------------------------------------- 
 *  10-08-97 [tune]  creation
 *
 *  Demonstrates the basic configuration of NPC's
 * 
 *  Section 1: General NPC configuration
 *               Name, short, long, race, gender, level, ids, shrug msg. 
 *  Section 2: Additional Features
 *               Msgin, msgout, mmsgin, mmsgout, wimpy, go chance.
 *
 */
 

#include <npc.h>
#include <properties.h>

inherit "/std/npc";


/* =======================================================================
**       [Section 1]      Initial Configuration
** =======================================================================
**
**       Setting up a simple NPC doesn't take much effort. The basic
**       things you should configure are short and long, name, race,
**       level, and gender. This will give you a perfectly functional,
**       though somewhat bland, NPC.
**
**       The directory /p/school/examples/npc/ contains more example
**       npcs which use some of the more sophisticated features, too.
*/

varargs void create()
{ 

    // --> Always start NPC's like this (and only NPC's!)
    
  ::create();


    // --> NPC's should have a name if they are "unique" NPC's,
    //     meaning that they can be identified by name.
    //
    //     If you set both a name and a short, set the name first.
    //     If the name is set secondly, it will overwrite the short.
    //
    //     The advantage to having both a short and a name is that
    //     the NPC will be listed by its short in room inventories,
    //     but will respond to find_living queries by it's name.
    //
    //     Giving your NPC a name will not add the name to its ids,
    //     but it will react to its name like an id.
     
  SetName("Jane");
  
  SetShort("Jane, the basic npc");

  
    // --> What does she look like? The long is displayed when a player
    //     looks at our NPC.
    
  SetLong("Jane has long mousey hair and is wearing a high-necked "
          "conservative dress.\n");

  
    // --> Now give her some characteristics. 
    //
    //     Gender can be set to male (GENDER_MALE), female (GENDER_FEMALE),
    //     or other (GENDER_OTHER). Only new players in creation should
    //     have GENDER_UNSET. The defines for these settings can be found
    //     both in living.h and properties.h (take your pick, you only need
    //     to include one of them).
    //
    //     Setting a level sets the numerical level value, plus other values
    //     such as stats, hp, sp, experience, and even food and alcohol.
    //
    //     Setting a race will give this NPC all the race bonus points of 
    //     that race, as long as the race exists in the race master.
    //     It's possible to set your NPC to any race you wish, even if
    //     it is not in the race master. The NPC will then get an ID of
    //     that value.
    
  SetGender(GENDER_FEMALE);
  SetLevel(8);
  SetRace("human");
  

    // --> The shrug message is what is printed when the NPC doesn't know
    //     the answer to a question. It's not necessary, but setting it
    //     does help make your NPC just a tiny bit more interesting.
  
  SetShrugMsg(
    "Jane stares at you blankly. That question was obviously far too "
    "difficult.\n");


    // --> It is also possible to add ids specifically to NPC's, just like
    //     you would add ids to objects. The name and race of an NPC are
    //     automatically treated as ids, though they are not listed as such.

  AddId("example"); 


/* =======================================================================
**       [Section 2]      Additional Features                          
** =======================================================================
**
**       Here are some additional values you can easily add to you NPC
**       in create() to make it even more unique.
**       
*/    

    // --> The MSGIN and MSGOUT properties contain the text which is
    //     printed when your NPC enters a room or leaves the room by
    //     "normal" methods (walking).
    //
    //     The MMSGIN and MMSGOUT are "magic" entrance and exit messages,
    //     printed when the NPC enters by magical means (teleportation).
    //
    //     In each case, the first value is for livings who can see, and
    //     the second is for livings which can't see currently (i.e. it's
    //     too dark in the room).   

  Set(P_MSGIN,   ({ "stumbles in", "arrives" }) );
  Set(P_MSGOUT,  ({ "stumbles out", "leaves" }) );

  Set(P_MMSGIN,  ({ "plops in", "is here" }) );
  Set(P_MMSGOUT, ({ "fades away", "left" }) );


    // --> The go_chance determines if you NPC moves around or not.
    //     The higher you set it, the higher the chances are that it
    //     will move each heartbeat.
   
  Set(P_GO_CHANCE, 10);


    // --> You can set an NPC's wimpy value, too.

  Set(P_WIMPY, Query(P_MAX_HP)/2);
}
