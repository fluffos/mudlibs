// letter.c 书信，超度任务往来凭证

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(YEL"书信"NOR, ({"letter"}));
  set_weight(100);
  if( clonep() )
  	set_default_object(__FILE__);
  else {
  	set("unit", "封");
    set("long","这是一封洛阳万安寺方丈写给少林寺玄慈大师的书信。\n");
    set("material", "paper");
  }
}
