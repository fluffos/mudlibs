/*
 * This object was especially made for configuration.
 * inherit this object. 
 * These are the functions available in all guilds:
 * 
 * help		... display help information what can be done in the
 *		    guild room
 * cost 	... show money/exp needed to advance level and/or exp
 * advance 	... arguments:
 *		    - level: (or no argument) advance to next level
 *		    - stats: advance player stats points. argument is a string
 * 		      which may contain the following:
 *		      str dex con int chr wis  !! 920122 remove this Llort
 * list		... arguments:
 *		    - no argument: list number of quests to solve.
 *		    - number: show quest help.
 * join		... join the guild. A player must not belong to another guild,
 *		    only exception is the adventurers guild.
 * spend	... every time a player advances a level, he/she get's a point
 *		    to spend on stats. arguments: str dex con int chr wis
 * points	... shows the number points left to be spent on stats.
 *		    The player must not leave the guild unless all points are
 *		    spent. Check this with the following function:
 * chk_leave	... If the player has points to spend _AND_ is able to spend
 *		    them on stats, this routine returns 0 (the player must not
 *		    leave). If the routine returns 1, allow the player to leave
 *		    You can use "chk_leave" in EXTRA_MOVE, if you are using
 *		    the standard room macros "room/room.h".
 */

#include "tune.h"	
#define NUM_STATS	6

#define SAY(x); tell_room(this_object(),x+"\n");
#define	TP	this_player()
#define TPL	this_player()->query_level()
#define TPN	this_player()->query_name()
#define TPG	this_player()->query_gender()
#define TPT	this_player()->query_title()
#define GM	"guild/master"
#define QR	"room/quest_room"

string ds_stats;		/* Array containing stat description */
int gd;				/* guild number */

reset(arg) { 
  if (arg) return;
  set_light(1);
  ds_stats=explode("Str/Dex/Con/Int/Wis/Chr","/");
}

set_guild(arg) { gd=arg; }
query_guild() { return gd; }

init() {
  add_action("do_help","help");
  add_action("do_cost","cost");
  add_action("do_advance","advance");
  add_action("do_list","list");
  add_action("do_join","join");
/*  add_action("do_spend","spend");
  add_action("do_point","points"); */
}

/* #############     do_help()      ############## */

do_help(str) {
string fname,d1,d2;

  if (!str) return;
  if (sscanf(str,"%s %s",d1,d2)==2) return;	/* more than one word */
  fname="/guild/helpdir/"+str;
  if (file_size(fname)>0) {
     cat(fname);
     return 1;
  }
}

/* #############     do_cost()      ############## */

do_cost() 
{

  if (gd!=TP->query_guild()) 
  {
     write("You don't belong to this guild.\n");
     return 1;
  }
  else if (TPL > 29 && 
           member_array("mentor",explode(TP->query_quests(),"#"))==-1)
  { 
      write("You have to find a Wizard to be your Mentor.\n");
      return 1;
  }
  else if (TPL>=GM->query_levels(gd)) 
  {
     write("You will have to seek other ways.\n");
     return 1;
  }
  else if (TP->query_perc_advance_lev() < 100)
  {
     write("But, you are not ready to advance.\n");
     return 1;
  }
  write("It will cost you nothing to be promoted.\n");
  return 1;
}

/* ##########    do_advance()      ########## */

do_advance() 
{
int max_l, qneeded;
  string pretitle;

  if (gd!=TP->query_guild()) 
  {
     write("You don't belong to this guild, you may not advance here.\n");
     return 1;
  }
  else if (TPL > 29 && 
           member_array("mentor",explode(TP->query_quests(),"#"))==-1)
  { 
      write("You have to find a Wizard to be your Mentor.\n");
      return 1;
  }
  else if (TPL>=GM->query_levels(gd)) 
  {
     write("You will have to seek other ways.\n");
     return 1;
  }
  else if (TP->query_perc_advance_lev() < 100)
  {
     write("But, you are not ready to advance.\n");
     return 1;
  }
    else if(TPL==29){
        qneeded=QR->count(1);
          if(qneeded){
           write("You still have to solve "+qneeded+" compulsary quests.\n");
            return 1;
           }
         }
   TP->set_level(TPL+1);
   if (TP->query_level()>29)
   log_file("/log/PROMOTE", TP->query_name()+" advanced to level 30 on "+ctime(time())+"\n");
      shout("A new immortal was born !\n");
   pretitle=GM->query_pretitle(gd,TPL,TPG);
   if (!pretitle) pretitle="none";
   TP->set_pretitle(pretitle);
   TP->set_title(GM->query_title(gd,TPL,TPG));
   say(TPN+" is now level "+TPL+".\n");
}

