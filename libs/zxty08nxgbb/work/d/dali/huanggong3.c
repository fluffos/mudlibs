// Room: /d/dali/huanggong3.c
// Data: ĞÄ(ami)
// Time: ¹«Ôª£º1999Äê4ÔÂ19ÈÕ£¬±±¾©Ê±¼ä£º13Ê±22·Ö2Ãë¡£

inherit ROOM;

void create()
{
	set("short", "[1;33m¹ã³¡[2;37;0m");
	set("long", @LONG
ÕâÀïÊÇÕıµÂµîÇ°µÄÒ»¸ö¹ã³¡£¬ËÄÖÜÖÖÂúÁË´óÀíµÄÃû²è»¨£¬ÖĞ¼äÒ»
Ìõ°×Óñ´óµÀÖ±Í¨ÕıµÂµî£¬´óµÀÁ½ÅÔÕ¾×ÅÒ»ÅÅÕûÆëÑÏËàµÄ½ûÎÀ¾ü£¬ÏÔµÃ
¸ñÍâµÄ×¯ÑÏËàÄÂ¡£
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"huanggong17",
  "south" : __DIR__"huanggong2",
  "northup" : __DIR__"huanggong4",
]));

                 set("objects", ([
                __DIR__"npc/taijian" : 2,
                __DIR__"npc/weishi2" : 4,
        ]));

        setup();

}

