//*************************************** find target ***************//
int do_ready()
{
        object ob = this_object();
        object *ulist, selected;
        string hostage_n,hostage_i,hostage_w,myfam;
        mapping npcgroup;
        int i, j;
        
        ulist = filter_array(objects(), (: userp :));
        ulist = filter_array(ulist, (: $1->query("combat_exp") > 1000000 && $1->query("shen") > 500000 && !$1->query_temp("be_saved") && !wizardp($1) :));

        if (1==1) {
//        if (sizeof(ulist) < 1 || random(sizeof(ulist)) < 10 || random(10) > 4) {
                npcgroup = npclist[random(sizeof(npclist))];
                hostage_n = npcgroup["name"];
                hostage_i = npcgroup["id"];
                hostage_w = npcgroup["where"];
                myfam = npcgroup["family"];
                ulist = objects( (: clonep :) );
                for (i=0;i<sizeof(ulist);i++)
                        if (ulist[i]->query("id") == hostage_i) {
                                tell_room(environment(ulist[i]),"突然，不知从什么地方冲出来几个魔教杀手，三拳两脚把" + hostage_n + "打倒后抬走了。\n");
                                ulist[i]->revive(1);
                                ulist[i]->reicarnate();
                                selected = ulist[i];
                                remove_call_out("do_check_where");
                                call_out("do_check_where", 1, ulist[i]);
                                break;
                        }
                if (!objectp(selected)) {
                        call_out("do_ready",1);
                        return 1;
                }
        }

// 从在线玩家中找出 exp > 1000000 ,+shen > 500000 的，然后随机抽出一个去监狱
        else {
		j = random(sizeof(ulist));
                message_vision("突然，不知从什么地方冲出来几个魔教杀手，三拳两脚把$N打倒后抬走了。\n",ulist[j]);
                hostage_n = ulist[j]->query("name");
                hostage_i = ulist[j]->query("id");
                hostage_w = base_name(environment(ulist[j]));
                myfam = ulist[j]->query("family/family_name");
                ulist[j]->set_temp("be_saved",1);
                ulist[j]->unconcious();
                selected = ulist[j];

                if (!objectp(selected)) {
                        call_out("do_ready",1);
                        return 1;
                }
        }
        selected->move(__HMY__"jail");
        selected->set("startroom", __HMY__"jail");
        selected->set_temp("hostage/where",hostage_w);
        ob->set("hostage/name",hostage_n);
        ob->set("hostage/id",hostage_i);
        ob->set("hostage/where",hostage_w);
        ob->set("hostage/family",myfam);
        ob->set("hostage/target",selected);
        ob->set("hostage/ready",1);
        call_out("do_fail", 1800, ob);
        return 1;
}

void do_check_where(object ob)
{
        object room;

        if (environment(ob) != (room = load_object(__HMY__"jail"))) {
                tell_room(environment(ob), HIR"\n突然从旁边冲出来了几个日月神教弟子，对着"+ob->name()+"HIR恶狠狠的说道：想跑？看你往哪里跑？\n\n"NOR);
                ob->move(room);
                remove_call_out("do_check_where");
                call_out("do_check_where", 1, ob);
                return;
        }
        remove_call_out("do_check_where");
        call_out("do_check_where", 1, ob);
}

