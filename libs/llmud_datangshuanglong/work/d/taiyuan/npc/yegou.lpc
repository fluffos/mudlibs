inherit NPC;
void create()
{
   set_name("野狗",({ "dog","gou"}) );
   set("race","野兽");
  set("long", "这是一只野狗，看来快饿死了。\n");
   set("combat_exp", 20000);
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set_temp("apply/armor",30);
   set("chat_chance",20);
   set("chat_msg",({
   	"野狗冲着你叫道：汪，汪！\n",
   	(:random_move:),
}));
   set("verbs",({"bite"}));
   set("limbs",({"头","腿","肚子","尾巴"}));
   setup();
  
}
