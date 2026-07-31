// mei.c
inherit NPC;
#include <ansi.h>;
void create()
{
        set_name( "梅超风" ,({ "mei chaofeng", "mei" }));
        set("title", "黑风双煞");
        set("nickname", HIB"铁尸"NOR);
        set("gender", "女性");
        set("age", 32);
        set("long",
            "梅超风是黄药师唯一的女弟子，本来极受黄药师疼爱，可惜她与师兄陈玄风\n"
            "暗生情愫，他们偷了《九阴真经下卷》私奔。\n"
            "她面色大概因为久居海岛显得黝黑，模样却颇为俏丽。她在桃花弟子中尤精\n"
            "通鞭法。\n");
        set("attitude", "aggressive");
        set("str", 27);
        set("int", 32);
        set("con", 35);
        set("max_qi",26500);
        set("max_jing",26000);
        set("neili", 22500);
        set("max_neili", 22500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 5200000);

        set_skill("claw", 280);
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("dodge", 220);
        set_skill("jiuyin-baiguzhao", 320);
        set_skill("bibo-shengong", 290);
        set_skill("anying-fuxiang", 290);

        map_skill("force", "bibo-shengong");
        map_skill("parry", "luoying-shenjian");
        map_skill("dodge", "anying-fuxiang");
        map_skill("claw", "jiuyin-baiguzhao");
        prepare_skill("claw", "jiuyin-baiguzhao");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "claw.zhua" :),
                (: perform_action, "claw.cuijin" :),
                (: perform_action, "claw.zhua" :),
        }) );

        create_family("桃花岛", 2, "被逐弟子");
        set("inquiry", ([
           "铁尸":     "江湖上的人都这么叫我的，你怕不怕？哈哈哈哈。",
           "东邪":     "那是我师父的绰号。",
           "西毒":     "那是与家师齐名的高手之一，是个老毒物，住在白驼山。",
           "南帝":     "段王爷已出家当和尚去了，法名叫一灯。",
           "北丐":     "北丐统领中原的丐帮，势力颇为强大。",
           "梅超风":   "不就是我么？你是白痴啊？",
           "黄药师":   "他是我师父。"]) );
        setup();
        carry_object("/kungfu/class/taohua/obj/bupao")->wear();
}



void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}


void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}


void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	if(((int)who->query("jinyong/book5")>=1))
	{
//::die();	
	}
        else if(who) {
  	if(!who->query("jinyong/book5") && who->query("combat_exp",1) >= 800000 )
{
		message_vision("$N说道：不 不 不！\n" NOR,this_object());
		i = 800+random(2000);
		who->set("jinyong/book5",1);
		who->add("combat_exp",i+9000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+9000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
}
        }
	call_out("leavet",1);
}


void leavet()
{
        object ob = this_object();
 message_vision("$N飞身向北方逃去！\n" NOR,this_object());
        destruct(this_object());
}