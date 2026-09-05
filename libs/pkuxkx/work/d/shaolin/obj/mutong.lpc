// mutong.c
//木桶，挑水任务用
//seagate@pkuxkx 2010/10/11

inherit ITEM;
void carrying(object me,object room);

void create()
{
	set_name("木桶", ({ "mu tong", "tong" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("long", "这是挑水用的木桶，你可以用手提(carry)着它。\n");
		set("value", 1000);
		set("no_get", 1);
		set("material", "wood");
	}
	
	set("water",0);
	setup();
}

void init()
{
	add_action("do_carry", "carry");
}

//表示你拎着木桶，仅仅是一个标志，并且启用call_out每秒检核行步速度
int do_carry() 
{
	object me,ob;
	
	me=this_player();
	ob=present("mu tong", me);
	if(!living(environment())) {
		if(ob) {
			if(ob->query("carried")) {
				tell_object(me, "你已经拎着木桶了！\n");
				return 1;
			}
			else {
				ob->set("carried",1);
				tell_object(me, "你拎起一对木桶。\n");
				ob->carrying(me,environment(me));
			}
		}
		else {
			move(me);
			set("carried",1);
			tell_room(environment(), RANK_D->query_respect(me)+"从地上拎起一对木桶。\n");
			carrying(me,environment(me));
	  }
		return 1;
	}
	else {
		if(ob->query("carried"))
			tell_object(me, "你已经拎着木桶了！\n");
		else {
			set("carried",1);
			tell_object(me, "你拎起一对木桶。\n");
			carrying(me,environment(me));
		}
		return 1;
	}
}

//行步检核，没有水的时候不检核，带水的时候走快了水就撒没了
//走快的标准是1秒钟你最多走一步，超过一步就有惩罚
//基本轻功没过100级的时候有最高8%的几率会把水撒了1/10。具体
//几率和先天身法，基本轻功都有关系。
void carrying(object me,object room)
{
	object *rooms,roomBuf;
	string *exits,exit;
	
	if(!query("water")) {
		remove_call_out("carrying");
		if ( objectp(me) )
		  call_out("carrying",1,me,environment(me));
	}
	else {
	  if ( !objectp(me) )
	    return;
	  
		if(!room->query("exits")&&environment(me)!=room) {
			set("water",0);
			remove_call_out("carrying");
			call_out("carrying",1,me,environment(me));
			tell_object(me, "你一个手不稳，把水全撒了！\n");
			return;
		}
		
		exits=values(room->query("exits"));
		rooms=({room});
		foreach(exit in exits) {
			if(!objectp(roomBuf=find_object(exit)))
				roomBuf=load_object(exit);
			rooms=rooms+({roomBuf});
		}
		if(member_array(environment(me),rooms)>=0&&environment(me)!=room) {
//基本轻功小于100的时候会极低概率撒掉部分水
//几率是（100-先天身法*2-基本轻功/2)/1000
			if(me->query_skill("dodge",1)<100&&
			 random(2000)<(100-me->query("dex")*2-me->query_skill("dodge",1)/2)) {
				add("water",-10);
				if(query("water")<=0) {
					set("water",0);
					tell_object(me, "你没有保持住身体平衡，一个倾斜把木桶里面剩下那点水全撒了！\n");
				}
				else
					tell_object(me, "你没有保持住身体平衡，一个倾斜把木桶里面的水撒了！\n");
			}
			remove_call_out("carrying");
			call_out("carrying",1,me,environment(me));
		}
		else if(environment(me)==room) {
			remove_call_out("carrying");
			call_out("carrying",1,me,environment(me));
		}
		else {
			set("water",0);
			remove_call_out("carrying");
			call_out("carrying",1,me,environment(me));
			tell_object(me, "你走的太快了，把水全撒了！\n");
		}
	}
}