/*

  Although I dont know if these will be actually stats, just
  put em for now to see how they look in the setup

  Last changes:
  [Unknown]   Creation
  [Softbyte]  18mar1998 :   Small output changes

*/

#include <properties.h>
#include <daemons.h>
#include <msgclass.h>
#include <money.h>

#define TP this_player()
#define CAP(x)  capitalize( (x)||"" )
#define SLIB "/lib/string"
inherit MONEY_LIB;

string GetColour(int amount,int max)
{
  int percent;
  if (amount<0 || max<1) return "";

  percent=100*amount/max;

  if (percent>90) return "%^BOLD%^%^GREEN%^";
  else if (percent>66) return "%^GREEN%^";
  else if (percent>33) return "%^BOLD%^%^ORANGE%^";
  else return "%^BOLD%^%^RED%^";
}

public int main( string arg )
{
  string msg;
  string short;
  string hpcol,spcol,mepcol,pepcol,rescol;
  int j, k, l, m, reminvis;
  seteuid(getuid());

  j = ({int})EXPLOREMASTER->CountBits(({string})TP->QueryExplored());
  k = (j*100)/({int})EXPLOREMASTER->TotalEP();

  l = ({int})BANK_D->QueryAccount(getuid(TP));
  if (l<0){ l=0; } /* Just so the account doesn't show '-1' in bank */

  m = QuerySomeonesValue(TP);


  if (({int})this_player()->QueryGhost())
  {
    msg_write(CMSG_GENERIC,
    "You can't use the command score right now.  Perhaps you're\n"+
      "dead or something.  Please try again later.  Thank you.\n");
    return 1;
  }

  hpcol=GetColour(({int})TP->QueryHP(),({int})TP->QueryMaxHP());
  spcol=GetColour(({int})TP->QuerySP(),({int})TP->QueryMaxSP());
  pepcol=GetColour(({int})TP->QueryPEP(),({int})TP->QueryMaxPEP());
  mepcol=GetColour(({int})TP->QueryMEP(),({int})TP->QueryMaxMEP());
  rescol="%^RESET%^";

  if ( query_verb() == "sc" )
  {
    msg=
    sprintf(
      "You have %s%d/%d%s HP %s%d/%d%s SP"
      " %s%d/%d%s PEP %s%d/%d%s MEP and %d"
      " XP as well as %d coins.\n",
      hpcol,({int})TP->QueryHP(),({int})TP->QueryMaxHP(),rescol,
      spcol,({int})TP->QuerySP(),({int})TP->QueryMaxSP(),rescol,
      pepcol,({int})TP->QueryPEP(),({int})TP->QueryMaxPEP(),rescol,
      mepcol,({int})TP->QueryMEP(),({int})TP->QueryMaxMEP(),rescol,
    ({int})TP->QueryXP(),m);
    msg_write(CMSG_GENERIC,msg);
    seteuid(0);
    return  1;
  }

  if((({string})this_player()->QueryGuild()) == 0) {this_player()->SetGuild("None");}

  reminvis = ({int})TP->QueryInvis(); TP->SetInvis(0);

  short = ({string})TP->Short();
  TP->SetInvis(reminvis);
  if (reminvis) short = (short || "")+" (invisible)";
/* nice confusing invis sequence eh? */

  msg="";
  msg+=({string})SLIB->cadjust(" "+({string})TP->QueryShort()+"'s score ",75,"-=")+"\n";
  msg += sprintf(
  "Title: %s %s\n"
  "Level: %d\n\n"
  "Str:  %3.3d      Money: %-10.10d  Race:   %-15.15s \n"
  "Con:  %3.3d      Bank:  %-10.10d  Guild:  %-15.15s \n"
  "Int:  %3.3d      Known: %-3.3d%%        Gender: %-4.6s\n"
  "Wis:  %3.3d      XP:    %-10.10d  \n"
  "Agi:  %3.3d                       \n"
  "Qui:  %3.3d      Wimpy: %-3.3d         Load:   %-1.8d stones \n"
  "Cha:  %3.3d      Mails: %-3.3d         Age:    %-20.20s\n"
  "\n"
  "HP:  %s%-3.3d/%3.3d%s   Spec:              Food:    %-16.16s\n"
  "SP:  %s%-3.3d/%3.3d%s   Aim:               Water:   %-16.16s\n"
  "PEP: %s%-3.3d/%3.3d%s                      Alcohol: %-16.16s\n"
  "MEP: %s%-3.3d/%3.3d%s                      \n"
  ,

  ({string})TP->QueryShort(), ({string})TP->QueryTitle(),
  ({int})TP->QueryLevel(),
  ({int})TP->QueryStr(), m, CAP(({string})TP->QueryRace()),
  ({int})TP->QueryCon(), l, ({string})TP->QueryGuild(),
  ({int})TP->QueryInt(), k, CAP(({string})TP->QueryGenderString()),
  ({int})TP->QueryWis(), ({int})TP->QueryXP(),
  ({int})TP->QueryAgi(),
  ({int})TP->QueryQui(), ({int})TP->QueryWimpy(),   ({int})TP->QueryWeightContent()/10,
  ({int})TP->QueryCha(), ({int})MAILDEMON->FingerMail(getuid(TP)),({string})TP->AgeString(),
  hpcol,({int})TP->QueryHP(), ({int})TP->QueryMaxHP(),rescol, ({string})TP->QueryFoodMsg(),
  spcol,({int})TP->QuerySP(), ({int})TP->QueryMaxSP(),rescol, ({string})TP->QueryDrinkMsg(),
  pepcol,({int})TP->QueryPEP(),({int})TP->QueryMaxPEP(),rescol,({string})TP->QueryAlcoholMsg(),
  mepcol,({int})TP->QueryMEP(),({int})TP->QueryMaxMEP(),rescol
  );

  msg+=({string})SLIB->mkstr(75,"-=")+"\n";
  msg_write( CMSG_GENERIC,msg);
  seteuid(0);
  return 1;
}
