inherit NPC;
void create()
{
   set_name("瞎眼老婆婆",({"old woman","old","woman"}));
   set("age",75);
   set("shen_type",1);
   set("combat_exp",5000);
   set("gender","女性");

   set_skill("unarmed",140);
   set_skill("dodge",120);
   set_skill("parry",210);
   set_skill("literate",130);
   set_skill("force",120);

   set("chat_chance",10);
   set("chat_msg",({
     "唉,张山孩儿怎么还不回来啊.\n",
     "多亏我家媳妇贤惠,我才没跟着老头子去啊.\n",
    }));

   setup();
   carry_object("/clone/misc/cloth")->wear();
   add_money("silver",random(4));
}