
inherit NPC;
int ask_shu();

void create()
{
	seteuid(getuid());

	set_name("仆人", ({"puren",}));
	set("gender", "男性");
	set("age", 20);
	set("long", "这是个仆役打扮的年青人，两眼乱转，四处看个不停,好象害怕什么。\n");
	set("attitude","heroism");
	set("generation",0);
	set("winner","none");

	set("str",20);
	set("con",20);
	set("int",20);
	set("dex",20);
	set("max_qi",200);
	set("eff_qi",200);
	set("qi",80);
	set("max_jing",200);
	set("jing",200);
	set("neili",0);
	set("max_neili",0);
	set("shen_type",1);
	set("no_clean_up",1);
	set("combat_exp",1000);

	set_skill("force",20);
	set_skill("unarmed",20);
	set_skill("dodge",20);
	set_skill("parry",20);
        set("inquiry", ([
                "佛堂" :  "你也知道佛堂里有书？\n",
                "便宜一些" :  "没戏！\n",
                "书" :   (: ask_shu :),
                "四十二章经" :  (: ask_shu :),
                "秘密" :  (: ask_shu :),
                "钥匙" :  (: ask_shu :),
               ]) );

	setup();
        carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() >= 1000000)
        {
                who->set_temp("money2_paid",1);
                return 1;
        }
        return 0;
}

int ask_shu()
{
	if (this_player()->query_temp("money2_paid"))
	{
		this_player()->delete_temp("money2_paid");
		say("仆役说道：地板下面有暗锁，钥匙在佛像左耳里。\n");
		say("仆役又说：货真价实，不会骗你的。实在不行你回头来找我。\n");
                this_player()->delete_temp("money2_paid");
                this_player()->set_temp("book42_asked", 1);
		return 1;
	}
	say("仆役说道：干什么也得先交钱啊。\n");
	say("仆役又说：我花了一年多时间才查到这件物事的所在，\n"+
	"你这一万两银子，可不是好赚的。\n");
	return 1;
}
