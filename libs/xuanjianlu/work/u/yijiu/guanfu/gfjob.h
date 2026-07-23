#include <ansi.h>
#include "map.lpc"
#include "/d/REGIONS.h"
#include "npc_setup.h"


void init()
{
        add_action("do_jie", ({"xian","jie"}));
     
}

int do_jie(string arg)
{
	object me, target,room;
        mapping weizhis;
        string room_msg, region;

	int exp, position;

	if(!arg) return 0;
	me = this_player();

	exp=(int)me->query("combat_exp"); 
        weizhis = where[random(sizeof(where))];

	if(arg != "wenshu" && arg != "wen") return 0;

	if(me->query_condition("guanfu_task"))
		return notify_fail("你已经揭过榜了，难道不想做了？！\n");
	if(me->query_temp("guanfu_task") || present("wenshu", me))
        return notify_fail("你身上还有文书，可以通过(kan wenshu)来查询。\n");
        
        if(me->query_condition("gf_busy"))
        return notify_fail("你发现文书已经被人揭光了，看样子要等一会了！\n");

    if(exp<50000)
		return notify_fail("你刚想伸手，忽然看到上面凶神恶煞的画像，想了想觉得自己的这点功夫，还是算了吧。\n"); 
	
	target = new(__DIR__"killer");
	target ->set_status(me); 
            
        if(exp>=380000){
	tell_room(this_object(),
		HIY + me->name()
		+ "推开围观的行人，走到近前,微微睁开眼睛，冷冷瞥了一眼告示，随手揭了下来揣进了怀中。\n"NOR, ({ me }));
	write(HIY"你推开围观的行人，走到近前,微微睁开眼睛，冷冷瞥了一眼告示，随手揭了下来揣进了怀中。\n"NOR);
	 }
        if(exp<=120000){
        tell_room(this_object(),
                 HIY + me->name()
                 + "壮了壮胆，费力拔开行人，来到近前深深吸了口气，竭力镇定一下紧张的心情，四下看了看，悄悄把文书揭了下来。\n"NOR, ({ me }));
        write(HIY"你壮了壮胆，费力拔开行人，来到近前深深吸了口气，竭力镇定一下紧张的心情，四下看了看，悄悄把文书揭了下来。\n"NOR);
         }
        if(exp>120000 && exp<380000){
        tell_room(this_object(),
                 HIY + me->name()
                 + "分开行人来到近前，目光淡淡的扫视了几眼告示，嘴角微微一翘，神态自如的把文书揭了下来。\n"NOR, ({ me }));
        write(HIY"你分开行人来到近前，目光淡淡的扫视了几眼告示，嘴角微微一翘，神态自如的把文书揭了下来。\n"NOR);
        }
        me->set_temp("mark/gkill1",1);
	me->set_temp("guanfu_target", target->query("name"));
        me->set_temp("gstart_rooms", weizhis["weizhi"]);
        
        room_msg = me->query_temp("gstart_rooms");
        if ( strsrch(room_msg, "/d/") != 0        
        ||undefinedp(region = region_names[explode(room_msg, "/")[1]]))
                region = "";
        weizhis["chinese"]=region+weizhis["chinese"];
        me->set_temp("ch_weizhi", weizhis["chinese"]);
        new(__DIR__"wenshu")->move(me);
        target->move(me->query_temp("gstart_rooms"));
        room=me->query_temp("gstart_rooms");
        target->move(room);
        message("vision", target->name(1)+"快步走了过来.\n", room, target);
        me->apply_condition("guanfu_task", me->set_temp("guanfu_time", random(70)+70));
        me->apply_condition("gf_busy", random(20)+20);
        
	return 1;
}
