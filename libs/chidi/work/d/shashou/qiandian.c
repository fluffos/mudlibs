//room: /u/chen/shashou/qiandian.c
inherit ROOM;

void init();

void create()
{
	set("short","前殿");
	set("long", @LONG
	这里是杀手楼的前殿，两旁是金刚石铺成的宏阔
大道，槐柳成荫，四周画栋雕梁，飞檐崇脊，气势磅礴，
这里看起来防卫森严。
LONG
	   );
	set("exits",([/* sizeof()==5 */
          "south" : __DIR__"jiaochang",
	    "north" : __DIR__"yilou",
	    "west" : __DIR__"erlou",
	    "east" : __DIR__"sanlou",
	   ]));
	set("objects",([
                      __DIR__"npc/weishi":2,
//               "/u/quest/zuolen~1" : 1,
			]));
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
