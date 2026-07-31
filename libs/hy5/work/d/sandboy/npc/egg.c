inherit ITEM;
void create()
{
  set_name("大雁蛋", ({"egg", "danyan egg"}));
  set_weight(60);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一枚大雁蛋,说不定能孵出大雁来呢。\n");
    set("unit", "枚");
    set("value", 50);
  }
}


