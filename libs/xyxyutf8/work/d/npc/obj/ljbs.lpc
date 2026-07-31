//yitianjian.c
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
//inherit F_UNIQUE;
void create()
{
     set_name(HIW"垃圾匕首"NOR, ({ "bishou" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
//                set("unique", 1);
//                set("no_drop",1)
                set("no_put",1);
//                 set("no_zm",1);
//                 set("no_give",1);
//              set("value", 0);
set("fz_get",1);
        
         set("material", "iron");
        	set("long", "上古十二神兵之一：仙剑");
       set("wield_msg","寒光冷现，$n已在$N手中，天地为之变色。\n");
                 set("unwield_msg", "$N将$n插回腰间，寒光顿敛，天地间只闻龙鸣。\n");
//            set("is_monitored",1);
	}
        init_dagger(40+random(20));
	setup();
}
void init()
{
        add_action("do_wield","wield");
}
int do_wield (string arg)
{
  object me = this_player();
  if(me->query("family/family_name")!="火系魔法教派")
{
  message_vision(HIR"明心锥"NOR+"是火系魔法教派的专用武器\n",me);
return 1;
}
}
