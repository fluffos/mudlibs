#include <weapon.h>
#include <ansi.h>
inherit SWORD;
object ob;
void create()
{
seteuid(getuid());
	set_name("天王麦克风", ({"wwmac"}));
set_weight(50);
if ( clonep ())
	set_default_object(__FILE__);
	else
{
	set("unit", "只");
	set("value", 1);
	set("material", "gold");
	set("long", "这是小花了三天从天王手中要来的\n");
	this_player()->set_skill("literate", 1000);
	this_player()->set("max_jing", 2000);
}
init_sword(200);
setup();
}
