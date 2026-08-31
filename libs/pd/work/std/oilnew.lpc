// new inheritable for oils

#include <std.h>
#include <locations.h>

inherit OBJECT;

string MyUseMsg, TheirUseMsg, MyHealMsg, TheirHealMsg, UseAction;
int OilUses, OilStrength;

string expandos(string);

void set_my_mess(string);
void set_their_mess(string);
void set_my_heal_mess(string);
void set_their_heal_mess(string);
void set_action(string);
void set_uses(int);
void set_strength(int);

string query_my_mess();
string query_their_mess();
string query_my_heal_mess();
string query_their_heal_mess();
string query_action();
int query_uses();
int query_strength();

void create() {
  ::create();
  MyUseMsg = "You rub the oil on your bleeding wounds.";
  TheirUseMsg = "$N rubs healing oil on $P wounds.";
  MyHealMsg = "The oil goes through your wounds and heals them.";
  UseAction = "rub";
  OilUses = 1;
  OilStrength = 4;
}
// Originally by Seeker
// Changed to inheritable by Nightshade 
#include <std.h>
#include <locations.h>

inherit OBJECT;

string _YourRubMessage, _TColor, _TFirst, _TLast, _HealMessage, _Action;
string _FColor, _FFirst, _FLast;
int Uses, Heals;
int _OilStrength;

void set_uses(int i);

void create()
{
 ::create();
 _TColor = "";
 _FColor = "";
 _OilStrength = 50;
 set_uses(1);
}

int set_id(string *str) {
  str += ({"oilcheck"});
  return ::set_id(str);
}

void set_strength(int s) { _OilStrength = s; }
int query_strength() { return _OilStrength; }

void set_uses(int i) {
  if(i < 1)
    Uses = 1;
  else
    Uses = i;
  Heals = Uses;
}

string query_short() {
  string str;

  str = ::query_short();
  str += " %^RESET%^(";
  str += cardinal(Uses);
  if(Uses == 1)
    str += " use left)";
  else
    str += " uses left)";
  return str;
}

void init()
{
 ::init();
 add_action("fApply", _Action);
}

void set_your_mess(string str) { _YourRubMessage = str; }

varargs void set_their_mess(string str1, string str2, string str3) {
  _TColor = str1;
  _TFirst = str2;
  _TLast = str3;
}

void set_their_heal(string str1, string str2) {
  _FColor = str1;
  _FFirst = str2;
}

void set_heal_mess(string str) { _HealMessage = str; }

void set_action(string str) { _Action = str; }

int fApply(string str)
{
  if (!str || str == "" || present(str, this_player()) != this_object())
    return notify_fail(capitalize(_Action)+" what?");

 if (this_player()->query_paralyzed())
   return notify_fail(this_player()->query_paralyze_message());

 if (this_player()->query_disable() || this_player()->query_magic_round() || this_player()->query_casting())
   {
    write("You are too busy doing something else.");
    return 1;
   }
 this_player()->set_disable();
 write(_YourRubMessage);
 if(_TLast && _TLast != "")
   say(_TColor+this_player()->query_cap_name()+_TFirst+this_player()->query_title_gender()+_TLast);
 else
   say(_TColor+this_player()->query_cap_name()+_TFirst);
 call_out("do_oil", 6, this_player() );
 Uses--;
 if(Uses == 0)
   this_object()->move(TEMP_LOC);
 return 1;
}

int do_oil(object ob)
{
  if (!ob) return 0;
 ob->add_hp(60+ query_strength() + random(4*query_strength()) );
 ob->add_sp(query_strength()/4 + random(query_strength()/3) );
 foreach (string l in ob->query_limbs())
   ob->heal_limb(l, query_strength()/7 + random(query_strength()/5) );
 if(_FFirst)
   say( _FColor+this_player()->query_cap_name()+_FFirst);
 message("info", _HealMessage, ob);
 Heals--;
 if(Heals <= 0)
   this_object()->remove();
 return 1;
}
