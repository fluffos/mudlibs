inherit NPC;
void create()
{
   set_name("穆念慈",({"mu nianci"}));
	set("gender","女性");
   set("score",25000);
   set("combat_exp",80000);
   
set("per",30);
set("age",19);
   set("qi",800);
   set("max_qi",800);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",30);

   set_skill("dodge",80);
   set_skill("force",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set_skill("club",50);
   set_skill("sword",80);
   set_skill("blade",80);
   
   set("inquiry",([
   "比武招亲":"这个...这个...问我爹爹吧.\n",
   "绣花鞋":"问这个干嘛,流氓.\n",
   ]));

   setup();
   add_money("silver",5);
carry_object(__DIR__"obj/skirt")->wear();
carry_object(__DIR__"obj/xiuhuaxie")->wear();
}
