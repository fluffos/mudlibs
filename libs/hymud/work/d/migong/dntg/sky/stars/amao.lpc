//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("七刃",({"star wxyz","wxyz","star"}));
  set("gender", "男性");
  set("title", "鬼金星官");
  set("age", 59);

  set("attitude", "heroism");
  set("class", "yaomo");
  set("combat_exp", 2197634);
  set("daoxing", 2197634);
  set("qi", 1307);
  set("max_qi", 1307);
  set("jing", 2409);
  set("max_jing", 2409);
  set("neili", 5815);
  set("max_neili", 2908);
  set("mana", 9859);
  set("max_mana", 4930);
  set("force_factor", 144);
  set("mana_factor", 247);
  set("str", 29);
  set("per", 11);


       set_skill("lamaism", 250);
        set_skill("literate", 280);
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("blade", 250);
        set_skill("sword", 220);
        set_skill("dodge", 280);
        set_skill("longxiang", 380);
        set_skill("shenkong-xing", 380);
        set_skill("hand", 280);
        set_skill("dashou-yin", 380);
        set_skill("mingwang-jian", 280);
        set_skill("xue-dao", 380);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
	}) );


setup();
carry_object("/clone/misc/cloth")->wear();
carry_object(__DIR__"obj/blade")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="blade";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"血淋淋的枯骨"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","人皮");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"头盖骨"NOR);
}

