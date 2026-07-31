
// Room: /d/snow/schoolhall.c

inherit ROOM;

void create()
{
	set("coor",({-15,-50,0}));
	set("short", "淳风武馆大厅");
	set("long",
"这里是淳风武馆的正厅，五张太师椅一字排开面对著门口，这是武馆中四位大师傅与馆主柳\n"
"淳风的座位，和一般武馆不同的是，墙上竟然挂著几幅风骨颇为不俗的书画，显示这里的主\n"
"人并非大字不识的粗汉，而是文武双全的高人。\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"school2",
  "west" : __DIR__"inneryard",
]));
	set("valid_startroom", 1);
        set_temp("light",1);
	setup();
}

