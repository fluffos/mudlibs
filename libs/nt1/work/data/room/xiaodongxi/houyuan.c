// SN:5J>Y1kS\^RF\0Be>
// File(/data/room/xiaodongxi/houyuan.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "ºóÔº");
	set ("long", @LONG
ÕâÊÇ°®µÄĞ¡ÎİµÄºóÔº£¬ÕıÖĞÒ»¸ö¼ÙÉ½£¬°ÁÈ»¶øÁ¢¡¢·Ç³£ĞÛÎ°¡£ÏÂ
ÓĞÒ»Ë®³Ø£¬»·É½¶ø×ß£¬ÓÆÈ»²»Ï¢¡£¶«ÃæÄËÊÇÁ·ÎäÖ®´¦£¬Î÷ÃæÊÇÓ¶ÈËÃÇ
×¼±¸Ê³ÎïµÄ³ø·¿¡£[2;37;0m
LONG );

	set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄĞ¡Îİ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}
