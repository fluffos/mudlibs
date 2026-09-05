/*   This is a generic wiz workroom.  It has a number of examples
	that should help you get started. Before you get too far along,
	you should change 'your_name' to your real name. (i.e I would
	change 'your_name' to "eurale")  I've tried to include things
	that most people want to add so look through and if you still
	have questions, contact someone for help.  Enjoy  -Eurale
*/

#include "/open/ansi.h"
#define TP this_player()
#define NAME "your_name"
inherit "room/room";
int shield;

reset(arg) {
  if(arg) return;

short_desc = "Wizard Workroom";
long_desc =
  "A sparse working area with nothing but a desk and chair. You may\n"+
  "turn your privacy shield (on/off). There are also hidden exits to\n"+
  "the 'church' and the 'post' office.\n";
set_light(1);

items = ({
  "chair","A creaky old wooden chair",
  "desk","A scarred old desk with the intial 'B' carved in it",
});

dest_dir = ({
  "room/adv_inner.c","north",
});

}

init() {
  ::init();
  add_action("church","church");
  add_action("on"); add_verb("on");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
if(this_player()->query_real_name() != NAME && shield == 1) {
  write("You feel an electric shock and see a FLASH of white light\n"+
        "as you rebound off some surrounding shield.\n");
  this_player()->move_player("off the shields#room/church");
  return 1; }
 }

church() {
  TP->move_player("church#room/church.c");
  command("look",this_player());
  return 1; }

static on() {
  write("You "+BOLD+"activate"+NORM+" the shield.\n");
  shield = 1;
  return 1; }

static off() {
if(TP->query_real_name() != NAME) {
  write("You are not allowed to do that!!!!!!!\n");
  return 1; }
  write("You "+BOLD+"deactivate"+NORM+" the shield.\n");
  shield = 0;
  return 1; }

post(){
  TP->move_player("post office#room/post.c");
  return 1; }
