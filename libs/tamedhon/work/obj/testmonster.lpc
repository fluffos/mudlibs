inherit "std/npc";
#include <properties.h>
#include <language.h>

int warte;

void say_str(string str);
 
void create()
{
  if (!clonep(this_object())) return;
  ::create();
  SetProp(P_NAME, "Testmonster");
  SetProp(P_GENDER, NEUTER);
  SetProp(P_SHORT, "Das Testmonster - nervtoetend -");
  SetProp(P_ALIGN, 100);
  SetProp(P_LONG, 
  "Dies ist Testie, das Testmonster. Es hatte alle möglichen, übel aussehenden\n"+
  "Testgeräte dabei. Leg Dich lieber nicht mit ihm an ...\n");
  AddId("monster");
  AddId("testmonster");
  AddId("testie");
  SetProp(P_RACE, "tester");
  SetProp(P_LEVEL, 19);
  SetProp(P_MAX_HP, 275);
  SetProp(P_HP, 275);
  SetProp(P_XP, 0);
  SetProp(P_HANDS, ({" mit einem Spannungsprüfer", 5}) );
  SetProp(P_AC, 1);
  seteuid(getuid(this_object()));
  AddSpell(1,5,"Ein Testmonster schlägt Dir ein Testheft um die Ohren.\n",
               "Ein Testmonster schlägt @WEN mit einem Testheft.\n");
  AddSpell(1,8,"Ein Testmonster testet Deine Reaktion auf Hitze.\n",
               "Ein Testmonster hält ein Feuerzeug unter @WESSEN Hintern.\n");
  AddSpell(1,11,"Ein Testmonster testet Deine Reaktion auf elektrischen Strom.\n",
                "Ein Testmonster verpasst @WEM einen Elektroschock.\n");
  AddSpell(1,15,"Ein Testmonster testet Deine Säurebeständigkeit.\n",
                "Ein Testmonster überschüttet @WEN mit konzentrierter Säure.\n");
  AddSpell(1,10,"Ein Testmonster nimmt eine Blutprobe von Dir.\n",
                "Ein Testmonster sticht @WEN mit einer gigantischen Nadel.\n");
  SetProp(P_SPELLRATE,50);
  warte=10;
}

void give_notify(object obj)
{
  write("Danke für "+obj->name(WEN, 1)+".\n");
  return;
}

void catch_tell(string str)
{
  mixed s1, s2;

  if (!str || str=="") return;
  if (sscanf(str,"%s tritt%sTestmonster",s1,s2))
  {
    say_str(capitalize(name())+" sagt: Aua, wieso trittst Du mich, "+s1+"?\n");
    return;
  }
  if (sscanf(str,"%s sagt: %s",s1,s2))
  {
    if (!s2) s2=" ";
    s2=explode(s2,"\n");
    if (sizeof(s2))
      s2=implode(s2," ");
    else
      return;
    say_str(capitalize(name())+" sagt: Wieso sagst Du \""+s2+"\", "+s1+"? \n");
    return;
  }
}

void say_str(string str)
{
  call_out("do_say",0,str);
}

void do_say(string str)
{
  say(str);
}

void heart_beat()
{
  ::heart_beat();
  warte--;
  if (warte) return;
  warte=8;
  Flee();
}
