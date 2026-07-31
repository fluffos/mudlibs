// SN:PGT`AoJAkjZRL4CH
// File(/data/room/lingling/xiaoyuan.c) of lingling's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "ôáÇä¾ÓĞ¡Ôº");
	set ("long", @LONG
[1;36mÎí½¥½¥Å¨ÁËÆğÀ´£¬Æéá«µÄÂ·ÃæÈÃÈË²»Ò×Í¨¹ı£¬ÔÙ¼ÓÉÏÅ¨Îí·Á
    °­ÁËÊÓÏß£¬×ßµ½ÖøÀïÖ»ºÃÒ»²½Ò»²½Ğ¡ĞÄÒíÒíµÄÂıÂıÇ°½ø£¬²»
    È»Ò»¸ö²»Ğ¡ĞÄ¾Í»áµø¸ö¹·³ÔÊºÂŞ¡£ĞÄÀïÕıÔÚÖäÂîÖøÂ·ÄÑĞĞµÄ
    Ê±ºò£¬Í¸¹ıÎíÆøÑÛÇ°ËÆºõ³öÏÖÁË¼äĞ¡Ğ¡Ä¾Îİ¡£[2;37;0m
LONG );

        set("room_key", "1 of lingling");
	setup();

	set("exits", ([
                "out"    : "/d/hangzhou/shanlu7",
	]));

        set("outdoors", "hangzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "Ä½Èİôá");
        set("room_name", "ôáÇä¾Ó");
        set("room_id", "ling");
        set("room_owner_id", "lingling");
        set("room_position", "É½Â·");
}
