//sgzl

inherit NPC;

void create()
{
set_name("偏将",({"pian jiang","jiang"}));
set("gender", "男性");
set("title", "傲来国");
set("age", 25);
set("long", "    \n一名傲来国的偏将，正在认真的站岗。\n");

set("attitude", "heroism");
set("class", "fighter");
set_level(20);
set("force_factor", 15);
set("mana_factor", 0);
set_skill("dodge",200);
set_skill("unarmed", 150);
set_skill("parry", 150);
set_skill("spear", 200);

setup();
        carry_object(0,"spear",0)->wield();
        carry_object(0,"armor",0)->wear();
        carry_object(0,"kui",0)->wear();
        carry_object(0,"cloth",0)->wear();
        carry_object(0,"pifeng",0)->wear();
        carry_object(0,"shield",0)->wear();
        carry_object(0,"shoes",0)->wear();
        carry_object(0,"hand",0)->wear();
        carry_object(0,"wrists",0)->wear();
        carry_object(0,"waist",0)->wear();

}

void unconcious ()
{
  object me = this_object();

  message_vision ("\n$N喊到：＂快来人哪！有人劫兵器库啦！＂说罢撒腿跑了出去。\n",me);
  message_vision ("\n另一个$N急急忙忙的赶来。\n",me);
  powerup(0,1);
  remove_all_killer();
  all_inventory(environment())->remove_killer(me);
}

void die ()
{
  unconcious();  
}