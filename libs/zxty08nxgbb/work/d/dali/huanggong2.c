// Room: /d/dali/huanggong2.c
// Data: ¹şµÏË¹(hades)
// Time: ¹«Ôª£º1999Äê4ÔÂ18ÈÕ£¬±±¾©Ê±¼ä£º21Ê±27·Ö26Ãë¡£

inherit ROOM;

void create()
{
	set("short", "[1;33mÀöÕıÃÅ[2;37;0m");
	set("long", @LONG
ÕâÀïÊÇ´óµîÇ°µÄÀöÕıÃÅ¡£·ÅÑÛÍûÈ¥£¬µ«¼û½ğ¶¤Öì»§£¬»­¶°µñÁº£¬
Îİ¶¥¾¡¸²Í­Íß£¬ïÔïÎÁú·ï·ÉÏâÖ®×´£¬Î¡¶ë×³Àö£¬¹âÒ«ÒçÄ¿¡£½ûÒÂÎÀÒÂ
¼×ÏÊÃ÷£¬À´»ØÑ²ÊÓ¡£
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huanggong1",
  "north" : __DIR__"huanggong3",
]));

	setup();
}

