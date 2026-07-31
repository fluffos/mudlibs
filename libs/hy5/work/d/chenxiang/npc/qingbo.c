 // (C)1998-2000 Tie Yu
inherit NPC;
int tell_him();
int tell_him2();
void create()
{
        set_name("清波公子", ({ "prince qingbo","qingbo" }) );
        set("gender", "男性" );
        set("long","清波本是朝廷显赫，但因为犯上作乱，已经满门抄斩，唯独清波公子得以幸免。\n");
        set("age", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("per",30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "清波公子喃喃道：袁姬．．．袁姬．．我知道你来了．．．。\n",
        }) );
        set("inquiry", ([
                "袁姬" : (: tell_him :),
                "yuanji" : (: tell_him:),
                "十五月圆" : (: tell_him2 :),
                "shiwuyueyuan" : (: tell_him2 :),
        ])); 
        setup();
        carry_object(__DIR__"obj/scloth2")->wear();
} 
int tell_him()
{
 object me;
 me =this_player();
 tell_object(me,"清波公子道：袁姬本是和我青梅竹马，但因为我家被满门抄斩，\n");
 tell_object(me,"她已经被皇上纳入后宫了！\n");
 return 1;
} 
int tell_him2()
{
 object me;
 me =this_player();
 if (me->query("m_success/义助袁姬")==1) {
        message_vision("$N说，谢谢你帮助了我们团聚。\n",this_object());
   return 1;
 }
 if (me->query("m_success/义助袁姬")==2) {
        message_vision("$N痛哭流涕地说，晚了，晚了。\n",this_object());
        return 1;
 }
 if (me->query("m_success/义助袁姬")==3) {
        message_vision("$N怒道，你这个小人，害了我的袁姬。\n",this_object());
        this_object()->kill_ob(this_player());
        return 1;
 }      
 if(me->query_temp("marks/yuanji")) {
 tell_object(me,"清波公子声嘶力竭道：啊！你已经见过袁姬了！你救救我们，帮她逃离后宫吧！\n");
 tell_object(me,"清波公子颓丧道：但是她是当今皇上的妻妾！除非袁姬死了，我们恐怕再也见不到了！\n");
 command("cry");
 me->set_temp("marks/qingbo",1);
 return 1;
 } else return 0;
}         
