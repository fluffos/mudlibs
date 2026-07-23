// shi.c 史青山
// Modified by snowman 21/05/2000

#include <ansi.h>
inherit NPC;
string ask_me();
int ask_job();
int do_proceed(object who, object ob);

void create()
{
       set_name("史青山", ({ "shi qingshan", "shi", "qingshan" }));
       set("title", "扬州守将");
       set("gender", "男性");
       set("age", 33);
       set("str", 25);
       set("dex", 16);
       set("long", "史青山曾经是武当山的俗家弟子，又跟丐帮有点关联，只是不知为何吃上了朝廷饭。\n");
       set("combat_exp", 200000);
       set("shen_type", 1);
       set("attitude", "heroism");

       set_skill("unarmed", 100);
       set_skill("tiyunzong",100);
       set_skill("yinyun-ziqi",100);
       set_skill("force", 100);
       set_skill("sword", 100);
       set_skill("dodge", 100);
       set_skill("parry", 100);
       set_skill("stick", 100);
       set_skill("dagou-bang", 100);
       map_skill("parry", "dagou-bang");
       map_skill("stick", "dagou-bang");
       map_skill("dodge","tiyunzong");
       set_temp("apply/attack", 70);
       set_temp("apply/defense", 70);
       set_temp("apply/armor", 70);
       set_temp("apply/damage", 70);

        set("inquiry", ([
                "为官" : (: ask_me :),
                "报效朝廷" : (: ask_me :),
//                "job" : (: ask_job :),
//                "任务" : (: ask_job :),
       ]));
       
       set("max_qi", 1700);
       set("qi", 1700);
       set("neili", 2000); 
       set("max_neili", 2000);
       set("jiali", 30);

       setup();
       carry_object(BINGQI_D("langya-bang"))->wield();
       carry_object(ARMOR_D("armor"))->wear();
}

int accept_fight(object me)
{
       command("say 老夫久未和江湖人动手过招了，今日也不想破例。");
       return 0;
}

void init()
{
       object ob;
       ::init();
       if (interactive(ob = this_player()) && living(this_object()) &&
               (int)ob->query_condition("killer")) {
               remove_call_out("kill_ob");
               call_out("kill_ob", 0, ob);
       }
}

int ask_job()
{
        object *all, *inv, ob, room, me=this_player();
	int i, j=0;

	if (me->query_temp("mark/巡捕", 1)){
		command("? "+me->query("id"));
		return 1;
	}

	if (me->query("PKS") > 50
        && me->query("combat_exp") / me->query("PKS") < 350000){
		command("hehe "+me->query("id"));
		command("say 哈哈，想不到你这个杀人无数的臭贼，自己找上门来了。");
		message_vision("$N大叫一声：来人啊，给我把这厮拉下去。突然间冲上一批官兵，$n被五花大绑的抬了下去！\n", this_object(), me);
		me->apply_condition("city_jail", 50);

		inv = all_inventory(me);
                for( i=0; i<sizeof(inv); i++ ) {
                	if( inv[i]->query_autoload() ) continue;
                	if( inv[i]->query("equipped") )
                		inv[i]->unequip();
                	destruct(inv[i]);
                }
		me->move("/d/city/dalao");
		message("vision","只听“乒”地一声，一个昏沉沉的东西被扔了进来。\n", environment(me), me);
		return 1;
	}
	
	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");
        
        if (userp(me) && me->query("id") == room->query("winner") ) {
                command("say 阁下是中神通，老夫可担待不起！");
                return 1;
        }

	if (me->query("combat_exp") < 50000){
		command("say 你是哪里来的小毛孩，闯到这儿来打趣老夫？");
		command("kick "+me->query("id"));
		me->move("/d/city/bingyingmen");
        	message("vision","只听“乒”地一声，" +me->query("name") + "从兵营里飞了出来。\n", environment(me), me);
		return 1;
	}

	all = users();

        for(i=0; i<sizeof(all); i++){
        	if( wiz_level(all[i]) ) continue;
         	if( all[i]->query_temp("mark/巡捕") )
                        j++;
                if (j > 6){
			command("shake");
			command("say 这里现在不缺人手。");
			return 1;
			break;
		}
	}

	say("史青山哈哈大笑道；好！老夫正缺人手，今天起你就在我手下任事吧！\n");
	me->set_temp("apply/short", ({ HIR" 大内巡捕  "NOR+me->query("name")+"("+capitalize(me->query("id"))+")"}));
	ob = new("/d/city/obj/wenshu2");
	ob->move(me);
	me->set_temp("mark/巡捕", 1);
	write("史青山从身后找出一张文书递给你。\n");
	return 1;
}

