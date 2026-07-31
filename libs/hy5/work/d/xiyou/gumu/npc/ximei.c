//喜媚
//轩辕古墓

//ximei.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_for_leave();


void create()
{
              set_name(HIW"喜媚" NOR, ({"xi mei", "ximei", "mei"}));
       set("long", "
一只羽翼初满的雉鸡，尚有百年修为，妲己非常
喜爱她，将玄阴修行之术传于她后，尤好采阳补
阴，在朝歌鹿台之上纣王大宴妲己所邀众妖仙之
时不胜酒力，显露原形毙于太师闻仲的金鞭之下
后于封神台被妲己和王贵人所救\n");
       set("title", HIB"雉鸡精" NOR);
       set("gender", "女性");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("per", 40);
        set("int", 40);
       set("max_kee", 900);
       set("max_gin", 600);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 600);
       set("mana", 600);
       set("mana_factor", 40);
       set("combat_exp", 400000);
  set("daoxing", 800000);


        set("eff_dx", 200000);
        set("nkgain", 350);

    

create_family("轩辕古墓", 2, "弟子");
setup();


}

