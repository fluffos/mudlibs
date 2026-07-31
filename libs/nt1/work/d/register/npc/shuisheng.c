// shuisheng 水笙

inherit NPC;

void greeting(object me);
int do_register(string arg);
int do_decide(string arg);

void create()
{
        set_name("水笙", ({ "shui sheng","shuisheng"}));
        set("long", "她轻妆淡抹，眉目之中深深的透露哀思。\n");
        set("gender", "女性");
        set("age", 22);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 25);

        setup();
        carry_object("/clone/cloth/cloth.c")->wear();
}

void init()
{
        object me;

        ::init();
        me = this_player();
        if (! objectp(me) || ! userp(me))
                return;

        add_action("do_register", "register");
        add_action("do_decide", "decide");

        remove_call_out("greeting");
        call_out("greeting", 0, me);
}

void greeting(object me)
{
        if (! objectp(me) || environment(me) != environment(this_object()))
                return;

        if (! me->query("registered"))
        {
                command("tell " + me->query("id") + " 你还没有注册，快注册(register)吧。");
                command("tell " + me->query("id") + " 你务必注册你个你能够收取信件的地址"
                        "，\n以备口令丢失的时候能够收取更新的口令。");
                return;
        }

        if (! stringp(me->query("character")))
        {
                command("tell " + me->query("id") + " 你还没有选择品质，快去附近选选吧。");
                return;
        }

        if (! wizardp(me))
        {
                command("tell " + me->query("id") + " 咦，你怎么跑到这里来了？");
                if (! stringp(me->query("born")))
                {
                        message_vision("$N被昏昏沉沉的扔了出去。\n", me);
                        me->delete("born");
                        me->move("/d/register/yanluodian");
                        message_vision("啪的一声，$N被扔到了地上。\n", me);
                        return;
                }

                message_vision("$N被昏昏沉沉的扔了出去。\b", me);
                me->move(VOID_OB);
                message_vision("啪的一声，$N被扔到了地上。\n", me);
                return;
        }

        command("look " + me->query("id"));
}

int do_register(string arg)
{
        object me;
        string id, address;

        if (! objectp(me = this_player()))
                return 0;

        if (me->query("registered"))
        {
                command("say 你不是已经注册过了吗？不用再注册了。");
                return 1;
        }

        if (! arg || ! stringp(arg))
        {
		command("shake " + me->query("id"));
                command("say 注册的email地址你得给我啊。请输入register 你的email地址");
                return 1;
        }

        if (strlen(arg) > 64 || sscanf(arg, "%s@%s", id, address) != 2)
        {
                command("say 我怎么没有见过这么怪的email地址？你看看清楚好吗？");
                return 1;
        }

        me->set_temp("email", arg);
        command("nod " + me->query("id"));
        command("tell " + me->query("id") + " 好，你的email地址是：" + arg +
                "，如果没有\n错误，你就决定(decide)吧。");
        command("tell " + me->query("id") + " 请注意，由于本站不采用mail确认，所以
你即使注册一个你无法收信的地址，系统也不能识别。当你决定采用
这个信箱地址以后，它将成为确认你身份的唯一途径，这个注册的信
箱地址是永远不能改变的。当你丢失了你的密码以后系统的管理人员
可以将修改后的口令发送到你注册的信箱中，如果你出于某种目的不
愿意注册你的信箱，那么管理人员将不为你的密码负任何责任，这意
味着你必须自己保管好你的密码。");
        return 1;
}

int do_decide(string arg)
{
        object me;
        object link_ob;

        if (! objectp(me = this_player()))
                return 0;

        if (me->query("registered"))
        {
                command("say 行了行了，我已经知道你的地址了，不用再说啦！\n");
                return 1;
        }

        if (! stringp(me->query_temp("email")))
        {
                command("say 你要决定什么？是决定注册吗？要是那"
                        "样请你先注册你的email地址。");
                return 1;
        }

        command("say 好了！你的email地址已经注册了！现在快去附近选你的品质吧。");
        me->set("email", me->query_temp("email"));
        me->set("registered", 1);
        me->save();
        return 1;
}
