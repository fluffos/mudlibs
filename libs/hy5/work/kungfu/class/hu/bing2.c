// created by snowcat on 12/9/1997

inherit NPC;
#include "/d/migong/romnpc2.c"
string *names = ({
  "兵丁",
  "十夫长",
  "百夫长",
  "小旗",
  "总旗",
});

string *names2 = ({
  "马鹞军",
  "侍卫军",
  "近卫军",
  "宫帐军",
  "部族军",
});

void create()
{
  int i = random(4)+8;
  set_name(names[random(sizeof(names))], ({"liao bing", "liaobing"}));
  set("gender", "男性");
  set("age", 20);
  set("combat_exp", 50000*i);
  set("per", 10);
  set("nickname",names2[random(sizeof(names2))]);
  set_skill("parry", 20*i);
  set_skill("unarmed", 20*i);
  set_skill("dodge", 40*i);
  set_skill("blade", 20*i);
  set_skill("staff", 20*i);
  set_skill("club", 20*i);
  set_skill("spear", 20*i);
  set_skill("sword", 20*i);
  set_skill("whip", 20*i);
  set_skill("axe", 20*i);
  set_skill("hammer", 20*i);
  set_skill("staff", 20*i);
  set_skill("staff", 20*i);
  set_skill("staff", 20*i);
  set_skill("dagger", 20*i);
  set("max_jing",200*i);
  set("max_qi",200*i);
  set("max_jing",200*i);
  set("neili",200*i);
  set("max_neili",200*i);
  set("max_neili",200*i);
  set("force_factor",10*i);
  setup();
  initlvl((200+random(200)),random(63));

  carry_object("/d/qujing/dudi/obj/cloth")->wear();
  carry_object("/d/qujing/dudi/obj/fork")->wield();
}
void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}


void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}