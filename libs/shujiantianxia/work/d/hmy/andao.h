string *way = ({
	"up",
	"down",
	"west",
	"east",
	"south",
	"north",
	"southeast",
	"southwest",
	"northeast",
	"northwest",
	"southup",
	"southdown",
	"northup",
	"northdown",
	"eastup",
	"eastdown",
	"westup",
	"westdown",
});
	
void init()
{
	add_action("do_action", "");
}

int do_action(string arg)
{
	object me = this_player();
	string action = query_verb();

	if(!me->query_temp("hostage/job_2")
	 || !me->query_temp("hostage/ready_3")) {
		switch (action) {
			case "kill mojiao shashou":
			case "yun play":
			case "exert play":
			case "yun roar":
			case "exert roar":
			case "hit mojiao shashou":
				write("魔教杀手「嘿嘿」笑了几声：在我面前玩这些花样，不顶用的。\n");
				return 1;
		}
	}
	return 0;
}
	
int valid_leave(object me, string dir)
{
	object obj;
	int i;
	
	if(me->query_temp("hostage/job_2") == 1 && !me->query_temp("hostage/ready_3")) {
		if (random(5)>2 || me->query_temp("hostage/job2_killed") < 5) {
			obj = new(__DIR__"npc/killer3");
			obj->set_temp("target",me->query("id"));
			obj->move(environment(me));
		}
		for(i=0;i<sizeof(way);i++) {
			if (dir == way[i] && objectp(present("mojiao shashou", environment(me)))) {
				tell_room(environment(me),CYN"狱卒大声对着" + me->name() + "喝道：" + RANK_D->query_rude(me) + "，你来到这里还想撒野！\n"NOR);
				return 0;
				break;
			}
		}
	}
	return ::valid_leave(me, dir);
}
