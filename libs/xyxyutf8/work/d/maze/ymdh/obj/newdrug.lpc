#include <ansi.h>
inherit ITEM;

mapping tt = ([
        "combat_exp" : "武学经验",
        "daoxing"       : "道行",
        "combat_exp"    : "武学经验",
        "potential"     : "潜能",
        
        "str"           : "膂力",
        "cor"           : "胆识",
        "int"           : "悟性",
        "spi"           : "灵性",
        "cps"           : "定力",
        "per"           : "魅力",
        "con"           : "根骨",
        "kar"           : "福缘",

        "kee"           : "气血",
        "sen"           : "精神",
        "force"         : "内力",
        "mana"          : "法力",
]);      
        
string query_target();
string query_type();
int query_time();
int query_pot();
string query_eat_msg();

void init()
{
	if( environment() && userp(environment()) )
        {
        	if( !query("geted") )
           	{
           		if( environment()->query("env/brief_message")!=3 )
           			CHANNEL_D->do_channel(this_object(),"rumor","听说"+environment()->name()+HIM"得到了"NOR HBWHT+HIM+name()+NOR HIM"。"NOR);
           		tell_object(environment(),HIY"你得到了"+name()+HIY"。\n"NOR);
           		set("geted",1);
           	}
        }
	add_action("do_eat", "eat");
}

string query_eat_msg()
{
	return HIG"$N"HIG"轻轻掰开一颗$n"HIG"一时间香气四溢。只见$N"HIG"脸上慢慢泛出红晕，看起来有精神多了！\n"NOR;
}

int do_eat(string arg)
{
	object me = this_player();
	if( !arg || !id(arg) )
        	return 0;
	if( time()<me->query_temp("ad_apply/"+query_target()+"/"+query_type()+"/start")
	 +me->query_temp("ad_apply/"+query_target()+"/"+query_type()+"/time") )
		return err_msg("你上次使用的同类型的道具效果尚未消失，暂时不能累加使用。\n");
	me->set_temp("ad_apply/"+query_target()+"/"+query_type(),([
        	"start" : time(),
        	"time"  : query_time(),
        	"pot"   : query_pot(),
	]));          
	message_vision(query_eat_msg(),me,this_object());
	destruct(this_object());
	return 1;
}

string name()
{
	string arg,str="";

	if( query_pot()<=100 ) 
        	arg = "";
	else if( query_pot()<=110 )
        	arg = "低阶";
	else if( query_pot()<=125 )
        	arg = "中阶";
	else if( query_pot()<=150 )
        	arg = "上阶";
	else    arg = "天阶";
	switch(query_target())
        {
        	case "lijing" : str+= "天宫灭妖";break;
		case "rulai_杀"  : str+= "如来杀怪";break;
        	case "rulai_擒"  : str+= "如来擒怪";break;
        	case "rulai_劝"  : str+= "如来劝怪";break;
        	case "rulai_add_杀"  : str+= "☆如来杀怪";break;
        	case "rulai_add_擒"  : str+= "☆如来擒怪";break;
        	case "rulai_add_劝"  : str+= "☆如来劝怪";break;
		case "letter" : str+= "送信任务";break;
        	case "yuan"   : str+= "天监灭妖";break;
        	case "menpai" : str+= "门派任务";break;
        	case "xue"    : str+= "逃犯任务";break;
        	case "killer" : str+= "杀手任务";break;
        	case "feizei" : str+= "飞贼任务";break;
        	default       : str+= "神秘任务";break;
        }
	str = str+arg+::name();
	return str;
}               
                
string long()
{
	string str = "";
	switch(query_target())
        {
        	case "lijing" : str+= "李靖任务";break;
        	case "rulai_杀"  : str+= "如来杀怪任务";break;
        	case "rulai_擒"  : str+= "如来擒怪任务";break;
        	case "rulai_劝"  : str+= "如来劝怪任务";break;
	        case "rulai_add_杀"  : str+= "如来杀怪任务追加";break;
        	case "rulai_add_擒"  : str+= "如来擒怪任务追加";break;
        	case "rulai_add_劝"  : str+= "如来劝怪任务追加";break;
        	case "yuan"   : str+= "天监任务";break;
        	case "menpai" : str+= "门派任务";break;
        	case "xue"    : str+= "逃犯任务";break;
        	case "killer" : str+= "杀手任务";break;
        	case "feizei" : str+= "飞贼任务";break;
        	default       : str+= "神秘任务";break;
        }
	return "能在 "NOR HIR+CHINESE_D->chtime(query_time())+NOR"内使得你的 "HIR+str+NOR" 的 "NOR HIR+tt[query_type()]+NOR" 增加为平时的 "HIR+query_pot()+"% "NOR"的道具。\n";
}

