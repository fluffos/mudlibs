// by snowman@SJ

#include <weapon.h>
#include <ansi.h>

inherit F_DAGGER;
inherit COMBINED_ITEM;
inherit F_UNIQUE;
inherit F_EQUIP;

void set_amount(int v)
{
        object owner = environment();
        if (v >= 0) {
                set("weapon_prop/damage", v * (int)query("base_damage"));
                if (query("equipped") && objectp(owner)) {
                        owner->set_temp("apply/damage", query("weapon_prop/damage") );
                }
        }
        ::set_amount(v);
}

void add_amount(int v) { set_amount((int)query_amount()+v); }

void create()
{
       set_name( HIB"玄铁令"NOR, ({ "tie ling", "xuantie ling", "ling" }) );
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "块");
               set("base_unit", "块");
               set("base_weight", 1000);
               set("value", 100);
       set("unique", 3);
               set("base_damage", 50);
               set("material", "starsteel");
               set("rigidity", 10);
       }
       set_amount(1);
       init_dagger(40);
       setup();
}

int wield() 
{
        object me = environment();

/*        if (userp(me) && living(me) && me->query_skill("shenghuo-lingfa", 1) < 150){
                message_vision("$N拿出"+name()+"看看了，却搞不懂怎么使用这个东西。\n", me);
                return 0;
        }           
*/
        if( query_amount() > 2 ){
                message_vision("$N拿出"+name()+"看看了，却搞不懂怎么同时使用它。\n", me);
                return 0;
        }    
        if (query_amount() > 1){
                if (me->query_skill("shenghuo-lingfa", 1) < 200 || me->query_int() < 36){
                        message_vision("$N拿出"+name()+"看看了，却搞不懂怎么用它。\n", me);
                        return 0;
                }
        }
        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}

