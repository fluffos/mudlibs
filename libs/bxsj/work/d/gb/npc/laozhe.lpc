// laozhe.c 老者
// By Looklove for a quest at 2k/5/17

#include <ansi.h>
inherit NPC;
int ask_yulou();
int ask_yugan();

void create()
{
        set_name("老者", ({"lao zhe", "old man", "man"}));
        set("gender", "男性");
        set("age", 54);
        set("str", 22);
        set("int", 20);
        set("dex", 18);
        set("con", 20);

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 1100);
        set("max_jing", 1100);
        set("shen", 1000);
        set("no_get", 1);

        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("startroom","/d/gb/island3");
        set("chat_chance", 30);
        set("chat_msg", ({
		"老者自言自语道：这个小岛真是个好地方。\n",
		"老者说道：今天本来打算去钓鱼，没想到拿了鱼篓忘了鱼竿，我真是老糊涂了。\n",
		(: random_move :),
		"老者自言自语道：改天找几个老哥们一起比一把，让他们看看我的钓鱼水准。\n",
		"老者说道：哎，人老多忘事，鱼竿不知道被我放在什么地方了。\n",
		(: random_move :)

        }));

        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 200);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        set("inquiry", ([

                "鱼竿" : (: ask_yugan :),
                "鱼篓" : (: ask_yulou :),
                "钓鱼" : "钓鱼可是个修身养性的好办法。\n",
                "钓鱼大赛":"钓鱼大赛？下期吧，等乐仔的最新改进版出来的就开了。\n",
                "looklove":"嘿嘿，想找他一起钓鱼？我也想啊，就是找不到。\n",
                "name" : "小老头我有个外号，人称鱼王。\n",
                "here" : "这里你都不知道？这里是远近闻名的钓鱼岛啊。\n",
                "rumors" : "据说海龟吃了很补，要是钓到，嘿嘿……。\n",
                "钓鱼" : "钓鱼可是个修身养性的好办法。\n",
        ]));

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        carry_object(FOOD_D("jiudai"));
        carry_object("/d/gb/obj/yulou");
        add_money("silver", 5);
}
int ask_yulou()
{
        object me;
        object lou;
        me = this_player();

        if ((present("yu lou",  environment(me))) || (present("yu lou",me))){
                command("angry "+me->query("id"));
                command("say 鱼篓，鱼篓，你小子不是骑驴找驴么？");
        	return 1;
        }
        if (!me->query_temp("ask/yulou")){
                command("pat "+me->query("id"));
                message_vision(HIY"老者给$N一个鱼蒌。\n"NOR, me);
                me->set_temp("ask/yulou",1);
                lou=new("/d/gb/obj/yulou");
                lou->move(me);
        	return 1;
        }
        else
        command("say 我不是给你了吗？你弄哪去了？");
        return 1;
}
int ask_yugan()
{
        object me;
        me = this_player();

        if (!me->query_temp("find/yugan")){
                command("touch "+me->query("id"));
                command("say 原来你也爱钓鱼。");
                command("say 刚才我在木棚歇脚，大概鱼竿随手就丢那儿了。");
                me->set_temp("find/yugan",1);
                return 1;
        }
        else
        command("say 不是告诉你了吗？自己去找找。");
        return 1;
}