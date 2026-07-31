
inherit NPC;

void create()
{
   set_name("采参人",({ "man" }) );
        set("gender", "男性" );
        set("age", 42);
   set("long", "这是一个长白山采参的人。\n");
       
   set("combat_exp", 5000);
   set("str", 10);
   set("attitude", "peaceful");
   set("inquiry",([
      "人参":"你要采参吗？挖就可以了！\n",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

