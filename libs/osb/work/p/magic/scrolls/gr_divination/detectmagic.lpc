/* Adapted and improved by Softbyte 1995 */
#include <moving.h>
#include <magic.h>
#include <guild.h>
#include <secure/wizlevels.h>
#include <properties.h>

inherit "/obj/scroll";

int MyCast(string str) 
{
object *inv;
int i;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  inv = deep_inventory(this_player());
  for (i=0; i<sizeof(inv); i++) 
  {
    if (!inv[i]->QueryShort()) continue;  /* invis item */
    if (inv[i]->Query(P_MAGIC) ) 
         write(capitalize(inv[i]->QueryShort())+" glows red.\n");
    if (inv[i]->Query("cursed") ) 
         write(capitalize(inv[i]->QueryShort())+" appear to be black.\n");
    if (inv[i]->Query("blessed") ) 
         write(capitalize(inv[i]->QueryShort())+" appear to be yellow.\n");
    if (inv[i]->QueryInfo() )
         write(capitalize(inv[i]->QueryShort())+" glows blue.\n");
  }
  return CAST_SUCCESS;
}

int MyFail() {
    Message("Suddenly you detect that you're not magical.\n");
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("magic",ST_KNOW,30,#'MyCast,"detect magic item",50);
 SetSpellDesc(
"If you cast this, all magical items you carry will glow red and\n\
all those which can be identified will glow blue. Cursed items will appear\n\
black and blessed items yellow.\n");
 SetSpellUsage("cast magic\n");
 SetMemoLevel("allmage",14);
 SetFailFn(#'MyFail);
}

