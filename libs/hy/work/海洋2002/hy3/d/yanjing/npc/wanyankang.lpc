inherit NPC;
void create()
{
   set_name("完颜康",({"wanyan kang"}));
   set("gender","男性");
set("title","小王爷");
   set("long","王府小王爷!\n");
set("mingwang",-4000);
   set("combat_exp",160000);
   
set("age",19);
   set("qi",780);
   set("max_qi",780);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",50);

   set_skill("dodge",60);
   set_skill("force",60);
   set_skill("parry",60);
   set_skill("unarmed",60);
   set_skill("club",60);
   set_skill("sword",60);
   set_skill("quanzhen-jian",60);
   set_skill("xiantian-qigong",60);
   set_skill("jinyan-gong",60);
   set_skill("haotian-zhang",60);
   
   map_skill("sword","quanzhen-jian");
   map_skill("force","xiantian-qigong");
   map_skill("dodge","jinyan-gong");
   
   setup();
   add_money("silver",4);
carry_object(__DIR__"obj/jinpao")->wear();
carry_object(__DIR__"obj/changjian")->wield();
}
