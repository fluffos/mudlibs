inherit NPC;
void create()
{
  set_name("书生",({ "shu sheng","shu","sheng"}) );
        set("gender", "男性" );
        set("age", 25);
   set("long", "这是一个苦读诗书的书生。\n");
   set("combat_exp",3000+random(3000));
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   set("chat_chance",20);
   set("chat_msg",({
    "书生叹道：如今时世混乱，我怎么会有出头之日呢！\n",
    "书生看看四周：看，如今的长沙都成这个样子了！\n",
    "书生叹道：我空有一肚子学问，却没地方用啊。\n",
    "书生摇摇头，继续看自己手里的书。\n",
    }));
  setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
