/*
** File: statue.c
** Purpose: A stone staue - for when people get turned to stone.
*/

inherit OBJECT;

void create() {
  set("mass", 400);
  set("size", 6);
  set("name", "Noone");
  set("long", "@@query_long");
  set ("short", "@@query_short");
  set("gender", "neuter");
  set("id", ({ "statue", "stone statue" }) );
}

string query_short() {
  string name;

  name = query("name");
  name = "a stone statue of "+name;
  return name;
}

string query_long() {
  string name;
  
  name = query("name");
  name = 
"This is a stone statue of "+name+".\n"+
"From the look on "+possessive(query("gender"))+" face, "+
subjective(query("gender"))+" was in considerable pain, "+
"considerable horror, or both when "+subjective(query("gender"))+
" was transformed.";

  return wrap(name);
}

void set_name(object ob) {
  if (living(ob)) {
    set("gender", ob->query("gender"));
    set("name", ob->query("cap_name"));
  }

  set ("mass", (int)ob->query("mass") * 2);
  set ("size", ob->query("size"));
  return ;
}
