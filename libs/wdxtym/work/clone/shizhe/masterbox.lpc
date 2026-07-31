#include <ansi.h>

inherit ITEM; 

void create()
{
	set_name ("出师礼盒", ({ "master box"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","这是一个由檀木制成的出师礼盒，蕴含着一位师傅对徒弟殷切的关怀，"ZJURL("cmds:open master box")+ZJSIZE(20)+HIY"打开"NOR"它能够获得很多珍贵的礼物。\n");
	set("unit","个");
	set_weight(100);
	set("value",10000);
      set("no_give",1);
      set("no_drop",1);
      set("no_get",1);
      set("no_sell",1);
	setup();
     }
}


void init()
{
	add_action("do_read","open");
  
}

int do_read(string arg)
{
	object me=this_player();
	object ob1;
	int i,k;
	    
	if (!arg)
      		return notify_fail("你要开什么？\n");
      		
	if (arg!="master box")
      		return notify_fail("你要开什么礼盒？\n");
      		
        message_vision(HIY"$N打开了一个$n，
"HIW"$N获得了一串"HIG"葡萄"HIW"，
$N获得了一串"HIG"葡萄"HIW"，
$N获得了一串"HIG"葡萄"HIW"，
$N增加了72小时的会员时间"HIW"，
$N获得了一百两"HIY"黄金"HIW"，"NOR"\n", me, this_object()); 	

                        ob1 = new("/clone/gift/putao");
                        ob1->move(me);
                        ob1 = new("/clone/gift/putao");
                        ob1->move(me);
                        ob1 = new("/clone/gift/putao");
                        ob1->move(me);

	        ob1 = new("/clone/money/gold");
		ob1->set_amount(100);
		ob1->move(me); 

	        me->add("zjvip/times",259200);
i=random(100);

if (i<25){
ob1 = new("/clone/gift/unknowdan");
ob1->move(me);
        message_vision(HIW"$N获得了一颗"HIR"火红仙丹"HIW"。"NOR"\n", me, this_object());
//CHANNEL_D->do_channel(this_object(),"chat","恭喜"HIM+me->query("name")+HIC"获得了一颗"HIR"火红仙丹"NOR"！");
}
if (i>=25 && i<50){
ob1 = new("/clone/gift/shenliwan");
ob1->move(me);
        message_vision(HIW"$N获得了一颗"HIG"神力丸"HIW"。"NOR"\n", me, this_object());
//CHANNEL_D->do_channel(this_object(),"chat","恭喜"HIM+me->query("name")+HIC"获得了一颗"HIG"神力丸"NOR"！");
}
if (i>=50 && i<75){
ob1 = new("/clone/gift/xiandan");
ob1->move(me);
        message_vision(HIW"$N获得了一颗"HIY"醍醐仙丹"HIW"。"NOR"\n", me, this_object());
//CHANNEL_D->do_channel(this_object(),"chat","恭喜"HIM+me->query("name")+HIC"获得了一颗"HIG"神力丸"NOR"！");
}
if (i>=75 && i<98){
ob1 = new("/clone/gift/xisuidan");
ob1->move(me);
        message_vision(HIW"$N获得了一颗"YEL"洗髓丹"HIW"。"NOR"\n", me, this_object());
//CHANNEL_D->do_channel(this_object(),"chat","恭喜"HIM+me->query("name")+HIC"获得了一颗"YEL"洗髓丹"NOR"！");
}
if (i>=98){
ob1 = new("/clone/gift/jiuzhuan");
ob1->move(me);
        message_vision(HIW"$N获得了一颗"HIY"九转金丹"HIW"。"NOR"\n", me, this_object());
//CHANNEL_D->do_channel(this_object(),"chat","恭喜"HIM+me->query("name")+HIC"获得了一颗"HIY"九转金丹"NOR"！");
}




	destruct(this_object());
	return 1;
}	 

int query_autoload() { return 1; }