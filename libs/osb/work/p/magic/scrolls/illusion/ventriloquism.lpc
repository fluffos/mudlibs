/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";
string text;

void Laber(object mon) {
  string name;
  if (mon && living(mon) && mon->QueryIsNPC() && !mon->QueryChats()) {
     name = mon->QueryName();
     if (name) name = capitalize(name);
     mon->InitChats(5,({ name+" says: "+text+"\n" }));
  }
}

int MyCast(string str) {
  if (!str) text = "Hi There!";
  else text = str;
  filter(all_inventory(environment(this_player())),"Laber");
  return CAST_SUCCESS;
}

create() 
{
 ::create();
 AddSpell("ventriloquism",ST_INFLUENCE,50,#'MyCast,"ventriloquism",25);
 SetSpellDesc(
"This spell will cause all none-players in a room to say something again and\n\
again.\n");
 SetSpellUsage("cast ventriloquism <text>\n");
 SetMemoLevel(GC_ARCHMAGE,2);
}

