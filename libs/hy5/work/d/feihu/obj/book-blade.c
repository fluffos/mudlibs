// bookblade
//by steel
#include "ansi.h"
//inherit ITEM;
inherit ITEM;

void create()
{
	set_name("胡家古刀法", ({ "bladebook", "shu", "book" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "卷");
		set("long",
                        "这是一卷古书，封面上画着一柄刀,下首题着个"+HIR"胡"NOR+"字\n");
		set("no_put", 1);
//		//set("value", 100000);

		set("material", "papter");
		set("skill", ([
			"name":	"blade",	
			"exp_required":	50000,				"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	
			"max_skill":	380			
                  ]) );
	}
}

