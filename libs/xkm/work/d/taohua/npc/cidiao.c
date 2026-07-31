//Cracked by Roath
// yetu.c 野兔

inherit NPC;
#include <ansi.h>;

void create()
{
        set_name("雌雕", ({ "ci diao", "diao" }) );
	set("race", "家畜");
	set("age", 5);
        set("long", "桃花双雕之一。\n");
	set("attitude", "peaceful");
	
//	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
//	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 50);
//	set("shen_type", 0);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);

	setup();
}


void init()
{
       add_action("do_qi", "qi");
}

int do_qi(string arg)
{

             if( this_player()->query("family/family_name") != "桃花岛" && this_player()->query("family/master_name") != "黄药师")
                             return notify_fail("你不是黄药师的弟子，不能驾驭双雕！\n");
  message_vision(HIW"$N轻身而起，伏在雕背上。大雕长鸣一声，振翅飞向桃花岛......\n\n"NOR ,this_player() ,this_object() );
      this_player()->start_busy(10);
      this_object()->start_busy(10);
           this_player()->move("/d/taohua/bibochi");
          this_object()->move("/d/taohua/bibochi");
  message_vision(HIW"一会功夫，$N觉得脚下踏实了许多，睁眼一看，发现已经在桃花岛了。\n"NOR ,this_player() ,this_object() );
     this_player()->start_busy(3);

message_vision(HIW"双雕长嘶一声，振翅飞起，在你头上盘旋几周，飞走了。\n"NOR ,this_player() ,this_object() );
       destruct(this_object());

     return 1;
}
void die()
{
	object ob;
   message_vision(HIG"大雕吃痛，疾飞到空中，盘旋一阵，消失在天际。\n"NOR, this_object());
	destruct(this_object());
}
	
