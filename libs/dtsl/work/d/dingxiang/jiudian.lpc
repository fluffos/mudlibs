// /d/yazhang/jiudian.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "酒店");
	set("long", @LONG
大厅中摆放了十数张圆桌，旁边坐满了客人。几名店小二搭着雪白
的毛巾客人中穿梭着，好一派生意兴隆的景象。
LONG
	);
set("exits", ([
                 "west" : __DIR__"nandajie2",  
	]));
	set("objects",([
	 __DIR__"npc/xiaoer":1,
	 ]));
       setup();
	replace_program(ROOM);
}	
