inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "µþáÖ·å");
        set("long",
"[1;32mÕâÀïÈº·åµþáÖ£¬¶¼ÊÇÒ»¸ù¶ø³ö£¬¿´ËÆÈº·å£¬Ò²ÄÑËµÇå¾¿¾¹¸Ã\n"
"ÓÐ¶àÉÙ¡£È»¶ø£¬É½·åËäÖÚ£¬È´Î¨´ËÒ»·å¶À×ð¡£Ò»ÖêÆæÒìµÄÐ¡²Ý³¤ÔÚÉ½·å¾ø\n"
"¸ßÖ®´¦£¬ÈðÆøÏéÔÆ½ÔÓÉ´Ë¶øÀ´¡£\n"
);
        set("exits", ([ 
             "down" : __DIR__"mountain",
]));
        set("objects", ([ 
        "/quest/tulong/obj/drug1" : 1,
        "/quest/tulong/npc/spirit2" : 1,
                        ]) );
        set("no_magic", 1);
	setup();
//      replace_program(ROOM);
}

void grass_grow()
{
        object grass;
        seteuid(getuid());
        if(grass=new("/quest/tulong/obj/drug1")){
                grass->move(this_object());
                grass->invocation();
        }
        return;
}

