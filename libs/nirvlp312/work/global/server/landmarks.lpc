/*
    landmark server
    4/29/93 Foslay

    This server will be usable in connection with
    the position properties of rooms. The Idea is
    that a command (e.g. ``look at landmarks'') will
    describe other part of the mud which are close
    enough to be seen.
*/


#define SAVEFILE "/save/landmarks"

inherit "/basic/create";

mixed *landmarks = ({});

create ()
{
  if (clonep ()) destruct (this_object());
  restore_object (SAVEFILE);
}
register_landmark (x,y,z,size,region,descs,t) {}

