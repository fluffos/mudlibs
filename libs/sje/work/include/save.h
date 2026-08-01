string *special_props = ({
  "short", "long" });

int save_kingdom() {
  object env, me;
  string str, *name, file;
  mapping prop;
  int i;

  me = this_player();
  file = me->query("cwd") + "kingdom.lpc";
  //	new(me->query("cwd")+"kingdom");
  env = find_object(me->query("cwd") + "kingdom");

  str = "// Room: " + me->query("title") + @ROOM_CODE

#include "ansi.h"
inherit ROOM;

void create()
{
ROOM_CODE;
  str += sprintf("\tset(\"short\", %O);\n", env->query("short"));
  str += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", env->query("long"));
  prop = env->query_entire_dbase();
  name = keys(prop);
  for (i = 0; i < sizeof(name); i++) {
    if (member_array(name[i], special_props) != -1) continue;
    str += sprintf("\tset(\"%s\", %O);\n", name[i], prop[name[i]]);
  }
  str += "\n\tsetup();\n\treplace_program(ROOM);\n}\n";

  rm(file);
  write_file(file, str);
  return 1;
  return 0;

}

int save_room(string file) {
  object env, me;
  string str, *name;
  mapping prop;
  int i;

  me = this_player();
  //	new(file);
  env = find_object(file);

  str = "// Room: " + me->query("title") + @ROOM_CODE

#include "ansi.h"
inherit ROOM;

void create()
{
ROOM_CODE;
  str += sprintf("\tset(\"short\", %O);\n", env->query("short"));
  str += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", env->query("long"));
  prop = env->query_entire_dbase();
  name = keys(prop);
  for (i = 0; i < sizeof(name); i++) {
    if (member_array(name[i], special_props) != -1) continue;
    str += sprintf("\tset(\"%s\", %O);\n", name[i], prop[name[i]]);
  }
  str += "\n\tsetup();\n\treplace_program(ROOM);\n}\n";

  rm(file + ".lpc");
  write_file(file + ".lpc", str);
  return 1;
  return 0;

}
