// xuan-ku.h for fight and get letter from Xuan

#include <ansi.h>

string* names = ({
	"chengguan luohan",
	"chengzhi luohan",
	"chengming luohan",
	"chengjing luohan",
	"chengjian luohan",
	"chengxing luohan",
	"chengji luohan",
	"chengmie luohan",
	"chenghe luohan",
});

string ask_me()
{
	mapping fam, my_fam, skl; 
        object fighter, me, room, monk;
	string *sname;
	int i,j;

	fighter = this_player();
	me = this_object();
	my_fam  = me->query("family");

	skl = fighter->query_skills();
	sname  = keys(skl);

	for(i=0; i<sizeof(skl); i++) {
		if (skl[sname[i]] < 80) 
		return RANK_D->query_respect(fighter) + 
		"功力不夠，不夠資格闖羅漢大陣。";
	}

	if( fighter->query("luohan_winner") )
		return RANK_D->query_respect(fighter) + 
		"已然闖過羅漢大陣，可不要拿老衲開這等玩笑。";

	if ( mapp(fam = fighter->query("family")) 
	&& fam["family_name"] == "少林派"
	&& fam["generation"] != (my_fam["generation"] + 2))
		return RANK_D->query_respect(fighter) + 
		"輩份不合，不夠資格闖羅漢大陣。";

        if ( (int)fighter->query("guilty") > 0 )
		return RANK_D->query_respect(fighter) + 
		"你累犯數戒，身帶重罪，我如何能准許你闖羅漢大陣！";

	if ( me->query("assigned_fighter") )
		return RANK_D->query_respect(fighter) + 
		"，今日已有人挑戰羅漢大陣，你過一段時間再來吧。";

	fighter->set_temp("xuanku-asked", 1);

	say("\n玄苦說道：好吧，我來召集羅漢堂長老們于東練武場集合，我稍候在中央練武場上等你。\n");

	me->set("assigned_fighter", fighter->query("id")); 		
	
	if( !fighter->query_temp("xuannan-asked") )
	say("\n玄苦又道：請你速去告知般若堂玄難大師，請他即刻招集般若堂諸羅漢于西練武場集合。\n");

        message_vision("\n玄苦大師往南離開。\n\n", fighter);

        for(j=1; j<10; j++) 
	{
                if(!( room = find_object("/d/shaolin/luohan" + j)) )
                room = load_object("/d/shaolin/luohan" + j);
                
  		me->move(room);
                
		if( !objectp(monk = present(names[j-1], room) ))
		{
	        	me->move("/d/shaolin/luohan5");
        	        message_vision("\n玄苦大師走了過來。\n\n", fighter);
			return "真是對不起，羅漢堂中有人不在，無法舉行羅漢大陣。\n";	
		}

                message("vision", "\n玄苦大師走了過來，跟" + monk->query("name") + "俯耳輕聲說了几句。\n", room, monk);

                monk->move("/d/shaolin/wuchang2");
                message("vision", monk->query("name") + "羅漢點了點頭，快步走了出去。\n", room, monk);
	}
	
        me->move("/d/shaolin/wuchang");

        call_out("waiting", 1, me);

	return "好！大家都出來了。\n";
}

int waiting(object me)
{
	object fighter;
	int wait_time;

	if( wait_time == 300 )
	{
		say( "玄苦說道：看來他不會來了，我們回去罷！\n\n");
		call_out("do_back", 0, me);		
	}

	if( !objectp( fighter = present( me->query("assigned_fighter"), environment(me) ) ) )
	{
		wait_time++;
		call_out("waiting", 1, me);
	}
	else if( !present("xuannan dashi", environment(me)) || !fighter->query_temp("xuannan-asked") )
	{
		if( random(10) == 0 ) 
		say("\n玄苦說道：" + RANK_D->query_respect(fighter) + "去請了玄難大師沒有？ 照理他現在該到了罷？\n");

		wait_time++;
		call_out("waiting", 1, me);
	}
	else 	call_out("preparing", 1, me, fighter);

	return 1;
}

int preparing(object me, object fighter)
{
	object monk, room, ob;

	if(!( room = find_object("/d/shaolin/wuchang2")) )
	room = load_object("/d/shaolin/wuchang2");
	monk = present("mu ren", room);
	monk->move("/d/shaolin/houdian");

	if(!( room = find_object("/d/shaolin/wuchang1")) )
	room = load_object("/d/shaolin/wuchang1");
	monk = present("mu ren", room);
	monk->move("/d/shaolin/houdian");

	if(!( room = find_object("/d/shaolin/wuchang")) )
	room = load_object("/d/shaolin/wuchang");

	monk = present("daojue chanshi", room);
	message("vision", "玄苦大師跟道覺禪師俯耳輕聲說了几句。\n", room, monk );
	monk->move("/d/shaolin/houdian");
	message("vision", monk->query("name") + "禪師點了點頭，快步往北離開。\n", room);

	message("vision", HIY "\n玄苦大師大聲宣布：東羅漢大陣合圍！\n" NOR, room);
	message("vision", "\n只聽四周響起沙沙的腳步聲，東西十八位羅漢們個個神情肅殺，\n"
		"或赤手空拳，或手持兵器，慢慢地圍了上來，堵住了通路。\n\n", room);
	room->delete("exits");

	say( "玄苦又道：准備，羅漢大陣即刻發動！\n\n");

	fighter->delete_temp("xuanku-asked");
	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);

	call_out("fighting",  10, me, fighter, 0);

	return 1;
}

