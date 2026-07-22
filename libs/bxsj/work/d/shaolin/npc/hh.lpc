#include <ansi.h>
string* names = ({
        "juechan shiren",
        "bichan shiren",
        "kuchan shiren",
        "kongchan shiren",
        "jichan shiren",
        "liaochan shiren",
        "mingchan shiren",
});
string ask_me()
{
	mapping fam, my_fam, skl; 
        object me,fighter,room, monk;
	string *sname;
	int i,j;
        my_fam  = fighter->query("family");
	skl = fighter->query_skills();
	sname  = keys(skl);
	fighter = this_player();
       if(!fighter->query_temp("try"))
          return "你问我这个干吗?\n";
       command("hmm"+this_player()->query("id"));
          for(i=0; i<sizeof(skl); i++) {
           if (skl[sname[i]] < 120) 
        return (RANK_D->query_respect(this_player()) +
                "功力不够，不可轻试。");
             } 
        if(fighter->query("pass_du"))
         return (RANK_D->query_respect(fighter)+
                "大师是三长老的及门高弟，何必再入心禅堂?\n");
        if( fighter->query("pass_xin") )
		return (RANK_D->query_respect(fighter) + 
		"已是堂内高僧，可不要拿老衲开这等玩笑。");

	if ( mapp(fam = fighter->query("family")) 
	&& fam["family_name"] == "少林派"
	&& fam["generation"] != (my_fam["generation"] + 3))
		return (RANK_D->query_respect(fighter) + 
		"辈份不合，不够资格入堂修行。");

        if ( (int)fighter->query("guilty") > 0 )
		return (RANK_D->query_respect(fighter) + 
                "你累犯数戒，身带重罪，还是先回去忏悔吧！\n");
	say("\n慧云说道：好吧，我来启动石阵机关，你决定好就化地为局(huadi)准备入阵吧。\n");
	me->set("assigned_fighter", fighter->query("id")); 		
        message_vision("\n慧云大师急步离开。\n\n", fighter);
       for(j=1; j<8; j++) 
	{
                if(!( room = find_object("/u/hunthu/shiting" + j)) )
                room = load_object("/u/hunthu/shiting" + j);
  		me->move(room);
		if( !objectp(monk = present(names[j-1], room) ))
		{
	        	me->move("/d/shaolin/xcping");
        	        message_vision("\n慧云禅师走了过来。\n\n", fighter);
                        return "真是对不起，石亭中有石人丢窃，没法举行大阵了。\n"; 
		}
                message("vision", "\n慧云大师走了过来，在" + monk->query("name") + "背后轻击一掌。\n", room, monk);
                monk->move("/u/hunthu/xctang");
                message("vision", monk->query("name") + "快步走了出去。\n", room, monk);
	}

        me->move("/d/shaolin/xcping");
        call_out("waiting", 1, me);
	return ("好！大家都出来了。\n");
 
}

void waiting(object me)
{
	object fighter;
	int wait_time;

	if( wait_time == 300 )
	{
		say( "慧云说道：你比猪还慢，不等你了！\n\n");
		call_out("do_back", 0, me);		
	}

	if( !objectp( fighter = present( me->query("assigned_fighter"), environment(me) ) ) )
	{
		wait_time++;
		call_out("waiting", 1, me);
	}
	else if(!fighter->query_temp("huadi") )
	{
		if( random(10) == 0 ) 
		say("\n慧云说道：" + RANK_D->query_respect(fighter) + "你化地为局了吗？快点吧！\n");

		wait_time++;
		call_out("waiting", 1, me);
	}
	else call_out("preparing", 1, me, fighter);

        return;
}

