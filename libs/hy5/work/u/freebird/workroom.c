#include <ansi.h>
inherit ROOM;

void create ()
{
set("short",HIR "[1;31m¡¼ÖĞ·«ÔÚÏß¹¤×÷ÊÒ¡½[2;37;0m"NOR);

set("long",@LONG
ÕâÀïÊÇÔÆÖĞ·«µÄ¼Ò,¿Õµ´µ´µÄ×ó±ßÓĞÒ»ÉÈĞ¡ÃÅ,¿´À´ÏóÊÇ¸öÊé·¿
ÀïÃæ°Ú×Å¼¸Ì¨¿ò×ÓÒ»ÑùµÄ¼Ò»ï,×ĞÏ¸Ò»¿´Ô­À´ÊÇP4·şÎñÆ÷,ÔÎµ¹
ÔÚµçÄÔÌ¨±ßÉÏ°Ú×ÅÒ»¸öö¦Å®µÄÏàÆ¬,²»ÓÃ¿´ÁËËû¼Ò±¦±¦À²,°¡¹ş.
LONG );

        set("exits",([ /* sizeof() == 1 */
                "gc":"/d/city/guangchang",        
               "down":"/d/wizard/wizard_room" ]));
        set("objects", ([
                "/u/freebird/yutu" : 2,
                "/u/freebird/thousand-gold" : 1,       
                "/u/freebird/msgd" : 1,        
        ]));

        set("valid_startroom", 1);
        set("no_suck", "1");
        set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
}