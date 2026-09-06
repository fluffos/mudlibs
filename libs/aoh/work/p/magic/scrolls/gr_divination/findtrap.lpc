/* Rewritten  by Softbyte August 1995 */
/* Check aktiv:  QueryTraps          */
/*       passiv: PROP "DetectTrap"   */
#include <magic.h>
#include <guild.h>
#include <moving.h>
#include <skills.h>
inherit "/obj/scroll";
#define TP this_player()

int mystr;  /* in percent , how good we will find traps */
object owner;

int MyCast(string str) 
{
int tmp;
  if (str)
  {
   if (str!=TP->QueryName())
      write("You cannot use an argument with this "+QuerySpellNoun()+".\n");
    return CAST_FAIL_NOMSG;
  }
  if (present("_xtrap",TP))
  {
    write("The "+QuerySpellNoun()+" is still active.\n");
    return CAST_FAIL_NOMSG;
  }
  SetIds(({"find_trap","_xtrap"}));

  mystr=4*TP->QueryInt();
  if (mystr<35) mystr=35;
  if (mystr>85) mystr=85;
  Message("You will now find traps better.\n");
  SetWeight(0);
  ForbidCast();
  SetShort(0);
  move(this_player(),M_NOCHECK);
  SetNoDrop();
  tmp=TP->QueryAttr(SK_DETECT);
  mystr=TP->ModifyAttr(SK_DETECT,mystr)-tmp; /* because of range check */
  environment(TP)->CheckTrapSecret(TP);   /* init handling in this room */
  owner=TP;
  call_out("exfind",8*mystr);
  return CAST_SUCCESS;
}

remove()
{
  if (owner) owner->ModifyAttr(SK_DETECT,-mystr);
 return ::remove();
}
void exfind() 
{
  if (!owner) return;
  owner->ModifyAttr(SK_DETECT,-mystr);
  tell_object(owner,"Your ability to detect traps fades away.\n");
  remove_call_out("exfind");
  remove();
  if (this_object()) destruct(this_object());
  return;
}


int MyFail() {
    Message("There seems to be a trap right under your feeds.\n");
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("find",ST_KNOW,10,#'MyCast,"find trap",10);
 SetSpellDesc(
"This scroll will allow you to find traps for some minutes.\n");
 SetSpellUsage("cast find\n");
 SetMemoLevel(GC_SORCERER,16);
 SetMemoLevel(GC_ARCHMAGE,16);
 SetFailFn(#'MyFail);

 NoMemorize();
 NoDestruct();
 mystr=10;
}

