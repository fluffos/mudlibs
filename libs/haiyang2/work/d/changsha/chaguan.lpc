// /d/zhuojun/chaguan.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "佩秋亭");
	set("long", @LONG
这个茶馆非常大，茶馆中的桌椅都是由檀木做成，茶壶，茶碗都是
景德镇的瓷器，第一遍茶都不喝，只是用来涮涮碗而已，因此全城的人
都乐意到此喝茶聊天。
LONG
	);
set("exits", ([
                "north"  :__DIR__"xidajie2",
	]));
	set("resource/water",1);
	set("objects",([
	__DIR__"npc/xiaoer2":1,
	]));
       setup();
	replace_program(ROOM);
}	
