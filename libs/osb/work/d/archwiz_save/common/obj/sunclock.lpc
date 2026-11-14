/* a sunclock
**
** (C) Loco
*/

#include <properties.h>
#include <nightday.h>
#include <config.h>
#include "path.h"

inherit "/std/thing";

#define NUM2STR ({"one","two","three","four","five","six",\
		    "seven","eight","nine","ten","eleven","twelve"})

create() {
  (::create());
  seteuid(getuid());
  SetShort("a sun dial");
  AddId(({"clock","sunclock","clock", "dial", "sundial"}));
  AddAdjective("sun");
  Set(P_NOGET,1);
}

int GetGameTime() {
  int daylen,i;
  mixed states;
  daylen=0;
  states=NIGHTDAY->QueryStates();
  for (i=NIGHTDAY->QueryState();i>0;--i) daylen+=states[i][0];
  daylen+=states[0][0]/2;
  daylen-=NIGHTDAY->TimeLeft();  
  if (daylen<0) daylen+=DAY_LENGTH;
  return (daylen*86400)/DAY_LENGTH;
}

QueryLong() {
  string s;
  int t;

  t=GetGameTime();
  if (NIGHTDAY->QueryState()<ND_SUNRISE || NIGHTDAY->QueryState()>ND_PREFALL)
    return "A sunclock, but it is too dark to get a time from it.\n";
  return "A sunclock. The time it shows is:\n"+time2str(t)+".\n";
}

time2str(int t) {
  string s;
  s="";
  switch ((t+1350)%3600/900) {
  case 0: s+="about a quarter to";
    break;
  case 1:s+="around";
    break;
  case 2:s+="about a quarter past";
    break;
  case 3:s+="around half past";
    break;
  }
  s+=" "+NUM2STR[((t-2250)/3600)%12]+" o'clock "+
    ((t+1350)%86400<43200 ? "am" : "pm");
  return s;
}


