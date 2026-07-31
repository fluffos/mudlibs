// Room: /d/hainan/shutang.c

inherit ROOM;

void create()
{
	set("short","白云庵藏经堂");
	set("long", @LONG
这间房间的四周摆了几个放经书的架子,上面摆满了书,不过就是比 
起一般的寺庙也是远远不如.但你如果拿起一本来看的话,就会发现,这里 
保存的都是武林各门派的武功秘籍. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"chucang.c",
  "east" : __DIR__"jingtang",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/jinggui.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
