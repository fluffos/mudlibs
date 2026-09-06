/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
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
   if (!weap) {
      write("You don't have that!\n");
      return CAST_FAIL_NOMSG;
   }
   if (weap->QueryAC()<1) {
      write("That 'armour' can't be blessed!\n");
      return CAST_FAIL_NOMSG;
   }
   if (weap->QueryArmourType()!=AT_MAIL) {
      write("You can't bless that.\n");
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
      write("You cannot bless curesed armour!\n");
      return CAST_FAIL_NOMSG;
   }
   if (weap->QueryAC()<5) weap->SetAC(weap->QueryAC()+1);
   else weap->SetAC(to_int(weap->QueryAC()*1.2));
   Message( ({"You have blessed "+weap->QueryShort()+".\n",
      this_player()->QueryName()+" has blessed some armour.\n"}) );
   weap->SetShort(weap->QueryShort()+" (blessed)");
   weap->AddAdjective("blessed");
   weap->Set("blessed",1);
   return CAST_SUCCESS;
}

int MyFail() 
{
object *obj;
int i;
string a,b;
   if (Repulse(this_player(), this_player())) return CAST_REPULSE;
   Message( ({"Your armour start to burn!\n",
        add_gen(this_player()->QueryName())+" armour start to burn!\n"}));
   seteuid(getuid(this_object())); 
   obj=all_inventory(this_player())||({});
   for (i=0;i<sizeof(obj);i++)
   {
      if ( obj[i]->QueryAC()>=1 &&
        2!=sscanf(obj[i]->QueryShort(),"%sblesse%s",a,b) &&
        2!=sscanf(obj[i]->QueryShort(),"%scurse%s",a,b) &&
        !obj[i]->Query("cursed") &&
        !obj[i]->Query("blessed") )
      {
         CURSER->CurseArmour(obj[i],obj[i]->QueryAC()-1);
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
 AddSpell("barmour",ST_CHANGE,50,#'MyCast,"bless armour",20);
 SetSpellDesc(
"This spell will increase the AC of an armour of type armour.\n");
 SetSpellUsage("cast barmour <armour>\n");
 SetMemoLevel(GC_SORCERER,11);
 SetMemoLevel(GC_ARCHMAGE,11);
 SetFailFn(#'MyFail);
}

