#include <std.h>
inherit MONSTER;

object killer;
int i;

void create() {
 ::create();
   set_name("mom");
   set_short("Sigmas mother");
   set_long("
                                 .
                              .  !\\  _
                              l\\/ ( /(_
                             _ \\\\`--\" _/ .
                             \\\\~\")   (_,/)
                             _)/.   ,\\\\,/
                    _____,-\"~    \\ /   \"~\"-._____
                ,-~\"     \"~-.  .  \"  .  ,-~\"     \"~-.\n"
"              ,^             ^. `. .' ,^             ^.
             /                 \\  ^  /                 \\
            Y___________________Y   Y___________________Y
            I I^~\"I^   _ ^l\"~^l I   I l\"~\"l^ _   ^l\"~\"l l
            l !   l   (0) !   ! l   l !   ! (0)   !   ! I
            l  \\  `\\.___,/'  /  !   l  \\  `\\.___,/'  /  !
             \\  ^.         ,^  /!   !\\  ^.         ,^  /
              ^.  ~-------~  ,^\\`v-v'/^.  ~-------~  ,^
              _)~-._______,-~   }---{   ~-._______,-~(_\n"
"         .--\"~           ,-^7' /     \\ `Y^-,           ~\"--.
        /               (_,/ ,/'     `\\. \\._)    ___        \\
        \\_____.,--\"~~~\"--..,__        ___,..--<\"~   ~\"-.,___/
            / (    __,--~ _.._\"\"~~~~\"\" ,-\"  \"-.`\\     /~.-\"
            `._\"--~_,.--\"~    \\       /        \\ `---' /\n"
"               \"~\"\"            \\     /          \"-.__,/
                               `L   ]'
                                l   !
                                j___L
                               (_____)
                                I   I
                            -(Sigmas Mother)-
");
   set_level(2);
   set_gender("female");
   set_race("bird");
   set_body_type("fowl");
   set_id(({ "bird", "mascots mother", "dodo", "mother" }));
   new("/d/standard/obj/weapon/frypan")->move(this_object());
   this_object()->force_me("wield pan");
}

void set_killer(object ob)
{
 killer = ob;
}
void init()
{
 ::init();
 set_heart_beat(1);
}

void heart_beat()
{
 ::heart_beat();
 if (environment(killer)!=environment(this_object())) return;
 if (!i)
   {
    i++;
    message("shout", "Sigmas mom shouts: SIGMA MY LITTLE BOY! "+killer->query_name()+" KILLED HIM! HE WILL PAAAAY!!", users());
    this_object()->force_me("say MY LITTLE BOY! YOU KILLED HIM! DIE!!");
    this_object()->force_me("frypan "+killer->query_name());
    this_object()->move_player("/d/standard/freezer", "runs off sobbing.");    
    present("pan", this_object())->remove();
    this_object()->remove();
   }
}
