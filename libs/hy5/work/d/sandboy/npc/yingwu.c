inherit NPC;
void create()
{
   set_name("鹦鹉", ({ "yingwu","bird" }) );
   set("race", "野兽");
   set("age", 5);
   set("long", "羽毛绚烂无比的鹦鹉，能模仿人说话。\n");
   
   set("str", 10);
   set("cor", 20);
   set("combat_exp",5000);

   set("limbs", ({ "头部", "身体", "左翅", "右翅", "左脚","右脚" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 5);
   set("chat_msg", ({
  "鹦鹉好奇地歪着脑袋看着你.\n",
  "鹦鹉摇晃着脑袋，作出喝醉了酒的模样。\n",
 }));
   set_temp("apply/attack", 5);
   set_temp("apply/armor", 25);

   setup();
}

void die()
{
  message_vision("$N跳了几跳，扑扇了两下翅膀，死了.\n",this_object());
  destruct(this_object());
  return;
}