#include <mudlib.h>

inherit BASE_ROOM;

string *desc = ({
	"你往红红的轿帘外看去，却什么也看不清楚。\n",
	"你想着他的样子，一片红云飘上了脸颊。\n",
	"轿子晃悠悠的在走，你的心也晃悠悠在动。\n",
	"你悄悄掀开大红布头的一角来，偷偷的往轿外看。\n",
	"喜乐声声，想着今天晚上。。。你羞红了脸。\n",
	"大家在看我吧。。。你想起他，心里泛起一阵甜蜜。\n",	
});
void right_place(object ob, string dest);

void setup()
{
	set_light(50);
	set_brief("花轿中");
	set_long("新娘子的花轿子，大红大红的好不喜气洋洋。\n");	
}
void destruct_itself(object ob, string boy)
{
//       if(environment(ob)!=this_object())
//                     destruct( this_object() );  // added by fire
	string roomb, roomd;
	object envi;
	
	remove_call_out("destruct_itself");
	roomb = CHAR_D->get_char(boy,"room");
	envi = load_object( roomb );		
	roomd = "/a/"+CHAR_D->get_char(boy,"area")+"xitang";
	if(roomb == roomd )call_out("right_place", ob, envi);
	else {
//		printf( desc[random(sizeof(desc))] );
		tell_from_outside(this_object(),desc[random(sizeof(desc))]);
		call_out("destruct_itself", 4, ob, boy);
	};
	return;
}
void right_place(object ob, object env)
{
	object *obs;
	int i;
	this_object()->move( env );
//	ob->move( env );
	tell_environment( this_object(),"一队喜气洋洋的轿夫簇拥着一顶大红花轿走了过来。\n");
	tell_from_inside (this_object(),
	sprintf("花轿终于停了下来，媒婆掀开轿帘笑着说：“到了，姑娘！”\n"));
	obs=all_inventory(this_object());
	if(sizeof(obs)) {
		for(i=0;i<sizeof(obs);++i) {
			if(obs[i]->is_living()) {
				obs[i]->move(env);
		obs[i]->simple_action("$N由媒婆搀着下了花轿。\n");
			}
		}
	}
//        ob->simple_action("$N从马车上跳了下来。\n");
	tell_environment(this_object(),"车夫一扬皮鞭，道：诸位，回见。\n不一会儿，马车就消失在漫天尘土之中了。\n");
    destruct( this_object() );
	return;
}
