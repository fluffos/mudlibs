inherit GUILD;

create_monster()
{
  set_name(({"jerry","aged farmer","jerry garcia", "farmer"}));
  set_short("Jerry Garcia, the aged farmer");
  set_long(wrap("Jerry Garcia is an old white haired and bearded man."+
  " He looks like Santa Claus in a pair of over-alls. He has a piece "+
  "of wheat in between his teeth, and his hands are very dirty. He "+
  "is not wearing any shoes. It appears that the only kind of clothing "+
  "he has on is his over-alls and nothing else. He has a very large smile "+ 
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

  add_answer ("news",
    "Madrid has told me in my dreams that in the next few days "
  + "I will be allowed to teach the rest of ya'll what I know so ya'll "
  + "can make your own food.");
}

create_guild ()
{
  set_guild ("School of Elementary Agriculture");
  set_guild_desc (
    "A student of elementary agriculture becomes fluent in the basic "
  + "skills of planting and gathering plants.\n");

  set_titles (({ "hillbilly", "redneck", "gatherer", "sower", "farmer" }));
  set_default_train_msg ("You become a bit more adept at [skill_name].\n");
  set_custom_advance_msg ("You feel a bit more wise in the ways of agriculture.\n");

  add_avail_skill ("planting", ({ 10, 15, 25, 40, 50 }));
  add_avail_skill ("harvesting", ({ 10, 15, 25, 45, 50 }));
  add_avail_skill ("gathering", ({ 0, 5, 20, 30, 45 }));
  add_avail_skill ("weeding", ({ 0, 5, 20, 30, 45 }));
  add_avail_skill ("sowing", ({ 0, 5, 20, 30, 45 }));
  add_avail_skill ("seed knowledge", ({ 0, 5, 20, 30, 45 }));
  add_avail_skill ("irrigation", ({ 0, 0, 10, 15, 20 }));
  add_avail_skill ("plant diagnosis", ({ 0, 0, 0, 10, 25 }));

                                    // ##1  ##2  ##3  ##4  ##5
  add_req_skill ("planting",        ({   0,   5,   0,   0,  35 }));
  add_req_skill ("harvesting",      ({   0,   5,   0,   0,   0 }));
  add_req_skill ("gathering",       ({   0,   0,   5,   0,   0 }));
  add_req_skill ("weeding",         ({   0,   0,   5,   0,  25 }));
  add_req_skill ("sowing",          ({   0,   0,   5,   0,  25 }));
  add_req_skill ("seed knowledge",  ({   0,   0,   0,   0,  10 }));
  add_req_skill ("irrigation",      ({   0,   0,   0,  11,   0 }));
  add_req_skill ("plant diagnosis", ({   0,   0,   0,   0,  10 }));
}
