// Room: jyentrance.c

inherit ROOM;

void create()
{
        set("short", "监狱入口");
        set("long", @LONG
这里是明教监狱的入口，明教虽然不是名门正派，但一向行事光明磊落
所以这里关押的一向是江湖上著有恶名的大盗，采花淫贼。但听说这儿也
关押有明教的一些违规的弟子。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shenghuo-tang",
  "north" : __DIR__"jianyu",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yu-zu" : 1,
  __DIR__"npc/lengqian" : 1,
]));
        set("no_clean_up", 0);

        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && objectp(present("leng qian", environment(me))))
                return notify_fail(
"冷谦喝道：那是明教重地，这位" + RANK_D->query_respect(me) + "请止步。\n");
        return ::valid_leave(me, dir);
}

