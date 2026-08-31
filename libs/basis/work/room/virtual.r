// simple example of a room using rdl (room description language)
// this rdl is meant as more of an example of a virtual language than
// anything else (although it might grow more useful as i muck with it)
// --Truilkan@TMI 5/92

// lines beginning with // are comments

// short description

short: virtual room

// long description

long:
This room is virtually real.  It is an example of how the MudOS virtual
object facility may be used to create a virtual language/compiler.  The
description for this room is stored in /room/virtual.r (type 'people'
to see what room the driver thinks you are in).  The room description
language compiler is in /adm/obj/virtual/r.c.  The template object for
this room is stored in /obj/templates/room.c.  The interface to the
virtual object facility is provided via the compile_object() function
in the master object.  The virtual object facility was conceived of and
added to MudOS by Whiplash (Jeremy Radlow).  Mudlib support was added by
Truilkan (me).  This room should contain a dictionary (book).  This object
is an example of how the socket efunctions may be used.  You can try out the
dictionary by typing 'open book' and 'define something'.  Be sure to
dest or close the book when finished to avoid wasting file descriptors.
**

// light level of the room

light: 1

// exits out of the room.  first word is the name of the exit.  second word
// is the name of the exit we will arrive from.  third word is pathname of
// the room the exit leads to.

exit: east west /room/start

// these objects are cloned into the room.  at reset time, a check
// is made to replace the object if it is missing.  the first word
// after "object:" is the name the object id's to.  the second word
// is the filename of the object.

object: bag /obj/webster
object: terminal /obj/terminal
