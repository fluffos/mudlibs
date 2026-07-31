#include <ansi.h>
  inherit "/clone/fam/gift/gift";

void create()
{
        set_name(HIY "天涯会员卡" NOR, ({ "tianya card", "card", "huiyuan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "一张精致的卡片,仅天涯会员拥有,持这张卡片"
                                  "可以自由出入\n【天涯会员服务中心】并且可以"
                                "得到相关的服务。\n" NOR);
                set("base_unit", "张");
                set("base_value", 10);
                set("base_weight", 50);
        }
        setup();
}

