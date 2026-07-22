// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("大油锅", ({"da youguo", "youguo"}));
  set_weight(6000000);
  set_max_encumbrance(100000000000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "口");
    set("long", "一口巨大的油锅，里面热油滚滚。\n"),
    set("value", 50000);
  }
  setup();
}