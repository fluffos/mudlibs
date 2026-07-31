
inherit NPC;
void create()
{
   
   set_name("醉汉",({ "zui han","zui","han"}) );
   set("gender", "男性" );
   set("age",40+random(10));
   set("long", "这是一个喝的醉熏熏的醉汉。\n");
   set("combat_exp", 100000);
   set("str", 30); 
   set("chat_chance",20);
   set("chat_msg",({
     "醉汉哼道：小妹妹，去哪里？不如来哥哥家... ...\n",
     "醉汉骂道：王八羔子！整天打来打去，不如老子一醉解千仇！！\n",
     "醉汉低声道：咦？？酒呢？？又喝完了？\n",
    }));    
   setup();
    carry_object("/clone/misc/cloth")->wear();
  
  
}

string long()
{
  command("say 看什么看？？！！小心老子揍你一顿！！！");
  return query("long");
  
}
  