int fighting(object me, object fighter, int count)
{
	object monk1, monk2, room1, room2;

	if(!( room1 = find_object("/d/shaolin/wuchang2")) )
	room1 = load_object("/d/shaolin/wuchang2");

	if(!( room2 = find_object("/d/shaolin/wuchang")) )
	room2 = load_object("/d/shaolin/wuchang");

//	message_vision(HIY "xuanku's count = " + count + "\n" NOR, fighter);

	if( count <= 8 ) {
		message("vision", "\n羅漢大陣急速地旋轉著，一層層地向內收緊！\n" NOR, room2);

		monk1 = present(names[count], room1);
		monk1->move(room2);
	}
		
	if( count >= 1 && count <= 9 ) {
		monk2 = present(names[count-1], room2);
		monk2->move(room1);
	}

	if( !find_player(me->query("assigned_fighter")) ||
	!living(fighter) || fighter->query("qi") <= 1 )
	{
		if( objectp(present(me->query("assigned_fighter"), environment(me)) )) {
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		monk1->move(room1);

		say( "玄苦搖了搖頭，說道：想不到 ... 唉！\n\n");
		command("sigh");
		call_out("do_back", 5, me );
	}
	else if( count >= 9 )
	{
		if( (int)fighter->query_temp("beat_count") >= 18 )	
			call_out("do_recruit", 5, me, fighter);
		else
			call_out("do_back", 5, me );
	}
	else
	{
		count++;
		call_out("fighting", 2, me, fighter, count);
	}
 
	return 1;
}

int do_recruit(object me, object fighter)
{
	mapping ft_fam, my_fam;

	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
	fighter->add("combat_exp", 7500);
	fighter->set("luohan_winner", 1);

	if (!(ft_fam = fighter->query("family")) || ft_fam["family_name"] != "少林派")
	{
		command("bow");
		say("玄苦說道：" + RANK_D->query_respect(fighter) + "此番過陣，當對本身修行大有助益，百尺竿頭，更進一步，老衲就此別過！\n");
		call_out("do_back", 5, me );
	}
	else
	{
		say("\n玄苦說道：恭喜你闖過了十八羅漢大陣！ 本寺有此等杰出弟子，屆時必當為武林放一異彩！\n");
		call_out("do_back", 30, me );
	}

		
	return 1;
}

int do_back(object me)
{
        object monk, room1, room2;
	int i;

	message("vision", "\n玄苦大師揮了揮手， 羅漢堂長老們隨即魚貫離開練武場。\n", environment(me) );
	
        if(!( room1 = find_object("/d/shaolin/wuchang")) )
        room1 = load_object("/d/shaolin/wuchang");

        if(!( room2 = find_object("/d/shaolin/houdian")) )
        room2 = load_object("/d/shaolin/houdian");

        monk = present("daojue chanshi", room2);
	monk->move("/d/shaolin/wuchang");
        monk = present("mu ren", room2);
	monk->move("/d/shaolin/wuchang2");
        monk = present("mu ren", room2);
	monk->move("/d/shaolin/wuchang1");

        if(!( room1 = find_object("/d/shaolin/wuchang2")) )
        room1 = load_object("/d/shaolin/wuchang2");

	for(i=1; i<10; i++) 
	{
                if(!( room2 = find_object("/d/shaolin/luohan" + i)) )
                room2 = load_object("/d/shaolin/luohan" + i);

                if( objectp( monk = present(names[i-1], room1) ));
	                monk->move(room2);
	}

        me->delete("assigned_fighter");
	
	me->move("/d/shaolin/luohan5");

	return 1;
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "與本派素無來往，不知此話從何談起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺內學藝。");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，貧僧哪里敢當 !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "澄")
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麼跑到我這兒來了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query("luohan_winner") )
		{	
			command("say 老衲垂死之年，又得一可塑之才，真是可喜可賀 !");

			name = ob->query("name");
			new_name = "澄" + name[2..3];
			ob->set("name", new_name);
	
			command("say 從今以后你的法名叫做" + new_name + "，恭喜你榮升為少林派澄字輩羅漢之一 !");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "，你沒有闖過十八羅漢大陣，不能越級拜師。");
			return;
		}
	}

	return;
}
