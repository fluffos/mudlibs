
                                                              QUERY_VISION(L)

   NAME
     query_vision() - determine whether an object can see, and how much.

   SYNOPSIS
     int query_vision() ;

   DESCRIPTION
     The query_vision() lfun is defined in /std/living.c. It determines
     whether the room light lets the object see at all, and if so, how much.
     It makes a series of checks. First, if the object has its "full_vision"
     property set, the object may see at all times. If the room has light and
     the user is not blind, he may see. If the room is dark but the user has
     infravision, then the user may see some things based on his infravision
     capability.  Otherwise the user may not see things.  You can override
     query_vision in your own monsters if you like to, or you can implement
     night-vision goggles or other vision aids by shadowing this lfun.
     Objects that are nonliving, such as ghosts, also define this lfun
     seperately. In the ghost object it always returns 1, ie ghosts may see
     at all times.

   SEE ALSO
     /std/living.c, /std/ghost.c.

   AUTHOR
     Mobydick@TMI-2

                                                                            1

