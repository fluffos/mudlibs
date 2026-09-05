#include <armor.h>

inherit SHOULDER;

void create()
{
  set_name("护肩", ({"shoulder"}));
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一副有点破烂了的护肩，又是毛又是皮的，也不知道是什么动物身上弄的。\n");
    set("material", "furs");
    set("unit", "件");
    set("value", 0);
    set("armor_prop/armor", 30);
    
        set("no_sell",1);
                                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
                                set("no_give","总管发的装备，可不能乱送人哟！\n");
                                set("no_get","想拿总管按时地方发的装备？做梦吧!\n");
  }
  setup();
}
