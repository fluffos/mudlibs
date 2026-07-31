//LUCAS 2000-6-18
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("金乌杖", ({ "jinwu-staff" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
set("treasure",1);
                set("long", "这是一根以雪山金乌精英所铸的长杖。\n");
                set("value", 5500);
                set("material", "steel");
                set("wield_msg", "$N拿起金乌杖，舞了一圈，只见漫天金光闪耀，绚人眼目。\n");
                set("unwield_msg", "$N轰地一声将金乌杖插在地上，地动山摇，威势惊人。。\n");
        }
        init_staff(400);
        setup();
}

