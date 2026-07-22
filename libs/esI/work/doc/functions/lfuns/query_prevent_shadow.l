
QUERY_PREVENT_SHADOW(L) LOCAL FUNCTIONS   QUERY_PREVENT_SHADOW(L)

NAME
     query_prevent_shadow() - prevent assigning a shadow  to  the
     given object.

SYNOPSIS
     int query_prevent_shadow (object ob) ;

DESCRIPTION
     The query_prevent_shadow() lfun may be optionally defined in
     any  file  in the mudlib. The function valid_shadow() in the
     master object tries to call query_prevent_shadow in the sha-
     dowed  object  any time shadow is attempted: if the function
     returns 1 the shadow is denied, but if the function  returns
     0,  the  shadow succeeds. You can use the object argument to
     make the success of the shadow conditional on the  shadowing
     object - this is done in the body objects, for one example.

SEE ALSO
     valid_shadow()

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

