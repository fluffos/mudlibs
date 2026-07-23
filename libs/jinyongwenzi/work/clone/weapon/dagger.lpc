// tie-ling.c 铁令
// by snowman@SJ 18/02/2000

#include <weapon.h>
#include <ansi.h>

inherit F_DAGGER;
inherit COMBINED_ITEM;
inherit F_EQUIP;

void set_amount(int v)
{
        object owner = environment();
        if (v >= 0) {
                set("weapon_prop/damage", v * (int)query("base_damage"));
                set("rigidity", v * query("base_rigidity"));
                if (query("equipped") && objectp(owner)) {
                        owner->set_temp("apply/damage", query("weapon_prop/damage") );
                }
        }
        ::set_amount(v);
}

void add_amount(int v) { set_amount((int)query_amount()+v); }

void create()
{
        set_name("暗杀匕首", ({ "ansha bishou","bishou", "dagger" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("base_unit", "柄");
                set("base_weight", 500);
                set("long", "这是一柄两尺来长的暗杀匕首。\n");
                set("value", 1000);
                set("material", "steel"); 
                set("base_damage", 20);
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        set_amount(1);
        init_dagger(20);
        setup();
}

int wield() 
{
        object me = environment();

        if (!userp(me)) return ::wield();
        
        if( query_amount() > 2 ){
                message_vision("$N拿出"+name()+"看了看，却搞不懂怎么同时使用它。\n", me);
                return 0;
        }    
        if (query_amount() > 1){
                if (me->query_skill("shenghuo-lingfa", 1) < 80 || me->query_int() < 30){
                        message_vision("$N拿出"+name()+"看了看，却搞不懂怎么用它。\n", me);
                        return 0;
                }
        }
        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}
