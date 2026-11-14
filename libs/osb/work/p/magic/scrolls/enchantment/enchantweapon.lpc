/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#define CURSER "/d/woodland/joern/masters/curser"
inherit "/obj/scroll";

int MyCast(string str) 
{
object weap;
string a, b, name;
   if (!str) 
   {
     write("Bless what ?\n");
     return CAST_FAIL_NOMSG;
   }
   weap=present(str, this_player());
   if (!weap) { write("You don't have that!\n"); return CAST_FAIL_NOMSG; }
   if (weap->QueryWC()<1) {
      write("That 'weapon' can't be blessed!\n"); 
      return CAST_FAIL_NOMSG;
   }
   name=weap->QueryShort();
   if (sscanf(name,"%sblesse%s",a,b)==2 || weap->Query("blessed") )
   {
      write("It's already blessed!\n");
      return CAST_FAIL_NOMSG;
   }
   if (sscanf(name,"%scurse%s",a,b)==2 || weap->Query("cursed") ) 
   {
      write("A cursed weapon cannot be blessed.\n");
      return CAST_FAIL_NOMSG;
   }
   if (weap->QueryWC()<4) weap->SetWC(weap->QueryWC()+1);
   else weap->SetWC(to_int(weap->QueryWC()*1.3));
   Message( ({"You have blessed "+weap->QueryShort()+".\n",
       this_player()->QueryName()+" has blessed a weapon.\n"}) );
   weap->AddAdjective("blessed");
   weap->SetShort(weap->QueryShort()+" (blessed)");
   weap->Set("blessed",1);
   
   return CAST_SUCCESS;
}

int MyFail()
{
object *obj;
int i;
string a,b;
   if (Repulse(this_player(), this_player())) return CAST_REPULSE;
   Message( ({"Your weapons start to burn!\n",
       add_gen(this_player()->QueryName())+" weapons start to burn!\n"}));
   seteuid(getuid(this_object()));
   obj=all_inventory(this_player())||({});
   for (i=0;i<sizeof(obj);i++)
   {
     if ( obj[i]->QueryWC()>1 &&
        2!=sscanf(obj[i]->QueryShort(),"%sblesse%s",a,b) &&
        2!=sscanf(obj[i]->QueryShort(),"%scurse%s",a,b)&&
        !obj[i]->Query("blessed") &&
        !obj[i]->Query("cursed") )
     {
        CURSER->CurseWeapon(obj[i],obj[i]->QueryWC()/2);
        Message(capitalize(obj[i]->QueryShort())+" is cursed.\n");
        obj[i]->SetShort(obj[i]->QueryShort()+" (cursed)");
        return CAST_SUCCESS;
     }
   } 
   return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("wbless",ST_CHANGE,40,#'MyCast,"bless weapon",15);
 SetSpellDesc("This spell will increase the WC of a weapon.\n");
 SetSpellUsage("cast wbless <weapon>\n");
 SetMemoLevel(GC_SORCERER,10);
 SetMemoLevel(GC_ARCHMAGE,10);
 SetFailFn(#'MyFail);
}

