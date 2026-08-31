

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/house1 */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"
#ifndef WAYS
#define WAYS ({})
#endif
#ifndef LONG_DESC
#define LONG_DESC ""
#endif
#ifndef SPEC_DESC
#define SPEC_DESC ""
#endif

void reset(int arg) 
{

if (!arg);
{
 clone_list=({1,1,"man",PATH+"monsters/hman",0,
             2,1,"woman",PATH+"monsters/hwoman",0,
             3,2,"child",PATH+"monsters/hchild",0});

set_light(1);
short_desc="A house in town";

long_desc=
    "This is a typical house in this town. " +
    "It isn't large but you don't miss anything. There is a kitchener, " +
    "a few chairs, a table, a cupboard and a bed for the parents.\n" + SPEC_DESC;
  
items=({
    "kitchen","It is an old kitchen, but it is enough to cook",
    "chairs","Simple wooden chairs",
    "table","A simple wooden table",
    "cupboard","The only cupboard in the house. All those people own is in it",
});

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
  
dest_dir=WAYS;
  }

::reset(arg);
replace_program("room/room");
}
