// Room: /u/wsl/changan/ta1.c
// This is a room made by Wsl.

inherit ROOM;

void create()
{
	set("short", "[1;37mĞ¡ÑãËş[2;37;0m");
	set("long", @LONG
Ğ¡ÑãËş½¨ÓÚ¾°ÁúÄê¼ä£¬Òò±È´óÑãËşĞ¡£¬¹Ê³ÆĞ¡ÑãËş¡£Ëş¸ß15¼¶
£¬Ë«ËşÁ¬ÀíÎªÒ»Ëş£¬ĞÎÌåĞãÀöÃÀ¹Û¡£
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"ca34",
]));

	setup();
	replace_program(ROOM);
}
