#include <ansi.h>
inherit __DIR__"npc_item";
#include "/d/suzhou/obj/npc_only/throwing.h"
void create()
{
	set_name("仿制漫天花雨", ({ "mantian huayu", "yu"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "簇");
		set("long", "这是一簇仿制的漫天花雨<NPC专用>。\n");
		set("value", 30000);
		set("material", "iron");
		set("throw_type","qi");
		set("effect",2000);
		set("anti_job",({"jobs/completed/huyidao"}));
	}
	setup();
}

