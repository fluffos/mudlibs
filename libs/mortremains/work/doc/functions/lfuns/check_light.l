
CHECK_LIGHT(L)          LOCAL FUNCTIONS            CHECK_LIGHT(L)

NAME
     check_light - Determine if an object is a light source.

SYNOPSIS
     int check_light() ;

DESCRIPTION
     The check_light() lfun is defined in the standard object. It
     determines  whether  the object is acting as a light source.
     It determines this in  the  following  way.  First,  if  the
     object  has  its  "light" property to be set greater than 1,
     then the object is a light source.  Second,  if  the  object
     does  not  have any contents, then it is not a light source.
     Third, if the object is opaque,  then  it  is  not  a  light
     source.  Fourth,  if the object is not emitting light itself
     but has contents and is not opaque,  then  check_light()  is
     called  in all of its contents to see if any of its contents
     are emitting light, and if so then the original object is  a
     light  source.   The  function  returns 1 if the object is a
     light source and 0 if the object is not a light source.  The
     recursive  call is used because it makes it possible to han-
     dle opacity of containers in a fairly natural way, and  also
     because    it   typically   executes   faster   than   using
     deep_inventory().  Note that this lfun  behaves  differently
     than  the  equivalent  efun did in LP 3.0. In 3.0, the light
     values of all objects, which could be negative, were  summed
     and  an  object was lit if the sum was greater than zero. In
     this version, there is no anti-light, and so a room  is  lit
     if  any of its contents are light sources. This is also fas-
     ter because it means that we can stop checking as soon as we
     hit the first lit object in the list.

SEE ALSO
     /std/object/ob_logic.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

