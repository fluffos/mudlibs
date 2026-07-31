inherit ROOM;
void create()
{
	set("short", "风雨楼顶");
	set("long", @LONG
这里是塔的最高层，中央放着根神杖，闪闪地放出光芒。如果你是乘车来的话，
你可以向盟主要(yaoche)。
    这里没有出口，你只能等待到一刻钟后被自动送回广场。
LONG );
       set("no_sleep_room",1);
       set("no_clean_up", 0);
			set("objects", ([
			"/d/biwu/champion": 1,
		]));


setup();
}

void init()
{
add_action("do_dazuo","dazuo");
add_action("do_dazuo","exercise");
add_action("do_dazuo","steal");
add_action("do_dazuo","beg");
add_action("do_dazuo","ansuan");
add_action("do_dazuo","hit");
add_action("do_dazuo","get");
add_action("do_yao","yaoche");
}

int do_dazuo()
{

   object me;
   me = this_player();
   tell_object(me,"这里不能用这个指令。\n");
return 1;
}
int do_yao()
{
	object *inv,kicker;
	int sizeinv,n,tt;

object me;

me = this_player();
if(!me->query("marks/mengzhu"))
		return notify_fail("你没有乘马车的权限。\n");
//   if (!me->query_temp("che"))
//		return notify_fail("你刚才没有乘车来这里。\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你想进去拐卖人口？\n");
       		
		}
	me->set_temp("che",0);
 message_vision("$N走出风雨楼，乘上了刚才来时的那辆马车匆匆忙忙地离去了。\n",me);
me->move("/d/city/majiu");
message_vision("$N又回到了原先来时的那间马厩。\n",me);

return 1;
}/*
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="down")
{remove_call_out("awayaway");
this_player()->set_temp("for_okok",0);
}return 1;
}*/
