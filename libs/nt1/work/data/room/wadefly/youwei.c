// SN:aCnKm7VkLI@MXcJ7
// File(/data/room/wadefly/youwei.c) of wadefly's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        object ob;

        set("short", "黯幽灵右卫舍");
	set ("long", @LONG
这里是右卫舍，是看护黯幽灵大门的家丁放哨的地方。 
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

        set("room_owner", "黯幽灵");
        set("room_name", "黯幽灵");
        set("room_id", "wadefly");
        set("room_owner_id", "wadefly");
        set("room_position", "碎石小道");
}
