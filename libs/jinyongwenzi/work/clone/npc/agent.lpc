// agent.c 代理商
// Creat By Looklove 2000/2/24
// A agent for sell Good weapon, armor, etc ...


/* 定义：v 物品本来价格(value)
        v2 物品估价 ( 含佣金 )
        v3 中间价 (除去代理佣金价)
        vt 临时价格 (只参与计算）
        vs 卖出价
        b  存款
        t  讨价还价级别
        pur 玩家淳朴
*/

#include <ansi.h>
inherit NPC;

string ask_money();
string ask_pay();
string ask_back();

void create()
{
        set_name("包老头", ({ "bao laotou", "bao", "laotou" }));
        set("title",HIC"兵器行家"NOR);
        set("gender", "男性");
        set("long","此人面色狰狞，形态可憎，小孩看见都会吓的睡不着觉。\n");
        
        set_max_encumbrance(100000000);
        set("age", 55);
        set("pur",2);
        
        set("no_get_from", 1);
        set("no_clean_up", 0);
        set("no_bark", 1);
        
        set("shen_type", 0);
        set("max_qi",800000);
        set("eff_qi",800000);
        set("qi",800000);
        set("max_jing",800000);
        set("eff_jing",800000);
        set("jing",800000);
        set("max_jingli",800000);
        set("eff_jingli",800000);
        set("jingli",800000);
        set_skill("unarmed", 60);
        set_skill("dodge", 800);
        set_skill("trade", 500);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

         set("combat_exp", 5000);
        set("attitude", "friendly");
        set("startroom","/d/city/bqp");

        set("unique", 1);
        set("chat_chance", 20);
        set("chat_msg", ({
                "包老头大声喊道: 天～亮～了～起～床～了～\n",
                "包老头懒洋洋地打了个哈欠。\n",
                "包老头小声对你说道: 道上的朋友，要不要看看紧俏货？\n",
                (: random_move :)
        }) ); 

        set("inquiry", ([
                "agent": "卖什么东西？我先估价(value)。同意价钱就帮你卖。当然要收取一成的佣金。\n",
                "转让": "转让什么东西？先估价(value)。同意就帮你卖。当然我要收取一成的佣金。\n",
                "代卖": "卖什么东西？我帮你卖，只收取一成的佣金。\n",
                 "估价": "不管卖什么东西，都要先拿来我估下价(value)。\n",
                "money": (: ask_money :),
                "生意": (: ask_pay :),
                "pay": (: ask_pay :),
                "goods" : (:ask_back:),
                "货物" : (:ask_back:),
                "name" : "老朽原是姓鲍的，专门帮人代卖(agent)旧货。后来才改了这个姓。\n",
                "rumors" : "听说为了鼓励投资，最近存款利率要下调了。\n",
                "佣金" : "佣金就是辛苦钱，你以后想赚这份钱，尽管找我，到时候我告诉你怎么赚。\n",
                "宝物" : "托我卖东西的，有的是笨蛋，费铜烂铁也想卖。你看(kan)一下就知道了。\n",
                "东西" : "想知道我都有什么东西，看(list)一下就知道。\n",
                "gold" : "如果我帮你卖过什么东西，你得提个醒，譬如“生意”什么的。\n",
                "钱" : "如果我帮你卖过什么东西，你得提个醒，譬如“生意”什么的。\n",
                "买卖" : "我现在没空，正忙着呢,想卖东西先估个价(value)。\n",
                "兵器" : "想知道我都有什么兵器，可以用list 或者list <物品ID> 来查询。\n",
                ]) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        ::init();
       add_action("do_value","value");
       add_action("do_value","gujia");
       add_action("do_agent","agent");
       add_action("do_buy","buy");
       add_action("do_list","list");
       add_action("do_list","kan");
}

int do_value(string arg) //估价部分
{
        object ob, me;
        int v, v2, pur;

        if( !arg )
                return notify_fail("格式： value <物品>\n");
        
        me = this_player();
        pur = (int)me->query("pur");
        
        if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");
        
        if(!wizardp(me)&&!ob->query("imbued" ))       //目前只代卖打造出来的兵器,考虑以后增加可以代卖其他物品。
                return notify_fail("目前只代卖打造出来的兵器。\n");
        
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("你先忙完再说吧。\n");

        if (query_temp("busy")&&!wizardp(me))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");
                
        if( ob->query("equipped"))
                return notify_fail("要代卖，你先放下啊。\n");

        if( ob->query("broken"))
                return notify_fail("我不代理损坏的武器。\n");
                
        if( ob->query("valued")){       // "valued" 物品已估价标记。
                v2 = (int)ob->query("valued");
                message_vision(CYN"$n看了看"+ob->name()+CYN"说道：“这个大约能卖"+MONEY_D->money_str(v2)+"。”\n"NOR, me, this_object());
                set_temp("busy", 1);
                call_out("delete_temp", 1, "busy");
                return 1;
        }
        
        v = (int)ob->query("value");    // 原始价格
        v2 = v*5 + random(v*5);          // v2 已估价
        ob->set("valued",v2);           // 物品估价标记
        message_vision(CYN"$N想让$n帮忙出售"+ob->name()+CYN"。\n"NOR, me, this_object());
        message_vision(CYN"$n看了看"+ob->name()+CYN"说道：“这个大约能卖"+MONEY_D->money_str(v2)+"左右。”\n"NOR, me, this_object());
        return 1;
}

int do_buy(string arg)  //买卖部分
{
        object me, ob;
        int b, v2, vs, t, pur, improve;
        
        me = this_player();
        pur = (int)me->query("pur");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");

        if (query_temp("busy")&&!wizardp(me))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

        if (base_name(environment()) != query("startroom"))
                return notify_fail("这。。。我这次是出来游玩的，你下次来吧。\n");

        if (!arg) return notify_fail("你想买什么？\n");
        
        if( !objectp(ob = present(arg, this_object())) )
                return notify_fail("你想买的东西我这里没有。\n");


        v2 = ob->query("valued");               //查询物品估价标记
        b = me->query("balance");               //查询玩家存款
        
        t = (int)me->query_skill("trade",1);
        vs = v2 + pur + random(pur) - t/4;      /* vs 卖出价格 准备开放手工讨价还价时开放,目前直接使用v2 */
        
        if( v2 > b) return notify_fail("你的钱庄里已经没有这么多钱了。\n");
        
        ob->delete("valued");                   //物品清除标记
        ob->delete("agentby");
        ob->delete("no_get");
        me->add("balance",-v2);                 //交易额从存款中扣除
        
        ob->set("user_weapon", geteuid(me));
        ob->move(me);
        message_vision("$N以"+MONEY_D->money_str(v2)+"的价格从$n那里买下了一" + ob->query("unit") +
                ob->name() + "。\n", me, this_object());
        
        improve = 40 - pur;
        me->improve_skill("trade", improve / 2 + random(improve));

        this_object()->add("balance",v2/10);    //记录佣金数额
        set_temp("busy", 1);
        call_out("delete_temp", 1, "busy");
        return 1;
}

int do_agent(string arg)        // 决定代理生效
{
        object ob, me;
        int v2, v3, vt;

        if( !arg )
                return notify_fail("格式： agent <物品>\n");
        
        me = this_player();
        
        if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");
        
        if(!ob->query("valued"))                //需要先估价
                return notify_fail("这样东西还没有估价，还是先估价(value)吧。\n");
        
        if(!ob->query("imbued" ))
                return notify_fail("目前只代卖打造出来的兵器。\n");
        
        if( ob->query("saved") )
        	return notify_fail("这兵器还是私人物品，请主人先放弃才能卖。\n");
        	
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("你先忙完再说吧。\n");
                
        if (me->query("agent")&&!wizardp(me))           //目前暂时只能代卖一件物品,准备以后开放更多。
                return notify_fail("我已经帮你代卖一样东西了。\n");
        
        if( ob->query("equipped"))
                return notify_fail("要代卖，你先放下啊。\n");

        v2 = ob->query("valued");
        v3 = v2*9/10;
        vt = v2 - v3;
        
        if (!me->query("agent")) me->set("agent",v3);   //玩家身上设置v3标记，v3 = v2 * 90% 如果没有,add 。
        else me->add("agent",v3);                       //add为开放代卖更多物品准备,不然为减少bug,就用set。
        
        ob->move(this_object());
        ob->set("agentby",me->query("id"));             //物品原主人标记
        ob->set("byname",me->query("name"));
        ob->set("no_get",1);
        
        if (!ob->query("no_steal")) ob->set("no_steal",1); //物品禁止窃取

        message_vision(CYN"$N决定让$n以"+MONEY_D->money_str(v2)+"的价格代卖"+ob->name()+CYN"。\n"NOR, me, this_object());
        message_vision("$N收下了$n的"+ob->name()+"，点头道：佣金是"+MONEY_D->money_str(vt)+"。\n", this_object(), me);

        //调试信息
        if(ob->query("value")>1000000){
        message("system", HIC "【江湖传闻】有人想要转让一"+ ob->query("unit") + ob->name()+"，"HIC"现在正由包老头代卖。\n" NOR,users());
        }
        return 1;
}

int do_list(string arg)           //买卖物品列表 开放查询物品详细描述功能。
{
        int i, goods;
        object *inv, ob;

        inv = all_inventory(this_object());     //代理商身上所有物品。
        goods = sizeof(inv);
        
        if (goods<2 ) return notify_fail("目前没有什么可以卖的东西。\n");

        if (!arg){
        write("目前包老头出售以下物品：\n");

        foreach (ob in inv)
                if(ob->query("valued"))
                write(sprintf("%-30s 单价：%s\n", ob->short(),
                MONEY_D->money_str(ob->query("valued"))));
                return 1;
        }

        if( !objectp(ob = present(arg, this_object())) )
                return notify_fail("你想看什么东西？请用list <物品ID> 格式。\n");
        
        if(ob->query("valued")){
                for (i = 0; i < sizeof(inv); i++){
                if( arg == (string)inv[i]->query("id"))
                write(sprintf("货品：    %s\n委托人：  %s (%s)\n描述：    %s\n转让价：  %s。\n \n",inv[i]->name(),inv[i]->query("byname"),inv[i]->query("agentby"),inv[i]->long(),MONEY_D->money_str(inv[i]->query("valued"))));
                }
                write("请输入你所要查看物品的准确ID。\n");
                return 1;
        }
        write("错误！没有这种物品。\n");
        return 1;

}

string ask_pay()        //收取佣金，提取货款部分
{
        object me, *inv;
        int pay, i;     
        // pay 实际等于 v3, 除佣金部分实际金额。
        
        me = this_player();
        pay = (int)me->query("agent");  //查询玩家标记
        
        inv = all_inventory(this_object());
        
        if( !pay ) return "你想要什么？";
        
        //查询物品是否售出。
        for (i = 0; i < sizeof(inv); i++)
        if((string)me->query("id") == (string)inv[i]->query("agentby")) return "东西我还没卖，卖了以后再说吧。";

        message_vision(CYN"$N点点头对$n道：东西已经卖了，除去佣金，我帮你存了"+MONEY_D->money_str(pay)+"在钱庄，自己去取吧。\n"NOR, this_object(), me);
        me->add("balance",pay);         //金额转成玩家存款。
        me->delete("agent");            //清除玩家标记。
        return "下次有这好事，记得来找我。";
}

string ask_money()      //调试部分，佣金累计。
{
        int n;
        n = this_object()->query("balance");
        if( n <1 ) return "我今天还没有开张。";
        return "我现在已经赚了" + MONEY_D->money_str(n) + "！";
}

string ask_back()       //玩家改变主意，取回代卖物品。
{
        object me, ob, *inv;
        int i, v3, v2, vt;
        
        me = this_player();
        ob = this_object();
        v3 = me->query("agent");        //代理标记

        if (!v3) return "你没让我帮你代卖过东西吧？";
        
        inv = all_inventory(ob);        
        for (i = 0; i < sizeof(inv); i++)
        if((string)me->query("id") == (string)inv[i]->query("agentby")){
                v2 = inv[i]->query("valued");
                vt = v2 - v3;
                inv[i]->delete("agentby");
                inv[i]->delete("valued");
                inv[i]->move(me);
                if(!wizardp(me)) me->delete("agent");   //if(!wizardp(me))..调试用，因为我总是卖很多东西给他。:)
                ob->add("balance",vt);
                me->add("balance",-vt);
                
                message_vision(CYN"$N对$n点点头，递给$n一"+ inv[i]->query("unit") + inv[i]->name()+"。\n"NOR, ob, me);
                return "既然你不想卖了，东西你就拿回去吧，不过我要收你"+MONEY_D->money_str(vt)+"的佣金。";
        }
        message_vision(CYN"$N脸上露出迷人的微笑，大声对$n说道：你托我卖的东西已经卖出去了。\n"NOR, ob, me);
        return "也不问问我生意怎么样，笨蛋！";
}
