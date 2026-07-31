//dizi3.c 万圭

#include <ansi.h>
inherit NPC;
string ask_me(object);

string* tools = ({
       __DIR__"obj/beixin",
       __DIR__"obj/armor",
       __DIR__"obj/junfu",
}); 

void create()
{
       set_name("万圭",({ "wan gui", "wan","gui" }) );
       set("title","襄阳武馆三弟子");
       set("gender", "男性" );
       set("age", 26);
       set("long","他是万震山的独子，长身玉立，脸型微见瘦削，俊美潇洒。\n");
       set("combat_exp", 4000);
       set("attitude", "friendly");

       set_skill("force", 30);
       set_skill("strike", 30);
       set_skill("sword", 30);

       set("inquiry", ([
              "防具" : (: ask_me :),
       ]) );
       setup();

       set("huju_count", 10);       
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

string ask_me(string name)
{        
        object tool;

        if (present("armor", this_player()) || present("junfu",this_player()) || present ("pi beixin",this_player()))
            return RANK_D->query_respect(this_player())+"你不是已经来要过防具了，怎么又来要了？可真贪心哦！";
 
        if (query("huju_count") < 1)
            return "抱歉，你来得不是时候，防具已经发完了。";

        if (this_player()->query_temp("getarmor"))
            return RANK_D->query_respect(this_player())+"你不是已经来要过防具了，怎么又来要了？可真贪心哦！";

        tool = new( tools[random(sizeof(tools))]);
        tool->set("value",10);
        tool->move(this_player());        
        this_player()->set_temp("getarmor", 1);
        add("huju_count", -1);
        message_vision("万圭给了$N一件"+tool->name()+"。\n", this_player());
        return "拿去吧。不过要记住，防具只可防身练武，不可凭此妨害他人。";
}     
 
void greeting(object ob)
{       
       command("bow "+ob->query("id"));
       command("say 这位" + RANK_D->query_respect(ob)
                                + "，到我这领防具 "HIY HBCYN"ask wan about 防具"CYN" 吧。"NOR);
}                               
