#include <std.h>
#include <shadow.h>

inherit MONSTER;

object pl;
int blah;

void create() {
  ::create();
  set_name("pixie");
  set("id",({"lost pixie","pixie","monster"}));
  set_level(10 + random(5));
  set("short","a lost pixie");
  set("long","This pixie must have been wandering around for a while.  She seems quite upset.");
  set("race","pixie");
  set_gender("female");
  set_body_type("pixie");
  set("alignment",500);
  pl = this_object();
  blah = 0;
}

void die() {
  if(environment(this_object()) == get_object("/d/shadow/rooms/nineteen"))
    "/d/shadow/rooms/nineteen"->set_here(1);
  ::die(1);
}

void init() {
  ::init();
   add_action("follow", "follow");
}

int follow(string str) {
  if(str != "allow pixie")
    return 0;
  blah = 1;
  this_object()->force_me("say Oh yippie skippy!  Someone to take me home!");
  pl = this_player();
  message("info","The small Pixie is now following you.",pl);
  blah = 0;
  return 1;
}

void catch_tell(string str) {
    string a, b;

    if((sscanf(str, "%shome%s", a, b) == 2) && (blah == 0)) {
        this_object()->force_me("say Home?  I dont know where it is!  I"
          " should have listened to my parents and not wandered so far north.");
        return;
    }
}

void heart_beat() {
  ::heart_beat();
  if (environment(this_object()) != environment(pl)) {
      message("info", "The little pixie follows "+pl->query_cap_name()+".\n", environment(this_object()));
      this_object()->move(environment(pl));
      message("info", "The little pixie skips in.\n",
           environment(pl));
    }
  if (environment(this_object()) == get_object("/d/shadow/rooms/seventh")) {
    this_object()->force_me("say Oh boy!  This is where my house is!");
    if(pl->query_gender() == "male")
        this_object()->force_me("say Thanks alot, mister man!");
    else if(pl->query_gender() == "female")
        this_object()->force_me("say Thank you, nice lady!");
    else
        this_object()->force_me("say Thank you sooooooo much!");
    say("The little pixie flies up into a tree and disappears from sight.\nIt just makes you feel all warm and fuzzy inside.");
    pl->add_alignment(100+random(50));
    if(!pl->set_mini_quest("pixie", 100, "You helped a lost pixie find her way home.\n"))
        pl->add_exp(800+random(200));
    this_object()->remove();
  }
}
