a
When a player tries to go from one room to another, the code in the first room
uses the efun call_other() to try to load the new room.  If the driver fails
to find a file corresponding to the new room, before returning an error, it
checks for a virtual room.

It does this by calling the function compile_object() in /adm/obj/master.c
with a string containing the supposed file name of the new room, eg
  "/domains/desert/room/500,501.d"

The master object calls the virtual daemon /adm/daemon/virtual_d.c  ie
  VIRTUAL_D-> compile_object( "/domains/desert/room/500,501.d" );

In the case of desert rooms, all the daemon does is the call
  "/adm/obj/server"-> compile_object( "/domains/desert/room/500,501.d" );

This in turn calls
  "/domains/desert/virtual/d_server"->
    compile_object( "/domains/desert/room/500,501.d" );

The d_server.c clones a copy of itself and returns it back up the chain to
the master and driver, at which point the room behaves just like any other
object you can do a call_other to.
