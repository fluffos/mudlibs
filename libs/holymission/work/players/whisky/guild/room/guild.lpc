

/* guildroom */

#define        NUM_STATS	6
#define	TP	   this_player()
#define  TPL	this_player()->query_level()
#define  TPN	this_player()->query_name()
#define  TPG	this_player()->query_gender()
#define  TPT	this_player()->query_title()
#define  GM	   "guild/master"
#define  QR	   "room/quest_room"

inherit "/room/room";
#include "tune.h"	

string *ds_stats;		
int gd;				/* guild number */

void reset(int flag) 
{ 
  if (flag == 0) 
  {
    set_light(1);
    ds_stats=explode("Str/Dex/Con/Int/Wis/Chr","/");
  }
}

void set_guild(int n) 
{ 
    gd=n; 
}

int query_guild() 
{ 
     return gd; 
}

void init() 
{
  add_action("do_help","help");
  add_action("do_help","about");
  add_action("do_toplist","tolpist");
  add_action("do_cost","cost");
  add_action("do_advance","advance");
  add_action("do_list","list");
  add_action("do_join","join");
  ::init();
}

/* helpdir */

int do_help(string arg) 
{
  if (!arg)
       arg = "guild";

  if (file_size("/guild/helpdir/"+arg) > 0 ) 
     cat("/guild/helpdir/"+arg);
     return 1;
}


/* costs to advance : not buyable */

int do_cost() 
{
 int qexp, last, next;

  last = GM->query_exp(gd,TPL);
  next = GM->query_exp(gd,(TPL + 1));

  qexp = ((100 * (QR->query_total_weight() + 
          TP->query_quest_points())) / QR->query_total_weight()) - 100;
   /* between 1 and 100 */

  if (gd!=TP->query_guild()) 
  {
     notify_fail("You don't belong to this guild.\n");
     return 1;
  }
  else if (TPL>= GM->query_levels(gd)) 
  {
     notify_fail("You will have to seek other ways.\n");
     return 0;
  }
  else if (TP->query_exp() < next)
  {
     notify_fail(
     "You still need "+to_string((next-last))+" experience to advance.\n");
     return 0;
  }
  else if (TPL == 29 && qexp < QUEST_PERCENT_FOR_WIZ) 
  {
      notify_fail("You still need to solve more quests to become a Wizard.\n");
      return 0;
  }
  else if ( qexp < (TPL * TPL / 12) && TPL > 4) 
  {
	write("You can't advance, you must seek more knowledge, find it "+
	      "solving quests.\n");
	return 0;
  }
  write("It will cost you nothing to be promoted.\n");
  return 1;
}

int do_advance(string arg) 
{
 int qexp;
 string pretitle, msg;
 int  last, next;

  last = GM->query_exp(gd,TPL);
  next = GM->query_exp(gd,(TPL + 1));

  qexp = ((100 * (QR->query_total_weight() + 
          TP->query_quest_points())) / QR->query_total_weight()) - 100;

  if (gd!=TP->query_guild()) 
  {
     notify_fail("You don't belong to this guild.\n");
     return 1;
  }
  else if (TPL>= GM->query_levels(gd)) 
  {
     notify_fail("You will have to seek other ways.\n");
     return 0;
  }
  /* own code depending on quests for an autoloading shadow */
  else if (TP->no_advance())
  {
       if (stringp(msg = TP->no_advance()))
           write(msg);
       return 1;
  }
  else if (TP->query_exp() < next)
  {
     notify_fail(
     "You still need "+to_string((next-last))+" experience to advance.\n");
     return 0;
  }
  else if (TPL == 29) 
  {
     if (qexp < QUEST_PERCENT_FOR_WIZ)
     {
      notify_fail("You still need to solve more quests to become a Wizard.\n");
      return 0;
     }
     else if (QR->count(1) > 0)
     {
        notify_fail("You still haven't done "+to_string(QR->count(1))+" of "+
                    "the compulsory quests.\n");
        return 0;
     }
  }
  else if (TPL >= (GM->query_levels(gd)-1) && !TP->query_quest("ask_god")) 
  {
     notify_fail("You have to find an Archwizard to sponsor you.\n");
     return 0;
  }
  else if ( qexp < (TPL * TPL / 12) && TPL > 4) 
  {
	write("You can't advance, you must seek more knowledge, find it "+
	      "solving quests.\n");
	return 0;
  }
  
     TP->set_level(TPL+1);

     pretitle=GM->query_pretitle(gd,TPL,TPG);

     if (!stringp(pretitle)) 
          pretitle="none";
     TP->set_pretitle(pretitle);

     TP->set_title(GM->query_title(gd,TPL,TPG));

     if (stringp(TPT) && TPL < GM->query_levels(gd)) 
       	write("You are now "+TPN+" "+TPT+" (level "+TPL+").\n");
     else if (TPL < GM->query_levels(gd))
       	write("You are now "+TPN+" (level "+TPL+").\n");
     else 
     {
	     write("You are now Appretice Wizard !\n");
	     shout("A new wizard has been born !\n");
	     log_file("PROMOTE",
		  TP->query_real_name() + " advanced to level 30 on " +
		  ctime(time()) + ".\n");
     }
     return 1;
  }


/* questlisting */
int do_list(string arg) 
{
  int i;
  if(!stringp(arg) || arg=="all") 
    QR->list_all(0);
  else if(arg=="long") 
    QR->list_all(1);
  else if ((arg) && sscanf(arg,"%d",i)==1) 
    QR->list(i);
  else 
    QR->count();
  return 1;
}

/* joining the guild */
int do_join() 
{
  if (!gd) 
  {
     notify_fail("You can't join the adventurers guild !\n");
     return 0;
  }
  else if (TP->query_real_name()=="guest") 
  {
     notify_fail("Sorry, but you have to become a real player to join !\n");
     return 0;
  }
  else if (TP->query_level()>10 && TP->query_guild() && TP->query_guild()!=gd) 
  {
     notify_fail("You already belong to another guild !\n");
     return 0;
  }
  else if (TP->query_guild()==gd) {
     write("But you are already a member here.\n");
     return 0;
  }
  return 1;
}


int query_drop_castle() 
{ 
    return 1; 
} 

