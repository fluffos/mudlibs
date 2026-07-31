#include <weapon.h>
inherit BOW; 

void create()
{
        set_name("乾坤弓", ({"qiankun gong", "qiankungong", "bow", "gong", "qiankun"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
		set("long", "本是上古封神大战时陈塘关的镇关之宝，不知道怎么会在这里。\n");
                set("unit", "张");
		set("value", 30000);
                set("wield_msg", "$N抓起一张$n，握在手中当武器。\n");
                set("material", "steel");
                set("no_sell",1);
        }
        init_bow(1);
        setup();
}