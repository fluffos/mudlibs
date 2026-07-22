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
/*
int accept_object(object who, object ob,object me)
{
	mapping fam, my_fam, skl; 
        object fighter,room, monk;
	string *sname;
	int i,j;
        my_fam  = fighter->query("family");
	skl = fighter->query_skills();
	sname  = keys(skl);
	fighter = this_player();
        //me = this_object();
        if(!who->query_temp("baitie")){
                command("say 你的拜贴是那来的，别人转赐老衲恕不接待！");
                return 1;
	}
        if(ob->query("name")=="拜贴"){
        if (!(fam = this_player()->query("family")) 
           || fam["family_name"] != "少林派"){
                command("angry "+who->query("id"));
                command("say 好啊，你公然挑战我派，老衲让你知道厉害！");
                command("follow"+who->query("id"));
                command("kill"+who->query("id"));
        return 1;
        }
          command("hmm"+this_player()->query("id"));
          for(i=0; i<sizeof(skl); i++) {
                if (skl[sname[i]] < 120) 
        return notify_fail((RANK_D->query_respect(this_player())) +
                "功力不够，不可轻试。");
                }

        if(fighter->query("pass_du"))
         return notify_fail(RANK_D->query_respect(fighter)+
                "大师是三长老的及门高弟，何必再入心禅堂?\n");
        if( fighter->query("pass_xin") )
		return notify_fail(RANK_D->query_respect(fighter) + 
		"已是堂内高僧，可不要拿老衲开这等玩笑。");

	if ( mapp(fam = fighter->query("family")) 
	&& fam["family_name"] == "少林派"
	&& fam["generation"] != (my_fam["generation"] + 3))
		return notify_fail(RANK_D->query_respect(fighter) + 
		"辈份不合，不够资格入堂修行。");

        if ( (int)fighter->query("guilty") > 0 )
		return notify_fail(RANK_D->query_respect(fighter) + 
                "你累犯数戒，身带重罪，还是先回去忏悔吧！\n");

/*        if ( me->query("assigned_fighter") )
		return notify_fail(RANK_D->query_respect(fighter) + 
		"今日已有人挑战石人大阵，你过一段时间再来吧。");
         command("say 当年昆仑三圣何足道挑我少林，寺中高手无一是其敌手
                      连心禅七老都大受挫折。");
         command("say 此后他们苦练绝技，终身以抱负为念，使此等七位大智慧
                      的长老终不能成我佛家高僧大贤。");
         command("say 所以入这心禅堂也实是我少林凶险之处，虽也有不少高僧大
                      贤，可以入内清修。但我佛家首推禅理，武功乃是末节"+
                      RANK_D->query_respect(this_player()) +"何必定要冒此大险？
                      望你自决。");
	say("\n慧云说道：好吧，我来启动石阵机关，你决定好就化地为局(huadi)准备入阵吧。\n");
	me->set("assigned_fighter", fighter->query("id")); 		
	//if( !fighter->query_temp("xuannan-asked") )
	//say("\n玄苦又道：请你速去告知般若堂玄难大师，请他即刻招集般若堂诸罗汉于西练武场集合。\n");
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
			return notify_fail("真是对不起，石亭中有石人丢窃，没法举行大阵了。\n");	
		}

                message("vision", "\n慧云大师走了过来，在" + monk->query("name") + "背后轻击一掌。\n", room, monk);

                monk->move("/d/shaolin/hguangz1");
                message("vision", monk->query("name") + "快步走了出去。\n", room, monk);
	}
	
        me->move("/d/shaolin/xcping");

        call_out("waiting", 1, me);
        command("nod"+fighter->query("id"));
        return 1;
} */

