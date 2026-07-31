// duanchang.c

#include <ansi.h>
#include <room.h>
#include "tiao.c"
inherit ROOM;


void init()
{
        add_action("do_pa", "pa");
        add_action("do_bang", "bang");
        add_action("do_cuo", "cuo");
        add_action("do_tiao", "tiao");
        add_action("do_yes", "yes");
        add_action("do_no", "no");
        add_action("do_jump","jump");        
        add_action("do_xiao","xiao");
}

void create()
{
        set("short",YEL"峭壁"NOR);
        set("long", @LONG
你来到山峰腰部的一处峭壁，岩壁上不知是谁刻得有几行大字（dazi），
自此向上，数十丈光溜溜的寸草不生，终年云雾环绕，天风猛烈，便飞鸟也甚
难在峰顶停足。山崖旁边就是一道深渊（shenyuan）。悬崖边上长着一棵老松
树（song）斜斜的探出崖边。
LONG);
        set("item_desc", ([
        "dazi": HIY"                             
            ※※※※※※※※※※※※※※※※※※
            ※※※※　                  ※※※※
            ※※※※    十 六 年 后，   ※※※※
            ※※※※                    ※※※※
            ※※※※    在 此 相 会，   ※※※※
            ※※※※                    ※※※※
            ※※※※    夫 妻 情 深，   ※※※※
            ※※※※                    ※※※※
            ※※※※    勿 失 信 约。　 ※※※※ 
            ※※※※　                  ※※※※
            ※※※※※※※※※※※※※※※※※※\n"NOR,
        "shenyuan":HIB"你从渊口向下望去，但见渊中云雾缭绕，黑幽幽的深不见底。\n"NOR,
        "song": HIG"一棵老松树，盘枝交错，斜探着枝桠深入云霄。\n"NOR,
        ]));

        set("outdoors", "绝情谷");

        setup();
}

int do_pa(string arg)
{
        object me;

        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if ( !arg || arg != "down" )
                return notify_fail("你要往哪爬？\n");
        if (!me->query_temp("mark/bang"))
                return notify_fail("你想跳崖自杀么？直接跳下去吧！\n");
        message_vision(HIG"$N颤颤噤噤地爬了下去。\n"NOR, me);
        me->move(__DIR__"yabi1");
        me->add_temp("tengacc",-1);
        tell_room(environment(me), me->name() + "从上面颤颤噤噤地爬了下来。\n", ({ me }));
        me->delete_temp("mark/bang");
        return 1;
}

int do_bang(string arg)
{      
        object me;
        me = this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if( (int)me->query_temp("tengacc", 1)<=0 )
            return notify_fail("你要用什么绑？\n");
        if ( !arg || arg != "song" )
                return notify_fail("你要绑什么？\n");
        if (me->query_temp("mark/bang"))
                return notify_fail("绳子已经绑好了。\n");
        message_vision(HIY"$N仔仔细细地把树藤一端绑在松树干上。\n"NOR, me);
        me->set_temp("mark/bang",1);
        return 1;
}

int do_cuo(string arg)
{
        object me;
        me = this_player();
        if ( !arg || arg != "shupi" )
        return notify_fail("你要搓什么？\n");         
        if( (int)me->query_temp("tengacc", 1)<=0 )
        {
                if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");                
                message_vision(GRN"$N剥下一块树皮，将它搓成一根树藤。\n"NOR, me);
                me->set_temp("tengacc", 1);
                return 1;
        }
        if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着哪！\n"); 
        if ((int)me->query_temp("tengacc") >= 8)
          return notify_fail("树皮都被你剥光了，你还剥什么剥？\n");
        message_vision(GRN"$N剥下一块树皮，用它把树藤接长。\n"NOR, me);
        me->add_temp("tengacc",1);
        return 1;
}

int do_jump(string arg)
{
       object me;
       me = this_player(); 
       if (arg != "back" ) return 0;
       if (!arg ) return 0;        
       if (!living(me)) return 0;
         message_vision("$N纵身向断肠崖跳了回去。\n", me);
       if(me->query_temp("tengacc"))
         me->delete_temp("tengacc");
         me->move(__DIR__"shanlu10");
         tell_room(environment(me), me->name() + "从峭壁跳了过来。\n", ({ me }));
         return 1;
}

int get_object(object ob)
{
       return userp(ob);
}

int do_xiao(string arg,object *obj)
{
        object me=this_player();
        mapping fam;
        object *inv = deep_inventory(me);        
        fam = me->query("family");
        if (arg) return 0;
        if( ! fam || fam["family_name"] != "古墓派") return 0;
        obj = filter_array(inv,(:get_object:));
        if(sizeof(obj)){
          tell_object(me,HIR"你刚想偷偷背个人骑上白雕，结果负重太多，脚下一个绊拴，摔倒在地。\n"NOR);
          me->unconcious();
          return 1;
        }
        message_vision(HIW"\n$N当下作哨招雕，只见白雕双翅一振，高飞入云，盘旋数圈，猛地里从空中疾冲而下。\n"+
                          "$N骑上白雕后，那白雕厉声长鸣，穿破云雾，冲下山崖。\n\n"NOR,me);
        me->move(__DIR__"tanan");
        tell_room(environment(me), me->name() + "从白雕身上跳了下来，白雕双翅一振，高飞入云。\n", ({ me }));
        return 1;
}
