#include <ansi.h>
#define OUT_ROOM "/d/city/guangchang"
inherit ROOM;

int do_leave(string arg);
void create()
{
	set("short", "宝塔一层");
	set("long","这里是万安寺内宝塔的第一层，戒备森严，一看就知道关押着重要人物。\n");
	set("out_room", OUT_ROOM);
	set("exits", ([
		"south" : OUT_ROOM,
	]));
	setup();
}

void nextlv(int delay)
{
	add("sllv",1);
	set("short", "宝塔"+CHINESE_D->chinese_number(query("sllv"))+"层");
	set("long","这里是万安寺内宝塔的第"+CHINESE_D->chinese_number(query("sllv"))+"层，戒备森严，一看就知道关押着重要人物。\n");
	tell_room(this_object(),ZJFORCECMD("look"));
	call_out("nextlv2",delay);
}

int nextlv2()
{
	object slnpc;
	slnpc = new("/clone/fuben/wanansi/npc/hero");
	slnpc->move(this_object());
	slnpc = new("/clone/fuben/wanansi/npc/sldizi");
	slnpc->move(this_object());
	tell_room(this_object(),"你来到了"+query("short")+"。\n");
	return 1;
}

void no_die(object ob)
{
	object *inv,env;
	int i;
	int k = 0;

	env = environment(ob);
	inv = all_inventory(env);
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]!=ob&&playerp(inv[i])) k = 1;
	}
	if(!k)
		call_out("des_me",1);
	ob->delete("wanan");
}

int valid_leave(object me, string dir)
{
	no_die(me);
	return ::valid_leave(me, dir);
}

void des_me()
{
	destruct(this_object());
}