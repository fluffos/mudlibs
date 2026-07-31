 //TIE
inherit NPC; 
void create()
{
        set_name("郭嵩阳", ({ "guo", "yang"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位兵器谱上有名的高手，但他现在没剑．．．\n");
        set("title", "嵩阳铁剑");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("sword", 100);
        set_skill("dodge", 40);
        setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
} 
int recognize_apprentice(object ob)
{
        if( !ob->query("marks/guo") ){
                say("郭嵩阳道：我连剑都没有....\n");
                return 0;
        } 
        return 1;
} 
int accept_object(object who, object ob)
{
        if(ob->query("id") == "guo sword")
        {
                who->set("marks/guo", 1);
                say("郭嵩阳说道：好！好！好！太好了！你没拜我为师，
别的不能教你，但几手基本剑法还是可以的！\n");
        if(!who->query("m_success/郭嵩阳"))
        {
                who->set("m_success/郭嵩阳",1);
                who->add("score",400); 
        } 
                return 1;
        }
        return 0; 
}   
