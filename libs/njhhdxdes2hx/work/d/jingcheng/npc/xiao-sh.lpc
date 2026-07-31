// Created by ysgl
// Data: 1997.10.17
// The latest changed by ysgl in 1997.10.30
               
#include <ansi.h> 
inherit NPC;                               
mapping *step_phase;
mapping *read_table(string file);
int ask_biao(object me);
int j;

void create()
{
	set_name("萧升", ({ "xiao sheng", "xiao" ,"sheng" }));
	set("title",GRN"震远镖局总镖头"NOR);
	set("nickname", GRN"河洛"NOR+HIY"一剑"NOR);
	set("long",
	"他就是振远镖局现在的当家－－萧升。他不但武艺高强，而且为人豪爽，是一条真\n"
	"性情的汉子。自从老镖头退出江湖之后，这震远镖局大大小小的事物就有他一手打理。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "heroism");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 35);   
	set("can_biao", 3);
	set("combat_exp", 60000+random(15000));
	set_skill("dodge", 100);
	set_skill("unarmed", 80);
	set_skill("sword", 120);
	set_skill("force",120);
	set_temp("apply/defense", 40);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"萧升淡淡的瞅了你一眼，回过头去接着督促弟子们练武。\n",	
        }) );             
	set("inquiry", ([
		"押镖" : "萧升道：“本镖局创立以来，业务蒸蒸日上，急需扩大人手，现在本局正好有一趟镖要走，有志者可\n"
		"可以组队押镖，酬金优厚！”\n",
		"走镖"   : (: ask_biao :),
	]));
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/gangjian")->wield();
}
void init()
{
	object me;
    	::init();
    	if( interactive(me = this_player()) && !is_fighting() 
	&& !(this_object()->query_temp("is_biao")) )
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	object obj;
	command("hi "+me->query("id"));
}                       
int ask_biao(object me)
{          
	object ob = this_object();
	object player=this_player();

	if( ob->query("can_biao") <= 0 || ob->query_temp("is_biao") ) {
		message_vision("$N笑道：“这趟镖已经有人押送了，"+RANK_D->query_close(player)+
		"还是等下一趟吧。”\n", ob);
		return 1;                 
	} else {
		message_vision("$N笑道：“ "+RANK_D->query_respect(player)+"请稍等片刻，镖车马上就好。”"
		"\n", ob);
		this_object()->add("can_biao", -1);
		remove_call_out("anounce");
		call_out("anounce", 5,player);
		return 1;
	}
}
void anounce(object player)
{
	command("chat 我武维扬～～～我武维扬～～～！！！");
	this_object()->set("chat_chance", 0);
	this_object()->set_temp("is_biao", 1);
	j = 0;
	step_phase = read_table(__DIR__"luxian");
	remove_call_out("ya_biao");
	call_out("ya_biao", 5,player);
}                              
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for( i = 0 ; i < sizeof(line) ; i++ ) {
		if( line[i] == "" || line[i][0] ==	'#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i] == "" || line[i][0] == '#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]]);
		fn = (++fn) % sizeof(field);        
		if( !fn ) ++rn;
	}
	return data;
}
void ya_biao(object player)
{        
	object obj, place;     
	int i,jj;             

	if( this_object()->is_fighting() && this_object()->query_temp("is_biao") ) {
		if( random(10) > 6 )
			command("say 振远镖局～～～我武维扬～～～！？");
		call_out("ya_biao", 1,player);
		return;
        }
        if( random(step_phase[j]["random"]) > 5 ) { 
		tell_object(player,RED"突然间，从四周冒出一伙黑衣蒙面人来，大叫着朝镖车冲了上来。\n"NOR);
		command("say 有强盗，大家小心护镖！");
		jj=2+random(4);
		for( i = 0 ; i < jj ; i ++ ){
		   	obj = new(__DIR__"xiaoer");
		   	obj->move( step_phase[j]["place"] );
	   		obj->kill_ob(this_object());
			this_object()->kill_ob(obj);
			obj->kill_ob(player);
			player->kill_ob(obj);
	           	
		}
		call_out("ya_biao", 5,player);
		return;
	}                
	place = load_object( step_phase[j]["place"] );           
	message_vision("$N领着镖车“辘辘～”的走过"+place->query("short")+"，继续前进。\n", this_object());
	command(step_phase[j]["command"]);
        j++;               
        if( j == sizeof(step_phase)) {
		player->set_temp("done_biao", 1);
		command("pat "+player->query("id"));
		command("say 好样的！这趟镖得保平安押到，真是多亏了"+RANK_D->query_respect(player)
		+"的大驾啊！\n");
		command("say 这是给你的酬金！");
		obj = new("/npc/money/gold");
		obj->set_amount( 50+random(50) );
		obj->move(player);
		message_vision("萧升愉快的交给$N一些黄金。\n", player);
		this_object()->delete_temp("is_biao");
	 	return;
	}
	call_out("ya_biao", 1,player);
	return;
}
