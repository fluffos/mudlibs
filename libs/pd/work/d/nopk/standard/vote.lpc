#include <locations.h>
#include <locations.h>
#include <locations.h>
#include <locations.h>
// seeker
#include <std.h>
#include <sindarii.h>
#include <voting.h>
#include <security.h>
#include <daemons.h>

inherit ROOM;

mapping votes;
string *voted;

int new_vote();

void create()
{
 ::create();
 set_name("voting room");
 set_short("Casting their vote in the voting room!");
 set_long("You are in the Tirun voting hall. Here you can cast your vote "
          "on the topic that is displayed below. The way voting works is "
          "you can vote on a thing thats already up there, or you can add "
          "your own vote. To find out what the votes that are already up "
          "on the voting board, type <list votes>. To vote for something "
          "thats already up there type <vote [vote number]>. To make your "
          "own vote, type <vote new>.\nTopic: What part of PD needs improvement, or what needs to be added?");
 set_exits( ([ "out" : SQUARE_LOC ]) );
 set_properties( ([ "light" : 2, "night light" : 2, "no attack" : 1,
                    "no magic" : 1, "no bump" : 1 ]) );

votes = ([]);
voted = ({});
seteuid(UID_VOTESAVE);
restore_object(DIR_VOTES + "/improvement");
seteuid(getuid());
}

void init()
{
 ::init();
 if (this_player()->query_level() < 5) 
   {
    write("You need to be at least level 5 to vote!");
    this_player()->move(SQUARE_LOC);
   }
 add_action("fList", "list");
 add_action("fVote", "vote");
}

int fList()
{
 int i;
 string *key;
 write("\nTopic: What part of PD needs improvement, or what needs to be added?");
 i = sizeof(key = keys(votes));
 if (!i) return notify_fail("There are no votes on the board.\n");
 for(i=1; i <= sizeof(key); i++)
  {
   write("["+i+"] "+key[i-1]+"; votes: "+votes[key[i-1]]);
  }
 
 return 1;
}

int fVote(string str)
{
 int i;
 string *key;

if (!str || str == "") return notify_fail("Huh?\n");
if (member_array(this_player()->query_name(), voted ) != -1 )
  return notify_fail("You cannot vote more than once.\n");
if (str == "new")
  {
   new_vote();
   return 1;
  }
 key = keys(votes);
 i = to_int(str);
 if (i > sizeof(votes)||i<=0) return notify_fail("Invalid vote.\n");
 votes[key[i-1]]++;
 write("Vote marked and counted for.");
 voted += ({ this_player()->query_name() });
 seteuid(UID_VOTESAVE);
 save_object(DIR_VOTES + "/improvement");
 seteuid(getuid());

 return 1;
}

int new_vote()
{
 write("What vote do you want to add? [ type it in below ] ");
 input_to("f_newvote");
 return 1;
}

int f_newvote(string str)
{ 
 if (!str || str == "" || sizeof(str) < 4)
  return notify_fail("Make a valid type of vote here, common.\n");
 if (votes[str]) return notify_fail("That already exists!\n");
 votes[str] = 1;
 voted = ({ this_player()->query_name() });
 write("Vote added.");
 seteuid(UID_VOTESAVE);
 save_object(DIR_VOTES + "/improvement");
 seteuid(getuid());
 return 1;
}

mapping query_votes() { return votes; }
