// zimuzhen.c
#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("子母飞针", ({"zimuzhen", "zhen" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "这是一根细若柔丝的银针。\n");
		set("unit", "些");
                set("base_value", 1);
		set("material", "steel");
                set("base_unit", "根");
		set("base_weight", 10); 
	}	
        set_amount(50);
        init_throwing(300);
        setup();
}

void init()
{
        add_action("do_wield", "wield");
	add_action("do_unwield", "unwield");
}
// 30
int do_wield(string arg)

{  object victim; int damage_bonus; int factor;
       object me=this_player();

        object ob;
        string str;
	int i, count;

// 40
        if (!id(arg))   return notify_fail("你要装备什么？\n");


	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备著了。\n");

// 50
	if( ob->wield() ) {
              if( !stringp(str = ob->query("wield_msg")) )
			str = "$N装备$n作武器。\n";
              message_vision(str, me, ob);me->set_temp("marks/子母针",1);
 
//	}

              return 1;
	}

        else
                return 0;
}
int do_unwield(string arg)

{  object victim; int damage_bonus; int factor;
       object me=this_player();

        object ob;
        string str;
	int i, count;

// 40
        if (!id(arg))   return notify_fail("你要放下什么？\n");


	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经放下了。\n");

// 50
	if( ob->unwield() ) {
              if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N放下手中的$n。\n";
              message_vision(str, me, ob);me->delete_temp("marks/子母针");

//	}

              return 1;
	}

        else
                return 0;
}
