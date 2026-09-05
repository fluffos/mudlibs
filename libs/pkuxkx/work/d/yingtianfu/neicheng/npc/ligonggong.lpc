//Zine,低等太监

#include <ansi.h>
#include <title.h>
inherit NPC;

string ask_zhisi();

void create()
{
        set_name("李公公", ({"li gonggong", "li","tai jian", "jian","gonggong"}));
        set("title", HIW"大明 司礼监"NOR);
        set("long",
                "他是大明司礼监的低等太监，负责分配粗使之人的职务。\n"
        );

        set("gender", "无性");
        set("rank_info/respect", "公公");
        set("attitude", "peaceful");
        set("inquiry",([
                "职司"  : (: ask_zhisi :),
                "position" : (: ask_zhisi :),
        ]));

        set("age", 40);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("kar", 20);

        set("apply/attack",  30);
        set("apply/defense", 30);
        set("mingpin", 6);
		
				set("max_qi", 2800);
				set("eff_qi", 2800);
				set("qi", 2800);

				set("max_jing", 1800);
				set("eff_jing", 1800);
				set("jing", 1800);

				set("jingli", 3600);
				set("max_jingli", 3600);

				set("neili", 5600);
				set("max_neili", 5600);

				set("jiali", 150);

				set("combat_exp", 50000);
	
				set_skill("force", 250);
				set_skill("dodge", 220);
				set_skill("cuff", 220);
				set_skill("strike",220);

				set_skill("parry", 220);
				set_skill("blade",220);
				set_skill("sword",220);

        
        
        
        setup();
        
        add_money("silver", 10);
}




string ask_zhisi()
{
        object me;
        string title1;
        string *title=({"司苑局 佥书","酒醋面局 佥书","针工局 佥书","内织造局 佥书","巾帽局 佥书","浣衣局 监工",
            "银作局 佥书","兵仗局 管理","混堂司 监工","宝钞司 管理","钟鼓司 司房","惜薪司 佥书"});
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	    string color1=color[random(sizeof(color))];
        me = this_player();
        if (!me->query("ming/tj/pin"))
            return "你别假装是我大明内廷中人，我可精明着呢。";
        
        if (me->query("ming/tj/pin")<=7)
        {
            return "我只负责低等职司的分配，其他需要去司礼监分配。";
        }
        if (!me->query_temp("tj/finish"))
        {
            return "你还没完成杂役处的抄写宫规，我不能分配你具体职司，你赶紧去杂役处吧。";
        }
        title1=title[random(sizeof(title))];
        me->set("ming/title",title1+"太监");
        me->set("title",HIW+"大明 "+color1+title1+"太监"+NOR);
			  //title系统记录玩家title by seagate@pkuxkx
			  me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3}), HIW+"大明 "+color1+title1+"太监"+NOR, "大明");
		
				me->set("ming/tj/pin",7);
    		message("chat",HIW"【大明】内廷任命："+me->query("name")+HIW+"加入内廷后，勤快能干，晋升"+title1+"太监。\n"NOR,users());
        return color1+"你加入大明内廷，尚算勤勉，从今天起，你就是"+title1+"太监了。\n"NOR;
}



