
#include <mudlib.h>

#define MAGPAGE "/obj/mag/"
inherit DAEMON;
inherit OBJECT;

string path;

void create() {
  seteuid(getuid());
  set("short", "porno magazine");
  set("long", "Mud Chix Magazine for those who want some.\n"+
  "But aint gettin any.\n"+
  "Type goggle index.\n");
  set("id", ({ "magazine" }) );
set("value", 3);
 
 }

void init() {
  add_action("cmd_goggle", "goggle");
  }
int cmd_goggle(string str) {
  string page;
  if (!str) str = "index";
 
  page = read_file(MAGPAGE+"/"+str);
    write(page);
    return 1;
 }