int preparing(object me, object fighter)
{
	object monk, room, ob;

	if(!( room = find_object("/d/shaolin/xcping")) )
	room = load_object("/d/shaolin/xcping");
//	monk = present("mu ren", room);
//	monk->move("/d/shaolin/houdian");

	if(!( room = find_object("/u/hunthu/shifang")) )
	room = load_object("/u/hunthu/shifang");
//	monk = present("mu ren", room);
//	monk->move("/d/shaolin/houdian");

//	if(!( room = find_object("/d/shaolin/hguangz2")) )
//	room = load_object("/d/shaolin/hguangz2");

//	monk = present("daojue chanshi", room);
//	message("vision", "玄苦大师跟道觉禅师俯耳轻声说了几句。\n", room, monk );
//	monk->move("/d/shaolin/houdian");
//	message("vision", monk->query("name") + "禅师点了点头，快步往北离开。\n", room);

	message("vision", HIY "\n慧云大师大声宣布：心禅石人大阵启动！\n" NOR, room);
	message("vision", "\n只听一阵机关声响，七个面无表情的石人堵住了通路。\n\n", room);
	room->delete("exits");
      	command("chat " + fighter->query("title") + fighter->query("name") + 
	"于今日" + NATURE_D->game_time() + "挑战心禅堂七老大阵！\n");
       fighter->delete_temp("baitie");
	fighter->delete_temp("huadi");
	fighter->delete_temp("beat_count");
       fighter->set_temp("fighting", 1);
	call_out("fighting",  8, me, fighter, 0);
	return 1;
}

int fighting(object me, object fighter, int count)
{
	object monk1, monk2, room1, room2;
        if(!( room1 = find_object("/d/shaolin/xcping")) )
	room1 = load_object("/d/shaolin/xcping");
        if(!( room2 = find_object("/u/hunthu/xctang")) )
	room2 = load_object("/u/hunthu/xctang");
        //	message_vision(HIY "xuanku's count = " + count + "\n" NOR, fighter);

	if( count <= 8 ) {
		message("vision", "\n石人各踏九宫八卦方位，缓缓而来！\n" NOR, room2);

		monk1 = present(names[count], room1);
		monk1->move(room2);
	}
		
	if( count >= 1 && count <= 8 ) {
		monk2 = present(names[count-1], room2);
		monk2->move(room1);
	}

	if (!living(fighter) || environment(fighter)!=environment(me))
	{
		if( objectp(fighter)) {
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		monk1->move(room1);

		say( "慧云摇了摇头，说道：我说不可轻试吧！\n\n");
		command("sigh");
              command("chat"+ "*"+ "disapp");
        	call_out("do_back", 5, me );
	}
	else if( count >= 8 )
	{
		if( (int)fighter->query_temp("beat_count") >= 8 )	
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
	fighter->add("combat_exp", 30000);
	fighter->set("pass_xin", 1);
	say("\n慧云说道：恭喜你闯过了心禅大阵！ 心禅堂又多一高僧！\n");
       command("chat"+"*"+"praise"+fighter->query("id"));	
	call_out("do_back", 5, me );
        return 1;
        }
int do_back(object me)
{
        object monk, room1, room2;
	int i;

	message("vision", "\n慧云大师按动机关， 石人们随即鱼贯离开。\n", environment(me) );
	
        if(!( room1 = find_object("/u/hunthu/xctang")) )
        room1 = load_object("/u/hunthu/xctang");
 //       if(!( room2 = find_object("/d/shaolin/xcping")) )
 //       room2 = load_object("/d/shaolin/xcping");
//        monk = present("daojue chanshi", room2);
//	monk->move("/d/shaolin/hguangz2");
//        monk = present("mu ren", room2);
//	monk->move("/d/shaolin/wuchang2");
//        monk = present("mu ren", room2);
//      monk->move("/d/shaolin/wuchang1");

     //   if(!( room1 = find_object("/d/shaolin/xcping")) )
       // room1 = load_object("/d/shaolin/xcping");

	for(i=1; i<8; i++) 
	{
                if(!( room2 = find_object("/u/hunthu/shiting" + i)) )
                room2 = load_object("/u/hunthu/shiting" + i);
                if( objectp( monk = present(names[i-1], room1) ));
	                monk->move(room2);
	}

        me->delete("assigned_fighter");
	
	me->move("/d/shaolin/xcping");

	return 1;
} 

