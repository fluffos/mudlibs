/*     This is a demo ball for OSB
*
*      It shows the use of the throwing skill in OSB
*
*   (c) Softbyte@OSB 11nov97
*
*
*/


#include <properties.h>
#include <moving.h>
#include <skills.h>
#include <math.h>
#include <msgclass.h>

#define TP this_player()
#define TO this_object()
#define SQUEEZE_TIME 900 

inherit "/std/thing";

// This function creates the messages when the ball if thrown from
// 'from' to 'to'
// This function is only needed if you want to extend the standard
// throwing messages and is specified via P_SK_THROW_MSG
void throw_msg(object from,object to,string id, int modus)
{
int dist;
  dist=call_other(L_DISTANCE,"dist",environment(from),environment(to));
  msg_object(from,CMSG_GENERIC,
  "You throw the red ball to "+to->QueryName()+". After tiring "+dist+
  "m it arrives there.\n");
  if (to!=from)
    msg_object(to,CMSG_GENERIC,
    capitalize(from->QueryName())+" throws a small red ball to you. "+
    dist+"m later it arrives in your hands.\n");
  msg_room(environment(to),CMSG_GENERIC,
  "A small red ball is thrown to "+to->QueryName()+".\n",({to,from}));
  if (environment(to)!=environment(from))
    msg_room(environment(from),CMSG_GENERIC,
    "A small red ball is thrown away from "+from->QueryName()+".\n",({to,from}));
}

// This function is called when the ball breaks due a skill fail 
// The chance of a break is specified with P_SK_BREAK_CHANCE (0..1000)
// and this function is specified via P_SK_BREAK_FUN
// The person who threw the ball is 'from'
void throw_break(string id,object from)
{
object ob;
  msg_room(environment(from),CMSG_GENERIC,
  "The crystal ball breaks into dozends of pieces.\n");
  seteuid(getuid());
  ob=clone_object("/std/thing");
  ob->SetShort("some red glass pieces");
  ob->SetLong("These are some pieces of red glass.\n");
  ob->AddId("pieces");
  ob->AddId("glass");
  ob->AddAdjective("red");
  ob->AddAdjective("some");
  ob->AddAdjective("glass");
  ob->SetValue(0);
  ob->move(environment(this_object()),M_SILENT);
  remove();
}

create()
{
  ::create();

  Set(P_SHORT,"a small red ball");
  Set(P_LONG,
  "This is a small red crystal ball which can be thrown around. You can use:\n"
  " - throw ball east : Throw to the room east of you\n"
  " - throw ball to softbyte: throw the ball to softbyte if he is less than\n"
  "                           50m afar\n"
  " - throw ball at orc: Hit the orc with the ball doing up to 5 HP damage\n"
  "\n");
  AddId("ball");
  AddAdjective("small");
  AddAdjective("crystal");
  AddAdjective("red");
  Set(P_WEIGHT,50);
  Set(P_SMELL,"The ball smells like plastic.\n"); 
  Set(P_NOISE,"The ball squeaks.\n"); 

  // Add the possibilty to throw this ball. How difficult it is to
  // throw the ball is determined by the 250 (1:extremely easy, 1000:
  // extermly hard). The array with 'ball' etc are the keywords which
  // you can throw [might later on be combined with the Ids/Ads
  // The last argument, the big mapping, is fully optional, i.e. you
  // can omit it. Here you can specify some additional properties for
  // the skills as shown above. You can use 0,1 or all of them
  AddSkill(SK_THROW,0,250,({"ball","small ball","crystal ball"}),
       ([
      P_SK_THROW_MSG:#'throw_msg, // we want an individual message when
                                  // the ball is thrown. They are provided
                                  // by this function
      P_SK_THROW_DISTANCE:50,     // we can throw at most 50m
                                  // use -1 for infinite distances
                                  // use 0(default) this room only
      P_SK_THROW_HITHP:5,         // 5 HP damage when hitting an enemy
                                  // This can also be a function returning
                                  // the damage, ie.e
                                  // int throw_dam(string id,object from,
                                  //               object to)
      P_SK_THROW_BREAK_CHANCE:500,// 50% chance to break on fail
      P_SK_THROW_BREAK_FUN:#'throw_break,// the crystal ball is breaked
                                  // in this function
      ]) );
}

