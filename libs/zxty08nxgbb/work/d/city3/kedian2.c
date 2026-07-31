// bye enter 

inherit ROOM;

void create()
{
        set("short", "客店二楼");
        set("long", @LONG
你正走在客店二楼的走廊上，可以听到从客房里不时地呼呼的打酣声，
一阵高过一阵。不时有睡意朦胧的旅客进进出出，到楼下的掌柜处付了钱
再上来睡觉。
LONG
        );

        set("exits", ([
                "down" : __DIR__"kedian",
                "1" : __DIR__"kefang1",
                "2" : __DIR__"kefang2",
                "3" : __DIR__"kefang3",
                "4" : __DIR__"kefang4",
                "5" : __DIR__"kefang5",
        ]));


        setup();
}

void init()
{
       this_player()->delete_temp("rent_paid");
}
