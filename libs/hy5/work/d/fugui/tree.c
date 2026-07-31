 inherit ROOM;
void create()
{
        set("short", "楠木树上");
        set("long", @LONG
从这里往四周看，吉祥镇的一切都尽揽眼底。树下似乎是个院子。
LONG
        );
        set("outdoors", "fugui");
        set("objects", ([
                __DIR__"npc/bird":2,
        ]) );
        set("exits", ([ 
                "down" : __DIR__"shilu1",
        ]));
        set("item_desc", ([
        "树": "树叶挡住了你的视线，树下似乎是个院子。\n",
        "tree": "树叶挡住了你的视线，树下似乎是个院子。\n",
        "院子": "树叶挡住了你的视线，只能施展轻功撞撞运气了。（ｊｕｍｐｔｏ）\n",
        "yard": "树叶挡住了你的视线，只能施展轻功撞撞运气了。（ｊｕｍｐｔｏ）\n",
        ]) );
    set("coor/x",-570);
        set("coor/y",90);
        set("coor/z",10);
        setup();
} 
void init ()
{
        add_action ("do_jumpto", "jumpto");
} 
int do_jumpto (string arg)
{
        object me,room;
        int dodge;
        if (!arg || (arg != "yard" && arg != "院子"))
                return notify_fail("你要向哪里跳？\n");
        me = this_player();
        dodge = me->query_skill("dodge",1);
        message_vision("\n$N横下心来，闭上眼睛，猛地向外跳了出去....\n",me); 
        if(!room)
           room = find_object(__DIR__"jinyuan");
                room=load_object(__DIR__"jinyuan");
        if (dodge < 50)
        {
                message_vision("\n只听一阵衣衫撕裂和树枝折断的声音，然后$N重重地摔到了地上...\n\n",me);
                me->move(room);
                me->unconcious();
        }
        else
        {
                message_vision("\n$N借着树枝反弹之力，飞越了丛丛树叶，一下跳进了金府大院。\n\n",me);
                me->move(room);
                me->start_busy(1);
        }
        return 1;
} 
