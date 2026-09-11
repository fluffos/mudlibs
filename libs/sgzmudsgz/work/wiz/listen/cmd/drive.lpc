#include <mudlib.h>
inherit CMD;
#define K 0.3
nosave private mixed * disp=
({
	"你坐在车里，悠闲地欣赏着四周的风景。\n",
	"你坐在%^H_CYAN%^跑车%^RESET%^中，转瞬间越过了一座高山。\n",
	"你路过一座小城市，人们热情地向你挥手致意。\n",
	"你忽然瞥见一个美女，不由一愣：在哪里见过？\n但你的%^H_CYAN%^跑车%^RESET%^立刻把她甩远了。\n",
	"穿过一片黑黑的森林，你的车头强光惊起一片片飞鸟。\n",
	"你只能听见引擎的轰鸣声在山谷中回荡。\n",
	"远处人声嘈杂，似乎有土匪出没。\n",
	"你突然退档，心爱的%^H_CYAN%^跑车%^RESET%^在轰鸣声中加快了速度。\n转瞬间，你把其他人远远地抛在了身后。\n",
	"一声炸雷，暴雨倾盆而降, 你在车中也能听见沙沙的雨声\n",
	"你远远的似乎听到了战场的撕杀声。\n",
});
private void main(string arg)
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
		write("只有坐在车中才能使用这个命令。\n");
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
		write("你的"+env->short()+"一次跑不了这么远，你的车会没油的。\n");
		return;
	}
	t=to_int(dist*speed*K)+5;
	d_name=AREA_D->get_area(arg,"name");
	this_body()->simple_action(
		"$N一踩油门，"+env->short()+"象火箭般朝远方急驰而去。。。\n");

	rid=env->get_riders();
	foreach(object o in rid)
		o->start_busy(t,"你现在必须专心开车。\n");
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
				"一阵尘土扬起，一辆%s突然出现在你的面前。\n",env->query_chinese_id()));

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
