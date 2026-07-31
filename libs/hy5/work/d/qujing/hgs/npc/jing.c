inherit NPC;
#include "/d/migong/romnpc2.c"
string *names = ({
  "虎精",
  "豹精",
  "狮精",
  "狼精",
});

string *ids = ({
  "hu jing",
  "bao jing",
  "shi jing",
  "lang jing",
});


void create()
{
int ii;
ii=random(sizeof(names));

set_name(names[ii], ({ids[ii], "jing", "monster"}));
set("race", "野兽");
set("age", 33);

set("long", @LONG
一只吸取日月精华而成精的猛兽。
LONG);

//set("attitude", "aggressive");
set("class", "yaomo");
set("combat_exp", (random(5)*10000+50000));
set("daoxing", (random(5)*1000+20000));
set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
set("verbs", ({ "bite"}));

set("qi", 800);
set("max_qi", 800);
set("jing", 1200);
set("max_jing", 800);
set("neili", 1000);
set("max_neili", 1000);
set("neili", 500);
set("max_mana", 500);
set("force_factor", 30);
set("mana_factor", 30);
set("str", 30);



setup();
initlvl((200+random(200)),random(62));

}

