#include <ansi.h>
inherit NPC;
string ask_me();
void create()
{
        set_name(MAG"程灵素"NOR, ({
                "cheng lingsu",
                "cheng",
                }));
        set("long",
                "她是药王的高徒，妙手回春，有起死回生之神功。\n"
        );


        set("gender", "女性");
        set("attitude", "friendly");
        set("age",20);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 150);
        set("max_neili", 150);
        set("combat_exp", 1000);
        set("score", 1000);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("strike", 30);
        set_skill("parry", 40);
        set_skill("literate", 100);
        set("inquiry", ([
                "救人"     : (: ask_me :),
                "治病"     : (: ask_me :),
                "治病救人"   : (: ask_me :)
        ]));

        setup();

//        carry_object("/d/shaolin/obj/changjian")->wield();
//        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

void init()

{       
        object me, ob;

        me = this_object();

        ::init();
        if( objectp(ob = present("lie hu", environment())) )
        {
                remove_call_out("repairing_1");
                call_out("repairing_1", 5, me, ob);
        }
}

int repairing_1(object me, object ob)
{       object mee=this_player();
        if ( !present(ob, environment()) ) return 1; 

        command("say 哎呀，伤得这么重啊！我来看看。\n");
        message_vision(GRN"\n程神医轻轻解开老猎户的衣襟，仔细地检验伤口，不禁微微皱起了眉头。\n"NOR);
        message_vision(GRN "\n她接着从怀里掏出许多纱布，小刀小镊之类的东西，精心地刮去腐肉，\n清理伤口,又细心地包扎起来。\n\n" NOR, me);
        command("sigh");
        command("say 他的伤如果再早几天治，还是有救的。现在病已入骨，纵使扁雀重生，华佗再世，
                     怕也难了。不过还有一线希望：我早年听恩师说过，有一种奇药，采天地之精华，
                     集日月之灵气，有起死回生之神效，或许还救得他的性命。只是此药配方极其难得，
                     是以从古至今也未曾有人配得几颗，这位"+ RANK_D->query_respect(mee) + "如能采全,
                     当可成就功德一件，配置此药需要：\n"+
                         HIR"千年灵芝、黑熊熊胆、新鲜麝香、白虎虎骨\n"NOR +
                          "以"+HIG"上古玄冰"NOR+"做药引，方可配成啊！\n" );
                     
        return 1;
}

int do_back(object me)
{
        me->move("/d/shaolin/twdian");
        return 1;
}

string ask_me()
{
        mapping fam; 
        object ob;

        ob = this_player();
        command("say 从医者以扶危济世，治病救人为本分， 好吧，我跟你去看看。");
        command("follow " + ob->query("id"));
        ob->set_temp("救人",1);
        return "我们走罢！\n";
}
int accept_object(object me, object ob)
{
        object obb; 
        object sss=this_object();
        if(!me->query_temp("救人")|| !present("lie hu", environment() )) {return 1;}
        if (ob->query("id")=="she xiang") {
           if (me->query_temp("xiong") && me->query_temp("ling") && me->query_temp("xuan") && me->query_temp("hu")){
                command("say 辛苦" + RANK_D->query_respect(me) +
                ",这颗丸药给老人家服下，他的性命可保。\n");  
              me->delete_temp("xiong");
              me->delete_temp("hu");
              me->delete_temp("ling");
              me->delete_temp("xuan");
              me->delete_temp("she");  
              me->delete_temp("救人");  

              obb = new(__DIR__"obj/shanlw");
              obb->move(this_player());  
              message_vision(GRN "\n程神医翩然离去。\n" NOR, me);
                sss->move("/d/shaolin/guangchang3");
              return 1;
              }
         else {
              command("nod " + me->query("id"));
              me->set_temp("she",1);
              return 1;
              }
        }
       if (ob->query("id")=="hu gu") {
           if (me->query_temp("xiong") && me->query_temp("ling") && me->query_temp("xuan") && me->query_temp("she")){
                command("say 辛苦" + RANK_D->query_respect(me) +
                ",这颗丸药给老人家服下，他的性命可保。\n");  
              me->delete_temp("xiong");
              me->delete_temp("hu");
              me->delete_temp("ling");
              me->delete_temp("xuan");
              me->delete_temp("she");  
              me->delete_temp("救人");          
              obb = new(__DIR__"obj/shanlw");
              obb->move(this_player());  
              message_vision(GRN "\n程神医翩然离去。\n" NOR, me);
                sss->move("/d/shaolin/guangchang3");
              return 1;
              }
         else {
              command("nod " + me->query("id"));
              me->set_temp("hu",1);
              return 1;
              }
        } 
       if (ob->query("id")=="xuan bing") {
           if (me->query_temp("xiong") && me->query_temp("ling") && me->query_temp("she") && me->query_temp("hu")){
                command("say 辛苦" + RANK_D->query_respect(me) +
                ",这颗丸药给老人家服下，他的性命可保。\n");  
              me->delete_temp("xiong");
              me->delete_temp("hu");
              me->delete_temp("ling");
              me->delete_temp("xuan");
              me->delete_temp("she");  
              me->delete_temp("救人");          
              obb = new(__DIR__"obj/shanlw");
              obb->move(this_player());  
              message_vision(GRN "\n程神医翩然离去。\n" NOR, me);
                sss->move("/d/shaolin/guangchang3");
              return 1;
              }
         else {
              command("nod " + me->query("id"));
              me->set_temp("xuan",1);
              return 1;
              }
        } 
       if (ob->query("id")=="xiong dan") {
           if (me->query_temp("she") && me->query_temp("ling") && me->query_temp("xuan") && me->query_temp("hu")){
                command("say 辛苦" + RANK_D->query_respect(me) +
                ",这颗丸药给老人家服下，他的性命可保。\n");  
              me->delete_temp("xiong");
              me->delete_temp("hu");
              me->delete_temp("ling");
              me->delete_temp("xuan");
              me->delete_temp("she");  
              obb = new(__DIR__"obj/shanlw");
              me->delete_temp("救人");  
              obb->move(this_player());  
              message_vision(GRN "\n程神医翩然离去。\n" NOR, me);
                sss->move("/d/shaolin/guangchang3");
              return 1;
              }
         else {
            command("nod " + me->query("id"));
              me->set_temp("xiong",1);
              return 1;
              }
        }
        if (ob->query("id")=="ling zhi") {
                if (me->query_temp("xiong") && me->query_temp("she") && me->query_temp("xuan") && me->query_temp("hu")){
                command("say 辛苦" + RANK_D->query_respect(me) +
                ",这颗丸药给老人家服下，他的性命可保。\n");  
              me->delete_temp("xiong");
              me->delete_temp("hu");
              me->delete_temp("ling");
              me->delete_temp("xuan");
              me->delete_temp("she");  
              me->delete_temp("救人");  
              obb = new(__DIR__"obj/shanlw");
              obb->move(this_player());  
              message_vision(GRN "\n程神医翩然离去。\n" NOR, me);
                sss->move("/d/shaolin/guangchang3");
              return 1;
              }
         else {
              command("nod " + me->query("id"));
              me->set_temp("ling",1);
              return 1;
              }
        }
        return 0;
       
}
