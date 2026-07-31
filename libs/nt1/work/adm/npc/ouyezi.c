// ouyezi.c 欧冶子
// Created by Lonely@nitan(1)

#include <ansi.h>

inherit KNOWER;

private int     ask_me();
int  start_work(object me, object ob);       // 开始工作
int  prepare_upgrade(object me, object ob);     // 开始打造
int  do_help(string arg);
int  do_show(string arg);
void time_out(object me, object ob);

mapping need;
// 以下是各个等级防具升级需要的材料
mapping need1 = ([
        "/d/item/obj/hongshongm" : 1,
        "/d/item/obj/lanbaos"    : 2,
        "/d/item/obj/hupos"      : 2,
        "/d/item/obj/huiy"       : 2,
]);
mapping need2 = ([
        "/d/item/obj/mhshongm"   : 1,
        "/d/item/obj/jingweis"   : 3,
        "/d/item/obj/thuangs"    : 3,
        "/d/item/obj/heilvy"     : 3,
]);
mapping need3 = ([
        "/d/item/obj/wlshongm"   : 1,
        "/d/item/obj/ziyawus"    : 4,
        "/d/item/obj/qicais"     : 4,
        "/d/item/obj/donglings"  : 4,
]);
mapping need4 = ([
        "/d/item/obj/tiancs"     : 1,
        "/d/item/obj/tanxiangm"  : 1,
        "/d/item/obj/donghais"   : 5,
        "/d/item/obj/qingjins"   : 5,
]);
mapping need5 = ([
        "/d/item/obj/wujins"     : 1,
        "/d/item/obj/zitanm"     : 1,
        "/d/item/obj/lvsongs"    : 6,
        "/d/item/obj/qinghaiy"   : 6,
]);
mapping need6 = ([
        "/d/item/obj/chanhs"     : 1,
        "/d/item/obj/hhtanm"     : 1,
        "/d/item/obj/meihuay"    : 7,
        "/d/item/obj/shoushans"  : 7,
]);
mapping need7 = ([
        "/d/item/obj/longyanm"   : 1,
        "/d/item/obj/shuims"     : 1,
        "/d/item/obj/gaos"       : 4,
        "/d/item/obj/mubians"    : 4,
        "/d/item/obj/dushany"    : 4,
        "/d/item/obj/kongques"   : 4,
        "/d/item/obj/moy"        : 4,
]);
mapping need8 = ([
        "/d/item/obj/fenghuangm" : 1,
        "/d/item/obj/wangtianm"  : 1,
        "/d/item/obj/butian"     : 1,
        "/d/item/obj/huangdis"   : 4,
        "/d/item/obj/kunluny"    : 4,
        "/d/item/obj/zdhongs"    : 4,
        "/d/item/obj/yangzhiy"   : 4,
        "/d/item/obj/ganlans"    : 4,
        "/d/item/obj/hujings"    : 4,
]);
void create()
{
        set_name("欧冶子", ({ "ouye zi", "zi" }));
        set("nickname", RED "赤心剑胆" NOR);
        set("gender", "男性" );
        set("age", 1000);
        set("long",     
                "他头上包着头巾，三缕长髯飘洒胸前，面目清瘦但红晕有光，\n"
                "二目炯炯有神，烁烁闪着竟似是凛凛的剑光，浑身似乎都包围\n"
                "在一股剑气之中。自从干将和莫邪的复出后他就改行做防具了。\n");
        set("str", 250);
        set("shen_type", 0);

        create_family("玄天派", 1 ,"弟子");
        set("combat_exp", 250000);
    
        set("attitude", "peaceful");
        
        set("inquiry", ([
                "铸剑" : "我已经很久很久没有铸剑了，你还是另找别人吧。\n",
                "升级" : (: ask_me() :),
                "防具" : (: ask_me() :),
        ]));
        
        setup();
        set("chat_chance", 3);
        set("chat_msg", ({
                "欧冶子抚剑而歌：巨阙神兵兮，人铸就。盖世宝剑兮，配英雄！\n",
                "欧冶子低头沉吟，似乎在思考什么。\n"
                "欧冶子叹了一口气：神兵配英雄，可英雄。。。。。。\n"
        }));
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        add_action("do_show", "show");
        add_action("do_help", "help");
        add_action("do_help", "帮助");
        add_action("do_summon", "summon");
}

