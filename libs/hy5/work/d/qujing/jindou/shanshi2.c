// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "山石冈");
  set ("long", @LONG

山石冈四处是碎石块，石块的缝隙里长出一些杂草。路的两边
为赫色的山岩，尖锋利刃。石冈远远近近地长着一些古树，在
山风中摇曳。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"shanshi1",
        "southeast"   : __DIR__"jindou2",
        "southwest"   : __DIR__"shidong",
      ]));
  set("outdoors", "xy17");

  setup();
}

void init()
{
  add_action("do_all", "",1);
}

int do_all(string arg)
{


  if (random(8)==0)
    set("exits/southwest", __DIR__"shidong");
  else
    set("exits/southwest", __DIR__"shanshi1");
  return 0;
}