/* #############      do_list()       ############## */

do_list(str) {
int i;
  if(str=="all") {
    QR->list_all(0);
    return 1;
  }
  if(str=="long") {
    QR->list_all(1);
    return 1;
  }
  if ((str) && sscanf(str,"%d",i)==1) QR->list(i);
  else QR->count();
  return 1;

}

/* ##############     do_join()     ############ */

do_join() {

  /* Note: this routine is not the complete join routine. It only checks
     that the player belongs to the adv.guild, and returns 1 if yes.
     If the player belongs to another guild, it returns 0. Use this like:

     if (::do_join()) {
	(* Your own join code *)
     }
  */
  if (!gd) {
     write("You can't join the adventurers guild !\n");
     return 0;
  }
  if (TP->query_real_name()=="guest") { /* Moonchild */
     write("Guest cannot join guilds !\n");
     return 0;
  }
  if (TP->query_level()>10 && TP->query_guild() && TP->query_guild()!=gd) {
     write("You already belong to another guild !\n");
     return 0;
  }
  else if (TP->query_guild()==gd) {
     write("But you are already a member here.\n");
     return 0;
  }
  return 1;
}

/* ############    do_spend      ############### */

do_spend(str) {
int i,s;

  if (gd!=TP->query_guild()) {
      write("You have to spend your points at your own guild.\n");
      return 1;
  }
  if (!TP->query_spend_points()) {
      write("No points left to spend.\n");
      return 1;
  }

  i=calc_statx(str); 
  if (i<0) return;
  s=TP->query_stats(i);
  if (s>=GM->query_levels(gd)) {
     alas(i);
     return 1;
  }
  if (s-3>=TPL) {
     write("You are too low level to spend a point on this one.\n");
     return 1;
  }
  TP->set_stats(i,s+1);
  TP->add_spend_points(-1);
  write("Ok.\n");
  return 1;
}

/* ############    do_point      ############### */

do_point() {
int i;

  if (TP->query_guild()!=gd) {
     write("You don't belong to this guild.\n");
     return 1;
  }
  if (i=TP->query_spend_points()) 
      write("You have "+i+" points left to spend.\n");
  else write("No points left.\n");
  return 1;
}

/* ############################################## */ 

query_drop_castle() { return 1; } /* No castles allowed */

chk_leave() {
int i,mlvl,r;

  if (TP->query_guild()!=gd) return;
  r=0;
  mlvl=GM->query_levels(gd);
  if (TP->query_spend_points())
     for (i=0;i<NUM_STATS;i++)
	 if (TP->query_stats(i)<mlvl) {
	    r=1;
	    break;
	 }
  if (!TP->query_immortal() && r) {
     write("You have points to spend.\n");
     return 1;
  }
}

calc_statx(str) {
int i;

  i=0;
  switch (str) {
  case "chr" : i++;
  case "wis" : i++;
  case "int" : i++;
  case "con" : i++;
  case "dex" : i++;
  case "str" : i++;
  }
  i--;
  return i;
}

alas(i) {
string alas_str;

  alas_str=explode("strong and powerfull/skilled and vigorous/"
		 + "tough and endurable/knowledgeable and wise/"
		 + "wise and salomonic/charismatic and heroic","/");

  write("Sorry, "+gnd_prn()+", but you are already as "+alas_str[i]+"\nas any");
  if (TPG==2) write("thing ");
  else write("one ");
  write("could possibly hope to get.\n");
  return 1;
}

too_high_average() {
int i,sum;

  sum=0;
  for (i=0;i<NUM_STATS;i++) sum+=TP->query_stats(i);
  sum/=NUM_STATS;
  if (sum>=TPL+3) {
     write("Sorry, "+gnd_prn()+", but you are not of high enough level.\n");
     return 1;
  }
  return 0;
} 

gnd_prn() {
  switch(TPG) {
  case 0 : return "best creature";
  case 1 : return "sir";
  case 2 : return "madam";
  }
}

raise_cost(base,action) {
int cost,saldo;
 
  if (base>=GM->query_levels(gd)) return 0; /* max.stats reached */
  cost = (GM->query_exp(gd,base+1) - GM->query_exp(gd,base))/STAT_COST;
  saldo = (TP->query_exp()-GM->query_exp(gd,TP->query_level()));
  if (!action) return cost;
  if (saldo<cost) return 0;	/* don't move below current level */
  TP->add_exp(-cost);
  return cost;

}

