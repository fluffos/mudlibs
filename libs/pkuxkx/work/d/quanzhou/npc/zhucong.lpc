// zhucong.c wzfeng by 98-10-14
// Modify By River 98/10
#include <ansi.h>

inherit NPC;
void greeting(object ob);
void create()
{
	 object obj;
         set_name("朱聪", ({ "zhu cong", "zhu", "cong"}));
         set("nickname", YEL"妙手书生"NOR);
         set("title","江南七侠");
         set("long", "他是江南七侠中的妙手书生，一生嫉恶如仇，专爱打抱不平。\n");
         set("gender", "男性");
         set("attitude", "friendly");
         set("unique", 1);
         set_temp("no_return", 1);
         set("location", 1);
         set("age", 28);
         set("per",20);
         set("shen", 5000);
         set("str", 30);
         set("int", 26);
         set("con", 25);
         set("dex", 23);

         set("max_qi", 2000);
         set("qi", 2000);
         set("max_jing", 1500);
         set("jing", 1500);
         set("neili", 2500);
         set("max_neili", 2500);
         set("eff_jingli", 2000);
         set("jiali", 100);
         set("combat_exp",500000);

         set_skill("cuff", 100);
         set_skill("dodge", 100);
         set_skill("force", 100);
         set_skill("stealing", 200);
         set_skill("taizu-quan", 100);
         set_skill("lingbo-weibu", 100);
         set_skill("hunyuan-yiqi", 100);
         set_skill("parry", 100);
         map_skill("force","hunyuan-yiqi");
         map_skill("dodge","lingbo-weibu");
         map_skill("cuff","taizu-quan");
         map_skill("parry","taizu-quan");
         prepare_skill("cuff","taizu-quan"); 

         set_temp("apply/armor", 50);

         setup();
         obj= new("/clone/misc/cloth");
         obj->set("name",HIW"长衫"NOR);
         obj->move(this_object());
         obj->wear();
}




