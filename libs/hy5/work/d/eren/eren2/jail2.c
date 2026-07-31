 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "哨房");
        set("long", @LONG
又是石壁上一块凹进的地方，约摸有两丈见方，点着一盏油灯，放着
几个木箱和一张床，地上胡乱丢着几柄长剑，看上去像个哨卡。四壁阴暗
潮湿，长满了青苔。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"jail1",
                "west" : __DIR__"jailroad2",
        ]));
        set("objects", ([
                __DIR__"npc/star_snake" : 1,
        ]) );
        set("item_desc", ([
        "青苔" : "暗色的青苔布满了洞壁。\n",
        "moss" : "暗色的青苔布满了洞壁。\n",
        "木箱" : "几个木箱堆起来，成了一张临时的桌子。\n",
        "box" : "几个木箱堆起来，成了一张临时的桌子。\n",
        "床" : "一张断了一条腿的木床，是守卫轮值休息时用的。\n",
        "bed" : "一张断了一条腿的木床，是守卫轮值休息时用的。\n",
    ]));
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
int valid_leave(object me,string dir)
{
        object alert_room,trap_room;
        object guard;   
        if(userp(me) && dir == "north") {
                if (!guard=present("bishe",this_object())) 
                        return 1;
           trap_room = find_object(__DIR__"underjail1");
                if(!objectp(trap_room))
                        trap_room = load_object(__DIR__"underjail1");
                message_vision(HIR"$N脚下突然出现了一个大洞。\n"NOR, me);
                message_vision(YEL"$N一个跟斗向洞里栽了下去。\n"NOR,me);
                message("vision",guard->query("name")+"说，哎呀，壮士小心。\n",this_object());
                me->move(trap_room);
                me-> unconcious();
                return notify_fail("\n");       
        }
        return 1;
} 
