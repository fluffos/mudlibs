#include <living.h>
#include <properties.h>
#include <msgclass.h>

inherit "/std/npc";

#define TO this_object()
#define TP this_player()

// User defined function as an answer to some questions
// It will called when the player typed the corresponding sentence
// Arguments: object who:       the player that did the question
//            string sequence:  the talk sequence (e.g. "abac") the player
//                              did enter
// varargs void kill_it(object who,string talk_sequence)
varargs void kill_it(object who)
{
  msg_room(environment(TO),CMSG_SAY,
    TO->QueryName()+" says: YOU insult me? DIE "+who->QueryName()+
    "!\n",({TO}));
  Kill(who);
}

varargs void create()
{
  ::create();

// An example talking NPC
  SetRace("orc");
  SetName("Bitty");
  SetGender(GENDER_MALE);
  SetShort("Bitty the Orc");
  SetLong("This is Bitty the Orc.\n"
	  "You can 'talk with' him.\n");


  /* Adds a talk to this NPC..The player will be asked the following menu
     where '!' means the end of the talk and *1), *2), *3), *4) are jumps
     to other branches of the tree, e.g.
        *1) proceeds with (AA,AB,AC)
        *2) proceeds with (AAA,AAB,AAC)
        *3) proceeds with (AAAA)
        *4) proceeds with (AACAA,AACAB)

                                           talk with orc
                                               |
                           A-------------------B-----------C
                           |                   |           !
             AA------------AB------AC       BA----BB      kill
             |             |       !        !     !
       AAA--AAB------AAC   *2)    kill      *1)  kill
        |    |        |
      AAAA  *3)   AACA-------AACB--AACC
        !          |          |     !
               AACAA--AACAB   *4)
                 !      !


  */
  AddTalk("A","Heya @@QueryName@@!","How are you today?");
    AddTalk("AA","How are you myself, my friend?","I am fine, thank you.");
      AddTalk("AAA","How is the weather today?","Quite good actually.");
        AddTalk("AAAA","So anything else my friend?","Not that I'd know of.\n");
      AddTalk("AAB","How is your family?","Not bad, not bad.","AAA");
      AddTalk("AAC","How is the king?","Sigh, he caught a severe flu.");
        AddTalk("AACA","Too bad to hear.","Indeed!\n");
          AddTalk("AACAA","I better hurry there.","You better do. C'ya.\n");
          AddTalk("AACAB","Shall I go there?","You better run. Bye.\n");
        AddTalk("AACB","This poor guy.","Indeed!\n","AACA");
        AddTalk("AACC","Can I help him?","Go to his doctor and ask him!\n");
    AddTalk("AB","I am fine. Thank you.","That's good to hear.","AA");
    AddTalk("AC","I am fine. But you are not...you will DIE.",#'kill_it);
  AddTalk("B","Howdie.","Howdie stranger.");
    AddTalk("BA","So, what's up?","Not much here. How are you?\n","A"); 
    AddTalk("BB","Stranger...Fucking orcs.",#'kill_it);
  AddTalk("C","Shitty orc!!!",#'kill_it);

  // end of example NPC
}


