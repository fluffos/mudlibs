inherit NPC;

void create()
{
   set_name("牦牛", ({ "mao niu","niu" }) );
   set("race", "野兽");
   set("age", 12);
   set("long", "一头发怒的公牛,两个角上微微闪着金光。\n");
   
   set("str", 25);
   set("cor", 24);
   set("combat_exp",15000);
   set("kee",400);
   set("max_kee",400);

   set("limbs", ({ "头部", "身体", "尾巴", "前蹄","后蹄" "牛角"}) );
   set("verbs", ({ "bite", "claw" }) );

   set_temp("apply/attack", 15);
   set_temp("apply/armor", 25);
   
   set("chat_chance",5);
   set("chat_msg",({
     "牦牛瞪着碗大的眼睛,仔细研究着你.\n",
     "牦牛张嘴对天叫了两声,你却没听到一点声音.\n",
     }));

   setup();
}

void die()
{
      object corpse;
         if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
  message_vision("$N怒哼一声,一头撞向山壁,不见了.\n",this_object());
  new(__DIR__"obj/niujiao.c")->move(environment(this_object()));
  destruct(this_object());
  return;
}