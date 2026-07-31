// teacher.c
// by Find.

inherit NPC;

void create()
{
	set_name("李侍尧", ({ "teacher li","teacher","li"}) );
	set("title", "教书匠");
	set("gender", "男性" );
	set("age", 47);
	set("int", 26);
	set("long",
		"李侍尧是这一带唯一的一个秀才，考取功名未成遂教书靠着\n"
		"微薄的学费为生。这里的居民都把子弟送来学习读书识字。\n");
        set("inquiry", ([
		"学费": "嗯....每次只要五两银子。\n",
		"读书识字": "对，我就是教这个。",
        ]) );
	set("attitude", "peaceful");
	set_skill("literate", 80);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if( !ob->query_temp("school/李侍尧") ){
                say("李侍尧说道：咦？我不记得收过你这个学生啊....\n");
                return 0;
        }

        return 1;
}

int accept_object(object who, object ob)
{
        if( !who->query_temp("marks/李侍尧") ) {
                if( ob->value() >= 500 ) {
                        say("李侍尧点了点头，说道：很好，有关读书识字(literate)的问题就尽管问吧。\n");
                        who->set_temp("school/李侍尧",1);
                        return 1;
                } else {
                        say("李侍尧说道：你的诚意不够，这钱还是拿回去吧。\n");
                        return 0;
                }
        } else
                say("李侍尧点了点头，说道：哦，象你这麽有心的学生还真是不多见，好好努力\n"
                        "                      将来必定前途无量，谢了。\n");
        return 1;
}