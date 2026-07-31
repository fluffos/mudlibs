inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "¶É´¬");
        set("long",
"[1;32mÒ»Ò¶Ğ¡ÖÛ£¬×î¶àÒ²¾ÍÄÜÔØÆß¸öÈË¡£Ò»Ãû¾«Áé×åµÄÀÏô¹¹«£¬ÊÖ\n"
"³Ö³¤Öñ¸İ£¬ÕıÔÚ´¬Î²³ÔÁ¦µØ³Å×Å´¬¡£\n"
);
        set("no_clean_up", 0);
        set("no_magic", 1);
	setup();
        replace_program(ROOM);
}

