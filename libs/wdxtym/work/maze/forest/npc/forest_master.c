inherit NPC;
#include <ansi.h>

void give_reward_forest(object ob, int ref_exp);

mapping itemlist = ([      
        "/d/maze/forest/npc/obj/bear_dan":1,
        "/d/maze/forest/npc/obj/bear_hand":5,
        "/d/maze/forest/npc/obj/bear_skin":10,
        "/d/maze/forest/npc/obj/snake_egg":1,
        "/d/maze/forest/npc/obj/snake_dan":5,
        "/d/maze/forest/npc/obj/snake_skin":10,
        "/d/maze/forest/npc/obj/tiger_xxx":1,
        "/d/maze/forest/npc/obj/tiger_bone":5,
        "/d/maze/forest/npc/obj/tiger_skin":10,
        "/d/maze/forest/npc/obj/wolf_eye":1,
        "/d/maze/forest/npc/obj/wolf_meat":5,
        "/d/maze/forest/npc/obj/wolf_skin":10,
        "/d/maze/forest/npc/obj/dragon_skin":3,
        "/d/maze/forest/npc/rabbit":1,
        "/d/maze/forest/npc/toad":1,
]);

void create()
{
        set_name(HIG "丛林狩猎者" NOR, ({ "forest hunter","hunter" }) );

        set("gender", "男性");
        set("age", 30);
        set("long",
                GRN"\n    这是一个猎物收购者，给他一定数量的猎物，获取你的奖励！
                \n      十张狼皮  五块狼肉  一对狼眼
                \n      十张熊皮  五只熊掌  一只熊胆	
                \n      十张虎皮  五具虎骨  一根虎鞭
                \n      十张蛇皮  五个蛇胆  一个蛇蛋
                \n      三块龙鳞  一个龙蛋
                \n      一只流氓兔
                \n"NOR);
        set("attitude", "peaceful");
        set("str", 26000);
        set("com", 30);
        set("int", 24);
        set("dex", 30);
        set("per", 50);



        set("chat_chance", 10);
        set("chat_msg", ({
                BLU"丛林狩猎者说道：收购各种猎物。\n"NOR ,
	        YEL"丛林狩猎者说道：唉，我那走丢了的孩子啊......\n"NOR ,

        }) );

        set("combat_exp", 11000000);
        set("attitude", "peaceful");

        set_skill("unarmed", 300);
        set_skill("dodge", 300);

        set("max_qi", 4500);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);

        setup();

}

int accept_object(object me, object obj)
{
	string filename;
	int need_amount,amount,exp;
	filename = base_name(obj);
	
	if (undefinedp(itemlist[filename]))
        {
	        command("shake");
                command("say 这是什么东西，我不需要！");
                return 0;
        }
        
        need_amount = itemlist[filename];
	if (need_amount<=0 )
		return 0;
	if (function_exists("query_amount",obj) && obj->query_amount()<need_amount )
		return 0;

        exp = 1000;

	if (function_exists("query_amount",obj))
		amount = obj->query_amount();
	else 
		amount = 1;

	exp = exp/need_amount*amount;

        command("pat "+me->query("id"));
	give_reward_forest(me,exp);
        destruct(obj);
	return 1;
}

void give_reward_forest(object ob, int ref_exp) 
{
	//ref_exp是参考修为，exp不影响gold，高级玩家可以到forest挣钱
        mixed user_exp;
        int exp,pot,mar,score,gold;
	string reward_msg;
        // gold = ref_exp/500;
	user_exp = ob->query("combat_exp");
        if (count_lt(user_exp,1000000))
		exp = ref_exp*5/4;
        else if (count_lt(user_exp,4000000))
		exp = ref_exp;
        else if (count_lt(user_exp,6000000))
		exp = ref_exp/2;
        else if (count_lt(user_exp,8000000))
		exp = ref_exp/4;
	else
		exp = ref_exp/10;;

	pot = exp/2;
        score = exp/50;
        mar = exp/30;
        gold = ref_exp/100;
        if (gold < 1) gold = 1;
        /*
	reward_msg =GRN"你得到了报酬：\n\t\t" +
	chinese_number(exp) + "点实战修为\n\t\t"+
	chinese_number(pot) + "点潜能\n\t\t" +
        chinese_number(mar) + "点体会\n\t\t" +
	chinese_number(score) + "点评价\n\t\t" + 
	chinese_number(gold) + "两黄金\n"NOR;
	tell_object(ob,reward_msg);

	ob->add("combat_exp",exp);
	ob->add("potential",pot);
        ob->add("experience",mar); 
	ob->add("score",score);
	ob->add("balance",gold*10000);
	*/
	
	GIFT_D->work_bonus(ob, ([ "exp" : exp, "pot" : pot, "mar" : mar, 
	                          "score" : score, "gold" : gold ]));
}
