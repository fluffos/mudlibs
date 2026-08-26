
QUERY(L)                LOCAL FUNCTIONS                  QUERY(L)

NAME
     query - returns the value of a property in an object

SYNPOSIS
     mixed query (string prop) ;

DESCRIPTION
     This lfun is defined in the standard object. It is  used  to
     get  the  values of properties previously set with the set()
     lfun.

     The standard object contains a mapping called ob_data, which
     is  used  to  store  the  properties  and  their values. The
     query() lfun returns the value of the element in the ob_data
     mapping whose key is the argument passed.  Example:

     foo = query("hit_points") ;

     will  set  the  variable  foo  equal   to   the   value   of
     ob_data["hit_points"].

     Property values may be set  to  function  names  instead  of
     values,  by  setting  them  to a string beginning with "@@".
     When this is done, query("foo") will call  the  named  func-
     tion, and will return the result of that function call.  For
     example:

     set ("frogs", "@@find_frogs") ;

     would cause query("frogs") to call the function  find_frogs.
     This function might look like this:

     int find_frogs() {       if  (wizardp(this_player())  return
     frogs ;      return 0 ; }

     meaning that if query("frogs") is called by a  wizard,  they
     will  get  the  number  of frogs, but if called by a player,
     they will get 0.  Properties  whose  values  depend  on  the
     querier, or whose values change over time, should usually be
     handled by overrides. For example, the room's long  descrip-
     tion  is handled by an override so that a list of the room's
     contents can be appended when query("long") is called in the
     room.

     If a property is set to a mapping, then the individual  ele-
     ments  of  that  mapping can be queried using the / divider.
     For example:

     set ("wealth", ([ "gold" : 50, "silver" : 10 ]) ) ;


TMI-2 Release 0.9         Last change:                   4-2-93

QUERY(L)                LOCAL FUNCTIONS                  QUERY(L)

     then

     query ("wealth/gold") ;

     will return 50.

SEE ALSO
     set(), add(), delete(), /std/object/prop.c.

AUTHOR
     Mobydick@TMI-2

Sun Release 4.1           Last change:                          2

