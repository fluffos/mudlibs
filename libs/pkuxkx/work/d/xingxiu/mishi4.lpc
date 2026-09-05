// 密室
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>



void create()
{
	set("short", "密室");
	set("long", @LONG
这里星宿派炼制毒物的密室。外人不得入内。
LONG
	);
    set("normaldesc", @LONG
这里星宿派炼制毒物的密室。外人不得入内。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"mishi2",
		
    ]));
	//set("objects", ([(__DIR__"npc/qinjun") : 1,
    //]));
	setup();
	::create();
}

void init()
{
        add_action("do_liandu", "liandu");
        add_action("do_ronghe", "ronghe");
        add_action("do_special","special");
        ::init();
}

int do_special()
{
    return notify_fail("炼毒室不需使用特技。\n");
}

int checkst(object me)
{
    
    string* desc=({"毒液在你体内徘徊，久久不能凝聚。\n","你潜运内力，试图融合毒液，却未能成功。\n","你的内力和毒液接近融合，成功只在一线之间。\n","毒液被你吸收入体内，到处乱窜。\n",});
    string* color=({RED,YEL,BLU,GRN,CYN,HIM,WHT});
    int exp;
    if (me->query_temp("liandutimes")>10+random(10))
    {
        if (base_name(environment(me))!="/d/xingxiu/mishi4")
        {
            tell_object(me,"你不知道自己为何离开了密室，赶紧停止了炼毒。\n");
            return 1;
        }
        if ((int)me->query_skill("poison", 1) < 100 && random(100)>70)
        {
            message_vision("$N毒技研究不够，终于控制不住，伤了自己。\n", me);
            me->apply_condition("xx_poison", 5);
            me->set_temp("liandutimes",0);
            return 1;
        }

        else
        {
            me->improve_skill("poison", (me->query_skill("huagong-dafa",1)+me->query("poison",1))*(int)(me->query("int"))* (int)me->query_temp("liandutimes")/150);
            write (RED"你只觉得毒液在体内行走一周天后，完全与你的内力融合。\n"NOR"你对基本毒技的领会又加深了一些！\n");
            me->set_temp("liandutimes",0);
            if (random(100)>40)
            {
            
                exp=me->query_skill("poison",1)/3;
                exp=REWARD_D->add_exp(me,exp);
                me->add("exp/xxliandu", exp);
                write("冥冥中，你觉得自己获得了"+chinese_number(exp)+"点经验；\n");
               
            }
            return 1;
         
        }
    }
    else
    {
        if (base_name(environment(me))!="/d/xingxiu/mishi4")
        {
            tell_object(me,"你不知道自己为何离开了密室，赶紧停止了炼毒。\n");
            return 1;
        }
        tell_object(me,color[random(sizeof(color))]+desc[random(sizeof(desc))]+NOR);
        me->add_temp("liandutimes",1);
        me->add_busy(2);
        call_out("checkst",2+random(2),me);
        return 1;
    }
}

int checkst2(object me)
{
    
    string* desc=({"五毒的毒素在你体内徘徊，却难以凝聚成形。\n","你将五毒毒素融合进自身精血，却未能成功。\n","你本身精血和五毒毒素接近融合，成功只在一线之间。\n","五毒毒素被你吸收入体内，却到处乱窜。\n",});
    string* color=({RED,YEL,BLU,GRN,CYN,HIM,WHT});
    int exp,increase,bonus;
    if ( !objectp(me) )
    	return 0;
    
    if (me->query_temp("liandutimes")>10+random(10))
    {
        if (base_name(environment(me))!="/d/xingxiu/mishi4")
        {
            tell_object(me,"你不知道自己为何离开了密室，赶紧停止了炼毒。\n");
            return 1;
        }
        if ((int)me->query_skill("poison", 1) < 300 && random(100)>70)
        {
            message_vision("$N毒技研究不够，终于控制不住，伤了自己。\n", me);
            me->apply_condition("xx_poison", 5);
            me->set_temp("liandutimes",0);
            return 1;
        }

        else
        {
            me->apply_condition("xx_poison", 1+random(3));
            increase=(me->query_skill("huagong-dafa",1)+me->query("poison",1))*(int)(me->query("con"))* (int) me->query_temp("liandutimes")*4/(int)(me->query("int")*13);
            if (present("xiang",me)&&present("xiang",me)->query("is_xiang")&&present("xiang",me)->query("dian"))
            {
                message_vision(HIW+"$N身上的$n"+HIW+"在融合毒素中起到了凝神的功效。\n"+NOR,me,present("xiang",me));
                bonus=100+(int)present("xiang",me)->query("basic_xiang_bonus")+(int)present("xiang",me)->query("xiang_bonus");
                
                if (time()<1322902169)
                {
                    increase=increase*2;
                }
                else
                {
                    increase=increase*bonus/100;
                }
                if (me->query("id")=="zine")
                {
                    tell_object(me,"加成效果"+bonus+"%.\n");
                }
                if (!random(10))
                {
                    me->improve_skill("force", increase);
                }
                if (!random(20))
                {
                    me->improve_skill("huagong-dafa", increase);
                }
            }
            me->improve_skill("poison", increase);
            write (BLU"你只觉得五毒毒素在体内行走一周天后，与你的精血完全融合。\n"NOR"你对基本毒技的领会又加深了一些！\n");
            me->set_temp("liandutimes",0);
            if (random(100)>40)
            {
            
                exp=me->query_skill("poison",1)/2;
                exp=REWARD_D->add_exp(me,exp);
                me->add("exp/xxliandu", exp);
                write("冥冥中，你觉得自己获得了"+chinese_number(exp)+"点经验；\n");
               
            }
            return 1;
         
        }
    }
    else
    {
        if (base_name(environment(me))!="/d/xingxiu/mishi4")
        {
            tell_object(me,"你不知道自己为何离开了密室，赶紧停止了炼毒。\n");
            return 1;
        }
        tell_object(me,color[random(sizeof(color))]+desc[random(sizeof(desc))]+NOR);
        me->add_temp("liandutimes",1);
        me->add_busy(2);
        call_out("checkst2",2+random(2),me);
        return 1;
    }
}

