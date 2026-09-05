
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"较技场"NOR);
	set("long", @LONG
这里是正气山庄的较技场。有什么恩怨不能化解的，正气山庄会邀请他们来这里公平较技。
很多仇家，对头，都是在这里不打不相识，不但化解了仇恨，甚至成为了朋友。正气山庄的
威望可见一斑。
LONG);

	set("objects", ([
	//这个庄丁很重要，用来向看台里传递消息，所以，不要删除掉
		__DIR__"npc/jiading2" : 1,
	]));
	
	set("exits", ([
		"east": __DIR__"jiaoji_kantai",
	]));
	set("no_die",1);
	setup();
	replace_program(ROOM);
}

void init()
{
	add_action("do_showbugid","show_bugid");
}

int do_showbugid()
{
    object *users;
    int i, j;
    string *keys, msg1="", msg2="";
    mapping map;

    if (!wizardp(this_player())) return 0;
    users = users();
    for (i=0;i<sizeof(users);i++)
    {
        if( users[i]->query("leave_family/betrayer") != users[i]->query("betrayer") &&
            users[i]->query("xiantian/str/luohan") && users[i]->query("birthday") > 1349446043 )
        {
            msg1 += sprintf("\n%s betrayer:%d\n", users[i]->name_id(), users[i]->query("betrayer"));
            map = users[i]->query("leave_family");
            if ( mapp(map) )
            {
                keys = keys(map);
                for (j=0;j<sizeof(keys);j++)
                {
                    if (stringp(map[keys[j]]))
                    {
                        msg1 += sprintf("%s %s\n", "leave_family/"+keys[j], map[keys[j]]);
                    }
                    else if (intp(map[keys[j]]))
                    {
                        msg1 += sprintf("%s %d\n", "leave_family/"+keys[j], map[keys[j]]);
                    }
                }
            }
        }

        if ( users[i]->query("potential")+users[i]->query("deposit_qn_num") > users[i]->query("combat_exp")+100000 && users[i]->query("birthday") > 1349446043 )
        {
            msg2 += sprintf("\n%s ", users[i]->name_id());
            msg2 += sprintf("pots:%d exp:%d\n", users[i]->query("potential")+users[i]->query("deposit_qn_num"), users[i]->query("combat_exp"));
        }
    }

    printf("%s%s", msg1, msg2);
    return 1;
}

