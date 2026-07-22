// Room: /city/wumiao.c
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "ÎäÃí");
    set("long", @LONG
ÕâÀïÊÇÔÀÍõÃíµÄÕıµî£¬ÄÚÓĞÔÀ·ÉÏñ£¬ÏñÉÏ·½Ğü¹ÒÔÀ·ÉÊÖÊé¡°»¹ÎÒºÓÉ½¡±µÄ
ºáØÒ¡£µîÁ½²à±ÚÉÏÇ¶×Å¡°¾¡ÖÒ±¨¹ú¡±ËÄ¸ö´ó×Ö¡£ÎäÈËµ½´Ë£¬¶¼·ÅÏÂÎäÆ÷£¬±Ï¹§
±Ï¾´µØÉÏÏãÀñ°İ¡£ÅÔ±ßËÆºõÓĞÒ»µÀ²àÃÅ¡£

                           [1;31mÔÀÍõÃí[2;37;0m

LONG
    );

    set("exits", ([
        "east" : __DIR__"beidajie2",
    ]));
        setup();
}
//ÊÇ¾µÏñ
int is_mirror() { return 1; }