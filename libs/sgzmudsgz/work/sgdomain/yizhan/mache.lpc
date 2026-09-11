#include <mudlib.h>

inherit BASE_ROOM;

string *desc = ({
	"车夫扬起手中鞭，吆喝着：看车，看车！\n",
	"你坐在马车里，浑然不知外面的情景。\n",
	"马车晃晃悠悠，停停走走，不知过多久。。。\n",
	"你不耐烦的向外张望着：还要走多久？\n",
	"车夫用力的挥了几下鞭子。\n",
	"路上没有一个行人，马车越来越快了。\n",	
});
void right_place(object ob, string dest);

void setup()
{
	set_light(50);
	set_brief("马车里");
	set_long("一辆宽敞的马车，正慢慢的前进着。\n");	
}
void destruct_itself(object ob, int time, string dest)
{
//       if(environment(ob)!=this_object())
//                     destruct( this_object() );  // added by fire
	remove_call_out("destruct_itself");
	time = time - 4;
	if( time < 4 )call_out("right_place", time, ob, dest);
	else {
//		printf( desc[random(sizeof(desc))] );
		tell_from_outside(this_object(),desc[random(sizeof(desc))]);
		call_out("destruct_itself", 4, ob, time, dest);
	};
	return;
}
void right_place(object ob, string dest)
{
	string path, name;
	object env;
	object *obs;
	int i;
	path = AREA_D->get_area(dest, "path");
        name = AREA_D->get_area(dest, "go");
        if(!name) name=AREA_D->get_area(dest,"fly");
	env = load_object( path + name);
	this_object()->move( env );
//	ob->move( env );
	tell_environment( this_object(), "一辆马车缓缓的移动过来。\n");
	tell_from_inside (this_object(),
        sprintf("大车终于停了下来，车夫掀开车门道：%s已到，请下车。\n",
		AREA_D->get_area(dest,"name")));
	obs=all_inventory(this_object());
	if(sizeof(obs)) {
		for(i=0;i<sizeof(obs);++i) {
			if(obs[i]->is_living()) {
				obs[i]->move(env);
				obs[i]->simple_action("$N从马车上跳了下来。\n");
			}
		}
	}
//        ob->simple_action("$N从马车上跳了下来。\n");
	tell_environment(this_object(),"车夫一扬皮鞭，道：诸位，回见。\n不一会儿，马车就消失在漫天尘土之中了。\n");
    destruct( this_object() );
	return;
}
