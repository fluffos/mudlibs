// feisheng.c 飞升岩
// by llin 

inherit ROOM;

void create()
{
	set("short", "飞升岩");
	set("long", 
"南岩宫西面深壑之中有一孤峰崛起，此地名唤飞升台，传\n"             
"说为真武舍身成神之处。其势如楼阁飞空，险奇峻秀。立身其\n"         	
"上,下望千丈悬崖峭壁，端是令人心惊胆寒。\n"  
	);                          	
	set("outdoors", "wudang");
	set("exits", ([
		"eastdown" : __DIR__"liangyi",
	]));
	setup();
	replace_program(ROOM);
}