//*************************************** give job 1 ***************//
int ask_renzhi()
{
        object me = this_object();
        object ob = this_player();
        object ob1, ob2;
        
        if (ob->query_condition("job_busy")) {
                command("say " + RANK_D->query_respect(ob) + "，您正忙着呢！");
                return 1;
        }

        if (ob->query_condition("hostage_busy")) {
                command("say " + RANK_D->query_respect(ob) + "，您刚营救过人质，辛苦您了。");
                return 1;
        }

        if (!me->query("hostage/ready") ) {
                command("say 我日月神教虽然身为魔教，但也不会随随便便抓正派人士的！");
                return 1;
        }
        if (me->query("hostage/gived") >= 2 ) {
                command("say 已经有人去救人了！");
                return 1;
        }
        
        if (base_name(environment(me)) != __HMY__"pingding/kefang") {
		command("say 你说什么呢？");
		return 1;
        }
        if (ob->query("combat_exp")<1500000) {
                command("say 救人质可是十分危险的，我看阁下似乎无此能力吧？");
                return 1;
        }
/*
        if (ob->query("shen")<0) {
                command("say 阁下面露凶光，恐怕是东方不败派来的吧？");
                return 1;
        }
*/

	command("say 现今东方不败将"HIY
                + me->query("hostage/family") + CYN"的"HIY
                + me->query("hostage/name") + "("
                + me->query("hostage/id") + ")"CYN"抓去做了人质，我们务必要想办法将他救出来。");

	if (me->query("hostage/gived") == 0) {
		me->set("pl1/name",ob->query("name"));
		me->set("pl1/id",ob->query("id"));
		me->set("hostage/gived", 1);
		command("say 此事危险非凡，现在只有你一个人，恐怕难以完成，你需要再找一个搭档！");
		return 1;
	}
    if (!(ob1 = present(me->query("pl1/id"),environment(me)))) {
        command("say 咦，"+me->query("pl1/name")+"("+me->query("pl1/id")+")怎么不见了？");
		me->set("hostage/gived", 1);
		me->set("pl1/name",ob->query("name"));
		me->set("pl1/id",ob->query("id"));
		command("say 那你再另找一个人搭档吧！");
		return 1;
	}
	if (ob == ob1) {
		command("? " + ob->query("id"));
		command("say 你怎么还不快去找搭档呀？！");
		return 1;
	}
        me->set("hostage/gived", 2);
        me->set("pl2/name",ob->query("name"));
	me->set("pl2/id",ob->query("id"));

// 任务随机
	ob2 = ob;
	if (random(2)) {
		ob2 = ob1;
		ob1 = ob;
	}

// to pl1
        ob1->set_temp("hostage/partner",ob2->query("id"));
        ob1->set_temp("hostage/hostage_n",me->query("hostage/name"));
        ob1->set_temp("hostage/hostage_i",me->query("hostage/id"));
        ob1->apply_condition("hostage1",40+random(20));
        ob1->apply_condition("hostage_busy",300);

// to pl2
        ob2->set_temp("hostage/partner",ob1->query("id"));
        ob2->set_temp("hostage/hostage_n",me->query_temp("hostage/name"));
        ob2->set_temp("hostage/hostage_i",me->query_temp("hostage/id"));
        ob2->apply_condition("hostage11",50+random(20));
        ob2->apply_condition("hostage_busy",300);

        
        command("say 此行我们的主要目的是要打探好黑木崖的虚实，然后再做定夺！");
        ob1->set_temp("hostage/job_1",1);
        command("whisper " + ob1->query("id") + " 你现在去找魔教长老童百雄，跟他打听打听东方不败的消息。");
        
        ob2->set_temp("hostage/job_1",2);
        command("whisper " + ob2->query("id") + " 你现在去问令狐冲把黑木令要来，我在这里等着。");

//make a log
        log_file("job/HMY_1",sprintf("%s %s(%s)[exp %d]和%s(%s)[exp %d]开始营救%s(%s)。\n", ctime(time())[4..19], ob1->name(1), ob1->query("id"), ob1->query("combat_exp"), 
        				ob2->name(1), ob2->query("id"), ob2->query("combat_exp"), me->query("hostage/name"), me->query("hostage/id")));
	remove_call_out("waiting");
	call_out("waiting", 600, me);
        return 1;
}

int waiting(object me)
{
        object one, two;

        one = find_player(me->query("pl1/id"));
        if (!one)
                one = find_living(me->query("pl1/id"));
        if (one) {
                one->delete_temp("hostage");
                one->apply_condition("hostage_busy",80+random(20));
        }
        two = find_player(me->query("pl2/id"));
        if (!two)
                two = find_living(me->query("pl2/id"));
        if (two) {
                two->delete_temp("hostage");
                two->apply_condition("hostage_busy",80+random(20));
        }
        me->set("hostage/gived",0);
        command("say 咦？"+me->query("pl1/name")+"("+me->query("pl1/id")+")和"
        	+me->query("pl1/name")+"("+me->query("pl1/id")+")怎么还不见回来？看来是凶多吉少了！");
        command("sigh");
	return 1;
}


