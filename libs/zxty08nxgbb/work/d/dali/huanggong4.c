// Room: /d/dali/huanggong4.c
// Data: ¹şµÏË¹(hades)
// Time: ¹«Ôª£º1999Äê4ÔÂ18ÈÕ£¬±±¾©Ê±¼ä£º21Ê±27·Ö26Ãë¡£

inherit ROOM;

void create()
{
	set("short", "[1;33mÕıµÂµî[2;37;0m");
	set("long", @LONG
ÕâÀïÊÇ³ĞµÂµîÇ°µÄÒ»¸ö´óµî£¬ÕâÀïÊÇ¸ø´ó³¼ÉÏ³¯Ê±ĞİÏ¢ÓÃµÄ¡£ÏÖÔÚ
ÒÑ¾­É¢³¯ÁË£¬Ö»ÓĞ¼¸¸öÎÀÊ¿ÔÚµîÉÏÖ´ÇÚ¡£¾­¹ıÇ°ÃæµÄÕıµî£¬¾Íµ½ÁË»Ê¹¬
µÄÖĞĞÄ³ĞµÂµî¡£
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"huanggong3",
  "north" : __DIR__"huanggong5",
]));
                 set("objects", ([
                __DIR__"npc/shiwei" : 2,
        ]));


	setup();
}

