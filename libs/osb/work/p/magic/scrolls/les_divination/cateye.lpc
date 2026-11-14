/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str)
{
object wolf;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  /* Message in eyes */
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_OBJ_DIR "cateyes");
  wolf->AktivateEyes(this_player()->QueryAttr("Sta")*200,this_player());
  return CAST_SUCCESS;
}

int MyFail() 
{
object wolf;
  seteuid(getuid(this_object()));
  wolf=clone_object("/d/woodland/common/obj/rose");
  wolf->move(this_player());
  Message( ({"A flower appears in your hand.\n",
      "A flower appears in "+this_player()->QueryName()+"'s hand.\n"}) );
  return CAST_SUCCESS;
}
create()
 {
 ::create();
 AddSpell("cateyes",ST_LIGHT,10,#'MyCast,"cat eyes",40);
 SetSpellDesc("This spell will make your eyes see in the dark.\n");
 SetSpellUsage("cast cateyes\n");
 SetMemoLevel("allmage",15);
 SetFailFn(#'MyFail);
}

