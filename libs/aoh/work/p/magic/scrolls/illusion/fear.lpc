/* Adapted and improved by Softbyte 1995 */
#include <moving.h>
#include <magic.h>
#include <guild.h>
#include <secure/wizlevels.h>
#define TP this_player()

inherit "obj/scroll";

int MyCast(string str) 
{
object wolf;
string name;
int lev;
  if (!str) wolf=GetEnemy(TP);
  else wolf=present(str,environment(TP));
  if (!wolf) { write(capitalize(QueryCastVerb())+" it on whom?\n"); return CAST_FAIL_NOMSG;}
  if (wolf->id("shopkeeper")) {
     write("You can't "+QueryCastVerb()+" it at a shopkeeper.\n"); 
     return CAST_FAIL_NOMSG;
  }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't scare that!\n"); return CAST_FAIL_NOMSG; }
  if (IS_WIZARD(wolf)) {
     write("Nothing can scare an almighty wizard!\n"); return CAST_FAIL_NOMSG;}
  if (Repulse(wolf, TP)) return CAST_REPULSE;
  name=wolf->QueryName()||wolf->QueryShort();
  name=capitalize(name||"someone");
  lev=wolf->QueryLevel()-TP->QueryLevel(); 
  if (lev<1) lev=1;
  if (random(lev)>4)
  {
    Message(name+" looks not very scared by your attempt.\n");
    return CAST_SUCCESS;
  }
  Message(({"You scare "+name+"!\n",
     TP->QueryName()+" scares "+name+".\n",
     ({wolf}), ({TP->QueryName()+" scares you. Your legs "+
	"run away with you.\n"}) }) );
  wolf->GoAway();
  return CAST_SUCCESS;
}

int MyFail() 
{
    Message(({"Suddenly you are afraid of yourself.\n",
      TP->QueryName()+" runs away in panic.\n"}) );
    TP->GoAway();
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("fear",ST_INFLUENCE,30,#'MyCast,"horrible illusion",30);
 SetSpellDesc(
"With this spell you create a horrible illusion.\n"+
 "The monster/player will run out of the room in panic.\n");
 SetSpellUsage("cast fear <opponent>\n");
 SetMemoLevel(GC_CONJURER,4);
 SetMemoLevel(GC_NECROMANCER,4);
 SetMemoLevel(GC_ARCHMAGE,4);
 SetFailFn(#'MyFail);
}

