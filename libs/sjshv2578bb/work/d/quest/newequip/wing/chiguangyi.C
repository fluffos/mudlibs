// 风翼 kuku@sjsh 2003.09.14

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;
void create()
{
        set_name(WHT"赤光翼"NOR, ({"chiguang yi", "wing"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("long", "仙族使用的羽翼。\n");
                set("material", "leather");
                set("unit", "件");
                set("Is_Diablo_Obj",1); 
                set("value", 1000);
                set("armor_prop/armor", 1);
        }
        setup();
}

void init()
{
        add_action("do_wear","wear");      
}

int do_wear (string arg)
{
        object me = this_player();
        object ob = this_object();
  
        if(arg == ob->query("id") || arg == "wing" ){
                if( me->query("family/family_name")=="大雪山"    //魔族不能用仙族的风翼
                || me->query("family/family_name")=="火云洞"
                || me->query("family/family_name")=="陷空山无底洞"
                || me->query("family/family_name")=="盘丝洞"
                || me->query("family/family_name")=="轩辕古墓"
                || me->query("family/family_name")=="阎罗地府"){
                        write("你不是仙族，不能穿这件羽翼。\n");
                        return 1;
                }
        }
        return 0;
}

