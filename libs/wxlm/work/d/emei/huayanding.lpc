//Room: huayanding.c 华严顶
inherit ROOM;

void create()
{
      set("short","华严顶");
      set("long",@LONG
华严顶挺拔高峭，古刹云深，殿宇孤耸，风景奇险。这里视野开阔，仰可
见金顶巍巍，俯可望群峰罗列，许多蹲伏山间的寺院也在眼底。由此向西过数
坡，即到莲花石，东下过十二盘可到万年寺。北面是一间马厩。
LONG);
      set("objects", ([
	   CLASS_D("emei") + "/li" : 1,
	   __DIR__"npc/girldizi" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
	  "south"    : __DIR__"majiu2",
	  "northeast"     : __DIR__"shierpan4",
	  "north"     : __DIR__"jingji/enter",
	  "westup"   : __DIR__"lianhuashi",
      ]));
      setup();
      //replace_program(ROOM);
}
