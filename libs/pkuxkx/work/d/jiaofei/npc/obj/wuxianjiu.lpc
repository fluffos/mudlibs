//by skywolf 2009-2-5 for wuzhishan-jiaofei
//thanks bjddy,诸葛不亮,新血等人
//五仙酒作用:恢复内力至最大值,两分钟内多喝会晕,一壶能喝10口.
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void init()
{
        add_action("do_drink", "drink");
}

void create()
{
        set_name("五仙大补酒", ({"wuxian jiu", "jiu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这五仙大补药酒，是五毒教祖传秘方所酿，
所酿的五种小毒虫珍奇无匹，据说每一条小虫都要十多年
才培养得成，酒中另外又有数十种奇花异草，中间颇具生
克之理。服了这药酒之人，百病不生，诸毒不侵，陡增十
余年功力，原是当世最神奇的补药。\n");
                set("unit", "壶");
                set("value", 3000000);
                set("max_liquid", 10);
                set("no_store",1);
                set("no_pawn",1);
                set("no_sell",1);
                set("mingjiao",1);
				//set("no_give",1);
                        }
}

int do_drink(string arg)
{
        object me = this_player();
        
	if (!id(arg))  return notify_fail("你要喝什么？\n");
        
	if(query("max_liquid")<1){
		tell_object(me,HIR"你晃了晃酒壶,发现酒已经喝光了."NOR+"\n");
		return 1;
	}
	if(arg=="jiu") 
	{
		if (time()-me->query_temp("last_eat_jiu")<120)
             {
             tell_object(me,HIR"你喝了一口五仙酒，突然觉得内息冲顶，显是体内酒效过度.
你觉得身体如被五毒所噬,痛苦难当."NOR+"\n");
		        add("max_liquid",-1);
               me->unconcious();
			   return 1;
               }
        me->set_temp("last_eat_jiu",time()); 
		me->set("neili",me->query("max_neili"));
		message_vision(HIC"$N小心喝了一口五仙酒，霎时觉得丹田内有股炽热之气蹿动，内力片刻便涌现了出来！"NOR+"\n", me, this_object());
        add("max_liquid",-1);
	    me->start_busy(1);}
	return 1;
}