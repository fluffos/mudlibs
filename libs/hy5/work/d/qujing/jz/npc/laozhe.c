//Cracked by Roath
inherit NPC;
string ask_book();
void create()
{
        set_name("老者", ({"old man","lao zhe","man"}));
        set("gender", "男性");
        set("age", 58);
        set("long","一个年迂古稀的老人，听说他就爱替别人写状纸，而打报不平。");
        set("attitude", "friendly");
        set("per", 30);
        set("str", 30);
        set("combat_exp",2000);
	set("combat_exp",2000);	
        set("max_qi",300);
        set("max_jing",300);
        set("inquiry", ([
                "告状" : (: ask_book :),
                "状纸" : (: ask_book :),
                        ]) );
        setup();
}
string ask_book()
{
        object ob;
        object me = this_player();

        if(query_temp("no_zz")) 
        return "我这没有状纸了。";

        ob = new("/d/qujing/jz/obj/paper");
        if(random(10)==1 && !query_temp("no_zz")) {
        ob->move(this_player());
        set_temp("no_zz",1);
        return "看来您好象有血海深仇，这有写好的状纸，告状去吧。";
                                          }
        else
        return "平白无故，告什么状啊！";
}
