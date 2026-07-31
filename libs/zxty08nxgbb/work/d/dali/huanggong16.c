// Room: /d/dali/huanggong16.c
// Data: ¹şµÏË¹(hades)
// Time: ¹«Ôª£º1999Äê4ÔÂ18ÈÕ£¬±±¾©Ê±¼ä£º21Ê±27·Ö26Ãë¡£

inherit ROOM;

void create()
{
	set("short", "[1;33m¼ÎÃ÷µî[2;37;0m");
	set("long", @LONG
¼ÎÃ÷µîÊÇ´óÀí»Ê¹¬¹©½øÓùÉÅµÄËùÔÚ£¬ÓëÇŞ¹¬ËùÔÚµÄÇÚÕşµîÏàÁÚ¡£
ËÄÖÜ½ûÎÀÇ×´Ó¡¢½üÊÌÖĞ¹ó£¬Ìá¾¯µÃÉõÊÇ½ûÑÏ¡£
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"huanggong17",
  "north" : __DIR__"huanggong15",
  "west" : __DIR__"huanggong18",
]));

                 set("objects", ([
                __DIR__"npc/weishi2" : 4,
        ]));

	setup();
}

