// SN:F=]>_UdDVZQ::C:`
// File(/data/room/xiaodongxi/lianwu.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "Á·Îä³¡");
	set ("long", @LONG
´Ë´¦±ãÊÇÁğÁ§¾ÓµÄÁ·Îä³¡£¬Ê±¶ø¸¡³ö½­ºşµÄĞ¡Ì«±££¬ÊÇÉîÖª¡°Îä
¹¦ÍòÍò²»¿É»Ä·Ï¡±µÄµÀÀí¡£±øÆ÷²¢ÎŞÍâÂ¶£¬Éî¸½ÔÚÇ½±ÚÀïÃæ£¬°¼Ïİ½ø
È¥¡£Äã²»ÓÉµÃÎªÕâÒ»¾«ÖÂµÄÏë·¨,°µ°µ½ĞºÃ¡£[2;37;0m
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
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
