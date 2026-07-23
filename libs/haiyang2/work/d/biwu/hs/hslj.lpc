#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"华山之颠"NOR);
        set("long", @LONG
   武林中的一块圣地。当年中原五绝在此处比武定位以决定天下第一,
现在每隔一段时间，在此就会举行一次华山论剑，以考验江湖新秀的能力
。在傍边有一块石头，上面刻有一些人的名字：
[33m
                       东邪 西毒，
                       南帝 北丐。
                        中神通              
[36m
              你可以挑战中原五绝进行华山论剑。(lunjian)
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : "/d/huashan/lianhua",
]));
       
	set("citybiwu",1);
	set("no_death_penalty",1);
	set("no_get",1);
	set("no_dazuo",1);
	       
	setup();
}
void init()
{
	add_action("do_levelup","lunjian");
        add_action("do_quit","exert");
        add_action("do_quit","exercise");
        add_action("do_quit","get");
        add_action("do_quit2","quit");
        add_action("do_quit2","exit");
        add_action("do_quit2","exercise");
        add_action("do_quit2","halt");
        add_action("do_quit2","dazuo");
        add_action("do_quit2","learn"); 
        add_action("do_quit2","xue");
        add_action("do_quit2","respirate");
        add_action("do_quit2","tuna"); 
        add_action("do_quit2","persuade");
        add_action("do_quit2","practice");
        add_action("do_quit2","lian"); 
        add_action("do_quit2","study");
        add_action("do_quit2","du");
        add_action("do_quit2","teach");
        add_action("do_quit2","jiao");
}
int  do_levelup(string arg)
{
	object me, ob;
	object fight;
	int cost = 1;
	int i,j,base,current;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
        if (me->is_fighting()) 
        return notify_fail("你正在华山论剑呢!\n");
	if( me->is_busy() )
		return notify_fail("你正忙着呢! \n");
        if (!wizardp(me) && !me->query("guard/flag"))
	return notify_fail("你的江湖经验还不够，没有资格华山论剑！\n");
        if (!wizardp(me) && me->query("combat_exp")< 5000000)
	return notify_fail("你的能力还不够，没有资格华山论剑！\n");
	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
	return notify_fail("你的杂学太多，华山论剑只允许能代表一方门派的新秀参加！\n");
	if(!wizardp(me) && me->query("guard/ok"))
	return notify_fail("你已经通过了华山论剑了！\n");

	if(environment(me)->query("alrd")
	 && !me->query_temp("hslj/1"))
	return notify_fail("现在还不到华山论剑的时间，或已经开始了！\n");
environment(me)->set("alrd",1);
if (!me->query_temp("hsljn"))
{
environment(me)->set("alrd",1);
message("channel:chat", HIG"【华山论剑】听说"+me->name() + "在华山之颠挑战中原五绝!"NOR"\n", users());
me->set_temp("hsljn",1);
}
me->start_busy(2);

if (!me->query_temp("hslj"))
{
fight=new(__DIR__"huang");
fight->move(environment(me));
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
fight->kill_ob(me);
message("channel:chat", CYN"【华山论剑】听说"+me->name() + "在华山之颠挑战东邪黄药师!"NOR"\n", users());
}
else
if (me->query_temp("hslj/1")
&& !me->query_temp("hslj/2")
&& !me->query_temp("hslj/3")
&& !me->query_temp("hslj/4")
&& !me->query_temp("hslj/5"))
{
fight=new(__DIR__"hong");
fight->move(environment(me));
fight->kill_ob(me);
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
message("channel:chat", YEL"【华山论剑】听说"+me->name() + "在华山之颠挑战北丐洪七公!"NOR"\n", users());
}
else
if (me->query_temp("hslj/2")
&& !me->query_temp("hslj/3")
&& !me->query_temp("hslj/4")
&& !me->query_temp("hslj/5"))
{

fight=new(__DIR__"yideng");
fight->move(environment(me));
fight->kill_ob(me);
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
message("channel:chat", HIY"【华山论剑】听说"+me->name() + "在华山之颠挑战南帝一灯!"NOR"\n", users());
}
else
if (me->query_temp("hslj/3")
&& !me->query_temp("hslj/4")
&& !me->query_temp("hslj/5")
)
{
fight=new(__DIR__"ouyangfeng");
fight->move(environment(me));
fight->kill_ob(me);
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
message("channel:chat", HIR"【华山论剑】听说"+me->name() + "在华山之颠挑战西毒欧阳锋!"NOR"\n", users());
}
else
if (!me->query_temp("hslj/5"))
{
fight=new(__DIR__"wang");
fight->move(environment(me));
fight->kill_ob(me);
if (fight->query("combat_exp") < me->query("combat_exp"))
fight->set("combat_exp",me->query("combat_exp"));
message("channel:chat", HIB"【华山论剑】听说"+me->name() + "在华山之颠挑战中神通王重阳!"NOR"\n", users());
}
else 
{
me->set("guard/ok",1);
me->save();
message("channel:chat", HIW"【华山论剑】听说"+me->name() + "在华山之颠通过了中原五绝的考验!"NOR"\n", users());
}
return 1;
}

int do_quit(string arg)
{
	if(arg=="roar") {
        write(this_player()->query("name")+"，安心的华山论剑吧！\n");
        return 1;
	}

	if(arg=="all") {
        write(this_player()->query("name")+"，安心的华山论剑吧！\n");
        return 1;
	}
	if(arg=="corpse") {
        write(this_player()->query("name")+"，安心的华山论剑吧！\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"，安心的华山论剑吧！\n");
        return 1;
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
       if (  me->is_fighting() )
        return notify_fail("你不正在比武吗！\n");
	
        me->delete_temp("hsljn");
	return ::valid_leave(me, dir);

}

