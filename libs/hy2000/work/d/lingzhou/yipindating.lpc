// Room: /lingzhou/yipindating.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "一品堂大厅");
	set("long", @LONG
这里是西夏一品堂的大厅，厅内阔大，显得有点阴晦。数十根合抱
大柱撑着看不清顶的飞檐，厅里气氛很是森森煞人。北面正中一副楠木
匾额(bian)高悬，金字蓝底，隐隐生威。红木公案后虎皮交椅上，正襟
威坐着的，就是征东大将军赫连总管。周围立着几个一品堂卫士，纹风
不动。
LONG );
	set("item_desc", ([
		"bian"  : "一品堂\n",
	]));
	set("exits", ([
		"south"  : __DIR__"yipindayuan",
	]));
	set("objects", ([
		"/quest/helian" :1,
		__DIR__"npc/yipinwushi" :4,
	]));
	set("no_fight",1);
	setup();
	replace_program(ROOM);
}

