
/*     
      The equipment command
	  Shows your worn armour and wielded weapons
      1997 Softbyte
      
*/

#include <properties.h>
#include <combat.h>
#include <daemons.h>
#include <msgclass.h>
#define TP this_player()

int is_atype(object armour,mixed type)
{
  if (!armour) return 0;
  if (!({string})armour->QueryShort() || ({int})armour->Query(P_INVIS)) return 0;
  if (type!=({mixed})armour->QueryArmourType()) return 0;
  return 1;
}
string getArmour(object *a,mixed type)
{
  string s;
  int i;
  a=filter(a||({}),#'is_atype /*'*/,type);
  if (!a || !sizeof(a)) return "None";

  s="";
  for (i=0;i<sizeof(a);i++)
  {
    s+=({string})a[i]->QueryShort();
	if (i<sizeof(a)-1) s+=", ";
  }
  return s;
}

public int main( string arg )
{
  string msg,s;
  object *weapons,*armours;
  int i,flag;

  weapons=({object *})TP->QueryWeapons()||({});
  armours=({object *})TP->QueryArmours()||({});

  flag=0;

  s="";  
  for (i=0;i<sizeof(weapons);i++)
  {
    if (({string})weapons[i]->QueryShort()&&!({int})weapons[i]->Query(P_INVIS))
	{
	  s+=({string})weapons[i]->QueryShort()+", ";
	  flag++;
    }
  }
  if (s[<2..<1] == ", ") s=s[0..<3];  // dirty bugfix 
  msg="\nWielded weapon"+(flag>1?"s":"")+": ";
  if (flag>0) msg+=s+"\n";
  else msg+="None\n";

  msg+="\n";

  msg+="Worn armour:   Head:  "+getArmour(armours,AT_HELMET)+"\n";
  msg+="               Body:  "+getArmour(armours,AT_MAIL)+"\n";
  msg+="         Light Body:  "+getArmour(armours,AT_CLOAK)+"\n";
  msg+="              Hands:  "+getArmour(armours,AT_GLOVES)+"\n";
  msg+="               Legs:  "+getArmour(armours,AT_TROUSERS)+"\n";
  msg+="               Feet:  "+getArmour(armours,AT_BOOTS)+"\n\n";
  msg+="             Shield:  "+getArmour(armours,AT_SHIELD)+"\n";
  msg+="               Ring:  "+getArmour(armours,AT_RING)+"\n";
  msg+="             Amulet:  "+getArmour(armours,AT_AMULET)+"\n";

  msg+="\n";

  msg_write(CMSG_GENERIC,msg);
  return 1;
}


