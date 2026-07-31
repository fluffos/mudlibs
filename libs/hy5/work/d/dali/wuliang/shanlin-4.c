// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "É­ÁÖ");
	set("long", @LONG
ÕâÀïËÄÖÜ¶¼ÊÇÊÇ²ÎÌì¹ÅÄ¾£¬µ±ÈÕÑô¹â²ÓÀÃ£¬ÁÖÖĞÈ´ºÚ³Á³ÁµØÍğÈç»Æ»è£¬Ô½
×ßÊ÷ÁÖÔ½ÃÜ£¬ÓĞÊ±²»µÃ²»²àÉí¶øĞĞ¡£Ô 
LONG
	);
        set("outdoors", "´óÀí");

	set("exits", ([
            "south" : __DIR__"shanlin-3",
	    "west" : __DIR__"shanlin-5",
	]));

	setup();
	replace_program(ROOM);
}
