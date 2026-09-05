// yhzzyahoo 2015.6.4 ,铜雀台
#include <ansi.h>
inherit ITEM;
string *specialsk=({
    "corporeity","ironskin","health","energy","chainless","sociability","greedy","agile",
    "might","spirituality","athanasy","intellect","constitution","perceive","lucky",   
    });      
    
string *specialsk_cn=({
    "固本培元","铜皮铁骨","气息悠长","聚精会神","金蝉脱壳","长袖善舞","饕餮之力","身轻如燕",
    "力大无穷","灵气逼人","凤凰涅磐","聪明睿智","镇蕴七星","传音搜魂","洪福齐天",   
    });      
        
string random_special(object who);

void init()
{
	add_action("do_jingdu", "jingdu");
}

void create()
{
	set_name(HIR"特技研究秘籍"NOR, ({ "tj_yanjiu miji"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本特技研究的秘籍(据说是北侠神秘人物所著)，你可以精读(jingdu)它。\n");
			set("unit", "本");
		}
}

int do_jingdu()
{
   int lv_m,special_cnt;//自身等级
   int now_pot;//身上带的pot
   string special_skill,special_skill_cn;

    object me=this_player();
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你翻了翻这本武功秘籍，却觉得过于晦涩难懂。\n");
        return 1;
    }
   // tell_object(me,"你准备新添一个特技了！\n"); 
	special_cnt=sizeof(me->query("special_skill"));

   if (special_cnt>10)
   {
		return notify_fail("你的特技已经太多了，不能再增加了，再增加服务器该爆了。\n");
   }

	lv_m=me->query("level");
	now_pot=to_int(me->query("potential") - me->query("learned_points"));
	if (me->query("safari_special/special_bit"))
	{
		return notify_fail("你已经取得过这个特技，哈哈哈哈，积分白花了吧。\n");
	}
	if (special_cnt<4)
	{
		if (lv_m<100)
		{
			return notify_fail("你的人物等级不够。\n");
		}

	}
	else
	{
		if (lv_m<106)
		{
			return notify_fail("你的人物等级不够。\n");
		}
	}
	if (me->query("safari_credit")<9)
	{
		return notify_fail("你的铜雀台积分不够。\n");
	}
	if(me->query("balance") < 500000000)  
		 return notify_fail("你的钱庄存款不足，至少需要花费50000两金子才能取得特技。\n");
	if (now_pot<3000000)
	{
		 return notify_fail("你的潜能不足，至少需要花费3000000点潜能才可以取得特技！\n");
	}
	if(me->query("combat_exp") < 10000000)
		 return notify_fail("你的经验不足，至少需要花费10000000点经验才可以取得特技！\n");

    special_skill = random_special(me);
    special_skill_cn = specialsk_cn[member_array(special_skill,specialsk)];

	me->add("combat_exp",-10000000);
	me->add("balance",-500000000);
	me->add("potential",-3000000);
	me->add("safari_credit",-9);
	me->set("safari_special/special_bit",1);
    tell_object(me,"你学会了"+HIG+special_skill_cn+NOR+"这个特技！\n");        
    CHANNEL_D->do_channel(this_object(), "jh", "铜雀台："+me->query("name")+"("+capitalize(me->query("id"))+")根骨神奇，特立独行！\n",-1);
    me->set("special_skill/"+special_skill,1);
	me->save();
	message_vision("$N很诡异地无风自燃起来了。\n",this_object());
	destruct(this_object());
	return 1;
}

string random_special(object who)
{
        string msg;
        while(1)
        {
         msg=specialsk[random(sizeof(specialsk))];
         if(who->query("special_skill/"+msg)) continue;
         break;
        } 
        return msg;    
}
