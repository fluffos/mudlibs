
SET(L)                  LOCAL FUNCTIONS                    SET(L)

NAME
     set - sets the value of a property in an object

SYNOPSIS
     varargs void set (string prop, mixed data, int security) ;

DESCRIPTION
     This lfun is defined in the standard object. It is  used  to
     assign  values  to  properties  (named  by  strings)  in the
     object.

     The standard object contains a mapping called ob_data, which
     is  used to store the properties and their values. The set()
     lfun creates a new element in that mapping whose key is  the
     first argument passed and whose value is the second argument
     passed. Example:

     set ("hit_points", 10) ;

     would set ob_data["hit_points"] equal to 10. If the  mapping
     already  has  an  element by that name, the old value of the
     data element is lost.

     In the secure standard object, the optional third  argument,
     when  used  at  the initial call to set(), provides security
     against later changes of the

     variable value, by limiting  what  objects  can  later  call
     set()  to that property name. Possible values are defined in
     /include/priv.h, and they are:

     PUBLIC  -  anyone  can  change  it.  This  is  the  default.
     READ_ONLY  -  anyone  can  read  it,  but only the owner can
     change it.  OWNER_ONLY - Only the owner can read it LOCKED -
     Anyone  can  read  it,  but  no one, not even the owner, can
     change it.  MASTER_ONLY - can only be  read  by  the  master
     object.   PRIVATE  - Cannot be read or changed. For internal
     use only.

     You can set a property to be a mapping. For example, you can
     do:

     set ("wealth", ([ "gold" : 50, "silver", 10 ]) ) ;

     which causes the wealth property to be  a  two-element  map-
     ping.  If  you  have already set a property to be a mapping,
     you can subsequently set the elements of that mapping  using
     the / divider. Example:

     set ("wealth/gold", 60) ;


TMI-2 Release 0.9         Last change:                   4-2-93

SET(L)                  LOCAL FUNCTIONS                    SET(L)

     will cause the gold element of the wealth property to be set
     to 60. You can nest as deeply as you like.

     You can also set properties to be function names rather than
     values.  This  causes the function to be called whenever the
     property is queried, and have  the  function  determine  the
     value  returned. This is done by setting the property to the
     name of the function with "@@" prepended. Example:

     set ("long", "@@query_long") ;

     will cause the function query_long to be called whenever the
     "long"  property  is  queried.  This is done in the standard
     room, for example, to add a list of the room's current  con-
     tents to the room description.

SEE ALSO
     query(), add(), delete(), /std/object/prop.c

AUTHOR
     Mobydick@TMI-2, based on Buddha's comments in priv.h.

Sun Release 4.1           Last change:                          2

