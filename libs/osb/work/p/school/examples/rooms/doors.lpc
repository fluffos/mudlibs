/*--------------------------------------------------------------------------
 *  /p/school/examples/rooms/doors.c --  Example Doors Room
 *
 *  Copyright (C) 1997 by One Step Beyond.
 *  All Rights Reserved.
 *  Permission granted for non-commercial use.
 *-------------------------------------------------------------------------- 
 *  29-sep-92 [mateese]  creation
 *  11-nov-97 [tune]     update
 *
 *  This is a sample room featuring a door connected to a door in ***.
 *  Here we also find the right key for the locked door in ***.
 * 
 *  Section 1: Initial configuration of the room
 *               
 *  Section 2: Simple uses of AddDoor()
 *
 *  Section 3: A more complex use of AddDoor()
 *
 */
 
 
/* =========================================================================
**       [Section 1]      Initial Configuration
** =========================================================================
**
**       Doors are actually not as difficult to add to rooms as they
**       may at first seem. As long as you use the standardized doors
**       via AddDoor() from /std/room.c, most of the work is done for
**       you.
**
**       AddDoor() automatically clones a door object and adds an exit
**       to the specified room. It is neither necessary to manually
**       clone the door object nor specially add this exit. 
*/


  // -------------------------------------------------------------------
  //   First we include the macros we'll need. We need doors.h and 
  //   lock.h for the door macros, and rooms.h for the right key.
  // -------------------------------------------------------------------

#include <properties.h>
#include <doors.h>     
#include <lock.h>
#include <rooms.h>     
#include <school.h>

inherit "/std/room";

void create() 
{
  ::create();
  
  // -------------------------------------------------------------------
  //   Set up the room as you would any other room with long, short,
  //   details and exits which don't use doors.
  // -------------------------------------------------------------------

  Set(P_INT_SHORT, "The doors example room");

  Set(P_INT_LONG,
   "You are in the example room for doors. "
   "It features a simple door leading west, a locked door leading east, "
   "and a locked trapdoor set into the ground.\n");
     
     
   // Now place the right key for the locked eastern door here.
   // The key will be refreshed on every reset if it was taken away.
   //
   
  AddItem ("/p/school/examples/rooms/boguskey", REFRESH_REMOVE);
  
     
/* =========================================================================
**       [Section 2]      Simple Uses of AddDoor()
** =========================================================================
**
**       Doors are actually not as difficult to add to rooms as they
**       may at first seem. As long as you use the standardized doors
**       via AddDoor() from /std/room.c, most of the work is done for
**       you.
**
**       AddDoor() automatically clones a door object and adds an exit
**       to the specified room. It is neither necessary to manually
**       clone the door object nor to specially add the exit. 
*/


  /* -------------------------------------------------------------------
   *   Example 1
   *   AddDoor( string exit_direction, string connected_room, 
   *            string door_short, string door_long,
   *            0, int lock_status )
   * -------------------------------------------------------------------
   *
   *   Now we add our first door. This is the simplest type of door
   *   which you can add to a room. It is openable and closable, but
   *   not lockable.
   *
   *   arg1:   The command to exit via this door, also giving
   *           the direction it leads.
   *   arg2:   The room to which the door leads. If in that room contains 
   *           a door with the same arg3, both doors are connected
   *           and synchronized automatically.
   *   arg3:   A short description of the door. When looking into the room,
   *           the door will appear as "There is a <arg3> to the <arg1> 
   *           here." This is also the identification for the remote door 
   *           on the other side of the exit.
   *   arg4:   The door's long description (subject to process_string() ).
   *   arg5:   The key's ID. Since this door isn't lockable, this is 0.
   *   arg6:   The macro LOCK_CLOSED is from lock.h, and indicates
   *           that the door is closed by default.
   *
   * -------------------------------------------------------------------
   */
  
   AddDoor( "west", EXROOMS("xroom2"), "wooden door",
            "An old wooden door.\n", 0, LOCK_CLOSED );
           

  /* -------------------------------------------------------------------
   *   Example 2
   *   AddDoor( string exit_direction, string connected_room, 
   *            string door_short, string door_long,
   *            string key_id, int lock_status )
   * -------------------------------------------------------------------
   *
   *   This door only differs to example 1 in that it can be locked
   *   and unlocked using the key specified in key_id.
   *
   *   Doors can be configured to recognize either generic types of
   *   keys, or only one specific key. When key_id (arg5) is a string,
   *   the door checks the key's ids to see if one matches. This id
   *   could easily be a generic type of id which would match various
   *   keys. Our eastern door will recognize any key which has an id
   *   of "skeleton key".
   *
   * -------------------------------------------------------------------
   */
   
   AddDoor( "east", EXROOMS("xroom2"), "locked grating",
            "A locked grating in the lower east wall leads into darkness.\n",
            "skeleton key", LOCK_LOCKED );
            

  /* -------------------------------------------------------------------
   *   Example 3
   *   AddDoor( exit_direction, connected_room, door_short, 
   *            door_long, ({ key_code, key_id1, key_idn }), 
   *            lock_status )
   * -------------------------------------------------------------------
   *
   *   A second way to implement key ids is to use one or more generic
   *   ids and a specific key_code. The key_code is used to restrict
   *   the locking or unlocking of the door to one specific key. 
   *
   *   In this case, arg5 should be an array of strings. The first element
   *   in the array is the specific key_code, and the remaining elements
   *   are generic key types. They must all match any one key for the
   *   door to be locked/unlocked. The array may also contain only one
   *   element, the key_code.
   *
   * -------------------------------------------------------------------          
   */
   
   AddDoor( "up", "/p/school/examples/rooms/drinking",
            "metal door", "A shining metal door.\n",
             ({ "exMetalKey6", "metal key" }), LOCK_OPEN );
   
   


   
   
}  // end of create()

/*------------------------------------------------------------------------*/
