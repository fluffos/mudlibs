// Room: /d/dali/huanggong1.c
// Data: ¹şµÏË¹(hades)
// Time: ¹«Ôª£º1999Äê4ÔÂ18ÈÕ£¬±±¾©Ê±¼ä£º21Ê±39·Ö13Ãë¡£

inherit ROOM;

void create()
{
	set("short", "[1;33mÊ¥´È¹¬[2;37;0m");
	set("long", @LONG
Ê¥´È¹¬ÊÇ´óÀí»Ê¹¬µÄÇ°µî£¬µîÉÏÖìÁºÓñÖù£¬ÁúÅÌ·ïÎè£¬»­¶°µñÀ¸£¬
ÇÉ¶áÌì¹¤¡£´óµîÉÏ¹Ò×ÅÒ»·ùÄÏÌÆÀîºóÖ÷»æµÄ¡¸ÁÖÈª¶ÉË®ÈËÎï¡¹¡£·ÅÑÛ
ÍûÈ¥£¬¹¬ÖĞ½ğµîÁÖÁ¢£¬½ğ±Ì»Ô»Í¡£
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"paifang",
  "north" : __DIR__"huanggong2",
]));

	setup();
}

