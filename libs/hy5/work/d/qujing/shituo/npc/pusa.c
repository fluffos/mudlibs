//Cracked by Roath
// guanyin.c 观音菩萨
// By Dream Dec. 19, 1996
#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc2.c"


void create()
{
	set_name("观音菩萨", ({ "guanyin pusa", "guanyin", "pusa" }));
	set("title", "救苦救难大慈大悲");
	set("long", @LONG
理圆四德，智满金身。眉如小月，眼似双星。兰心欣紫竹，
蕙性爱得藤。她就是落伽山上慈悲主，潮音洞里活观音。
LONG);
	set("gender", "女性");
	set("age", 35);
	set("attitude", "peaceful");
	set("rank_info/self", "贫僧");
	set("rank_info/respect", "菩萨娘娘");
	set("class", "bonze");
                set("str",100);
                set("spi",80);
                set("cor",80);
                set("cps",80);
                set("con",80);
                set("per",40);
                set("int",40);
                set("kar",40);// Cigar@sjsh_SKxyj add the all attribute.
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("max_jing", 5000);
        set("neili", 6000);
        set("max_neili", 3000);
        set("force_factor", 250);
        set("max_mana", 4000);
        set("mana", 8000);
        set("mana_factor", 250);
	set("combat_exp", 2000000);
	set("daoxing", 10000000);

      
	set("inquiry",([
      "净瓶": "前些天，福星借我的净瓶用，到现在也没有还，你去看看吧。" ]));



	//let's use cast bighammer to protect her...weiqi:)
	create_family("南海普陀山", 1, "菩萨");

	setup();
	initlvl((3500+random(3500)),random(63));
        carry_object("/d/qujing/nanhai/obj/jiasha")->wear();
        carry_object("/d/qujing/nanhai/obj/nine-ring")->wield(); 
}


void die()
{
	int i;
	string file;
	object *inv;

        if( environment() ) {
        message("sound", "\n\n观音菩萨摇头叹道：刚离迷障，又入魔障，世间疾苦，何人度之！\n\n", environment());
        command("sigh");
        message("sound", "\n观音菩萨驾祥云，登彩雾，径往西方去了。。。\n\n", environment());


	destruct(this_object());
}
}


void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/shituo") == "done")
    return;
  if (! who->query_temp("obstacle/shituo3_killed"))
    return;
  if (! who->query_temp("obstacle/shituo2_killed"))
    return;
  if (! who->query_temp("obstacle/shituo1_killed"))
    return;

  i = random(900);
  who->add("obstacle/number",1);
  who->set("obstacle/shituo","done");
  who->add("combat_exp",i+37000);
   who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"狮驼岭狮驼洞施神威，收服 三魔王！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(i+37000)+"点经验"+
               chinese_number(i*8)+"点潜能"+" 十点门派贡献 二点成长上限！！\n");
  who->save();
}