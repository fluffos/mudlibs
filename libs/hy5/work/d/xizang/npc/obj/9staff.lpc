#include <ansi.h>
#include <weapon.h> 
inherit STAFF; 
void create()
{
        set_name("九环禅杖" , ({ "9-ring staff", "staff" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "一条又粗又长的寒铁禅杖，上面镶着九个铁环，杖中间还刻了些很不显眼的藏文。\n");
                set("value", 6200);
                set("material", "iron");
                set("wield_msg", "$N拿出一根乌黑的$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        } 
        set("skill", ([
                        "name":         "iron-cloth",             
                        "exp_required": 50000,                          
                        "sen_cost":     50,                     
                        "difficulty":   50,                     
                        "max_skill":    50              
                        ]) );
        ::init_staff(120);
}  
