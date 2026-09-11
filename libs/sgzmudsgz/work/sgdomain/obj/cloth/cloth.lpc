#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit "/sgdomain/modules/m_cloth";
inherit M_GETTABLE;
inherit M_VALUE;

private int p_level;
private string owner="";
void set_owner(string s) {
	owner=s;
}
string query_owner() {
	return owner;
}

void set_level(int i)
{	p_level=i;
}
int query_level()
{	return p_level;
}
void setup()
{    if(file_name(previous_object())!=OBJ_D)
    {
        write("非法复制.\n");
        destruct(this_object());
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


	set_att_abi(par["att_abi"]);
        set_def_pow(par["def_pow"]);
	set_level(par["level"]); // NPC's default weapon level

    set_slot(par["sub_type"]);
	
    set_wearmsg(par["wear_msg"]);
    set_removemsg(par["rm_msg"]);
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
	ret+="等级："+sprintf("%2d",inf["level"])+"        价钱："+
		((inf["value"] < 0) ? ("无价之宝"):(CHINESE_D->chinese_value(inf["value"])))+"\n";
	ret+="攻击技能增加(攻击成功率)："+sprintf("%2d",inf["att_abi"])+
		"  防护力：+"+inf["def_pow"]+"\n";
	ret+="重量："+
		((inf["size"]>5) ? (chinese_number(inf["size"]/2)+"斤。\n")
		: "很轻\n" );
	one_name=CHAR_D->get_char(owner,"name");
	if(one_name);
		ret+="所有者："+one_name+"("+owner+")\n";
	return ret;

}

mixed direct_check_obj()
{
	return 1;
}
