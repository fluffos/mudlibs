// xuan-nan.h for fight and get letter from Xuan

#include <ansi.h>

string* names = ({
	"chengxin luohan",
	"chengyi luohan",
	"chengsi luohan",
	"chengshi luohan",
	"chengzhi luohan",
	"chengxin luohan",
	"chengling luohan",
	"chengyu luohan",
	"chengshang luohan",
});

void preparing(object, object);

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
        if (mapp(skl)) sname  = keys(skl);

	if( fighter->query("luohan_winner") )
		return RANK_D->query_respect(fighter) + 
		"已然闯过罗汉大阵，可不要拿老衲开这等玩笑。";

	for(i=0; i<sizeof(skl); i++) {
		if (skl[sname[i]] < 80 && sname[i] != "medicine") 
		return RANK_D->query_respect(fighter) + 
		"功力不够，不够资格闯罗汉大阵。";
	}

	if ( mapp(fam = fighter->query("family")) 
	&& fam["family_name"] == "少林派"
	&& fam["generation"] != (my_fam["generation"] + 2))
		return RANK_D->query_respect(fighter) + 
		"辈份不合，不够资格闯罗汉大阵。";

        if ( (int)fighter->query("guilty") > 0 )
		return RANK_D->query_respect(fighter) + 
		"你累犯数戒，身带重罪，我如何能准许你闯罗汉大阵！";

	if ( me->query("assigned_fighter") )
		return RANK_D->query_respect(fighter) + 
		"，今日已有人挑战罗汉大阵，你过一段时间再来吧。";

	fighter->set_temp("xuannan-asked", 1);

	say("\n玄难说道：好吧，我来召集般若堂长老们于东练武场集合，我稍候在中央练武场上等你。\n");

	me->set("assigned_fighter", fighter->query("id")); 		
	
	if( !fighter->query_temp("xuanku-asked") )
	say("\n玄难又道：请你速去告知罗汉堂玄苦大师，请他即刻招集般若堂诸罗汉于西练武场集合。\n");

        message_vision("\n玄难大师往东离开。\n\n", fighter);

        for(j=1; j<10; j++) 
	{
                if(!( room = find_object("/d/shaolin/banruo" + j)) )
                room = load_object("/d/shaolin/banruo" + j);
                
  		me->move(room);
                
		if( !objectp(monk = present(names[j-1], room) ))
		{
	        	me->move("/d/shaolin/brtang");
                        me->delete("assigned_fighter");
        	        message_vision("\n玄难大师走了过来。\n\n", fighter);
                        return "真是对不起，般若堂中有人不在，无法举行罗汉大阵。\n";
		}

                message("vision", "\n玄难大师走了过来，跟" + monk->query("name") + "俯耳轻声说了几句。\n", room, monk);

                monk->move("/d/shaolin/hguangz3");
                message("vision", monk->name() + "罗汉点了点头，快步走了出去。\n", room, monk);
	}
	
        me->delete("startroom");
        me->move("/d/shaolin/hguangz2");

        call_out("waiting", 1, me, 0);

	return "好！大家都出来了。\n";
}

void waiting(object me, int wait_time)
{
	object fighter;

        if( wait_time >= 300 )
	{
		say( "玄难说道：看来他不会来了，我们回去罢！\n\n");
                call_out("do_back", 1, me);
		return;
	}

	if( !objectp( fighter = present( me->query("assigned_fighter"), environment(me) ) ) )
	{
                call_out("waiting", 1, me, wait_time + 1);
		return;
	}
	if( !present("xuanku dashi", environment(me)) || !fighter->query_temp("xuanku-asked") )
	{
		if( random(10) == 0 ) 
		say("\n玄难说道：" + RANK_D->query_respect(fighter) + "去请了玄苦大师没有？ 照理他现在该到了罢？\n");

                call_out("waiting", 1, me, wait_time + 1);
		return;
	}
	preparing(me, fighter);
}

