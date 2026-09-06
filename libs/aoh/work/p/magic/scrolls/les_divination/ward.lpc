/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object wolf;
int ac;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  wolf=present("familiar",this_player());
  if (!wolf) wolf=present("mascot",this_player());
  if (!wolf) wolf=present("familiar", environment(this_player()));
  if (!wolf) wolf=present("mascot",environment(this_player()));
  if (!wolf) wolf=present("fellow",this_player());
  if (!wolf) { write("I can't see any familiar.\n"); return CAST_FAIL_NOMSG; }
  Message(({capitalize(wolf->QueryName())+" looks a bit different now.\n",
      add_gen(this_player()->QueryName())+" familiar looks different now.\n"}) );
  ac = this_player()->QueryLevel() / 2;
  if (ac < 4) ac = 4;
  if (ac<wolf->QueryAC()) ac=wolf->QueryAC();
  wolf->SetAC(ac);
  return CAST_SUCCESS;
}

int MyFail() {
    Message(({"Your familiar farts!\n",
        add_gen(this_player()->QueryName())+" familiar farts noisily.\n"}) );
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("ward",ST_CHANGE,90,#'MyCast,"ward familiar",22);
 SetSpellDesc(
"This spell will increase the armour class of your familiar or mascot.\n"+
"How much the armour class is increased depends on your level.\n");
 SetSpellUsage("cast ward\n");
 SetMemoLevel("allmage",2);
 SetFailFn(#'MyFail);
}

