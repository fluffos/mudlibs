inherit NPC;
void create()
{
   set_name("戏友",({ "xi you","xi","you" }) );
   set("gender", "男性" );
   set("age", 22);
   set("long", "这是一个非常喜欢看戏的戏友。\n");
   set("combat_exp", 20000);
   
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set_temp("apply/armor",30);
   set("chat_chance",20);
   set("chat_msg",({
    "戏友高声喝道：好，唱的好！！！\n",
    "戏友情不自禁地随着台上唱了起来：恩～～～～啊～～～～好，好！！\n",
    "戏友朝店小二喊道：店小二，再给我来壶茶～～～～\n",
    }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
