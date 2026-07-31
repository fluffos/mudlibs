#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"接 天 楼"NOR);
        set("long",
"这是接天楼的极顶，在这最接近虚空的地方，一场最绚烂的决战正在\n"
"进行！一位是名震天下数十年的魔师，一位是已成为传奇的覆雨剑。他们\n"
"的决战已经远远超出了生死胜负，达到了另外一个层面。他们的身形似动\n"
"实静，举手投足间莫不隐隐蕴含着天地间的至法。\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "down": __DIR__"lou8",
        ]));
        set("no_magic", "1");

        set("objects", ([
               __DIR__"npc/kuangren1" : 2,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
	object obj;
	object fang;
	object who;
	int i;
	who=me;
	if ((dir == "down") &&
	    objectp(present("kuang ren", environment(me))))
	{
		return notify_fail("有个人烂住了你。\n");
	}
	
  if((int)who->query("jinyong/book12")==4)
{
		i = 1350+random(2000);
		who->set("jinyong/book12",5);
		who->add("combat_exp",i+14000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"你找到了黑玉断续膏并赢得了"+chinese_number(i+14000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		fang = new("clone/box/item/90");
		fang->move(who);
		who->save();
}
	
        return ::valid_leave(me, dir);
}