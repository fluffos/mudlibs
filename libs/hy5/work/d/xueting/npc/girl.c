// girl.c
inherit NPC;
#include <ansi.h>
string *make_msg = ({
    MAG "白衣女子冷冷的看著你说道：谢谢你了!\n\n" NOR,
    MAG "白衣女子盯着你的双眼，仿佛要看穿你的内心。\n\n" NOR,
    MAG "白衣女子道：这把剑你拿去，记住这可不是普通的剑啊! \n\n" NOR,
    MAG "白衣女子转过身，背对着你道：快滚，否则我还要杀了你。\n\n" NOR,
});
void create()
{
        set_name("白衣女子", ({ "girl" }) );
        set("con", 21);
        set("str", 19);
        set("spi", 22);
        set("per", 22);
        set("int", 20);
        set("gender", "女性" );
        set("combat_exp", 555000);
        set_skill("sword", 350);
        set_skill("dodge", 350);
        //set_skill("chunqiubifa", 150);
        set_skill("parry", 250);
        set_skill("blade", 70);
        set_skill("dagger", 70);
      //  map_skill("parry", "chunqiubifa");
        set("age", 19);
        set("long",
                "一个身穿白衣的女子，看起来年纪不会超过二十岁，容貌虽不甚美，却\n"
                "别有一股灵秀之气，令人凛然不敢轻侮。\n" );
        setup();
   //     carry_object(__DIR__"obj/white_dress")->wear();
   //     carry_object(__DIR__"obj/slasher_sword")->wield();
        set("inquiry", ([
              "here" : "滚出去，这里不是你应该来的地方。\n",
              "name" : "再多嘴我杀了你。\n", 
              "古铜发簪" : "您怎么知道我丢了发簪，是不是你偷了。\n", 
              "发簪" : "您怎么知道我丢了发簪，是不是你偷了。\n", 
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
                  say( "白衣女冷冷的道：滚出去，否则我杀了你！\n");
                        break;
                case 1:
                  say( "白衣女子叱道：滚，难道你准备找死。\n");
        }
}
int accept_object(object who, object ob)
{
     string objname;
     objname = (string)ob->name();
        if ( objname != "古铜发簪")  {
           command("heng");
            say ( MAG "谢谢!可惜我对这个没兴趣....\n" NOR);
           command("blush");
             return 1;
            }
        if( !who->query_temp("白衣女子/发簪") )  {
          call_out( "make_stage", 2, who, 0 );
            who->set_temp("白衣女子/发簪", 1);
         } else {
             say (HIY "怎么会还有，难道刚才你给我的是假的! \n" NOR);
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
       obj = new("/d/xueting/npc/obj/slasher_sword");
       obj->move(who);
    return;
}
