
// Room: /d/snow/crossroad.c

inherit ROOM;

void create()
{
        set("coor",({0,4900,10}));
	set("short", "林间小路");
        set("long",
"这里往南就是通往宁远城的官道了，一块官府立的告示牌立在路旁，上面写着“宁远城地界\n"
"”。往北是一片茂密的竹林，隐约看到里面有几个人影。\n"
);
        set("exits", ([ /* sizeof() == 3 */
 "north" : __DIR__"happyinn1",
// "northwest" : "/d/xiyu/yroad1",
  "south" : __DIR__"nroad2",
]));
        set("no_clean_up", 0);
        set("outdoors", "ny");

        setup();
        replace_program(ROOM);
}
