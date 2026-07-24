// Room: /dream/zhaobi.c
// HEM 1998/11/5
inherit ROOM;
void create()
{
	set("short", "照壁");
	set("long", @LONG
	这是一面宽阔的照壁，上面雕有瑞兽麒麟，活灵活现，仿佛要破壁而出。两旁
各有一通道。绕过照壁，就可以进入“留剑堂”。
LONG
	);
        set("outdoors", "tangmen");
	set("exits", ([
		"north" : __DIR__ "damen",
		"southwest" : __DIR__ "liujiantang",
                "southeast" : __DIR__ "liujiantang",
	]));
	setup();
	replace_program(ROOM);
}

