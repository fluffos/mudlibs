/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) {
  object wolf;
  int hp, max, health;
  if (!str) 
  { 
    write("Whose health do you want to know?\n");
    return CAST_FAIL_NOMSG;
  }
  wolf=present(str,environment(this_player()));
  if (!wolf) { write("That's not here.\n");  return CAST_FAIL_NOMSG; }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }
  max=wolf->QueryMaxHP();
  hp=wolf->QueryHP();
  health=(hp*100)/max;
  Message(add_gen((wolf->QueryName()||"Its"))+" health is "+health+"%.\n");
  return CAST_SUCCESS;
}

int MyFail() {
    Message("The health is "+random(100)+"%.\n");
    return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("health",ST_KNOW,20,#'MyCast,"know health",25);
 SetSpellDesc("This spell will show you the health of someone.\n");
 SetSpellUsage("cast health <target>\n");
 SetMemoLevel("allmage",6);
 SetFailFn(#'MyFail);

 NoMemorize();
}

