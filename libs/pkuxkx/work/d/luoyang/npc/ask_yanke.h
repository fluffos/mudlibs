// modified by Zine 10/4/2011 add 宴客功能给玩家
#include <ansi.h>


int ask_yanke()
{
    object me = this_player();
    object ob = this_object();
    object gd = load_object(ob->query("palace"));
    if (me->is_busy() || me->is_fighting())
		{
            tell_object(me,"你正忙着哪！\n");
			return 1;
        }
    if (gd->query("yanke")||gd->query("lingjiang"))
    {
        command("say 宴客厅此时正在使用，你迟些再来吧。");
        return 1;
    }
    if (me->query("balance")<10000000)
    {
        command("say 宴客举行极尽奢华，一次需要花费一千两黄金，我看你的钱不够啊！");
        return 1;
    }
    if (me->query("age")<18)
    {
        command("say 小朋友乱花家里的钱可不好。");
        return 1;
    }
    if (me->query_temp(ob->query("yanke_no")+"/permit"))
    {
        command("say 你准备什么时候开席？\n");
        return 1;
    }
    if (ob->query("checking"))
    {
        command("say 请稍等一下。\n");
        return 1;
    }
    else
    {
        command("say 那我把宴客的流程跟你简单说一下。");
        command("say 首先，宴席不能没有奖品，不然不会有人捧场。");
        command("say 所以，我需要你提供三颗同款的宝石作为奖品。");
        command("say 要注意的是，如果你提供了不同的宝石，弄错了我是不会退给你的，嘿嘿！");
        command("say 宝石检查完后，我会直接在你账上扣一千两，假如账户不足，宝石也不会退的。");
        command("say 之后你就可以开始宴客了。");
        me->set_temp(ob->query("yanke_no")+"prepare",1);
        return 1;
    }
}

int notice(object who)
{
    object ob=this_object();
    if (who)
    {
        command("tell "+who->query("id")+" 转账成功，你现在可以在宴客厅门厅举行宴会了，命令是yanke <此次宴客标语>。\n");
        who->set_temp(ob->query("yanke_no")+"/permit",1);
        return 1;
    }
}

int draw(object who)
{
    if (who->query("balance")<10000000)
    {
        command("tell "+who->query("id")+" 不好意思，你的存款不足一千两黄金，之前的宝石不退了。\n");
        return 1;
    }
    else
    {
        command("tell "+who->query("id")+" 好的，现在开始扣款，转账后你就可以开始宴会了。\n");
        who->add("balance",-10000000);
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
        object du=this_object();
        if (ob->query("newgem"))
        {
            if (who->query_temp(du->query("yanke_no")+"prepare"))
            {
                if (who->is_busy() || who->is_fighting())
		        {   
			        return notify_fail("你正忙着哪！\n");
                }
                if (!du->query("yankegem/level")&&!du->query("yankegem/material"))
                {
                    du->set("yankegem/level",ob->query("level"));
                    du->set("yankegem/material",ob->query("material"));
                    du->set("yankegem/gem",ob->query("name"));
                    du->set("checking",1);
                    call_out("cancelcheck",300);
                    command("tell "+who->query("id")+" 好的，我收下你的第一颗宝石。\n");
                    who->add_busy(2);
                    who->add_temp(du->query("yanke_no")+"/gemcheck",1);
                    call_out("destgem",1,ob);
                    return 1;
                }
                else
                {
                    if (du->query("yankegem/level")!=ob->query("level")||du->query("yankegem/material")!=ob->query("material"))
                    {
                        du->delete("yankegem");
						who->delete_temp(du->query("yanke_no")+"/gemcheck");
                        return notify_fail(du->query("name")+"说道：你用不一样的宝石耍我啊？之前的宝石没收了。\n");
                    }
                    else
                    {
                        if (who->query_temp(du->query("yanke_no")+"/gemcheck")>=3)
                        {
                            return notify_fail(du->query("name")+"说道：已经够了，我也不想多拿你的宝石。\n");
                        }
                        who->add_temp(du->query("yanke_no")+"/gemcheck",1);
                        who->add_busy(2);
                        command("tell "+who->query("id")+" 好的，我收下你的第"+chinese_number(who->query_temp(du->query("yanke_no")+"/gemcheck"))+"颗宝石。\n");
                        if (who->query_temp(du->query("yanke_no")+"/gemcheck")>=3)
                        {
                            tell_object(who,du->query("name")+"道：好的，大奖都帮你收好了，现在开始扣款！\n");
                            who->set_temp(du->query("yanke_no")+"/gemlevel",du->query("yankegem/level"));
                            who->set_temp(du->query("yanke_no")+"/gemmaterial",du->query("yankegem/material"));
                            who->set_temp(du->query("yanke_no")+"/gemname",du->query("yankegem/gem"));
                            du->delete("yankegem");
                            who->delete_temp(du->query("yanke_no")+"prepare");
                            draw(who);
                        }
                        call_out("destgem",1,ob);
                        return 1;
                    }
                }
                
            }
            else
            {
                return notify_fail(du->query("name")+"对你摆手道：小的可不敢收客官的东西。\n");
            }
        }
        return notify_fail(du->query("name")+"对你摆手道：小的可不敢收客官的东西。\n");
}

