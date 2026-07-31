// ³şÖİº«ĞÅìô¿ /d/city/chuzhou/hanxin_ci.c
// by lala, 1997-12-05

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", WHT"º«ĞÅìô"NOR);
    set("long", @LONG
³şÖİÎª¹ÅÊ±¡°ĞËººÈı½Ü¡±Ö®Ò»µÄº«ĞÅ¹ÊÀï£¬ËùÒÔÕâÀï½¨ÓĞìôÌÃ¼ÍÄîËû¡£´óµî
ÕıÖĞº«ĞÅÈÖ×°ÕÌ½£¶øÁ¢£¬Ó¢Æø±ÆÈË¡£ÉÏ·½Ğü¹Ò×ÅÒ»¿é½ğ×Ö´óØÒ(sign)£¬ÅÔ±ß¸ßĞü
×ÅÒ»¸¶¶ÔÁª(duilian) £¬ÕıÊÇ¶Ôº«ĞÅÒ»ÉúµÄÉú¶¯ÆÀ¼Û¡£
LONG
    );
    set("no_kill",  "yangzhou");
    set("detail", ([
        "sign"  : YEL@LONG

              ¹ú  Ê¿  ÎŞ  Ë«
            
LONG
        NOR,
        "duilian"   : @LONG
        
            ´æ              Éú
            Íö              ËÀ
            Á½              Ò»
            ¸¾              Öª
            ÈË              ¼º
        
LONG
    , ]));        
        
    set("exits", ([
        "north"      : __DIR__"yanxing_jie",
    ]));
    set("objects", ([
        __DIR__"npc/youke"  :   random(4),
    ]));
    setup();
}

    