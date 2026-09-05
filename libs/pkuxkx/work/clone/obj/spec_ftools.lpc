#include <ansi.h>

inherit ITEM;
inherit DISGUISE_TOOLS;
//临时道具
void create()
{
        set_name( "易容包", ({ "yirong bao", "bao" }) );
        set("long", @LONG
这是临时道具——易容包，可以易容(disguise)成为随机人物。
LONG);

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "只");
                set("material", "cotton");
                set("value", 0);
                set("no_store",1);
                set("no_put",1);
                set("no_drop",1);
                set("used_times",0);
//min_level和max_level两个属性指的是伪装复杂度限定，关联是否可以佩戴面具以及是否可以提升技能等级。
                set("max_level", 0);
//add_level表示佩戴面具以后获得的伪装复杂度增益，提供除技能等级以外的伪装复杂度
//max_complex表示该伪装工具能够提供的最高伪装复杂度
                set("max_complex", 500);
				set("add_level",500);
//dress_effect表示化妆的容貌改变范围，11表示浮动范围是-9到9（-19/2到19/2）                
                set("dress_effect", 19);
//只要disguise技能大于等于200级就可以进行化妆                
                set("dress_level", 0);
        }
        setup();
}

void init()
{
        add_action("do_disguise", "disguise");
}
int do_disguise(string arg)
{
	object me, ob;
	
	me=this_player();
	ob=new("/d/changbai/npc/killer1");
	ob->set("combat_exp",0);
	ob->set_skill("dodge",0);
	ob->move(environment(me));
	tell_object(me,DISGUISE_D->query_complex(this_object(), me)+"\n");
	paint_face(me, ob, 0);  
  	disguise_me(me, "copy4");
  destruct(ob);
  destruct(this_object());
  
  return 1;
}

