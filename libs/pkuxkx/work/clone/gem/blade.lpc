// standard s_weapon object
// blade
// by Kiden@pkuxkx
// all comments added by Vast

/*                                                             镶嵌后可能改变的属性
1.类型 skill_type  、blade
2.name、id                                                       name
3.base_weight                                                    O
4.描述 long                                                      O
5.material
6.rigidity
7.value                                                          O
8.wield_msg、unwield_msg                                         O
9.weapon_prop/damage                                             O
10.weapon_prop/attack、weapon_prop/strength                      O
11.

*/

inherit S_WEAPON;

#include <ansi.h>
#include "blade.h"

varargs void gen_blade(int min, int max);

void create()
{
        //只能在专门的地方进行买卖
        set("no_store",1);
        set("no_sell",1);
        set("no_pawn",1);
        gen_blade();
        setup();
}

//先确定武器基本种类、属性，再生成武器的gem类公有属性
varargs void gen_blade(int min, int max)
{
        //剑的基本类型 相当于diablo中的灰色物品
        //青铜剑、铸铁剑、精钢剑、玉箫、薄刃、宽刃剑、双手剑、玄铁剑
        int i, type;
        object blade;

        if(query("type"))
        {
//              set_weight(query("base_weight"));
//              delete("weapon_prop/damage");
//              init_sockets();
                return;
        }

        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 1900) type = 1;         //(19%)
        else if (i < 3600) type = 2;    //(17%)
        else if (i < 5100) type = 3;    //(15%)
        else if (i < 6500) type = 4;    //(14%)
        else if (i < 7700) type = 5;    //(12%)
        else if (i < 8700) type = 6;    //(10%)
        else if (i < 9500) type = 7;    //双手剑(8%)
        else type = 8;  //玄铁剑(5%)

        set("type", type);

        //if(!stringp(query("name")))
        set_name(blade_name[type - 1], blade_id[type - 1] );
        set("weapon_id", parse_command_id_list());
        //if(!query_weight())
        set("base_weight", blade_weight[2*(type - 1)] + random(blade_weight[2*type - 1]));
        //if(!stringp(query("long")))
        set("base_long", blade_long[type - 1]);
        set("material", blade_material[type - 1]);
        set("rigidity", blade_rigidity[2*(type - 1)] + random(blade_rigidity[2*type - 1]));
        set("value", blade_value[type - 1]);
        //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
        //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        set("weapon/min_dam", blade_damage[2*(type - 1)]);
        set("weapon/max_dam", blade_damage[2*type - 1]);

        set("unit", "柄");

        if(type == 7) set("thand", 1); //双手剑

//      delete("weapon_prop/damage");
        init_sockets();
}

