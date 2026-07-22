// girl-2.c

inherit NPC;

void create()
{
	set_name("玉亭亭", ({ "yu ting" }) );
	set("title", "名妓");
	set("gender", "女性" );
	set("age", 22);
	set("str", 12);
	set("per", 50);
	set("long", @LONG
    她就是你日夜思念的梦中之人！真是有沉鱼落雁之容，
闭月羞花之貌。不过........她好象不卖身。
LONG
);
	set("combat_exp", 1000);
	set("attitude", "friendly");

        set("chat_chance_combat", 25);
        set("chat_msg_combat", ({
"玉娇娇微微冲你一笑，你已经神魂颠倒了！\n",
	}) );

	set_skill("literate", 80);
//        set_skill("music", 100)

	set("inquiry", ([
		"name" : "我就是玉娇娇。。",
		"here": "您要听我弹一曲吗？",
		"弹一曲": "收五两黄金。",
		"过夜": "小女子不卖身。",
		"sex": "对不起，小女子不卖身。",
	]) );

	setup();
	
	carry_object(__DIR__"obj/pink_cloth")->wear();
//   carry_object(__DIR__"obj/silk_bra")->wear();
       carry_object(__DIR__"obj/pipa")->wield();
// carry_object(__DIR__"obj/color_pants")->wear();
}

int recognize_apprentice(object ob)
{
        if( !ob->query("marks/玉娇娇") ) {
                say("玉娇娇道：咦？我不记得您啊......\n");
                return 0;
        }
        return 1;
}

int accept_object(object who, object ob)
{
	if( ob->value()<1 ){
 	        command("say 对不起，我有点累，想休息了！");
               return 0;
              } 
       if( ob->value()<50000) {
	        command("say 对不起，我今天太累了！");
               return 0;
              }
       if( this_player()->query("str") < 20) {
               command("chat 又来了个调戏我的无赖！！！");
               return 0;
              }
        
	 command("say 我开始唱了。\n");
        say("   玉娇娇闭上了双眼，右手轻轻的弹起琵琶来。 \n");
        say("你听着玉娇娇的琵琶曲，心里平静多了，你已经和曲子融入到了一起。\n");
        say("   一曲下来，你好象忘掉了一切烦恼。\n    你悟到了一个新的境界。\n"); 
        this_player()->receive_heal("gin",80); 
        this_player()->receive_heal("kee",80); 
        this_player()->receive_heal("sen",80); 
        return 1;
}

int accept_fight(object me)
{
	command("chat 救命呀！杀人啦！！！！！");
	return 0;
}

