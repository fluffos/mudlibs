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
  Message( ({"You conjure some food.\n",
     this_player()->QueryName()+" conjures some food.\n"}) );
  seteuid(getuid(this_object()));
  switch(random(3))
  {
    case 0: cloak=clone_object(MAGIC_OBJ_DIR "knob");
    break;
    default: cloak=clone_object(MAGIC_OBJ_DIR "food");
    break;
  }
  cloak->move(this_player());
  return CAST_SUCCESS;
}

int MyFail() 
{
    Message( ({"It starts to rain dead mice.\n",
        "It starts to rain dead mice.\n"}) );
    this_player()->SetSmell(this_player()->QueryName()+
                   " smells as if he slept in a cellar full of dead mice.\n");
    return CAST_SUCCESS;
}
create()
 {
 ::create();
 AddSpell("create",ST_CREATE,42,#'MyCast,"create food",25);
 SetSpellDesc(
"This spell creates some food for you.\n"+
"The food will be worthless, but very tasty.\n");
 SetSpellUsage("cast create\n");
 SetMemoLevel(GC_CONJURER,9);
 SetMemoLevel(GC_ARCHMAGE,9);
 SetFailFn(#'MyFail);

 NoMemorize();
}

