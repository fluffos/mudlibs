inherit NPC;

void create()
{
   set_name("大雁", ({ "dayan","wield goose" }) );
   set("race", "野兽");
   set("age", 6);
   set("long", "一只离群的大雁,在芦苇中独自生活。\n");
   
   set("str", 19);
   set("cor", 20);
   set("combat_exp",1000);

   set("limbs", ({ "头部", "身体", "左翅", "右翅", "左脚","右脚" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 6);
   set("chat_msg", ({
  "大雁孤独地望着天空,似乎在怀念昔日的伙伴.\n",
  "大雁抬头看着你,眼角流下两道泪水.\n",
 }));
   set_temp("apply/attack", 8);
   set_temp("apply/armor", 10);

   setup();
}
void die()
{
  message_vision("$N悲啼一声,扇起双翅,飞走了.\n",this_object());
  new(__DIR__"egg.c")->move(environment(this_object()));
  destruct(this_object());
  return;
}