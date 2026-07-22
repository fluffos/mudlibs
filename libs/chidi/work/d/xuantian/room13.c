// xuantian  by:pipip
inherit ROOM;
string* npcs = ({
        __DIR__"npc/shou",

});

void create()
{
        set("short", "石道");
        set("long", @LONG
你走进这灯光昏暗的石头小道里，四周传来些奇怪的吼声。
LONG
        );
        set("exits", ([
              "east" : "d/xuantian/room7",
              "north" : "d/xuantian/room6",
              "south" : "d/xuantian/room2",
              "west" : "d/xuantian/room14",
        ]));
        set("objects", ([
                npcs[random(sizeof(npcs))] : 2,

        ]));
    

        setup();
}
void init()
{
    this_player()->receive_damage("qi", 35);
    this_player()->receive_wound("qi",  35); 
    this_player()->apply_condition("fire_poison", 300);    message_vision(RED"$N只觉得空气越来越热，呼吸越来越难。\n"NOR, this_player());
}

int valid_leave(object me, string dir)
{
        if (  (dir != "up")
           && ((string)me->query("family/master_id") != "wuming laoren")
           && objectp(present("shou", environment(me))) )
         return notify_fail
               ("几只怪兽迅速的包围了你，你顿时陷入苦战中！！\n");
        return ::valid_leave(me, dir);
}

