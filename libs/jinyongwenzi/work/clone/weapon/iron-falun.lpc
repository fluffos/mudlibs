//iron-falun 铁法轮
#include <ansi.h>
#include <weapon.h>
inherit F_HAMMER;
inherit F_EQUIP;
inherit COMBINED_ITEM;
inherit F_UNIQUE;

void set_amount(int count)
{
    unequip();
 set("weapon_prop/damage", 25*count);
    ::set_amount(count);
}

void create()
{
        set_name( BLU"铁法轮"NOR,({ "iron falun" ,"lun" ,"falun","tie falun","tiefalun" }));
        set_weight(25000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "只");
                set("long","这是一只铁制法轮，约有尺半大小，上面铸有密宗伏魔真言，内藏九个小球，是僧人们作法事用的一种法器。\n");
                set("value", 100);
                set("rigidity", 1);
                set("weapon_prop/dodge", -6);
                set("weapon_prop/parry", 2);    
                set("material", "iron");
                set("base_unit", "只");
                set("base_weight", 18000);
                set("wield_msg", "$N从怀中掏出$n掂了掂分量，握在手中，当啷啷响声良久。\n");
                set("unwield_msg","$N将手中的$n揣回怀中。\n");
        }    
        set_amount(1);           
        init_hammer(40);
        setup();
}
int wield()
{
        object ob = environment();

	if (!userp(ob)) return ::wield();
        if (living(ob) && query_amount() >= 6 &&
             ob->query_str() < 60){
                message_vision("$N掏出"+name()+"试了试分量，太沉了，根本无法在战斗中自如运用。\n", ob);
                return 0;
                }

        if (living(ob) && query_amount() == 2 &&
            (ob->query_skill("xiangfu-lun", 1) < 50 ||
             ob->query_str() < 32)){
                message_vision("$N掏出"+name()+"试了试分量，太沉了，根本无法在战斗中自如运用。\n", ob);
                return 0;
                }
        if (living(ob) && query_amount() == 3 &&
            (ob->query_skill("xiangfu-lun", 1) < 100 ||
             ob->query_str() < 37)){
                message_vision("$N掏出"+name()+"试了试分量，太沉了，根本无法在战斗中自如运用。\n", ob);
                return 0;
                }

        if (living(ob) && query_amount() == 4 &&
            (ob->query_skill("xiangfu-lun", 1) < 150 ||
             ob->query_str() < 42)){
                message_vision("$N掏出"+name()+"试了试分量，太沉了，根本无法在战斗中自如运用。\n", ob);
                return 0;
                }

        if (living(ob) && query_amount() == 5 &&
            (ob->query_skill("xiangfu-lun", 1) < 200 ||
             ob->query_str() < 47)){
                message_vision("$N掏出"+name()+"试了试分量，太沉了，根本无法在战斗中自如运用。\n", ob);
                return 0;
                }

        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}

