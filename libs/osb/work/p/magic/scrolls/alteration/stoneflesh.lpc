/* Adapted and improved by Softbyte 1995 */
/* doomcave quest spell */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";
#define TP this_player()

int MyCast(string str) 
{
object mon, stone;
  if (!str) { write("Wrong usage.\n");  return CAST_FAIL_NOMSG; }
  if (str=="Mina" || str=="mina" || str=="statue") 
  {
     write("The magic starts working, but you have still got to SPEAK the following words:\n");
     write("'Flesh should be what flesh once was!'\n");
     return CAST_SUCCESS;
  }
  mon=present(str,environment(TP));
  if (!mon) { write(capitalize(QueryCastVerb())+" it on whom?\n"); return CAST_FAIL_NOMSG;}
  stone=present("stonecloak",mon);
  if (!stone)
  {
     write(capitalize(mon->QueryName()||"it")+" is not petrified.\n");
     return CAST_FAIL_NOMSG; 
  }
  tell_room(environment(TP),
  "The stone around "+mon->QueryName()+ " breaks away.\n"+
  mon->QueryName()+" recovers conciousness and begins to move slowly.\n",
   ({mon}));
  /* message to mon in stonecloak */
  if (stone) call_other(stone,"away","stone");
  return CAST_SUCCESS;
}

int MyFail() 
{
    Message(({"Hmmm. Nothing happens.\n",
              "Nothing happens.\n"}) );
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("flesh",ST_HEAL,50,#'MyCast,"stone to flesh",10);
 SetSpellDesc(
"This spell will turn a player back into flesh if he/she/it had been\n"+
"turned into stone.\n");
 SetSpellUsage("cast flesh <player>\n");
 SetMemoLevel("allmage",2);
 SetFailFn(#'MyFail);

 NoSell();
}

