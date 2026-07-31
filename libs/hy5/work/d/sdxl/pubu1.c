// xtj
// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;
int do_jump(string arg);
int do_hit(string arg);

void create()
{
    set("short", "山洪中");
    set("long", @LONG
这里是山洪只中，水流激荡，山洪从头顶轰隆轰隆的冲过，功力
稍弱的人，难以支撑过一柱香的时分。
LONG
    );

    set("outdoors", "xiangyang");
     set("no_clean_up", 0);

    setup();
 
}
void init()
{
	add_action("do_jump", "jump");
	add_action("do_hit", "hit");
	add_action("do_hit", "ji");
}
 
int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
	if (arg != "anshang" && arg != "shore")
           return notify_fail("你要往哪里跳？\n");
        	me->move(__DIR__"pubu");
	message_vision("$N忽然从山洪中跃了出来，足步虚幌的落在了岸边。\n", me);
	return 1;
}
 

int do_hit(string arg)
{
	object me = this_player();
	object weapon;
        int i;
        i = me->query_int();
       weapon = me->query_temp("weapon");
 

	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
 
	if (arg != "flood" && arg != "hongshui") {
		write("你想做什么？\n");
		return 1;
	}
	if (!weapon || weapon->query("skill_type") != "sword")
        {        
		write("你对着山洪拳打脚踢了一阵，感到劲疲力尽。\n");
		return 1;
        }
        if (me->query_skill("xuantie-jianfa",1) <= 120 &&
        weapon->query("id") != "xuantie jian"){
                write("你不用玄铁重剑怎能领悟玄铁剑法呢？\n");
        		return 1;
	}
         if (me->query_skill("xuantie-jianfa",1)>120 && 
             me->query_skill("xuantie-jianfa",1)<=160 &&
       weapon->query("id") != "changjian"){
                write("你想进一步提高玄铁剑法的修为，要换一把剑了。\n");
        		return 1;
	}   
         if (me->query_skill("xuantie-jianfa",1)>160 && 
             me->query_skill("xuantie-jianfa",1)<=300 &&
        weapon->query("id") != "mu jian"){
                write("你想进一步提高玄铁剑法的修为，要进一步去领悟了。\n");
        		return 1;
	} 
   
 
	if (me->query("neili") < 60) {
		write("你的内力不足，无法继续练下去。\n");
		return 1;
	}
	if (me->query("qi") < 60) {
		write("你已经不行了，无法继续练下去。\n");
		return 1;
	}
 	if (me->query("jing") < 60) {
		write("你精力不足，无法继续练下去。\n");
		return 1;
	}
       if (me->query_skill("xuantie-jianfa",1) <= 30){
	    me->improve_skill("xuantie-jianfa",i/3);
            me->improve_skill("force", i / 10);
	message_vision("$N用"+weapon->name()+"奋力击打着山洪，手中的"+weapon->name()+"发出了轻微的声响。\n",me);
        write("你似乎对于玄铁剑法的用力之道有所领悟。");
        me->receive_damage("qi", 20);
	me->add("neili", -20);
        me->add("jing",-50);
		return 1;
	}
	else 
       if (me->query_skill("xuantie-jianfa",1) <= 60){
	    me->improve_skill("xuantie-jianfa", i/2);
           me->improve_skill("force", i / 8);
	message_vision("$N用"+weapon->name()+"奋力击打着山洪，手中的"+weapon->name()+"发出了嗤嗤的声响。\n",me);
        write("你似乎对于玄铁剑法的运用之道有所领悟。");
        me->receive_damage("qi", 5);
	me->add("neili", -10);
        me->add("jing",-25);
		return 1;
	}
	else 
       if (me->query_skill("xuantie-jianfa",1) <= 90){
	    me->improve_skill("xuantie-jianfa", i);
            me->improve_skill("force", i / 5);
	message_vision("$N用"+weapon->name()+"奋力击打着山洪，手中的"+weapon->name() + "发出了刷刷的声响。\n",me);
        write("你似乎对于玄铁剑法的搏击之道有所领悟。");
        me->receive_damage("qi", 5);
	me->add("neili", -10);
        me->add("jing",-20);
		return 1;
	}
	else 
       if (me->query_skill("xuantie-jianfa",1) <= 120){
	    me->improve_skill("xuantie-jianfa",i*2/3);
	message_vision("$N用"+weapon->name()+"奋力击打着山洪，手中的"+weapon->name()+"发出轰隆隆的巨声。\n",me);
        write("你似乎对于玄铁剑法的内劲运用有所领悟。");
        me->receive_damage("qi", 5);
	me->add("neili", -10);
        me->add("jing",-30);
		return 1;
	}
        else 
       if (me->query_skill("xuantie-jianfa",1) <= 150){
	    me->improve_skill("xuantie-jianfa", i);
	message_vision("$N用"+weapon->name()+"奋力击打着山洪，手中的"+weapon->name()+"发出轰刷刷的声响。\n",me);
        write("你似乎对于玄铁剑法的精髓有所领悟。");
        me->receive_damage("qi", 5);
	me->add("neili", -10);
        me->add("jing",-20);
		return 1;
	}
        else 
       if (me->query_skill("xuantie-jianfa",1) <= 180){
	    me->improve_skill("xuantie-jianfa", i);
	message_vision("$N用"+weapon->name()+"奋力击打着山洪，手中的"+weapon->name()+"发出轰嗤嗤的声响。\n",me);
        write("你似乎对于玄铁剑法的御剑之道有所领悟。");
	me->add("neili", -10);
        me->add("jing",-20);
		return 1;
	}
        else 
     if (me->query_skill("xuantie-jianfa",1) <= 270){
	    me->improve_skill("xuantie-jianfa", i);
	message_vision("$N用"+weapon->name()+"奋力击打着山洪，手中的"+weapon->name()+"寂然无声。\n",me);
        write("你似乎对于玄铁剑法的御剑之气有所领悟。");
	me->add("neili", -10);
        me->add("jing",-20);
		return 1;
	}
 
       message_vision("$N用"+weapon->name()+"奋力击打着山洪，手中的"+weapon->name()+"寂然无声。\n",me);
       write("你已经无法再在这里加深你的玄铁剑法的修为了！\n");
        return 1;
}
 
