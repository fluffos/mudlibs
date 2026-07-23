// tieyan-ling.c 明教铁焰令
// by snowman@SJ 18/02/2000

#include <weapon.h>
#include <ansi.h>

inherit F_BLADE;
inherit COMBINED_ITEM;
inherit F_UNIQUE;
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
       set_name( RED"铁焰令"NOR, ({ "tieyan ling", "ling", "tieyan" }) );
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "块");
               set("base_unit", "块");
               set("base_weight", 1000);
               set("long", "这是用于通行明教的铁铸令牌。牌上用
金丝镶嵌着一个红色火焰之形。令牌边
缘锋利，好象可以斩(zhan)东西。\n");
               set("value", 100);
               set("base_damage", 30);
               set("material", "iron");
               set("rigidity", 1);
               set("base_rigidity", 1);
               set("unique", 8);            
       }
       set_amount(1);
       init_blade(40);
       setup();
}

int wield() 
{
        object me = environment();

        if (!living(me)){
                message_vision("$N拿出"+name()+"看看了，却搞不懂怎么使用这个东西。\n", me);
                return 0;
        }           
        if( query_amount() > 2 ){
                message_vision("$N拿出"+name()+"看看了，却搞不懂怎么同时使用它。\n", me);
                return 0;
        }    
        if (query_amount() > 1){
                if (me->query_skill("shenghuo-lingfa", 1) < 130 || me->query_int() < 32){
                	message_vision("$N拿出"+name()+"看看了，却搞不懂怎么用它。\n", me);
                	return 0;
                }
        }
	if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}
