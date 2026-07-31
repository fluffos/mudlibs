// SN:1BHnGQD^9i5?K7h^
// File(/data/room/xiaodongxi/zhulin.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "ÖñÁÖ");
	set ("long", @LONG
Ò»Æ¬´äÂÌµÄÖñÁÖ£¬·Ç³£ÓÄ¾²,·ç¶ùÒ»Æğ¾ÍÄÜÌıµ½ÖñÒ¶É³É³×÷Ïì¡£Ã¼
Ã¼²»¿ªĞÄµÄÊ±ºòÏ²»¶À´ÕâÀï£¬ÈÎÆ¾Î¢·ç´µ·÷×ÅÁ³ÅÓ£¬ËæÒâ·Å·É×Ô¼ºµÄ
Ë¼Ğ÷......[2;37;0m
LONG );

	set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄĞ¡Îİ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}
