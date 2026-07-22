#include <armor.h>
inherit WAIST;

/*  其他：
HEAD    头盔、头巾
NECK    项圈、围巾
ARMOR   盔甲
SURCOAT 外套
WAIST   护腰
WRISTS  护腕
SHIELD  盾
FINGER  指套
HANDS   手套
BOOTS   鞋子
*/

void create()
{
        set_name("腰带", ({ "my waist","waist" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一件用蚕丝织成的腰带，手工精细，针针体现着老裁缝高超的手艺。\n");
                set("unit", "条");
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("make",1);
                set("no_get",1);
//                set("no_drop",1);
                set("no_put",1);
        }
        setup();
        
}
string query_autoload()
{
        return query("name");
}
void autoload(string param)
{
        if (!param || !stringp(param))
        return;
        set("name",param);
}
void owner_is_killed() { destruct(this_object()); }

