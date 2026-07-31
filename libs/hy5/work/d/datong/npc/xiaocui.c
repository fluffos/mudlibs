// xiaocui.c

#define DATONG	"/d/datong/"

#include <ansi.h>

inherit NPC;

int ask_me(object who);

void create()
{
	set_name("小翠", ({ "xiao cui" }) );

	set("gender", "女性" );

	set("age", 17);

	set("long","这是一位十七八岁的小丫鬟。\n");
	set("combat_exp", 100);

	set("no_kill", 1);
	set("attitude", "friendly");

	set("inquiry",([
	"衣服" : (: ask_me :),
]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me(object who)
{
	string *pos = ({DATONG"huayanlu1",DATONG"shizilukou",DATONG"hongchanglu5",DATONG"hongchanglu1"}),where;
	object room,ob;

	if(!who->query("quest/shaolin_quest/win_zhuge"))
		return 0;

	if(who->query("quest/shaolin_quest/asked_yahuan"))
	{
		write(sprintf(CYN"%s说道：不是告诉你已经送出去了？找我也没用。\n"NOR,name()));
		return 1;
	}

	where = pos[random(sizeof(pos))];
	room = find_object(where);
	if(!room)
		room = load_object(where);
	if(!room)
		return 0;

	if(!objectp(ob = new(__DIR__"blind_beggar")))
		return 0;

	write(sprintf(CYN"%s说道：哦，你说的是少爷那件画满小人的脏衣服？那件衣服少爷
          好久都不穿了，又不让人洗。前几天和其他的旧衣服一
          起都布施给城里的乞丐了。那件衣服我记得好像是被一
          个瞎眼老乞丐拿走了。你去找找吧。\n"NOR,name()));

	who->set("quest/shaolin_quest/asked_yahuan",1);
	who->add("quest/shaolin_quest/hint",sprintf("      %s\n",
		"小翠告诉你衣服被一个大同府的『瞎眼乞丐』拿走了。"));

	ob->move(room);
	tell_room(sprintf("%s走了过来。\n",ob->name()));

	return 1;
}
