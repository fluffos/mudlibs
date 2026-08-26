// room used by the room description language compiler
// written by Truilkan@TMI - 92/05
// updated 93/02 -- Tru

#include <mudlib.h>
inherit ROOM;

mapping objects;

void make_object(string name, string path)
{
   object obj;

   if (!present(name,this_object())) {
      obj = new(path);
      obj->move(this_object());
   }
}

void reset()
{
   string *names;
   object obj;
   int j;

   names = keys(objects);
   for (j = 0; j < sizeof(names); j++) {
      make_object(names[j], objects[names[j]]);
   }
}

void add_object(string name, string path)
{
	objects[name] = path;
	make_object(name,path);
}

void add_exits(mapping e)
{
    set("exits", query("exits") + e);
}

int set_light(int l)
{
    set("light", l);
}

void set_name(string str)
{
   set("short", str);
}

void set_description(string str)
{
   set("long", str);
}

void describe_item(string str1, string str2)
{
   set("item_desc", query("item_desc") + ([ str1 : str2 ]));
}

void create()
{
   ::create();
   seteuid(getuid(this_object()));
   objects = ([]);
   set("exits", ([]));
   set("item_desc", ([]));
}
