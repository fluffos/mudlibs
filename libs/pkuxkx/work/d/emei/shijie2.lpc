// Room: /u/cuer/emei/shijie2.c

inherit ROOM;

void create()
{
	set("short", "石阶");
set("outdoors","emei");
	set("long", @LONG
过了山门和山门殿，这里就算进入了峨嵋派了。一条
蜿蜒的石阶小道向山上延伸，两旁树木成林，不时有巡山
弟子来来往往，耳听着悦耳的鸟鸣声，看着四周的美丽景
色，真希望这条路一直走下去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shmdian",
  "northup" : __DIR__"shenshui",
]));
	
        set("objects",([
           __DIR__"npc/xunshan" : 2,
            
           ]));

	setup();
	replace_program(ROOM);
}
