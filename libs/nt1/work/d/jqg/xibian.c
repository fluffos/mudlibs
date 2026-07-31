// river.c 溪流
#include <room.h>
inherit ROOM;
void create()
{
        set("short","小溪边");
	set("long",@LONG
你沿着山路前行数里，来到一条溪边。朝阳初升，照得碧玉般的水面上犹
如镶了一层黄金一般，壮丽无比，你站在这里，心中什么也不愿意想，只希望
就这样天长地久，时间永恒。
LONG
);
        set("outdoors","襄阳");

        set("exits",([ 
	    "south": __DIR__"shanlu1",
        ]));

	setup();
}

void init()
{
        add_action("do_look","look");
        add_action("do_jump",({"tiao", "jump", "yue"}));
}

int do_look(string arg)
{
        object me,room;
        me = this_player();
        if(!( room = find_object(__DIR__"boat")))
          room = load_object(__DIR__"boat");
        if ( room->query("ppl") > 0){
        set("long", @LONG
你沿着山路前行数里，来到一条溪边。朝阳初升，照得碧玉般的水面上犹
如镶了一层黄金一般，壮丽无比，你站在这里，心中什么也不愿意想，只希望
就这样天长地久，时间永恒。
LONG
);
        me->look(arg);
        }
        else {
        if (!arg) {
        set("long", @LONG
你沿着山路前行数里，来到一条溪边。朝阳初升，照得碧玉般的水面上犹
如镶了一层黄金一般，壮丽无比，你站在这里，心中什么也不愿意想，只希望
就这样天长地久，时间永恒。你沿岸迂回数次，发现溪中好象有艘小舟。
LONG
        );
        me->look(arg);
        }
        else if(arg == "boat" || arg == "zhou") {
          write("一叶小舟，飘飘忽忽地随着溪流而晃来晃去。\n");
          me->set_temp("jqg/look", 1);
          return 1;
          }
       }                
}

int do_jump(string arg)
{
        object me,room,*ob;
        int i;
        me = this_player();
        if(!( room = find_object(__DIR__"boat")))
          room = load_object(__DIR__"boat");
        if( !me->query_temp("jqg/look")) return 0;
        if( !arg ||(arg != "boat" && arg != "zhou")) 
            return notify_fail("你要往哪里跳？\n");
        if( arg =="zhou" || arg=="boat"){
        if( me->query_skill("dodge" ,1) < 100)
            return notify_fail("你只觉得力不从心，凭现在的轻功很难跃上远处的小舟。\n");
        ob = deep_inventory(me);
        i = sizeof(ob);
        while (i--)
        if (ob[i]->is_character())
            return notify_fail("你身上背负一个人，看来无法轻松地跃上远处的小舟。\n");    
        tell_object(me,"你吸了口气，纵身向小舟上跳将过去。\n");
        tell_room(environment(me), me->name() + "纵身往小舟上跳将过去。\n", ({ me }));
        room->add("ppl", 1);
        me->delete_temp("jqg");
        me->move(__DIR__"boat");
        tell_object(me,"你屏气凝神，稳稳地站落在小舟之上。\n");
        return 1;
        }
}
