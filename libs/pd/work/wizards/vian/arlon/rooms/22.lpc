#include <std.h>
#include <arlon2.h>
inherit HALL;
void create() {
    object board;
    ::create();
    set_properties( (["no attack" : 1, "no steal" : 1, "no bump" : 1, ]) );
    set("short", "The adventurer hall of Arlon");
    set("long", "The adventurer hall of Arlon is a giant room, but it is quite empty.  There is a sole old man here, who will help you in your training.  You can type <cost> to see your stats, and if you can train stats, you can use <improve statname> to improve them.  You can <advance> to grow in levels, or train your <skills> with <train skillname expamount>.  If you want to see quests available to you, you can <list> them and if you aren't happy with your stat roll, you can <roll stats> to have them randomized.");
    set_exits( 
              (["out" : ROOMS "21",
               ]));
                         board = new("std/bboard");
          board -> set_name("board");
          board -> set_id(({"board","adventurer workboard"}));
          board -> set_max_posts(1000);
          board -> set_edit_ok(({"vian"}));
          board -> set_location(ROOMS "22");
          board -> set_short("The Adventurer Board");
          board -> set_long("Do you have general comments about the newbie experience?  Post them here!");
           board->set_board_id("theadventurerboard");
                   if(!present("tibinus")){
        new(MOB"tibinus")->move(this_object());
}
}
