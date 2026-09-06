/* CHANGES
 *  98/07/05 [Mica] 'removed' look_at_room, is not used nor documented
 */

#include <config.h>
#include <properties.h>
#include <secure/wizlevels.h>
#include <secure/udp.h>
#include <nightday.h>
#include <search.h>
#include <living.h>
#include <npc.h>
#include <daemons.h>

/* TODO : tfinger foes not work with mudlink yet */

inherit "/std/npc/view";

#define THIS this_object()
#define TP this_player()

void add_view_commands() {
  add_view_cmds();
  add_action("toggle_obvious", "obvious");
  add_action("toggle_brief", "brief");
}

int toggle_brief() {
  if (SetBrief(!QueryBrief()))
    write("Brief mode.\n");
  else
    write("Verbose mode.\n");
  return 1;
}

int toggle_obvious() {
  if (SetObvious(!QueryObvious()))
    write("Showing obvious exits.\n");
  else
    write("Hiding obvious exits.\n");
  return 1;
}
