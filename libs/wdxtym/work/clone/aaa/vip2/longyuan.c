#include <ansi.h>

inherit COMBINED_ITEM_BANG;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;
	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIR"龙元"NOR, ({"long yuan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("yuanbao", 111111);
            set("no_sell",1);
			set("no_give",1);
		 set("no_get", 1);
        set("no_drop", 1);
		set("no_shop", 1);//下架
        set("no_give", 1);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 10000);
		set("long","这是神龙精血的精华，据说服用十颗可以获得和打通奇经八脉一样的属性加成效果,也只能服用十颗。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int i;
	string chuan;
	string *order = ({""HIG"", ""HIY"", ""HIC"", ""GRN"", ""HIR"", ""CYN"", ""HIW"", ""HIM""});
	string *name = ({	"基础伤害",		"最大气血",		"防御激发等级",		"攻击激发等级", 		"暴击", 		 "抗暴",		 "破甲", 		 "护体"	});		
	string *shuzi = ({		   465,		     9200,		        285,		            385, 	          60, 		        35,		      365, 		   365,});		
	string *daima = ({ "damage",     "max_qi",	    "defense",		   "attack", 		      "2ap", 	      "2dp",      "break",    "armor"	});	

  if (me->is_busy())
                return notify_fail("你正忙着呢。\n");
	if (!me->query("beat"))
                return notify_fail("等你打通奇经八脉再服用吧！\n");
                
	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");
		    
	if(me->query("gift/longyuan")>= 10)
	{
		tell_object(me,"一人一生只能使用10颗！\n");
		return 1;
	}
	
	write(YEL"你运功吸收"HIR"龙元"YEL"的力量，顿时功力大增！"NOR"\n");
	
	for(i=0;i<8;i++)
	{
	chuan="gain/"+daima[i];	
	write(""+order[i]+"原"+name[i]+"附加值:"+me->query(chuan)+"。增加"+shuzi[i]+","NOR);	
	me->add(chuan,shuzi[i]);
	write(""+order[i]+"现有值："+me->query(chuan)+"。"NOR"\n");	
	}
	me->add("gift/longyuan", 1);
	i=me->query("gift/longyuan");
	write("你已经服用了"+me->query("gift/longyuan")+"颗龙元，还可以服用"+(10-i)+"颗。"NOR"\n");	
	add_amount(-1);
	return 1;
}

