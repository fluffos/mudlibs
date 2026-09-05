//郭靖 李萍的儿子：）
//created by zine 30 Aug 2010

inherit NPC;
int ask_bian();
void create()
{
        set_name("郭靖", ({ "guo jing", "guo", "jing" }) );
        set("gender", "男性" );
		set("title", "小牧童");
        set("age", 4);
        set("long", 
            "他就是未来的射雕大侠郭靖，虽然他现在还很小。\n");
        set("str", 30);
        set("dex", 15);
        set("con", 15);
        set("int", 5);
		set("shen_type", 1);
		set("combat_exp", 50);
		set("max_qi", 30);
        set("max_jing", 30);
        set("neili", 1);
        set("max_neili", 1);
		set("attitude", "friendly");
        set("inquiry", ([
            "name" : "我的名字叫郭靖。",
            "李萍" : "李萍是我娘，她是我最亲的人 。",
            "报仇" : "我长大了一定要为爹爹报仇。",
			"段天德" : "我娘说是段天德这狗贼害死了爹爹。",
			"小山坡" : "小山坡就在出了蒙古包往东走就到了。",
            "here" : "这里是大草原，你连这都不知道，真是一个笨蛋。",
			"羊鞭" : (: ask_bian :),
            "放羊" : (: ask_bian :),
            
       	]) );
		set("chat_chance", 2);
        set("chat_msg", ({
                "郭靖说道：现在除了小山坡，其他地方都没有牧草了。\n",
                
        }) );
        setup();
		carry_object(__DIR__"items/pixue")->wear();
		carry_object(__DIR__"items/cloth2")->wear();
		
}


int ask_bian()
{
	object me=this_player();
    if (me->query_temp("guojing/yangbianask"))
    {
        command("say 你不是刚问过我吗？你怎么那么健忘，大家都说我笨，看来你比我还笨啊。");
        return 1;
    }
	command("say 我今天生病了，你愿意替我牧羊，那太好啦。");
	command("say 羊鞭就在门外的角落里，你找(zhao)一下就找到了。");
	me->set_temp("guojing/yangbianask",1);
	return 1;
}