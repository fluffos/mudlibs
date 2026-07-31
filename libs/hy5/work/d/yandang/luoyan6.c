// Room: /d/yandang/luoyan6.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
大厅十分广阔,纵横有二三十丈,在正北面是一扇屏风,其前面摆了
一张雕花太师椅,沿着大厅两边,摆了一长溜客椅,此处是庄主平常会见
客人和聚集弟子商议的所在.
LONG
	);
	set("no_clean_up", 0);
	set("valid_startroom", 2);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luoyan5",
  "north" : __DIR__"luoyan7",
]));
set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/master" : 1,
  __DIR__"npc/dizi" : 4,
  "/quest/menpai/newmp/shi13" : 1,
  "/d/biwu/champion_yd" : 1,
]));

	setup();

	replace_program(ROOM);
}
