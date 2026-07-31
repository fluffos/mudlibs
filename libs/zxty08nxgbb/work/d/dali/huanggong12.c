// Room: /d/dali/huanggong12.c
// Data: ¹şµÏË¹(hades)
// Time: ¹«Ôª£º1999Äê4ÔÂ18ÈÕ£¬±±¾©Ê±¼ä£º21Ê±27·Ö26Ãë¡£

inherit ROOM;

void create()
{
	set("short", "[1;33mÓùÊé·¿[2;37;0m");
	set("long", @LONG
ÕâÀïÊÇ»Ê¹¬µÄÓùÊé·¿¡£´óÀí¹úÈËÈËĞÅ·î·ğ½Ì£¬Êé·¿ÄÚÒ²²»·¦
·ğ¼Ò¾­µä¡£ÓÉÓÚ´óÀí¶ÎÊÏÊÀ´úÏ°Îä£¬ÕâÀïÒ²ÊÕ²ØÁË´óÀí¶ÎÊÏµÄ²»
ÉÙÎä¹¦ÃØÒª¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"huanggong10",
]));

	setup();
}

