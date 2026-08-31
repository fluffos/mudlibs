
#include <std.h>
#include <saahr.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("hare");
  set_race("hare");
  set_body_type("quadruped");
  set_gender(({"male","female"})[random(2)]);
  set_moving(1);
  set_speed(15+random(10));
  set_class("animal");
  set_subclass("fast");
  switch (random(5)) {
    case 0 :  case 1 :
      set_id(({"hare","large hare"}));
      set_short("a large hare");
      set_long("The hare is a dark brown color that blends in well "
        "with the shrubs. Its ears are up and alert to threats. It looks "
        "pretty large, it might make a good meal.");
      set_level(16);
    break;
    case 2 :  case 3 :
      set_id(({"hare","small hare"}));
      set_short("a small hare");
      set_long("A little hare, just recently matured. Its coat is dark "
        "brown, allowing it to hide well. It sniffs around "
        "and looks nervous.");
      set_level(15);
    break;
    case 4 :  default :
      set_id(({"hare","baby hare"}));
      set_short("a baby hare");
      set_long("A tiny little hare. Its coat is mostly white with spots "
        "of brown here and there. It moves a little awkwardly, like it "
        "shouldn't be out in the open just yet.");
      set_level(5);
    break;
  }
  set_id(query_id()+({"hare_kill_id"}));
}

void heart_beat() {
  ::heart_beat();
  if (!this_object() || !environment()) return;


  if (sscanf(file_name(environment()), VPROOMS+"river%*s") == 1 ||
      sscanf(file_name(environment()), VPROOMS+"lake%*s") == 1) {
        message("mout", "The hare swims off.", environment());
        this_object()->remove();
  }
}

