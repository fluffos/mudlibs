// SN:^lSBbUC8T>a^YWF;
// File(/data/room/xiaodongxi/yanwu2.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "°®µÄĞ¡ÎİÑİÎäÌü");
	set ("long", @LONG
°®µÄĞ¡ÎİµÄÑİÎäÌü¡£ÓĞÊ±ÓĞĞ©Ä½Ãû¶øÀ´»òÕßĞîÒâÌôÕ½µÄ½­ºşÅóÓÑ
À´°İ»á£¬ÏëÒ»ÊÔÉíÊÖ£¬·Ö³ö¸ßÏÂ,±ãÔÚÕâÀï±ÈÎä½ÏÁ¿¡£[2;37;0m
LONG );

	set("exits", ([
                "east" : __DIR__"yishiting",
	]));

        set("objects", ([
                "/clone/weapon/zhubang" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/mudao"   : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄĞ¡Îİ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}
