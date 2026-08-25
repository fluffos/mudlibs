#include <ansi.h>
#include "/wiz/ljty/ljty.h"
inherit M_HORSE_1;
inherit M_VALUE;
nosave protected mixed * horse_act=({
	"高兴地撒起欢来。\n",
	"津津有味地啃起路边的草来。\n",
	"摇摇尾巴，赶走苍蝇。\n",
	"一声长鸣，前蹄猛得立了起来。\n",
	"不知怎么发了脾气，联撂几个蹶子。\n"
});

private int p_level;
void add_hook(string, function);
private function        my_hook;
void horse_heart()
{
	string own;
	call_out("horse_heart",10+random(50));
//        own=query_owner();
	if((!find_user(own))&&(!sizeof(get_riders()))){
		tell_environment(this_object(),short()+"一溜烟跑不见了。\n");
		this_object()->remove();
		return;
	}
	tell_environment(this_object(),short()+horse_act[random(5)]);
}
void set_level(int i)
{
	p_level=i;
}
int query_level()
{
	return p_level;
}
void setup()
{
    if(file_name(previous_object())!=OBJ_D)
    {
        write("非法复制.\n");
        this_object()->remove();
        return;
    }
    if (!my_hook) {
         my_hook = (: remove_call_out :);
         add_hook("remove", my_hook);
	}
}

int init_obj(string p_id)
{
	mixed par;
	par=OBJ_D->get_obj(p_id);

	set_id(p_id,par["name"]);
	add_id(p_id+" obj");
	set_unit(par["unit"]);

	set_in_room_desc("一"+par["unit"]+par["name"]+"("+p_id+")\n");

	set_long(par["long"]);

    set_value(par["value"]);

//        set_attack_ability(par["att_abi"]);
	set_level(par["level"]); // NPC's default weapon level

    set_relations("on");
    set_preposition("on");

    set_max_capacity(par["size"]*VERY_LARGE);

	set_arrival_msg(par["arr_msg"]);
	set_departure_msg(par["dep_msg"]);

	set_ride_msg(par["up_msg"]);
	set_unride_msg(par["down_msg"]);
	call_out("horse_heart",random(10)+5);
}
int sg_obj() // so it is not a common obj
{
	return 1;
}
string check_obj()
{
	string ret;
	string own;
	object p_id=this_object()->query_primary_id();
	mixed inf;
	inf=OBJ_D->get_obj(p_id);
	ret="物品类别："+sprintf("%-8s  ",OBJ_D->type_name(inf["type"]));
	ret+="等级："+sprintf("%2d",inf["level"])+"\n价钱："+
		((inf["value"] < 0) ? ("无价之宝"):(CHINESE_D->chinese_value(inf["value"])))+"\n";
	ret+="攻击技能(决定攻击成功率)：+"+sprintf("%2d",inf["att_abi"])+"\n";
	ret+="速度："+100/inf["sp"]+ " 耐力："+inf["en"]+"\n";
	ret+="饲养消耗，金："+inf["fe"][0]+" 粮："+inf["fe"][1]+"\n";
	ret+="负重："+chinese_number(inf["size"])+"人。\n";

//        own=query_owner();
	if(sizeof(own))
	{	own=CHAR_D->get_char(own,"name")+"("+own+")";
		ret+="马主人："+own+"\n";
	}
	return ret;

}

mixed direct_check_obj()
{
	return 1;
}

mixed is_troop() {
   object env;
   env=environment(this_object());
   if(!objectp(env)) return 0;
   return env->is_troop();
}
