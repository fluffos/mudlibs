// Room: /d/jindezheng/jindezhen.c

inherit ROOM;

void create()
{
	set("short", "景德镇");
	set("long", @LONG
景德镇是江西名城,此地出产的瓷器遍销全国各地,甚至海外,尤其是 
此处烧制的青花瓷,玲珑瓷,粉彩瓷,颜色釉瓷,更是瓷器中的精品,为别处 
所无,你现在就在景德镇的一条小街上,街道的右手边就有一家陶瓷店. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 3 */
//  "northup" : "/d/hangzhou/lu4.c",
  "west" : __DIR__"street1",
  "south" : __DIR__"china-shop",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiongmao.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
