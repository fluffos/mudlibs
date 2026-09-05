// Room: /d/gumu/mishi.c 
// Modified by iszt@pkuxkx, 2007-04-02

inherit ROOM; 

void create() 
{
        set("short", "密室");
        set("long", @LONG
这里是一间密室，四周都是石壁，只有少许光亮。密室很大，密室顶(ding)
上密密麻麻地不知写着什么，似乎可以研读(study)。
LONG);
        set("no_fight", 1);
        set("item_desc", ([
                "ding" : "这个密室的顶很光滑，上面写着许多修炼内功的心法。\n",
        ]));
       
        set("exits", ([ /* sizeof() == 3 */
                "up" : __DIR__"guancai5",
                "east" : __DIR__"mudao15",
        ]));
}

void init()
{
        add_action("do_study","study");
}

int do_study(string arg)
{
        object me = this_player();
        int times;

        if(!arg || (sscanf(arg, "ding %d", times) != 1 && arg != "ding"))
        {
                write("指令格式：study ding <次数>\n");
                return 1;
        }
        if(!times)
                times = 1;
        if(times > 50)
        {
                write("学习次数不能超过五十次。\n");
                return 1;
        }
        if(me->is_busy())
        {
                write("你正忙着呢，还想研读石壁？\n");
                return 1;
        }
        if( me->query("jing") < 30*times )
        {
                write("你已经太累了，先休息一下吧。\n");
                return 1;
        }

        message_vision("$N正专心研读室顶上的文字。\n", me);
        if( (int)me->query_skill("force",1) < 20)
        {
                write("你内功不高，无法看清上面的字。\n");
                return 1;
        }
        if( (int)me->query("max_neili",) < 200)
        {
                write("你内力不够，不能看清上面的字。\n");
                return 1;
        }
        if (me->query("family/family_name") != "古墓派")
        {
                write("非古墓派弟子不能读此秘笈！\n");
                return 1;
        }

        if( (int)me->query_skill("jiuyin-shengong",1) < 100)
        {
                write("你的九阴神功根基太差，无法领会更高层次的功法。\n");
                return 1;
        }
        if( (int)me->query_skill("jiuyin-shengong",1)>200)
        {
                write("你读了半天，发现上面说的对你太浅了。\n");
                return 1;
        }
        if((int)pow((int)me->query_skill("jiuyin-shengong",1), 3)/10>me->query("combat_exp"))
        {
                write("你经验不够，无法继续读下去。\n");
                return 1;
        }
        else
        {
                message_vision("$N对着那些文字研读了一会，似乎有些心得。\n", me);
                me->add("jing",-30 * times);
                me->improve_skill("jiuyin-shengong",(int)((me->query_skill("literate")/5+1)*times));
                return 1;
        }
}

