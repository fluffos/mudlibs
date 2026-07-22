// niu.c

#include <ansi.h>

inherit NPC;

void create()
{
     set_name("绝色美女",({"niu","nu"}));
    set("gender","女性");
set("per",30);
set("age",19);
 set("long", "她年轻貌美，身材丰满，一脸的微笑就象春天一样。\n");
                       set("combat_exp", 350000);
set("attitude", "friendly");
  set("rank_info/respect", "波霸");
	set("inquiry",([
      "name" : "我就是杀手王爷从香港挑来的，给你们提供点服务。",
"here" : "这是杀手王爷的会客室，那边有包厢，咱们去吧！",
"yuj" : "那人只知道玩 MUD，其他什么都不懂。 ",
"snowman" : " 他喜欢玩雪球，经常把我的一些东西也当着雪球玩。",
"jpei" : "很久没来了，听说没有上网的帐号。",
"bbb" : "这个家伙自称杀手,模样还过得去,就可惜...唉,有些话不便出口.",
"rumors" : "这里的巫师们都喜欢我，我可忙不过来了，得让杀手再叫几个我的姐妹来。",
"ahunter" : "他整天玩侠客行，也不来看我，我主人说要杀了他。",
"swlb" : "他是臭流氓一个，我不伺候他，他拿 AK-47 枪来威胁我。",
  "keepon" : "一个正常的大男人，在银行里工作，老贪点小钱来给我，他喜欢我波霸喜欢得很。",
"qingyun" : "他建明教很辛苦，我常给他按摩,对了，他常给我小费。",
"look" : "这个人嘛...我看他工作认真，去给他按摩，他老瞎摸。",
"dubei" : "这个人嘛...居然还嫌我不好看，但是又老对我动手动脚。",
"cool" : "COOL 什么 COOL？cool 比较酷啦。",
"lius" : "他还在考察期，不敢来我这里风流。",
"acep" : "别提他了，没结婚的小毛孩一个，就盯着我看，什么也不动。",
"fay" : "可爱的小姑娘，不过身材可比我差远了。",
	]) );
set_skill("sword",250);
set_skill("dodge",250);
set_skill("parry",250);
          setup();
	carry_object(__DIR__"obj/b-cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch(random(3)) {
		case 0:
                        say( "美女对你笑道：这位" + RANK_D->query_respect
(ob)
              + "，杀手王爷让我给你服务，先按摩好吗！\n");
            break;
		case 1:
 say("美女对" + RANK_D->query_respect(ob) + "眉目传情，说道：大爷累了吧?小女子还是大姑娘一个，难道你不想泡妞吗? \n");
            break;
		case 2:
                        say( "美女笑咪咪地说道：这位" + RANK_D->query_respect
(ob)
                                + "，不要不好意思嘛，到包厢吧！\n");
            break;
        case 3:
			break;
	}
}
