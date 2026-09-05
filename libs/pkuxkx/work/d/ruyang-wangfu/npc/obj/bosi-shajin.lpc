//bosi-shajin.c -- 汝阳王府胡姬服装
//Zone: 汝阳王府
//Create by ddid
//2009-6-4

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
	set_name(GRN"波斯纱巾"NOR, ({ "bosi shajin", "shajin", "sha" }) );
  set("long", GRN"一条暗绿色的波斯纱巾。\n"NOR);
  
  set_weight(800);
  if( clonep() )
  	set_default_object(__FILE__);
  else
  {
  	set("unit", "条");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("value", 1200);
   }
   setup();
}