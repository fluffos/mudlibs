// Room: /u/cuer/emei/dian4.c

inherit ROOM;

void create()
{
	set("short", "后殿");
	set("long", @LONG
这里是千佛庵的后殿，在接引殿的后面，是师太们做
功课的地方。地上摆满了蒲团，殿内坐着十几个正在颂经
的尼姑，坐在中间的是静和师太。再往北就是神灯阁了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shendeng",
  "south" : __DIR__"dian3",
]));
	
        set("objects", ([
            __DIR__"npc/jinghe" : 1,
              ]));

	setup();
	replace_program(ROOM);
}
