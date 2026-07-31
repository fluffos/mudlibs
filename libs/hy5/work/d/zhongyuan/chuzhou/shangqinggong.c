// ³şÖİÉÏÇå¹¬¿ /d/city/chuzhou/shangqinggong.c
// by lala, 1997-12-06

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", WHT"ÉÏÇå¹¬"NOR);
    set("long", @LONG
ÉÏÇå¹¬ÕæÊÇÒ»×ùÏã»ğ¶¦Ê¢µÄ´óµÀ¹Û¡£ÕâÀïÃ¿Ìì¶¼ÓĞ³É°ÙÉÏÇ§µÄÈËÇ°À´ÎÊ¼ªĞ×£¬
Çó±£ÓÓ¡£ÄÇĞ©´ó²ÆÖ÷ÃÇÍùÍùÒ»³öÊÖ¾ÍÊÇÉÏÇ§ÉÏÍòÒø×ÓµÄ¾èÔù£¬ËùÒÔ¹ÛÀïÃæµÄµÀÊ¿
Ò²Ò»¸ö¸ö´º·çµÃÒâ¡£²»¹ı¾İËµÕâÀïµÄÌì×ğÕæµÄÊ®·ÖÁéÑé£¬¶øÕâÀïµÄµÀÊ¿ËãÃü¸üÊÇ
Ê®¶ş·ÖµÄ×¼¡£
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "west"      : __DIR__"qingyun_lu",
    ]));
    set("objects", ([
        __DIR__"npc/daoshi" :   1,
        __DIR__"npc/daoshi2":   1,
    ]));
    setup();
}

    