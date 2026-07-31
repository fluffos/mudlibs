// SN:K@omaYKG;b?QDeo:
// File(/data/room/hyber/youwei.c) of hyber's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        object ob;

        set("short", "龙腾虎啸右卫舍");
	set ("long", @LONG
这里是右卫舍，是看护龙腾虎啸大门的家丁放哨的地方。 
LONG );

	set("exits", ([
                "east"   : __DIR__"qianting",
	]));

        set("objects", ([
                "/d/room/roomnpc/shouwei" : 2,
        ]));

        set("no_sleep_room", 1);
        setup();

        ob = present("shou wei", this_object());
        ob->set("coagents", ({
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 1" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 1" ]),
        }));

        ob = present("shou wei 2", this_object());
        ob->set("coagents", ({
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 1" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 1" ]),
        }));

        set("room_owner", "风雷");
        set("room_name", "龙腾虎啸");
        set("room_id", "long");
        set("room_owner_id", "hyber");
        set("room_position", "碎石小道");
}
