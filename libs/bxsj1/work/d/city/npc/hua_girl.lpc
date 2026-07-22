#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_VENDOR;
int ask_me();
int ask_songhua();
int do_song(string arg);
void create()
{
                  set_name("紫竹", ({ "zi zhu", "zi" ,"zhu" }));
                  
                  set("shen_type", 1);
                  set("title",HIM"花店老板"NOR);
                  set("no_get", 1);
        	  set("no_bark", 1);
        	  set("job_npc", 1);
        	  set("no_ansuan", 1);


                  set("gender", "女性");
                  set("per", 30);
                  set("age", 15);
                  set("long",
"她是这里的卖花女，只见其含笑如春桃，玉唇含香,纤纤细腰,婀娜多姿，
虽粗布花衣，但不掩其清秀，实乃人间绝色。\n"
);
                  set("attitude", "friendly");
                  set("inquiry", ([
                                "送花" : (: ask_songhua :),
				"songhua" : (:ask_songhua :),
                  ]));


	set("vendor_goods", ({
           (["name":__DIR__"obj/flower/red_rose","number":99]),
           (["name":__DIR__"obj/flower/white_rose","number":99]),
           (["name":__DIR__"obj/flower/pink_rose","number":99]),
           (["name":__DIR__"obj/flower/blue_rose","number":99]),
           (["name":__DIR__"obj/flower/yellow_rose","number":99]),
	   (["name":__DIR__"obj/flower/qingren_cao","number":99]),
           (["name":__DIR__"obj/flower/ding_xiang","number":99]),
	   (["name":__DIR__"obj/flower/mu_dan","number":99]),
           (["name":__DIR__"obj/flower/yu_jinxiang","number":99]),
	   (["name":__DIR__"obj/flower/bai_he","number":99]),
           (["name":__DIR__"obj/flower/kang_naixin","number":99]),
	   (["name":__DIR__"obj/flower/ma_tilian","number":99]),
           (["name":__DIR__"obj/flower/jin_yucao","number":99]),
           (["name":__DIR__"obj/flower/huo_he","number":99]),
           (["name":__DIR__"obj/flower/hu_dielan","number":99]),
	   (["name":__DIR__"obj/flower/qiu_haitang","number":99]),
           (["name":__DIR__"obj/flower/shi_hulan","number":99]),
           (["name":__DIR__"obj/flower/mms","number":99])
        }));


                  setup();
	          carry_object("d/city/obj/pink_cloth")->wear();
		  carry_object("d/city/obj/flower_shoe")->wear();


                  remove_call_out("do_check_flower");
                  call_out("do_check_flower", 10+random(10) );

		  remove_call_out("do_full_flower");
                  call_out("do_full_flower", 1800 );
}

int do_full_flower()
{
   
	 tell_room(environment(), "\n几个花匠提着鲜花走了进来。\n");
	 tell_room(environment(), "“嗨！紫竹，我们给你送鲜花来了。”带头的那个花匠对紫竹打招呼。\n");
	 tell_room(environment(), "“紫竹喜声道：“谢谢花匠叔叔，放在后面的花室里吧。”\n");
 	 tell_room(environment(), "花匠们走过去将花放置好。\n");
	 tell_room(environment(), "花匠们走了出来对紫竹说道：“花放好了，我们下次再来。”\n");
	 tell_room(environment(), "花匠们走了出去。\n");

	set("vendor_goods", ({
           (["name":__DIR__"obj/flower/red_rose","number":99]),
           (["name":__DIR__"obj/flower/white_rose","number":99]),
           (["name":__DIR__"obj/flower/pink_rose","number":99]),
           (["name":__DIR__"obj/flower/blue_rose","number":99]),
           (["name":__DIR__"obj/flower/yellow_rose","number":99]),
	   (["name":__DIR__"obj/flower/qingren_cao","number":99]),
           (["name":__DIR__"obj/flower/ding_xiang","number":99]),
	   (["name":__DIR__"obj/flower/mu_dan","number":99]),
           (["name":__DIR__"obj/flower/yu_jinxiang","number":99]),
	   (["name":__DIR__"obj/flower/bai_he","number":99]),
           (["name":__DIR__"obj/flower/kang_naixin","number":99]),
	   (["name":__DIR__"obj/flower/ma_tilian","number":99]),
           (["name":__DIR__"obj/flower/jin_yucao","number":99]),
           (["name":__DIR__"obj/flower/huo_he","number":99]),
           (["name":__DIR__"obj/flower/hu_dielan","number":99]),
	   (["name":__DIR__"obj/flower/qiu_haitang","number":99]),
           (["name":__DIR__"obj/flower/shi_hulan","number":99]),
           (["name":__DIR__"obj/flower/mms","number":99])
        }));
	 remove_call_out("do_full_flower");
         call_out("do_full_flower",1800);
	 return 1;
	
}

private void go_home()
{
	if( !living(this_object()) ) return;
        message_vision("$N神色慌张地离开了。\n", this_object());
        this_object()->move("/d/city/huadian");
	message_vision("$N快步走了过来。\n", this_object());
}
	



void init()
{
     if( environment() != load_object("/d/city/huadian") ) 
		{
		remove_call_out("go_home");
		call_out("go_home", 1);
	}
    	 add_action("do_list", "list");
         add_action("do_buy", "buy");
         add_action("do_song", "song");
         //add_action("do_check_flower", "check_test");

}


