inherit ROOM;

void create()
{
      set("short","山路");
      set("long",@LONG
这是一条上山的小路，蜿蜒的通向山上，弯弯曲曲路上到处都是一些
细碎的沙石，两旁都是树，风吹动树叶在你耳边沙沙作响，你望着前
方，不禁暗自小心了起来！
LONG);
      set("outdoors", "xx");
      set("exits",([ /* sizeof() == 2 */
          "north" : __DIR__"shanlu2",
        ]));
      setup();
}

