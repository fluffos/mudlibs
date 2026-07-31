//Room: /d/dali/gaolishan2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","高黎山密林");
	set("long",@LONG
高黎山上地势险恶、树大林深，附近几乎毫无人烟。地处高山四
季皆寒，熊虎等猛兽时常出没，只有勇敢的猎人才敢上这里来。东面
下山即是泸水谷地。
LONG);
	set("objects", ([
	   "/d/hangzhou/npc/laohu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"gaolishan1",
	]));
	setup();
}

