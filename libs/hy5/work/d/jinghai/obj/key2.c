inherit ITEM;

void create()
{
      set_name("天牢钥匙", ({"tian key", "key"}));
      set_weight(100);
      if (clonep())
      set_default_object(__FILE__);
      else {
      set("unit", "把");
      set("long", "铜制的钥匙，用它可以开启天牢铁栅栏门。\n");
      }
      setup();
}

