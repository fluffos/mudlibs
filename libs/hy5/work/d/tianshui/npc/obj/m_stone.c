// m_stone.c

inherit ITEM;

void create()
{
    set_name("磨刀石", ({ "stone"  }) );
    set("unit", "块");
    set("long","一块磨刀用的石头。\n");
    set_weight(500);
    setup();
}