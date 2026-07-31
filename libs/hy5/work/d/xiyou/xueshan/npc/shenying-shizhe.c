// sgzl, 99.0.15.
// 换个名字好听点的好张罗生意

inherit NPC;

int test_hispai(object ob);
void give_yaopai(object ob);
string give_map(object me);
int do_yes(string arg);

void create()
  {
   set_name("神鹰使者", ({"shenying shizhe", "shizhe", "shenying", "eagle"}));
   set("gender", "男性" );
   set("age", 34);

   set("long", "大雪山巡山总督－－神鹰使者，负责四处巡查，八方联络。\n");
   set("class", "yaomo");
   set("combat_exp", 80000);
   set("daoxing", 75000);

   set("attitude", "heroism");
   create_family("大雪山", 3, "弟子");
   set_skill("unarmed", 60);
  
   set("max_kee", 500);
   set("max_sen", 500);
   set("force", 700);
   set("max_force", 700);
   set("mana", 700);
   set("max_mana", 700);	
   set("force_factor", 35);
   set("mana_factor", 35);


   set("inquiry", ([
	"name" : "在下大雪山神鹰使者，有何贵干？\n",
	"here" : "管它呢！反正比不上我们大雪山。\n",

	]) );

   set("no_map", 0);

   setup();

   carry_object("/d/obj/cloth/xueshan-pao")->wear();
   carry_object("/d/obj/armor/tenjia")->wear();

}

