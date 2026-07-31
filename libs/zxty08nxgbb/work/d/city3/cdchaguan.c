
inherit ROOM;

void create()
{
        set("short", "望风茶馆");
	set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几
张八仙桌一字排开，坐满了客人，或高声谈笑，或交头接耳，只
听见全是些操着川话的市俗之徒。你要若想打听江湖掌故和谣言，
这里是个好所在。需要些茶水和点心可在些小坐。
LONG
	);
        set("no_fight",1);

	set("exits", ([
                "north" : __DIR__"dongjie3",
	]));

	set("objects", ([
                __DIR__"npc/boss" : 1,
	]));

	setup();
	replace_program(ROOM);
}

