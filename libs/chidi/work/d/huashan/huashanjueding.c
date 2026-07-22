inherit ROOM;
string look_notice();
string *actions;

void create()
{
	set("short", "武林大会广场");
    set("long", @LONG
这里是比武大会的广场，四周各有一个向上的出口，参赛选手可以在这四
个房间休息以及观看比赛。中央有一凸起约丈高的石台，岩石上刻着历界华山
论剑的排行榜(notice)；空坪的东侧立有一丈许高的紫檀木架，架着一面血红
色的大鼓，比武开始后，台上会递出一块牌子(paizi)，向你展示当前比武的赛
程；峰顶四周云雾飘渺，仿佛置身大海，众山犹如海中小岛，环绕着主峰，仿
如一朵盛开的莲花。
LONG
    );
        set("item_desc", ([ /* sizeof() == 1 */
"大鼓"   : "这是一只牛皮制成的巨鼓，武林人士在华山论剑时敲响(knock)它开始比武。\n",
"notice" : (: look_notice :),
"paizi"  : "现在还没开始比赛呢！\n",
]));
    set("exits", ([ /* sizeof() == 2 */
		"1" : __DIR__"biwu1.c",
		"2" : __DIR__"biwu2.c",
		"3" : __DIR__"biwu3.c",
		"4" : __DIR__"biwu4.c",
		"southdown":__DIR__"houzhiwangyu.c",
        ]));
	set("no_fight",1);
	set("no_magic",1);
    set("objects",([
        "/clone/misc/drum":1,
    ]));
    setup();
}
void init()
{
	object me=this_player();

	actions = ({});
	actions += ({"respitate"});
	actions += ({"array"});
	actions += ({"duanlian"});
	actions += ({"duanlian2"});
	actions += ({"ansuan"});
	actions += ({"touxi"});
	actions += ({"persuade"});
	actions += ({"teach"});
	actions += ({"exercise"});
	actions += ({"study"});
	actions += ({"learn"});
	actions += ({"sleep"});
	actions += ({"kill"});
	actions += ({"steal"});
	actions += ({"cast"});
	actions += ({"conjure"});
	actions += ({"expell"});
	actions += ({"hit"});
	actions += ({"prcatice"});
	actions += ({"scribe"});
	actions += ({"surrender"});
	actions += ({"sha"});
	actions += ({"fly"});
	actions += ({"quit"});
	actions += ({"exert"});
	actions += ({"special"});
	actions += ({"perform"});
	actions += ({"yanjiu"});
	actions += ({"respire"});
	actions += ({"fight"});
	actions += ({"get"});

	add_action("discmds",actions);

	if( userp(me) && me->query("no_get") )
	{
		call_out("do_recover",1,me);
	}
}
void do_recover(object me)
{
    if( !me || environment(me) != this_object() ) return;
	me->delete("no_get");
	if (!living(me)) me->revive();
    me->set("eff_jing",me->query("max_jing"));
    me->set("jing",me->query("max_jing"));
    me->set("eff_qi",me->query("max_qi"));
	me->set("qi",me->query("max_qi"));
    if (me->query("neili")<me->query("max_neili"))
        me->set("neili",me->query("max_neili"));
    if (me->query("jingli")<me->query("max_jingli"))
        me->set("jingli",me->query("max_jingli"));
	me->clear_condition();
    me->set("food",me->max_food_capacity());
    me->set("water",me->max_water_capacity());
    me->start_busy(0);
}
int discmds()
{
	tell_object(this_player(),"现在你还是专心看比武吧！\n");

	return 1;
}
string look_notice()
{
        object who;
        string *name_list, file;
        int i, j=0, k;
        who=this_player();
        file=read_file("/log/fight/lunjian");
        if(!file)
                return "目前没有任何比武记录。\n";
        name_list = explode(file,"\n");
        for(i=0;i<sizeof(name_list);i++)
		{
			if(name_list[i] == "seperator" )
			{
				j++;
				k=0;
				printf("\n第"+chinese_number(j)+"届华山论剑结果：\n");
				continue;
			}
			k++;
			printf(GRN "第"+chinese_number(k)+"名：%-50s\n" NOR, name_list[i]);
        }
        return "\n";
}

int valid_leave(object me, string dir)
{
	object tagob,thisob;
	mapping skills;
	string *me_skill;
	int i,flag=0;

	thisob = this_object();

	if (dir == "southdown")
		return 1;

	if (wizardp(me))
		return 1;

    //if (me->query("mud_age")<86400*2)
	//	return notify_fail("你还小，那边很危险的！\n");

	skills = me->query_skills();      
    if (sizeof(skills))
    {
		me_skill = keys(skills);
		for (i=0;i<sizeof(me_skill);i++)
		{
            if( SKILL_D(me_skill[i])->type() !="knowledge" && skills[me_skill[i]] >= 2000)
			{
				flag = 1;
			}
			if(me_skill[i] == "literate" && skills[me_skill[i]] >= 15000)
			{
				flag = 1;
			}
		}
    }

	if(!flag)
	{
		return notify_fail("你是大米吧？过去了会被人打的！\n");
	}

	if(me->query("max_neili") < 300000 || me->query("max_jingli") < 100000)
	{
		return notify_fail("你这样的实力过去了一招也撑不过！\n");
	}

	if(!objectp( tagob = find_object( query("exits/"+dir) ) ))
	{
		tagob = load_object( query("exits/"+dir) );
	}

	if( sizeof(all_inventory(tagob)) >= 25 )
	{
		return notify_fail("那边观战坪已经人满了！！\n");
	}

	return ::valid_leave(me, dir);
}

