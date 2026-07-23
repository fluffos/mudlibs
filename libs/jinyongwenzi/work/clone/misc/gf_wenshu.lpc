// gf_wenshu.c
// By snowman@SJ 11/06/2000

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT "铁捕文书" NOR, ({ "tiebu wenshu", "wenshu" }));
	set("weight", 100);
	if(clonep()) set_default_object(__FILE__);
	else{
		set("unit", "张");
		set("long", WHT"这是一张巡捕房出的铁捕文书，上面有通缉犯的画像和名字。\n" NOR);
	}
	setup();
}
 
void init()
{
	add_action("do_arrest", "jubu");
}

int do_arrest(string arg)
{
	object ob, me;
	
	if (!arg)
		return notify_fail("你想拘捕谁？\n");
	
	me = this_player();
		
	if( !environment(me)->query("no_fight"))
		return notify_fail("只有在罪犯躲藏起来时，拘捕才有效。\n");

	if(!objectp(ob = present(arg, environment(me))) )
		return notify_fail("你要拘捕谁？\n");
		
	if(!ob->is_character() )
		return notify_fail("你要拘捕什么？\n");
		
	if( ob->query("id") != query("target/id") )
		return notify_fail("铁捕文书上记的不是这人吧？\n");
		
	message_vision("\n$N对着$n大吼一声：“被我逮到了！快快束手就擒吧！”\n", me, ob);
	me->kill_ob(ob);
	ob->fight_ob(me);
	
	return 1;
}
