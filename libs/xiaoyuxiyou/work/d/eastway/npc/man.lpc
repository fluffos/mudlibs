inherit NPC;
int ask_send();
void create()
{	string name;
        set_name("驼背老人", ({"old man","man"}));
        set("age", 48);
        set("gender", "男性");
        set("attitude", "friendly");
        set("combat_exp", 3000);
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        set("inquiry", ([
          	"送饭": (: ask_send :),
]));
        setup();
}

int ask_send()
{
    	object newob;
    	object who=this_player();
    	object ob=this_object();
	message_vision("\n\n$N对$n说道：好吧！多谢这位" + RANK_D->query_respect(who) + "\n",this_object(),who);
        newob=new("/d/eastway/obj/fanlan");
	newob->move(who);
	return 1;
}