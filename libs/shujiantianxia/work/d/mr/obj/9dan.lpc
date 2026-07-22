// 9dan.c
// by leontt@Sj 10/10/2000

#include <ansi.h>
inherit ITEM;
mapping *poi_list = ({
        (["id":         "snake_poison", // 所中毒的E文名称
          "name":       "蛇毒", // 所中毒的中文名称
          "col":        "\"BLU\"", // 中毒发作的颜色
          "con":        "湛蓝之气",]), // 中毒发作的状态
        (["id":         "lvbo_poison",
          "name":       "绿波香露奇毒",
          "col":        "\"BLU\"",
          "con":        "湛蓝之气",]),
        (["id":         "xx_poison",
          "name":       "星宿掌毒",
          "col":        "\"BLU\"",
          "con":        "湛蓝之气",]),
        (["id":         "dsy_poison",
          "name":       "密宗大手印掌毒",
          "col":        "\"CYN\"",
          "con":        "青气",]),
        (["id":         "fs_poison",
          "name":       "腐尸毒",
          "col":        "\"HIG\"",
          "con":        "绿气",]), 
        (["id":         "huagu_poison",
          "name":       "化骨绵掌剧毒",
          "col":        "\"BLU\"",
          "con":        "湛蓝之气",]),
        (["id":         "man_poison",
          "name":       "蔓陀萝花毒",
          "col":        "\"HIB\"",
          "con":        "黑气",]),
        (["id":         "qinghua_poison",
          "name":       "情花毒",
          "col":        "\"MAG\"",
          "con":        "紫气",]),
        (["id":         "qishang_poison",
          "name":       "七伤拳毒",
          "col":        "\"HIR\"",
          "con":        "潮红之气",]),
        (["id":         "yyz_hurt",
          "name":       "一阳指内伤",
          "col":        "\"HIY\"",
         "con":        "蜡黄之色",]),
        (["id":         "hunyuan_hurt",
          "name":       "混元无极内伤",
          "col":        "\"HIR\"",
         "con":        "潮红之气",]),
        (["id":         "qzhu_poison",
          "name":       "千蛛万毒手毒",
          "col":        "\"HIR\"",
          "con":        "潮红之气",]),
        (["id":         "sld_shexin",
          "name":       "摄心大法",
          "col":        "\"HIC\"", 
          "con":        "疯癫状态",]),
        (["id":         "sl_poison",
          "name":       "神龙毒",
          "col":        "\"BLU\"", 
          "con":        "湛蓝之气",]),
        (["id":         "sy_poison",
          "name":       "大手印掌毒",
          "col":        "\"HIR\"",
          "con":        "潮红之气",]),
        (["id":         "warm_poison",
          "name":       "热毒",
          "col":        "\"RED\"",
          "con":        "殷红之气",]),
        (["id":         "hot_poison",
          "name":       "火毒",
          "col":        "\"HIR\"",
          "con":        "潮红之气",]),
        (["id":         "cold_poison",
          "name":       "寒毒",
          "col":        "\"HIC\"",
          "con":        "绿青之气",]),
        (["id":         "bing_poison",
          "name":       "冰魄银针毒",
          "col":        "\"HIB\"",
          "con":        "湛蓝之气",]),
        (["id":         "bt_poison",
          "name":       "怪蛇毒", 
          "col":        "\"YEL\"",
          "con":        "泛黄之气",]),
        (["id":         "hb_poison",
          "name":       "寒冰绵掌毒",
          "col":        "\"HIB\"",
          "con":        "湛蓝之气",]),
        (["id":         "tz_poison",
          "name":       "铁掌奇毒",
          "col":        "\"HIR\"",
          "con":        "潮红之色",]),
        (["id":         "cold_poison",
          "name":       "寒冰神掌毒",
          "col":        "\"HIY\"",
          "con":        "寒气",]),
});

void setup()
{}
void init()
{
        add_action("do_eat", "fu");
}
void create()
{
        set_name(HIY"九天回转丹"NOR, ({"huizhuan dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗慕容祖传秘方配制的九天回转丹，据说能解百毒。\n");
//                set("value", 15); 
                set("no_give",1);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        int poi_lvl, neili_cost, i;
        mapping poi;

        if (!id(arg))
                return notify_fail("你要吃什么？\n");

        if((int)me->query_skill("medicine", 1) < 80 )
                return notify_fail("你的本草术理太低，吃了也没多大用。\n");

        if (me->query("family/family_name") != "姑苏慕容")
                return notify_fail("你并不是慕容弟子，偷吃别人的东西脸不红么!?\n");
        if( me->is_fighting() )
                return notify_fail("你正在战斗中，无法疗毒。\n");

        if( me->is_busy() )
                return notify_fail("你正忙着呢，无法疗毒。\n"); 

        for(i=0;i<sizeof(poi_list);i++)
        {
                poi = poi_list[i];
                if (me->query_condition(poi["id"]) > 0 )
                {
                        poi_lvl = me->query_condition(poi["id"]);
                        neili_cost = poi_lvl*3;
                        if (poi_lvl < (int)me->query_skill("medicine", 1)*2)
                        {
                                if( (int)me->query("neili") < neili_cost )
                                        return notify_fail("你的内力不足以借助"HIY"九天回转丹"NOR"去除体内余毒。\n");
                                 message_vision("$N双眼紧闭运功疗毒，借助"HIY"九天回转丹"NOR"的奇效，漫漫脸上的" + poi["con"] + "逐渐减退。\n",me);
                                tell_object(me,"你所中的" + poi["name"] + "已经完全去除。\n");
                                me->clear_condition(poi["id"]);
                                me->add("neili",-neili_cost);
                                me->start_busy(2);
                                me->set_temp("mr/9dan",1);
                                me->apply_condition("medicine",5 + random(5));
                                call_out("dest",0,this_object());
                                break;
                        }
                        else 
                        {
                                me->apply_condition(poi["id"],poi_lvl-(int)me->query_skill("medicine", 1)*2);
                                 message_vision("$N双眼紧闭运功疗毒，借助"HIY"九天回转丹"NOR"的奇效，漫漫脸上的" + poi["con"] + "逐渐减退。\n",me);
                                tell_object(me,"你所中" + poi["name"] + "已经漫漫消退。\n");
                                me->add("neili",-neili_cost);
                                me->start_busy(2);
                                me->set_temp("mr/9dan",1);
                                me->apply_condition("medicine",5 + random(5));
                                call_out("dest",0,this_object());
                                break;
                        }
                }
        }

        if (me->query_temp("mr/9dan")<1)
                return notify_fail("你没有中毒。\n");
        me->delete_temp("mr/9dan");
        me->delete_temp("mr/get_9dan");
        return 1;
}

void dest(object ob)
{ 
        destruct(ob);
        return;
}
