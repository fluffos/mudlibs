 // teacher.c
inherit NPC; 
void create()
{
        set_name("梦焕", ({ "meng huan", "huan" }) );
        create_family("东林寺", 20, "弟子");
        set("title", "笔下生花");
        set("vendetta_mark","shaolin");
        set("int",5);
        set("skill_public",1);
        set("gender", "男性" );
        set("age", 57);
        set("chat_chance", 2);
        set("chat_msg", ({
                "梦焕嘀咕道：＂不知道是谁偷了本寺的经书？＂\n",
        }) );
        set("long",
                "梦焕原姓孟,年轻时中过秀才，曾经是滁县的父母官,在任期间曾屡破疑案,\n"
                "可惜为奸佞所忌,仕途坎坷，终于看破红尘,出家为僧。\n");
        set("attitude", "peaceful");
        set_skill("literate", 150);
        set_skill("buddhism",100);
        setup();
}  
int recognize_apprentice(object ob)
{
        if(ob->query("free_learn/literate"))
        return 1;
        else {
                if( ob->query("m_success/勇保经书")) 
                {
                command ("say 好，好，你为本寺立了大功，如果你愿学读书和佛法，小僧当竭力相助。\n");
                ob->set("free_learn/literate", 1);
                return 1;
                }
                command ("say 东林寺多灾多难，最近有个胆大包天的又私闯藏经阁,小僧受方丈之嘱下山探访,无暇顾及诗书之事.");
                return 0;
        }
}     
