// sgzl, 99.0.15.

inherit NPC;

int test_hispai(object ob);
void give_yaopai(object ob);
string give_map(object me);
int do_yes(string arg);

void create()
  {
   set_name("黄雀侍儿", ({"huangque shier", "shier", "huangque"}));
   set("gender", "女性" );
   set("age", 22);

   set("long", "孔雀公主的贴身侍卫头领。\n");
   set("class", "yaomo");
   set("combat_exp", 35000);
   set("daoxing", 35000);

   set("attitude", "heroism");
   create_family("大雪山", 3, "弟子");
   set_skill("unarmed", 40);
 

   set("max_kee", 300);
   set("max_sen", 300);
   set("force", 300);
   set("max_force", 300);
   set("mana", 300);
   set("max_mana", 300);	
   set("force_factor", 15);
   set("mana_factor", 15);


   set("inquiry", ([
	"here" : "这就是大雪山啦！\n",
	]) );


   setup();

   carry_object("/d/obj/cloth/xueshan-pao")->wear();
   carry_object("/d/obj/armor/tenjia")->wear();

}

