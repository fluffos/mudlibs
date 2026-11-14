/* Rewritten by Softbyte  August 1995 */
/* Check aktiv:  QueryInvis, QuerySecrets */
/*       passiv: PROP "DetectSecret"      */
#include <secure/wizlevels.h>
#include <moving.h>
#include <properties.h>
#include <magic.h>
#include <guild.h>
#include <skills.h>
#define TP this_player()

inherit "/obj/scroll";
object last, envi, owner;
int power;
int mystr;  /* in percent , how good we will find secrets */


void SetPower() {
 if (!TP) power = 12;
 else power = TP->QueryAttr("Sta")+6;
 if (power<12) power=12;
 if (power>24) power=24;
 power=power*10; /* 10 minutes for STA=12 */
}

int MyCast(string str)
{
object old;
int tmp;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this "+QuerySpellNoun()+".\n");
    return CAST_FAIL_NOMSG;
  }
  if (present("_xreveal",TP))
  {
    write("The "+QuerySpellNoun()+" is still active.\n");
    return CAST_FAIL_NOMSG;
  }
 SetIds(({"scroll2","_xreveal"}));

  SetPower();
  owner = TP;
  last = owner;
  mystr=4*TP->QueryInt();
  if (mystr<35) mystr=35;
  if (mystr>85) mystr=85;
  SetWeight(0);
  SetShort(0);
  ForbidCast();
  move(this_player(),M_NOCHECK);
  SetNoDrop();
  tmp=TP->QueryAttr(SK_DETECT);
  mystr=TP->ModifyAttr(SK_DETECT,mystr)-tmp; /* because of range check */
  Message("You will now find secrets for some minutes.\n");
  environment(TP)->CheckTrapSecret(TP);
  call_out("find",1);
  return CAST_SUCCESS;
}
remove()
{
  if (owner) owner->ModifyAttr(SK_DETECT,-mystr);
 return ::remove();
}

void find() 
{
object inv;
string name;
mixed *hexi;
mixed t1;
string *sp;
int i;
  power-=1;
  if (!owner) return;
  if (power<=0) 
  {
     TP->Set(SK_DETECT,-mystr);
     tell_object(owner, "The Great Revelation Spell is now powerless.\n");
     remove_call_out("find");
     destruct(this_object());
     return;
  }
  envi=environment(owner);
  if (envi!=last) 
  {
     last=envi;
     t1=envi->QuerySecrets(mystr);
     if (t1)
     {
        if (stringp(t1)) sp=({ t1 });
        else sp=t1;
        for (i=0;i<sizeof(sp);i++)
            tell_object(owner,sp[i]);
     }
     if (envi->QueryHExits()) {
        hexi=envi->QueryHExits();
        for (i=0; i<sizeof(hexi[0]); i++)
            tell_object(owner,
            "There is a secret exit leading "+hexi[i][0]+".\n");
     }
     inv=first_inventory(envi);
     while (inv) 
     {
	 if (!inv->QueryShort() || inv->QueryInvis() )
         {
           if (living(inv))
           {
	      name=capitalize( (inv->QueryName()||"someone") );
	      if (name=="Someone") name=capitalize(inv->QueryRealName());
	      if (!IS_WIZARD(inv)) write("Invisible here: "+name+".\n");
              if (inv->QueryIsNPC()) inv->SetShort(name);
           }
	   else
           {
              if (inv->QueryName())
              { 
                 inv->SetShort(inv->QueryName());
                 write("Invisible item: "+inv->QueryName()+".\n");
              }
              else if (inv->Query(P_INFO))
                 write("Invisible item: "+inv->Query(P_INFO)+".\n");
           }
	}
	inv=next_inventory(inv);
     } /* next while */
  }
  call_out("find",3);
}

int query_power() { return power; }

int MyFail() {
   Message("You find nothing.\n");
   return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("reveal",ST_KNOW,60,#'MyCast,"great revelation",20);
 SetSpellDesc(
"This spell will allow you to find invisible items and secret exits.\n\
How long the spell will last depends on your stamina.\n");
 SetSpellUsage("cast reveal\n");
 SetMemoLevel(GC_SORCERER,13);
 SetMemoLevel(GC_ARCHMAGE,13);
 
 SetFailFn(#'MyFail);

 NoDestruct();
 NoMemorize();
 call_out("SetPower",1);
 mystr=10;
}

