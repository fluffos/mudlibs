// zhenwu-jian.c 真武剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE1;
void create()
{
      set_name(HIB"玄铁重剑"NOR,({ "xuantie jian", "xuantie", "sword", "jian" }) );
        set_weight(150000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long","此剑黑黝黝的毫无异状，却是沉重之极。两边剑锋都是钝口，剑尖更圆圆的似是个半球。\n");
                set("value", 100000);
                set("material", "blacksteel");
                set("weapon_prop/unarmed", -2);
                set("weapon_prop/parry", 3);
                set("unique", 1);
                set("rigidity", 300);
                set("replica_ob","/d/city/npc/obj/changjian");
                set("no_put",1);
                set("no_steal",1);    
                set("wield_neili", 1000);
                set("wield_maxneili", 2000);
                set("wield_str", 32);        
     set("wield_msg", HIY "$N举起$n，但见日月无光，沉雷郁郁，似乎要将一切生机压毁。\n" NOR);
                set("unwield_msg", HIY "玄铁乍收，生机徒现。\n" NOR);
                set("unequip_msg", HIY "玄铁乍收，生机徒现。\n" NOR);
        }
        init_sword(1000,2);
        setup();
}       

