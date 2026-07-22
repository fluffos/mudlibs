inherit ITEM;

void create()
{
   set_name("书信", ({ "shuxin"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一封推荐信。\n");
     set("material", "白纸");
     set("unit", "封");
   }
   setup();
}
