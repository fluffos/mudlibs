#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("rose");
   set_short("a red rose");
   set_long(@ENDTEXT
%^RESET%^%^RED%^
                .-=.-~,
               /{,_;--'},
              |  .=~`|//|
              | /   ; \ |%^GREEN%^      __,
%^RED%^              ||    | | |%^GREEN%^    .' \/\
%^GREEN%^             |%^RED%^\|    | | |%^GREEN%^\  / \ /_|
%^GREEN%^             \ %^RED%^|  | /|'/%^GREEN%^ / | \ /_ |
%^GREEN%^     ,_      `\ %^RED%^\/|/ /%^GREEN%^ /`   \ /__/
%^GREEN%^    /\/`'.     `\ %^RED%^`./%^GREEN%^.'/\   /.--'
    |_\ / \      '.  /|\/| //
    | _\ / |      | | \ \///  .""'-.
     \__\ /    .'/| |  `)`/__//_/_/_\
      '--.\   /\/_| |%^ORANGE%^}%^GREEN%^ /.---. \ \ \ /
          \\ |\/_/| | //`    `'...-'
   .-""'.  \\\/ /%^ORANGE%^{%^GREEN%^| |// 
  /_\_\_\\__\`(`  |  /
  \ / / / .---.\  | |
   '-..,'`    `\\ | |%^ORANGE%^}%^GREEN%^
                \\| |
                 \  |
                  | |
                 %^ORANGE%^{%^GREEN%^| |
                  | |
                  | |
                  | |%^ORANGE%^}%^GREEN%^
                  | |
                  |/
ENDTEXT);
   set_mass(0);
   set_weight(0);
   set_value(0);
   set_id(({ "rose", "flower", "red rose" }));
}

int query_auto_load() { if (this_player()->query_gender() == "female") return 1; }

