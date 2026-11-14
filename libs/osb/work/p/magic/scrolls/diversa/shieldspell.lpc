/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int GiveShield(object mon) {
  object shield;
  if (!living(mon) || !mon->QueryIsPlayer()) return 0;
  if (present("mystic_shield",mon)) return 0;

  seteuid(getuid(this_object()));
  shield=clone_object(MAGIC_OBJ_DIR "mystics");
  shield->move(mon);
  tell_object(mon, "A mystic shield appears in your hands.\n");
  shield->wear(mon);
  return 1;
}

int MyCast(string str)
{
mixed *mps;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  mps=filter(all_inventory(environment(this_player())),"GiveShield");
  if (!mps || !sizeof(mps) )
  {
    Message("Everybody has already a shield.\n");
    return CAST_FAIL_NOMSG;
  } 
  return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("shield",ST_CREATE,50,#'MyCast,"mystic shield",10);
 SetSpellDesc(
"This spell creates a mystic shield for every player around you.\n");
 SetSpellUsage("cast shield\n");
 ForbidMemo("all");
 NoSell();
 NoMemorize();
}

