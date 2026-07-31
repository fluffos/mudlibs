inherit ROOM;
#include <room.h>
int doing(object me);
void create()
{
        set("short", "厢房");
        set("long", @LONG
屋小幽雅，正中一张小几，几上有琴，琴上无弦。旁边一圆凳，凳上鸳鸯垫。
屋角木床，床单上大红刺绣，绣的是一对鸳鸯戏水。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"corror",
]));
        set("sleep_room", 1);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_get", "1");
        set("no_bug", "1");

        set("objects", ([
//        __DIR__"npc/chick1" : 1,
                        ]) );

        setup();
        create_door("west", "木雕门", "east", DOOR_CLOSED);
}

void init()
{
    add_action("do_makelove", "makelove");
}

int do_makelove(object arg)
{
        object obj,me;
        object *ob;
        int i;

        me=this_player();
        if (me->query("gender")=="无性")
        {
               tell_object(me,"唉!你无根无性，今生今世都没这个能力了！\n");
               return 1;
        }
        if(!arg || !objectp(obj = present(arg, environment(me))))
        {
               tell_object(me,"你想和谁赴巫山之会？\n");
               return 1;
        }

        if( !obj->is_character()||me->query("gender")==obj->query("gender") )
                return notify_fail("这样...？！恐怕不行吧？\n");

        if(!living(obj))
                return notify_fail("人家都这样了，你还...\n");

        if( !environment(me)->query("sleep_room")||
                 environment(me)->query("no_sleep_room"))
                return notify_fail("总得找个温馨点儿的地方吧。\n");

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++)
                if( ob[i]->is_character()&&ob[i]!=me
                        &&ob[i]!=obj&&!wizardp(ob[i]) )
                        return notify_fail("这儿还有别人呢，多不好意思呀！\n");
        if(!me->query_temp("makelove/quest"))
        {

            if((me->query("gender")=="男性"))
                {
                   message_vision(HIM "$N轻轻来到$n身后，双手环抱在$n的腰间，\n
在$n耳边柔声说道：亲爱的，今晚...\n"NOR,me,obj);
                tell_object(obj, HIR "傻子也能看出来他想和你共渡良宵，\n
如果你愿意，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 makelove 指令。\n" NOR);
                }
            else
                {
                        message_vision(HIM "不知是因为烛光，还是酒精，亦或是因为兴奋，$N的小脸儿红红的，\n
端着酒杯，$N直勾勾地盯着$n：亲爱的...听说...喝酒...乱性...\n"NOR,me,obj);
                tell_object(obj, HIR "傻子也能看出来她想和你共渡良宵，\n
如果你愿意，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 makelove 指令。\n" NOR);
                }
                obj->set_temp("makelove/quest",1);

        }
        else
        {
            if((me->query("gender")=="男性"))
                {
                        message_vision(HIM "$N回敬似的盯着$n的眼睛，半晌一言不发，突然一把抱住$n，\n
一双热唇堵住了$n的嘴，让$n简直喘不上来气，酒杯、红烛打了一地...\n"NOR,me,obj);
                call_out("over", 1, me,obj);
                }
                else
                {
                        message_vision(HIM "$n甚至能看见$N羞红的耳根，$N轻轻挣开$n的怀抱，\n
默默地焚香沐浴，$n却再也忍不住，一把将$N抱了起来...\n"NOR,me,obj);
                call_out("over", 1, obj,me);
                }
                me->delete_temp("makelove/quest");
        }


        return 1;
}


void over(object me,object obj)
{
        message_vision(HIR"...一阵疾风骤雨。\n"NOR,me);
        if(me->query("qi")<30||me->query("jing")<30||obj->query("qi")<30||obj->query("jing")<30)
        {
                if(me->query("qi")<30||me->query("jing")<30)
                {
                    message_vision(HIR "$N突然口吐鲜血，晕倒在地。看来是纵欲过度了。"NOR,me);
                    me->unconcious();
                }
                else
                {
                    message_vision(HIR "$N突然口吐鲜血，晕倒在地。看来是纵欲过度了。"NOR,obj);
                    obj->unconcious();
                }
        }
        else
        switch(random(10))
        {
        case 0:
                message_vision(HIR "$N突然大叫一声，显然是极度兴奋，紧接着竟晕死过去！\n"NOR,me);
                me->unconcious();
                obj->add("qi",obj->query_str()-55+random(10));
                obj->add("jing",obj->query_con()-55+random(10));
                break;
        case 1:
                message_vision(HIR "$N突然大叫一声，显然是极度兴奋，紧接着竟晕死过去！\n"NOR,obj);
                obj->unconcious();
                me->add("qi",obj->query_str()-55+random(10));
                me->add("jing",obj->query_con()-55+random(10));
                break;
        default:
                if(random(1))
                {
                        message_vision(YEL "$N坐在一旁闷头不语，望了一眼仍在微微娇喘的$n，\n
喃喃说到：要不然...再让我试一次...\n"NOR,me,obj);
                }
                else
                {
                        message_vision(HIY "$n静静地躺在$N的怀里，靠着那起伏的胸膛，\n
听着那均匀的呼吸，感到无限的幸福...\n"NOR,me,obj);
                }
                obj->add("qi",obj->query_str()-55+random(10));
                obj->add("jing",obj->query_con()-55+random(10));
                me->add("qi",obj->query_str()-55+random(10));
                me->add("jing",obj->query_con()-55+random(10));
        }
}
int valid_leave(object me, string dir)
{
        if ( dir == "west" )
        me->delete_temp("tmark");
        return 1;
}

