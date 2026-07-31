// rich 99/04/05
inherit ROOM;
void create()
{
	set("short", "东门");
	set("long", @LONG
马邑是西北的重镇，和突厥接壤，和灵武是抵抗突厥的第一道防线，
隋朝灭亡后，李阀占俱关中，突厥乘式控制了马邑，马邑反而是突厥进攻
中原的桥头堡，守门的官兵仔细的盘察来往的客商，一丝不敢大意。
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
                "west" : __DIR__"dongjie",
                "southup" : __DIR__"changcheng11",

	]));
set("objects",([
  __DIR__"npc/bing":2,
  __DIR__"npc/wujiang":1,
  ]));
       setup();
	replace_program(ROOM);
}
