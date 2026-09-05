// xian. 冼老板
// modified by Zine 10/4/2011 add 宴客功能给玩家
#include <ansi.h>

inherit NPC;
inherit F_DEALER;

int ask_kaoya();
int ask_yanke();
void create()
{
	set_name("冼老板", ({ "xian laoban", "xian" }));
	set("title", "醉仙楼老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
        set("long", "冼老板经营祖传下来的醉仙楼已有多年，以各式精美菜式和烤鸭著称。\n");
	set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
                __DIR__"obj/hdjiudai",
                "/d/lingjiu/obj/suanmei",
                "/clone/food/nanxiang-xiaolong",
                "/clone/food/qingzheng-jiyu",
                "/clone/food/shengjian-mantou",
                "/clone/food/su-jianjiao",
	}));
        set("inquiry", ([
                "烤鸭" : (: ask_kaoya :),
                "宴客" : (: ask_yanke :),
                "yanke" : (: ask_yanke :),
        ]));

	setup();
    carry_object("/clone/armor/cloth")->wear();
        add_money("silver", 10);
        //add_money("gold", 1);
}

void init()
{
add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int adv_tell(object ob)
{
    command("tell "+ob->query("id")+" 阁下这样大喜的日子，不来醉仙楼举办个宴席，实在太寒碜了。");
    if (ob->query("pyh_obtain_high_gem"))
    {
        command("tell "+ob->query("id")+" 古语有云：破财消灾，你在鄱阳湖寻宝中拿到那么大宝石不怕折福吗？");
    }
    command("tell "+ob->query("id")+" 详情咨询请来醉仙楼，ask xian about 宴客。");
    return 1;
}

int ask_yanke()
{
    object me = this_player();
    object ob = this_object();
    object gd = load_object("/d/city/guodao");
    if (me->is_busy() || me->is_fighting())
		{
            tell_object(me,"你正忙着哪！\n");
			return 1;
        }
    if (gd->query("yanke")||gd->query("lingjiang"))
    {
        tell_object(me,"冼老板道：宴客厅此时正在使用，你迟些再来吧。\n");
        return 1;
    }
    if (me->query("balance")<10000000)
    {
        tell_object(me,"冼老板道：宴客举行极尽奢华，一次需要花费一千两黄金，我看你的钱不够啊！\n");
        return 1;
    }
    if (me->query("age")<18)
    {
        tell_object(me,"冼老板道：小朋友乱花家里的钱可不好。\n");
        return 1;
    }
    if (me->query_temp("yanke/permit"))
    {
        tell_object(me,"冼老板道：你准备什么时候开席？\n");
        return 1;
    }
    if (ob->query("checking"))
    {
        tell_object(me,"冼老板道：请稍等一下。\n");
        return 1;
    }
    else
    {
        tell_object(me,"冼老板道：那我把宴客的流程跟你简单说一下。\n");
        tell_object(me,"冼老板道：首先，宴席不能没有奖品，不然不会有人捧场。\n");
        tell_object(me,"冼老板道：所以，我需要你提供三颗同款的宝石作为奖品。\n");
        tell_object(me,HIR"冼老板道：要注意的是，如果你提供了不同的宝石，弄错了我是不会退给你的，嘿嘿！\n"NOR);
        tell_object(me,"冼老板道：宝石检查完后，我会直接在你账上扣一千两，假如账户不足，宝石也不会退的。\n");
        tell_object(me,"冼老板道：之后你就可以开始宴客了。\n");
        me->set_temp("宴客准备",1);
        return 1;
    }
}

int ask_kaoya()
{
        object me = this_player();
        object ob;
        if(!me->query_temp("kaoya"))
        {
                message_vision(CYN"冼老板说道：「客官请先付"HIW"十二两银子"NOR+CYN"，小店利薄，恕不赊欠。」\n"NOR, me);
                return 1;
        }
        if(me->query("mud_age") - me->query_temp("kaoya") < 1+random(4))
        {
                message_vision(CYN"冼老板说道：「客官稍安毋躁，烤鸭马上出炉。」\n"NOR, me);
                return 1;
        }
        ob = new(__DIR__"obj/kaoya");
        ob->move(me);
        me->delete_temp("kaoya");
        message_vision(CYN"冼老板转身吩咐了伙计几句，伙计将一只肥的流油的烤鸭交给了$N。\n"NOR, me);
        return 1;
}

int notice(object who)
{
    if (who)
    {
        tell_object(who,"冼老板告诉你：转账成功，你现在可以在宴客厅门厅举行宴会了，命令是yanke <此次宴客标语>。\n");
        who->set_temp("yanke/permit",1);
        return 1;
    }
}

int draw(object who)
{
    if (who->query("balance")<10000000)
    {
        tell_object(who,"冼老板说道：不好意思，你的存款不足一千两黄金，之前的宝石不退了。\n");
        return 1;
    }
    else
    {
        tell_object(who,"冼老板说道：好的，现在开始扣款，转账后你就可以开始宴会了。\n");
        who->add("balance",-10000000);
        remove_call_out("notice");
        call_out("notice",10,who);
        return 1;
    }
}

int destgem(object ob)
{
    if (ob)
    {
        destruct(ob);
    }
    return 1;
}

int cancelcheck()
{
    this_object()->delete("checking");
}
int accept_object(object who, object ob)
{       
        object xian=this_object();
        if (ob->query("money_id") && ob->value() >= 1200) 
        {
                message_vision(CYN"冼老板收下银两，对$N说道：「客官稍候，烤鸭马上出炉！」\n"NOR, this_player());
                this_player()->set_temp("kaoya",this_player()->query("mud_age"));
                return 1;
        }
        if (ob->query("newgem"))
        {
            if (who->query_temp("宴客准备"))
            {
                if (who->is_busy() || who->is_fighting())
		        {   
			        return notify_fail("你正忙着哪！\n");
                }
                if (!xian->query("yankegem/level")&&!xian->query("yankegem/material"))
                {
                    xian->set("yankegem/level",ob->query("level"));
                    xian->set("yankegem/material",ob->query("material"));
                    xian->set("yankegem/gem",ob->query("name"));
                    xian->set("checking",1);
                    call_out("cancelcheck",300);
                    tell_object(who,"冼老板道：好的，我收下你的第一颗宝石。\n");
                    who->add_busy(2);
                    who->add_temp("yanke/gemcheck",1);
                    destruct(ob);
                    return 1;
                }
                else
                {
                    if (xian->query("yankegem/level")!=ob->query("level")||xian->query("yankegem/material")!=ob->query("material"))
                    {
                        xian->delete("yankegem");
						who->delete_temp("yanke/gemcheck");
                        return notify_fail("冼老板说道：你用不一样的宝石耍我啊？之前的宝石没收了。\n");
                    }
                    else
                    {
                        if (who->query_temp("yanke/gemcheck")>=3)
                        {
                            return notify_fail("冼老板说道：已经够了，我也不想多拿你的宝石。\n");
                        }
                        who->add_temp("yanke/gemcheck",1);
                        who->add_busy(2);
                        tell_object(who,"冼老板道：好的，我收下你的第"+chinese_number(who->query_temp("yanke/gemcheck"))+"颗宝石。\n");
                        if (who->query_temp("yanke/gemcheck")>=3)
                        {
                            tell_object(who,"冼老板道：好的，大奖都帮你收好了，现在开始扣款！\n");
                            who->set_temp("yanke/gemlevel",xian->query("yankegem/level"));
                            who->set_temp("yanke/gemmaterial",xian->query("yankegem/material"));
                            who->set_temp("yanke/gemname",xian->query("yankegem/gem"));
                            xian->delete("yankegem");
                            who->delete_temp("宴客准备");
                            draw(who);
                        }
                        destruct(ob);
                        return 1;
                    }
                }
                
            }
            else
            {
                return notify_fail("冼老板对你摆手道：小的可不敢收客官的东西。\n");
            }
        }
        return notify_fail("冼老板对你摆手道：小的可不敢收客官的东西。\n");
}

