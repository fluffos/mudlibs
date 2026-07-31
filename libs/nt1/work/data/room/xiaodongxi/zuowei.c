// SN:aPPC3E8AD;PHj8^Y
// File(/data/room/xiaodongxi/zuowei.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        object ob;

        set("short", "°®µÄÐ¡ÎÝ×óÎÀÉá");
	set ("long", @LONG
°®µÄÐ¡ÎÝ×óÎÀÉáÊØ»¤´óÃÅµÄ¼Ò¶¡¾Ó×¡µÄµØ·½[2;37;0m
LONG );

	set("exits", ([
                "west"   : __DIR__"qianting",
	]));

        set("objects", ([
                "/d/room/roomnpc/shouwei" : 2,
        ]));

        set("no_sleep_room", 1);
        setup();

        ob = present("shou wei", this_object());
        ob->set("coagents", ({
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 1" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 1" ]),
        }));

        ob = present("shou wei 2", this_object());
        ob->set("coagents", ({
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 1" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 1" ]),
        }));

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄÐ¡ÎÝ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ð¡µÀ");
}
