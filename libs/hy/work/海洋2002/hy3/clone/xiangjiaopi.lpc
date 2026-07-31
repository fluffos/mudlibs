// xiangjiaopi.c
#include <ansi.h>
inherit F_UNIQUE;
inherit ITEM;
string *pass_id = ({ });
string *room = ({
	"/d/city/guangchang",
        "/d/city/dangpu",
        "/d/city/qianzhuang",
	"/d/city/dongmen",
	"/d/city/ximen",
	"/d/city/dongmen",
	"/d/city/beimen",
	"/d/city/nanmen",
});

int move_pi();
int move2();
int des();

void create()
{
	set("channel_id","香焦皮精灵(Pi)");
	set_name(HIY"香焦皮"NOR,({
		"xiangjiao pi",
		"pi",
	}));
	set_weight(20000);
	if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long","不知道是谁吃的香焦，吃完后把皮扔到了地上．\n");
	set("unique",5);
	set("unit", "个");
	set("no_get",1);
	set("value", 1);
	set("count",0);
	}
	remove_call_out("des");
	call_out("des",2000);
	setup();
}
int des()
{
	destruct(this_object());
	return 1;
}
void init()
{
	object ob;
	ob = this_player();
	if( !ob ) return;
	if( wizardp(ob) ) return;
	if( !userp(ob) ) return;
	if( member_array( ob->query("id") , pass_id ) != -1 ) return;
	message_vision(HIY"$N被$n拌了一跤，起来后骂到：“哪个ＸＸ扔的？”\n"NOR,ob,this_object());
//	add("count",1);
//	if( query("count") > 10 ) {
//	message_vision("$N一脚把$n踢飞了！\n",ob,this_object());
	pass_id += ({ ob->query("id") });
	ob->start_busy(3);
	if( random(2) ) {		
		remove_call_out("move_pi");
		call_out("move_pi",1);
	} 
	else {
		remove_call_out("move2");
		call_out("move2",1);	
	}
	}
//}
int move_pi()
{
	object ob,room1;
	ob = new("/clone/xiangjiaopi");
	if( !ob || !objectp(ob) ) return 0;
	room1 = load_object(room[random(sizeof(room))]);
	this_object()->move(room1);
	tell_room(room1,HIY"一个香焦皮飞了过来！\n"NOR);
	remove_call_out("move2");
	call_out("move2",3);
	return 1;
}
int move2()
{
	string *dir_name,dir_temp,temp;
	object room1;
	int i,T;
	pass_id = ({ });
        room1 = load_object(room[random(sizeof(room))]);
	say("香焦皮飞走了．\n");
	if( !room1 || !objectp(room1) ) {
		CHANNEL_D->do_channel(this_object(),"sys","没有" + sprintf("%O",room) + "这个房间");
		return 1;
	}
	
	this_object()->move(room1);
	tell_room(environment(this_object()),"香焦皮飞了过来．\n");
	return 1;
}

		
