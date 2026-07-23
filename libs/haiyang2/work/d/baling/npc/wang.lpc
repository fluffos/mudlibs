
inherit NPC;

void create()
{
   //reload("yy_yaodian_wang");
   set_name("王药师",({ "wang yaoshi","wang","yaoshi"}) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "这是巴陵的王药师，他这里有很多新奇的药物。\n");
    set("shop_id",({ "wang yaoshi","wang","yaoshi"}) );
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("qi",800);
   set("max_qi",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}


int regenerate()
{
        set("called", 0);
        return 1;
}
