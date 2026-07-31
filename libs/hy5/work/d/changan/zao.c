// Room: /u/wsl/changan/zao.c
// This is a room made by Wsl.

inherit ROOM;

void create()
{
	set("short", "[31mÔæÊ÷ÁÖ[2;37;0m");
	set("long", @LONG
Äã×ßÔÚÒ»ÌõÓÄ¾²µÄÇàÊ¯Ğ¡ÏïÖĞ£¬ÏïÁ½±ßÖÖ×ÅÒ»ĞĞÔæÊ÷¡£²»ÁÏ·±»ª
µÄ³¤°²³ÇÄÚÒ²ÓĞÈç´ËÓÆÈ»È¥´¦¡£Ò»ÕóÔæÏã¡¢Ò»Ë¿²èÒâ¡¢Ò»ÉùË¿ÖñÈçÔ¶
´¦¸ßÂ¥µÄ¸èÉù£¬ÒşÒşÆ®À´¡£
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ca17",
]));

	setup();
	replace_program(ROOM);
}
