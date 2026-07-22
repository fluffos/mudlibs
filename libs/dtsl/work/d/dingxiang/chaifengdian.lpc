// /d/yazhang/chaifengdain.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "裁缝店");
	set("long", @LONG
这里是牙帐最大的裁缝店，这里做出的衣服，不论样式还是手工都
是首屈一指的，在整个牙帐都挑不出第二家。这里出品的衣服价格昂贵，
但却都是极品。
LONG
	);
set("exits", ([
                 "east" : __DIR__"nandajie1",    
	]));
 set("objects",([ __DIR__"npc/licaifeng":1,]));
       setup();
	replace_program(ROOM);
}	