int do_liandu(string arg)
{
        object me = this_player();
        object duye = present("du ye",me);
        if (me->query_skill("poison", 1) > 199 && (me->query("newbiediaoyu")||me->query("newbie_hongdou")))
			return notify_fail("因为你早年不听从师门教诲，并没有被告知进一步炼毒的秘诀。\n");
		//红豆不再限制
        if ((int)me->query_skill("poison", 1) > 300)
                return notify_fail("你的毒技已经较为高深，无法再用五毒的毒液修炼。\n");
        if ( arg != "du ye" || !living(this_player()))
                return notify_fail("你要用什么炼毒？\n");
        if(!duye)
                return notify_fail("你身上没有毒液，无法炼毒。\n");
        if(duye->query("owner")!=me->query("id"))
                return notify_fail("只有自己采取的毒液才能和自身融合。\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成, 不能运功炼毒。\n");
        if ( me->is_fighting())
                return notify_fail("你在战斗中不能运功炼毒。\n");
        if ( me->query("neili") < 100)
               return notify_fail("你内力太低，无法融合毒素。\n");

        message_vision("$N将毒液用内力炼化，缓缓吸入体内。\n", me);
        destruct(duye);
        me->set_temp("liandutimes",0);
        me->add("neili", -10);
        call_out("checkst",1,me);
        return 1;
         
}

int do_ronghe(string arg)
{
        object me = this_player();
        object du; 
        if (!arg)
        return notify_fail("你要用什么融合？\n");
		du= present(arg,me);
        if (!objectp(du))
		return notify_fail("你身上有这样东西吗？\n");
		if (me->query("newbie_hongdou")||me->query("newbiediaoyu"))
		return notify_fail("因为你早年不听从师门教诲，并没有被告知融合的秘诀。\n");
		if ((int)me->query_skill("poison", 1) >= 700)
                return notify_fail("你的毒技已经较为高深，无法再用五毒来融合修炼。\n");
        if ((int)me->query_skill("poison", 1) >= 600&&!me->query("safari_skill/xx_dushen"))
                return notify_fail("你的毒技已经较为高深，无法再用五毒来融合修炼。\n");
        if ( (arg != "xue zhizhu" && arg != "dilong xiezi" && arg != "huo wugong" && arg != "zhuye qing" && arg != "youming hama") || !living(this_player()))
                return notify_fail("你只能用五毒融合！\n");
        if(!present("xue zhizhu",me) && !present("dilong xiezi",me) && !present("huo wugong",me) && !present("zhuye qing",me) && !present("youming hama",me))
                return notify_fail("你身上没有五毒，要怎么融合？\n");
        if(du->query("owner")!=me->query("id"))
                return notify_fail("只有自己抓来的五毒才能和自身融合。\n");
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成, 不能运功融合。\n");
        if ( me->is_fighting())
                return notify_fail("你在战斗中不能运功融合。\n");
        if ( me->query("neili") < 1000)
               return notify_fail("你内力太低，无法融合毒素。\n");
        if((int)me->query("eff_jing") < (int)me->query("max_jing")*2/3)
               return notify_fail("你精血不够，无法融合毒素。\n");
        message_vision("$N将五毒与自身融合，毒素在体内运转。\n", me);
        destruct(du);
        me->set_temp("liandutimes",0);
        me->add("neili", -100);
        call_out("checkst2",1,me);
        return 1;
         
}
