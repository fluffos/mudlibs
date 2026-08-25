// base.c for players by fire on 30/Jan/2000

#include <mudlib.h>
#define BASE_SERVER "/sgdomain/base/base_server/"
inherit CMD;

private void main(string arg)
{
	string p_area;
    mixed * bases;
	string f_name;
	object ob;
	p_area=this_body()->query_room()->get_area();

	if(!AREA_D->area_exist(p_area)) {
		write("这里不是三国地区。\n");
		return;
	}

	f_name=file_name(this_body()->query_room());
	if(f_name!=(AREA_D->get_area(p_area,"path")+AREA_D->get_area(p_area,"go"))) {
		write("只有从城门口才能进入生产基地。\n");
		return;
	}
	bases=AREA_D->get_area(p_area,"base");
	if(!sizeof(bases)) {
		write("本地区没有任何生产基地。\n");
		return;
	}
	if(sizeof(bases)>1) {
		if(member_array(arg,bases)==-1) {
			write("你要进入哪个生产基地呀。\n");
			foreach(string b in bases) {
				write(BASE_D->get_base(b,"name")+"("+b+") " );
			}
			write("\n");
			write("用 base <id> 进入特点的生产基地。\n");
			return;
		}
	}
	else arg=bases[0];

	this_body()->simple_action("$N到"+BASE_D->get_base(arg,"name")+
		"去了。\n");

     ob = load_object(BASE_SERVER+p_area+"/"+arg+"/enter");
	 if(objectp(ob)) {
			this_body()->move(ob);
	        this_body()->do_game_command("look");
			this_body()->other_action("$N进入了"+BASE_D->get_base(arg,"name"));
	 }
     return;
}

