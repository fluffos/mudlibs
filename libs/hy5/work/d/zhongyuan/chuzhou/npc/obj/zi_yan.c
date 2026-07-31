// 淄砚 /d/city/chuzhou/npc/obj/zi_yan.c

inherit ITEM;

void create()
{
    set_name("淄砚", ({"zi yan", "yan"}));
    set_weight(5000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", @LONG
淄砚是山东淄博的名产，和端砚齐名。本朝名臣司马光就因为编撰《资治通鉴》
而得到了先帝神宗皇帝奖励的上品淄砚。
LONG
        );
        set("unit", "块");
        set("value", 5300);
    }
}
