//Cracked by Roath
// Rewrote by iszt@pkuxkx, 2007-02-11

#include <ansi.h>

inherit NPC_TRAINEE;
void set_kind(int);

void create()
{
	set("race", "蛇类");
	set("age", 4);
	set("attitude", "peaceful");

	set("msg_fail", "$n冲$N嘶地一吐舌头");
	set("msg_succ", "$n嘶嘶做响，蛇头随着$N的手动了起来");
	set("msg_trained","$n悄无声息地游到$N的脚下不动了");
	set("wildness", 9);
	set("neili", 3000);
	set("max_neili",3000);
	set("jiali", 100);	

	set_skill("unarmed", 1000);
	set_skill("parry", 1000);
	set_skill("dodge", 1000);
	set_skill("force", 1000);
	set_skill("dushe-neigong", 1000);
	set_skill("sheyao", 1000);
	map_skill("force", "dushe-neigong");
	map_skill("unarmed", "sheyao");
	map_skill("parry", "sheyao");
	prepare_skill("unarmed", "sheyao");

	set("combat_exp", 1000000);

	set_temp("apply/attack", 25);
	set_temp("apply/damage", 16);
	set_temp("apply/armor", 20);
	set_kind(random(8));
	set("shen_type",-1);
set("score",10000);
setup();
}

void set_kind(int poison)
{
	int s;

	if(poison > 7) poison = 7;

	s = random(40);

	switch( poison )
	{
	case 0:
		set_name("毒蛇", ({ "snake", "she" }) );
		set("long", "一只有着三角形脑袋的蛇，尾巴沙沙做响。\n");
		break;
	case 1:
		set_name("黑蛇", ({ "hei she", "snake" ,"she" }) );
		set("long", "这条黑蛇身子黑得发亮，身上白点也是闪闪发光，张开大口，露出四根獠牙。\n");
		break;
	case 2:
		set_name("竹叶青", ({ "zhuye qing", "snake" }) );
		set("long", "一只身体碧绿的蛇，显得特别细小。\n");
		break;
	case 3:
		set_name("百步蛇", ({ "baibu she", "she", "snake" }) );
		set("long", "一条青色长蛇，黄鳞覆体。据说被百步蛇咬了，走出一百步必死无疑。\n");
		break;
	case 4:
		set_name("青花蛇", ({ "qinghua she", "she", "snake" }) );
		set("long", "一条混身青黄相间的毒蛇，斑条鲜明，蛇头奇扁，作三角之形，显具剧毒。\n");
		break;
	case 5:
		set_name("蝮蛇", ({ "fu she", "she", "snake" }) );
		set("long", "一条细颈青身的蝮蛇。\n");
		break;
	case 6:
		set_name("赤练蛇", ({ "chilian she", "chilian", "she", "snake" }) );
		set("long", "一条尺许长的赤练蛇，青红斑斓，甚是可怖。\n");
		break;
	case 7:
		set_name("金线蛇", ({ "jinxian she", "she", "snake" }) );
		set("long", "一条方头小蛇，全身绿鳞覆体，一条金线由蛇腹而下。\n");
		break;
	}
	set_name("沥泉怪蛇", ({ "liquan guaishe", "she", "snake", "guaishe" }) );
	set_weight(poison*600 + 9000);
	set("str", 40 + poison );
	set("con", 30 + poison );
	set("int", 20);
	set("dex", 30 + poison );

	set("max_jing", 3600 + poison*400);
	set("max_qi", 3600 + poison*400);
	set("eff_jing", 3600 + poison*400);
	set("eff_qi", 3600 + poison*400);
	set("jing", 3600 + poison*400);
	set("qi", 3600 + poison*400);

	set("combat_exp", (poison + 1)*6000000);

	set_temp("apply/attack", 200 + s + poison*20 );
	set_temp("apply/damage", 200 + s + poison*20 );
	set_temp("apply/armor", 200 + s + poison*20 );

	set("snake_poison", 60 + poison*40 +random(61));
	set("bt_snake", 1);
}

void die()
{
	object ob;
	message_vision("\n$N全身扭曲，翻腾挥舞，全身软软地散了开来。\n", this_object());
	ob = new("/d/qilincun/obj/liquan");
	ob->move(environment(this_object()));
	CHANNEL_D->do_channel(this_object(), "rumor", HIG"沥泉怪蛇伏诛，沥泉灵现世！"NOR);
	destruct(this_object());
}