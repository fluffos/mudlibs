// Room: /d/xingxiu/yueerquan.c
// Jay 3.17/96
// Zine 2010 Dec 10 Add hswlb quest
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "月儿泉");
        set("long", @LONG
出乎你的意料之外，在沙漠中竟然有泉水。一泓清澈的泉水形成一个月牙的
形状，因而得名月儿泉。南面是一片峭壁(cliff)，东边传来嗡嗡的声响。
LONG
        );
        set("resource/water", 1);

        set("exits", ([
                "east" : __DIR__"shashan",
        ]));

        set("item_desc", ([
                "cliff" : "峭壁上似乎有一个洞(hole)。\n"
        ]) );

        setup();
//        replace_program(ROOM);
}

void init() //by Zine黄沙万里鞭quest
{
        object me=this_player();
        add_action("do_enter", "enter");
        add_action("do_wubian", "wubian");
        if (me->query_temp("yeqfirst"))
        {
            return;
        }
        if (me->query_temp("silkjob/found")|| (me->query("hswlbcanlearn")&&me->query_skill("huangsha-wanlibian",1)<188))
        {
            tell_object(me,"你觉得沙漠中万里黄沙，似乎隐藏着绝世武功的道理，想找个鞭子来印证(wubian)自己想法。\n");
            me->delete_temp("silkjob");
            me->set_temp("yeqfirst",1);
            me->delete("silkjob");
            me->set("hswlbcanlearn",1);
        }
        return;
}

int checkst(object me)
{
    
    string* desc=({"你神态自若，手中鞭如龙蛇一般。\n","你潜运内力，手中鞭如一支利剑直插蓝天。\n","手中鞭一圈两圈三圈，大大小小的圈子连环裹叠。\n","你大喝一声，手中鞭子竟如有神助一般准准击中丈外的一只苍蝇。\n",});
    string* color=({RED,YEL,BLU,GRN,CYN,HIM,WHT});
    int exp;
    if (me->query_temp("wbtimes")>5+random(5))
    {
        if (base_name(environment(me))!="/d/silk/yueerquan")
        {
            tell_object(me,"你不知道自己身处何地，赶紧停止了练功。\n");
            return 1;
        }
        if (!me->query("hswlbcanlearn"))
        {
            message_vision("$N状若癫狂，一鞭抽在自己头上，伤了自己。\n", me);
            me->set_temp("wbtimes",0);
            return 1;
        }

        else
        {
            me->improve_skill("huangsha-wanlibian", (int)(me->query("int"))* (int)me->query_temp("wbtimes")* 10);
            write (YEL"你的黄沙万里鞭精进了一些。\n"NOR);
            me->set_temp("wbtimes",0);
            if (random(100)>65)
            {
            
                exp=1+me->query_skill("huangsha-wanlibian",1);
                exp=REWARD_D->add_exp(me,exp);
                write("冥冥中，你觉得自己获得了"+chinese_number(exp)+"点经验；\n");
               
            }
            return 1;
         
        }
    }
    else
    {
        if (base_name(environment(me))!="/d/silk/yueerquan")
        {
            tell_object(me,"你不知道自己身处何地，赶紧停止了练功。\n");
            return 1;
        }
        tell_object(me,color[random(sizeof(color))]+desc[random(sizeof(desc))]+NOR);
        me->add_temp("wbtimes",1);
        me->add_busy(2);
        call_out("checkst",1+random(2),me);
        return 1;
    }
}


int do_wubian()
{
        object me=this_player();
        object weapon;
        if (!me->query("hswlbcanlearn"))
        {
            return notify_fail("你笨拙的样子还不如放羊的牧童，别丢人现眼了！\n");
        }
        if( me->is_busy() )
            return notify_fail("你上一个动作还没有完成, 不能领悟高深鞭法。\n");
        if ( me->is_fighting())
                return notify_fail("你在战斗中不能领悟高深鞭法。\n");
        if ((int)me->query_skill("huangsha-wanlibian", 1) > 188)
                return notify_fail("你的黄沙万里鞭已经有相当造诣，无法在这里提高了。\n");
        if ( me->query("neili") < 100)
               return notify_fail("你内力太低，无法领悟高深鞭法。\n");
        if (me->query_skill("whip",1)>200)
        {
            return notify_fail("你的基本鞭法已有格局，黄沙万里鞭运鞭方式完全不同，你无法领会。\n");
        }
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "whip")
            return notify_fail("你要装备鞭类武器才能领悟黄沙万里鞭。\n");
        message_vision("$N缓缓舞动手中鞭，意态古拙。\n", me);
        me->set_temp("wbtimes",0);
        me->add("neili", -10);
        call_out("checkst",1,me);
        return 1;
         

}

int do_enter(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="hole" ) {
                if ( me->query_encumbrance() * 100 / me->query_max_encumbrance() < 20) {
		                        message("vision",
me->name() + "一纵身跃进了洞里。\n",
                        environment(me), ({me}) );
                        me->move("/d/silk/mogaoku");
                        message("vision",
me->name() + "从洞外跳了进来。\n",
                        environment(me), ({me}) );
                return 1;
                }
                else {
                        write("你身上背的东西太重，洞口又太高，你够不着。\n");
                        return 1;
                }
        }
}

