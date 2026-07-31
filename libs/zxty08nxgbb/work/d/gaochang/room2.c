// Room: /u/mei/room2.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "Èû¿Ú");
	set("long", @LONG
ÕâÀïÊÇÖĞÔ­ÈëÎ÷ÓòµÄ±Ø¾­Ö®Â·£¬´óÅúµÄÉÌÈËÍÒ¶Ó¶¼Ò»¶¨Òª´ÓÕâÀï¾­¹ı£¬
ĞÎ³ÉÁËÕâÀïµÄ»ûĞÎÂ·Èİ¡£ÏòÎ÷Äã¿ÉÒÔ¿´µ½Ò»¶ÎÆÆ¾ÉµÄ³¤³Ç£¬ÉÏÃæºÃÏó»¹ÓĞ±»
ÍÁÅÚºä¹ıµÄºÛ¼££¬Ïò±±ÊÇÒ»¼ÒĞ¡µê¡£Ò»¿é¡°[1;37mÁúÃÅ¿ÍÕ»[2;37;0m¡±µÄÄ¾°åÕĞÅÆ¹ÂÁãÁãµÄ
ÔÚº®·çÖĞÒ¡Ò·¡£
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room3",
  "north" : __DIR__"room16",
  "east" : __DIR__"room1",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room2");

	setup();
	replace_program(ROOM);
}
