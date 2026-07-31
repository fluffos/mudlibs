// SN:h=8dJ2<E4Kn;FPH8
// File(/data/room/hongdou/xiaoyuan.c) of hongdou's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "²Ð°®¾ÓÐ¡Ôº");
	set ("long", @LONG
Ò»¸ö¿íÀ«µÄÔºÂä£¬ËæÒâµÄÖÖ×Å¼¸¸öÏàË¼Ê÷£¬Ñô¹âÕÕÏÂÀ´Í¸¹ýÊ÷Òñ
Í¶ÏÂ°ß²µµÄÓ°×Ó¡£²»ÉÙÊ÷Ä¾ÒÑÈ»³ÊÕÚÌìÖ®ÊÆ£¬ÄÜ¿´µ½Äñ¶ùµÄÉíÓ°£¬È´
Ìý²»¼ûßóßóÔûÔûµÄÃù½Ð.....±±ÃæÓÐÒ»ÉÈË®¾§ÃÅ½ô½ôµÄ¹Ø±Õ×Å¡£[2;37;0m
LONG );

        set("room_key", "1 of hongdou");
	setup();

	set("exits", ([
                "out"    : "/d/gumu/hanshuitan",
	]));

        set("outdoors", "gumu");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "ºì¶¹");
        set("room_name", "²Ð°®¾Ó");
        set("room_id", "xiaohan");
        set("room_owner_id", "hongdou");
        set("room_position", "º®Ë®Ì¶");
}
