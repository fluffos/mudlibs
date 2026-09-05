#include "/players/fakir/color.h"
inherit "/obj/treasure";
reset(arg) {
  if(arg) return;
  set_id("title"); }
init() {
  ::init();
  add_action("title","title"); }
title() {
this_player()->set_guild_name(0);
this_player()->set_title(BOLD+RED+"Etherial Dervish"+OFF);
this_player()->set_pretitle("");
this_player()->set_al_title(CYAN+"Spiffy"+OFF);
 return 1; }


