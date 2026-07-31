inherit ITEM;
int do_apply (string arg);
void create()
{
  set_name("金龙符", ({"jinlong fu", "jinglong", "fu"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("no_sell", 1);
    set("no_drop", 1);
    set("unit", "张");
  
  set("long", "一张黄色的纸符，上面画了尾喷云吐雾的金龙。
可用来显化(apply)咒语。\n");
    }
    setup();
}
