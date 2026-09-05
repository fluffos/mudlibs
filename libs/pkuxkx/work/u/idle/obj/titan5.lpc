#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
        set_name(BLK +"战争枷锁"+ NOR, ({ "thuwan" }));
        set("long","Ｓｈａｃｋｌｅｓ︿Ｏｆ︿Ｗａｒ\n");
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit","个");
                set("no_get", 1);
                set("no_drop", "这东西不能扔。\n");
                set("no_steal", 1);
                set("value",1000000);
                set("material", "cloth");
                set("armor_prop/armor", 100);
        }
        setup();
}  

void init()
{
        if (environment()->query("name")!="泰坦")
        {
                message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
                message_vision(query("name")+"从$N的身上掉了下来，在地上滚了滚，不见了。\n",this_player());
                destruct(this_object());
                return;
        }
}
