inherit NPC;
void create()
{
  set_name("醉汉",({ "man"}) );
        set("gender", "男性" );
        set("age", 35);
   set("long", "这是一个整天无所事事的醉汉。\n");
   set("combat_exp",3000+random(3000));
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   set("chat_chance",20);
   set("chat_msg",({
    "醉汉打了饱嗝：艳福楼的姑娘就是好，哈哈！\n",
    "醉汉笑道：我、我当年也是武林高手呢！\n",
    "醉汉一皱眉：又没有钱买酒喝了。\n",
    "醉汉朝西边大声喊道：艳福楼的姑娘，我晚上再来！\n",
    }));
  setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
