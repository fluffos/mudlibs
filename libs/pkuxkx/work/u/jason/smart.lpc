inherit NPC;
#include <ansi.h>

string* emotes = ({
	"blink","xixi","bosimao","bow","thank","thanks","greet","la","help!!!"
});
string* words = ({
	"我想买个房子，谁能支援点钱吗，十两，二十两都行。我在客栈等。",
	"我想买个房子，帮帮我吧，谢谢！！",
	"有人可以给我点钱买个房子吗？我在客栈",
	"帮帮新手吧。",
});

int start_fight();
int do_fight();
int do_cure();

//设计核心
//1. 走路，从指定地点到指定地点，处理其中可能的问题，比如guard
//2. 战斗，攻击，逃跑，疗伤，捡武器，买药，买武器，换使用的技能

string* kedian_to_fight_room = ({
	"west","north","west","down"
});

string* fight_room_to_kedian = ({
	"up","east","south","east"
});

string* kedian_to_dangpu = ({
	"west","south","south","east"
});

string* dangpu_to_kedian = ({
	"west","north","north","east"
});

string* kedian_to_quanzhou = ({
	"west","south","east","east","east","east","east","east","southeast","south","east","south","south","south","south","south",
	"west","west"
});

string* quanzhou_to_kedian = ({
	"east","east","north","north","north","north","north","west","north","northwest","west","west","west","west",
	"west","west","north","east"
});

string* kedian_to_bank = ({
	"west","west"
});

string* bank_to_kedian = ({
	"east","east"
});

int walk(int path,int startpos, int cmdpos,string cmd)
{
	string* patharr;
	int ret;
	int retry;
	int goback = 0;
	int i =0;
	printf("I am at %s \n",environment()->query("short"));

	switch(path)
	{
		case 0:
			patharr = kedian_to_fight_room;
			break;
		case 1:
			patharr = fight_room_to_kedian;
			break;
		case 2:
			patharr = kedian_to_dangpu;
			break;
		case 3:
			patharr = dangpu_to_kedian;
			break;
		case 4:
			patharr = kedian_to_quanzhou;
			break;
		case 5:
			patharr = quanzhou_to_kedian;
			break;
		case 6:
			patharr = kedian_to_bank;
			break;
		case 7:
			patharr = bank_to_kedian;
			break;
		default:
			return -1;
	}

	if(query("inbusy"))
	{
		return -2;
	}

	for( i=startpos;i<sizeof(patharr);i++)
	{
		printf("go "+patharr[i]+"\n");
		retry = 0;
		ret = command("go "+patharr[i]);
		while(ret == 0 && retry++ < 10)
		{
			printf("go "+patharr[i]+",retry %i\n",retry);
			ret = command("go "+patharr[i]);
		}

		if(ret == 0)
		{
			//return back!
			printf("go back\n");
			goback = 1;
			break;
		}

		printf("I am at %s \n",environment()->query("short"));

		if(cmdpos == i && cmd != "")
		{
			command(cmd);	
			printf(cmd+"\n");
			call_out("walk",3,path,i+1,0,"");
			return 0;
		}


	}

	if(goback == 1)
	{
		//fail to arrive, let go back
		if(path%2 == 0)
			call_out("walk",1,path + 1,sizeof(patharr) - i,0,"");
		else
			call_out("walk",1,path - 1,sizeof(patharr) - i,0,"");
	    return 1;
	}
	printf("I am at %s \n",environment()->query("short"));
	return 0;
}

void create()
{
        set_name( "雪儿", ({ "xuer"}));
        set("title","平民百姓");

        set("gender", "女性");	
        set("age", 18);    
            
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 2500);
        set("max_jing", 2500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("combat_exp", 15000000);
    	
        set_skill("force", 500);
        set_skill("kuihua-shengong", 450);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("riyue-dao", 450);
      	set_skill("riyue-shengong",400);
        set_skill("kaishan-zhang", 450);
        set_skill("strike", 450);
        set_skill("ryingzhua-gong", 450);
        set_skill("claw", 480);
    	set_skill("sword",500);
    	set_skill("riyue-jian",450);
    	set_skill("blade",450);
        set_skill("feitian-shenfa", 450);
        set_skill("literate",280);
	    set_skill("pixie-jian",490);
        map_skill("force", "kuihua-shengong");
        map_skill("parry", "riyue-jian");
        map_skill("dodge", "pixie-jian");
        map_skill("sword","pixie-jian");
        map_skill("claw", "ryingzhua-gong");
        map_skill("strike", "kaishan-zhang");
        
    	prepare_skill("claw", "ryingzhua-gong");
    	prepare_skill("strike", "kaishan-zhang");
	
        setup();
	    carry_object("/d/city/obj/flower_shoe")->wear();
        carry_object("/d/city/obj/pink_cloth")->wear();
        carry_object("/d/city/obj/goldring")->wear();
        carry_object("/d/city/obj/necklace")->wear();
	    carry_object("/d/quanzhou/obj/xiuhua");
	    carry_object("/d/riyuejiao/obj/xiuhuajia")->carry();
	    
	    set("smartnpc",1);
}