//*************************************** job 2 ***************//
// 必须要完成job1        
int ask_jiuren()
{
        object me = this_object();
        object ob = this_player();
        object ob1, ob2;
        
        if (base_name(environment(me)) != __HMY__"pingding/kefang") {
		command("say 你说什么呢？");
		return 1;
        }
        
        if (me->query("hostage/gived") >= 4) {
                command("say 已经有人去救人了！");
                return 1;
        }

        if (me->query("hostage/gived") <= 2) {
                command("say 救人为快乐之本，但你是想要救什么人呢！？");
                return 1;
        }

        if (!me->query("hostage/ready") ) {
                command("say 你已经晚了，人质已经被旁人救走了！");
                return 1;
        }

        if (ob->query("combat_exp")<1500000) {
                command("say 救人质可是十分危险的，我看阁下似乎无此能力吧？");
                return 1;
        }
        if (ob->query("shen")<0) {
                command("say 阁下面露凶光，恐怕是东方不败派来的吧？");
                return 1;
        }

	if (me->query("pl1/id") == ob->query("id")) {
		ob1 = ob;
		if (!(ob2 == present(me->query("pl2/id"),environment(me)))) {
			command("咦，"+me->query("pl2/name")+"("+me->query("pl2/id")+")怎么不见了？");
			command("say 你再去找找他吧，我们的时间紧迫！");
			return 1;
		}
	}
	else if (me->query("pl2/id") == ob->query("id")) {
		ob2 = ob;
		if (!(ob1 == present(me->query("pl1/id"),environment(me)))) {
			command("咦，"+me->query("pl1/name")+"("+me->query("pl1/id")+")怎么不见了？");
			command("say 你再去找找他吧，我们的时间紧迫！");
			return 1;
		}
	}
	else {
		command("say 此事危险非凡，我正在等"+me->query("pl1/name")+"("+me->query("pl1/id")+")和"
       			+me->query("pl1/name")+"("+me->query("pl1/id")+")他们的消息！");
		return 1;
	}

// 任务随机	
	if (random(2)) {
		ob = ob1;
		ob1 = ob2;
		ob2 = ob;
	}

        ob1->apply_condition("hostage2",100 + random(20));
        ob2->apply_condition("hostage2",100 + random(20));
        
        me->set("hostage/gived",4);
        
        ob1->set_temp("hostage/job_2", 1);
        message_vision("$N低下头来，想了一会。\n",me);
        command("whisper " + ob1->query("id") + " 你现在去监狱杀掉看守，准备救"+ me->query("hostage/name") +"。");
        command("whisper " + ob1->query("id") + " 监狱的入口在后殿的墙上，推动(push)后就可以进去了。");
        
        ob2->set_temp("hostage/job_2", 2);
        command("whisper " + ob2->query("id") + " 你现在从这里去杨莲亭的书房找钥匙，小心点，别被他发现了。");
        command("say 好了，现在出发去营救" + me->query("hostage/family") + "的" + me->query("hostage/name") + "，我等着你们的好消息。");
//make a log
        log_file("job/HMY_2",sprintf("%s %s(%s)[exp %d]和%s(%s)[exp %d]开始营救%s(%s)。\n", ctime(time())[4..19], ob1->name(1), ob1->query("id"), ob1->query("combat_exp"), 
        				ob2->name(1), ob2->query("id"), ob2->query("combat_exp"), me->query("hostage/name"), me->query("hostage/id")));
	remove_call_out("waiting");
	call_out("waiting", 1000, me);

        return 1;
}

int do_fail(object me)
{
        object ob, room;
        object one, two;

        room = load_object(__HMY__"jail");
        ob = present(me->query("hostage/id"),room);
        if (!ob) {
                message_vision(CYN"$N自言自语道：原来" 
                + me->query("hostage/family") + "的"
                + me->query("hostage/name") + "已经被人救走了！\n"NOR,me);
                return 1;
        }
        tell_object(ob,"监狱大门突然打开了，走进来一个魔教杀手，将你放了出去。\n");
        ob->move(me->query("hostage/where"));
        tell_room(environment(ob),"几名魔教弟子押着" + ob->name() + "走了过来。\n",({ob}));
        message_vision(HIY"\n领头的转过身，横横的对$N说道：“教主有令今日暂且放你回来，以后决不轻饶！”说完哈哈大笑几声，快步离开了。\n"NOR,ob);

        if (me->query("hostage/pl1")) {
        one = find_player(me->query("hostage/pl1"));
        if (!one)
                one = find_living(me->query("hostage/pl1"));
        if (one) {
                one->delete_temp("hostage");
                one->apply_condition("hostage_busy",80+random(20));
        }
        }
        if (me->query("hostage/pl2")) {
        two = find_player(me->query("hostage/pl2"));
        if (!two)
                two = find_living(me->query("hostage/pl2"));
        if (two) {
                two->delete_temp("hostage");
                two->apply_condition("hostage_busy",80+random(20));
        }
        }

	me->delete("hostage");
        me->set("hostage/gived", 0);
        remove_call_out("do_check_where");
        remove_call_out("do_ready");
	call_out("do_ready", 900);
	return 1;
}

int do_letout()
{
        object obj,room,me = this_object(),ob = this_player();

        if (!wizardp(ob) && ob->query("id")!= "numa")
                return 1;
        if (!me->query("hostage/where") || !me->query("hostage/id")) {
                command("say 好象没有人质被抓走吧，即使你是巫师，也不能开这种玩笑呀！");
                command("kick numa");
                command("giggle");
                return 1;
        }
        room = load_object(__HMY__"jail");
        if (!objectp(obj = present(me->query("hostage/id"),room))) {
                command("say 好象已经被放出去了呀！");
                command("lean numa");
                return 1;
        }
        obj->move(obj->query_temp("hostage/where"));
        command("say "+ me->query("hostage/id") +"已经照您的吩咐放出去了。");
        if (userp(obj))
                tell_object(obj,GRN"任盈盈悄悄在你耳边说道：是驽马让我放你出去的，快点走吧，别再被抓住了！\n"NOR);
        message_vision(HIY"突然，一阵狂风刮起，$N骤然出现在这里，样子呆呆傻傻，可能是被吓坏了。\n"NOR,obj);
        return 1;
}
