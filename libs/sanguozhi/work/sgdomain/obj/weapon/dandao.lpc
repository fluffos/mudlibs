#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
private int p_level;
private string owner="";
string get_type() {
	string p_id=query_id()[0];
	return OBJ_D->get_obj(p_id,"sub_type");
}
void set_owner(string s) {
	owner=s;
}
string query_owner() {
	return owner;
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
}

int init_obj(string p_id)
{
	mixed par;
	par=OBJ_D->get_obj(p_id);

	set_id(p_id,par["name"]);
	add_id(p_id+" obj");
	set_unit(par["unit"]);

	set_in_room_desc("一"+par["unit"]+par["name"]+"("+p_id+")\n");

	set_size(par["size"]);
	set_gettable(1); // food always can get
	set_long(par["long"]);

    set_value(par["value"]);

	set_can_drop(par["can_drop"]);
	set_can_give(par["can_give"]);
	set_can_sell(par["can_sell"]);
	set_is_keeping(par["is_keeping"]);


	set_attack_ability(par["att_abi"]);
	set_attack_power(par["att_pow"]);
	set_level(par["level"]); // NPC's default weapon level

	set_combat_messages("combat-"+par["sub_type"]);

	set_wield_message(par["wield_message"]);
    set_unwield_message(par["unwield_message"]);
	
//		"$N『呛啷』一声抽出一柄$o，握在手中。\n");
//    set_unwield_message("$N划了一个刀花，将$o插回鞘中。\n");


}
int sg_obj() // so it is not a common obj
{
	return 1;
}

string check_obj()
{
	string ret;
	string one_name;
	object p_id=this_object()->query_id()[0];
	mixed inf;
	inf=OBJ_D->get_obj(p_id);

	ret="物品类别："+sprintf("%-8s  ",OBJ_D->type_name(inf["type"]))+"子类别："+
		OBJ_D->type_name(inf["sub_type"])+"\n";
	ret+="武器等级："+sprintf("%2d",inf["level"])+"        价钱："+
		((inf["value"] < 0) ? ("无价之宝"):(CHINESE_D->chinese_value(inf["value"])))+"\n";
	ret+="攻击技能(决定攻击成功率)：+"+sprintf("%2d",inf["att_abi"])+
		"  杀伤力：+"+inf["att_pow"]+"\n";
	ret+="重量："+chinese_number(inf["size"]/2)+"斤。\n";
	one_name=CHAR_D->get_char(owner,"name");
	if(one_name);
		ret+="所有者："+one_name+"("+owner+")\n";
	return ret;

}

mixed direct_check_obj()
{
	return 1;
}