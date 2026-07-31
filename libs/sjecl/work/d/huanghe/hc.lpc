
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "海船");
        set("long", @LONG
这是神龙教劫来的一艘海船。
舱内陈设富丽，脚下铺着厚厚的地毡，桌上摆满茶果细点，便如王公大官之
家的花厅一般。
LONG
);
        set("no_fight",1);
        //set("sleep_room",1);
        //set("outdoors", "神龙岛");
        set_temp("curstatus","ready");
        setup();
}

void init()
{
        object me = this_player();
        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "神龙教") {
        	message_vision("突然有个人飞起一脚把$N踢了出去。\n",me);
        	me->move(__DIR__"road2");
        	tell_object(environment(me),me->name()+"被人从海船上踢了下来。\n",({me}));
        	return;
       	}  
        if(userp(me)) {
                call_out("run_mufa", 5+random(5),me);
        }
}

void run_mufa(object me)
{        
        if(!me){
        	destruct(this_object());
        	return;
        }
        message_vision(HIC"\n\n$N倚在舷窗边向海面上望去，眼见波涛汹涌，云低遮日，几只海鸥在掠波滑翔。\n"NOR,me);
        call_out("run_mufa1", 5+random(5), me);
}

void run_mufa1(object me)
{        
        if(!me){
        	destruct(this_object());
        	return;
        }
        message_vision(CYN"\n\n此刻海风正急，大船疾速行驶，片刻功夫后$N便在海面东北方看到有一处陆地。\n"NOR,me);
        call_out("run_mufa2", 5+random(5), me);
}

void run_mufa2(object me)
{        
        if(!me){
        	destruct(this_object());
        	return;
        }
        message_vision(WHT"\n\n转眼间大船已然驶近陆地，但见岸上树木苍翠，长长的海滩望不到尽头，尽是雪白细沙。\n"NOR, me);
        call_out("run_mufa3", 4+random(5), me);
}

void run_mufa3(object me)
{
        object* ob;
        if(!me){
        	destruct(this_object());
        	return;
        }
        message_vision("大船慢慢靠向陸地，$N整理了下衣冠便缓缓走了下去。\n",me);
        ob = all_inventory(this_object());
        for(int i=0; i<sizeof(ob); i++) {
                if(!living(ob[i])) continue;
                ob[i]->move("/d/sld/dukou");
                tell_room(environment(me), ob[i]->name() + "从海船上走了上来。\n",({ ob[i] }));  
        }
        destruct(this_object());
}