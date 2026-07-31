// Room: /u/wsl/changan/ta2.c
// This is a room made by Wsl.

inherit ROOM;

void create()
{
	set("short", "[1;37m´óÑãËş[2;37;0m");
	set("long", @LONG
ÌÆÓÀ»ÕÈıÄê£¬Ê¥É®ĞşŞÊÎª±£»¤·ğ¼Ò¾­Êé£¬ÓÉÌÆ¸ß×Ú×ÊÖú½¨³É´ËËş
¡£¡¶Èı²Ø·¨Ê¦´«¡·¾íÈıÖĞ¼ÇÔØ£ºÄ¦½Ò¹úÓĞÒ»ËÂ£¬Ò»ÑãÀëÈºÂäÓğ£¬Ë¤ËÀ
µØÉÏ£¬É®ÒÔÎªÑã¼´ÆĞÈø£¬½¨Ëş¼ÍÄî£¬¹ÊÃû´óÑãËş¡£
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"ca34",
]));

	setup();
	replace_program(ROOM);
}
