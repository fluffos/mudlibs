// /u/poq/sdxl/npc/choudiao.c 丑雕
// by poq@jyqx 97/7
// amend dubei

inherit NPC;

void create()
{
    set_name("丑雕", ({ "chou diao","chou","diao"}) );
    set("long", @LONG
眼前赫然是一头大雕，那雕身形甚巨，比人还高，形貌丑陋之极，全身羽毛疏
疏落落，似是被人拔去了一大半似的，毛色黄黑，显得甚是肮脏，模样与桃花岛上
的双雕倒也有五分相似，丑俊却是天差地远。这丑雕钓嘴弯曲，头顶生著个血红的
大肉瘤，世上鸟类千万，从未见过如此古拙雄奇的猛禽。但见这雕迈著大步来去，
双腿奇粗，有时伸出羽翼，却又甚短，不知如何飞翔，只是高视阔步，自有一番威
武气概。
LONG
    );
    set("gender", "无性");
    set("age", 100);
    set("attitude", "peaceful");
    set("shen_type", 0);
    set("str", 44);
    set("int", 38);
    set("con", 42);
    set("dex", 44);

    set("max_qi", 34000);
    set("max_jing", 34000);
    set("neili", 34000);
    set("max_neili", 34000);
    set("combat_exp", 18000000);
    set_skill("force", 280);
    set_skill("dodge", 280);
    set_skill("unarmed", 280);
    set_skill("whip", 280);
    set_skill("parry", 280);
//    set("unique", 1);
//    set("startroom","/u/dubei/sdxl/pubu");

    set_temp("apply/attack", 200);
    set_temp("apply/defense", 200);
    	set_temp("apply/damage", 6560);
	set_temp("apply/armor", 6560);
    set("dan_count", 2);
    setup();

    set("chat_chance", 15);
    set("chat_msg", ({
        "丑雕仰起头来，高鸣三声。\n",
        (: random_move :),
    }) );
}
void init()
{
        object me, ob, where, ob0;
        ::init();
        ob = this_player();
        me = this_object();
        where = environment(me);
        if (interactive(ob = this_player()) && !is_fighting()
         && random(ob->query("kar"))+10>27 && query("dan_count") > 0
         && random(20)<5 ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob,me,where,ob0);
        }       
 
}

void greeting(object ob,object me,object where,object ob0)
{
        write("突有一股腥臭之气，显有大蛇之类毒物来到邻近。\n");
        message_vision("丑雕昂起头来，哇哇哇连叫三声，似向敌人挑战。\n",me);
        add("dan_count", -1);
        ob0 = new( __DIR__"dumang");
        ob0->move(where);
        message_vision("一条怪蟒突然窜了出来，气势凶凶。\n",me);
        me->kill_ob(ob0);
        ob0->fight_me(me);
        
}
