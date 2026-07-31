// Room: /d/dali/huanggong18.c
// Data: ¹şµÏË¹(hades)
// Time: ¹«Ôª£º1999Äê4ÔÂ18ÈÕ£¬±±¾©Ê±¼ä£º21Ê±27·Ö26Ãë¡£

inherit ROOM;

void create()
{
	set("short", "[1;33mÓù³ø·¿[2;37;0m");
	set("long", @LONG
ÕâÀïÊÇÕ¹ÖĞÊ¡ËùÊôµÄÓù³ø£¬³øÖĞÖò»ğÍ¨Ã÷£¬¼¸¸ö³ø×ÓÕıÃ¦×ÅÎª
¹¬ÖĞ×¼±¸Íí²Í¡£¿´×ÅÂúÎİµÄÂúÎ¶¼ÑëÈ£¬Äã²»ÓÉÒ²Ïë½Ğ(serve) Ò»·İ
·¹²Ë¡£
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"huanggong16",
]));

	setup();
}

