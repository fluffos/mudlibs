#include <ansi.h>
inherit KZZNPC;
void create()
{
	mapping data;
	data=get_npc_data();
	set_npc_data(data,1);
        setup();
      add_money("gold",1);
      carry_object(__DIR__"obj/jiasha.c")->wear();
      carry_object(__DIR__"obj/zhuzhang.c")->wield();
}
