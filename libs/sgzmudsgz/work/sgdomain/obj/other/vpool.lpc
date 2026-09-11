// vpool.c 池塘边
inherit OBJ;
void setup()
{
  set_attached(1);
  set_unit("片");
  set_id("pool","池塘", "water","chitang");
  set_long("就是一个普通的小池塘，游游泳还是不错。");
}
int swim(string s)
{
	int p_hp,p_sjlev,p_sjexp;
	p_hp=this_body()-> query_cur_hp();
	p_sjlev=this_body()->query_sk_level("jbsj");
	p_sjexp=this_body()->query_sk_exp("jbsj");
	if (p_hp<15)
	{ write("这么累了还敢游，不怕淹死呀。\n");
	this_body()->other_action("$N脱了衣服准备往池塘里跳，犹豫了半天又没跳下去。\n");
	return 1;
	}
	write ( "你跳到池塘里，尽情地游了一会，爬上岸时，感到心情异常舒畅。\n");
	this_body()->other_action("$N跳到了池塘里，胡乱扑腾了一阵就上来了\n");
	this_body()->do_game_command("xixi");
	if((p_sjlev<30) && (p_sjexp<1000))
	{
	write("你的游泳技术提高了。\n");
	this_body()->set_sg_skill("jbsj", p_sjlev, p_sjexp+10);
	}
	this_body()->set_cur_hp(p_hp-12);
	return 1;
}
         
