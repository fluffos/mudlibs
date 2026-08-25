inherit "/std/outside";
string * npcs = ({"frog","rat","gnoll","merchant","frog","dog"});
#define MAXNPC 4

mapping my_setup()
{
   add_property("no_undead",1);
   add_clone("/d/newbie/lizard/npcs/"+npcs[random(sizeof(npcs))],random(MAXNPC));
}
void dummy() { } /* leave this here, taniwha */
