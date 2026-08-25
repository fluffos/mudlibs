// go.c
// by fire on March 27, 1999
// this is used to spy in a room
#define K 0.3
nosave private mixed * disp=
({
	"你发觉周围都是山路，一个人影都瞧不见，背上不由冒出一丝冷汗。\n",
	"你骑在马背上，凝神倾听，远处好象传来『呜呜』的狼嗥声。\n",
	"你路过一个小村庄，见到小孩们在村外草地上嬉戏。\n",
	"你忽然瞥见一个美女，不由一愣：在哪里见过？\n但你的马立刻把她甩远了。\n",
	"穿过一片黑黑的森林，你不禁感到毛骨耸然。\n",
	"马蹄声『哒，哒，哒，哒』地在山谷中回荡。\n",
	"远处人声嘈杂，似乎有强人出没。\n",
	"跨下马越跑越快，路旁的树木飞一般向后掠去。\n",
	"一声炸雷，你的马一惊，只见暴雨倾盆而降。\n",
	"你远远的似乎听到了战场的撕杀声。\n",
});
void start(string arg)
{
	object me=this_body();
	object env,eenv;
	string h_type;
	mixed rid;
	int dist,t;
	string star,d_name;
	int speed, endurance;
	env=environment(me);
	if(!env->is_horse()){
		write("只有骑马才能长途旅行。\n");
		return;
	}
	h_type=env->query_primary_id();
	speed=OBJ_D->get_obj(h_type,"sp");
	endurance=OBJ_D->get_obj(h_type,"en");
	if(!speed) speed=10;
	if(!endurance) endurance=10;
	if(!arg)arg="";
	if(!AREA_D->area_exist(arg)){
		write("没有这个地区，请用cmd help go 查看帮助。\n"+
			"用 info a list 查阅地区列表。\n");
		return;
	}
	eenv=me->query_room();
	star=eenv->get_area();
	dist=AREA_D->get_distance(star,arg);
	if(dist==0){
		write("你现在就在这个地区。\n");
		return;
	}
	if(dist==-1)dist=10;
	if(dist>endurance) {
		write("你的"+env->short()+"一次跑不了这么远，要累死的。\n");
		return;
	}
	t=to_int(dist*speed*K)+5;
	d_name=AREA_D->get_area(arg,"name");
	this_body()->simple_action(
		"$N双腿一夹，催动跨下"+env->short()+"，向远方急驰而去。。。\n");

	rid=env->get_riders();
	foreach(object o in rid)
		o->start_busy(t,"你现在正骑着马向"+d_name+"进发。\n");
	env->move(new(VOID_ROOM));
	call_out("random_disp",random(5)+3,({env,arg}));
	call_out("get_target",t,({env,arg}));
	return;

}
void get_target(mixed par)
{
	object o,env,envv;
	string tar,room;
	mixed rid;
	remove_call_out("random_disp");
	tar=par[1];
	if(AREA_D->get_area(tar,"go"))
        
	room=AREA_D->get_area(tar,"path")+
                AREA_D->get_area(tar,"go");
	else
        room=AREA_D->get_area(tar,"path")+
                AREA_D->get_area(tar,"fly");
	env=par[0];
	if(!objectp(env)) return;
	envv=environment(env);
		if(envv->is_voidroom())
		{
			o=load_object(room);
			tell_from_outside(o,sprintf(
				"只听到『哒哒』的马蹄声由远及进，一匹%s风尘仆仆地赶了过来。\n",env->query_chinese_id()));

			env->move(o);
			tell_from_outside(env,"目的地到了。\n");
			destruct(envv);
		}
	rid=env->get_riders();
	if(sizeof(rid))
	foreach(object p in rid)
	{
		
		p->start_busy(0);
		p->responda("look");
	}

}
void random_disp(mixed par){
	call_out("random_disp",4+random(6),par);
	if(objectp(par[0]))
		tell_environment(par[0],disp[random(sizeof(disp))]);
}
