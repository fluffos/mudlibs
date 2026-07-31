// /u/beyond/mr/matou.c
// this is made by beyond
// updated by Jpei  1999.9.7

inherit ROOM;

#include <ansi.h>  

mapping *sign=({
([
	"name":"琴韵小筑",
        "id":"mr",
        "file":__DIR__"duchuan",
	"value":500
]),
([
	"name":"燕子坞",
	"id":"yanziwu",
	"file" :__DIR__"zhou",
	"value":1000
]),
});

string look_sign();
int do_go(string);

void create()
{
        set("short", "码头");
	set("long",@LONG
这里是慕容家的家仆和丫鬟出入太湖的水上码头，只见人们来来往往，
一个个风尘仆仆，码头边的老船夫见到你走过来，马上笑呵呵的迎了上去。
价格表(sign)。旁边还有一条小快船你可以进去(enter)。
LONG 
);
	set("outdoors","mr");
	set("exits",([
		"north" : __DIR__"shiqiao",
	]));
        set("objects",([  
           "/clone/misc/dache" : 1 ,
        ])); 

	set("item_desc", ([
		"sign" : (: look_sign :)
	]));
//	set("outdoor", "abc");

	setup();
}

void init()
{
	add_action("do_go", ({ "qu", "dao" }));
    add_action("do_enter", "enter");
}

string look_sign()
{
	object ob = this_player();
	string str="";
	int i=sizeof(sign);

        if (ob->query("family/family_name") != "姑苏慕容") i--;

	while (i--) {
		str += sign[i]["name"];
		str += "(" + sign[i]["id"] + ") ";
	        if (ob->query("family/family_name") == "姑苏慕容")
			str += "慕容弟子免费\n";
		else
			str += MONEY_D->price_str(sign[i]["value"]) + "\n";
	}

	return str;
}

void do_move(object ob, int i)
{
        if (ob->query("family/family_name") == "姑苏慕容")
		message_vision(YEL"\n$N随着船家上了一条小舟。\n\n"NOR,ob);
	else
		message_vision(YEL"\n$N把钱交给船家，船家领$N上了一条小舟。\n\n"NOR,ob);
	ob->move(sign[i]["file"]);
}

int do_go(string arg)
{
	object ob=this_player();
	int level1, level2, i=sizeof(sign);
	string skill;

	if (!arg) return notify_fail("你要去哪里？\n");
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("你正忙着呢！\n");

//	if (ob->query("family/family_name") != "姑苏慕容") i--;

	while(i--) {
		if (arg == sign[i]["id"]) {
		        if (ob->query("family/family_name") == "姑苏慕容") {
				level1 = ob->query_skill("xingyi-zhang", 1);
				level2 = ob->query_skill("canhe-zhi", 1);
				if (!level1 && !level2) skill = "燕子出巢";
				else if (level1 > level2) skill = SKILL_D("xingyi-zhang")->query_skill_name(random(level1));
				else skill = SKILL_D("canhe-zhi")->query_skill_name(random(level2));
				message_vision("$N向船家打了个揖道：“这位船家，我乃慕容弟子，想去" + sign[i]["name"] + "。”\n",ob);
				
				if (!skill) skill = "燕子出巢";
				message_vision("船家看了看$N，露出怀疑的神色。\n",ob);
				message_vision("$N面露微笑，使了一招“" + skill + "”，道：“如何？”\n船家点了点头道：“随我来。”\n",ob);
				ob->start_busy(1);
				call_out("do_move", 1, ob, i);
			}
			else {
				switch (MONEY_D->player_pay(ob, sign[i]["value"])) {
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

int do_enter ( string arg )
{
    object ob ;
    string dir;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    if( ob->query("family/family_name") != "姑苏慕容")
{
     message_vision("$N这是姑苏慕容的快船,你不能上!\n",  ob);
    return 1;
}
    message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);
    message_vision("船夫升起帆，快船就向湖中航行。\n", ob);
    ob->move("/d/mr/yanziwu") ;
    tell_object(ob, BLU "你在湖中航行了一会就到了一个岛上!\n" NOR ) ;
    return 1 ;
}