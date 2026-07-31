// Room: /d/dali/huanggong14.c
// Data: ¹şµÏË¹(hades)
// Time: ¹«Ôª£º1999Äê4ÔÂ18ÈÕ£¬±±¾©Ê±¼ä£º21Ê±27·Ö26Ãë¡£

inherit ROOM;

void create()
{
	set("short", "[1;33mÇŞ¹¬[2;37;0m");
	set("long", @LONG
ÕâÀïÊÇ»ÊµÛµÄÇŞ¹¬¡£ÊÒÄÚÒ»Ö»ÏãÂ¯ÀïÑ¬×ÅÒ»ÊøÌ´Ïã£¬Õû¸öÊÒÄÚ
ÏãÑÌçÔÈÆ£¬ÈÃÈË»è»èÓûË¯¡£Áú´²ÉÏÉ´ÕÊÇá´¹£¬½õ±»ÊÕÊ°µÃÏË³¾²»È¾¡£
¼¸¸öÌ«¼àºÍ¹¬Å®Õı²»Í£µØÊÕÊ°·¿¼ä¡£
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"huanggong13",
]));

                 set("objects", ([
                __DIR__"npc/gongnu" : 2,

                __DIR__"npc/taijian" : 2,
        ]));

         
	setup();
}

