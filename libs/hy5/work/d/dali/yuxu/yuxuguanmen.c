// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "ÓñĞé¹ÛÃÅ");
	set("long", @LONG
×ßµ½½ü´¦£¬¼ûÄÇ»ÆÇ½Ô­À´ÊÇËùËÂ¹Û£¬ØÒ¶îÉÏĞ´µÄËÆºõÊÇ¡®ÓñĞé¹Û¡¯Èı×Ö£¬
»ÆÇ½ºìÍß£¬Õâ¹Û¿´ÆğÀ´ºÜÊÇ¼òÂª£¬ÃÅ¿ÚÕ¾×ÅÁ½¸öĞ¡µÀÍ¯¡£Ğ
LONG
	);
        set("outdoors", "´óÀí");
	set("exits", ([ /* sizeof() == 1 */
	    "enter" : __DIR__"yuxuguan",
	    "east" : __DIR__"dadao5",
        ]));
        set("objects", ([
	__DIR__"npc/daotong" : 2 ]) );

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
