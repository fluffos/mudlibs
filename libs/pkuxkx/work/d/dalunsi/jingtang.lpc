// Room: jingtang.c

#include <ansi.h>

inherit ROOM;
int do_mingxiang2(string arg);
int inc(object me);

void create()
{
        set("short", "大经堂");
        set("long", @LONG
殿为十字歇山顶，形制峻瑰，殿堂规模宏大，内有大柱上千根，可同时容纳
几百名僧人同时诵经。殿前有跃马、伏虎、卧牛、怪兽、等许多石雕像。殿内大
柱和四面墙壁上刻满经文，有几个僧人正在柱下禅定(chanding)，还有些僧人对
着墙壁上的经文冥想苦思(mingxiang)。几个新来的僧人正围着石壁，仔细地抄
写着经书(write jingshu)。
LONG
        );

        set("exits", ([
                "west" : __DIR__"fanyinge",
                "south" : __DIR__"jingjinzhacang",
        ]));
        set("no_perform",1);
        set("no_exert",1);
        set("no_fight",1);

        setup();
}

void init()
{
        add_action("do_chanding", "chanding");
        add_action("do_mingxiang", "mingxiang");
        add_action("do_write","write");
}

int do_chanding(string arg)
{
        object me;
        int times;

        me = this_player();
        if(!arg)
                arg = "1";
        sscanf(arg, "%d", times);
        if(!times)
                times = 1;

        if (me->is_busy())
                return notify_fail("你正忙着呢。\n");
        if (me->is_fighting())
                return notify_fail("你无法在战斗中禅定。\n");

        if (me->query_skill("literate",1)<10)
                return notify_fail("经文深奥玄妙，你识字不多，无法领悟。\n");
        if(me->query_skill("huanxi-chan",1) < 100)
                return notify_fail("你对经文尚有不甚理解之处，禅定没什么效果。\n");

        if (me->query_skill("huanxi-chan",1)>300)
                return notify_fail("石柱上的经文你已经领悟透彻了，禅定对你没什么帮助了。\n");

        if((int)me->query("jing") < 20*times){
            message_vision("你刚要禅定，只觉得天旋地转，原来你太疲劳了......\n",me);
            me->unconcious();
            return 1;
        }      
        me->add("jing", -20*times);
   
        me->improve_skill("huanxi-chan", me->query("int")*times);
             write("你对着大柱禅定，仿佛对大柱上的经文有所领悟。\n");
        if(random(4) == 1)
                tell_room(me, HIM + me->name()+"正对着大柱专心禅定，仿佛外界的一切都无法打扰。\n"NOR, ({me}));
        me->start_busy(times / 14 + random(2));
        return 1;
}

int do_mingxiang(string arg)
{
        object me;
        int times;
        me = this_player();
        if(!arg)
                arg = "1";
        sscanf(arg, "%d", times);
        if(!times)
                times = 1;

        if (me->is_busy())
                return notify_fail("你正忙着呢。\n");
        if (me->is_fighting())
                return notify_fail("你无法在战斗中冥想。\n");

        if (me->query_skill("literate",1)<10)
                return notify_fail("经文深奥玄妙，你识字不多，无法领悟。\n");

        if (me->query_skill("huanxi-chan",1) < 300)
                return notify_fail("你屏息静气，闭目冥想。脑中却一片空白，原来你的基础太差了。\n");
			
        if (me->query_skill("huanxi-chan",1) > 500)
//                return notify_fail("石壁上的经文你已经领悟透彻了，冥想对你没什么帮助了。\n");
                return do_mingxiang2(arg);

        if((int)me->query("jing") < 50*times) {
                message_vision("你刚要冥想，只觉得天旋地转，原来你太疲劳了......\n",me);
                me->unconcious();
                return 1;
        }      
        me->add("jing", -50*times);
        me->improve_skill("huanxi-chan", me->query("int")*times);   
        write("你屏息静气，闭目冥想，似乎对墙壁上的经文有所领悟。\n");
        if(random(4) == 1)
                tell_room(me, HIM + me->name()+"正对着墙壁专心冥想，仿佛外界的一切都无法打扰。\n"NOR, ({me}));
        me->start_busy(times / 14);

        return 1;
}

