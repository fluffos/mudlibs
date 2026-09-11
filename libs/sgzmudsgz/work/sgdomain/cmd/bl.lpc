// bl.c check if you are in the blacklist
// by fire on March 22, 2000
void start(string arg)
{
	mapping bn;
	string p_id;
	if(!AREA_D->area_exist(arg)){
		write("用法：cmd bl <a_id>, 例如：cmd bl changan"+
			"用 info a list 查阅地区列表。\n");
		return;
	}
	bn=AREA_D->get_area(arg,"bn");
//	tell_user("fire",sprintf("%O\n",bn));
	if(!mapp(bn)) bn=([]);
	p_id=this_body()->query_primary_id();
	if(!bn[p_id]) {
		write ("你不在"+AREA_D->get_area(arg,"name")+"的黑名单上。\n");
		return;
	}
	write (AREA_D->get_area(arg,"name")+"的黑名单上有你的尊姓大名\n");
}
