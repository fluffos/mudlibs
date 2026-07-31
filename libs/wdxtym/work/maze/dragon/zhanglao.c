inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "³¤ÀÏÊÒ");
        set("long",
"[1;32mÕâÊÇ¾«Áé³¤ÀÏËùÔÚµÄ·¿¼ä£¬Ò»¸ö°×ºú×ÓµÄ¾«Áé×åÀÏÈËÕı×øÔÚ\n"
"´°Ç°³ÁË¼×ÅÊ²Ã´¡£\n"
);
        set("exits", ([ /* sizeof() == 4 */
   "west" : __DIR__"village",
   "southeast" : __DIR__"xiuxishi",
   ]));

        set("no_magic", 1);
	setup();
        replace_program(ROOM);

}

