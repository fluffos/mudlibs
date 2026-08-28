inherit MONSTER;
create_monster()
{
  set_name(({"John","man"}));
  set_short("John Wesley Harding, a young farmer");
  set_long(wrap("Jerry Wesley Harding is a slim, young, black haired man."+
  "  He looks like a very nice person indeed.  He has a piece "+
  "of barley in between his teeth, and is quite clean for a farmer.  He "+
  "is wearing large black boots over his feet and lower legs.  It appears"+ 
  " that this farmer hasn't seen many harvest moons in his day.  He has a very"+
  "  large smile on his face and seems to be grinning at himself.\n"));
  set_race("thari");
  set_levels((["fighter" : 50 ]));
  set_language("sartog");
  set_wimpy(50,100);
  set_talk_delay(20);
  set_wander(1,45);
  set_emote(({"John bends over with laughter.",
              "John winks his eye at you.",
              "The young farmer gives you a friends smile.",
              "John becomes preoccupied for a second and then smiles.",
              "John grits his teeth and stares at the ground.",
              "John spits something out of his mouth.",
              "The farmer scratches his head."}));
 set_talk(({"Hello there, are you a farmer yet?",
            "Jerry Garcia sure is a hard professor.",
            "My friend Bob sure knows alot about seeds.",
            "Barliman knows about gettin' some water for your crops.",
            "Ol' Butterbung some call him, he's so damn funny!",
            "Velinax Belmonte can sell ya your equiptment pal.",
            "Wheel is turning and you can't slow down!",
            "You can't let go and you can't hold on!",
            "You can't go back and you can't stand still!",
            "If the thunder don't get ya then the lightning will!"}));
}
init()
{
  ::init();
  //add_action("do_ask","ask");
}
do_ask(string what)
{
  if(!what)
  {
    THOB->force_us("say Ask what?");
    return 1;
  }
  if(what == "jerry about news" || what == "jerry about the news" 
     || what == "Jerry about new" || what == "Jerry about the new")
  {
    THOB->force_us("say Madrid has told me in my dreams that in the next few days "+
    "I will be allowed to teach the rest of ya'll what I know so ya'll can "+
    "make your own food");
    return 1;
  }
  else 
  {
    THOB->force_us("say I don't know what you are trying to ask me about");
    return 1;
  }
return 0;
}
