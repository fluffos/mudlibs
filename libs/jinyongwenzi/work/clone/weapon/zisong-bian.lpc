// zisong-bian.c 紫松鞭
// Created by Numa@Sj 1999-11-23

#include <weapon.h>
#include <ansi.h>

inherit WHIP;
inherit F_UNIQUE;

void create()
{
        set_name(MAG"紫松鞭"NOR,({ "zisong bian", "whip","bian" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 1);
                set("unique", 1);
                set("rigidity", 3);
                set("material", "wood");
                set("weapon_prop/dodge", 5);
                set("treasure",1);
                set("wield_neili", 400);
                set("wield_maxneili", 1000);
                set("wield_str", 25);
                set("long", "这是一条由嵩山特产的紫竹做成的鞭子，轻盈小巧，拿在手中犹若无物。\n");
                set("unwield_msg", "$N一背身，缓缓将$n盘回腰间。\n");
                set("wield_msg", "$N从腰间小心翼翼的抽出一条$n握在手中。\n");
        }
        init_whip(80);
        setup();
}

