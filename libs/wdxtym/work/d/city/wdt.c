// Room: /city/bocai.c 
#include <room.h> 
inherit CREATE_CHAT_ROOM; 
	
int is_chat_room() { return 1; } 
	
void create() 
{ 
	set("short", "武道塔"); 
	set("long", @LONG 
这是一个通往武道塔的地方 
LONG 
	); 
	set("no_fight", 1); 
	set("no_sleep_room", 1);  
	set("item_desc", ([
		"【武道塔】" : "这是一个通往武道塔的必经之路 \n"
			ZJOBACTS2"挑战:wdt \n",
	]));
		set("objects", ([
		//"/adm/npc/cishu" : 1,
	    
	]));
		set("action_list", ([
		"领取次数" : "day_sign",
	
	]));
	set("exits", ([ 
		"west" : "/d/city/kedian", 
	])); 
	
	setup(); 
} 
void init()
{
	add_action("do_sign","day_sign");
}


int do_sign(string arg)
{
	object ob,me;
	string hol,file;
	int vlv,last,times,pot;
	mapping gifts;

	me = this_player();

	last = me->query("last_day_signn");
	times = me->query("day_sign_timess");
	if(time()/86400 == last/86400)
		return notify_fail("你今天已经领取到了次数，你目前已连续领取【"+times+"】天。\n");

	me->set("last_day_signn",time());
	times += 1;
	me->set("day_sign_timess",times);
	me->set("wdtcs",1);
	tell_object("你领取了一次武道塔挑战机会，且行且珍惜\n");
	tell_object(me,"\n");
	log_ufile(me,"sign","你成功领取了一次武道塔次数。\n");
	GIFT_D->check_gift(me);
	return 1;
}