int do_write(string arg)
{
        object me ;
        int lite;
        me = this_player();
        lite = me->query_skill("literate",1);
        if ( arg != "jingshu" ) 
             return notify_fail("你要写什么？\n");

        if (me->is_fighting())
                return notify_fail("你无法在战斗中写经书。\n");

        if (me->query_skill("literate",1)<10)
                return notify_fail("你大字不识几个，也想写经书？\n");

        if (me->query_skill("huanxi-chan",1)<30)
                return notify_fail("你看着满墙密密麻麻的文字，只觉头脑发涨，没有头绪。原来你的基础太差了。\n");

        if ((!present("bo juan", this_player())) || (!present("mao bi", this_player()))) 
                return notify_fail("现在你书写所用的器具不够，无法写经书。\n");
 
        if( me->query_temp("fojing"))
                return notify_fail("你已经抄好经文了。\n");

        if ((me->query_temp("write") == 20 ) && (lite<50)) {
            new(__DIR__"npc/obj/fojing3")->move(me);
            me->set_temp("fojing", 1);
            message_vision("你将写好的帛绢按次序理顺，伸了个懒腰，终于抄完了。\n",me);
            return 1;
        }
        if ((me->query_temp("write") == 35 ) && (lite < 100) && (lite >= 50)) {
            me->set_temp("fojing", 1);
            new(__DIR__"npc/obj/fojing1")->move(me);
            message_vision("你将写好的帛绢按次序理顺，伸了个懒腰，终于抄完了。\n",me);
            return 1;
        }
        if ((me->query_temp("write") == 50 ) && (lite >= 100)) {
            new(__DIR__"npc/obj/fojing2")->move(me);
            me->set_temp("fojing", 1);
            message_vision("你将写好的帛绢按次序理顺，伸了个懒腰，终于抄完了。\n",me);
            return 1;
        }
        me->add_temp("write", 1);
        message_vision("$N展开铺平帛绢，用毛笔将墙壁上的经文工工整整的录了下来。\n", me);
        return 1;
}

int do_mingxiang2(string arg)
{	
	object me=this_player();
	mapping fam;
	int skill = me->query_skill("huanxi-chan",1);
	skill = skill/1.5 - me->query("int")*10;
	if (skill <= 0 ) skill = 1;
	
	if (skill*skill/10>me->query("combat_exp")/skill)
	return notify_fail("你受到自身经验和悟性的影响，无法继续冥想了。\n");
	
	if (!(fam=me->query("family")) || fam["family_name"]!="大轮寺")
	return notify_fail("你又不是密宗弟子，在这里凑什么热闹！\n");

	if ((int)me->query("purefamily/level")<=0 || me->query("purefamily/family_name") != "大轮寺")
	return notify_fail("在得到本门密传之前，你冥想再久也不会有什么新的感悟了。\n");

	if((int)me->query("jing")<(int)me->query("max_jing"))
	return notify_fail("你心神无法专一，怎能参悟密宗至理？\n");
	
	if((int)me->query("qi")<(int)me->query("max_qi"))
	return notify_fail("你气血亏缺，无法静下心来参悟密宗至理！\n");

	if (me->is_busy())
	return notify_fail("你现在无法静下心来冥想！\n");

	if (time()-me->query_temp("mingxiang") < 10)
	return notify_fail("你刚刚冥想，需要休息一会儿！\n");

	tell_object(me,"你屏息静气，闭目冥想，似乎对墙壁上的经文有所领悟。\n" );
	me->set_temp("mingxiang",time());
	me->set_temp("duration",6);
    inc(me);
	return 1;
}

int inc(object me)
{	
	int dur, inc;
	
	if ( !objectp(me) )
		return 1;
		
	dur=me->query_temp("duration");
	inc=(int)me->query_skill("huanxi-chan",1)*1*(int)me->query("int")/30;
	
	if (dur==6){
	message("vision", 
		me->name() + "走到墙边，盘膝坐下，口中仿佛念念有词。\n",environment(me),me);
	me->add_temp("duration",-1);
	me->start_busy(35);
	call_out("inc",5,me);
	return 1;
	}

	if (dur<6 && dur>0) {
	tell_object(me,HIW"你闭目冥想密宗佛学的真谛，似乎对墙壁上的经文有所领悟。\n"NOR);
	me->improve_skill("huanxi-chan",inc);
	me->add_temp("duration",-1);
	me->start_busy(30);
	call_out("inc",5,me);
	return 1;}
	
	if (dur==0){
	message_vision("$N冥想完毕，收心定神，满心释然地站了起来。\n",me);
	me->start_busy(0);
	return 1;}
}
