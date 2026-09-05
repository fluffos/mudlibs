inherit ROOM;

#include <ansi.h>
void create()
{
	set("short","私塾");
	set("long",@LONG
这里是我踏月色而来特别为北侠失学儿童捐资盖起的私塾，大家可以在这里
自由自在的练功读书。累了就来这里休息一下吧。
LONG);

        set("least_msg",1);
        
	    set("objects", ([
		
        "/d/luoyang/npc/halaoban":1,
		]));
	set("exits", ([
		"north" : __DIR__"hutong6",
	]));
	set("no_sleep_room",1);
    set("no_task",1);
	set("cant_drop",1);
	set("no_fight", 1);
	set("no_sick_spread",1);
	//不涨岁数
	setup();
	
}
void init()
{
	add_action("do_exert", "yun");
	add_action("do_none", "hitall");
	add_action("do_none", "killall");
	add_action("do_none", "kill");
	add_action("do_exert", "exert");
	add_action("do_none", "attack");
	add_action("do_none", "qiecuo");
	add_action("do_none", "xiulian");
	add_action("do_none", "perform");	
//    add_action("do_xiuxi", "xiuxi");
}

int do_none()
{
    return 1;
}

int do_exert(string arg)
{
	string verb,target;
	if(arg!="roar" && arg!="bhcs") return 0;
  if(sscanf(arg, "%s %s", verb, target)==2)
  	if(verb!="roar" && verb!="bhcs" )
  		return 0;
	return 1;
}

/*int do_xiuxi(string arg)
{
        object me;
        string family;
        string *familys=({"丐帮","全真派","天龙寺","古墓派","日月神教","桃花岛","峨嵋派","明教","华山派","少林派","武当派","星宿派"});
        me=this_player();
        family=me->query("family/family_name");
        if(me->is_busy())  return notify_fail("瞧你忙的？\n");
        if (member_array(family,familys)!=-1)
        {
            tell_object(me,"你想起之前师门给你的教诲，决定早早回去给师门做事。\n");
            return 1;
        }
        if (me->query("age")>17)
        {
             return notify_fail("这么大了，还来冒充失学儿童？\n");
          }
        else if(me->query("max_neili")>1000||me->query("max_jingli")>1000||me->query("combat_exp")>110000){
             return notify_fail("你已经很厉害了，可以去闯荡江湖了。\n");
          }
        else{
                me->set("neili",random(me->query("max_neili")/2+me->query("max_neili")/4));
                me->set("idleapply",1);// add by Zine 12/2/2011 给不用发呆室的玩家增加了福利quest,做个判断
                tell_object(me,HIY"你休息了一会儿，发现自己居然精神百倍！\n"NOR);
                me->start_busy(10);
                if (me->query("max_neili")>950||me->query("max_jingli")>950||me->query("combat_exp")>109000)
                	tell_object(me,HIR"18岁以前，最大内力1000以上或最大精力1000以上或经验110000以上就该把机会让给其他新人啦，\n
                		你的状态已经接近此上限，请多加注意！\n"NOR);
                
                return 1;
            }
}*/
