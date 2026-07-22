// Npc: /d/tianshan/npc/nvtong.c
// By Linux

#include <ansi.h>
inherit NPC;
int ask_tong1();

void create()
{
        set_name("女童", ({"nv tong", "tong", "girl"}));
        set("gender", "女性");
        set("per",25);
        set("age", 8);
        set("long", 
                "这人身形矮小，年纪约莫有八九岁，但双目如电，炯炯有神，向你瞧来之\n"
                "时，自有一股凌人的威严。\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 35);
        set("con", 40);
        set("dex", 40);

        set("inquiry", ([
                "童姥" : (: ask_tong1 :),
                "天山童姥" : (: ask_tong1 :),
                "name" : (: ask_tong1 :),
        ]));

        set("qi", 8000);
        set("max_qi", 8000);
        set("jing", 4000);
        set("max_jing", 4000);
        set("neili", 9600);
        set("max_neili", 9600);
        set("eff_jingli", 4500);
        set("jiali", 100);
        set("combat_exp",4000000);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("hand",300);
        set_skill("strike", 300);
        set_skill("sword",300);

        set_skill("zhemei-shou",300);          //逍遥折梅手(hand)
        set_skill("liuyang-zhang",300);        //天山六阳掌(strike)(unarmed)
        set_skill("pinxu-lingfeng",300);       //凭虚临风(dodge)
        set_skill("bahuang-gong", 300);        //八荒六合唯我独尊功(force)
	set_skill("tianshan-jianfa", 300);     //天山剑法(sword)
	set_skill("literate", 160);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "pinxu-lingfeng");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianshan-jianfa");
        prepare_skill("hand","zhemei-shou");
        prepare_skill("strike","liuyang-zhang");

        create_family("灵鹫宫",1, "开山祖师");
	setup();

        carry_object(MISC_D("cloth"))->wear();   
}

void init()
{
        add_action("do_ketou", "ketou");
}

int ask_tong1()
{
        object me=this_player(),ob=this_object();
        if (me->query_temp("tonglao/pass3")){
                command ("haha");
                message_vision(CYN"$N说道：算你这"+ RANK_D->query_rude(me) +"有眼光。见了长辈也不行礼，这般没规矩。\n"
                        "若不是念在你相救有功，姥姥一掌早便送了你的狗命\n"NOR, ob);
                me->set_temp("tonglao/pass4",1);
                me->set_temp("tonglao/ketou",0);
                ob->set_name("天山童姥", ({ "tianshan tonglao", "tonglao"}) );
                ob->set("nickname", HIR "唯我独尊" NOR);
                ob->set("title", "灵鹫宫主人");
                ob->set("long",
	    		"她就是「灵鹫宫」的开山祖师.\n"+
	    		"乍一看似乎是个八九岁的女子,可神情却是老气横秋.双\n"+
	    		"目如电,炯炯有神,向你瞧来时,自有一股凌人的威严.\n");
                return 1;
        } else {
                command ("?");
                command ("dunno");
                return 1;
        }
}

int do_ketou(string arg)
{
        object me=this_player();
        if (!me->query_temp("tonglao/pass4")) return 0; 

        if( !arg || arg != "tonglao" ) return 0;
        if( me->query_temp("tonglao/ketou") < 6 ){
                switch( random(2) ) {
                case 0:
                                message_vision("$N必恭必敬的对对天山童姥磕了个响头。\n",me);
                                me->add_temp("tonglao/ketou",1);
                        break;
                case 1:
                                message_vision("$N双眼紧闭，恭恭敬敬的向天山童姥磕了个响头。\n",me);
                                me->add_temp("tonglao/ketou",1);
                        break;
                }
                return 1;
        }
        if( me->query_temp("tonglao/ketou") >= 6 ) {
                message_vision(CYN"天山童姥道：“你总算对姥姥恭谨有礼。姥姥一来要利用于你，二来嘉奖后辈，\n"+
                        "便传你天山六阳掌和天山折梅手！灵鹫宫秘道里记着六阳掌和折梅手的要诀，你\n"+
                        "可以去看看，秘道的走法是东三北七。这条路一直向北走可以出去。”。\n"NOR, me);
                me->set("quest/tonglao/pass", 1);
                me->set_skill("liuyang-zhang",10+random(5));
                me->set_skill("zhemei-shou",10+random(5));
                message_vision(HIC"你的天山六阳掌进步了。\n", me);
                message_vision("你的天山折梅手进步了。\n"NOR, me);
                log_file("quest/tonglao",sprintf("%8s%-10s成功解开童姥秘密，经验：%d，福：%d，次数：%d。\n",
                        me->name(),"("+me->query("id")+")", me->query("combat_exp"),
                        me->query("kar"), me->query("quest/tonglao/quest")), me);
                me->delete_temp("tonglao");
                remove_call_out("dest");
                call_out("dest", 2, this_object());
                return 1;
        }
}

void dest(object ob)
{      
        if (!ob ) return;
        message_vision(YEL"\n突然你听得身后蹄声急促，夹着叮当、叮当的铃声，回头望去，但见数十匹马急驰而至。\n"+
                            "马背上乘者都披了淡青色斗篷，远远奔来，宛如一片青云，听得几个女子声音叫道：“尊\n"+
                            "主，属下追随来迟，罪该万死！”数十匹马奔驰近前，乘者全是女子，斗篷胸口都绣着一\n"+
                            "头黑鹫，神态狰狞。众女望见童姥，便即下马，快步奔近，在童姥面前拜伏在地人人对童\n"+
                            "姥极是敬畏，俯伏在地，不敢仰视。童姥哼了一声，怒道：“你们都当我已经死了，是不\n"+
                            "是？”那老妇在地下重重磕一个头，说道：“不敢，属下九天九部已全部下山，分路前来\n"+
                            "伺候尊主。属下无能，追随来迟，该死，该死！”说着连连磕头。童姥道：“看你们个个\n"+
                            "衣衫破烂，这三个多月之中，路上想来也吃了点儿苦头，等回宫后再说吧”。说完和一行\n"+
                            "人向灵鹫宫方向而去。\n"NOR, ob);
       destruct(ob);
}

#include "npc.h";
