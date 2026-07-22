
                                                               SET_OUTSIDE(L)

   NAME
     set_outside() -  notify the weather daemon that a room is outside.

   SYNOPSIS
     varargs void set_outside (string zone) ;

   DESCRIPTION
     The set_outside() lfun is defined in room.c. When called by a room, it
     sets that room to be outdoors for the purposes of time and weather. This
     has the following effects: 1. The room will receive daylight and weather
     notices.  2. Light in the room is determined by the
     query_ambient_light() lfun in the weather daemon, based on sun and
     weather.  3. The room's "outdoor" property is set to the string argu-
     ment, or to "A" if no argument was passed.

     The string argument currently does nothing, but will later be used to
     implement time zones and weather zones.

   SEE ALSO
     /std/room.c, /adm/daemons/weather_d.c.

   AUTHOR
     Mobydick@TMI-2, 7-2-93

                                                                            1

