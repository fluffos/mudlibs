#include <std.h>
#include <tirun.h>

inherit MONSTER;

void create() {
  ::create();
  set_level(10+random(4));
  set_race("human");
  set_body_type("demon");
  set_name("Mr Lomack");
  set_short("A deformed, wilted man");
  set_long("This man seems to have undergone a change that went terribly wrong.  He has grown horns and has scales covering parts of his body.  You can even see a slight tail on him.");
  set_gender("male");
  set_alignment(-300);
  set_id(({"man", "deformed man", "wilted man", "mr lomack", "lomack"}));
}

void catch_tell(string str) {
    object ob;
    string a, b;
    int i;
    i = random(8);

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%s gives you %s", a, b) == 2) {
        if(present("good_potion_QO", ob)) {
          if(this_object()->query_current_attacker()) {
            ob->force_me("emote angrily rejects the potion!");
            ob->force_me("bury good_potion_QO");
            return;
          }
          ob->force_me("emote greedily drinks the antidote.");
          present("good_potion_QO", ob)->remove();
          call_out("finish_quest", 3, this_player());
        }
        else if(present("bad_potion_QO", ob)) {
          ob->kill_ob(this_player());
          ob->force_me("emote drinks down the potion and begins to change!");
          ob->force_me("emote roars angrily!");
          message("info", 
"                                               ,--,  ,.-.\n"
"                 ,                   \\,       '-,-`,'-.' | ._\n"
"                /|           \\    ,   |\\         }  )/  / `-,',\n"
"                [ ,          |\\  /|   | |        /  \\|  |/`  ,`\n"
"                | |       ,.`  `,` `, | |  _,...(   (      .',\n"
"                \\  \\  __ ,-` `  ,  , `/ |,'      Y     (   /_L\\\n"
"                 \\  \\_\\,``,   ` , ,  /  |         )         _,/\n"
"                  \\  '  `  ,_ _`_,-,<._.<        /         /\n"
"                   ', `>.,`  `  `   ,., |_      |         /\n"
"                     \\/`  `,   `   ,`  | /__,.-`    _,   `\\\n"
"                 -,-..\\  _  \\  `  /  ,  / `._) _,-\\`       \\\n"
"                  \\_,,.) /\\    ` /  / ) (-,, ``    ,        |\n"
"                 ,` )  | \\_\\       '-`  |  `(               \\\n"
"                /  /```(   , --, ,' \\   |`<`    ,            |\n"
"               /  /_,--`\\   <\\  V /> ,` )<_/)  | \\      _____)\n"
"         ,-, ,`   `   (_,\\ \\    |   /) / __/  /   `----`\n"
"        (-, \\           ) \\ ('_.-._)/ /,`    /\n"
"        | /  `          `/ \\\\ V   V, /`     /\n"
"     ,--\\(        ,     <_/`\\\\     ||      /\n"
"    (   ,``-     \\/|         \\-A.A-`|     /\n"
"   ,>,_ )_,..(    )\\          -,,_-`  _--`\n"
"  (_ \\|`   _,/_  /  \\_            ,--`\n"
"   \\( `   <.,../`     `-.._   _,-`\n"
"    `                      ```\n", environment(ob));
          ob->set_race("chimaera");
          ob->set_body_type("dragon");
          ob->new_body();
          ob->set_level(ob->query_level() + 5);
          ob->kill_ob(this_player());
          present("bad_potion_QO", ob)->remove();
        }
        else ob->force_me("emote looks at you quizzically.");
    }
    else {
        if(!ob->query_current_attacker())
        switch(i) {
          case 0: ob->force_me("say Ugh...  I'm in so much pain."); break;
          case 1: ob->force_me("say I wish I had never heard of the Chimaera."); break;
          case 2: ob->force_me("emote cringes in pain."); break;
          case 3: ob->force_me("emote sighs deeply, then enters a fit of coughs."); break;
          case 4: ob->force_me("say please help me..."); break;
          default: break;
        }
    }     
}

void finish_quest(object tp) {
    this_object()->force_me("emote sighs loudly and lands in a heap on the ground.");
    this_object()->force_me("whisper "+tp->query_name()+" Thank you..  I can now rest in peace.");
    if(tp->set_manual_quest("Haunted House")) {
      tp->set_stats("strength", tp->query_stats("strength") + 1);
      tp->set_stats("wisdom", tp->query_stats("wisdom") + 1);
      tp->set_stats("constitution", tp->query_stats("constitution") + 1);
      tp->set_stats("intelligence", tp->query_stats("intelligence") + 1);
      tp->set_stats("dexterity", tp->query_stats("dexterity") + 1);
      tp->set_stats("charisma", tp->query_stats("charisma") + 1);
      message("info", "You feel different somehow.", tp);
    }
    this_object()->force_me("emote transforms back into human form and dies.");
    this_object()->force_me("emote 's corpse turns into dust and blows away.");
    this_object()->remove();
}
