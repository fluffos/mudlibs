#include <ansi.h>
inherit ITEM;


void create()
{
        set_name(HIC"【江湖】"+HIY"会员卡" NOR, ({ "huiyuan card", "card", "huiyuan"}));     
        set_weight(10); 
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "一张精致的卡片,仅江湖会员拥有,持这张卡片"
                                  "可以自由出入\n【江湖会员服务中心】并且可以"
                                "得到相关的服务。\n" NOR);
                set("unit", "张");
                set("value", 10);
                set("no_drop",1);
                set("no_get",1);
                set("no_put",1);
                set("no_give",1);              
                        }
        setup();
}
void owner_is_killed() { destruct(this_object()); }

