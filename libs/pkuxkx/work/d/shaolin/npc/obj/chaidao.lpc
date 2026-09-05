// chaidao.c
//seagate@pkuxkx 2010/10/09

#include <weapon.h>

inherit BLADE;
int do_pi(string);

void create()
{
        set_name("柴刀", ({ "chai dao", "dao", "blade" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "iron");
                set("long", "这是一柄铁制的柴刀，上面有些缺口，看来僧人常用它来劈(pi)柴。\n");
                set("wield_msg", "$N抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插回腰间。\n");
                set("shaolin",1);
        }
        init_blade(15);
        setup();
}

void init()
{
	add_action("do_pi","pi");
}

//装备柴刀在身的时候可以去木墩劈柴，劈柴如果刀法不够精湛，最高有10%几率会失败，到100级以上就永远100%成功率。
//劈柴70%几率获得基本刀法的提高，最高等级150级，获得经验是1+先天臂力/10+刀法等级/10。
//有30%几率获得基本剑法的提高，最高等级150级，获得经验公式同上。
int do_pi(string arg)
{
	string name;
	string *prefix=({"yicun","liangcun","sancun"});
	mapping wood=([
	  "松柴":"songchai",
	  "柏柴":"bochai",
	  "杨柴":"yangchai",
//	  "柳柴":"liuchai",
//	  "槐柴":"huaichai"
	  ]);
	object me,ob;
	int inch,size,blade,lucky,exp;
	
	me=this_player();
	
	if(!arg) {
		printf("命令格式：pi 数字，其中数字代表要劈成多宽的木柴。\n");
		return 1;
	}
	else if(!sscanf(arg,"%d",inch)) {
		printf("命令格式：pi 数字，其中数字代表要劈成多宽的木柴。\n");
		return 1;
	}
	else if(inch>3||!inch) {
		printf("木柴只能将木柴加工成一寸宽、二寸宽、三寸宽三种规格。\n");
		return 1;
	}
	else if(environment(me)->query("short")!="厨房后院") {
		printf("这里没有木墩怎么劈柴啊？\n");
		return 1;
	}
	else if(!me->query_temp("quest_pichai/putwood")) {
		printf("木墩上什么东西都没有，你怎么劈柴？\n");
		return 1;
	}
	else if(!me->query_temp("quest_pichai/reqwood")) {
		printf("中年僧人一把推开你，喊道：“没看见我正在劈柴吗？”\n");
		return 1;
	}
	else if(!me->query_temp("quest_pichai/chaidao")) {
		printf("中年僧人一把推开你，喊道：“没看见我正在劈柴吗？”\n");
		return 1;
	}
	else if(environment(this_object())!=me) {
		printf("你没有把柴刀装备在身上，怎么用它来劈柴？\n");
		return 1;
	}
	else if(!query("equipped")) {
		printf("你没有把柴刀装备在身上，怎么用它来劈柴？\n");
		return 1;
	}
	else if(me->is_busy()||me->is_fighting()) {
		printf("你现在正忙着呢。\n");
		return 1;
	}
	else if(me->query("qi")<this_player()->query("max_qi")*80/100) {
		printf("你已经非常疲劳了，休息休息再劈柴吧。\n");
		return 1;
	}
	
	size=me->query_temp("quest_pichai/size");
	
//未处理木柴尺寸过小的时候劈下来就会把木柴劈碎了，木柴原始尺寸范围是3-8，每成功劈一刀都会减去相应尺寸。
	if(size<inch) {
		tell_object(me,"这根"+me->query_temp("quest_pichai/name")+"实在太小了，你一不小心就把木柴整个劈碎了。\n");
		me->delete_temp("quest_pichai/putwood");
		me->delete_temp("quest_pichai/name");
		me->delete_temp("quest_pichai/material");
		me->delete_temp("quest_pichai/size");
		me->start_busy(1);
		return 1;
	}
	else {
		size=size-inch;
		me->set_temp("quest_pichai/size",size);
		blade=me->query_skill("blade",1);
		lucky=1900+blade;
    
//刀法没过100级的时候最高会有70%的几率会把木柴给劈坏了。		
		if(random(2000)>lucky) {
			tell_object(me,"你用力过大，一不小心把整根木柴都劈碎了。\n");
			me->delete_temp("quest_pichai/putwood");
			me->delete_temp("quest_pichai/name");
			me->delete_temp("quest_pichai/size");
			me->delete_temp("quest_pichai/material");
			me->start_busy(1);
		}
		else {
			exp=1+me->query("str")/10+blade/10;

//在这里决定木柴的材质，为了保证同样的原料出来的成品都是一种材质。			
			if(!me->query_temp("quest_pichai/material")) {
				name=keys(wood)[random(1000)%sizeof(keys(wood))];
				me->set_temp("quest_pichai/material",name);
			}
			else
				name=me->query_temp("quest_pichai/material");
			
			if(size>0)
				tell_object(me,"你往"+me->query_temp("quest_pichai/name")+"上劈了一刀，劈下一根"+chinese_number(inch)+"寸宽的"+name+"。\n");
			else {
				tell_object(me,"你往"+me->query_temp("quest_pichai/name")+"上小心地劈了一刀，劈出一根"+chinese_number(inch)+"寸宽的"+name+"。\n");
				me->delete_temp("quest_pichai/putwood");
				me->delete_temp("quest_pichai/name");
				me->delete_temp("quest_pichai/size");
				me->delete_temp("quest_pichai/material");
			}
				
			ob=new(__DIR__"wood2");
			ob->set_name(chinese_number(inch)+"寸宽的"+name, ({prefix[inch-1]+" "+wood[name],"wood"}));
			ob->set("owner",me->query("id"));
			ob->move(me);
			
			if(random(100)<30&&me->query_skill("sword",1)<=150) {
				tell_object(me,"你在劈柴的过程中触类旁通，在用剑的诀窍上有了更深的理解。\n");
				me->improve_skill("sword",exp);
			}
			else if(blade<=150) {
				tell_object(me,"你在劈柴的过程中触类旁通，在用刀的诀窍上有了更深的理解。\n");
				me->improve_skill("blade",exp);
			}
			me->receive_damage("qi",me->query("combat_exp")>10000?to_int(log(to_float(me->query("combat_exp"))/10000)):1);
			me->start_busy(1);
		}
		return 1;
	}
}