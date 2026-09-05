// book0.c
// modified by iszt@pkuxkx, 2007-02-09

inherit ITEM;

int do_study(string arj);

void create()
{
        set_name("达摩心经", ({"damo xinjing", "xinjing", "jing"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是达摩老祖多年研究佛法的心血，整本书是用梵文写的。\n");
                set("value", 10000);
        set("material","paper");
        }
        setup();
}

void init()
{
        add_action("do_study", "study");
        add_action("do_study", "du");
}

int do_study(string arg)
{
        object me = this_player();
        int times;
	string my_id;

	if(!arg || (sscanf(arg, "%s for %d", my_id, times) != 2 || !id(my_id)))
                return notify_fail("你想读什么？\n");

        if(!times)
                times = 1;
        if(times > 50)
                return notify_fail("学习次数不能超过五十次。\n");

        if( (int)me->query_skill("fanwen",1)<1)
        {
                write("你不懂梵文，无法领悟上面的东西。\n");
                return 1;
        }
        if ((int)me->query("jing") > 35 * times)
        {
                me->add("jing", -35*times);
                if ((int)me->query_skill("buddhism",1) <150)
                {
                        if(!random(4))
                                message_vision("$N正专心的研读达摩心经。\n", me);
                        me->improve_skill("buddhism", (int)me->query_skill("fanwen",1)/5*times+1);
                        write("你对达摩心经研读了一会，似乎有所心得。\n");
                }
                else
                {
                        write("你对达摩心经研读了一会，发现上面的太过浅薄，对你毫无意义。\n");
                }
                return 1;
        }
        else 
        {
                write("你现在有些疲倦，无法专心下来研读新知。\n");
        }
        return 1;
}
