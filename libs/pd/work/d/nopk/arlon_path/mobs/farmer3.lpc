#include <std.h>
#include <arlonpath.h>
inherit MONSTER;

create() {
  ::create();
  set_name("farmer");
  set_id( ({"farmer"}) );
  set_short("old farmer");
  set_level(10);
  set_long("Am old farmer, weathered and bent by years of farming. He looks worried");
  set_gender("male");
  set("race", "human");
  set_alignment(300);
  set_body_type("human");
}

void init() {
  ::init();
  remove_call_out("do_say");
  call_out("do_say", 2);
}

void do_say() { this_object()->force_me("say I seem to have lost my keys. Will you help "
                                        "me find them? Please say yes."); }

void catch_tell(string str) {
    object ob;
    string a, b;

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%syes%s", a, b) == 2) {
        this_object()->force_me("say Excellent! Well, I was mucking out the siloh when a "
             "pack of rats attacked me. When I got outside I noticed my keys were missing "
             "and I could not lock the siloh back up. Please help me find my keys.");
        return;
    }
/*
    if(sscanf(str, "%skeys%s", a, b) == 2) {
        this_object()->force_me("say If you find my keys I will give you a reward.");
        return;
    }
*/
    if(sscanf(str, "%sgives you%s", a, b) == 2) {
        if(present("siloh keys", this_object())) {
          this_object()->force_me("say Excellent! I am greatful. Please accept this reward.");
          ob->add_money("gold", 500);
          ob->force_me("give 500 gold coins to "+this_player()->query_name());
          if(this_player()->set_mini_quest("Siloh Keys", 1000, "You found the siloh keys for a farmer.\n"))
          message("info", "You feel more experienced from the deed.", this_player());
          present("siloh keys", this_object())->remove();
        }
        else
          ob->force_me("say Thank you, but I have no use for that.");
        return;
    }
}
