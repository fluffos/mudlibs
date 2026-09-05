// File         : songlin.c
// Created By   : iszt@pkuxkx, 2006-09-05

inherit ROOM;
void dest(object ob);
void create(string comefrom)
{
        set("short", "松林");
        set("long",
"走入松林，视线不如先前开阔，便如身处茫茫大海，令人手足无措。地上厚
厚的一层积雪，每走一步双腿都会深深陷入雪中，要付出相当大的气力才能拔出
腿来，继续前进。寒风在林间呼呼的刮着，似乎有什么东西注视着你，令你毛骨
悚然。");

        set("indoors", "凌霄城");
        set("exits", ([
                "northup" : __FILE__,
                "northwest" : __FILE__,
                "southdown" : __FILE__,
                "southeast" : __FILE__,
        ]));
        set("objects", ([
                __DIR__"npc/wolf" : random(2),
        ]));
        if(!comefrom)
                comefrom = "void";
        switch(random(4))
        {
        case 0:
                if(comefrom == "northwest")
                        break;
                add("long", "西北首有一道山壁，阻住了去路。");
                delete("exits/northwest");
                break;
        case 1:
                if(comefrom == "southeast")
                        break;
                add("long", "东南方是一道断崖，无法前进了。");
                delete("exits/southeast");
                break;
        case 2:
                if(comefrom == "northup")
                        break;
                add("long", "北面一道山壁阻住了去路，只能从旁绕开。");
                delete("exits/northup");
                break;
        case 3:
                if(comefrom == "northwest" || comefrom == "northup")
                        break;
                add("long", "西北两面都是山壁，看来只有绕开了。");
                delete("exits/northwest");
                delete("exits/northup");
        default:
        }
        add("long", "\n");

        set("no_task",1);
        setup();
}

void init()
{
        add_action("do_look", "look");
        add_action("do_go", "go");
        //改走出迷宫后递归dest new出来的房间为init时call_out大约15分钟后dest，避免递归调用dest过深的问题
        //icer
        remove_call_out("dest");
        call_out("dest",600+random(600),this_object());
}

int do_look(string arg)
{
        if(!arg || !stringp(query("exits/"+arg)))
                return 0;
        write("四周是一片浓密的松林，什么也看不到。\n");
        return 1;
}

int do_go(string dir)
{
        object me = this_player();

        if(!query("exits/"+dir))
                return 0;
        if(me->is_busy())
        {
                write("你正忙着呢。\n");
                return 1;
        }
        if(me->is_fighting())
        {
                write("你还在战斗，脱不开身。\n");
                return 1;
        }

        message_vision("$N深一脚浅一脚的在松林中独自前行……\n", me);
        call_out("do_move", 1, me, dir);
        me->start_busy(2);

        return 1;
}

int do_move(object me, string dir)
{
        object room;
        string comefrom;
        object* inv;
        int i;

        switch(dir)
        {
        case "southeast":
                comefrom = "northwest";
                break;
        case "northwest":
                comefrom = "southeast";
                break;
        case "southdown":
                comefrom = "northup";
                break;
        case "northup":
                comefrom = "southdown";
                break;
        }

        if(objectp(query("exit/" + dir)))
                room = query("exit/" + dir);
        else
        {
                room = new(__DIR__"songlin", comefrom);
                room->set("exit/" + comefrom, this_object());
                set("exit/" + dir, room);
        }
        if(dir == "northup")
        {
                me->add_temp("lingxiao/songlin/nu", 1);
                me->add_temp("lingxiao/songlin/sd", -1);
        }
        if(dir == "northwest")
        {
                if(me->query_temp("lingxiao/songlin/nu") > 3)
                        me->add_temp("lingxiao/songlin/nw", 1);
                me->add_temp("lingxiao/songlin/se", -1);
        }
        if(dir == "southdown")
        {
                me->add_temp("lingxiao/songlin/sd", 1);
                me->add_temp("lingxiao/songlin/nu", -1);
        }
        if(dir == "southeast")
        {
                me->add_temp("lingxiao/songlin/se", 1);
                me->add_temp("lingxiao/songlin/nw", -1);
        }
        if(me->query_temp("lingxiao/songlin/nw") > 4 && !me->query_temp("lingxiao/songlin/nwexit"))
        {
                room->set("exits/northup", __DIR__"bingchuan");
                me->set_temp("lingxiao/songlin/nwexit", 1);
        }
        if(me->query_temp("lingxiao/songlin/nu") > 5 && !me->query_temp("lingxiao/songlin/nuexit"))
        {
                room->set("exits/northup", __DIR__"xuedi6");
                me->set_temp("lingxiao/songlin/nuexit", 1);
        }
        if(me->query_temp("lingxiao/songlin/se") > 4 && !me->query_temp("lingxiao/songlin/seexit"))
        {
                room->set("exits/southdown", __DIR__"xuedi4");
                me->set_temp("lingxiao/songlin/seexit", 1);
        }
        if(me->query_temp("lingxiao/songlin/sd") > 3 && !me->query_temp("lingxiao/songlin/sdexit"))
        {
                room->set("exits/southeast", __DIR__"xuedi4");
                me->set_temp("lingxiao/songlin/sdexit", 1);
        }
        if(query("exits/" + dir) != __FILE__)
        {
                room = load_object(query("exits/" + dir));
                me->move(room);
                message_vision("$N终于从松林中走了出来，长舒了一口气！\n", me);
                me->delete_temp("lingxiao/songlin");
                this_object()->dest(this_object());
                return 1;
        }
        me->move(room);
        message_vision("$N走了过来，四周仍是一片松林。\n", me);
        if(me->query_temp("lingxiao/songlin/sd") > 20
                || me->query_temp("lingxiao/songlin/se") > 20
                || me->query_temp("lingxiao/songlin/nu") > 20
                || me->query_temp("lingxiao/songlin/nw") > 20)
        {
                write("就在你几乎绝望时，发现自己竟有如神助般找到了出口，"
                        "不禁丢下所有累赘，欣喜若狂的奔了过去！\n");
/*
                inv = deep_inventory(me);
                for(i=sizeof(inv); i>=0; i--)
                {
                        if(inv[i]->query("id") == "lang pi")
                                destruct(inv[i]);
                }
*/
                me->move(__DIR__"xuedi4");
                message_vision("$N终于从松林中走了出来，长舒了一口气！\n", me);
                me->delete_temp("lingxiao/songlin");
                this_object()->dest(this_object());
                return 1;
        }
        return 1;
}
/*
void dest(object excluded_ob)
{
        object ob;
        this_object()->set("desting",1);
        if(objectp(ob = query("exit/northup")) && !ob->query("desting"))
                ob->dest(this_object());
        if(objectp(ob = query("exit/northwest")) && !ob->query("desting"))
                ob->dest(this_object());
        if(objectp(ob = query("exit/southdown")) && !ob->query("desting"))
                ob->dest(this_object());
        if(objectp(ob = query("exit/southeast")) && !ob->query("desting"))
                ob->dest(this_object());

        destruct(this_object());
}
*/
void dest(object ob)
{
		object *inv;
		int i,can_dest;
		
		inv = all_inventory(ob);
		can_dest = 1;
		for (i=0;i<sizeof(inv);i++)
			if (userp(inv[i]))
				can_dest = 0;
		
		if (!can_dest)		
			call_out("dest",600+random(600),ob);
		else destruct(ob);
		return;
}