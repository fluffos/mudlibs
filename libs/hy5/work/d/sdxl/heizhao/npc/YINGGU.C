// yinggu.c 刘瑛姑

#include <ansi.h>

inherit NPC;
//inherit F_SKILL;
string ask_book();
string ask_yideng();
void create()
{
int i,k,a,b,c,d,e,f,temp;
        set_name("刘瑛姑", ({ "liu yinggu", "liu", "yinggu" }));
        set("gender", "女性");
        set("nickname", CYN "神算子" NOR ) ;
        set("age", 42);
        set("long",
        "但见她额头满布皱纹，面颊却如凝脂，一张脸以眼为界，上
半老，下半少，却似相差了二十多岁年纪。\n",);
	set("per",39);

d=60+random(60);
set("str",d);
set("dex",d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
	set_skill("force", 580);
        set("combat_exp", 8000000);
        set("shen_type", 1);

        set("max_neili", 200000);
        set("neili", 200000);
        set("jiali", 0);

        set_skill("force", 500);
        set_skill("kurong-changong", 500);
        set_skill("sword", 520);
        set_skill("duanjia-sword",520);
        set_skill("dodge", 550);
        set_skill("tiannan-step", 520);      //金雁功
        set_skill("unarmed", 500);
        set_skill("kongming-quan",500);     //空明拳
        set_skill("parry", 520);
        set_skill("literate",580);

        map_skill("force", "kurong-changong");
        map_skill("sword", "duanjia-sword");
        map_skill("dodge", "tiannan-step");
        map_skill("parry", "duanjia-sword");
        map_skill("unarmed","kongming-quan");

        set("inquiry", ([
                "周伯通"     : "他、他、、他在哪里！",
                "段智兴"     : "这个老和尚，枉称慈悲！\n",
                "一灯大师"   : (: ask_yideng :),
                "九章算术"   : (: ask_book :),
        ]) );
	set("book_count", 1);
	set("yideng_count", 1);
	set_temp("apply/attack", 150);
	set_temp("apply/armor", 510);
	set_temp("apply/damage", 515);
		set_temp("apply/defense",150);
        setup();
        carry_object(__DIR__"obj/black_cloth")->wear();
}

string ask_book()
{
	mapping fam; 
	object ob;

	if ( (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "大理段家") ||
		(query("book_count") < 1) ) 
		return RANK_D->query_respect(this_player()) + 
		"说什么？我实在不明白。";

	if (this_player()->query_skill("literate",1) < 100)
		return RANK_D->query_respect(this_player()) + 
		"想要这书？你还读不懂它呢。";
	add("book_count", -1);
	ob = new(__DIR__"lbook4");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到九章算术啦。\n");
	return "好吧，这本「九章算术」你拿回去好好钻研。\n";
}

string ask_yideng()
{
	mapping fam; 
	object ob;
	
	if (query("yideng_count") < 1)
		return RANK_D->query_respect(this_player()) + 
		"想说什么？找一灯大师，那可别找我。";
	add("yideng_count", -1);
	ob = new(__DIR__"obj/whiteobj");
	ob->move(this_player());
	ob = new(__DIR__"obj/yellowobj");
	ob->move(this_player());
	ob = new(__DIR__"obj/redobj");
	ob->move(this_player());
	return "你想见他？好吧，这三个囊儿给你，有缘你就去找他吧。\n";
}
