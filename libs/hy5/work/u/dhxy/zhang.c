// zhang.c 张天师

#include <ansi.h>

inherit NPC;

int ask_me();
int ask_hui();

void create()
{
	set_name("张天师", ({ "zhang tianshi", "zhang" }));
	set("age", 57);
	set("gender", "男性");
	set("long", "这是一位仙风神骨，道貌岸然的法师。\n");
	set("attitude", "peaceful");

	set("str", 28);
        set("int", 35);
        set("con", 38);
	set("dex", 31);

        set("max_qi", 8000);
        set("max_jing", 8000);
        set("max_neili", 8000);

        set_skill("magic", 200);
        set_skill("taoism", 350);

        set("chat_chance_combat", 3);
	set("chat_msg_combat", ({
                "张天师摇摇铃铛，道：天灵灵，地零零，太上老君还不显灵？\n",
                "张天师呼呼的吹了几口气。\n",
	}));

        set("inquiry", ([
                "销毁" : (: ask_hui :),
                "开光" : (: ask_me :),
                "没钱" : "没钱就去赚，跟我说什么。",
                "穷"   : "看你也是一副穷命。",
                "魔法" : "魔法？什么玩艺？",
                "法术" : "法术还分很多种呢，道术、妖术、仙术不一而足。",
                "道术" : "道术？这可是本源正宗！",
                "妖术" : "妖术啊，趋于下乘，不足为提。",
                "仙术" : "仙术只好算是中乘，还是不能和道术相比。",
//                "浸入" : "你要是不行我可以帮你看看(show)浸入需要用什么物品。",
        ]));

	setup();
	carry_object("/clone/cloth/dao-cloth")->wear();
}

void init()
{
        add_action("do_show", "show");
        add_action("do_summon", "summon");
}

int ask_me()
{
        command("heihei");
        command("say 我只给神兵利器开光，寻常刀剑莫提！要"
                "你本人的，我可不能帮你做坏事！");
        tell_object(this_player(), GRN "张天师在你耳边悄悄说："
                    "你把要开光的拿出来给我看看(show)！\n" NOR);
        return 1;
}

int ask_hui()
{
        command("sigh");
this_player()->delete("diablo");
this_player()->save();
        tell_object(this_player(), GRN "张天师在你耳边悄悄说："
                    "重新进入游戏，你的武器可以重新开光，放宝石了！\n" NOR);
        return 1;
}

int do_summon(string arg)
{
        if (! wizardp(this_player()))
        {
                command("say 你在我面前瞎抓个什么劲？别地试去！");
                return 1;
        }

        return 0;
}

