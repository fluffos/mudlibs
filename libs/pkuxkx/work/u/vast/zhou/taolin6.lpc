#include <ansi.h>

inherit ROOM;

void create()
{
        int i, n;
        string *direct = allocate(4), *dir = ({"east","north","south","west"});
        for(i = 3; i >= 0; i--)
        {
        	n = random(sizeof(dir));
                direct[i] = dir[n];
        	set("sign" + i, direct[i]);
                dir -= ({direct[i]});
        }

        set("short", "桃林");
        set("long", @LONG
你仿佛走进了一个迷宫，四面都是花树，五色缤纷，不见尽头，
只看得头晕眼花。花树之间既无白墙黑瓦，亦无炊烟犬吠，静悄悄的
情况怪异之极。
LONG);
        set("exits", ([
                direct[0] : __DIR__"taolin3",
                direct[1] : __DIR__"taolin4",
                direct[2] : __DIR__"taolin5",
                direct[3] : __DIR__"taolin7",
       	]));
        set("outdoors","taohuadao");
        setup();
}

void init()
{
	object me = this_player();
	string *str = allocate(4);
	if (me->query_temp("zyhb/bhcs"))
	{
	switch (query("sign0"))
	{
		case "east":
		str[0] = "听出其音以“商”音为主。";
		break;
		case "south":
		str[1] = "听出其音以“商”音为主。";
		break;
		case "west":
		str[2] = "听出其音以“商”音为主。";
		break;
		case "north":
		str[3] = "听出其音以“商”音为主。";
		break;
	}
	switch (query("sign1"))
	{
		case "east":
		str[0] = "听出其音以“宫”音为主。";
		break;
		case "south":
		str[1] = "听出其音以“宫”音为主。";
		break;
		case "west":
		str[2] = "听出其音以“宫”音为主。";
		break;
		case "north":
		str[3] = "听出其音以“宫”音为主。";
		break;
	}
	switch (query("sign2"))
	{
		case "east":
		str[0] = "听出其音以“角”音为主。";
		break;
		case "south":
		str[1] = "听出其音以“角”音为主。";
		break;
		case "west":
		str[2] = "听出其音以“角”音为主。";
		break;
		case "north":
		str[3] = "听出其音以“角”音为主。";
		break;
	}
	switch (query("sign3"))
	{
		case "east":
		str[0] = "听出其音以“徵”音为主。";
		break;
		case "south":
		str[1] = "听出其音以“徵”音为主。";
		break;
		case "west":
		str[2] = "听出其音以“徵”音为主。";
		break;
		case "north":
		str[3] = "听出其音以“徵”音为主。";
		break;
	}
		tell_object(me, HIC"东面的桃林隐约传来一阵箫声，你经过仔细聆听，" + str[0] + "\n"NOR);
		tell_object(me, HIC"南面的桃林隐约传来一阵箫声，你经过仔细聆听，" + str[1] + "\n"NOR);
		tell_object(me, HIC"西面的桃林隐约传来一阵箫声，你经过仔细聆听，" + str[2] + "\n"NOR);
		tell_object(me, HIC"北面的桃林隐约传来一阵箫声，你经过仔细聆听，" + str[3] + "\n"NOR);
	}
}

int valid_leave(object me, string dir)
{
        if (dir == query("sign3"))
        	me->add_temp("zyhb/zhulin" , 8);
        else if (dir == query("sign0"))
        	me->set_temp("zyhb/zhulin" , 0);
        else
        	me->add_temp("zyhb/zhulin" , 16);

        return ::valid_leave(me, dir);
}
