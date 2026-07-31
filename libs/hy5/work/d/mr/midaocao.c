//midao.c
inherit ROOM;

void create()
{
  set("short","密道");
  set("long","这里是漆黑的密道，当年幕容弟子为了有事直达中原而挖凿的。\n"); 
  set("exits" , ([
    "north" : "/d/city/kedian",
    "south" : "/d/mr/yanziwu",
      ]));
  set("no_npc", 1);
  set("no_clean_up", 0);
 setup();
}
