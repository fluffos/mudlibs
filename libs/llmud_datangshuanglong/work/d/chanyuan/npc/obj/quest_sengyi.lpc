
#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("僧衣", ({ "seng yi","cloth","yi"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("unit", "件");
     set("value", 40);
     set("armor_prop/armor", 10);
   }
   setup();
}

int is_get_of(object ob,object obj)
{
  if(ob->query("id")!=obj->query("owner_id"))
  return notify_fail("这个东西你捡不起来。");
  return 1;
}