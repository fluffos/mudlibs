inherit NPC;
void create()
{
   set_name("霍阿伊",({"huo ayi"}));
   set("gender","男性");
   set("long","木卓伦的儿子,在回族中很高的威望!\n");
   set("mingwang",160000);
   set("combat_exp",400000);
   set("area_name","回族牧群");
   
set("age",29);
   set("kee",1000);
   set("max_kee",1000);
set("food",250);
set("water",250);
   set("force",500);
   set("max_force",500);
   set("force_factor",30);

   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("whip",80);
   set_skill("sword",80);
   set_skill("club",120);

   setup();
   add_money("silver",30);
carry_object(__DIR__"obj/tiejia")->wear();
carry_object(__DIR__"obj/tieqiang")->wield();
}
