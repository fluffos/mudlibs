#include "path.h"
inherit CITY("adv_guild_inh");

create() {
  ::create();
  AddExit("north","./vill_road2");
  AddExit("east","./voting_room");
  AddExit("south",#'gocenter);
  SetLocation("nf-city");
log_file("guilds/advguild.log","Adv.Guild1 cloned by "+ QueryCreator() +" on "+ ctime() +" .\n");
}
