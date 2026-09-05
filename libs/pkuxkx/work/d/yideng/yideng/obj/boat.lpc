// 小船
//by icer
inherit ITEM;

void create()
{
        set_name("小船", ({"boat"}));
        set_weight(10000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long",
		"这是一只铁制的小船,船身极窄,最多只能作下两个人。想划船就得用力扳(ban)桨。\n"
		);
        }
}

void init()
{
	add_action("do_enter","enter");
	add_action("do_ban","ban");
}
int do_enter()
{
	if ((int)this_player()->query_temp("marks/渔4")) {
		write("你坐进了小船中。\n");
		this_player()->set_temp("marks/渔5",1);
		return 1;
	}
	return notify_fail("你要进哪儿？\n");
}
int do_ban()
{
  object *inv;
  int lp,user;
        
  inv=all_inventory(this_player());
  user=0;
  for(lp=0;lp<sizeof(inv);lp++)
  	if(userp(inv[lp]))
   		user=1;
        		
  if(user)
  	return notify_fail("你的负重太高了，进不了小船。\n");
  	
	if ((int)this_player()->query_temp("marks/渔5")) {
		write("你开始用力划起船来。不一会儿，就到了半山腰。你下了船，开始步行。\n");
		this_player()->add("neili",-100);
                this_player()->move("/d/yideng/yideng/banshan1");
		destruct(this_object());}
        return 1;
}
	
