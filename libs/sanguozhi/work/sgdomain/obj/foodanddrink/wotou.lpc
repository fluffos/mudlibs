// wotou.c 窝头，cheap food
// by fire on Jan 1999
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
inherit M_VALUE;
void setup()
{
    if(file_name(previous_object())!=OBJ_D)
    {
            write("非法复制.\n");
            this_object()->remove();
            return;
    }
	/*set_id("wotou", "窝头");
    set_long("黄黄的窝头，引不起人的一点食欲。");
	set_eat_val(10);
    set_size(SMALL);
    set_gettable(1);
    set_num_eats(10);
    set_unit("枚");
	set_can_drop("窝头虽然难吃，也不能乱扔呀。\n");
	set_can_give("这种烂窝头也好意思给人。\n");
    set_eat_action("$N咬了一口窝头，真难吃，差点没吐出来。\n");
    set_last_eat_action("$N把剩下的窝头一把塞进嘴里，嚼都没敢嚼就咽了下去。\n");*/
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

    set_currency_type(par["currency_type"]);
    set_value(par["value"]);

	set_eat_val(par["eat_val"]);
	set_drink_val(par["drink_val"]);
	set_num_eats(par["num_eats"]);		//能吃多少次
	set_eat_action(par["eat_action"]);	//吃的动作显示，或者一个函数名字
	set_last_eat_action(par["last_eat_action"]);//最后一次吃的显示

	set_can_drop(par["can_drop"]);
	set_can_give(par["can_give"]);
	set_can_sell(par["can_sell"]);
	set_is_keeping(par["is_keeping"]);
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
	ret+="食物恢复："+sprintf("%+d\n",inf["eat_val"])+
		"饮水恢复："+sprintf("%+d\n",inf["drink_val"])+
		"价钱："+
		((inf["value"] < 0) ? ("无价之宝"):(CHINESE_D->chinese_value(inf["value"])))+"\n";
	ret+="能吃几口："+sprintf("%d",inf["num_eats"])+
		"\n还乘几口："+this_object()->query_num_eats()+"\n";
	return ret;

}

mixed direct_check_obj()
{
	return 1;
}