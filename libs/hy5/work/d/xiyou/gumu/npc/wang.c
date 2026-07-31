//轩辕古墓NPC 王贵人

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string say_key();
void punish_player(object me);
int accept_object(object me, object ob);

/************************************************************/
void create()
{
  set_name(HIW"王贵人" NOR, ({"wang guiren", "wang", "guiren"}));
    set_weight(1000000);
  set("gender", "女性" );
  set("age", 23);
   set("long", "
与妲己一同在昆仑山修炼的一只石琵琶精，道行尚浅，却禁不住人世间
五光十色、扑朔迷离滚滚尘世的诱惑，堕入魔道，终在朝歌被化做占卜
道士的太公望·姜子牙一记打神鞭送往了封神台，后与妲己一同逃脱
\n");
  set("title", HIB"玉石琵琶精" NOR);
  set("combat_exp", 10000000);
  set("attitude", "heroic");
  create_family("轩辕古墓", 1, "弟子");
  set("int", 25+random(5));
  set("cor", 30+random(10));
  set("per", 40);
  set_skill("unarmed", 220);
  set_skill("dodge", 220);
 
  set("per", 50);
  set("max_kee", 5000);
  set("max_sen", 5000);
  set("force", 6000);
  set("max_force", 3000);
  set("force_factor", 150);
  set("mana",6000);
  set("max_mana", 3000);
  set("mana_factor", 150);
  set("inquiry",([
       "name": "我就是王贵人了，你要找我？",
       "here": "这里就是轩辕古墓天阴玄石殿，想在这里撒野，哼，还轮不到你！",
       ]));
  set("chat_chance_combat", 60);
   
   set("chat_msg_combat", ({
    (: perform_action, "sword.hebi" :)
   }) );
  setup();
  carry_object("/d/obj/weapon/sword/xy_sword.c")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
}
