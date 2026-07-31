inherit ROOM;

#include <localtime.h>

int start_moku_fuben(object who);
void end_fuben_moku(object me, object moku);
private void init_player(object me);
int check_out(object me);
private void restore_status(object me);

void create()
{
	set("short", "魔窟一层");
	set("long", @LONG
这里常年被邪气侵染，血魔在四处游走。
LONG);
	
	set("action_list", ([
		"离开副本" : "likai",
		]));
	
	set("no_magic", 1);
	set("no_clean_up_fb", 1);
	
	setup();
}

void init()
{
	add_action("do_likai", "likai");
}

int do_likai(string arg)
{
	if(!arg)
		return notify_fail(ZJOBLONG + "你确定要离开副本？\n" ZJOBACTS2 + "确定:likai y\n");
	
	if(arg == "y")
	{
		remove_call_out("end_fuben_moku");
		restore_status(this_player());
		this_player()->move("d/city/kedian");
	}
	destruct(this_object());
	return 1;
}

int start_fuben_moku(object who)
{
	int last_time;
	object room, xuemo;
	
	last_time = who->query("fuben_moku/last_time");
	if ((localtime(last_time)[LT_MON] == localtime(time())[LT_MON]) && (localtime(last_time)[LT_MDAY] == localtime(time())[LT_MDAY]))
	{
		tell_object(who, "魔窟邪气过重，一天无法进入两次。\n");
		return 0;
	}

	xuemo = new(__DIR__"xuemo");
	xuemo->init_npc(who, xuemo);
	xuemo->move(this_object());
	who->set("fuben_moku/last_time", time());
	who->move(this_object());
	this_object()->set("player", who);
	call_out("end_fuben_moku", 3600, who, this_object());
	init_player(who);
	write("挑战开始！！！\n");
	
	return 1;
}

void end_fuben_moku(object me, object moku)
{
	if (sscanf(base_name(environment(me)), __DIR__"%*s"))
	{
		restore_status(me);
		me->move("d/city/kedian");
		tell_object(me,HBRED+HIY"挑战时间到，你被传回扬州客店\n"NOR);
	}
	destruct(moku);
}

private void init_player(object me)
{
	me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
    me->set_override("die", (: call_other, __FILE__, "check_out" :));
	me->set("backup/condition", me->query_condition());
    me->clear_condition();
}

int check_out(object me)
{
    object ob;
    mapping my;
    string msg;
    string room;

    room = base_name(environment(me)) + ".c";
    if( room !=  __FILE__)
    {
            return 0;
    }
	
    my = me->query_entire_dbase();
    my["eff_qi"] = my["max_qi"];
    my["eff_jing"] = my["max_jing"];
    my["qi"] = 1;
    my["jing"] = 1;

    tell_object(me, HIR "\n你觉得眼前一阵模糊...这下完了！\n" NOR);
    if( ob = me->query_last_damage_from() )
            msg = WHT "\n$N被" + ob->name(1) + "打成重伤，狼狈而逃！\n\n" NOR;
    else
            msg = WHT "\n$N身受重伤，狼狈而逃！\n\n" NOR;

    message_vision(msg, me);

    restore_status(me);
    me->move("d/city/kedian");
    message("vision", "一个黑影倏的窜了出来，随即就是“啪”的"
            "一声，就见" + me->name() +"摔倒了地上，一副半死不"
            "活的样子。\n", environment(me), ({ me }));
    tell_object(me, "半昏半迷中，你觉得被人拎了起来，又"
                "重重的摔倒了地上。\n");
    if( !living(me) )
            me->revive();

    return 1;
}


void restore_status(object me)
{
	mapping cnd;
	string *ks;
	int i;
	
    me->delete_override("unconcious");
    me->delete_override("die");
    me->clear_condition();
    cnd = me->query("backup/condition");
    if (! mapp(cnd)) return;
    
	ks = keys(cnd);
	for (i = 0; i < sizeof(ks); i++)
		me->apply_condition(ks[i], cnd[ks[i]]);
    me->receive_damage("qi", 0);
}