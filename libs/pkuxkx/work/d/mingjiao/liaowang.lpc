// liaowang.c 
// by yuer
// modified by Zine newbie job MJ
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "了望塔");
	set("long", @LONG
      从这里你可以看见山下的景象，是明教用来观测山下情形的地方。
LONG
	);
        set("outdoors", "mingjiao");

	set("exits", ([
	
	       "east" : __DIR__"banshanmen",
	]));
	setup();
	
}

void init() 
{
    add_action("do_liaowang","liaowang");
}

int liaowang(object me)
{
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    string * desc1=({"山下静悄悄的，一个人影都没有。","山下过往的都是明教教众，没有问题。","今天天气极好，你伸了伸懒腰。","一眼望去，一切都是那么宁静。"});
    string desc;
    if (!me)
    {
        return 1;
    }
    if (!living(me))
    {
        return 1;
    }
    if (!environment(me))
    {
        return 1;
    }
    if (base_name(this_object())!=base_name(environment(me)))
    {
        tell_object(me,"你站岗时候擅离职守，回杨左使处领罚吧。\n");
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/newnewbiecount")>25+random(15))
    {
        me->delete_temp("mingjiao/tasks/newnewbiecount");
        me->set_temp("mingjiao/tasks/newnewbiefinish",1);
        tell_object(me,HIG"你站岗完毕，回杨左使处复命吧。\n"NOR);
        return 1;
    }
    desc=desc1[random(sizeof(desc1))];
    me->add_busy(1);
    me->add_temp("mingjiao/tasks/newnewbiecount",1);
    message_vision("$N开始对着山下张望。\n",me);
    tell_object(me,color1+desc+"\n"+NOR);
    call_out("liaowang",1+random(2),me);
    return 1;
}

int do_liaowang()
{
    object me=this_player();
    if (!me->query_temp("mingjiao/tasks/newnewbie"))
    {
        tell_object(me,"没有杨左使的手令，不得使用了望塔。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/newnewbiefinish"))
    {
        tell_object(me,HIG"你站岗完毕，回杨左使处复命吧。\n"NOR);
        return 1;
    }
    if (me->query_temp("mingjiao/tasks/newnewbiecount"))
    {
        tell_object(me,"了望开始了，事关重大，你不要分心。\n");
        return 1;
    }
    me->add_busy(1);
    message_vision("$N开始对着山下张望。\n",me);
    call_out("liaowang",1+random(2),me);
    return 1;
}

