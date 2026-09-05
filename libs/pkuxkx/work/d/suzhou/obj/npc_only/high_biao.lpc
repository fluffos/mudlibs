#include <ansi.h>
inherit __DIR__"npc_item";
#include "/d/suzhou/obj/npc_only/throwing.h"
void create()
{
	set_name("仿制孔雀翎", ({ "kongque ling", "ling"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "筒");
		set("long", "这是一筒仿制的孔雀翎<NPC专用>。\n");
		set("value", 150000);
		set("material", "iron");
		set("throw_type","qi");
		set("high_biao",1);
		set("effect",10000);
		set("anti_job",({"jobs/completed/huyidao"}));
	}
	setup();
}

