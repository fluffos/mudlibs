// Room: /d/huashan/v-road-3.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "山涧");
        set("long", @LONG
这里周围都是灌木，前面无法继续行走，西边是刚才来时的路。你隐隐约
约看到上面是玉女峰(mount)。
LONG);
        set("item_desc", ([
"mount" : "你仰头往上往去，隐约见到玉女峰高高在上。突然你发现就在离你很近的\n"
        "地方，上面有个东西闪闪发光！\n",
        ]) );
        set("exits", ([ /* sizeof() == 3 */
                "westdown"      : __DIR__"v-road-2",
                "southeast"      : __DIR__"shulin3"
        ]));
        set("outdoors", "华山");
        set("coor/x",60);
  set("coor/y",90);
   set("coor/z",0);
   setup();
}

int init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me;
        me=this_player();
        if ( arg!="up") return 0;
        tell_object(me, "你抓住周围的灌木，爬了上去。\n");
        message("vision", "只见" + me->query("name") + "抓住周围的灌木，爬了上去。\n", environment(me), me);
        me->move(__DIR__"v-road-4");
        return 1;
}
