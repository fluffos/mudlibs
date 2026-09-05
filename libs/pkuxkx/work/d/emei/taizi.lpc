// Room: /u/cuer/emei/taizi.c

inherit ROOM;

void create()
{
	set("short", "太子坪");
	set("long", @LONG
这里是千佛庵西边的太子坪，是峨嵋派年幼的弟子们
练功的场所。在这片开阔的草坪上散布着几个年幼的还没
有出家的小女孩。				
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"xiaodao",
]));
	set("objects",([
           __DIR__"npc/girl2" : 3, 
           __DIR__"npc/nigu1" : 3,
             ]));    

	setup();
	replace_program(ROOM);
}
