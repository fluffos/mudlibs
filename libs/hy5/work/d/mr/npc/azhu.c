//  /u/beyond/mr/npc/azhu.c 阿珠
// this is made by beyond
// update 1997.6.23
#include <ansi.h>
inherit NPC; 
string ask_sword();
void create()
{
set_name("阿朱", ({ "a zhu", "a", "zhu" }));
        set("gender", "女性");
        set("age", 20);              
	set("title",GRN"贴身丫鬟"NOR);
	set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("per", 30);
        set("combat_exp", 14000);
        set("shen_type", 0);
        set("attitude", "peaceful");
	set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
	set("jiali",30);
	set("score", 8000);

        set_skill("cuff", 50);
	set_skill("parry",50);
	set_skill("yanling-shenfa",50);
        set_skill("dodge", 50);
	set_skill("force",50);
	set_skill("shenyuan-gong",50);

	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");      
         
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/red_silk")->wear();
        carry_object(__DIR__"obj/skirt")->wear();
        set("inquiry", ([
            "name" : "我就是慕容公子的贴身丫鬟阿珠，好久不见公子不知出事没有。\n",
            "here" : "这里是听香水榭，是慕容老爷为了照顾我，给我安排的住处。\n",
            "rumors" : "最近有一个大和尚来燕子坞，要去还施水阁看武功秘籍，他好厉害呀。\n",
            "慕容复" : "慕容复是我们燕子坞的主人，以以彼之道，还施彼身而天下闻名。\n",
            "还施水阁" : "我只知道还施水阁是公子藏书的地方，可不知具体在什么地方。\n",
            "阿碧" : "阿碧是我的好美眉，她住在琴韵小筑，和我一样是公子的贴身丫鬟。\n",   
            "后厅" : "后厅在燕子坞的南面那里供奉着老爷子的灵位和生前的事物。\n",       
            "供奉" : "后厅供奉着老爷子的灵位和一把生前的宝剑，名为碧玉剑，江湖人事都携带俸品来供奉在灵位前。\n",
            "碧玉剑" : (: ask_sword :),
        ]));
}
string ask_sword()
{
mapping fam; 
// object ob
	if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "姑苏慕容")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
		return "碧玉剑是老爷子仙逝后的遗物，公子让我收起来好好保管，我把它放到后厅供起来了！\n";
}
