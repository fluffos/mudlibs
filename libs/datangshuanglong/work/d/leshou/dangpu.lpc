// /d/zhuojun/dangpu.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "当铺");
	set("long", @LONG
你走进当铺，看见一位老先生，这个老先生据说是当年朝庭的供奉，
眼力非凡，他订的价几乎就是金口玉言，所以前来典当东西的人经常光顾
此处询问价值。
LONG
	);
set("exits", ([
                "south"  :__DIR__"xidajie2",
	]));
	set("objects",([
	__DIR__"npc/qiao":1,
	]));
       setup();
	replace_program(ROOM);
}	