private int ask_me()
{
        message_vision("$N对$n说道：" 
                "你是要升级自己的防具吗？\n"
                "我这里可以为你升级身上穿的(cloth)之类的防具。\n"
                "你先付给我一千两黄金，然后把防具给我看看(show)。\n",
                this_object(), this_player());
        this_player()->set_temp("upgrade/money", 10000000);
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

int accept_object(object me, object ob)
{
        string *obj;
        mapping needs;
        int i;

        if (query_temp("upgrade/making")) 
        {
                message_vision("$N对$n说：我现在正忙着呢，请稍等一会！\n",
                               this_object(), me);
                return 0;
        }
                
        if (ob->query("money_id"))
        {
                if (! me->query_temp("upgrade/money"))
                {
                        message_vision("$N把$n递过去的" + ob->name() +
                                       "推了回来，道：无功不受禄！\n",
                                       this_object(), me);
                        return 0;
                }

                if (ob->value() < me->query_temp("upgrade/money"))
                {
                        message_vision("$N对$n说：对不起，老夫这一"
                                       "千多年来，还没有打过折扣。\n",
                                       this_object(), me);
                        return 0;
                }

                message_vision("$N对$n说道：好，你这就把你的要升级的防具给我看看(show)先。\n",
                               this_object(), me);

                me->set_temp("paid/欧冶子", 1);
                destruct(ob);
                return -1;
        }
        
        if (! mapp(needs = me->query_temp("upgrade/need")) 
        &&  ! me->query_temp("upgrade/prepare"))
        { 
                message_vision("$N对$n说：你给我这个干什么啊！\n",
                               this_object(), me);
                return 0;
        }
        
        if (ob->query("armor_type") == "cloth" && ob->is_item_make()
        &&  ob->item_owner() == me->query("id"))
        {       
                if (me->query_temp("upgrade/prepare"))
                {
                        me->delete_temp("upgrade");
                        start_work(me, ob);
                        return 1;
                } else 
                {
                	message_vision("$N对$n说：你给我这个干什么啊！\n",
                               	       this_object(), me);
                        return 0;
                }
        }
        
        obj = keys(needs);
        for (i = 0; i < sizeof(obj); i++) 
        {
                if (ob->short() == obj[i]->short()) 
                {               
                        needs[obj[i]] = needs[obj[i]] - 1;
                        if (needs[obj[i]] < 1) 
                        {
                                map_delete(needs, obj[i]);
                        }
                        
                        me->set_temp("upgrade/need", needs);
                        if (! mapp(needs = me->query_temp("upgrade/need")) || sizeof(keys(needs)) < 1)
                        {
                                me->set_temp("upgrade/prepare", 1); 
                                me->delete_temp("upgrade/need");
                                tell_object(me, HIR "\n升级防具的物品齐了，现在把你的要升级的防具给我吧！\n" NOR);
                        }
                        destruct(ob);                   
                        tell_object(me, HIR "\n恩，不错，还有没有了？！\n" NOR);
                        return -1;
                } else
                {
                    message_vision("$N对$n说：你给我这个干什么啊？我要你找的材料不是这个！\n",
                                   this_object(), me);
                        return 0;
                }
        }
}

int start_work(object me, object ob)
{
        remove_call_out("prepare_upgrade");
        call_out("prepare_upgrade", 1, me, ob);
        set_temp("upgrade/making", ob);
        set_temp("upgrade/player", me);
        ob->set_temp("upgrade/player_id", me->query("id"));
        me->set_temp("upgrade/status", "waiting");
        return 1;
}

int prepare_upgrade(object me, object ob)
{       
        message_vision(HIC "\n$N说道：好，开炉锻炼！\n\n" NOR, this_object());
        message_vision(HIM "$N看了看手中的那些升级所需要的物品" +
                       HIM "，随手把它们抛入炉内，霎时\n间那些物品" + 
                       HIM "已被火炉中的熊熊" HIR "烈焰" HIM "吞没。" +
                       "$N凝视着炉火，喃喃说道：\n天地之精华为其血脉，日"
                       "月之光辉是其灵气......\n\n" NOR , this_object());
        remove_call_out("work_step_1");
        call_out("work_step_1", 5, me, ob);
        return 1;
}

private int work_step_1(object me, object ob)
{               
        message_vision(HIG "炉火渐渐的转成了绿色，火苗不断跳跃，欧冶子神情凝重地注视"
                       "着炉中物品的变化。\n\n" NOR, this_object());
        if (objectp(me) && environment(me) == environment())
        {
                me->set_temp("upgrade/can_help", 1);
                message_vision(HIW "$N对$n说道：现在需"
                               "要注入你自己的精气血脉，请"
                               "助(help)我一臂之力！\n\n", this_object(), me);
        }
        remove_call_out("time_out");
        call_out("time_out", 30, me, ob);
        return 1;
}

private int work_step_2(object me, object ob)
{
        message_vision(RED "炉火淡淡的暗了下来，呈现出一片红色......\n\n" NOR, this_object());
        remove_call_out("work_step_3");
        call_out("work_step_3", 3, me, ob);
        return 1;
}


private int work_step_3(object me, object ob)
{
        if (! objectp(ob))
        {
                delete_temp("upgrade"); 
                return notify_fail("欧冶子因为一时找不到要升级防具，所以升级半途而废！\n");
        }
        
        if (! objectp(me))
                me = find_player(ob->query_temp("upgrade/player_id"));

        if (! objectp(me) || environment(me) != environment())
        {
                message_vision(HIW "$N叹了口气，说道：客人为何这就去"
                               "了！？罢了罢了，不做了，去吧！\n"
                               "$N把升级的道具抛进火炉，就此不见。\n\n" NOR,
                               this_object());
                if (objectp(me))
                        me->delete_temp("upgrade");

                if (objectp(ob) && present(ob, this_object()))
                        destruct(ob);

                delete_temp("upgrade");
                return 1;
        }
                
        message_vision(HIW "$N左手从怀里取出了一个很古老的一个瓶子，向炉中倒入了一些神秘\n" +
                       HIW "不知名的物质，$N右手将" + ob->short() + HIW + "放入炉中。渐渐" +
                       HIW "的，炉中发\n生了奇妙的变化，发出神秘的光芒。\n\n" NOR,
                       this_object());
        ob->armor_upgrade(me);
        remove_call_out("work_step_4");
        call_out("work_step_4", 2, me, ob);
        return 1;
}


private int work_step_4(object me, object ob)
{
        if (! objectp(ob))
        {
                delete_temp("upgrade"); 
                return notify_fail("欧冶子因为一时找不到要升级防具，所以升级半途而废！\n");
        }
                
        message_vision(HIW "$N缓缓的从炉中抽出了升级好的" + ob->short() +
                       HIW "看了看，满意地说，很好，很好。\n\n" NOR,
                       this_object());
        remove_call_out("work_step_6");
        call_out("work_step_5", 2, me, ob);
}

private int work_step_5(object me, object ob)
{
        object moye;
        int improve;

        if (! objectp(me))
                me = find_player(ob->query_temp("upgrade/player_id"));

        if (! objectp(me) || environment(me) != environment())
        {
                message_vision(HIW "$N叹了口气，说道：客人为何这就去"
                               "了！？罢了罢了，不做了，去吧！\n"
                               "$N把升级的道具抛进火炉，就此不见。\n\n" NOR,
                               this_object());
                if (objectp(me))
                        me->delete_temp("upgrade");

                if (objectp(ob) && present(ob, this_object()))
                        destruct(ob);

                delete_temp("upgrade");
                return 1;
        }
        ob->move(me, 1);
        ob->save();
        message_vision("$N把升级好的" + ob->query("name") + "交给了$n。\n",
                       this_object(), me);
        me->delete_temp("upgrade");
        delete_temp("upgrade");
        return 1;

}

// 以内力哺育炉火，提高道具等级
// 要求：精 >= 180  气 >= 300  内力有效等级 >= 100  内力 >= 800 最大内力 >= 1000
// 结果：耗费 200 点内力，可以提高 10%
int do_help(string arg)
{
        object me;
        object ob;

        me = this_player();
        if (me->query_temp("upgrade/status") != "waiting")
        {
                return notify_fail("没你什么业务。\n");
        }
        if (! me->query_temp("upgrade/can_help"))
        {
                if (arg) return 0;
                write("现在不是你帮忙的时候！\n", me);
                return 1;
        }
        if (me->query("potential") - me->query("learned_points") < 5000)
        {
                return notify_fail("你的潜能不够５０００点，没法注入你的精气血脉。\n");
        }
        if (me->query("jing") < 180 || me->query("max_jing") < 180)
        {
                message_vision(HIR "$N" HIR "长啸一声，双手搭上炉边，正待以内"
                               "力哺育炉火，突然眼前一黑...\n" NOR, me);
                tell_object(me, RED "你感到精力衰竭。\n" NOR);
                me->set("jing", 0);
                return 1;
        }
        me->receive_damage("jing", 180);
        if (me->query("qi") < 300 || me->query("max_neili") < 300)
        {
                message_vision(HIR "$N" HIR "长啸一声，双手搭上炉边，正待以内"
                               "力哺育炉火，突然眼前一黑...\n" NOR, me);
                tell_object(me, RED "你感到心虚气短。\n" NOR);
                me->set("qi", 0);
                return 1;
        }
        me->receive_damage("qi", 300);
        if (me->query("neili") < 800 || me->query("max_neili") < 1000)
        {
                message_vision(HIR "$N" HIR "长啸一声，双手搭上炉边，正待以内"
                               "力哺育炉火，突然眼前一黑...\n" NOR, me);
                tell_object(me, RED "你感到内力枯竭。\n" NOR);
                me->set("neili", 0);
                return 1;
        }
        if (me->query("jingli") < 300 || me->query("max_jingli") < 500)
        {
                message_vision(HIR "$N" HIR "长啸一声，双手搭上炉边，正待以内"
                               "力哺育炉火，突然眼前一黑...\n" NOR, me);
                tell_object(me, RED "你感到精元枯竭。\n" NOR);
                me->set("jingli", 0);
                return 1;
        }
        message_vision(HIR "$N" HIR "长啸一声，双手搭上炉边，刹那间，炉火沸腾，"
                       "一道" HIW "白光" HIR "，直冲霄汉。\n\n" NOR, me);
        ob = query_temp("upgrade/making");
        me->delete_temp("upgrade/can_help");
        me->delete_temp("upgrade/status");
        remove_call_out("time_out");
        remove_call_out("work_step_2");
        call_out("work_step_2", 6, me, ob);
        me->add("max_neili", -300);
        me->add("max_jingli", -100);
        me->add("neili", -200);
        me->add("jingli", -100);
        return 1;
}

int do_show(string arg)
{
        object money;
        object ob;
        object me;
        int defense_lvl, n, i;
        string *obj, str;
        mapping needs;
        object needob;

        if (query_temp("upgrade/making")) 
                return notify_fail("我正在忙着呢，请稍等一会！\n");
        
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

        if (! me->query_temp("paid/欧冶子", 1))
        {
                command("heihei");
                me->set_temp("upgrade/money", 10000000);
                command("say 这...怎么也的有点意思意思吧？你"
                        "说一千两黄金怎么样？当然多些我也不反对。");
                return 1;
        }
        
        if (ob->query("armor_type") != "cloth")
        {
                command("say 你给我这个干什么啊？我只负责升级身上穿的之类的防具。");
                return 1;
        }

        if (! ob->is_item_make())
        {
                command("heng");
                command("say 这...这...我看还是算了吧！");
                return 1;
        }

        if (ob->item_owner() != me->query("id"))
        {
                command("kick " + me->query("id"));
                command("say 你以为我的仙术是蒙事的啊，这分明不是你的！");
                return 1;
        }

        if (me->query("can_summon/" + ob->query("id")))
        {
                defense_lvl = ob->armor_level();
                /*
                switch (defense_lvl)
                {
                case 5:
                        need = need1;
                        break;
                case 10:
                        need = need2;
                        break;
                case 30:
                        need = need3;
                        break;
                case 100:
                        need = need4;
                        break;
                case 300:
                        need = need5;
                        break;
                case 1000:
                        need = need6;
                        break;
                case 3000:
                        need = need7;
                        break;
                case 10000: 
                        need = need8;
                        break;
                default:
                        return notify_fail("啊！这个我无能为力。\n");
                }
                */
                if (defense_lvl == 5) need = need1;
                else if (defense_lvl == 10) need = need2;
                else if (defense_lvl == 30) need = need3;
                else if (defense_lvl == 100) need = need4;
                else if (defense_lvl == 300) need = need5;
                else if (defense_lvl == 1000) need = need6;
                else if (defense_lvl == 3000) need = need7;
                else if (defense_lvl == 10000) need = need8;
                else return notify_fail("啊！这个我无能为力。\n");
        }
        
        me->set_temp("upgrade/need", need);
        // needs = me->query_temp("upgrade/need");
        if (! mapp(need)) return notify_fail("好像出了点问题。\n");
        obj = keys(need);
        
        str = "\n你的" + ob->short() + HIG + "此次升级需要的物品如下：\n\n";
        for (i = 0; i < sizeof(obj); i++)
        {
                needob = new(obj[i]);
                str += sprintf("%-40s ：\t%s%s\n",
                               needob->short(), 
                               CHINESE_D->chinese_number(need[obj[i]]),
                               needob->query("unit"));
                destruct(needob);
        }
        tell_object(me, HIG + str + NOR);
        tell_object(me, "你千万要记好我叫你找的的物品，否则.....\n");
        tell_object(me, "你把" + ob->short() + "升级所需的物品备齐，再来找我吧！\n");
        me->delete_temp("paid/欧冶子");
        return 1;
}

void time_out(object me, object ob)
{
        int at_present;

        if (! objectp(me))
                me = find_player(query_temp("upgrade/player_id"));

        if (! objectp(me) || environment(me) != environment())
        {
                command("say 奇怪，刚才那位客人呢？怎么这就走了？\n");
                at_present = 0;
        } else
        {
                command("say 我可不能跟你耗着！下次再来吧！");
                at_present = 1;
        }

        delete_temp("upgrade");
        if (objectp(me))
                me->delete_temp("upgrade");

        if (ob)
        {
                if (at_present)
                        command("give " + ob->query("id") +
                                " to " + me->query("id"));

                if (environment(ob) == this_object())
                        command("drop " + ob->query("id"));
        }
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
