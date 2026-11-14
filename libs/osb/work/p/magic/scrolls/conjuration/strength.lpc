/*
** Scroll: giant strength
** Descr.: This spell will create some gauntlets which increase the strength
** Author: Joern@Nightfall
** Update: Thragor@Nightfall, 09jun95
**         Softbyte@Nightfall, 30jul95
*/

#include <magic.h>
#include <guild.h>
#include <moving.h>
#include "/d/woodland/sys/woodland.h"

// #define TP this_player()
#define P_GAUNTLETS "Gauntlets"

inherit "/obj/scroll";

int MyCast(string str)
{
  mixed *bon;
  object wolf;

  if (!TP) return CAST_FAIL_NOMSG;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  if (TP->Query(P_GAUNTLETS))
  {
      write("You can't cast that spell twice!\n");
      return CAST_FAIL_NOMSG;
  }
  Message( ({"You materialize some gauntlets.\n",
     this_player()->QueryName()+" materializes some gauntlets out of thin air.\n"}) );
  seteuid(getuid());
  wolf=clone_object(MAGIC_OBJ_DIR "gauntlets");
  wolf->move(TP,M_SILENT);
  TP->Set(P_GAUNTLETS,wolf);
  write("Now you'll have to wear the gauntlets!\n");
  return CAST_SUCCESS;
}

int MyFail()
{
object wolf;
  seteuid(getuid(this_object()));
  wolf=clone_object(OBJ("rose"));
  wolf->move(this_player());
  Message(({"A flower appears in your hand.\n",
      "A flower appears in "+add_gen(TP->QueryName())+" hand.\n"}) );
  return CAST_SUCCESS;
}

create()
{
  (::create());
  AddSpell("strength",ST_CREATE,75,#'MyCast,"giant strength",70);
  SetSpellDesc(
"This spell will create some gauntlets of giant power for you.\n"+
"Wearing these gauntlets will increase your strength.\n");
  SetSpellUsage("cast strength\n");
 SetMemoLevel(GC_CONJURER,16);
 SetMemoLevel(GC_ARCHMAGE,16);
 
  SetFailFn(#'MyFail);

  NoMemorize();
}
