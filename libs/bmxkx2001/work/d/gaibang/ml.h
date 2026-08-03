//Cracked by Roath
// Room: /gaibang/ml.h
// xbc 06/21/97

void init()
{
	add_action("do_pick", "pick");
	add_action("do_pick", "zhai");
}

int do_pick(string arg)
{
	object me = this_player();
	object ob = new(__DIR__"obj/zhusun");

	if ( !arg || arg == "") return 0;

	if ( arg == "zhu sun" || arg == "bamboo shoot" || "竹笋"){
               	message_vision("$N折下一把竹笋，揣在怀里。\n", me);
		ob->move(me);
	        return 1;
	}
	return 0;
}

