//  /d/diaoyudao/obj/qigan.c  旗杆
//  hongdou 98.10.07

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("旗杆", ({ "qi gan","qigan","gan"}) );
        set_weight(80000); 
		set_max_encumbrance(80000);
        set("no_get", 1);
	set("no_give",1);
	set("no_drop",1);
	set("no_steal",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_shown",1);
                set("prep", "under");
                set("unit", "根");
                set("long", "这是一根立在中军大帐门前的旗杆，上面飘扬着一面旗子，上写：\n"
+HIY+"         大清国抚远大将军"+NOR+"   "+HIR+"韦"+NOR+"，\n    虽然破旧，但仍显得气势威严。\n");
        }
}

