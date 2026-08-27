
QUERY_HB_STATUS() MISC. REFERENCE MANUAL PAGES  QUERY_HB_STATUS()

NAME
     query_hb_status() - indicate whether a  monster's  heartbeat
     is on

SYNOPSIS
     int query_hb_status() ;

DESCRIPTION
     The query_hb_status() lfun is defined in /std/monster.c.  In
     the  TMI-2  mudlib,  monsters who are not healing and not in
     combat turn off their heartbeats, in order to save CPU  use.
     The  query_hb_status()  function  returns  1  if a monster's
     heart is beating and 0 if not. The heart_beat is turned back
     on in the kill_ob function when combat begins, and is turned
     off when the monster is healed in the heal_up function.

SEE ALSO
     heal_up(), kill_ob(), /std/monster.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

