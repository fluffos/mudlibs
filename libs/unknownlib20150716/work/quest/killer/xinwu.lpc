//130级
#include <ansi.h>
inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "po");
}

void create()
{
        set_name("生死信物", ({"shengsi xinwu", "xin", "xinwu","wu"}));
	set("base_weight",1);
	set("base_unit", "个");
        set("unit", "些");
        set("long", "这是见证了生死之间奥妙的勇者才配拥有的信物。\n"HIR"据说集齐了10个信物，将能从中窥破(po)生死奥妙，从而突破合体限制。"NOR"\n");
        set("value", 0);
	set("no_give",1);
	set("no_drop",1);
	set("no_get",1);
	set("changed",1);
	set_amount(1);
        setup();
}

int do_eat(string arg)
{
	string cls,*gifts,*temp;
	mapping prop;
	int i,succ = 0;
	object me = this_player();
	if( !present(this_object(),me) )
		return 0;
	if( query_amount()<10 )
		return 0;
	if( query("owner_id") && query("owner_id")!=me->query("id") )
		return 0;	
	if( me->query_level()!=129 )
		return err_msg("以你目前的境界，看来是不需要这个。\n");
	if( me->query_max_exp()-me->query("combat_exp")>500000 )
		return err_msg("你目前的武学经验还没达到瓶颈，用这个纯属浪费。\n");
	if( me->query("kee")<me->query_maxkee()
	 || me->query("eff_kee")<me->query_maxkee()
	 || me->query("sen")<me->query_maxsen()
	 || me->query("eff_sen")<me->query_maxsen()
	 || me->query("force")<me->query_maxforce()
	 || me->query("mana")<me->query_maxmana() )
	 	return err_msg("你现在的状态不是最佳状态。\n");
	if( me->is_fighting() || me->is_busy() )
		return err_msg("你现在正忙着呢。\n");
	write("你盘膝坐下，过往种种厮杀如走马灯般在脑海中不停盘旋，你沉浸其中，若有所思。\n");
	message("vision",me->name()+"盘膝坐下，低头沉思，若有所得。\n",environment(me),me);
	me->start_busy(2);
	me->add("mana",-500);
	me->add("force",-500);
	me->receive_damage("kee",800);
	me->receive_damage("sen",800);
	if( random(me->query_kar()/10)>5 )
		succ+= 1;
	if( random(me->query_spi()/10)>4 )
		succ+= 1;
	if( random(me->query_int()/10)>4 )
		succ+= 1;
	if( random(10)==6 )
		succ+= 1;
	if( wizardp(me) ) tell_object(me,"succ="+succ+"\n");		
	if( random(succ*10)>15 || (wizardp(me)&&me->query("env/test")) )
	{
		write(HIY"你于沉思中，福至心灵，感觉诸多天象，道心愈加稳固，你的境界提升了！"NOR"\n");
		cls = me->query("class");
		if( !cls )
			cls = "ohter";
		switch(cls)
		{
			case "fighter" :
				message_vision(HIR"\n但见$N"HIR"浑身冲出道道战气，迎风幻化出元古战场，内有杀声震天，旌旗招展，一股股杀伐之气从中蓬勃而出，映红了半边天地！"NOR"\n\n",me);break;
			case "dragon"  :
				message_vision(HIC"\n$N"HIC"枯坐半日，忽发龙吟，惊彻天地。背后幻现四海风雷，一条条金鳞巨龙在内蜿蜒盘桓，作风雷之音！"NOR"\n\n",me);break;
			case "yaomo"   :
				message_vision(HIB"\n$N"HIB"忽的睁开赤红双眸，背后黑气缭绕，一个头生双角，面目狰狞的巨大魔影若隐若现，狰狞魔相跃跃欲出，咆哮不止！"NOR"\n\n",me);break;
			case "shen"    :
			case "xian"    :
				message_vision(HIC"\n$N"HIC"背后一时间霞光千丈，毫光四射，隐现一座仙殿。金庭玉柱，银字瑶阶，光华闪烁，被亿万道霞光瑞气包裹其中，只能隐隐的看得真面目。"NOR"\n",me);break;
			case "bonze"   :
				message_vision(HIC"\n但见$N"HIC"身后虚空之中涌出朵朵五色莲花，异香袭袭，弥漫了四周。五彩莲花毫光放出，其中一副副的图画显现出来，有天女散花、有琉璃极乐、有功德池中金龙翻滚，雷音宝刹之中，舍利悬于高空，普照大千，诸金身罗汉合掌梵唱，声音传将出来，令人俗念全消。\n\n"NOR,me);break;
			case "taoist"  :
				message_vision(HIC"\n但见$N"HIC"顶梁冲出一道清气，于半天或化三朵青莲，或化太极双鱼，或作龙虎交泰，翻滚不已，端是神奇。"NOR"\n\n",me);break;
			case "scholar" :
				message_vision(HIC"\n但见$N"HIC"顶梁冲出一道玄气，迎风化作清光天幕垂下，内有浩然正气冲天，又有那儒家七十二位诸贤幻象，一时间祥云万道，瑞气千条。"NOR"\n\n",me);break;
			default :
				message_vision(HIC"\n$N"HIC"唱一声诺，顿时清音大做，背后涌起千朵黄色莲花，五色祥云瑞气。又背后有诸多异象，玄之又玄。"NOR"\n\n",me);break;
		}
		if( me->level_up() )
		{
			tell_object(this_object(),HIG"【系统】你的等级提升了"HIR"1"HIG"级。\n"NOR);
			if( !me->query("mark/130突破奖励") )
			{
				me->set("mark/130突破奖励",1);
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
			if( me->query("class")!="yaomo" && me->query("class")!="bonze" )
				CHANNEL_D->do_channel(this_object(),"rumor","听说"+me->name(1)+HIM"堪破生死奥妙，道心弥固，已达"HIY"渡劫"HIM"境界！"NOR);
			else	CHANNEL_D->do_channel(this_object(),"rumor","听说"+me->name(1)+HIM"堪破生死奥妙，境界突破，已达"HIY"大乘"HIM"境界！"NOR);	
			if( this_object()->query_amount()==10 )
				destruct(this_object());
			else	this_object()->add_amount(-10);
			return 1;	
		}
	}
	write("奈何奈何，天道渺茫，你平白失去了一次机会，好不可惜！\n");
	message("vision",me->name()+"睁开眼来，却是露出一丝无奈神色。\n",environment(me),me);
	this_object()->save(1);
	if( this_object()->query_amount()==10 )
		destruct(this_object());
	else	this_object()->add_amount(-10);
	return 1;	
}	