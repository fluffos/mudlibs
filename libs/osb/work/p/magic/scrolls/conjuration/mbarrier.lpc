/* Adapted and improved by Softbyte 1995 */
/* I guess this does not work properly with abbr. commands 'n','s'm... */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
  object barrier;
  Message( ({"You create a magic field to the "+str+".\n",
  this_player()->QueryName()+" creates a magic field to the "+str+".\n"}) );
  seteuid(getuid(this_object()));
  barrier=clone_object(MAGIC_OBJ_DIR "barrier");
  barrier->move(environment(this_player()));
  barrier->block(str);
  return CAST_SUCCESS;
}

int MyFail() 
{
    Message(({"It starts to rain stones.\n",
        "It starts to rain stones.\n"}) );
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("barrier",ST_DARK,50,#'MyCast,"magic barrier",25);
 SetSpellDesc(
"This spell will create a barrier which blocks the exit in a room\n\
in one direction.\n\
You will be able to pass, but others won't.\n");
 SetSpellUsage("cast barrier <direction> direction: north, south, ...\n");
 SetMemoLevel(GC_CONJURER,7);
 SetMemoLevel(GC_ARCHMAGE,7);
 
 SetFailFn(#'MyFail);

 NoMemorize();
}

