inherit NPC;

void create()
{
   set_name("绵羊", ({ "sheep","yang" }) );
   set("race", "野兽");
   set("age", 22);
   set("long", "白色的羊毛卷曲,温柔的眼波,千万不要被外表迷糊。\n");
   
   set("str", 13);
   set("cor", 24);
   set("combat_exp",5000);
   set("kee",600);
   set("max_kee",600);

   set("limbs", ({ "头部", "身体", "尾巴", "前蹄","后蹄" "羊角"}) );
   set("verbs", ({ "bite", "claw" }) );

   set_temp("apply/attack", 15);
   set_temp("apply/armor", 20);
   
   set("chat_chance",5);
   set("chat_msg",({
     "绵羊吃了一会草,抬头呆呆的看着头顶飘过的白云.\n",
     "绵羊摆摆蹄子,动动腿,低头向你撞来.\n",
     }));

   setup();
}

void die()
{
     object corpse;
         if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
  message_vision("$N侧身倒下,四肢抽搐一阵,死了.\n",this_object());
  new(__DIR__"obj/yangrou.c")->move(environment(this_object()));
  destruct(this_object());
  return;
}