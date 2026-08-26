#include <mudlib.h>

inherit OBJECT;

void describe() ;

void create() {
  seteuid(getuid());
  set("value", 150) ;
  set("short", "a disembodied head");
  set("long", "A disembodied head.");
  set("mass", 7) ;
  set("bulk", 2) ;
  set("smell", "It smells like rotting flesh.\n");
  set("author", "chronos");
  set("id", ({ "head", "disembodied head" }) );
  describe() ;
}

void describe() {
  string str;
  switch(random(10)+1) {
    case 1: str=@ENDDESC
The disembodied head of a little girl.  Part of the spine is still
attached and her eyes look at you, hauntingly.
ENDDESC
 ;     break ;
    case 2: str=@ENDDESC
The disembodied head of an old man.  The skin clings to his face tightly,
drawing the mouth into a permanent sneer.
ENDDESC
 ;     break ;
    case 3: str=@ENDDESC
The disembodied head of a little boy.  The eyelids are half-closed, and
the eyes themselves are rolled back into his skull.
ENDDESC
   ;   break ;
    case 4: str=@ENDDESC
The disembodied head of a large bearded man.  Blood is caked throughout
his beard and eyes are beginning to dry up and rot.
ENDDESC
  ;    break ;
    case 5: str=@ENDDESC
The disembodied head of a fat woman.  The face is all bloated and pale,
barely recognizable as human.
ENDDESC
 ;     break ;
    case 6: str=@ENDDESC
The disembodied head of a fair elf maiden.  Her face is frozen in a
permanent scream, heard by no one.
ENDDESC
;      break ;
    case 7: str=@ENDDESC
The disembodied head of a stout dwarf.  His face is calm and serene,
as if death as an old friend he had been waiting to meet.
ENDDESC
 ;     break ;
    case 8: str=@ENDDESC
The disembodied head of a strange race you do not recognize.  The
features are barely discernable, as it is badly mutilated and scarred.
ENDDESC
;      break ;
    case 9: str=@ENDDESC
The disembodied head of a frail old woman.  Her mouth is curled into
a coy little smile and her eyes are closed.
ENDDESC
;      break ;
    default:str=@ENDDESC
The disembodied head of a teenage girl.  Once pretty, this head is a
wretched sight.  Whatever killed her was not gentle.
ENDDESC
;      break ;
  }
  set("long", str) ;
  return ;
}
