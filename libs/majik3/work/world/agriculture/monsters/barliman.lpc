inherit MONSTER;
#define say(x) THOB->force_us("say "+x);
#include "../path.h";

create_monster()
{
     set_name(({"barliman"}));
     set_short("Barliman Bastain, a stout halfling");
     set_long(wrap("Before you stands a round, stout halfling. His is sweating profusely and "+
      "breathing hard. He wears a dirty, yellow shirt and a pair of torn trousers. His eyes "+
      "are a deep blue, and his hair is dark brown and very curly.\n"));

     set_gender (1);
     set_language ("sartog");

     set_emote(({"Sweat pours from Barliman's brow.", 
                 "Barliman grabs a wrench and begins to assemble some sections of pipe."}));

     set_talk(({"Is there something you came for?",
                "If you want to know about irrigation just ask me about it.",
                "This job is a real bitch some times."}));
     
     set_race("halfling");

     set_levels(([ "fighter" : 15 ]));

}

init_monster()
{
  add_action("do_ask","ask");
  add_action("do_buy","buy");
}

do_ask(string what)
{
  
  if(what == "barliman about irrigation")
  {
   "/command/mortal/say"->main("If you plan on growing any crops 'round here your gonna need an ample "
    + "supply of water. I have pipes runnin' all over the farmlands and you can access "
    + "them with one of my special water drills. They only last for a limited time so "
    + "don't ferget to come back. If you want to buy one I can sell you one right here. "
    + "They're only 1 silver dime, type 'buy water drill' to do so.");
    return 1;
  }
  else {
    write ("Try asking about irrigation.\n");
    return 1;
  }
}

do_buy(string thing)
{
  if(thing == "water drill")
  {
    if(THIS->query_money() < 50)
       {"/command/mortal/say"->main("I said it costs 1 silver dime, which you don't have.\n");
        return 1;}
      if(THIS->query_money() >= 50)
    {
      say("Just a second and I'll get your drill.\n");
      write(wrap("Barliman runs off to front of the mill and returns quickly with an object "
       + "in his hand. He hands it to you with a smile and returns to his work.\n"));
      message("standard", THIS->query_cap_name()+" hands some money to "
       + "Barliman.\n", ENV(THIS), THIS);
      message("standard", "Barliman heads for the front of the mill and returns quickly. "
       + "He hands a strange object he brought back with him "
       + "to "+THIS->query_cap_name()+ "\n", ENV(THIS), THIS);
      clone_object(ITEM_PATH + "drill")->move(THIS);
      THIS->add_money(-50);
      THOB->add_money(50);
      return 1;
    }
  }
}
