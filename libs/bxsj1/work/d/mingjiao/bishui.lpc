// bishui.c 碧水寒潭
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIC"碧水寒潭"NOR);
       set("long", @LONG
你一走到这里，忽然间一股寒气直扑而来，你不由得打了一个寒颤。你仔
细的一看，原来你已置身于一个水面结满厚冰的寒潭上面，望下去是碧沉沉的，
深不见底。厚冰彼为结实，但见滑如镜，滑不溜脚，这时你不由得产生一股想
上去走走(walk)的念头。远处有一处很薄的地方，好象可以跳(jump)下去。
LONG);    
	set("exits", ([
		"west" : __DIR__"shanlu2",				
	]));             
        set("outdoors", "明教光明顶");
        set("mj_xl", "zhang-zhong");
	setup();
}

void init()
{
        object me = this_player();
        string arg = this_object()->query("mj_xl");
        if(me->query_temp("mj/xunluo")
           && !me->query_temp(arg)
           && me->query_temp("eatroom")
           && me->query_temp("bingqi")
           && me->query_temp("yaofang")
           && me->query_temp("mj/xunluo") == 1){
              me->add_temp(arg,1);
              me->delete_temp("eatroom");
              me->delete_temp("bingqi");
              me->delete_temp("yaofang");
        }
	if ( userp(me))
		me->start_busy(1);
        add_action("do_walk", "walk");
	add_action("do_jump", "jump");
	add_action("do_jump","tiao");
}

int do_jump(string arg)
{
	object me;
	me=this_player();
	if ( !arg || arg!="down") return 0;
	if ( !living(me)) return 0;
	if(me->is_busy() || me->is_fighting())
	        return notify_fail("你正忙着呢。\n");
	if ((int)me->query("jing") < 30)
		return notify_fail("你太累了，无法做这么高难度的动作！\n");
        message("vision", me->name()+"击破一处薄冰，一个纵身，向潭底跳了下去。\n",environment(me), ({me}) );
	if ((int)me->query_skill("force",1) < 30){
		me->move(__DIR__"tandi");
		write(HIR"你发觉你的内力不足以抵抗寒潭的剌骨寒冷。\n"NOR);
	        me->unconcious();
                me->move(__DIR__"bishui");
                message("vision", me->name()+"从潭底慢慢浮了上来。\n",environment(me), ({me}) );
 	        return 1;
	}
	if ((int)me->query_skill("force",1) >= 101){
		write("\n你就是再如何跳，对你也没有什么好处了。\n\n");
		me->move(__DIR__"tandi");
                message("vision", me->name()+"从潭面跳了下来。\n", environment(me), ({me}) );
	        return 1;
	}
        if ((int)me->query_skill("force", 1) >= 30 
         && (int)me->query_skill("force", 1) <= 101
         && arg=="down" ){
                me->receive_damage("jing", 20+random(10));
                me->improve_skill("force", me->query("int"));
		write("\n你击破一处薄冰，做了一个漂亮的动作，跳了下去...\n\n");
		me->move(__DIR__"tandi");
                message("vision", me->name() + "从潭面跳了下来。\n", environment(me), ({me}) );
                tell_object(me,"你发现深潭奇冷无比，急忙运起内功与之相扩。\n");
	return 1;
	}
}

int do_walk(string arg)
{
        object me;
        me = this_player();
	if (!living(me)) return 0;
	if(me->is_busy() || me->is_fighting())
	        return notify_fail("你正忙着呢。\n");
	if ((int)me->query("jing") < 30)
		return notify_fail("你太累了，无法继续在冰面上行走！\n");
	if ((int)me->query_skill("dodge", 1) > 100)
		return notify_fail("你已能在光滑的冰面上行走自由，再走下去好象对你的轻功没多大的帮助。\n");
	if ((int)me->query_skill("dodge", 1) < 30 )
		return notify_fail("因为冰上太滑，使你无法在上面行走，差点摔倒！\n");
	me->receive_damage("jing", 20+random(10));
	me->improve_skill("dodge", me->query("int"));
	message_vision("$N在光滑如镜的冰面上不断的来回走动。\n", me);
	return 1;	
}
