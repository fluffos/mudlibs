inherit MONSTER;

#include "../path.h";
#define say(x) "/command/mortal/say"->main(x)

create_monster()
{
     set_name(({"glandil", "prince","prince glandil", "elf", "tanir"}));
     set_short("Glandil, the elven prince is here trying to keep himself awake");
     set_long(wrap("Glandil is a medium height, slender elf. He looks very tired, like he's "+
      "been awake for many days. He wears a golden headband, which signifies him as a prince. "+
      "He is clothed in a dark green cloak over his breastplate.\n"));

     set_emote(({"Glandil rubs his eyes to try to stay awake."}));

     set_gender (1);
     set_language("alande");

     set_talk_delay(20);

     set_talk(({"I want Rayak's head.",
                "50 silver coins goes to the one who gives me the goblin king's head."}));
    
     set_race ("tanir");
     set_levels(([ "fighter" : 42 + random(20) ]));
}

init()
{
  add_action("do_give","give");
}

do_give(string what)
{
 int i;
  if(present("goblin head",THIS))
  {
    if(what == "head to glandil" || what == "head to prince")
     {
       say("You are truly a valiant warrior " + THIS->query_cap_name() +". Here is your "+
           "due reward of 50 silver.\n");
       for(i = 0;i<50;i++)
       {
       THIS->add_money(50);
       }
       destruct(present("goblin head",THIS));
       return 1;
     }
    else
     {
       write(wrap("Give what to who?\n"));
       return 0;
     }
  }
}
