// gui nu.c 龟奴
// Modify by Looklove for sell mm 嘿嘿.... 2000/10/07
// Modified by iszt@pkuxkx, 2007-02-21

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("龟奴", ({ "gui nu", "nu", "slave" }) );
        set("gender", "无性" );
        set("title", "丽春院总管");
        set("age", 32);
        set("long", 
                "他是丽春院里里外外管事的，没有他丽春院就不会有今天的繁荣。"
                "不过他也干尽了逼良为娼的坏事。此人两膀膂力过人，不好惹。\n");
        set("str", 35);
        set("dex", 35);
        set("con", 25);
        set("int", 25);
        set("shen_type", -1);

        set_skill("unarmed", 90);
        set_skill("force", 20);
        set_skill("dodge", 55);

        set("combat_exp", 95000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);

        set("attitude", "friendly");
        set("inquiry", ([
                "name" : "我也不知道我原来叫什么。",
                "韦小宝" : "那是我们老板娘的儿子。",
                "丽春院" : "我们丽春院可是扬州城里头一份的找乐子去处。",
                "here" : "我们丽春院可是扬州城里头一份的找乐子去处。",
                "赎身" : "那可不行。我们这儿的姑娘是摇钱树。除非你加倍地给我钱。",
                "从良" : "那可不行。我们这儿的姑娘是摇钱树。除非你加倍地给我钱。",
                "姑娘" : "姑娘就是姑娘，连这都不懂还逛什么窑子。",
        ]) );
        set("my_money", 0);

        setup();
        set("chat_chance", 3);
        set("chat_msg", ({
        "龟奴说道：「客官是要缺钱花就把你妹妹，女儿什么的卖到我这来吧。」\n",
        "龟奴说道：「卖姑娘，谁漂亮谁才能卖个好价钱。」\n",
        }) );
        carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_sell","sell");
}

void greeting(object me)
{
        object * ob;
        int found,i;
    
        if (!me)
                return;
        found = 0;
    
        if (me->query("hooker")) {
                command("say 好啊，"+me->name() + "，我还当你要逃到天边呢，你又回来了！");
                command("say 你要再逃我打断你的腿！");
                return;
        }
        if (me->query("gender")!="无性")
        {
                ob = all_inventory(environment());
                for(i=sizeof(ob)-1; (i>=0) && !found; i--)
                {
                        if( !userp(ob[i]) )
                                continue;
                        if (ob[i]->query("hooker"))
                        {
                                found = 1;
                                command ("say "+ob[i]->name() + "，看见客人来了还不快迎接！ ");
                                command ("kick " + ob[i]->query("id"));
                        }
                }   
        }
        return ;
}

int do_sell(string arg)
{         object ob;
        int value, per;

        string* name1s = ({
                "小", "春", "夏", "秋", "冬", "月", "彩", "金" });
        string* name2s = ({
                "红", "兰", "月", "翠", "莲", "荷", "叶", "花", "蝶" });
        string* name3s = ({
                "姐姐", "妹妹", "姑娘", "姑娘", "姑娘" });
        string nick;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要卖谁？\n");

        if (!ob->is_character())
                return notify_fail("这你得卖到当铺去。\n");

        if (userp(ob))
              return notify_fail("我们不能买卖玩家。\n");
 
        if (ob->query("gender")!="女性")
                return notify_fail("本院目前还不召男妓。\n");

        if (ob->query("hooker"))
                return notify_fail("她已经是我们丽春院的人了，你不能再卖了。\n");
        if (ob->query("cannot_sell"))
                return notify_fail("这个女人非同寻常，我可不敢要。\n");
        if (( ob->query_per())< 5 )
                return notify_fail("这个妞长得太丑了，还是你自己留着吧。\n");

        if (ob->query("combat_exp") <= 10000)
                return notify_fail("她还是个雏儿呢，我可没工夫教她。\n");

        per = ob->query("per");
        if(per > 40)
                per = 30 + per / 4;
        if(per > 50)
                per = 50;
        if(!userp(ob))
                value = per * 800;
        else
                value = ob->query("combat_exp") / 10 + per * 800;

        if(query("my_money") < value && !userp(ob))
                return notify_fail("小人暂时没有那么多现钱来买这位姑娘，实在抱歉。\n");

        message_vision("$N把"+ ob->name()+"卖到了丽春院。\n", this_player());
        MONEY_D->pay_player(this_player(), value);
        add("my_money", -value);
        this_player()->add("shen", -(value/100));
        this_player()->add("sell_woman/" + ob->query("id"), 1);

        ob->move(this_object());
        if( !ob->query("old_title"))
                ob->set("sell/title",ob->query("title"));
        else
                ob->set("sell/title", ob->query("old_title"));

        nick = name1s[random(sizeof(name1s))] + name2s[random(sizeof(name2s))]
                + name3s[random(sizeof(name3s))];
        if (ob->query("age")<22)       
                ob->set("title","丽春院新人");
        else if (ob->query("age")<30)
                ob->set("title","丽春院头牌");
        else if (ob->query("age")<45)
                ob->set("title","丽春院皇后");
        else ob->set("title","丽春院教师");

        ob->set("nickname", nick);
        command ("chat 我们丽春院新来了「"+nick+ "」"+ob->name()+"，欢迎各位大爷光顾！");
        ob->set("hooker", 1); 

        return 1;
}

int accept_object(object me, object obj)
{
        int per, value;

        per = me->query("per");
        if(per > 40)
                per = 30 + per / 4;
        if(per > 50)
                per = 50;
        if(!userp(me))
                value = per * 800;
        else
                value = me->query("combat_exp") / 10 + per * 800;

        if(!obj->query("money_id"))
                return 0;

        if(!me->query("hooker"))
        {
                command("say 谢谢赏钱。");
                command("bow "+ me->query("id"));
                return 1;
        }
        if(obj->value() < value*2)
        {
                command("say 谢谢"+me->query("nickname")+"赏钱。");
                command("bow "+ me->query("id"));
                return 1;
        }

        command ("say 好吧，人各有志，你要从良我也不勉强，找个好人家嫁了吧。我们大家会想你的。");
        command ("cry "+me->query("id"));
        if( !me->query("sell/title") && me->query("family"))
                me->set("title",me->query("family/family_name")+"第"+
                        chinese_number(me->query("family/generation"))+
                        "代弟子");
        else
                me->set("title",me->query("sell/title"));
        me->delete("sell/title");
        me->delete("nickname");
        command("slow "+me->query("id"));
        me->delete("hooker");

        return 1;
}

