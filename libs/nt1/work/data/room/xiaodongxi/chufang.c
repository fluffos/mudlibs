// SN:ZjoNI`^D?gN6b_0Z
// File(/data/room/xiaodongxi/chufang.c) of xiaodongxi's room
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
´ó·²·òÐ¡Ë××Ó,×ÔÈ»ÒªÊ³ÈË¼äÑÌ»ð¡£·Çµ«Èç´Ë,Å®Ö÷ÈËÃ¼Ã¼»¹ÊÇÐ¡
²ö×ì,ºÞ²»µÃ³Ô±éÌìÉÏÈË¼äµØÏÂ!´Ë´¦±ãÊÇ°®µÄÐ¡ÎÝµÄ³ø·¿£¬Îä¹¦ÔÙ¸ß
ÖÕ¾¿Ò²²»ÄÜ±Ù¹È£¬·¹×ÜÊÇÒª³ÔµÄ¡£[2;37;0m
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

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄÐ¡ÎÝ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ð¡µÀ");
}
