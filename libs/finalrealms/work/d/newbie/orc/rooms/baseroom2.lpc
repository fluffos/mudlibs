inherit "/std/outside";
string * npcs = ({"orcguard","rat","centi","neworc","orcchild","dog"});
#define MAXNPC 4

void my_setup()
{
   add_property("no_undead",1);
   add_clone("/d/newbie/orc/monsters/"+npcs[random(sizeof(npcs))],random(MAXNPC));
}
