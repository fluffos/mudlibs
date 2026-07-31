//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("浪翻云",({"star lfy","lfy","star"}));
  set("gender", "男性");
  set("title", "昂日星官");
  set("age", 41);

  set("attitude", "heroism");
  set("class", "yaomo");
  set("combat_exp", 2473945);
  set("daoxing", 2473945);
  set("qi", 1258);
  set("max_qi", 1258);
  set("jing", 2223);
  set("max_jing", 2223);
  set("neili", 5681);
  set("max_neili", 2841);
  set("mana", 8479);
  set("max_mana", 4240);
  set("force_factor", 144);
  set("mana_factor", 213);
  set("str", 30);
  set("per", 10);

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
  set("inquiry", ([
     "here" : "这里是那？你问我，我问谁去？不知道，不知！",
     "name" : "浪翻云就是大爷我，我就是浪翻云。",
     "lfy" : "浪翻云就是大爷我，我就是浪翻云。",
     "pk" : "想知道怎麽pk吗？快去买我的pk宝典吧，特价100黄金一本。",
     "star" : "对，昂日就是我的属相，利害吧？嘿嘿！",
     "昂日" : "对，昂日就是我的属相，利害吧？嘿嘿！",
]));


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
       my_weapon->set("name",HIY"血"+HIC"刀"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",YEL"腿骨"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",YEL"头骨"NOR);
}

