// Room: /d/dali/huanggong5.c
// Data: ¹şµÏË¹(hades)
// Time: ¹«Ôª£º1999Äê4ÔÂ18ÈÕ£¬±±¾©Ê±¼ä£º21Ê±27·Ö26Ãë¡£

inherit ROOM;

void create()
{
	set("short", "[1;33mÕıµî[2;37;0m");
	set("long", @LONG
ÕâÀïÊÇ³ĞµÂµîÇ°µÄÒ»¼äÕıµî¡£ÕâÀïÊÇ³¯³¼ÉÏ³¯±ØÓÉÖ®Â·£¬Òò´Ë
µîÄÚ¼×Ê¿ÁÖÁ¢£¬½ä±¸É­ÑÏ¡£
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"huanggong4",
  "west" : __DIR__"huanggong11",
  "east" : __DIR__"huanggong10",
  "north" : __DIR__"huanggong7",
  "northup" : __DIR__"huanggong6",
]));

                 set("objects", ([
                __DIR__"npc/shiwei" : 4,

        ]));

	setup();
}

