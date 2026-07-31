// Room: /d/yanjing/street2.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
街道的两边是林立的招牌店铺,几个行人围着个卖菜的小贩在讨价还
价,一条黄狗叼着只烧鸡跑了过去,后面跟着个气喘吁吁的大胖子,街道的西
边是家客栈,北边围了一大圈人,不知在干什么.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/person.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"gaosheng",
  "north" : __DIR__"street",
  "south" : __DIR__"street3",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
