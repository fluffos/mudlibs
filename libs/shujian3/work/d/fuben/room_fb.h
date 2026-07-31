
//可搜索到的物品列表
string *random_ob = ({
    "/clone/money/gold",
    "/clone/money/coin",
    "/clone/money/silver",
});

int clean_up()
{
	return 1;
}

void init()
{	
	set("no_clean_up_fb", 1);
	//识别隐藏房间
	if ( this_object()->query("anniu_hide")) 
		add_action("do_anniu", "anniu");
	if ( this_object()->query("jiguan")) 
		add_action("do_anniu", "anniu");
}
