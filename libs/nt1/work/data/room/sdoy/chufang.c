// SN:`2c:7mJbSY8iSTMf
// File(/data/room/sdoy/chufang.c) of sdoy's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

string *names = ({
	"/d/shaolin/obj/mala-doufu",
	"/d/shaolin/obj/bocai-fentiao",
	"/d/shaolin/obj/shanhu-baicai",
	"/d/shaolin/obj/liuli-qiezi",
	"/d/shaolin/obj/mizhi-tianou",
	"/d/shaolin/obj/jiaxin-biji",
	"/d/shaolin/obj/basi-shanyao",
	"/d/shaolin/obj/furong-huagu",
});

void create()
{
	set("short", "³ø·¿");
	set ("long", @LONG
ÕâÀïÓÐ×Å×î´¿ÕýµÄÏç´åÁÏÀíÅ¶[2;37;0m
LONG );

	set("exits", ([
                "east" : __DIR__"houyuan",
	]));

        set("objects", ([
                names[random(sizeof(names))] : 1,
                names[random(sizeof(names))] : 1,
                names[random(sizeof(names))] : 1,
                "/d/room/roomobj/rice"  : 2,
                "/d/room/roomobj/soup"  : 2,
                "/d/room/roomobj/mantou": 3,
                "/d/room/roomnpc/puren" : 2 + random(3),
        ]));

        set("resource/water", 1);
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "ÎÞÃû");
        set("room_name", "´å¾Ó");
        set("room_id", "sdoy");
        set("room_owner_id", "sdoy");
        set("room_position", "Çà×©Â·");
}
