// Room: /d/emei/jiudaoguai3.c 峨嵋派 九十九道拐3

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIW "树上" NOR);
        set("long", @LONG
一股腥臭之气扑面而来。你抬头一看，顿时毛骨悚然，一条碗口粗细的巨
蟒倒悬在树干上，张开大口，正要向你扑来！
LONG
        );
        set("exits",([
                "down" : __DIR__"jiudaoguai3",
]));
        set("objects",([
        __DIR__"npc/jumang" : 1,
]));
        set("outdoors", "峨嵋山");
        setup();
}

void reset()
{
        object room = this_object();
        object *ob;
        int i;
        
        ob = deep_inventory(room);
        if (!ob)
                return;
        for (i=0;i<sizeof(ob);i++)
        {
                if (userp(ob[i]) && !wizardp(ob[i]))
                {
                        tell_object(ob[i],"突然，一阵风吹过，树枝摇摇晃晃，你被吹落到了树下。\n");
                        ob[i]->move(__DIR__"jiudaoguai3");
                        tell_room(environment(ob[i]),"突然，一阵风吹过，"+ob[i]->name(1)+"从树上掉了下来。\n",({ob[i]}));
                        continue;
                }
        }
        
        ::reset();
}

void init()
{
        add_action("do_action", "");
}

int do_action(string arg)
{
        object me = this_player();
        string action = query_verb();

        switch (action)
        {
                case "dazuo":
                case "exercise":
                case "tuna":
                case "lian":
                case "practice":
                case "du":
                case "study":
                case "respirate":
                        message_vision("$N拉开架势，正欲练功，突然一个不小心，从树上掉了下去。\n",me);
                        me->move(__DIR__"jiudaoguai3");
                        tell_room(environment(me),"突然，一阵风吹过，"+me->name(1)+"从树上掉了下来。\n",({me}));
                        return 1;
        }
        return 0;
}
