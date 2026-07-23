// /d/taiyuan/nanmen.c
// Room in 太原
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "太原南门");
	set("long", @LONG
太原是西北的重镇，历来是兵家必争之地，隋朝灭亡后，李阀占俱
关中，太原又是李阀的根本重地，所以太原的防务十分严格，守门的官
兵仔细的盘察来往的客商，一丝不敢大意。
LONG
	);
set("outdoors", "taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "north" : __DIR__"nandajie1", 
	        "southeast" : __DIR__"sroad1",
	]));
      set("objects", ([
		__DIR__"npc/bing": 2,
		__DIR__"npc/wujiang":1,
	]));
       setup();
	replace_program(ROOM);
}	
