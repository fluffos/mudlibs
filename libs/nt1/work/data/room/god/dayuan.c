// SN:8<K2ZLdDMXeBSWPa
// File(/data/room/god/dayuan.c) of god's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "ÔÆº£´óÔº");
	set ("long", @LONG
[1;31mÕâÊÇÉÏµÛ¾Ó×¡µÄµØ·½[1;32mËÄÖÜ¿´ÆðÀ´ÔÆÎíÃÖÃÉ£¬¿´²»ÇåÄÄÀïÊÇ±ßÔµ£¬´«ËµÉÏ

µÛ¾­³£ÐÝÏ¢µÄµØ·½£¬²»¹ýÃ»ÓÐÈË¿´¼û¹ýËûµÄµ½À´ºÍÀëÈ¥¡£Èç·çÒ»ÑùÀ´£¬Èç·çÒ»

ÑùÈ¥¡£[2;37;0m
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/city/mingren",
	]));

        set("outdoors", "unknow");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "ÉÏµÛ");
        set("room_name", "ÔÆº£");
        set("room_id", "god");
        set("room_owner_id", "god");
        set("room_position", "ÃûÈËÌÃ");
}
