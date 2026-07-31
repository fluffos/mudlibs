//Cracked by Roath
// by happ@ys

#include <ansi.h>

inherit NPC;
//inherit NPC;
inherit F_MASTER;
int send_me();
int work_me();
string expell_me(object me);
string check_book();
int zhua_gui();
string ask_cancel();
string obstacle_sc();

void create()
{
       set_name("阎罗王", ({"yanluo wang","wang", "master", "yanluo"}));
       set("long", "身穿大红蟒袍，头戴黑绸软巾．
面如锅底，须若钢针，这就是阎罗王．\n");
       set("title", "阴间十王之");
        set("class", "youling");
       set("gender", "男性");
       set("age", 50);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
       set("max_kee", 1100);
       set("max_gin", 1100);
       set("max_sen", 1100);
       set("force", 1150);
       set("max_force", 1000);
       set("force_factor", 60);
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 50);
       set("combat_exp", 1000000);

      




create_family("阎罗地府", 2, "你好");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}
