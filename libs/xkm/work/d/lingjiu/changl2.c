//room: changlang2.c
/*Updated by George 98/7
	1. sword to 30;
	2. tianyu-qijian to 30;
*/

inherit ROOM;

int do_wujian();

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
	  "hua"	:	"这是一幅栩栩如生的仕女图，画中美女手持长剑(wujian)，正随着音乐翩翩起舞。\n",])
	 );

  set("exits",([
      "east" : __DIR__"changl3",
      "west" : __DIR__"huayuan",
     ]));

 setup();
// replace_program(ROOM);
}

void init()
{
	add_action("do_wujian", "wujian");
}

int do_wujian()
{
	mapping fam; 
	object ob, weapon;

	ob = this_player();

	if (!objectp(weapon = ob->query_temp("weapon"))					//must wield jian first
	|| (string)weapon->query("skill_type") != "sword")				
		return notify_fail("你使用的武器不对。\n");
	
	if (!(fam = ob->query("family")) || fam["family_name"] != "灵鹫宫")
	{
		write("如此美丽的舞姿，你看着看着禁不住随之翩翩起舞。\n");
		return 1;
	}

	if ((int)ob->query_skill("sword", 1) < 30) 
    {
			
		if( (int)ob->query_skill("sword", 1)* (int)ob->query_skill("sword", 1) * (int)ob->query_skill("sword", 1)/ 10 > (int)ob->query("combat_exp") ) {
			write("也许是缺乏实战经验，你对画中的意境总是无法领会。\n");
			return 1;
		}
		ob->receive_damage("jing",30, "心力憔悴死了");
		ob->improve_skill("sword", ob->query("int"));
		write("如此美丽的舞姿，你看着看着禁不住随之翩翩起舞。\n");
		return 1;
	}
	else if((int)ob->query_skill("tianyu-qijian",1)>30)
	{
		write("如此美丽的舞姿，你看着看着禁不住随之翩翩起舞。\n");
		return 1;
	}
	else{
		ob->receive_damage("jing",30, "心力憔悴死了");
		ob->improve_skill("tianyu-qijian",ob->query("int"));
		write("如此美丽的舞姿，你看着看着禁不住随之翩翩起舞。\n");
		return 1;

	}

	return 1;
}