// Room: /u/xiaozhen/yidao1.c

inherit ROOM;

void create()
{
	set("short", "´óæäµÀ");
	set("long", @LONG
ÕâÊÇÒ»Ìõ³¾ÍÁ·ÉÑïµÄ´óæäµÀ£¬Â·ÉÏÈËÀ´ÈËÍù¡£Ìôµ£×ÓµÄ¡¢ĞĞ
ÉÌµÄ¡¢¸Ï×Å´ó³µµÄÂí·ò£¬ÂçÒï²»¾ø£¬Â·±ß»¹ÓĞÒ»Ğ©Ğ¡ÉÌ··ÔÚ½ĞÂô£¬
·Ç³£ÈÈÄÖ¡£²»Ê±»¹ÓĞÁ½ÈıÆï¿ìÂí±ß·É³Û¶ø¹ı£¬ÑïÆğÒ»Â·³¾°£¡£ÄÏ
ÃæÊÇÌìË®Õò£¬Íù±±Ò»Ö±×ß¾ÍÊÇ±ß¹Ø´óÓª¡£Ì
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yidao2",
  "south" : "/d/huanghe/tumenzi",
]));

        set("objects",([
        __DIR__"npc/scholar" :1,
]));
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