int accept_object(object who, object ob)
{
	object room;
	
	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");

	if ( userp(ob) && ob->query("id") == room->query("winner") ){
		command("say 你把中神通打晕了？！佩服！佩服！");
		command("say 但你还是先废了此人的中神通身份吧！");
		return 0;
	}
	
        if (userp(ob) && ob->query("PKS") >= 50)
                return do_proceed(who, ob);
        return 0;
}

int do_proceed(object who, object ob)
{	
	object *inv, gold;
	int bonus, i;

	ob->clear_condition();
	ob->set("startroom", "/d/city/dalao");

	inv = all_inventory(ob);
	for( i=0; i<sizeof(inv); i++ ) {
                if( inv[i]->query_autoload() ) continue;
                if( inv[i]->query("equipped") )
                	inv[i]->unequip();
                destruct(inv[i]);
        }

	bonus = ob->query("combat_exp")/10;
	if (bonus > 3000) bonus = 3000;

	if(ob->query("PKS") > 99){
		ob->apply_condition("city_jail", 300);
	}

	else if(ob->query("PKS") > 74){
		bonus = bonus*2/3;
        	ob->apply_condition("city_jail", 200);
        }

	else if(ob->query("PKS") > 49){
		bonus = bonus*2/3;
		ob->apply_condition("city_jail", 100);
	}
	
	who->add("combat_exp", bonus);
	ob->add("comba_exp", -bonus);
	if(ob->query("city_jail") > 4)
		ob->apply_condition("city_jail", 400);
	
	ob->add("PKS", -1);
	ob->add("city_jail", 1);
	call_out("move_ob", 1, ob);
	
	message_vision("$N吩咐左右给$n穿上琵琶骨，拖进大牢。\n", this_object(), ob);

	command("thumb "+who->query("id"));
	gold=new("/clone/money/gold");
	gold->set_amount(10);
	gold->move(who);
	command("say 干得好，这是你的赏金，下去歇着吧！");	
	write("史青山给你一些黄金！\n");
	command("chat "+ob->query("title")+ob->query("name")+"于今日"+ NATURE_D->game_time() +"被本府收监。");
	log_file("Jail", sprintf("%s(%s)把%s(%s)送进 city jail on %s，得EXP %d\n",
                  who->query("name"), who->query("id"), ob->query("name"), ob->query("id"), ctime(time()), bonus));
	return 1; 
}
void move_ob(object ob)
{
	if( !ob ) return;
	ob->move("/d/city/dalao");
	message("vision", "只听“乒”地一声，一个昏沉沉的家伙被扔了进来。\n", environment(ob), ob);
}

