//Cracked by Roath
inherit NPC;

string *first_name = ({ "降龙",
			"伏虎",
			"清静",
			"接引",
			"归真",
			"金刚",
			"精进",
			"功德",
			"旃檀",
			"光明",
			"贤善",
			"庄严",
			"智慧",
			"日月",
			"妙音",
			"须弥",
			"金身",
			"广力"
});

string *name_words = ({"罗汉"});

int create()
{
	string name;
	name = first_name[random(18)];
	name+= name_words[random(sizeof(name_words))];

	set_name(name, ({"luo han", "luohan"}));
  	set("long", "南海观音座下十八罗汉。\n");
	set("title", "十八罗汉");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("rank_info/self", "贫僧");
        set("class", "bonze");
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("max_neili", 2000);

        create_family("南海普陀山", 2, "弟子");

        setup();
        carry_object("/d/xiyou/nanhai/obj/sengpao")->wear();
        carry_object("/d/xiyou/nanhai/obj/budd_staff")->wield();
        return 1;
}
