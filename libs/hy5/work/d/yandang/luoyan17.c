// Room: /d/yandang/luoyan17.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
这是一条青石板铺成的大道,落雁山庄名镇武林,每天慕名前来的
武林人士络绎不绝,路两边林木森森,林中楼阁隐隐,神仙景地,从此地向
北,是男弟子居室,南面是女弟子居室,向东是客房.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"luoyan34.c",
  "south" : __DIR__"luoyan19",
  "north" : __DIR__"luoyan18",
  "west" : __DIR__"luoyan9",
]));
	set("outdoors", "/d/yandang");
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
	object ob;
	   if ( (dir=="south") && (me->query("gender")=="男性") )
	        return notify_fail("喂,走错了,男弟子的住房在北面！\n");
	   else{
	        if((dir=="north")&&(me->query("gender")=="女性") )
	        return notify_fail("你看到一群男弟子正在睡觉,赶忙退了出来,走错房间了!\n");
       }   
	   return ::valid_leave(me, dir);
}
