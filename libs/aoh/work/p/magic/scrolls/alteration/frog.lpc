/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <secure/wizlevels.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object wolf;
int ali;
string hname;
  if (!str) 
  {
    write("Who should be frogged?\n");
    return CAST_FAIL_NOMSG;
  }
  wolf=present(str,environment(this_player()));
  if (!wolf) {write("That's not here.\n"); return CAST_FAIL_NOMSG; }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }
  if (IS_WIZARD(wolf)) { write("Don't you dare!\n"); return CAST_FAIL_NOMSG; }
  if (Repulse(wolf, this_player())) return CAST_REPULSE;
  if ((wolf->QueryFrog()==0) && (wolf->QueryIsPlayer()) && wolf!=this_player())
    LogCast(this_player(),wolf);
  hname=wolf->QueryName();
  if (wolf->QueryFrog())
  {
     Message( ({ hname+" is no longer a frog.\n",
                 hname+" is no longer a frog.\n",
                 ({wolf}), ({"You are no longer a frog.\n"}) }) );
     wolf->SetFrog(0);
  }
  else
  {
     Message( ({ hname+" is now a frog.\n",
                 hname+" is now a frog.\n",
                 ({wolf}), ({"Quaak.\n"}) }) );
     wolf->SetFrog(1);
  }
  return CAST_SUCCESS;
}

int MyFail() {
  if (Repulse(this_player(), this_player())) return CAST_REPULSE;
     Message(({"You turn into a frog.\n",
          this_player()->QueryName()+" says: Quaak!\n"}) );
     this_player()->SetFrog(1);
     return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("frog",ST_CHANGE,40,#'MyCast,"frog curse",40);
 SetSpellDesc(
"This spell will turn someone into a frog or remove a frog curse\n"+
"if that one is a frog.\n");
 SetSpellUsage("cast frog <target>\n");
 SetMemoLevel("allmage",13);
 SetFailFn(#'MyFail);

 NoMemorize();
}

