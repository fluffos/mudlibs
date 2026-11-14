/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object cloak;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  Message( ({"You conjure a ring of healing.\n",
     this_player()->QueryName()+" materializes a ring out of thin air.\n"}) );
  seteuid(getuid(this_object()));
  cloak=clone_object(MAGIC_OBJ_DIR "healring");
  call_other(cloak,"move",this_player());
  this_player()->command_me("wear ring");
  return CAST_SUCCESS;
}

int MyFail() {
  object cloak;
  Message(({"Something brown that smells awful appears in your hands.\n",
      "A piece of shit appears in "+add_gen(this_player()->QueryName())+
      " hands.\n"}));
  seteuid(getuid(this_object()));
  cloak=clone_object("/d/woodland/common/obj/shit1");
  cloak->move(this_player());
  this_player()->SetSmell(this_player()->QueryName()+
       " smells of shit.\n");
  return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("healring",ST_CREATE,70,#'MyCast,"ring of healing",20);
 SetSpellDesc(
"This spell creates a ring of healing for you.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast healring\n");
 SetMemoLevel(GC_CONJURER,7);
 SetMemoLevel(GC_ARCHMAGE,7);
 
 SetFailFn(#'MyFail);

 NoMemorize();
}

