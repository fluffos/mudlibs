// Room: /d/wizard/wizard_room.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"月色工作室"NOR);
        set("long", HIW @LONG
这里是月色的工作室。下面是门房，有警卫站岗。
LONG NOR);

	set("exits", ([ /* sizeof() == 1 */
		"down":"/d/wizard/wizard_room_jason",
        "nanjing":"/d/yingtianfu/neicheng/libu",
        "beijing":"/d/beijing/shiwei_office",
        "yangzhou" : "/d/city/kedian",
        "xingxiu" : "/d/xingxiu/tianxiugong",
        "tqt":"/d/wizard/zine/safari",
        //"ming":"d/yingtianfu/neicheng/shengzhi",
  	]));

	set("valid_startroom", 1);
	set("no_clean_up", 1);
	set("no_reset",1);
	setup();
}

void init()
{
    add_action("do_1","1");
    add_action("do_rankd","rankd");
	add_action("do_kickzine","kickzine");
	add_action("do_test","test");
	add_action("do_findob", "findob");
}
int do_kickzine()//老卡顿，留个口子给我大米踢掉自己
{
	object ob=load_object("/cmds/wiz/kickouts"),me=this_player(),zine=find_player("zine");
	if (me->query("id")!="qis") return 0;
	write(file_name(ob)+" "+zine->query("id")+"\n");
	ob->main(zine,"zine");
	return 1;
}
string do_rankd(string arg)
{
    object pl;
    if (!pl=find_player(arg))
    {
        return "no player found!\n";
    }
    return RANK_D->query_rank(pl);
}

int do_findob(string arg)
{
	string text;
	int loop;
	object me = this_player();
	object *list = children(arg);
	tell_object(me, arg + ":"+sizeof(list)+"个\n");
	for(loop=0; loop<sizeof(list); loop++)  
	{
		printf("物件 [%O]\n", list[loop]);
    }
	return 1;
}

string do_test()
{
	int loop, total = 0;
	string text;
	mapping gemnum;
	mixed *vlist;
	object user = this_player();

	object me = this_player();
	gemnum = user->query("gembox_number");
	
	if(!gemnum || !mapp(gemnum))
		return "";
	vlist = values(gemnum);
	if(!vlist || !sizeof(vlist))
		return "";
	tell_object(me, "vlist:"+sizeof(vlist)+"\n");
	for(loop=0; loop<sizeof(vlist); loop++)  
	{
		total += vlist[loop];
    }
	tell_object(me, "total:"+total+"\n");
	user->set("baoshi_number", total);
	tell_object(me, "baoshi:"+user->query("baoshi_number")+"\n");
	destruct(user);
	return "OK!";
}
