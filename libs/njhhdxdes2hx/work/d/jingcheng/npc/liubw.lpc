// The latest changed by ysgl
// Data : 1997.11.1

inherit NPC;
#include <ansi.h>
int ask_me();

void create()
{
        set_name("刘伯温", ({ "liu bowen", "liu", "bowen" }) );
        set("title",GRN "当朝宰相" NOR);
        set("gender", "男性");
        set("age", 40);
        set("long",
                "他是当朝宰相，奉旨监考，为国家选拔人才。\n");
        set("attitude", "peaceful");
        set("str", 50000);
        set("con", 30);
        set("int", 24);
        set("dex", 30000);
        set("chao_ting",9000000);
        set("force", 80000);
        set("max_force", 80000);
        set("force_factor", 1000);
        set("combat_exp", 20000000);
        set("score", 2000000);
        set_skill("dodge", 500);
        set_skill("force", 1000);
        set_skill("iron-cloth",1000);
	set("inquiry", ([
		"科举" : (: ask_me :),
	        ]) );

        setup();

 }
int accept_fight(object me)
{
        command("say 生命可贵！不要自寻死路！");
        return 0;
}

int ask_me()
{
	int j,combatexp;
	string title;
	object me;

 	string *guan = ({            
                      HIW"白丁"NOR,
                      BLK"童生"NOR,
                      RED"秀才"NOR,
                      GRN"举人"NOR,
                      YEL"贡生"NOR,
                      BLU"监生"NOR,
                      MAG"三甲进士"NOR,
                      CYN"二甲进士"NOR,
                      WHT"头甲进士"NOR,
                      HIR"翰林"NOR,
                      HIG"协办大学士"NOR,
                      HIC"文华殿大学士"NOR,
                      BLK"武英殿大学士"NOR,
                      HIB"保和殿大学士"NOR,
                      RED"体任阁大学士"NOR,
                      HIW"文渊阁大学士"NOR,
                      GRN"龙图阁大学士"NOR,
                      GRN"大宰相"NOR,
                        
        });

	string *chaoting = ({ 
                        "0",
                        "10000",
                        "30000",
                        "60000",
                        "100000",
                        "300000",
                        "800000",
                        "1500000",
                        "3000000",
                        "5000000",
                        "8000000",
                        "12000000",
                        "24000000",
                        "48000000",
                        "96000000",
                        "120000000",
                        "240000000",
                        "480000000",
                        });
	me=this_player();
	combatexp = (int) me->query("chao_ting");
        j = (int) me->query_skill("literate",1);
        if (combatexp<12000000) 
	combatexp = combatexp + j* j* j /40;
        for(j= sizeof(chaoting) - 1 ; j>=0; j--)
        {
                if( atoi(chaoting[j])  <= combatexp )
                        {    
                           
                           title=guan[j];
			   me->set("guantitle",title);
                            message_vision("刘伯温看了看$N的考评，说道：
	$N可以得个"+title+"的功名。\n", me);
                                break;
                        }
        }      
	return 1;          
}

