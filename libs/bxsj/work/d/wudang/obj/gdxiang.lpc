// box.c 功德箱

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED "功德箱" NOR, ({ "gongde xiang", "xiang", "box" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", "这是一个小庙里常见的功德箱，专门用来接受善男信女们的捐款。\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

int is_container() { return 1; }

void init()
{
	add_action("do_put", "put");
        add_action("do_ketou", "ketou");
}

int do_ketou(string arg)
{
	object me,what_ob;

	me = this_player();

	if (!arg ||( arg != "gongde xiang" && arg != "xiang" && arg != "box")){
		message_vision( HIY "$N磕头如小鸡啄米似地朝四周乱拜一气。周围的行人以为$N在发痒癫疯，都一脸的惊讶！\n"NOR,me);
		return 1;
	}
	message_vision( HIY "$N磕头许愿:弟子在此诚心跪拜，请太上老君保佑我今后能惩恶锄奸，替天行道。如有违愿，人神共弃！\n"NOR,me);
	what_ob = present("gold_money", me);
	if ((int)me->query("shen",1) < (int)me->query("combat_exp",1)){
		if ( !present("gold", me)){
		message_vision( RED "$N磕完头，伸手入怀想要拿些钱捐赠，却发现自己没带多少钱。手半天也拿不出来甚是尴尬！\n"NOR,me);
		return 1;
		}
		else {
			message_vision( HIY"$N磕完头，掏出一两黄金投入功德箱。\n"NOR,me);
			what_ob->add_amount(-1);
			if (me->query("shen",1) < 80000){
				me->add("shen",random(500)+200); 
				write(HIW"你做完善事,心情顿时好多了.\n"NOR);
			}
		}
	}
	return 1;
}

int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;

	me = this_player();

	if( !arg || sscanf(arg, "%s in %s", item, target)!=2 
	||  sscanf(item, "%d %s", amount, item)!=2
	||  !objectp(obj = present(item, me)) )
		return 0;

	if( obj->query("money_id") == "silver" 
 	 && obj->query_amount() >= 5 && amount >= 5 ){
	    if( me->query("begger") > 0) {
		message_vision( sprintf(HIY "$N将一%s%s放进%s。\n" NOR,
		obj->query("unit"), obj->name(), this_object()->name()),me );
		obj->set_amount(obj->query_amount() - amount);
		me->add("begger", (-1)*(amount/5));
		if( me->query("begger") < 0) me->set("begger", 0);
		this_object()->add("amount", amount);
		return 1;
 	    }
	}
	return 0;
}
