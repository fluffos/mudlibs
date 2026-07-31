// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

int ask_ren(object me);            
int ask_pipa(object me);

void create()
{
	set_name("柳玉儿", ({ "liu yuer" , "liu" , "yuer" }));
	set("title","天涯歌女");
	set("long",
	"一个孤苦无依的歌女，沦落他乡，只有靠卖唱为生。\n");
	set("gender", "女性");
	set("age", 24);
	set("attitude", "peaceful");  
	set("per", 35);
	set("combat_exp", 1000);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"柳玉儿调了调手中琵琶的弦，开始曼声吟唱起来。\n",	
		"柳玉儿理了理头上的发丝，浅浅的一笑。\n",
		"柳玉儿听见楼下的脚步声，一双充满期待的眼睛看看楼梯口，缓缓的摇了摇头。\n",
		"柳玉儿数了数面前的小钱，低低的叹了一口气。\n",
        }) );
	set("inquiry",([
		"琵琶"  : (: ask_pipa :),
		"等人"  : (: ask_ren :),
	]));
		
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/pipa");
}

void init()
{
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 3, me);
                return;
        }
}

void greeting(object me)
{                                                                     
	object ob = this_object();
	message_vision("$N笑着对$n说：这位"+RANK_D->query_respect(me)+
	"请上座，待奴家为"+RANK_D->query_respect(me)+"来弹上一曲。\n", ob, me);
}

int ask_pipa(object me)
{
	object ob = this_object();
        
	message_vision("$N紧紧的抱着怀里的琵琶，唯恐被别人给抢走似的。\n", ob);
	message_vision("$N看着$n惊恐的说：这是我娘留给我的遗物，我不卖！\n", ob, this_player());
	                
         this_player()->set_temp("done",1);
         return 1;
}                                     

int ask_ren(object me)
{
	object ob = this_object(); 

	message_vision("$N惊奇的看着$n说道：这位"+RANK_D->query_respect(this_player())+
	"怎么知道我在等人？\n", ob, this_player());
	command("sigh");
	tell_object(this_player(),"柳玉儿满面愁色，说道：只是虽然我每日来此弹唱。但是挣钱不多，何日\n"
	"才能踌齐那十两黄金啊。事到如今只好希望那南天霸能大发慈悲了，放我们一条生路了。\n");
	return 1;
}

int accept_object(object who, object what)                  
{                  
	object ob, obj;
	ob = this_object();
	
	if( what->query("money_id") ){
		tell_object(who,"柳玉儿轻轻的摇摇头说：多谢"+RANK_D->query_respect(who)
		+"好意，\n小女子心领了，不过这件事还是让我自己设法解决吧。\n");
		return 1;
	}
	if( !(obj=present("baiyu pipa", ob)) ){
		tell_object(who,"柳玉儿惊叫一声道：哎呀，我的琵琶那里去了。\n");
		return 1;
	}
	if( what->query("id") == "letter" && who->query_temp("done") ){
		tell_object(who,GRN"柳玉儿接过信，匆匆的看了一遍后，感激的对你说："
		+RANK_D->query_respect(who)+"成全，\n小女子不胜感激，无以回报，就将这"
		"白玉琵琶送给"+RANK_D->query_respect(who)+"留个纪念吧。\n");
		obj->move(who);
		message_vision("$N对$n做了个万福，道：不劳相送，小女子这就告辞了。\n", ob, who);
                this_player()->set_temp("done",0);
        	remove_call_out("dest");
		call_out("dest", 1, ob);
		return 1;
	}
	return 0;
}		
		 
void dest(object ob)
{
	destruct(ob);
}
