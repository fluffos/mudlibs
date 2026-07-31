// Room: /d/jindezheng/tea-room.c

inherit ROOM;

void create()
{
	set("short", "碧桐园茶馆");
	set("long", @LONG
茶馆门口,是一杆旗杆,上面高高的挑了个茶字,门口两大石狮,却是 
一边大,一边小,上几级台阶,进门就是个大厅堂,摆了几十张桌子,靠北是 
个高台子,坐一老头,旁还有一大姑娘,干嘛的,说书的!不知道两人在说啥 
反正下面黑鸦鸦的人群是鸦雀无声,都入了迷了. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/oldman.c" : 1,
  __DIR__"npc/bgirl.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"street2",
]));

	setup();
	replace_program(ROOM);
}
