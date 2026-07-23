//gold-falun.c 金法轮
//by iceland
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"金法轮"NOR,({ "jin falun","gold falun" ,"lun" ,"falun","jinfalun" }));
        set_weight(25000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long","这是一柄黄金铸造的法轮，约有尺半大小，上面铸有密宗伏魔真言，内藏九个小球，是高僧作法事用的一种法器。\n");
                set("value", 3000);
                set("unique", 1);
                set("rigidity", 8);
                set("sharpness", 5);
                set("treasure",1);  
                set("weapon_prop/dodge", -8);
                set("weapon_prop/parry", 10);     
                set("material", "gold");
                set("wield_neili", 500);
                set("wield_maxneili", 1500);
                set("wield_str", 35);
                set("wield_msg", "$N从怀中掏出一柄$n掂了掂分量，握在手中，当啷啷响声良久。\n");
                set("unwield_msg","$N将手中的$n揣回怀中。\n");
        }
        init_hammer(100);
        setup();
}

void init()
{
    add_action("do_add",({"zuhe", "组合"}));
}

int do_add()
{
     object me,ob,ob2,ob3,ob4,ob5,falun;
     me = this_player();
     if ((int)me->query_skill("longxiang-boruo",1) <150 )
           return notify_fail("你的龙象般若功第九层修为尚未融会贯通，无法组合法轮。\n");
     ob = this_object();
     ob2 = present("silver falun", me);
     ob3 = present("bronze falun", me);
     ob4 = present("iron falun", me);
     ob5 = present("leaden falun", me);
     if( !objectp(ob2) || !objectp(ob3)
      || !objectp(ob4) || !objectp(ob5))
           return notify_fail("你手中的法轮不足以组合成风火轮。\n");
     falun = unew(BINGQI_D("bestfalun"));
     if(!clonep(falun)) return notify_fail("你突然发现手中的法轮卡住了，看来不能组合了。\n");
     message_vision(HIY"金、银、铜、铁、铅五只法轮烁然生光，互相吸引，咔咔几声合在一起，组成一只更庞大的法轮。\n"NOR, me);
     destruct(ob2);
     destruct(ob3);
     destruct(ob4);
     destruct(ob5);   
     falun->move(me);
     destruct(ob);
     return 1;
}
