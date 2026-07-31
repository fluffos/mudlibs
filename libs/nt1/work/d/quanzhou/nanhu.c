// Room: /d/quanzhou/nanhu.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "¼ÎĞËÄÏºş");
	set("long", @LONG
ÕâÀïÊÇ¼ÎĞËÄÏºş¡£½Ú½üÖĞÇï£¬ºÉÒ¶½¥²Ğ£¬Á«Èâ±¥Êµ¡£Ò»ÕóÇáÈáÍÍñ×ªµ
Ä¸èÉù£¬Æ®ÔÚÑÌË®ÃÉÃÉµÄºşÃæÉÏ¡£ºş±ßÒ»¸öµÀ¹ÃÔÚÒ»ÅÅÁøÊ÷ÏÂÇÄÁ¢ÒÑ¾Ã¡£
LONG );
	set("exits", ([
            "west"      : __DIR__"jiaxing",
            "east"      : __DIR__"jiaxinggang",
            "south"     : __DIR__"tieqiang",
            "southeast" : __DIR__ "nanhu1",
	]));
	set("outdoors", "quanzhou");
        set("objects", ([
            CLASS_D("gumu") + "/limochou" : 1
        ]));
//      set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
