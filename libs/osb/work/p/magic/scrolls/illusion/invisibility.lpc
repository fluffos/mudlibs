/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) {
  object cloak;
  if (str)
  {
    write("You cannot use an argument with this "+QuerySpellNoun()+".\n");
    return CAST_FAIL_NOMSG;
  }
  if (this_player()->QueryInvis()==1) {
     cloak=present("icloak",this_player());
     if (cloak) cloak->remove();
     this_player()->fvis();
     /* message is in inviscloak */
     return CAST_SUCCESS;
  }
  this_player()->finvis();
  seteuid(getuid(this_object()));
  cloak=clone_object(MAGIC_OBJ_DIR "inviscloak");
  cloak->move(this_player());
  Message( ({"You become invisible.\n",
         this_player()->QueryName()+" makes some magical gestures.\n"}) );
  return CAST_SUCCESS;
}

int MyFail() {
   Message( ({"You turn into a frog!\n",
       this_player()->QueryName()+" turns into a frog.\n"}) );
   this_player()->SetFrog(1);
   return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("invis",ST_CHANGE,65,#'MyCast,"invisibility",40);
 SetSpellDesc(
"This spell make you invisible. If you're invisible you will become\n"+
"visible again. It depends on your stamina how long you stay invisible.\n");
 SetSpellUsage("cast invis\n");
 SetMemoLevel(GC_SORCERER,10);
 SetMemoLevel(GC_ARCHMAGE,10);
 
 SetFailFn(#'MyFail);
}

