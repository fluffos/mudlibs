/*
** FILE: nuke_skull.c
** PURPOSE: What's left after somebody gets nuked.
**				YOU COULD BE NEXT! MUHAHAHA!!
** CHANGES:
**   24 Apr 97   Cyanide@QuestionMud   Created the File
*/

#include <mudlib.h>

inherit OBJECT;

void create() {
  set("mass", 1);
  set("name", "Noname");
  set("id", ({ "skull", "charred skull" }) );
  set("short", "@@query_short");
  set("long", "@@query_long");
}

string query_short() {
  string str;

  str = (string)query("name");
  str = "the charred skull of "+capitalize(str);

  return str;
}

string query_long() {
  string str;

  str = (string)query("name");
  str = "This is all that remains of poor "+str+".\n";

  return str;
}
