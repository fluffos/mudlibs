inherit NPC;

void create()
{
   set_name("小黄狗", ({ "dog" }) );
   set("race", "野兽");
   set("age", 3);
   set("long", "一只毛绒绒的小狗。\n");
   
   set("str", 24);
   set("cor", 26);

   set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 6);
   set("chat_msg", ({
     (: call_other, this_object(), "random_move" :),
     "小黄狗呲着小犬牙冲你汪汪叫。\n",
     "小黄狗摇晃着尾巴，围着你转了圈。\n",
     "小黄狗绕着圈子想咬住自己的尾巴。\n",
     "小黄狗用后腿抓了抓自己的耳朵。\n", }) );
     
   set_temp("apply/attack", 10);
   set_temp("apply/armor", 3);

   setup();
}
int accept_object(object who, object ob)
{
   if( ob->id("bone") ) {
     set_leader(who);
     message("vision", name() + "高兴地汪汪叫了起来。\n", environment());
     return 1;
   }
}
