inherit NPC;
#include <ansi.h>
string *make_msg = ({
    HIY "阿宝微笑的看著你说道：谢谢您了!\n\n" NOR,
    HIY "阿宝想了想，似乎觉得应该报答您，但又不知道怎么报答好。\n\n" NOR,
    HIY "阿宝脸一红道：嗯! 就把我的这个梳子给您吧! \n\n" NOR,
});
void create()
{
        seteuid(getuid());
        set_name("阿宝", ({ "arbao" }) );
        set("rank", "盗贼");
        set("gender", "女性" );
        set("combat_exp", 4000);
        set("spi", 18);
        set("int", 19);
        set("con", 17);
        set_skill("stealing", 40);
        set_skill("dodge", 35);
        set_skill("dagger", 40);
        set_skill("sword", 30);
        set_skill("parry", 10);
        //set_skill("chunqiubifa", 20);
        //map_skill("parry", "chunqiubifa");
        set("age", 15);
        set("long",
                "这个十五、六岁的小姑娘就是「阿宝」了，她身上虽然穿著粗布\n"
                "衣服，但却十足是个美人胚子，一双水汪汪的大眼睛骨碌碌地转\n"
                "著，还不时盯著你看，使你不禁觉得有些发窘。\n");
        setup();
       	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();


        set("inquiry", ([
              "here" : "嘻，您自己爬上来的啊，难道不知道是哪里？\n",
              "name" : "讨厌啦，问人家这么脸红的问题\n", 
               ]) );
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
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        switch( random(2) ) {
                case 0:
                  say( "喂 ... 我肚子好饿，有没有吃的，我好想吃爱窝窝？\n");
                        break;
                case 1:
                  say( "阿宝对你微笑， \n 说道：嘘 ...这位" +
RANK_D->query_respect(ob)
                   + "，别让婆婆知道我在这里 ...。\n");
        }
}
int accept_object(object who, object ob)
{
     string objname;
     objname = (string)ob->name();
        if ( objname != "爱窝窝")  {
           command("smile");
            say ( HIY "谢谢您?! 怎麽好意思!真是谢谢你。\n" NOR);
           command("blush");
             return 1;
            }
        if( !who->query_temp("阿宝/爱窝窝") )  {
          call_out( "make_stage", 2, who, 0 );
            who->set_temp("阿宝/爱窝窝", 1);
         } else {
             say (HIY "我已经不饿了，再次谢谢您了! \n" NOR);
             return 1;
          }
          return 1;
}
void make_stage(object who, int stage)
{
     object obj;
     tell_object(who, make_msg[stage]);
     if( ++stage < sizeof(make_msg) ) {
         call_out( "make_stage", 2, who, stage );
         return;
     } else
       obj = new(__DIR__"obj/comb");
       obj->move(who);
    return;
}
