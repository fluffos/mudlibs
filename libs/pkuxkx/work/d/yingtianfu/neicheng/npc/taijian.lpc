// hai.c 海公公
// Jay 4/6/96
//Redesign for Dongchang by Vast on 3/27/2009

#include <ansi.h>
#include <title.h>
inherit NPC;

int advtise();
string ask_for_zigong();

void create()
{
        set_name("少监", ({"shao jian", "shaojian", "jian","gonggong"}));
        set("title", HIW"大明 司礼监"NOR);
        set("long",
                "他是大明司礼监的少监，奉旨出来招募些粗使之人。\n"
        );

        set("gender", "无性");
        set("rank_info/respect", "公公");
        set("attitude", "peaceful");
        set("inquiry",([
                "入宫"  : (: ask_for_zigong :),
                "join"  : (: ask_for_zigong :),
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

        
        
        set("chat_chance", 15);
        set("chat_msg", ({
                (: advtise :),
        }) );

        setup();
        
        add_money("silver", 10);
        call_out("dest",7200);
}

int dest()
{
    destruct(this_object());
    return 1;
}

void init()
{
        add_action("do_decide", "decide");
}

int advtise()
{
    object room;
    if (environment(this_object())&& random(100)>95)
    {
        room=environment(this_object());
        if (room)
        {
            CHANNEL_D->do_channel(this_object(), "jh", "大明内廷招募粗使之人，请有意者来"+TASK_D->place_belong(room)+room->query("short")+"报名。");
        }
        
    }
        
}

string ask_for_zigong()
{
        object me;

        me = this_player();
        
        if(me->query("class") == "officer")
        	return "你乃女真的官员，想混进我国内廷吗......";
        if (me->query("family/family_name")=="朝廷")
            return "你乃女真的官员，想混进我国内廷吗......";
        if (me->query("ming/tj/pin"))
            return "公公莫非给我开玩笑，我昨天在宫里还见着公公的。";
        if( (string)me->query("gender")=="无性" )
        {
            tell_object(me,"这倒是巧了，原来阁下也是位无鸟之人，倒可省了一刀。\n");
        }

        if( (string)me->query("gender") == "女性" )
                return "这年头什么稀奇事都有，好好的大姑娘也要来当太监？";

        me->set_temp("pending/zigong", 1);
        return "入宫？你可想清楚了，鸟去不能复生，你若决心已定(decide)，我也不拦你。";
}



int do_decide()
{
        object me=this_player();
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
        string color2=color[random(sizeof(color))];
        if( !this_player()->query_temp("pending/zigong") )
                return 0;
        
        me->set("title",HIW+"大明 "+color2+"杂役太监"+NOR);

			  me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3}), HIW+"大明 "+color2+"杂役太监"+NOR, "大明");					

        me->set("ming/tj/pin",8);
        if (me->query("gender")=="无性")
        {
            message_vision("$N道：你直接去承天门找李公公就好了。\n",this_object());
            message_vision("$N道：记住，入宫后须服三天杂役才可分配任务，离宫。\n",this_object());
            return 1;
        }
        message_vision(
                "$N将$n带至身后小房间。\n\n"
                "$N唤出两个小太监按住$n双手，褪下$n的中衣，挥刀而下……\n\n"
                "$n顿时惨叫一声昏了过去……\n\n",
                this_object(), this_player() );
        CHANNEL_D->do_channel(this_object(), "jh", "这世上又多了一个落魄的丢鸟之人啊……");
        
        this_player()->delete_temp("pending/zigong");
        this_player()->set("gender","无性");
        this_player()->set("combat_exp",this_player()->query("combat_exp")+1000);
        this_player()->unconcious();
        this_player()->move("/d/yingtianfu/neicheng/zayichu");
        return 1;
}

