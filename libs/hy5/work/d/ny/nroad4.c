
// Room: /d/snow/nroad4.c

inherit ROOM;
int do_mercy(string arg);
void create()
{
	set("coor",({-40,4870,10}));
	set("short", "小胡同");
	set("long",
"你走到一个胡同里，西面是衙门，东面是堵土墙，这里是买卖人口的地方。\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yamen_square",
]));
        set("item_desc", ([
                "sign": @TEXT
卖身葬父，价格：１０两黄金。

mercy    同情施舍黄金。

TEXT
        ]) );
	set("no_clean_up", 0);
	set("outdoor","snow");
	setup();
}

void init()
{
	add_action("do_mercy", "mercy");
}

