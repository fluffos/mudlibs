// duan_be_killed.h cry 9.17.98

int refuse_killing(object me)
{
    object ob=this_object(),here=environment(ob);

    command("say 是谁让你来刺杀我的？");
    ob->set("force_factor",200);
    me->apply_condition("kill_dali", 1000);
    if ( here->query_temp("be_killed") ) return 0;
    here->set_temp("be_killed",1);
    call_out("call_guard",2,me);
    return 0;
}

void call_guard(object me)
{
    object obj,env,ob=this_object();
    int i;
    string *place = ({"lianwu_chang2","zhengyuan",
	"shuixie","dongyuan"});
    string sguard,*guard = ({"fu_sigui","gu_ducheng",
	"zhu_wanli","zhu_danchen"});

    for(i=0;i<4;i++){
	if(objectp(env=find_object("/d/menpai/duanshi/"+place[i]))){
		sguard=replace_string(guard[i],"_"," ");
		write(sguard);
		if(objectp(obj=present(sguard,env))){
			tell_room(environment(obj),RED""+obj->query("name")+"大喊一声：“有刺客！快去保护王爷！”\n"NOR
+obj->query("name")+"匆匆忙忙的离开了。\n");
			destruct(obj);
		}
	}
	obj=new(__DIR__+guard[i]);
	obj->move(environment(ob));
	obj->set("env/attack",100);
	obj->set("force_factor",150);
    }
}