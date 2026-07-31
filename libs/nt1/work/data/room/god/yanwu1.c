// SN:2h\B]OiKP5lN5YWB
// File(/data/room/god/yanwu1.c) of god's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "‘∆∫£—›Œ‰Ã¸");
	set ("long", @LONG
[1;31m’‚ «‘∆∫£µƒ—›Œ‰Ã¸£¨”– ±”––©Ω≠∫˛≈Û”—¿¥ª·£¨œÎ“ª ‘…Ì ÷£¨æÕ‘⁄
    ’‚¿Ô±»Œ‰Ωœ¡ø°£[2;37;0m
LONG );

	set("exits", ([
                "west" : __DIR__"yishiting",
	]));

        set("objects", ([
                "/clone/weapon/zhubang" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/mudao"   : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "…œµ€");
        set("room_name", "‘∆∫£");
        set("room_id", "god");
        set("room_owner_id", "god");
        set("room_position", "√˚»ÀÃ√");
}
