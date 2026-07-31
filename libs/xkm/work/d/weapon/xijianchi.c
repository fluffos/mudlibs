#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"洗剑池"NOR);
        set("long", @LONG
这是侠骨柔情中的一块圣地,常年处在关外的冰峰之中,吸收着天地的灵气,武林中人
常常在这里洗剑,希望借天地的灵气来锻炼自己的武器,但是能不能成功就要看自己的造化了
你可以试试在这个有灵气的地方提升(levelup)武器的等级。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //  "down" : __DIR__"tianchi1",
]));
       
        set("no_death_penalty",1);
        set("no_dazuo",1);
               
        setup();
}
void init()
{
        add_action("do_levelup","levelup");
      }
int  do_levelup(string arg)
{
        object me, ob;
        object gold;
        int cost = 1;
        int i,j,base,current;
        string id,name ;        
        string file,newfile,filestring;
        me = this_player();
        id = me->query("id");
        if( !arg ) return notify_fail("你要提升什麽武器？\n");
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("你身上没有金子。\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("你身上没有这样东西。\n");
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
        if( ob->query("equipped") )
        return notify_fail("你不可祭装备著了的武器。\n");
        if( !ob->query("ownmake") )
        return notify_fail("你只可祭自己打造的武器。\n");
        if( (int)me->query("qi") < 150 )
                return notify_fail("你的气不够，无法锻炼兵器！\n");

        if( (int)me->query("eff_qi") < 30 )
                return notify_fail("你现在的体力太弱，无法锻炼兵器！\n");

        if( (int)me->query("eff_jing") < 10 )
                return notify_fail("你现在的精力无法集中，不能锻炼兵器！\n");
             if( (int)me->query("max_neili") < 1000 )
            return notify_fail("你现在的内力不够，不能锻炼兵器！\n");
/*
            if( (int)me->query("score") < 100 )
                return notify_fail("你现在的江湖阅历不够，不能锻炼兵器！\n");
*/
        if( ((int)me->query("potential") - (int)me->query("learned_points"))< 500 )
                return notify_fail("你的潜能不够，无法锻炼兵器！\n");
        j = (int)me->query("weapon/lv");

        if(j<6) cost = 30*j;
        else if(j<11) cost = 40*j;
        else if(j<20) cost = 50*j;
        else if(j<40) cost = 60*j;
        else if(j<60) cost = 70*j;
             else if(j<80) cost = 80*j;
           else cost = 120*j;
        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没带够" + sprintf("%d",cost)+ "两金子。\n");
        gold->add_amount(-cost);
        me->start_busy(4);
        me->add("bellicosity",cost);
        seteuid(ROOT_UID);
        me->add("qi",-150);
        me->add("eff_qi",-30);
        me->add("jing",-30);
        me->add("eff_jing",-30);
        me->add("score",-100);
        me->add("learned_points", 100);
        me->set("weapon/lv", j+1);
        me->add("max_neili", -j*5);
        me->save();
        reload_object(ob);
        message_vision(HIC "只见眼前忽的一亮，一道金光隐入$N的"+ob->name()+HIY"，不见了！\n" NOR,me);
        message_vision(HIG "$N的"+ob->name()+HIG"的剑气提高了！\n" NOR, me);
        seteuid(getuid());
        return 1;
}


