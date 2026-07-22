//bye enter 

inherit ROOM;

void create()
{
        set("short", "客房");
        set("long", @LONG
这是一间假日客店的客房，这里的开房率向来很高，对面
有个窗户，通过那里，可以看见街上热闹的情景，床铺看起来
很干净，被子是新换的，看着就让人想睡觉。
LONG
        );

        
        set("sleep_room", "1");
        set("no_fight", "1");
        set("hotel",1);

        set("exits", ([
                "out" : __DIR__"kedian2",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "out" ) me->delete_temp("rent_paid");

        return ::valid_leave(me, dir);
}

