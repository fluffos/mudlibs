// yaoqin.c

inherit ITEM;

void create()
{
set_name("瑶琴", ({ "yao qin" }) );
set_weight(2000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "把");
set("long", "这是一把青竹制作的瑶琴。\n");
set("value",1000);
set("material", "bamboo");
}
setup();
}