int do_show(string arg)
{
        object money;
        object ob;
        object me;
	string type;

        if (! arg)
                return notify_fail("你要亮出什么东西？\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)))
                return notify_fail("你身上没有这种东西。\n");

        if (ob->query("equipped"))
                return notify_fail("你先解除" + ob->name() + "的装备再说！\n");

        message_vision("$n拿出一" + ob->query("unit") + ob->name() +
                       "对$N说：“拜托拜托...”\n",
                       this_object(), me);

        if (ob->query("money_id"))
        {
                command("say 你亮出钱干什么？想献给观里？那就给我好了。");
                return 1;
        }

        if (! me->query_temp("paid/张天师", 1))
        {
                command("heihei");
                command("say 这...怎么也的有点意思意思吧？你"
                        "说一千两黄金怎么样？当然多些我也不反对。");
                return 1;
        }

        if (!ob->query("max_sockets"))
        {
                command("say 哦！我看它不能开光！");
                return 1;
        }
	if (mapp(ob->query("weapon_prop")))
		type = "weapon";
	else if (mapp(ob->query("armor_prop")))
		type = ob->query("armor_type");


if (type=="finger")
{
if (me->query("diablo/" + type + "/sockets/max",1) >= 3
&& me->query("combat_exp") < 10000000 )
        {
                command("say 哦！我看它现在已经不需要在开光了！");
                return 1;
        }
if (me->query("diablo/" + type + "/sockets/max",1) >= 4
&& me->query("combat_exp") < 20000000 )
        {
                command("say 哦！我看它现在已经不需要在开光了！");
                return 1;
        }
if (me->query("diablo/" + type + "/sockets/max",1) >= 5)
        {
                command("say 哦！我看它现在已经不需要在开光了！");
                return 1;
        }

}
if (type=="weapon")
{
if (me->query("diablo/" + type + "/sockets/max",1) >= 3
&& me->query("combat_exp") < 10000000 )
        {
                command("say 哦！我看它现在已经不需要在开光了！");
                return 1;
        }
if (me->query("diablo/" + type + "/sockets/max",1) >= 4
&& me->query("combat_exp") < 20000000 )
        {
                command("say 哦！我看它现在已经不需要在开光了！");
                return 1;
        }
if (me->query("diablo/" + type + "/sockets/max",1) >= 5)
        {
                command("say 哦！我看它现在已经不需要在开光了！");
                return 1;
        }

}
if (type=="cloth")
{
if (me->query("diablo/" + type + "/sockets/max",1) >= 3
&& me->query("combat_exp") < 10000000 )
        {
                command("say 哦！我看它现在已经不需要在开光了！");
                return 1;
        }
if (me->query("diablo/" + type + "/sockets/max",1) >= 4
&& me->query("combat_exp") < 20000000 )
        {
                command("say 哦！我看它现在已经不需要在开光了！");
                return 1;
        }
if (me->query("diablo/" + type + "/sockets/max",1) >= 5)
        {
                command("say 哦！我看它现在已经不需要在开光了！");
                return 1;
        }

}
//        if (ob->query("sockets/max") >= ob->query("max_sockets"))
//        {
//                command("say 哦！我看它现在已经不需要在开光了！");
//                return 1;
//        }

        if (ob->query("sockets/max",1) >= 5)
        {
                command("say 哦！我看它现在已经不需要在开光了！");
                return 1;
        }

        message("vision", HIM + name() + "从口袋中摸出一张黄色"
                                "的符纸，抽出背后的桃木剑，"
                                "将那符纸点燃了，扫过" + ob->name() + HIM "，然"
                                "后用桃木剑穿了，手舞足蹈，口中念念有词："
                                "“太上老君急急如律赐令！”说罢一抖掌中剑，"
                                "喝道：“疾”！\n" NOR, environment());
        message_vision("焰光划出一道光华，$N发了发呆，也不知道算是怎么回事。\n",
                       me);
        command("say 行了，行了！你可以走了。");
        me->delete_temp("paid/张天师");
	if (mapp(ob->query("weapon_prop")))
		type = "weapon";
	else if (mapp(ob->query("armor_prop")))
		type = ob->query("armor_type");
	me->set("diablo/" + type + "/id", ob->query("id"));
	me->add("diablo/" + type + "/sockets/max", 1);
	seteuid(ROOT_UID);
	reload_object(ob);
        seteuid(getuid());
        return 1;
}

int accept_object(object who, object ob)
{
        if (! ob->query("money_id"))
        {
                command("say 这玩艺我可没啥兴趣！");
                return 0;
        }

        if (ob->value() < 10000000)
        {
		command("shake " + who->query("id"));
                command("say 你这算是给观里的香火么？");
                return 0;
        }

        command("say 唉！看你也算有点心意，我就替你开一次光吧！");
        who->set_temp("paid/张天师", 1);
//      destruct(ob);
        return 1;
}

void fight_ob(object ob)
{
        ::fight_ob(ob);
        message_vision("$N冷笑一声，道：“这年头，什么人都有。”说完伸手一指$n。\n",
                       this_object(), ob);
        ob->unconcious();
}

int accept_fight(object who)
{
        command("say 没兴趣。");
        return 0;
}

int accept_ansuan(object who)
{
        return notify_fail("你刚想暗算，可是眼前一花，看不太清楚。\n");
}

void receive_damage(string type, int n)
{
        return;
}

void receive_wound(string type, int n)
{
        return;
}
