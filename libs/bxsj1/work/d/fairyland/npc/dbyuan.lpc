// dabaiyuan.c
// By jpei
// Modify By River@SJ

#include <ansi.h>
inherit NPC;
int do_cut(string arg);
void dest();
void create()
{
        set_name(HIW"大白猿"NOR, ({ "da baiyuan", "da", "baiyuan", "yuan" }) );
        set("race", "野兽");
        set("age", 54);
        set("long", "一只浑身长着白毛的老猿，肚上脓血模糊，生着一个大疮。\n仔细检查才发现，它肚子上的突起是被人用针线缝了什么进去，看来需要割开缝过之处才行。\n");

        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 100000);
    
	set_temp("apply/attack", 250);
        set_temp("apply/defense", 250);
        set_temp("apply/damage", 250);
        set_temp("apply/armor", 250);

        setup();
	if (clonep()) call_out("disappear",120);
}

void init()
{
	add_action("do_cut", ({"cut", "sever", "ge", "heal", "zhi", "yizhi", "zhiliao"}));
}

void disappear()
{
	message_vision("$N等了许久，也没有人救治它，泱泱地去了。\n", this_object());
	destruct(this_object());
}

int do_cut(string arg)
{
	object thread, yaocao,book;
	object me = this_player();
        if (me->is_busy() || me->is_fighting())
             return notify_fail("你正忙着呢！\n");
	if (id(arg)){
             if(!me->query_temp("monkey_help"))
                return notify_fail("连小猴都没救活，你还想干什么？\n");
             if( me->query_skill("medicine", 1) < 120)
                return notify_fail("你看了看白猿的伤势，感觉自己医术不够，只能叹了口气。\n");
	     if(!present("sharp rock", me))
		return notify_fail("可惜你手头没有刀剪。\n");
	     if(!present("fish bone", me) || !thread = present("xi si", me))
		return notify_fail("可惜你手头没有针线。\n");
	     if(!yaocao = present("yao cao", me))
		return notify_fail("可惜你手头没有草药。\n");
	     thread->add_amount(-1);
	     yaocao->add_amount(-1);
             me->delete_temp("monkey_help");
             remove_call_out("dest");
             call_out("dest", 1, this_object());
             if(me->query("jiuyang/mai") || !me->query("jiuyang/zhang"))
                return notify_fail(HIY"\n你用尖石慢慢割开白猿肚腹上缝补过之处，原来是上次伤口没有敷好，都已经糜烂了。\n"+
               	                      "你用鱼骨做针，树皮撮成的细丝作线，补好了伤口，最后把草药嚼烂了给它敷在伤处。\n\n"NOR);
             book = unew("/d/fairyland/obj/jiuyang");
             if(!clonep(book)){                
            	write(HIY"\n你用尖石慢慢割开白猿肚腹上缝补过之处，原来是伤口上次没有敷好，都已经糜烂了。\n"NOR);
	        write(HIY"你用鱼骨做针，树皮撮成的细丝作线，补好了伤口，最后把草药嚼烂了给它敷在伤处。\n"NOR);
	        if(!me->query("jiuyang/baiyuan"))
	        {
	        	new_ob("../obj/pantao")->move(me);
	        	return notify_fail(HIY"白猿十分感激你，给了你一个罕见的大蟠桃，然后走了。\n\n"NOR);
	        }
	        return notify_fail("");
             }
             if(clonep(book) && book->violate_unique()){
                destruct(book);                
            	write(HIY"\n你用尖石慢慢割开白猿肚腹上缝补过之处，原来是伤口上次没有敷好，都已经糜烂了。\n"NOR);
	        write(HIY"你用鱼骨做针，树皮撮成的细丝作线，补好了伤口，最后把草药嚼烂了给它敷在伤处。\n"NOR);
	        if(!me->query("jiuyang/baiyuan"))
	        {
	        	new_ob("../obj/pantao")->move(me);
	        	return notify_fail(HIY"白猿十分感激你，给了你一个罕见的大蟠桃，然后走了。\n\n"NOR);	        		        	
	        }
	        return notify_fail("");	        
             }
	     write(HIY"\n你用尖石慢慢割开白猿肚腹上缝补过之处，只见里面竟藏着一个油布包裹，打开一看，是一套经书。\n"NOR);
	     write(HIY"你来不及仔细检查，忙揣入怀中。然后用鱼骨做针，树皮撮成的细丝作线，勉强补好了白猿的伤口。\n"NOR);
	     if(!me->query("jiuyang/baiyuan"))
	     {	     
	     	new_ob("../obj/pantao")->move(me);
	     	write(HIY"最后你把草药嚼烂了给它敷在伤处，白猿十分感激你，给了你一个罕见的大蟠桃，然后走了。\n\n"NOR);
	     }
             me->set("jiuyang/baiyuan",1);
             book->set_temp("jiuyang",me->query("id"));
	     book->move(me);
	     
             return 1;
	}
	return 0;
}

void dest()
{
        destruct(this_object());
}
