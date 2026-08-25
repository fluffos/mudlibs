inherit "/std/room";
string * npcs = ({"orcguard","rat","orcchild","dog"});
#define MAXNPC 3

void my_setup()
{
   add_property("no_undead",1);
   add_clone("/d/newbie/orc/monsters/"+npcs[random(sizeof(npcs))],random(MAXNPC));
}