string ask_me()
{        
       	object me;
       	int gftimes;

       	me = this_player();
       	gftimes = (int)me->query("gf_job",1);
       
       	if (gftimes<1)
       		return "这位"+RANK_D->query_respect(me)+"还没有为朝廷出过力，何谈功名呢？！\n"; 
       	if (gftimes>=1 && gftimes<50)
       		return "这位"+RANK_D->query_respect(me)+"目前功劳不够，继续努力吧？！\n"; 
       	if (gftimes>=50 && gftimes<100){
       		command("nod ");
       		command("say 我已将你的功劳报给了兵部尚书，前日兵部来函提升你为快捕。");
       		me->set_temp("apply/short", ({HIY"朝廷官员九品快捕 "NOR+me->name()+"("+me->query("id")+")"}));
       		return "我辈身逢乱世，当为国家出力，为百姓造福啊！\n"; 
       	}
       	if (gftimes>=100 && gftimes<200){
       		command("nod " + me->query("id"));
       		command("say 我已将你的功劳报给了兵部尚书，前日兵部来函提升你为捕头。");
       		me->set_temp("apply/short", ({HIY"朝廷官员八品捕头 "NOR+me->name()+"("+me->query("id")+")"}));
       		return "好好干，老夫是不会亏待你的！\n";
       	}
       	if (gftimes>=200 && gftimes<500){
       		command("pat " + me->query("id"));
       		command("say 这位"+RANK_D->query_respect(me)+"的功劳早以传边大街小巷，特此提升你为铁捕！");
       		me->set_temp("apply/short", ({HIY"朝廷官员七品铁捕 "NOR+me->name()+"("+me->query("id")+")"}));
       		return "这位"+RANK_D->query_respect(me)+"的功劳不小，老夫下次进京，一定要亲自禀告兵部尚书！\n";
       	}
       	if (gftimes>=500 && gftimes<1000){
       		command("thumb " + me->query("id"));
       		me->set_temp("apply/short", ({HIY"朝廷官员六品都司 "NOR+me->name()+"("+me->query("id")+")"}));
       		return "这位"+RANK_D->query_respect(me)+"的成绩不小，但不要和江湖中人打的火热，否则休怪老夫手下无情！\n";
       	}
       	if (gftimes>=500 && gftimes<1000){
       		command("haha " + me->query("id"));
       		command("say 这位"+RANK_D->query_respect(me)+"的武功才智均为百里挑一，继续努力吧！");
       		me->set_temp("apply/short", ({HIY"朝廷官员五品游击 "NOR+me->name()+"("+me->query("id")+")"}));
       		return "听说最近江南常有江洋大盗出没，你去查查看！\n";
       	}
       	if (gftimes>=1000 && gftimes<2000){
       		me->set_temp("apply/short", ({HIY"朝廷官员四品参将 "NOR+me->name()+"("+me->query("id")+")"}));
       		return "老夫已包举你为参将，以后功名利禄指日可待！\n";
       	}
       	if (gftimes>=2000 && gftimes<2500){
       		me->set_temp("apply/short", ({HIY"朝廷官员正三品副将 "NOR+me->name()+"("+me->query("id")+")"}));
       		return "听说兵部尚书想要调你前去京城，你以后前途远大啊！\n";
       	}
       	if (gftimes>=2500 && gftimes<3000){
       		me->set_temp("apply/short", ({HIY"朝廷大将正二品总兵 "NOR+me->name()+"("+me->query("id")+")"}));
       		return "听说兵部尚书想要调你前去京城，你以后前途远大啊！\n";
       	}
       	if (gftimes>=3000 && gftimes<3500){
       		me->set_temp("apply/short", ({HIY"朝廷重臣正一品提督 "NOR+me->name()+"("+me->query("id")+")"}));
       		return "听说兵部尚书想要调你前去京城，你以后前途远大啊！\n";
       	}
        if (gftimes>=3500 && gftimes<4500){
        	me->set_temp("apply/short", ({HIY"朝廷重臣正一品大将军 "NOR+me->name()+"("+me->query("id")+")"}));
       		return "听说兵部尚书想要调你前去京城，你以后前途远大啊！\n";
        }
       	if (gftimes>4500){
       		me->set_temp("apply/short", ({HIY"朝廷钦差大臣 "NOR+me->name()+"("+me->query("id")+")"})); //wiz get it now
       		return "怎麽，你想把官做的比老夫还大？\n";
       	}
}

void die()
{
        object killer;
        if(objectp(killer = query_temp("last_damage_from")) ){
                killer->apply_condition("killer", killer->query_condition("killer")+100);
                command("say "+killer->name()+"你竟敢谋杀朝廷命官！来人啊。。。");
                }
        ::die();
}    