void preparing(object me, object fighter)
{
	object monk, room, ob;

	if(!( room = find_object("/d/shaolin/hguangz2")) )
	room = load_object("/d/shaolin/hguangz2");

	say( "玄难说道：不相干的人，如不欲现场观摩罗汉大阵，请即刻离开此处。\n");

	message("vision", HIY "\n玄难大师大声宣布：西罗汉大阵合围！\n\n" NOR, room);
        command("chat " + fighter->query_family() + fighter->name() + "于今日" +
                NATURE_D->game_time() + "挑战少林十八罗汉大阵！\n");

	fighter->delete_temp("xuanku-asked");
	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);

        call_out("fighting",  4, me, fighter, 0);
}

void fighting(object me, object fighter, int count)
{
	object monk1, monk2, room1, room2;

	if(!( room1 = find_object("/d/shaolin/hguangz3")) )
	room1 = load_object("/d/shaolin/hguangz3");

	if(!( room2 = find_object("/d/shaolin/hguangz2")) )
	room2 = load_object("/d/shaolin/hguangz2");

	if( count <= 8 ) {
		message("vision", "\n罗汉大阵急速地旋转着，一层层地向内收紧！\n" NOR, room2);

		monk1 = present(names[count], room1);
		monk1->move(room2);
	}
		
	if( count >= 1 && count <= 9 ) {
		monk2 = present(names[count-1], room2);
		monk2->move(room1);
	}

	if (!fighter || !living(fighter) || environment(fighter)!=environment(me))
	{
		if( objectp(fighter) ) {
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		monk1->move(room1);

                command("chat* 说道：可惜呀... 唉！");
		command("sigh");
                call_out("do_back", 6, me );
	}
	else if( count >= 9 )
	{
		if( (int)fighter->query_temp("beat_count") >= 18 )	
                        call_out("do_recruit", 3, me, fighter);
		else
                        call_out("do_back", 6, me );
	}
	else
	{
		count++;
		call_out("fighting", 2, me, fighter, count);
	}
}

void do_recruit(object me, object fighter)
{
	mapping ft_fam, my_fam;

	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
	fighter->add("combat_exp", 7500);
	fighter->set("luohan_winner", 1);

	if (!(ft_fam = fighter->query("family")) || ft_fam["family_name"] != "少林派")
	{
		command("smile");
		say("玄难说道：" + RANK_D->query_respect(fighter) + "武功卓绝，兼又手下留情，品德更是过人一筹，老衲不胜佩服之至！\n\n");
                 call_out("do_back", 6, me );
	}
	else
	{
	        say("\n玄难说道：好，好，好！" + fighter->query("name") + "，你愿意拜我等为师吗？\n\n");
                 call_out("do_back", 31, me );
	}
}

void do_back(object me)
{
        object monk, room1, room2;
	int i;

	message("vision", "\n玄难大师也挥了挥手， 般若堂长老们随即也离开练武场。\n", environment(me) );
	
        if(!( room1 = find_object("/d/shaolin/hguangz2")) )
        room1 = load_object("/d/shaolin/hguangz2");

        room1->set("exits/east",  "/d/shaolin/hguangz3");
        room1->set("exits/west",  "/d/shaolin/hguangz1"   );
        room1->set("exits/south", "/d/shaolin/dabeidia" );

        if(!( room1 = find_object("/d/shaolin/hguangz3")) )
        room1 = load_object("/d/shaolin/hguangz3");

	for(i=1; i<10; i++) 
	{
                if(!( room2 = find_object("/d/shaolin/banruo" + i)) )
                room2 = load_object("/d/shaolin/banruo" + i);

                if( objectp( monk = present(names[i-1], room1) ))
	                monk->move(room2);
	}

        me->delete("assigned_fighter");
	
	me->move("/d/shaolin/brtang");
        me->set("startroom", "/d/shaolin/brtang");
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
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] < my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"]))
	{
		command("nod");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "澄")
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎么跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query("luohan_winner") )
		{
			command("say 老衲垂死之年，又得一可塑之才，真是可喜可贺 !");

			name = ob->query("name");
			new_name = "澄" + name[2..3];
			ob->set("name", new_name);
	
			command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派澄字辈罗汉之一 !");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "，你没有闯过十八罗汉大阵，不能越级拜师。");
		}
	}
}
