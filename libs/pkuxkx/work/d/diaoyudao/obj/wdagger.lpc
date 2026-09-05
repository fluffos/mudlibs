// shortsword.c 长剑

#include <weapon.h>
inherit SWORD;

void create()
{
   set_name("韦小宝之匕首",({ "dagger"} ));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
    set("long","这是韦小宝贴身的宝贝,一把能削金断玉的匕首.这是他从螯拜的府里搜出来的.他曾用此匕首杀死过很多高手.\n");
       set("value",100000);
		set("material", "steel");
   set("wield_msg", "$N诡密地将一把$n拿在手里,别人都没有注意到.\n");
       set("unwield_msg", "$N将手中的$n偷偷放回衣袖内. \n");
	}
     init_sword(100);
	setup();
}
