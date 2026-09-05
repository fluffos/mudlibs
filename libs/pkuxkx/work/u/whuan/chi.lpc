// chi.c
// 洗象池中

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"洗象池"NOR);
        set("long", @LONG
这是一个石砌的六角小池，传说普贤乘象至此，必先在此池沐浴其象，而后才
升至金顶，故为「洗象池」。池水清澈透亮。
LONG);
        set("outdoors", "峨嵋派");
        setup();
}

void init()
{
        object me, room;

        me = this_player();
        room = load_object(__DIR__"xixiangchi");
        if(interactive(me)){ 
                tell_room(environment(me), me->name()+"扑通一声跳了进来。\n", ({ me }));
                tell_object(me, "你扑通一声跳进了池水。\n");    
                tell_room(room, "只听“扑通”一声，"+me->name()+"已经跳进了池水里。\n");        
                call_out("do_swim", 1, me);     
        }
        add_action("do_no", "save");
        add_action("do_no", "quit");
        add_action("do_no", "practice");
        add_action("do_no", "respirate");
        add_action("do_no", "exercise"); 
        //不能攻击
        add_action("do_no", "hit");
        add_action("do_no", "hitall");
        add_action("do_no", "kill");
        add_action("do_no", "killall");
        add_action("do_no", "exert");
        add_action("do_no", "yun"); 
        add_action("do_no", "perform"); 
        add_action("do_halt", "halt");  }

int do_no()
{
        write("不准！\n");
        return 1;
}

int do_swim(object me)
{
        if (!me || !present(me) || !living(me)) return 0;       
        
        if(me->query_con() < 25){
                tell_object(me, HIB "不料池水冰冷刺骨，你猛得一颤，连忙爬出池外！\n"NOR);
                tell_room(environment(me), me->name()+"全身哆嗦，急急忙忙地又爬了上去！\n", ({ me }));
                me->move(__DIR__"xixiangchi");
                tell_room(environment(me), me->name()+"急急忙忙地从洗象池中跳了上来，全身发白，直打哆嗦！\n", ({ me }));
                me->start_busy(2);
                me->receive_damage("qi", 100);
                me->receive_damage("jing", 100);
                return 1;
        }
        tell_object(me, GRN "你在清凉的池水中尽情嬉戏，不过你还是担心有人在路旁走过窥探。\n"NOR);
        me->set_temp("swimming", 1);
        me->set_temp("apply/short", ({me->short(1)+GRN" <游水中>"NOR}));
        me->receive_damage("jing", me->query("con") * 4 );
        call_out("do_pa", (int)(50-me->query("con")), me);
        me->start_busy(1);
        return 1;        
}

int do_pa(object me)
{
        int i;

        if(!me || !present(me)) return 0;
        me->delete_temp("swimming");
        me->delete_temp("looked");
        me->delete_temp("apply/short");
        if(!living(me)){
                message_vision("一阵清风吹来，将昏迷的$N推到池边。\n", me);
                me->move(__DIR__"xixiangchi");
                message_vision("一阵徐徐清风吹来，将昏迷的$N推到了池边。\n", me);
                return 1;
        }
        //me->carry_object(__DIR__"obj/cloth")->wear();
        tell_object(me, HIY "\n突然一阵清风吹来，你哆嗦了一下，连忙爬出洗象池。\n" NOR );       
        tell_room(environment(me), "一阵清风吹过，"+me->name()+"轻轻哆嗦了一下，爬上池边穿好衣服。\n", ({ me }));
        i = me->query("per")/2;
        if (me->query_skill("beauty",1) < me->query_skill("force",1))
                me->improve_skill("beauty", me->query("con") * (i + random(i)));
        me->move(__DIR__"xixiangchi");
        call_out("get_ob",1,me);
        me->start_busy(1);
        tell_room(environment(me), me->name()+"精神抖擞地从洗象池中爬了上来。\n", ({ me })); 
        return 1;
}

int do_halt()
{
        object me = this_player();

        if (me->is_busy())
                return notify_fail("你正忙着哪！\n");
        remove_call_out("do_pa");
        me->delete_temp("swimming");
        me->delete_temp("apply/short");  
        if(me->query_temp("looked")){  
                me->delete_temp("looked");
                write(HIY "你连忙穿好衣服，爬出洗象池。\n" NOR);
                //me->carry_object(__DIR__"obj/cloth")->wear();
                tell_room(environment(me), me->name()+"匆匆忙忙穿好衣物，爬上池边。\n", ({ me }));
                call_out("get_ob",1,me);
                me->move(__DIR__"xixiangchi");
                tell_room(environment(me), me->name()+"一脸气极败坏地从洗象池中爬了上来。\n", ({ me })); 
                return 1;
        }
        write(HIY "突然你想起了什么事，连忙爬上池边穿好衣服。\n" NOR );
        //me->carry_object(__DIR__"obj/cloth")->wear();
        tell_room(environment(me), me->name()+"好象想起了什么似的，急忙爬上池边穿好衣服。\n", ({ me }));
        call_out("get_ob",1,me);
        me->move(__DIR__"xixiangchi");
        tell_room(environment(me), me->name()+"急急忙忙地从洗象池中爬了上来。\n", ({ me })); 
        return 1;
}
void get_ob(object me)
{
        object *inv;            	     
        object temproom;
        int i;
        if (objectp(temproom = me->query_temp("bath/temproom")))
        {
            inv = all_inventory(temproom);
            for(i=0; i<sizeof(inv); i++) 
            {
            inv[i]->move(me);
            }
            tell_object(me,"你把衣服打开，把东西拿了出来。\n");
            "/cmds/std/wear"->main(me,"all");
            destruct(temproom);
            me->delete_temp("bath/temproom");
        }
        return;
}  
