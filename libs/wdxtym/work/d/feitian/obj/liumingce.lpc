// 留名册
// diabio 2001/3/5

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"留名册"NOR, ({ "ce zi"}));    
	set_weight(200);       
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 500);
                        set("no_get",1);
		set("long","这是神古活心流历代弟子的留名册。(read)\n");
		set("material", "paper");
	  }
}
void init()
{
        add_action("do_look", "read");
        add_action("do_write","write");
}    
int do_look(string arg)
{
        object me = this_player();
        if(arg=="huaming ce"||me->query("family/family_name")=="飞天御剑流")
        {
        	if(me->query("write_name"))
        	{
        		tell_object(me,"这是一本神古活心流的留名册，记录了活心流的弟子，在末行上正写着你的名字----"HIR+me->name()+NOR"。\n");
        	         return 1;
        	}
        	else 
        	{
        		tell_object(me,"这是一本神古活心流的留名册，记录了活心流的弟子，\n上面居然还没有你的名字，看来只有自己添上了(write)。\n");        
                         return 1;
                 }        
        }
        return 1;
}        
int do_write()
{
	object me=this_player();
	if(me->query("write_name"))
        return notify_fail("飞天御剑流留名册上已经有你的名字了。\n");
        if(me->query("family/family_name")!="飞天御剑流")
	return notify_fail("哪里来的小混蛋，活心流留名册是你胡乱写的吗?\n");
	tell_object(me,"你小心翼翼的拿起笔，在册上留下了你的名字。\n");
	set("write_name",me->query("id"));
	me->set("write_name",1);
	return 1;
}	