inherit MONSTER;

mapping visitor = ([ ]);

create_monster ()
{
  set_name (({ "a village guard", "guard", "village guard", "moraki" }));
  set_short ("a village guard is standing here");
  set_long ("He is a village guard. Watching all traffic going in and out"
  +" from the hilltop village. It must be very lonely job.\n");
  set_race ("moraki");
  set_gender (1);
  set_levels (([ "fighter" : 20 + random(10) ]));
 
  set_talk (({ "This is a boring job..",
               "But someday this village will be bigger!",
               "Who are you?",
               "I've heard rumors that there is something mystical near hilltop of the gods in a cave..",
               "What are you doing here?",
               "This is my home, go away!",
               "There is nothing for you...",
               "I wish I had some food..",
               "Damn it! I can't even go outside.",
               "I am an intelligent monster, so don't fuckin' fuck with me!",
            }));
  set_emote (({ "Guard looks down from the window.",
                "Guard twiddles his thumbs.",
                "Guard looks very bored.",
                "Guard seems to be very hungry." }));
}

do_scribe (string str)
{
  string who;
  int what;
  write_file ("/log/hilltop", time() + " " + str + "\n");
  tell_room (environment(), "Guard scribes something on his notebook.\n");
  sscanf (str, "%s %d", who, what);
  if (!visitor[who])
    visitor[who] = 1;
  else
    visitor[who] += 1;

  if (visitor[who] == 10)
    {
      command ("say I wonder why that fuckin' "+capitalize(who)+" needs to run in and out all the time!");
    }
  if (visitor[who] == 20)
    {
      command ("say :angrily GRAAAAAAAAAAAAH!!!");
      add_talk ("That "+capitalize(who)+" is really a nuisance!");
    }
  if (visitor[who] == 5)
    {
      command ("say Again "+capitalize(who)+"! Better scribe it up anyway...");
    }
  return 1;
}
