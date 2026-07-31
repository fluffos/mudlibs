// 风翼 kuku@sjsh 2003.09.14
// 魔族门派：大雪山、火云洞、陷空山无底洞、盘丝洞、轩辕古墓、阎罗地府  其中三界山两种风翼都可装备
// 仙族门派：方寸山三星洞、五庄观、月宫、蜀山剑派、南海普陀山、将军府、东海龙宫

#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name(HIB"骷髅翼"NOR, ({"kulou yi", "wing"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("long", "魔族使用的羽翼。\n");
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
                if( me->query("family/family_name")=="方寸山三星洞"    //仙族不能用魔族的风翼
                || me->query("family/family_name")=="五庄观"
                || me->query("family/family_name")=="月宫"
                || me->query("family/family_name")=="蜀山剑派"
                || me->query("family/family_name")=="南海普陀山"
                || me->query("family/family_name")=="将军府"
                || me->query("family/family_name")=="东海龙宫"){
                        write("你不是魔族，不能穿这件羽翼。\n");
                        return 1;
                }
        }
        return 0;
}

