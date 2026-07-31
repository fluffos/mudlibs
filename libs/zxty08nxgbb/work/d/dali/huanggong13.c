// Room: /d/dali/huanggong13.c
// Data: ¹şµÏË¹(hades)
// Time: ¹«Ôª£º1999Äê4ÔÂ18ÈÕ£¬±±¾©Ê±¼ä£º21Ê±27·Ö26Ãë¡£

inherit ROOM;

void create()
{
	set("short", "[1;33mÇÚÕşµî[2;37;0m");
	set("long", @LONG
ÇÚÕşµîÊÇ±£¶¨µÛµÄÇŞ¹¬ËùÔÚµØ£¬µîÄÚÖéÁ±µÍ´¹£¬ºìÖò¸ßÕÕ£¬¼¸
¸ö¹¬×°ÉÙÅ®ÕıÔÚÊÕÊ°·¿¼ä¡£´©¹ı´óµî£¬ºó½ø¾ÍÊÇ¼¸¼äĞ¡µî£¬ÄÇ¾ÍÊÇ
»ÊµÛĞİÏ¢µÄµØ·½ÁË¡£
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"huanggong11",
  "southdown" : __DIR__"huanggong15",
  "west" : __DIR__"huanggong14",
]));

	setup();
}

