// Update by waiwai@2003/04/25

void init()
{
	remove_call_out("do_check");

	call_out("do_check", 60+random(120));
	add_action("do_check", "check");
}

int do_check()
{   
	object env, geng;
	env=environment(this_object());

	geng = new("/d/city/npc/obj/flower/huageng");

	if(userp(env)) {
		if(query("flower_aroma")>3) {
			message_vision("$N身上的$n已枯萎了。\n", this_player(),this_object());
			geng->set_name(this_object()->name()+NOR WHT"的花梗"NOR,({ "hua geng","geng" }));
			geng->move(this_player());
			destruct(this_object());
			return 1;
			}
	
		if((string)file_name(environment(env))!="/d/city/huadian") {
			message_vision("$N身上的$n传出一阵阵迷人的幽香。\n", env,this_object());		
			add("flower_aroma",1);
		}
		remove_call_out("do_check");
		call_out("do_check", 60+random(120));
		return 1;
		} else {
			message_vision("一阵风吹来，将$N吹走了。\n", this_object());	
			destruct(this_object());
			return 1;
		}
}

