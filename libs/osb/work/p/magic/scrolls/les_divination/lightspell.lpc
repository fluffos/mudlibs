/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";
#define TP this_player()


int MyCast(string str) {
  object wolf;
  int level;
  if (str)
  {
    write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  Message( ({
"You wave your right hand without even concentrating on the spell and\n"+
"fetch a stick out of nowhere. With an air of self-confidence you wave\n"+
"your left hand... 'Hmm... I'm good at this' you think to yourself.\n",
TP->QueryName()+" waves "+TP->QueryPossessive()+" hands in "+
  "the air and a buring stick appears.\n" }) );
  level= (int) TP->QueryRealLevel();
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_OBJ_DIR "light");
  wolf->move(TP);
  wolf->SetFuelAmount(random(level)+10);
  wolf->SetWeight(1);
  wolf->SetValue(0);
  TP->command_me("light stick");
  return CAST_SUCCESS;
}

int MyFail()
{
object wolf;
  Message( ({
"You wave your right hand without even concentrating on the spell and\n"+
"fetch a stick out of nowhere. With an air of self-confidence you wave\n"+
"your left hand...your left hand starts to burn...  'Oops! wrong gesture!'\n"+
"You take a look around just to make sure that nobody noticed that you\n"+
"failed to cast even this simple spell.\n",
TP->QueryName()+" waves "+TP->QueryPossessive()+" hands in "+
  "the air...but nothing happens.\n" }) );
/*   seteuid(getuid(this_object()));
//  wolf=clone_object("/d/shadows/common/guilds/eye");
  wolf->move(TP);
  TP->command_me("wear eyes"); commented out cause eyes dont exist [t] */
  return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("light",ST_LIGHT,5,#'MyCast,"light source",15);
 SetSpellDesc(
"This spell will allow you to summon a light-source.\n"+
 "The higher your level, the longer the magic stick will burn.\n");
 SetSpellUsage("cast light\n");
 SetMemoLevel("allmage",1);
 SetFailFn(#'MyFail);
}

