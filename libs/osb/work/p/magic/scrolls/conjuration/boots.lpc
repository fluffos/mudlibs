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
  Message( ({"You materialize some boots.\n",
     this_player()->QueryName()+" materializes some boots out of thin air.\n"}) );
  seteuid(getuid(this_object()));
  cloak=clone_object(MAGIC_OBJ_DIR "wizboots");
  cloak->move(this_player());
  this_player()->command_me("wear boots");
  return CAST_SUCCESS;
}

int MyFail() 
{
   Message(({"A pair of boots appears, looks at you and runs away in panic.\n",
       "A pair of boots appears, looks at "+this_player()->QueryName()+
   "and runs away in panic.\n"}) );
   return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("wizboots",ST_CREATE,40,#'MyCast,"wizard's boots",25);
 SetSpellDesc(
"This spell create some boots for you which can also take you back to\n"+
"your guild.\n"+
"Type 'guild' to go to your guild. This will only work if you have no\n"+
"enemies and are not hunted.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast wizboots\n");
 SetMemoLevel(GC_CONJURER,4);
 SetMemoLevel(GC_ARCHMAGE,4);
 SetFailFn(#'MyFail);

 NoMemorize();
}

