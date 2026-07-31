// pangu.c 盘古

#include <ansi.h>

inherit NPC;
void do_bite();

void create()
{
	set_name(HIR"王英[困难]"NOR, ({ "wang ying" }));

	set("gender", "男性");
      set("title",HIR "BOSS" NOR);
      set("age", 20);
	set("attitude", "friendly");
      
 

        set("str", 5000000);
        set("int", 5000000);
        set("con", 5000000);
        set("dex", 5000000);
      set("per", 30);
	set("shen_type", -1);


	set("combat_exp", 200000000);
	set("max_qi", 10000000000000000);
	set("max_jing", 10000000000000000);
	set("qi", 10000000000000000);
	set("jing", 10000000000000000);
	set("neili", 10000000000000000);
	set("max_neili", 10000000000000000);
      set("mana", 999999999999);
	set("max_mana", 999999999999);
	set("jiali", 20000000000);
      set("score", 500000);

      set_skill("count", 5000);
	set_skill("wudao-shanqian", 5000);
	set_skill("unarmed", 5000);
	set_skill("dodge", 5000);
	set_skill("force", 5000);
	set_skill("parry", 5000);
      set_skill("martial-cognize",5000);

        set("chat_chance", 50);
        set("chat_msg", ({
				(: random_move :),
				(: random_move :),
        }));	
	set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: do_bite() :),
        }) ); 


	setup();
	set_temp("apply/attack", 2500);
	set_temp("apply/defense", 2500);
	set_temp("apply/unarmed_damage", 2500);
	set_temp("apply/armor", 2500);

	setup();

         }
void do_bite(object me)
{
	        object *enemies,enemy;
        object *obs;			
        string msg;

        clean_up_enemy();
        enemies = query_enemy();
	        obs = all_inventory(environment(this_object()));		

if(!this_player())
{
::kill_ob(me);
return;
}

        if( !enemies || sizeof(enemies)==0 )
                return;
        enemy = enemies[random(sizeof(enemies))];
        if( !userp(enemy) ) return;
        message_vision(BLK HBRED"$N拿出刺刀向$n刺出！！！！\n"NOR,this_object(),enemy);
        enemy->receive_wound("qi",30000000000+random(30000000000),this_object());
        msg = "( $n" + 
              COMBAT_D->status_msg(enemy->query("qi") * 100 / 
              (enemy->query("max_qi") ? enemy->query("max_qi") : 100)) + ")\n"; 
        message_vision(msg, this_object(), enemy);
		
        this_object()->receive_wound("qi",30000000000+random(30000000000));
        this_object()->receive_damage("qi",30000000000+random(30000000000));


        if( !this_object()->is_busy() )
                this_object()->start_busy(2);
}
void init()
{
        object ob, me;

        me = this_player();
        ob = this_object();

        ::init();
        if( interactive(me) && visible(me) &&
            !is_fighting()) {
                //NPC_D->copy_from_me(ob, me, 10, 1);
        }
}
void kill_ob(object me)
{
	        object *obs;			
	        obs = all_inventory(environment(this_object()));		

if(!this_player())
{
::kill_ob(me);
return;
}

 if(this_player()->query("max_jing") > 1)
{
	command("say 受死吧！。\n");
      this_player()->start_busy(1);
	::kill_ob(me);
//    if( this_player()->query("doing") == "scheme" )
//		tell_object(this_player(),ZJSIZE(17)"敢在我面前开计划，看我秒杀你。\n"+NOR);
//
//		this_player()->unconcious();
}
}

void unconcious()
{
    die();
}
void die()
{
	object me,ob,memory,env,obj,item,corpse,obj1;
	mapping team;
        object *obs;
	
	string location;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();
	me = query_temp("last_damage_from");
//    message("channel:chat", HIG"【游戏GM】据说"+me->query("name")+"在钓鱼岛将"+name()+"斩于狠狠斩杀。\n"NOR,users());
	CHANNEL_D->do_channel( this_object(), "sys", HIY"地煞npc被杀死了！"+ZJURL("cmds:snoop "+me->query("id"))ZJSIZE(20)+""+me->query("name")+""NOR"\n");
		log_file("dangkou", sprintf("%s：%s(%s) 地煞副本boss。\n", ctime(time()),me->name(1),me->query("id")) );

        obs = all_inventory(environment(this_object()));

        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
	size = sizeof(team);
        env = environment(this_object());
		
/*        if (random(20) > 14)
        {
 		corpse = new("/clone/8yue/dishadan");
		corpse->set_amount(1);
        corpse->move(me);			

                message_vision("$N获得了1颗地煞丹。\n", me); 
        } else
        if (random(20) < 8)
        {
 		corpse = new("/clone/8yue/tiangang");
		corpse->set_amount(1);
        corpse->move(me);		
		message_vision("$N获得了1颗天罡丹。\n", me); 

   } else
        {
 		corpse = new("/clone/8yue/dishadan");
		corpse->set_amount(1);
        corpse->move(me);		
		message_vision("$N获得了1颗地煞丹。\n", me);          
             }		
*/
		
        me->add("yuanbao",50000000);
        me->add("swhs/exp",10000000);
        me->add("gongji",5);
		me->add("disha_jifen1",30);
      if(me->query("huoyuedian")<80)
{
      me->add("huoyuedian",5);
}

			
 		obj = new("/clone/money/xueye");
		obj->set_amount(70);
        obj->move(me);					
 		obj = new("/clone/money/jjd");
		obj->set_amount(70);
        obj->move(me);						
        tell_object(me,ZJSIZE(22)GRN"由于击杀boss之后你获得了：\n" +
        70 + "滴树精之血\n" +		
        70 + "个境界丹\n" +			
        30 + "地煞点券\n" +			

		        NOR);
//	destruct(ob);

        message_vision("\n$N摇身一晃，化为一缕缕青烟消散了。\n", this_object());
//        obj1 = new("/d/fuben/dangkou/npc/2");
//        obj1->move(environment(ob));
        destruct(ob);
}
