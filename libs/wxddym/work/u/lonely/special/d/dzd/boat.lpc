inherit __DIR__"dzd_room";

int nokill()
{
        object ob = previous_object(1);

        if (ob == find_object("/cmds/skill/exercise")
        || ob == find_object("/cmds/skill/respirate"))
                return 0;
        return 1;
}

void create()
{
	set("short","小船");
	set("long",@LONG
一只木制的小船，船上没有艄公，孤零零得停在海面上，似乎一个波浪就
会把它打翻。
LONG
	);
	set("objects",([
		__DIR__"npc/npc_dzd" : 1,
		]));
	set("no_fight",(: nokill:) );
}

void run_sea()
{
	tell_room(this_object(),"突然一位艄公跃上小船，身手竟然十分矫健，单手便拉起锚，船如离弦之箭般开了出去。\n");
	tell_room(this_object(),"你只觉得一阵晕头转向。\n");
	set("long",@LONG
一只木制的小船，正急速向东南向冲去。
LONG
	);	
}

void move_to_iland()
{
	remove_call_out("to_iland");
	call_out("to_iland",3+random(3));
}

void goiland(object me)
{
	me->move(__DIR__"matou");
	tell_room(me,"你无奈只下只得弃船来到这个陌生的码头。\n回头一看，小船已经沉没。\n");
}
void to_iland()
{
	object* obs;
	int t;
	tell_room(this_object(),"船身已经撞上了码头，歪歪斜斜，估计瞬时就要沉了。\n");
	obs = all_inventory(this_object());
	obs = filter_array(obs,(:userp:));
	t = sizeof(obs);
	if(!t) return;
	if(t>10) t= 10;
	for(int i=0;i<t;i++) goiland(obs[i]);
	call_out("to_iland",3+random(3));
}