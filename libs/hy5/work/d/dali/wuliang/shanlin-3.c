// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "É­ÁÖ");
	set("long", @LONG
ĞĞ³öÊıÀï£¬½øÁËÒ»×ù´óÊ÷ÁÖÖĞ£¬ËÄÖÜ¶¼ÊÇÊÇ²ÎÌì¹ÅÄ¾£¬µ±ÈÕÑô¹â²ÓÀÃ£¬ÁÖ
ÖĞÈ´ºÚ³Á³ÁµØÍğÈç»Æ»è¡£±±ÃæÒ»Ö±Í¨ÏòÁÖ×ÓÉî´¦¡£Ô 
LONG
	);
        set("outdoors", "´óÀí");

	set("exits", ([
             "north" : __DIR__"shanlin-4",
	     "westdown" : __DIR__"shanlin-2",
	]));
        set("objects", ([
	      __DIR__"obj/yeguo" : 2,
	]));
	setup();
	replace_program(ROOM);
}
