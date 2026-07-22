#include <ansi.h>
inherit COMBINED_ITEM;

void setup(){}

void create_name(){}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("升级仙丹", ({"xian dan", "dan"}));
        create_name();
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("base_unit", "粒");
                set("long", "一粒香气扑鼻的药丸。\n");
                set("value", 100);
                set("no_sell","仙丹有价无市啊。\n");
		set("drug_type", "良药");
        }
     	set_amount(1);
        setup();
}

string long()
{
	int lvl;
	string str = ::long();
	if( !intp(lvl=query("level")) )
		return str;
	str+= HIM"突破 "HIR+chinese_number(lvl)+"级 "HIM"专用。(需要武学经验99%)\n"NOR;
	return str;
}	

int do_eat(string arg)
{
	int lvl,succ,p,i;
	string cls,*gifts,*temp;
	mapping prop;
	object me = this_player();
        if( !arg || !id(arg) )
		return 0;
	if( !present(this_object(),me) )
		return 0;
	if( !intp(lvl=query("level")) )
		return 0;	
	if( !wizardp(me) || !me->query("env/test") )
	{		
		if( me->query_level()!=(lvl-1) )
			return err_msg(chinese_number(lvl-1)+"级专用。\n");
		p=(int)me->query("combat_exp");
        	if( p<10000000 )
        		p = p*100/me->query_max_exp();
        	else	p = p/10000*100/(me->query_max_exp()/10000);
        	if( p>100 ) p = 100;
        	if( p<99 )
        		return err_msg("你经验还差些火候，不可急急筑基。\n");
        }
	if( me->query("kee")<me->query_maxkee()
	 || me->query("eff_kee")<me->query_maxkee()
	 || me->query("sen")<me->query_maxsen()
	 || me->query("eff_sen")<me->query_maxsen()
	 || me->query("force")<me->query_maxforce()
	 || me->query("mana")<me->query_maxmana() )
	 	return err_msg("你现在的状态不是最佳状态。\n");
	if( me->is_fighting() || me->is_busy() )
		return err_msg("你现在正忙着呢。\n");
	if( environment(me)->query("no_fight")
	 || environment(me)->query("no_magic") )
	 	return err_msg("不可在安全区内尝试突破。\n");
	write("你盘膝坐下，静心冥思，仔细体验天地元气的奥妙。\n");
	message("vision",me->name()+"盘膝坐下，低头沉思，若有所得。\n",environment(me),me);
	me->start_busy(2);
	me->add("mana",-(500+(lvl-40)*5));
	me->add("force",-(500+(lvl-40)*5));
	me->receive_damage("kee",(500+(lvl-40)*2));
	me->receive_damage("sen",(500+(lvl-40)*2));
	succ = 0;
	if( random(me->query_kar()/10)>(3+(lvl-40)/10) )
		succ+= 1;
	if( random(me->query_spi()/10)>(3+(lvl-40)/10) )
		succ+= 1;
	if( random(me->query_int()/10)>(3+(lvl-40)/10) )
		succ+= 1;
	if( random(10)==6 )
		succ+= 1;
	if( wizardp(me) ) tell_object(me,"succ="+succ+"\n");		
	if( random(succ*10)>(15+(lvl-40)/10) || (wizardp(me)&&me->query("env/test")) )
	{
		write(HIY"你于沉思中，福至心灵，感觉诸多天象，道心愈加稳固，你的境界提升了！"NOR"\n");
		cls = me->query("class");
		if( !cls )
			cls = "ohter";
		switch(cls)
		{
			case "fighter" :
				message_vision(HIR"\n但见$N"HIR"浑身冲出道道战气，迎风隐现出元古战场，内有杀声震天，旌旗招展，一股股杀伐之气从中蓬勃而出，映红了半边天地！"NOR"\n\n",me);break;
			case "dragon"  :
				message_vision(HIC"\n$N"HIC"枯坐半日，忽发龙吟，惊彻天地。背后隐现四海风雷，一条条金鳞巨龙在内蜿蜒盘桓，作风雷之音！"NOR"\n\n",me);break;
			case "yaomo"   :
				message_vision(HIB"\n$N"HIB"忽的睁开赤红双眸，背后黑气缭绕，一个头生双角，面目狰狞的巨大魔影若隐若现，狰狞魔相跃跃欲出，咆哮不止！"NOR"\n\n",me);break;
			case "shen"    :
			case "xian"    :
				message_vision(HIC"\n$N"HIC"背后一时间霞光千丈，毫光四射，隐现一座仙殿。金庭玉柱，银字瑶阶，光华闪烁，被亿万道霞光瑞气包裹其中，只能隐隐的看得真面目。"NOR"\n",me);break;
			case "bonze"   :
				message_vision(HIC"\n但见$N"HIC"身后虚空之中隐现朵朵五色莲花，异香袭袭，弥漫了四周。五彩莲花毫光放出，其中一副副的图画显现出来，有天女散花、有琉璃极乐、有功德池中金龙翻滚，雷音宝刹之中，舍利悬于高空，普照大千，诸金身罗汉合掌梵唱，声音传将出来，令人俗念全消。\n\n"NOR,me);break;
			case "taoist"  :
				message_vision(HIC"\n但见$N"HIC"顶梁冲出一道清气，于半天隐现青莲，或化太极双鱼，或作龙虎交泰，翻滚不已，端是神奇。"NOR"\n\n",me);break;
			case "scholar" :
				message_vision(HIC"\n但见$N"HIC"顶梁冲出一道玄气，迎风隐现清光天幕垂下，内有浩然正气冲天，又有那儒家七十二位诸贤幻象，一时间祥云万道，瑞气千条。"NOR"\n\n",me);break;
			default :
				message_vision(HIC"\n$N"HIC"唱一声诺，顿时清音大做，背后隐现黄莲，五色祥云瑞气。又背后有诸多异象，玄之又玄。"NOR"\n\n",me);break;
		}
		if( me->level_up() )
		{
			tell_object(this_object(),HIG"【系统】你的等级提升了"HIR"1"HIG"级。\n"NOR);
			if( !me->query("mark/"+lvl+"突破奖励") )
			{
				me->set("mark/"+lvl+"突破奖励",1);
				prop = ([
					"str" : "膂力",	"cor" : "胆识",
					"int" : "悟性",	"spi" : "灵性",
					"cps" : "定力",	"per" : "魅力",
					"con" : "根骨",	"kar" : "福缘",
				]);
				gifts = keys(prop);
				temp = ({});
				for(i=0;i<sizeof(gifts);i++)
					temp+= ({gifts[random(sizeof(gifts))]});
				for(i=0;i<sizeof(temp);i++)
				{
					me->add(temp[i],1);
					tell_object(me,HIY"【系统】你的〖 "HIG+prop[temp[i]]+HIY" 〗增加了 "HIR"1"HIY" 点。\n"NOR);
				}
			}
			CHAR_D->setup_char( this_object() );
			UPDATE_D->check_user(this_object(),1);
			this_object()->powerup(0,1);
			this_object()->save(1);
			CHANNEL_D->do_channel(this_object(),"rumor","听说"+me->name(1)+NOR HIM"成功突破至 "HIY+me->level_name(me)+HIM" ！"NOR);
			if( this_object()->query_amount()==1 )
				destruct(this_object());
			else	this_object()->add_amount(-1);
			return 1;	
		}
	}
	write("奈何奈何，天道渺茫，你平白失去了一次机会，好不可惜！\n");
	message("vision",me->name()+"睁开眼来，却是露出一丝无奈神色。\n",environment(me),me);
	this_object()->save(1);
	if( this_object()->query_amount()==1 )
		destruct(this_object());
	else	this_object()->add_amount(-1);
	return 1;	
}			