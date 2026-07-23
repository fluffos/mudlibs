
inherit NPC;

void create()
{
   set_name("杜伏威",({ "du fuwei","du"}) );
        set("gender", "男性" );
        set("age", 42);
   set("long", "他是江淮军的龙头老大，据说他也是。\n"+
               "寇仲和徐子陵的义父。不过他早已归顺了\n"+
               "长安的李阀。他的毒辣和凶狠可是江湖闻名的。\n");
       
   set("combat_exp",800000);
   set("str", 28);
   set("per", 20);
   set("attitude", "peaceful");
   set_skill("unarmed",270);
   set_skill("dodge",270);
   set_skill("parry",270);
   set_skill("force",270);
   set_skill("strike",270);
   set_skill("cuff",270);

   set("max_qi",3000);
   set("max_jing",3000);
   set("max_neili",3000);
   set("force",3000);
   set("bellicosity",3000);
   set("inquiry",([
     "寇仲":"那小子的刀法确实很高，我早已不是他的对手了！\n",
     "徐子陵":"子陵为人很好，不知道他现在在哪里隐居。\n",
     ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

