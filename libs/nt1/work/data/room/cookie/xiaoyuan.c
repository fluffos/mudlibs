// SN:>XGT>Tf9\[O3TnCa
// File(/data/room/cookie/xiaoyuan.c) of cookie's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "ÌğÃÛÃÛĞ¡Ôº");
	set ("long", @LONG
ÈÎĞÔµÄÎÒ¿´×ÅÔÂÁÁÀ´ÁËÈ¥ÁË[2;37;0m
LONG );

        set("room_key", "1 of cookie");
	setup();

	set("exits", ([
                "out"    : "/d/xiakedao/xkroad3",
	]));

        set("outdoors", "xiakedao");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "ÖÓÇé");
        set("room_name", "ÌğÃÛÃÛ");
        set("room_id", "mylove");
        set("room_owner_id", "cookie");
        set("room_position", "Æ½Ô­Ğ¡Â·");
}
