// diamond_ring.c

#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
	set_name(HIW"钻石"+HIY"戒指"NOR, ({ "diamond ring", "ring" }) );
	set("long", "这是一枚光芒四射的" + HIW"钻石" + HIY"戒指"NOR + "。\n"
                    HIW"钻石"NOR + "代表着永恒的爱情，在那个庄严的时刻，\n"
                    "上帝将容许你将这枚" + HIY"戒指"NOR + "戴在你心爱的人的无名指上。\n");
	set_weight(200);
	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("material", "diamond");
                set("armor_prop/armor", 1);
	}
	set("value", 500000);
        set("no_drop",1);
        setup();
}

void init()
{
	add_action("do_dai", "dai");
}

int wear() {return 0;}
int do_dai(string arg)
{
	object ob;

	if( !arg )
              {
              return notify_fail("你不能给自己戴结婚戒指。\n");
              }
	else {
		ob = present(arg, environment(this_player()));
		if( !ob || !userp(ob))
			return notify_fail("你要给谁戴？\n");
             }

	if( !move(ob) ) return 0;

	if( ob!=this_player() )
        	message_vision("$N把" + name() + "戴在了$n的无名指上。\n", this_player(), ob);
        ::wear();
        return 1;	
}

 void remove(string arg)
{
          ::remove(arg);
         
}

string query_autoload()
{
	if( query("equipped") ) return query("name");
}

void autoload(string arg)
{
	int i;

	set("name", arg);
	::wear();
}


