
#include <std.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("hare");
  set_race("hare");
  set_body_type("quadruped");
  set_gender(({"male","female"})[random(2)]);
  switch (random(5)) {
    case 0 :  case 1 :
      set_id(({"hare","large hare"}));
      set_short("a large hare");
      set_long("The hare is a light brown color that blends in well "
        "with the grass. Its ears are up and alert to threats. It looks "
        "pretty large, it might make a good meal.");
      set_level(16);
    break;
    case 2 :  case 3 :
      set_id(({"hare","small hare"}));
      set_short("a small hare");
      set_long("A little hare, just recently matured. Its coat is light "
        "brown, allowing it to hide well in the grass. It sniffs around "
        "and looks nervous.");
      set_level(13);
    break;
    case 4 :  default :
      set_id(({"hare","baby hare"}));
      set_short("a baby hare");
      set_long("A tiny little hare. Its coat is mostly white with spots "
        "of brown here and there. It moves a little awkwardly, like it "
        "shouldn't be out in the open just yet.");
      set_level(8);
    break;
  }
}
    
