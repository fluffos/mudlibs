inherit MONSTER;
create_monster()
{
  set_name(({"Jerry","aged farmer","jerry","jerry garcia", "farmer"}));
  set_short("Jerry Garcia, the aged farmer");
  set_long(wrap("Jerry Garcia is an old white haired and bearded man."+
  "  He looks like Santa Claus in a pair of over-alls.  He has a piece "+
  "of wheat in between his teeth, and his hands are very dirty.  He "+
  "is not wearing any shoes.  It appears that the only kind of clothing "+
  "he has on is his over-alls and nothing else.  He has a very large smile "+ 
  "on his face and seems to be laughing at himself.\n"));
  set_race("thari");
  set_levels((["fighter" : 50 ]));
  set_language("sartog");
  set_wimpy(50,100);
  set_talk_delay(20);
  set_emote(({"Jerry bends over with laughter.",
              "Jerry picks his teeth with his finger.",
              "A terrible smell comes from the direction of Jerry.",
              "Jerry pulls the piece of wheat out of his mouth.",
              "The farmer puts a new piece of wheat in his mouth.",
              "The farmer looks up to the skies, ponders, and then sighs.",
              "Jerry licks his finger and puts it into the air."}));
 set_talk(({"YEE, HAW!",
            "Soon ya'll can know what I know",
            "I pray to Madrid every night, he helps my crops",
            "If you want to be my student you must join the school",
            "Ya'll should know that I teach class here",
            "Ya best behave in my classes"}));
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
