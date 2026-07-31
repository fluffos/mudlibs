//wanxi.c

inherit NPC;
inherit F_DEALER;
string ye_wu() ;
void create()
{
	set_name("萧万喜", ({ "xiao wanxi", "xiao", "wanxi"}));
	set("title", "当铺老板");
	set("shen_type", 1);
	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 34);
	set("str", 100);
       set("dealer", "pawn");
	set("long",
		"萧万喜是东城萧员外的胞弟。\n");
	set("no_get_from", 1);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("inquiry", ([
			 "★业务★" : (: ye_wu :),		     
	]));
	setup();
	carry_object(__DIR__"obj/choupao")->wear();
}

void init()
{
	 add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
	add_action("do_check", "listp");
	add_action("do_redeem", "redeem");
}
//业务list
string ye_wu()
{
   write(""WHT"﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎"NOR"\n");
   write( HIY"  ★ 估价 ★: "+NOR+HIG"( value 物品 )    ━估算物品价值。      \n"+NOR);
   write( HIY"  ★ 典当 ★: "+NOR+HIG"( pawn 物品 )     ━典当物品。      \n"+NOR);
   write( HIY"  ★ 查询 ★: "+NOR+HIG"( listp 物品 )    ━查询典当物品。      \n"+NOR);
   write( HIY"  ★ 赎回 ★: "+NOR+HIG"( redeem 物品 )   ━赎回典当的物品。  \n"+NOR);
   write( HIY"  ★ 卖断 ★: "+NOR+HIG"( sell 物品 )     ━卖断给当铺。\n"+NOR);
   write( HIY"  ★ 列表 ★: "+NOR+HIG"( list )	  ━查看卖断物品。\n"+NOR);
   write(""WHT"﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊"NOR"\n");
   return HIR"客官有什么吩咐！！！"+NOR;
}
int clean_up()
{
	return 0;
}

void die()
{
	message_vision("\n$N一声惨叫，死了。\n", this_object());
	destruct(this_object());
}

void unconcious()
{
	die();
}
