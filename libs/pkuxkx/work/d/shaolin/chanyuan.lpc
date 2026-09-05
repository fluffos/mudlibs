//  禅院
// by chui

#include <ansi.h>
inherit ROOM;

int inc(object me);
void init()
{
add_action("do_canchan","canchan");
}

void create()
{
        set("short", "禅院");
        set("long", @LONG
    这是一座古朴的殿堂。中堂上挂着南无阿弥陀佛的画像，
墙上画满了佛家普渡众生，六道轮回各类佛家典故的图谱，不
少白须白眉的老僧们正端坐在图谱画轴之前，似乎在苦苦思索。
南北山墙是高及屋顶的大书架，走近细看，都是佛家经书，
屋正中摆着几张矮几诃和几个团蒲，一片肃穆寂静，几位老僧
正在入定中。你可以在这里静坐参禅(canchan)。
LONG
        );

        set("exits", ([
                "south" : __DIR__"dmyuan2",
        ]));
        set("least_msg",1);
		set("no_sick_spread",1);
        set("no_perform",1);
        set("no_exert",1);
        set("no_fight",1);
        setup();
}
int do_canchan()
{       object me=this_player();
        mapping fam;
        int skill = me->query_skill("buddhism",1);
        skill = skill/1.5 - me->query("int")*10;
        if (skill <= 0) skill = 1;
	
	      if (skill*skill/10>me->query("combat_exp")/skill)
	      return notify_fail("你受到自身经验和悟性的影响，无法继续参禅了。\n");

        if (!(fam=me->query("family")) || fam["family_name"]!="少林派")
        return notify_fail("你又不是出家和尚，在这里凑什么热闹！\n");

        if((int)me->query_skill("buddhism",1)<150)
        return notify_fail("你在禅宗修为上尚且达不到可以无师自通的地步！\n");

        if((int)me->query("jing")<(int)me->query("max_jing"))
        return notify_fail("你心神无法专一，怎能参禅？\n");
        
        if((int)me->query("qi")<(int)me->query("max_qi"))
        return notify_fail("你气血亏缺，无法静下心来参悟参禅！\n");

        if (me->is_busy())
        return notify_fail("你现在无法静下心来参禅！\n");

        me->set_temp("duration",6);
//      remove_call_out("inc");
        inc(me);
//不能用call_out，改这里时记得改武当 iszt@pkuxkx, 2006-11-26
        return 1;
}

int inc(object me)
{       
//	if (!me||!living(me))
//	return 1;
        int dur=me->query_temp("duration");
        int inc=(int)me->query_skill("buddhism",1)*1*(int)me->query("int")/30;
        
        if (dur==6){
        tell_object(me,"你面对墙壁慢慢盘膝坐下，身躯挺直；头，手，足五心朝天；心中默念“南无阿弥陀佛”\n"
              WHT"渐渐的你心如止水，开始神游太虚。\n"NOR);
        message("vision", 
                me->name() + "坐在蒲团上，盘膝坐下，口中仿佛念念有词。\n",environment(me),me);
        me->add_temp("duration",-1);
        me->start_busy(30);
        call_out("inc",5,me);
        return 1;
        }

        if (dur<6 && dur>0) {
        tell_object(me,HIW"你闭目冥想禅宗中的真谛，心中的疑惑逐渐释然，对禅宗心法的理解也更进了一步。\n"NOR);
        me->improve_skill("buddhism",inc);
        me->add_temp("duration",-1);
        me->start_busy(30);
        call_out("inc",5,me);
        return 1;}
                
        if (dur==0){
        message_vision("$N修行完毕，收心定神，满心释然的站了起来。\n",me);
        me->start_busy(0);
        return 1;}
}
