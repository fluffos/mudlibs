// liehu_zhao.c
// 每人只能收一件活.
// by Find.

#include <ansi.h>
#define MAX		10
#define GET_RATE	20

inherit NPC;

static mapping liewu = ([ "野山鸡":__DIR__"obj/shanji",
"獐子":__DIR__"obj/zhangzi",
"麋鹿":__DIR__"obj/milu",
"山虎":__DIR__"obj/shanhu", ]);

private string pay_request(object who,string name,int yufu);
string check_request(string id);

void create()
{
	set_name("老赵", ({ "old zhao", "zhao" }) );
	set("title","猎户");
	set("gender", "男性" );
	set("age", 47);
	set("long", "老赵是这一带闻名的神猎手，不但每次打猎回
来收获丰厚，而且有时还能打到一些珍奇的野
兽，但是怎么打到的却是死活不说，别看是一
个猎户，也是很有头脑的，如果你想搞一些珍
奇野兽找他也许有办法，不过价钱可不会便宜
呀。你可以问问他关于“打猎”的事情。 \n");

	set("chat_chance",10);
	set("chat_msg",({
	CYN"老赵说道：“以前我爹常和我说：猎户的饭碗就在打猎的地方和方法上，就是死也不能和别人说。”\n"NOR,
	CYN"老赵说道：“这附近的山上有不少珍奇野兽，就是很难打到。”\n"NOR,
}));

	set("combat_exp", 20000);
	set("per", 30);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);

	setup();
	carry_object(__DIR__"obj/hupi")->wear();
if (random(2)==0)
carry_object(__DIR__"obj/shanji");
if (random(4)==0)
carry_object(__DIR__"obj/zhangzi");
if (random(8)==0)
carry_object(__DIR__"obj/milu");
if (random(16)==0)
carry_object(__DIR__"obj/shanhu");

}

