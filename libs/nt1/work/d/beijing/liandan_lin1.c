#include <ansi.h> 
inherit ROOM;
int do_cai(string arg);

void create()
{
        set("short", "城西后林");
        set("long", @LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼
天大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发
出的声响。
LONG );
        set("exits", ([
                "south" : __DIR__"ximenwai",
                "north" : __DIR__"liandan_lin3",
                "east" : __DIR__"liandan_lin5",
                "west" : __DIR__"liandan_lin4",
        ]));

        set("no_clean_up", 0); 
        setup();       
}
void init()
{
        add_action("do_cai","cai");
}

int do_cai(string arg)
{
        object me=this_player();
        object ob;
        object ob1;
        if ( (int)me->query_temp("caiyao")<1)
                return notify_fail("别在这浪费时间了，快走吧。\n");

        if (!arg || arg != "yao")
                return notify_fail("你要采什么。\n");

        if ( me->is_busy() )
                return notify_fail("慢慢找，先别急。\n");
       
        if ( (int)me->query("jing")<40)
                return notify_fail("你太累了，休息下吧。\n");

        if ( (int)me->query("qi")<40)
                return notify_fail("你太累了，休息下吧。\n");

        if ( (int)me->query_temp("caiyao")==2)
                return notify_fail("东西到手，快去交了吧。\n"); 
        message_vision("$N趴在地上，瞪大了眼睛在草丛中找寻着药草，生怕漏掉了目标。\n",me); 
        remove_call_out("cai"); 
        call_out("cai", 5, me);
        me->start_busy(3); 
        return 1;
}
 
int cai(object me)
{ 
        object ob;
        object ob1;        
        if (random(10)<7)
        {
        me->receive_damage("jing",10+random(20));
        me->receive_damage("qi",10+random(20));   
        message_vision(CYN"一翻摸索后，草丛中似乎没有$N要找的东西，$N失望的叹了口气。\n"NOR,me);
        }

        if(random(6)==1) 
        {         
        tell_room(environment(me),HIR"草丛中一阵晃动，突然钻出一条毒蛇。\n"NOR );
        ob=new("/d/beijing/npc/liandan_dushe");
        ob->move("/d/beijing/liandan_lin1");
        }

   else if(random(6)==1) 
        {         
        tell_room(environment(me),HIR"林子后面突然跳出一个凶神恶刹的男子，手提一把短刀向你扑来！\n"NOR );
        ob=new("/d/beijing/npc/liandan_langzhong");
        ob->move("/d/beijing/liandan_lin1");
        }
   else
        { 
        ob1 = new("/d/beijing/npc/dan/caoyao");
        ob1->move(me);
        me->receive_damage("jing",10+random(20));
        me->receive_damage("qi",10+random(20));
        me->add_temp("caiyao", 1);
        message_vision(HIG"$N找了半天，终于发现其中一株草苗与其它的草略有不同，
小心翼翼地掘了出来。\n"NOR,me); 
        }
        return 1;
       
}
