inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIW"通行令牌"NOR, ({"tongxing ling1"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("yuanbao", 9);
  set("no_give",1);
  set("no_drop",1);
  set("no_sell",1);
  set("no_steal",1);
		set("unit", "个");
		set("long","这是地狱家族发放的通行令牌，遇到劳德诺和空见时可以派上用场！\n");
	}
}

int query_autoload() { return 1; }