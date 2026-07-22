// /d/taiyuan/wanjingzhai.c
// Room in 太原
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "万金斋");
	set("long", @LONG
具说这家钱庄的东家是在朝中大员，本金雄厚，在关内各地都有分
号，所开出的银全国通行，就远到吐鲁番，西突厥也可通行。不过最近
老板外出旅游，所以这里没人打理。
LONG
	);
set("exits", ([
                "west" : __DIR__"nandajie1", 
	]));
 set("objects",([ __DIR__"npc/huoji":1,]));
       setup();
	replace_program(ROOM);
}	
