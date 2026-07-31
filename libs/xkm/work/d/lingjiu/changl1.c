//room: changl1.c
/*Update by George 98/7
	1. hand to 30;
	2. zhemei-shou to 30;
*/

inherit ROOM;

int do_zhemei();

void create()
{
  set("short","画廊");
  set("long",@LONG
这是一条非常精美的长廊，柱子和栏杆是用华贵的紫檀木制成，上面
雕饰着美丽的图画(hua)，画工精巧，美不胜收，似乎与别处不同。地
板不知是用什么材料做的，走在上面毫无声息，你只感到脚下软软的，
非常舒服。西边通向大厅。
LONG
    );

  set("item_desc",([
	  "hua"	:	"这是一幅栩栩如生的仕女图，画中美女手持一枝红梅(zhemei)，正翩翩起舞。\n",])
	 );

  set("exits",([
      "west" : __DIR__"changl5",
      "east" : __DIR__"huayuan",
     ]));

 setup();
 //replace_program(ROOM);
}

void init()
{
	add_action("do_zhemei", "zhemei");
}

int do_zhemei()
{
	mapping fam; 
	object ob;

	ob = this_player();
	
	if (!(fam = ob->query("family")) || fam["family_name"] != "灵鹫宫")
	{
		write("如此美丽的舞姿，你看着看着禁不住随之翩翩起舞。\n");
		return 1;
	}

	if ((int)ob->query_skill("hand", 1) < 30) 
    {
			
		if( (int)ob->query_skill("hand", 1)* (int)ob->query_skill("hand", 1) * (int)ob->query_skill("hand", 1)/ 10 > (int)ob->query("combat_exp") ) {
			write("也许是缺乏实战经验，你对画中的意境总是无法领会。\n");
			return 1;
		}
		ob->receive_damage("jing",30, "心力憔悴死了");
		ob->improve_skill("hand", ob->query("int"));
		write("如此美丽的舞姿，你看着看着禁不住随之翩翩起舞。\n");
		return 1;
	}
	else if((int)ob->query_skill("zhemei-shou",1)>30)
	{
		write("如此美丽的舞姿，你看着看着禁不住随之翩翩起舞。\n");
		return 1;
	}
	else{
		ob->receive_damage("jing",30, "心力憔悴死了");
		ob->improve_skill("zhemei-shou",ob->query("int"));
		write("如此美丽的舞姿，你看着看着禁不住随之翩翩起舞。\n");
		return 1;

	}

	return 1;
}