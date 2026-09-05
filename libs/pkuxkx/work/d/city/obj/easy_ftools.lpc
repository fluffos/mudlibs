#include <ansi.h>

inherit ITEM;
inherit DISGUISE_TOOLS;

//简易易容包最多可以使用6次，包括使用工具包进行的任何操作，
//化妆是指通过化妆随机调整后天容貌值，简易易容包可以提供-5到
//+5范围内的容貌调整。
//临摹和伪装是成对出现的，要伪装前必须先临摹对方的形象，一次
//临摹只能支持一次伪装，简易易容包只能临摹NPC。
//卸妆包括清除伪装的痕迹和化妆的痕迹。
void create()
{
        set_name( "简易易容工具包", ({ "simple tools", "tools" }) );
        set("long", @LONG
一个简陋的小布包，装着一些常见的化妆用工具和模仿人物用
工具，你可以使用该工具包进行包括化妆（dress）、临摹（paint）、
伪装（disguise）、卸妆（clear）在内的一系列常用化妆操作。
LONG);

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("material", "cotton");
                set("value", 30000);
                set("no_store",1);
                set("no_put",1);
                set("no_drop",1);
                set("used_times",0);
//min_level和max_level两个属性指的是伪装复杂度限定，关联是否可以佩戴面具以及是否可以提升技能等级。
                set("min_level", 100);
                set("max_level", 250);
//add_level表示佩戴面具以后获得的伪装复杂度增益，提供除技能等级以外的伪装复杂度
                set("add_level", 30);
//max_complex表示该伪装工具能够提供的最高伪装复杂度
                set("max_complex", 300);
//dress_effect表示化妆的容貌改变范围，11表示浮动范围是-5到5（-11/2到11/2）                
                set("dress_effect", 11);
        }
        setup();
}

void init()
{
        add_action("do_dress", "dress");
        add_action("do_paint", "paint");
        add_action("do_disguise", "disguise");
        add_action("do_clear", "clear");
}

int do_dress()
{
	object owner;
	
	owner=this_player();
	dress_me(owner);
  return 1;
}

int do_paint(string op)
{
	object me,ob;
	
	me=this_player();
	if ( !op || !(ob=present(op, environment(me))))
	{
		write("请确认你要临摹的对象是否存在。\n");
		return 1;
	}
	paint_face(me, ob, 0);  
  return 1;
}

int do_disguise()
{
	object me;
	
	me=this_player();
  disguise_me(me, "copy");
  
  return 1;
}

int do_clear()
{
	object me;
	
	me=this_player();
	clean_face(me, "copy");
  return 1;
}