//自己进入神之角斗场的房间开始和对手厮杀，不得超过30s，否则判负
//之后可以离开
//target是对手的id
void start(string target)
{
    int ret;
    set("target",target);
    set("status","goto_fight_room");
    set("path",0);
    ret = walk(0,0,0,"guard north"); 
    if(ret < 0)//we are still at the start point   
    {
        call_out("main_loop",1);
    }
    else if(ret > 0)//we are going to return back
    {
        call_out("main_loop",1);
    }
    else
    {
        //arrived
        set("status","start_fight");
		start_fight();
    }
    
}

//战斗结束时调用，离开神之角斗场，自行疗伤。直到下一局start，自动回到武庙down
void stop()
{
    remove_call_out("main_loop");
	if(environment()->query("short") != "客店")
	{
		//must be in 角斗场
		walk(1,0,0,"");
		set("status","pause");
	}
}

void got_fight(object who,string type)
{
//    if()
}

void busy_started()
{
    
}

void busy_stopped()
{
    
}

void damage_received(mixed who,string type)
{
    
}

void wound_received(mixed who,string type)
{
    
}


int main_loop()
{
	int ret=0;
    remove_call_out("main_loop");
    
    switch(query("status"))
    {
        case "goto_fight_room":
			if(environment()->query("short") == "客栈")
			{
				ret = walk(0,0,0,"");
				if(ret == 0)
				{
					set("status","start_fight");
					
				}
			}
            break;
		case "start_fight":
			start_fight();
			break;
		case "ask_for_money":
			if(random(5) == 1)
			{
				if(random(2))
				{
					command("chat* "+emotes[random(sizeof(emotes))]);
				}
				else
				{
					command("chat "+words[random(sizeof(words))]);
				}
				add("ask_money_times",1);
				if(query("ask_money_times") > 12)
				{
					set("status","start_final_fight");
				}
			}
			break;
		case "start_final_fight":
			ret = walk(0,0,0,"");
			if(ret == 0)
			{
				set("status","fighting");
				command("kill "+query("target"));
				do_fight();
			}
			break;
		case "fighting":
			do_fight();
			break;
		case "cure":
			do_cure();
			break;
		case "convert_cash_to_gold":
			ret = walk(6,0,1,"convert 1 cash to gold");
			if(ret == 0)
			{
				set("status","from_bank_back");

			}
			break;
		case "from_bank_back":
		{
			ret = walk(7,0,1,"");
			if(ret == 0)
			{
				set("status","goto_buy_zhen");

			}
		}
		break;
		case "goto_buy_zhen":
		{
			ret = walk(4,0,17,"buy zhen 30");
			if(ret == 0)
			{
				set("status","from_quanzhou_back");

			}
		}
		break;           
		case "from_quanzhou_back":
		{
			ret = walk(5,0,0,"");
			if(ret == 0)
			{
				set("status","start_final_fight");
			}

		}
		break;           

    }    
    
    call_out("main_loop",1);
    
    return 1;
}

int start_fight()
{
	int ret;
	if(present(query("target"),environment()))
	{
		command("kill "+query("target"));
		//leave immediately
		ret = command("halt");
		if(ret == 0)
		{
			command("chat* hammer "+query("target"));
		}
		walk(1,0,0,""); 
		set("status","ask_for_money");          
		command("chat* hi");
		command("chat 谁能给我点钱买房子吗？多谢了！我在客栈。");
		call_out("main_loop",1);
	}
	else
	{
		call_out("main_loop",1);
	}
	return 1;
}
void test(int path)
{
	walk(path,0,0,"guard north");
}





int accept_object(object who,object ob)
{
	int ret = 0;
	if(ob->query("money_id"))
	{
		command("bow "+who->query("id"));
		if(ob->value() > 100000)
		{
			command("chat* forgetx "+who->query("id"));
		}
		add("all_money",ob->value());
		if(query("all_money") > 3000)
		{
			//convert to gold first
			set("status","convert_cash_to_gold");
			ret = walk(6,0,1,"convert 1 cash to gold");
			if(ret == 0)
			{
				set("status","from_bank_back");
				ret = walk(7,0,0,"");
				if(ret != 0) return 1;				
			}

			//enough, goto buy some xiuhua zhen
			set("status","goto_buy_zhen");
			ret = walk(4,0,17,"buy zhen 30");
			if(ret == 0)
			{
				set("status","from_quanzhou_back");
				ret = walk(5,0,0,"");
				if(ret == 0)
				{
					set("status","start_final_fight");
					ret = walk(0,0,0,"");
					if(ret == 0)
					{
						set("status","fighting");
					}
				}
			}
		}
	}
	else
	{
		command("drop "+ob->query("id"));
	}
	return 1;
}

int do_fight()
{
	int ret = 0;
	if(!query("inbusy"))
	{
		command("get zhen");
		command("get zhen");
		ret = command("wield all");
		if(ret == 0)
		{
			//be ciwan or no zhen!
			set("status","cure");
			command("halt");
			walk(1,0,0,"");
			return 1;
		}
		command("perform sword.cixue");
	}
}