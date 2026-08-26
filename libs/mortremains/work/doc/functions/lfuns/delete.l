
DELETE(L)               LOCAL FUNCTIONS                 DELETE(L)

NAME
     delete - used to delete a property in an object.

SYNPOSIS
     void delete (string prop) ;

DESCRIPTION
     The delete lfun is is defined in the standard object. It  to
     delete a property from an object's data. Example:

     set ("short", "An exciting object") ; delete ("short") ;

     The delete statement would get rid of the "short"  property,
     so that the effect of the two statements is nil.

     The delete lfun can be used with the  /  divider  to  remove
     elements of mapping properties. Example:

     set ("wealth" : ([ "gold" : 10, "silver" : 20 ]) ) ;  delete
     ("wealth/gold") ;

     would result in the wealth property having a single element,
     silver, with a value equal to 20.

SEE ALSO
     set(), query(), add(), /std/object/prop.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

