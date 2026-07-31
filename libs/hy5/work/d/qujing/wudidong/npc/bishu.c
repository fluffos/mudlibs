// bishu.c 碧鼠精
// 9-2-97 pickle

#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc2.c"

/************************************************************/

// function and global variable declaractions

int attempt_apprentice(object me);
int recruit_apprentice(object me);
int prevent_learn(object me, string skill);
int accept_object(object me, object ob);
void bishu_leave(object me);
/************************************************************/

void create()
{
  set_name("碧鼠精", ({"bi shu", "bi", "shu", "bishu", "monster"}));
  set("gender", "女性");
  set("age", 19);
  set("long",
"虽然她看起来弱不禁风，但听说她天赋及佳，是块修仙的好料子。\n"
"自从入无底洞以来，她的武功进步及快，颇有赶过玉鼠的架式。\n");
  set("title", "无底洞大弟子");
  set("nickname", HIR"九死一生"NOR);
  set("combat_exp", 800000);
  set("combat_exp", 441500000);

  set("attitude", "heroic");
  create_family("陷空山无底洞", 2, "弟子");
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);

  
  set("cor", 50);
  set("str", 30);
  set("per", 30);
  set("max_qi", 900);
  set("max_jing", 900);
  set("neili", 650);
  set("max_neili", 650);
  set("force_factor", 20);
  set("neili", 650);
  set("max_neili", 600);
  set("mana_factor", 25);
  set("inquiry", ([
                   "name": "本姑娘就是地涌夫人的开山大弟子！",
                   "here": "你瞎了眼啦？这里就是鼎鼎大名的陷空山无底洞！",
		   "rumors": "不知道！找别人问去。",
		   "人肉包子": "你瞎了眼啦？本姑娘又不是厨子！",
                 ]) );  

  setup();
  initlvl((650+random(650)),28);  
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
}


/************************************************************/

int accept_object(object me, object ob)
{
    if (ob->query("name_recognized") != "白骨令")
	return notify_fail(CYN"碧鼠怒道：混帐，我又不是收破烂的！\n"NOR);
    remove_call_out("bishu_leave");
    call_out("bishu_leave", 1, me);
    return 1;
}
void bishu_leave(object me)
{
    command("say 这、这、这，这可怎么办是好？");
    command("sigh");
    command("say 既然夫人有令在此，我还是赶紧回去一趟吧！");
    message_vision("碧鼠精抓了一把土，向空中一抛，喝声：走！借土遁去了。\n", me);
    destruct(this_object());
    return;
}

