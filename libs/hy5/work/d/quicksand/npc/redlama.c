 // teacher.c
inherit NPC; 
void create()
{
        set_name("赤松", ({ "chi song", "song" }) );
        set("title", "三残喇嘛");
        set("gender", "男性" );
        set("class","lama");
        set("age", 52);
        set("skill_public",1);
        set("int", 30);
        create_family("大昭寺", 21, "弟子");
        set("long",
                "赤松本是葛伦高僧的得意大弟子，可是被人陷害。葛伦认为他偷\n"
                "了舍利子，将其逐出师门，囚于此谷，砍了他的双足，逼他说出\n"
                "舍利子的下落。不说出舍利子的下落，永不可回布达拉宫。\n"
                );
       set("chat_chance", 5);
        set("chat_msg", ({
                "赤松说道：谁帮我找回舍利子，我将全身功夫传给他！\n",
                "赤松说道：师傅说只要他在世一天，我就不能回布达拉宫。唉。。。\n"
        }) ); 
        set("inquiry", ([
                "舍利子": "嗯....舍利子一定是我师妹胭松盗走的。\n",
                "胭松": "胭松在布达拉宫城的大招寺里。",
        ]) );
        set("attitude", "peaceful");
        set_skill("iron-cloth", 180);
        set_skill("unarmed", 100);
        set_skill("bloodystrike", 80);
        set_skill("force", 100);
        set_skill("bolomiduo", 100);
        map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        set("combat_exp", 900000);
        setup();
} 
int recognize_apprentice(object ob)
{
        if( !ob->query("marks/song") ){
                say("赤松说道：你只有帮我回布达拉宫，我才会教你....\n");           
                return 0;
        } 
        return 1;
} 
int accept_object(object who, object ob)
{
        int bonus;
        if( ob->name() != "舍利子" && ob->name() != "九环禅杖")
        {
                       say("赤松说道：唉，我要的是舍利子....\n");
                        return 0;
        }
        if (ob->name() == "舍利子"&& ob->query("nature")!= "real" )
        {
                       say("赤松说道：唉，你也被普松骗了，这舍利子是假的....\n");
                        return 0;
        }
        if (ob->name()== "九环禅杖")
        {
                if (!who->query("marks/杀了葛伦")) return 0;
                else {
                say("赤松大惊失色：师傅，师傅他不在了？“\n");
                say("赤松叹了口气，也许我也该回去看看了。\n");
                say("赤松说：这位"+ RANK_D->query_respect(who)+"，谢谢你给我捎来消息。“\n");
                who->set("marks/song",1);
                if(!who->query("m_success/赤松"))
                {
                who->set("m_success/赤松",1);
                who->add("score",-1000);
                }
                return 1;
                }
        }
        else
        {
                who->set("marks/song", 1);
                say("赤松说道：好！好！好！太好了！我的冤终于见青天了....\n");
                bonus = random(50);
                who->add("combat_exp", bonus);
           bonus = bonus + random(10);
                who->add("potential", bonus );
                if(!who->query("m_success/赤松"))
                {
                who->set("m_success/赤松",1);
                who->add("score",400);
                }
                        return 1;       
        }
                return 1;
}       
