inherit ROOM;
string* npcs = ({
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/fushe",
});
 
void create()
{
        set("short", "灌木林");
        set("long",@LONG
这是一片灌木林。走了不远,你就可以看得见前面的空地了。
LONG);
	set("exits", ([
		"north" : __DIR__"kongdi",
		"south" : __DIR__"lin1",
	]));
	set("objects", ([
		__DIR__"npc/dushe" : 1+random(2),
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
	]) );
	set("outdoors", "shenlong");
    set_temp("wayao2",4);
	setup();
	replace_program(ROOM);
}

