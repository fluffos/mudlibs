#include <ansi.h>

inherit ITEM;
inherit DISGUISE_TOOLS;
//普通易容包最多可以使用6次，包括使用工具包进行的任何操作，
//化妆是指通过化妆随机调整后天容貌值，普通易容包可以提供-9到
//+9范围内的容貌调整。
//临摹和伪装是成对出现的，要伪装前必须先临摹对方的形象，一次
//临摹只能支持一次伪装，普通易容包只能临摹NPC。
//卸妆包括清除伪装的痕迹和化妆的痕迹。
void create()
{
        set_name( HIC"普通易容工具包"NOR, ({ "general tools", "tools" }) );
        set("long", @LONG
一个普普通通的羊皮包，装着一些常见的化妆用工具和模仿人物用
工具，你可以使用该工具包进行包括化妆（dress）、临摹（paint）、
伪装（disguise）、卸妆（clear）在内的一系列常用化妆操作，并且
可以用它帮助其他玩家进行易容。
LONG);

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "只");
                set("material", "cotton");
                set("value", 60000);
                set("no_store",1);
                set("no_put",1);
                set("no_drop",1);
                set("used_times",0);
//min_level和max_level两个属性指的是伪装复杂度限定，关联是否可以佩戴面具以及是否可以提升技能等级。
                set("min_level", 250);
                set("max_level", 400);
//add_level表示佩戴面具以后获得的伪装复杂度增益，提供除技能等级以外的伪装复杂度
                set("add_level", 50);
//max_complex表示该伪装工具能够提供的最高伪装复杂度
                set("max_complex", 500);
//dress_effect表示化妆的容貌改变范围，11表示浮动范围是-9到9（-19/2到19/2）                
                set("dress_effect", 19);
//只要disguise技能大于等于200级就可以进行化妆                
                set("dress_level", 200);
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

int do_dress(string arg)
{
	object owner, target;
	int rand_per, pre_per;
	
	owner=this_player();
  if ( arg &&
  	   !objectp(target=present(arg,environment(owner))) ) 
  {
  	write("你想卸妆的对象并不存在。\n");
  	return 1;
  }
  
  if (!target)
   	dress_me(owner);
  else
    dress_target(owner, target);

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

int do_disguise(string arg)
{
	object me, ob;
	
	me=this_player();
  if ( arg &&
  	   !objectp(ob=present(arg,environment(me))) ) 
  {
  	write("你想伪装的对象并不存在。\n");
  	return 1;
  }
  
  if ( ob )
  	disguise_target(me, ob, "copy2", 0);
  else
 	  disguise_me(me, "copy2");
  
  return 1;
}

int do_clear(string arg)
{
	object me, ob;
	
	me=this_player();
  if ( arg &&
  	   !objectp(ob=present(arg,environment(me))) ) 
  {
  	write("你想卸妆的对象并不存在。\n");
  	return 1;
  }
  
	clean_face(me, "copy2", ob);
  return 1;
}