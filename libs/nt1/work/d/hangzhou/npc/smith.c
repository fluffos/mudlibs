// smith.c

inherit NPC;
inherit F_DEALER;

string ask_me();
int do_gu(string arg);
int do_dapi(string arg);
int do_cuihuo(string arg);
void reward(object me);

void create()
{
        set_name("铁匠", ({ "tiejiang", "smith" }));
	set("title", "铁匠铺老板");
	set("shen_type", 1);

        set("gender", "男性" );
        set("age", 33);
        set("long", "铁匠正用铁钳夹住一块红热的铁块放进炉中。\n");

        set("combat_exp", 400);
	set("attitude", "friendly");
        set("vendor_goods",({
                   "/clone/weapon/changjian",
                   "/clone/weapon/hammer",
                   "/clone/weapon/tudao",
		   "/clone/weapon/dagger",
                   "/clone/weapon/tiegun",
                   "/clone/weapon/gangdao",
                   "/clone/cloth/tiejia",
        }));

        set("inquiry", ([
                "工作" : (: ask_me :),
                "job"  : (: ask_me :),
        ]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object me = this_player();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_gu", "gu");
        add_action("do_dapi", "dapi");
        add_action("do_cuihuo", "cuihuo");
}

string ask_me()
{
        object me = this_player();

        if (me->query("combat_exp") > 50000)
                return "让您老干这个未免屈尊了吧？";

        if (me->query("qi") < 50)
                return "你还是歇会儿吧！要是出了人命我可承担不起。";

        if (me->query_temp("smith/gu"))
                return "让你鼓风箱，你怎么还磨蹭(gu)？";

        if (me->query_temp("smith/dapi"))
                return "叫你打的坯你打了没有(dapi)？";

        if (me->query_temp("smith/cuihuo"))
                return "干活怎么尽偷懒？快给我淬火去(cuihuo)！";

        switch(random(3))
        {
        case 0:
                me->set_temp("smith/gu", 1);
                return "好！你帮我鼓一会儿风箱(gu)。";

        case 1:
                me->set_temp("smith/dapi", 1);
                return "这样吧，你帮我打一下坯吧(dapi)！";

        case 2:
                me->set_temp("smith/cuihuo", 1);
                return "去帮我把这些刚出炉的淬一下火(cuihuo)。";
        }
}

int do_gu(string arg)
{
        object me = this_player();

        if (me->is_busy())
                return notify_fail("你现在正忙。\n");

        if (! me->query_temp("smith/gu"))
        {
                message_vision("$n刚偷偷的拉起鼓风机，鼓了几阵风。"
                               "就听见$N对$n大喝道：滚开，乱搞什么。\n",
                               this_object(), me);
                return 1;
        }

        message_vision("$n拉起鼓风机拼命鼓了起来，$N看了点了点头。\n",
                       this_object(), me);
        reward(me);
        return 1;
}

int do_dapi(string arg)
{
        object me = this_player();

        if (me->is_busy())
                return notify_fail("你现在正忙。\n");

        if (! me->query_temp("smith/dapi"))
        {
                message_vision("$n拿起几块生铁，在手里掂了掂。"
                               "就听见$N对$n大喝道：放下，乱搞什么。\n",
                               this_object(), me);
                return 1;
        }

        message_vision("$n拿着锤子对刚出炉的火热的生铁用力敲打着，"
                        "$N“嗯”了一声，看上去有些满意。\n",
                       this_object(), me);
        reward(me);
        return 1;
}

int do_cuihuo(string arg)
{
        object me = this_player();

        if (me->is_busy())
                return notify_fail("你现在正忙。\n");

        if (! me->query_temp("smith/cuihuo"))
        {
                message_vision("$n刚抄起一个打造好的坯子，"
                               "就听见$N对$n大喝道：放下，别给我搞坏了。\n",
                               this_object(), me);
                return 1;
        }

        message_vision("$N用铁钳抄起一块火红的坯子，伸进了水"
                       "池，“哧”的一声轻烟四冒。\n",
                       me);
        reward(me);
        return 1;
}

void reward(object me)
{
        object coin;

        me->delete_temp("smith/gu");
        me->delete_temp("smith/dapi");
        me->delete_temp("smith/cuihuo");

        coin = new("/clone/money/coin");
        coin->set_amount(10 + random(10));
        coin->move(this_object());
        message_vision("$N对$n道：这是给你的工钱。\n",
                       this_object(), me);
        command("give coin to " + me->query("id"));
        if (me->query("combat_exp") < 250)
        {
                if (me->query("potential") < me->query_potential_limit())
                        me->add("potential", 1);
                me->add("combat_exp", 1 + random(2));
        }
        me->receive_damage("qi", 50);
        me->start_busy(3);
}
