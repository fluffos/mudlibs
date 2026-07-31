// SN:@WI20glX1hom<j7D
// File(/data/room/peiyu/zuowei.c) of peiyu's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        object ob;

        set("short", "杀人山庄左卫舍");
	set ("long", @LONG
这里是左卫舍，是看护杀人山庄大门的家丁放哨的地方。 
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

        set("room_owner", "俞佩玉");
        set("room_name", "杀人山庄");
        set("room_id", "peiyu");
        set("room_owner_id", "peiyu");
        set("room_position", "南海之滨");
}
