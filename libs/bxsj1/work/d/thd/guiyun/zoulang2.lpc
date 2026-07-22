// /u/jpei/guiyun/zoulang2.c

inherit ROOM;

void create()
{
	set("short","走廊");
	set("long",@LONG
这是连接中厅与后厅的走廊。走廊曲曲折折，两旁种满了花树。北边有一
间客房。
LONG
);
	set("exits",([
		"east" : __DIR__"zoulang1",
		"west" : __DIR__"zoulang3",
		"north" : __DIR__"kefang",
	]) );
	set("no_clean_up",0);
	set("outdoors", "归云庄");
	set("objects",([
        __DIR__"npc/zhuangding" : 1,
	]));  
	setup();
}
