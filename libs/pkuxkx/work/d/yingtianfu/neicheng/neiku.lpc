//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "内库");
        set("long", 
"这里是内廷的银库，各品级的太监可以来这里领取(ling)自己的俸薪。\n"

        );
        
        set("exits", ([
                
              
                
                
                "out" : __DIR__"sili",
               
                
                
                
        ]));
        setup();
   
}

void init()
{
    add_action("do_ling","ling");
}

int do_ling()
{
    object me=this_player();
    object baoshi;
    int salary,i;
    string gem;
    int *salary_list;
    salary_list = ({
              24000,
             68000,
			 152000,
			 262000,
			});
    if (!me->query("ming/tj/pin"))
    {
        return notify_fail("你根本不是大明内廷官员，难道想来偷鸡？\n");
    }
    if (me->query("ming/tj/pin")==8)
    {
        tell_object(me,"杂役太监的俸禄只有转正后才能领取。\n");
        return 1;
    }
    if (me->query("mud_age")-me->query("ming/salary")<86399)
    {
        tell_object(me,"还没有到领俸薪的时候。\n");
        return 1;
    }
    if (me->query("ming/tj/pin")<=3)
    {
        return notify_fail("明朝的太监有三品以上的吗？你忽悠谁啊！\n");
    }
    else
    {
        salary=salary_list[7 - me->query("ming/tj/pin")];
        me->set("ming/salary",me->query("mud_age"));
        MONEY_D->pay_player(me, salary);
        tell_object(me,"作为大明内廷"+chinese_number(me->query("ming/tj/pin"))+"品太监，你今年的俸禄一共是" + MONEY_D->money_str(salary) + "，几个小太监忙不迭把银两递给你。\n");
        if (!me->query("ming/salary"))
        {
            tell_object(me,"并补发你做杂役太监时的俸禄，以及净身的营养费六百两白银。\n");
            MONEY_D->pay_player(me, 60000);
        }
        if (me->query("ming/tj/pin")==4)
        {
            baoshi= new("/obj/gem/gem");
            i = random(20);
			if (i < 3) gem = "yan";
			else if (i < 6) gem = "mu";
			else if (i < 9) gem = "sui";
			else if (i < 12) gem = "jin";
			else if (i < 15) gem = "bing";
			else if (i < 16) gem = "gu";
			else if (i < 17) gem = "yu";
			else if (i < 18) gem = "jiao";
			else gem = "jia";
            baoshi->set_level(1,9999,gem);
            baoshi->move(me);
            tell_object(me,"作为内廷十二监正官，下属孝敬你宝石一枚。\n");
            message( "channel:" + "baowei",HIW + "【大明】内廷：" + me->query("name")+"被下属孝敬"+baoshi->query("name")+HIW+"一枚。\n"NOR,users());
        }
	    return 1;
    }
    
}