// 日本人

#include <ansi.h>

inherit NPC;

string *names = ({
	"山本五十六",
	"桥本太郎",
	"东条英机",
	"横路进二",
});

int ask_girl();
int ask_gold();

void create()
{
	set_name( HIY + names[random(sizeof(names))] + NOR, ({ "wolf" }) );
	set("long", @LONG
这是一个极端凶狠残暴的日本人，他率领了一批没有人性的
倭寇登上钓鱼岛，企图把这里划入他们的版图。此人满脸横
肉，面带奸笑，一望而知并非善种。
LONG
	);
	set("age", 46);
	set("gender", "男性");

	set("shen_type", -1);
	set("shen", -20000);

	set("combat_exp", 500000);
	set("max_qi", 2000);
	set("eff_qi", 2000);
	set("qi", 2000);
	set("jiali", 100);

	set_skill("force", 100);
	set_skill("blade", 150);
	set_skill("unarmed", 150);

	set("chat_chance", 10);
	set("chat_msg", ({
		query("name") + "自言自语道：大日本帝国是天下无敌的！\n",
		query("name") + "发出一阵险恶的狞笑。\n",
		query("name") + "流着口水淫笑道：花姑娘的，大大的好！\n",
	}) );
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		query("name") + "大喝道：八格牙路！死拉死拉的！\n",
		query("name") + "凶恶的面孔上忽然露出一丝恐慌。\n",
	}) );

	set("inquiry", ([
		"花姑娘" : (: ask_girl :),
		"聚宝箱" : (: ask_gold :),
	]) );

	set("attitude", "heroism");

	setup();

	carry_object(__DIR__"obj/mian_dao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

int ask_girl()
{
	object me, ob;

	me = this_player();
	ob = this_object();
	if (me->query("gender") == "女性")
	{
		message_vision("$N对着$n发出一阵淫笑，说道：花姑娘的干活，你想陪我玩玩？\n", ob, me);
		message_vision("$N开始对$n动手动脚。\n", ob, me);
	}
	else
	{
		message_vision("$N斜着眼睛瞪了$n一眼，说道：你想抢我的花姑娘？八格牙路！\n", ob, me);
		ob->kill_ob(me);
		me->kill_ob(ob);
	}
	return 1;
}

int ask_gold()
{
	object me, ob;
	
	me = this_player();
	ob = this_object();
	if (ob->query_weapon())
		message_vision("$N唰的一声抽出兵刃，恶狠狠地说道：想抢我的宝贝？去死吧！\n", ob);
	else
		message_vision("$N对着$n大喝一声：想抢我的宝贝？去死吧！\n", ob, me);
	ob->kill_ob(me);
	me->kill_ob(ob);
	return 1;
}

void die()
{
        object me = get_damage_origin_object();
        if(objectp(me) && (int)me->query("repute")<50000)
        {
                me->add("shen", 10000);
                me->add("repute", 1945);
                message_vision(HIR+BLINK"\n感谢$N杀死了罪大恶极的日本鬼子头目！$N的正气和江湖声望上升了！\n"NOR, me);
        }
        ::die();
}
