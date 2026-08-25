// shuihu.c by fire on 1999, Jan
inherit OBJ;
inherit M_GETTABLE;
inherit "/std/modules/m_drinkable2";
inherit M_VALUE;

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

	set_eat_val(par["eat_val"]);
	set_drink_val(par["drink_val"]);

	set_max_drinks(par["num_drinks"]);

	set_drink_action(par["drink_action"]);
	set_last_drink_action(par["last_drink_action"]);

	set_can_drop(par["can_drop"]);
	set_can_give(par["can_give"]);
	set_can_sell(par["can_sell"]);
}
int sg_obj() // so it is not a common obj
{
	return 1;
}

string check_obj()
{
	string ret;
	object p_id=this_object()->query_id()[0];
	mixed inf;
	inf=OBJ_D->get_obj(p_id);

	ret="物品类别："+sprintf("%-8s  ",OBJ_D->type_name(inf["type"]))+"\n";
	ret+="饮水恢复："+sprintf("%+d\n",inf["drink_val"])+
		"食物恢复："+sprintf("%+d\n",inf["eat_val"])+
		"价钱："+
		((inf["value"] < 0) ? ("无价之宝"):(CHINESE_D->chinese_value(inf["value"])))+"\n";
	ret+="能喝几口："+sprintf("%d",inf["num_drinks"])+
		"\n还乘几口："+this_object()->query_num_drinks()+"\n";
	return ret;

}

mixed direct_check_obj()
{
	return 1;
}