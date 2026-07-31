// /u/beyond/mr/anbian1.c
// this is made by beyond
// updated by Jpei  1998.9.7

#include <room.h>
#include <ansi.h>

inherit ROOM;

mapping *paizi=({
([  
	"name":"琴韵小筑",
	"id":"xiaozhu",
        "file":__DIR__"zhou6",                    
        "value":500
]),
([  
	"name":"燕子坞",
        "id":"yanziwu",
        "file":__DIR__"zhou",
	"value":500
]),               
});

string look_paizi();
int do_go(string);

void create()
{
	set("short",HIY"岸边"NOR);
	set("long", @LONG
这是曼佗罗山庄的一个小码头，从这里上船可以到达慕容世家的领地，
武林中的英雄豪杰们都十分仰慕闻名天下的燕子坞，因为那里是无人不知无
人不晓的“以彼之道，还施彼身”的发源地，而慕容世家一代就是住在那里。
岸边有一位老船夫，专门载着去燕子坞的武林人士，他一见你走过来，不敢
怠慢，带着笑脸连忙迎上前去。在岸边有一块牌子(paizi)。
LONG
);
	set("outdoors","mr");
	set("exits",([
		"north" : __DIR__"xiaojing1-0",
	]));
	set("item_desc",([
		"paizi" : (: look_paizi :)     
	]));
}

void init()
{
	add_action("do_go", ({ "qu", "dao" }));
}

string look_paizi()
{
	object ob = this_player();
	string str="";
	int i=sizeof(paizi);

//	if (ob->query("family/family_name") != "姑苏慕容") i--;

	while (i--) {
		str += paizi[i]["name"];
		str += "(" + paizi[i]["id"] + ") ";
	        if (ob->query("family/family_name") == "姑苏慕容")
			str += "慕容弟子免费\n";
		else
			str += MONEY_D->price_str(paizi[i]["value"]) + "\n";
	}

	return str;
}

void do_move(object ob, int i)
{
        if (ob->query("family/family_name") == "姑苏慕容")
		message_vision(YEL"\n$N随着船家上了一条小舟。\n\n"NOR,ob);
	else
		message_vision(YEL"\n$N把钱交给船家，船家领$N上了一条小舟。\n\n"NOR,ob);
	ob->move(paizi[i]["file"]);
}

int do_go(string arg)
{
	object ob=this_player();
	int level1, level2, i=sizeof(paizi);
	string skill;

	if (!arg) return notify_fail("你要去哪里？\n");
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("你正忙着呢！\n");

//	if (ob->query("family/family_name") != "姑苏慕容") i--;

	while(i--) {
		if (arg == paizi[i]["id"]) {
		        if (ob->query("family/family_name") == "姑苏慕容") {
				level1 = ob->query_skill("xingyi-zhang", 1);
				level2 = ob->query_skill("canhe-zhi", 1);
				if (!level1 && !level2) skill = "燕子出巢";
				else if (level1 > level2) skill = SKILL_D("xingyi-zhang")->query_skill_name(random(level1));
				else skill = SKILL_D("canhe-zhi")->query_skill_name(random(level2));
				message_vision("$N向船家打了个揖道：“这位船家，我乃慕容弟子，想去" + paizi[i]["name"] + "。”\n",ob);
				if (!skill) skill = "燕子出巢";
				message_vision("船家看了看$N，露出怀疑的神色。\n",ob);
				message_vision("$N面露微笑，使了一招“" + skill + "”，道：“如何？”\n船家点了点头道：“随我来。”\n",ob);
				ob->start_busy(1);
				call_out("do_move", 1, ob, i);
			}
			else {
				switch (MONEY_D->player_pay(ob, paizi[i]["value"])) {
					case 0:
						return notify_fail("穷光蛋，一边呆着去！\n");
					case 2:
						return notify_fail("有零钱吗？\n");
				}
				message_vision("$N在口袋里翻来覆去地找船钱。\n", ob);
				ob->start_busy(3);
				call_out("do_move", 3, ob, i);
			}
			return 1;
		}
	}
	return notify_fail("你要去哪里？\n");
}
