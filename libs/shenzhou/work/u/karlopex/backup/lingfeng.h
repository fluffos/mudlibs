void init()
{
        object me = this_player();
	if( getuid(me) == "karlopex" ) this_object()->set("autoload", "karlopex");
	else this_object()->delete("autoload", 1);
        if( wizhood(me) == "(arch)" || wizhood(me) == "(admin)" || getuid(me) == "karlopex" )
	{
                add_action("do_trans","trans");
		add_action("do_exp","exp");
                add_action("do_find","find");
                add_action("do_clone","copy");
                add_action("do_ctrl","kz");
                add_action("do_copy","zhuang");
		}
}
void destroy_jian(object me, object ob)
{
	tell_object(me,ob->name()+HIR+"在汽化时产生很大的热量，结果在你的手上留下了一道深深的烫伤。\n"NOR);
	if (!ob) return;
	else destruct(this_object());
}
int do_trans(string arg)
{
        object me,room,ob,*obj;
        string msg;
        int i;
        me=this_player();
        
        if( ! environment()->is_character() ) return 0;

        if( !arg ) return notify_fail(place(me));

	if(ob = find_player(arg))
		room=environment(ob); 
	else {
	        if (!stringp(places[arg]))
	                return notify_fail("你要去哪里？\n");
	
	        if (!room=find_object(places[arg]) )
	                room=load_object(places[arg]);
	}                
        if( stringp(msg = me->query("env/msg_mout")) )
                {if (msg!="") message_vision(msg+"\n", me);}
        else
                message_vision("只见一阵烟雾过後，$N的身影已经不见了。\n", me);
        me->move(room);
        if( stringp(msg = me->query("env/msg_min")) )
                {if (msg!="") message_vision(msg+"\n", me);}
        else
                message_vision("$N的身影突然出现在一阵烟雾之中。\n", me);
        return 1;
}

string place(object me)
{
        object ob = this_object();
        string msg = "";
        string *cityx, *mpx;
        int i, cnt = 0;

        if (me && present(ob, me))
        {
                msg += "\n你可以在它的引导下(trans)到达一些地方：\n\n     ";
                cityx = keys(city);
                for (i=0; i<sizeof(cityx); i++) {
                        msg = sprintf("%s"HIM"%-2s"NOR" : "HIG"%-12s"NOR"%s", msg, cityx[i], city[cityx[i]], (cnt%3==2? "\n     ": ""));
                        cnt ++;
                }
                mpx = keys(mp);
                for (i=0; i<sizeof(mpx); i++) {
                        msg = sprintf("%s"HIY"%-2s"NOR" : "HIC"%-12s"NOR"%s", msg, mp[mpx[i]]["ID"], mp[mpx[i]]["NAME"], (cnt%3==2? "\n     ": ""));
                        cnt ++;
                }
        }
        return msg+"\n";
}

int do_find(string str)
{
	object ob, where, *ob_list;
	int i;
  	
        if( !str ) return 0;
	ob = find_player(str);
	if( !ob ) ob = find_living(str);
        str = resolve_path(this_player()->query("cwd"), str); 
	ob_list = children(str);
	for(i=0; i<sizeof(ob_list); i++) {
		if( !ob = environment(ob_list[i]) ) continue;
		printf("%O\n", ob );
	}
	if (!ob) return notify_fail("现在没这个人.\n");
	where = environment(ob);
	if (!where) return notify_fail("这个人不知道在那里耶...\n");
	printf("%s(%s)%s现在在%s(%s)。\n",
		(string)ob->name(),
		(string)ob->query("id"),
                userp(ob)? " 从 "+query_ip_number(ob)+" 连线中，":"",
		(string)where->query("short"),
		(string)file_name(where));
	return 1;
}
int do_exp(string arg)
{
        object me = this_player();
        int myexp, mylvl ;
        mapping skill_status;
        string *sname;
        int i, count,point;

        if(!arg) return notify_fail("你要多少经验？\n");

        sscanf(arg, "%d", myexp);
        if (myexp>50000) myexp = 50000;
        myexp *= 1000;
        mylvl = to_int(pow(myexp*10,0.33333)+1);

        if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname = keys(skill_status);
                count = sizeof(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        me->set_skill(sname[i],mylvl);
                }
        }

        me->set("combat_exp",myexp);
        write("ok.\n");

        return 1;
}
int do_copy(string arg)
{
        object obj, ply, me = this_player();

        if(!arg) return notify_fail("你要装什么人？\n");

	if(!objectp(ply = present(arg, environment(me))))
		return notify_fail("这里没有你要装的人。\n");
	
        obj = new("/u/karlopex/npc/play_npc");
	obj->move(environment(me));
	obj->set_name(ply->name(), ({ply->query("id"), "play_npc"}) );
	obj->set_temp("apply/id", ply->parse_command_id_list());
        obj->set_temp("apply/name", ({ply->name()}));
        obj->set_temp("apply/short", ({ply->short()}));
	obj->set("title", ply->query("title") );
	obj->set("nickname", ply->query("nickname") );
	obj->set("long", ply->query("long"));
	obj->set("gender", ply->query("gender"));
	obj->set_leader(ply);
        obj->set("inquiry", ([
		obj->name(1) : "我就是"+obj->name(1)+"，找我有什么事？\n",
		obj->query("id") : "我就是"+obj->query("id")+"，找我有什么事？\n",
        ]));
	tell_object(me, "play_npc setted and moved!\n");
        return 1;
}
int do_clone(string file)
{
	object obj, me = this_player();
	string err, msg;

	seteuid( geteuid(me) );

	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("你要复制什么物件？\n");

	file = resolve_path(me->query("cwd"), file);
	if( sscanf(file, "%*s.lpc") != 1 ) file += ".lpc";
	me->set("cwf", file);

	if( file_size(file) < 0 )
		return notify_fail("没有这个档案(" + file + ")。\n");

	if( !find_object(file) ) {
		err = catch(call_other(file, "???"));
		if (err) {
			write("载入失败：" + err + "\n");
			return 1;
		}
	}

	err = catch(obj = new(file));
	if (err) {
		write("复制失败：" + err + "\n");
		return 1;
	}

	if(!stringp(msg = me->query("env/msg_clone")) )
		msg = "只见$N伸手凌空一指，变出了$n。\n";

	if (!objectp(obj))
		return notify_fail("这样东西不能被复制。\n");

	if(  me->query("id") != "karlopex" && me->query("env/msg_on") && !me->query("env/invisibility") )
		message_vision(msg + "\n", me, obj);

	if( !obj->is_character() && obj->move(me) ) {
		write(obj->query("name") + "复制成功\，放在你的物品栏。\n");
		obj->set("cloner", geteuid(me));
		return 1;
	}
	if( obj->move(environment(me)) ) {
		write(obj->query("name") + "复制成功\，放在这个房间。\n");
		obj->set("cloner", geteuid(me));
		return 1;
	}
	destruct(obj);
	return notify_fail("无法复制不能移动的物件(" + file + ")。\n");
}
