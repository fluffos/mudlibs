// A small voting box to allow wizard voting

#include <properties.h>

inherit "/obj/votingbox";

#define DURATION 14*24*3600

int endtime;

public void LoadTime();

varargs void create()
{
  ::create();
  SetSavefile("/log/wizvote");
  LoadTime();
  SetEndTime(endtime||time());

  SetShort("a small wooden voting box");
  SetLong(
  "With this voting box wizards can decide.\n");
  AddAdjective("small");
  AddAdjective("wooden");
  AddSubDetail(({"ingraving","ingravings"}),
   "This is your OSB voting box.");
  AddSubReadMsg(({"ingraving","ingravings"}),
   "You read: Please put in your vote here.");
}


public int AddTopic(string topic,string title,string desc)
{
  if (!::AddTopic(topic,title,desc)) return 0;
  AddAlternative(topic,"Don't know");
  AddAlternative(topic,"No");
  AddAlternative(topic,"Yes");
  endtime=SetEndTime(time()+DURATION);
  write("Endtime set to "+endtime+"\n");
//  SaveBox();
  return 1;
}

public void LoadTime()
{
  string f;
  f = QuerySavefile();
  if (!f || file_size(f+".o")<0) return;
  seteuid(getuid());
  restore_object(f);
  seteuid(0);
}

