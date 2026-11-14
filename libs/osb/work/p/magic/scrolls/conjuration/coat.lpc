/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int GiveShield(object mon) {
  object shield;
  if (!living(mon) || !mon->QueryIsPlayer()) return 0;
  if (present("coat of armour",mon)) return 0;
  seteuid(getuid(this_object()));
  shield = clone_object(MAGIC_OBJ_DIR "kymars");
  shield->move(mon);
  tell_object(mon, "A polished shield appears in your hands.\n");
  shield->wear(mon);
return 1;
}

MyCast(str)
{
mixed *mps;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  mps=filter(all_inventory(environment(this_player())),"GiveShield");
  if (!mps || !sizeof(mps)) 
  {
    Message("Everybody has already a polished shield.\n");
    return CAST_FAIL_NOMSG;
  }
  return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("coat",ST_CREATE,200,#'MyCast,"Kymar's Coat of Armour",45);
 SetSpellDesc(
"This spell creates a polished shield for every player in a room.\n");
 SetSpellUsage("cast coat\n");
 ForbidCast("all");
 SetCastLevel(GC_ARCHMAGE,1);
 SetMemoLevel(GC_ARCHMAGE,16);
}