string query_flower_file( string arg)
{
         return sprintf( DATA_DIR "flower/%c/%s", arg[0], arg );
}

int do_check_flower()
{
               object *ob,ob_letter;
               string file ;
               int i;
               ob = users();
               i = sizeof(ob);
               while (i--)
               {
                  if (userp(ob[i]))
                      {

                           file = query_flower_file( ob[i]->query("id")+".o" );
                           assure_file( file );

                                if(file_size(file)!=-1)
                                {

                                        if(interactive(ob[i]))
                                        if(living(ob[i]))
                                        if(!ob[i]-> is_busy())
                                        if(!ob[i]-> is_fighting() )
                                        {
                                                ob_letter=new("/clone/misc/flower");
                                                ob_letter->set_owner(ob[i]->query("id"));
                                                ob_letter->check(ob[i],this_object());
												destruct(ob_letter);
                                        }
                                }
                        }
                }
				  

          remove_call_out("do_check_flower");
          call_out("do_check_flower", 10+random(10) );

          return 1;
}

int ask_songhua()
{
        object ob = this_player();        
        write(CYN"紫竹欠身说到：“感谢" + RANK_D->query_respect(ob) + "光临小店，您先在这里将花买好，然后告诉小女要送给谁，小女一定为您送到。\n"
			  "送花格式：(song 花名 to 玩家ID)”\n"
			  "我们花店收费规则是：每一朵花收取一锭黄金的送花费。”\n"NOR);

                
                return 1;
}
int do_song(string arg)
{
	object ob_flower,me,send_flower;
    	int money_amount;
    	mapping flower;
	string flower_name,who;
	me=this_player();
    	if( !arg || sscanf(arg, "%s to %s", flower_name, who)!=2 )
		return notify_fail("你要送什么花给谁？\n");
	
	if(!FINGER_D->acquire_login_ob(who))
		  return notify_fail("这里有这个人吗？\n");
	 ob_flower=present(flower_name,me);
     	if(!ob_flower)
        return notify_fail("你身上好像并没有这种物品？\n");
        if (flower_name == "mms")
        return notify_fail(HIR"Ｍ"HIY"＆"HIB"Ｍ"HIW"'"HIG"ｓ"NOR"是吃的东西，本店暂时不运送。\n");
	if(!ob_flower->query("flower_w"))
        return notify_fail("对不起！我们这里不负责送这个。\n");
	if(me->is_busy())
		return notify_fail("你现在正忙着呢。\n");


		if(!send_flower=new("/clone/misc/flower"))
			return notify_fail("/clone/misc/flower初始化错误,和巫师联系\n");
		send_flower->set_owner(who);

		if(send_flower->query("flowername")==flower_name)
		  {
			  command("hmm ");
			  return notify_fail("对不起，我还没将您上次的花送到呢，请您稍后再来吧。\n");
		  }
		
		if(send_flower->query("from")==(me->name(1) + "(" + me->query("id") + ")"))
		  {
			  command("hmm ");
			  return notify_fail("对不起，我还没将您上次的花送到呢，请您稍后再来吧。\n");
		  }

		/////////////////////////////////////////////////////////////////////////////////
		//******************************收费*******************************************//
		if(ob_flower->query_amount()<10)
			money_amount=10;
		else
			money_amount=ob_flower->query_amount();
		
		if(ob_flower->query_amount()>1000)
			money_amount=1000;
		else
			money_amount=ob_flower->query_amount();


		
		switch (MONEY_D->player_pay(me, money_amount*10000) )
		{
	        case 0:  
	        	destruct(send_flower);		
			return notify_fail("您好像没有足够的银两来支付送花费用。\n");
            	case 2: 
            		destruct(send_flower);
			return notify_fail("您的零钱不够了，银票又没人找得开。\n");
        	}
		message_vision("$N对$n说道：“没问题，此次送花共收您"+MONEY_D->price_str(money_amount*10000)+"”。\n",this_object(),this_player());
		////////////////////////////////////////////////////////////////////////////////
		send_flower->set("flowername",ob_flower->query("name"));
		send_flower->set("flower_id",ob_flower->query("id"));
		send_flower->set("to",who);
		send_flower->set("from",me->name(1) + "(" + me->query("id") + ")");
		send_flower->set("amount",ob_flower->query_amount());

		flower = ([
                
		"flowername":ob_flower->query("name"),
            	"flower_id": ob_flower->query("id"),
            	"to": who,
            	"from": me->name(1) + "(" + me->query("id") + ")",
		"amount": ob_flower->query_amount(),

        	]);
		send_flower->send_flower(flower);
		send_flower->save();

		
		message_vision("$n将身上的"+ chinese_number(ob_flower->query_amount()) +ob_flower->query("unit")+flower["flowername"]+"拿出交给$N。\n",this_object(),this_player());
		message_vision("$N对$n说道：“好吧，小女子定会将花送到，包您满意。”\n",this_object(),this_player());
		
		destruct(send_flower);
		destruct(ob_flower);
		
		remove_call_out("do_check_flower");
         	call_out("do_check_flower", 10+random(10) );

		return 1;


}
