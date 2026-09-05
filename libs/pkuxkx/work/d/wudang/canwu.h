//canwu.h by Zine 19/3/2011
//参悟 adv_weapon
#include <ansi.h>
string *adv_weapon_name=({"剑意","刀芒","鞭影","霸斧","枪魂","怒锤","流戟","器灵","匕魔","横杖"});
string *adv_weapon=({"sword","blade","whip","axe","spear","hammer","halberd","throwing","dagger","staff"});
string *adv_weapon_place=({"/d/wudang/jueyigu","/d/emei/qingyin","/d/yingtianfu/neicheng/qls","/d/changbai/baihe",
"/d/yuewangmu/muqian","/d/dalunsi/tianhu","/d/jinyang/yanmenguan","/d/taohuadao/jicuiting","/d/mingjiao/bishuitanpan","/d/luoyang/longmen"});
void init()
{
  add_action("do_canwu","canwu");
  add_action("do_lian",({ "lian", "practice" }));
}

int over_canwu(object me,string type)
{
    int maxlv,exp,i;
    exp = me->query("combat_exp");
	maxlv = to_int(pow(exp/100,0.333)*10);
	if (member_array(me->query("adv_weapon/current"),adv_weapon_name)==-1)
	{
		message_vision("$N仿佛失魂落魄一般，不知所云。\n",me);
        return 1;
	}
    else if (me->query("adv_weapon/class/"+type+"/accuexp")>=me->query("adv_weapon/class/"+type+"/requirexp"))
    {
            me->set("adv_weapon/class/"+type+"/accuexp",0);
            me->add("adv_weapon/class/"+type+"/lv",1);
            if (me->query("adv_weapon/class/"+type+"/lv")>me->query("adv_weapon/maxlv"))
            {
                me->set("adv_weapon/maxlv",me->query("adv_weapon/class/"+type+"/lv"));
            }
            CHANNEL_D->do_channel(this_object(), "jh", WHT+me->query("name")+"历经艰险，对"+me->query("adv_weapon/current")+"的运用有了更深的理解。", -1);
            if (member_array(me->query("adv_weapon/class/"+type+"/lv"),({9,10,11,12}))!=-1)
            {
                me->add("adv_weapon/class/"+type+"/moredamage",maxlv);
            }
            if (me->query("adv_weapon/class/"+type+"/lv")==12)
            {
                CHANNEL_D->do_channel(this_object(), "jh", WHT+me->query("name")+"掌握了"+me->query("adv_weapon/current")+"的巅峰。", -1);
            }
            me->set("adv_weapon/block",1);
    }
    else
    {
            message_vision("$N对"+me->query("adv_weapon/current")+"的参悟更精深了一层。\n",me);
            me->delete_temp("adv_weapon/canwu");
            me->add("exp_dep",-(me->query("adv_weapon/class/"+type+"/consumeexp")));
            me->add("adv_weapon/class/"+type+"/accuexp",me->query("adv_weapon/class/"+type+"/consumeexp"));
            return 1;
    }
}

int start_canwu(object me)
{
    int tick=3+random(3),no;
    if (random(me->query("kar"))>25)
    {
        tick=tick-1;
    }
    if (me->query("int")>random(60))
    {
        tick=tick-1;
    }
	if (member_array(me->query("adv_weapon/current"),adv_weapon_name)==-1)
	{
        message_vision("$N仿佛失魂落魄一般，不知所云。\n",me);
        return 1;
    }
	no=member_array(me->query("adv_weapon/current"),adv_weapon_name);
    me->set("adv_weapon/class/"+adv_weapon[no]+"/consumeexp",me->query("adv_weapon/class/"+adv_weapon[no]+"/requirexp")/100);
	if (me->query("adv_weapon/class/"+adv_weapon[no]+"/consumeexp")<150)
	me->set("adv_weapon/class/"+adv_weapon[no]+"/consumeexp",150);
	if (me->query("adv_weapon/class/"+adv_weapon[no]+"/consumeexp")>3000)
	me->set("adv_weapon/class/"+adv_weapon[no]+"/consumeexp",3000);
	if (me->query("exp_dep")<me->query("adv_weapon/class/"+adv_weapon[no]+"/consumeexp"))
	{
		tell_object(me,"你的参悟经验不足，无法参悟"+me->query("adv_weapon/current")+"。\n");
		return 1;
	}
	message_vision("$N用手比划着"+me->query("adv_weapon/current")+"的要诀，沉浸其中。\n",me);
	me->set_temp("adv_weapon/canwu",1);
	me->add_busy(tick);
	remove_call_out("over_canwu");
	call_out("over_canwu",tick,me,adv_weapon[no]);
	return 1;
}

int do_canwu()
{
	object me=this_player();
	int no;
	if (!me->query("adv_weapon/permit"))
	return 0;
	if( me->is_busy() )
	return notify_fail("你上一个动作还没有完成, 不能参悟。\n");
	if ( me->is_fighting())
	return notify_fail("你在战斗中不能参悟。\n");
	if (me->query("combat_exp")<100000)
	return notify_fail("你的经验太低，完全不能参悟。\n");
	if (me->query("adv_weapon/block"))
	return notify_fail("你似乎遇到了瓶颈，也许这时候可以回去找无名氏解惑。\n");//做个任务再升
	if (me->query_temp("adv_weapon/canwu"))
	return notify_fail("你正在参悟中，还想怎样？\n");
	if (member_array(base_name(environment(me)),adv_weapon_place)==-1)
	return notify_fail("此地毫无灵性，不利于你参悟高深武技。\n");
	no=member_array(base_name(environment(me)),adv_weapon_place);
	if (me->query("adv_weapon/amount")>=2 && (!me->query("adv_weapon/class/"+adv_weapon[no])||me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")>=3))
	return notify_fail("你参悟的武技太多，以目前的情况，无法参悟更多。\n");
	if (!me->query("adv_weapon/class/"+adv_weapon[no]))
	me->add("adv_weapon/amount",1);
	if (me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")==12)
	return notify_fail("你对"+adv_weapon_name[no]+"的领悟已经登峰造极，再无提升的余地！\n");
	if ((me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")>=4 && me->query("combat_exp")<10000000)||
		(me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")>=8 && me->query("combat_exp")<1000000*(me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")+1)*(me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")+1)))
	return notify_fail("你的经验太低，不能进一步参悟"+adv_weapon_name[no]+"。\n");
	if ((me->query_skill(adv_weapon[no],1)<200 && me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")>=5)||
		(me->query_skill(adv_weapon[no],1)<800 && me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")>=9))
	return notify_fail("你的基本功夫太差，不能进一步参悟"+adv_weapon_name[no]+"。\n");
	if (me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")<4)
	me->set("adv_weapon/class/"+adv_weapon[no]+"/requirexp",(me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")+1)*(me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")+1)*1000);
	else if (me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")<8)
	me->set("adv_weapon/class/"+adv_weapon[no]+"/requirexp",(me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")+1)*(me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")+1)*10000);
	else
	me->set("adv_weapon/class/"+adv_weapon[no]+"/requirexp",me->query("combat_exp")/100*(me->query("adv_weapon/class/"+adv_weapon[no]+"/lv")-7));
	if (me->query("exp_dep")<10000||me->query("exp_dep")<me->query("adv_weapon/class/"+adv_weapon[no]+"/requirexp")/1000)
    return notify_fail("你的参悟经验不足，无法参悟"+adv_weapon_name[no]+"。\n");
	else
	{
		me->set("adv_weapon/current",adv_weapon_name[no]);
		start_canwu(me);
		return 1;
	}
}