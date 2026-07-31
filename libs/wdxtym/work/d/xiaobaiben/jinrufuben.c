// Room: /city/wumiao.c
// YZC 1995/12/04

#include <room.h>

inherit ROOM;

int is_chat_room() { return 1; }
private void restore_status(object me);
private void init_player(object me);
void create()
{
	set("short", "副本进入");
	set("long", @LONG
这里是进入副本的地方
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_learn", "1");
	set("no_study", "1");
	set("no_learn", "1");
	set("no_dazuo", "1");
	set("no_sleep_room", "1");
	set("valid_startroom","1");
	
	set("objects", ([
   
			 __DIR__"qiandao" : 1,
	

	]));
	set("action_list", ([
		
	    "每日挑战（三次）" : "tiaozhan met",//地图传送界面提示
	
	]));

	
	setup();
}

void init()
{

	add_action("do_tiaozhan","tiaozhan");
	//add_action("get_gift","getgift");
}

int valid_leave(object me, string dir)
{
	if (dir == "northwest" && ! userp(me) && ! me->is_chatter())
		return 0;
	return ::valid_leave(me, dir);
}



int do_tiaozhan(string arg)
{
object me=this_player();
object competitionroom,npc;
int GMT = time();
	string d, dd,times,timess;
	int h, s;
	times = ctime(GMT);
	d = times[0..2];//星期
if (!arg)
return 1;
//挑战每日接口，这个是字符串写法
 
 if (arg=="met")//进入指令
  {
  timess = ctime(me->query("fuben/met"));//标记
  dd=timess[0..2];//时间设置
  me->delete_temp("met");
//if (time() > me->query("fuben/met")&&d!=dd)
me->set("fuben/met",time());//增加挑战副本时间
//else
//return notify_fail("你今天已经挑战过了。\n");//超过次数提示
if (me->query("tiaozhancishu")>2)
return notify_fail("你今天已经挑战过了。\n");//超过次数提示

if (objectp(competitionroom= new("/d/xiaobaiben/fangjian"))&&objectp(npc=new("/d/xiaobaiben/npc/npcshuxing")))//读取地图 读取npc位置
//competitionroom->set("exits/east","/d/city/wumiao");//退出地点
tell_object(me,HBRED+HIY"挑战副本，限时半小时。\n"NOR);//进入提示
me->move(competitionroom);//读取该地图生成副本
npc->move(competitionroom);//读取该npc生成副本
npc->move(competitionroom);//读取该npc生成副本
me->add("tiaozhancishu",1);
me->set_temp("zhuangtai",me->query_skill("force",1));//增加挑战副本时间
call_out("end_competition",1800,me,competitionroom);//时间1设置为半小时
}
init_player(me);
return 1;

}

void end_competition(object me,object competition)
	{
	if (!objectp(me)||!objectp(competition))
	return;
	if (environment(me)->query("fuben"))
	{
	/*
	if (room1 = ) {//所处环境检测
			if (sscanf(base_name(environment(me)), "/d/jingcheng/wanan-si/%*s"))
	*/
	me->move("d/city/kedian");//时间到后传送离开地图
	me->delete_temp("fuben/met");
	me->delete_temp("zhuangtai");
	tell_object(me,HBRED+HIY"挑战时间到，你被传回扬州客店\n"NOR);
	}
	destruct(competition);
	}


	private void init_player(object me)//死亡保护
{
        me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
        me->set_override("die", (: call_other, __FILE__, "check_out" :));

        me->set_temp("backup/killer", me->query_killer());
        me->set_temp("backup/want", me->query_want());

        me->set("backup/condition", me->query_condition());
        me->clear_condition();

}

int check_out(object me)//死亡保护
{
        object ob;
        mapping my;
        string msg;
        object room;

        room = environment(me);
        if (!room->query("fuben"))
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

private void restore_status(object me)//清除状态
{
        object *inv, obj;
        mapping cnd;
        string *ks;
        int i;
        me->delete_override("unconcious");
        me->delete_override("die");
        me->remove_all_enemy(1);
        me->remove_all_killer();
        me->clear_condition();
        me->receive_damage("qi", 0);
}
