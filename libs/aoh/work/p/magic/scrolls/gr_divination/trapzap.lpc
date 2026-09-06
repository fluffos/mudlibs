/* Adapted and improved by Softbyte 1995 */
#include <properties.h>
#include <magic.h>
#include <guild.h>
inherit "obj/scroll";

MyCast(str) 
{
  object ch;
  if (!str) str="chest";
  ch=present(str,environment(this_player()));
  if (!ch) ch=present(str,this_player());
  if (!ch) ch=environment(this_player()); /* room */
  if (0==ch->Zap(this_player(),str))
    Message( ({"Fizzle...\n","Fizzle...\n"}) );
  else 
    Message( ({"You disarmed the trap.\n",
           this_player()->QueryName()+" disarmed a trap.\n"}) );
  return CAST_SUCCESS;
}

MyFail() {
   if (Repulse(this_player(),this_player(),ST_POISON) ) return CAST_REPULSE;
   this_player()->AddPoison(20);
   Message(({"Ooops, you are poisoned.\n","Poof.\n"}) );
   return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("tzap",ST_CHANGE,120,#'MyCast,"trap zap",70);
 SetSpellDesc(
"This spell will disarm traps. You can cast it either on chests\n"+
"or other objects or at a room trap by giving its name.\n");
 SetSpellUsage("cast tzap <trap>\n");
 SetMemoLevel("allmage",5);
 SetFailFn("MyFail");
}

