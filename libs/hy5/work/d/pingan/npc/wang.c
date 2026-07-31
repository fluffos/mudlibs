#include <ansi.h>
inherit NPC;
void create()
{
        set_name("王捕头", ({ "wang xunbu", "wang" , "xunbu"}) );
        set("long",
"王捕头是个京城的捕头！乐于助人，你可以向他打听[取消通缉]的情况。\n");
        set("title", BLU"超级名捕"NOR);
        set("attitude", "peaceful");
        set("combat_exp",4000000);
        set("str",60);
        set("per",10);
        set("int",80);
        set("force_factor", 100);
        set("max_force",5000);
        set("force",5000);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force",200);
        set_skill("chanchu-bufa",200);
        set_skill("hamagong",200);
        set_skill("shexing-diaoshou",200);
        set_skill("lingshe-zhangfa",200);
        set_skill("staff",200);

        map_skill("dodge", "chanchu-bufa");
        map_skill("force", "hamagong");
        map_skill("parry", "lingshe-zhangfa");
        map_skill("unarmed", "shexing-diaoshou");
        map_skill("staff", "lingshe-zhangfa");
        
//        set("inquiry", ([
//                "减叛师记录"          :"你找对人了，就是我能给你减判师记录(jian 判师记录)。\n",
//                "叛师"          :"唉，后悔背叛师门了吧。\n",
//                "叛师记录"          :"要是你以前曾经有过一次叛师师门的话，你的师傅可不愿意教你更高深的功夫！\n",
//                "减叛师"          :"你找对人了，就是我能给你减判师记录(jian 判师记录)。\n",
//                "减记录"          :"你找对人了，就是我能给你减判师记录(jian 判师记录)。\n",
//        ]) );
        setup();


}
int accept_fight(object me)
{
        command("say 王捕头说：你还不配和我过招。");
        return 0;
}
void init()
{
        add_action("do_jian","jian");
}

int do_jian(string arg)
{
        object me;
        mapping my_skl;
        string *skl_name;
        int i,*level;
        me= this_player();
        if (arg != "通缉记录") 
                return notify_fail("你要减什么？\n");
//      call snowfly->apply_condition("killer",0);
        if (me->apply_condition("killer") < 1) 
                return notify_fail("你正在通缉中吗？\n");
        my_skl=me->query_skills();
        if(mapp(my_skl)) {
        		skl_name = keys(my_skl);
        		level=values(my_skl);
        		for (i=0;i<sizeof(skl_name);i++)
{
if (level[i]>2)
        		me->set_skill(skl_name[i],level[i]-1);
}
                  }
        message_vision(MAG"$N跪在了地上，开始忏悔往事，后悔呀。。。后悔。。。\n\n"NOR,me);
        me->set("combat_exp", me->query("combat_exp") - me->query("combat_exp") /10);
        me->apply_condition("killer",0);
//        me->add("betrayer",-1);
//        me->set("title","普通百姓");
//        me->set("class","0");
//        me->delete("family");
//        me->delete("party");
        me->start_busy(3);
        me->set("score",me->query("score") - me->query("score") /10);
        return 1;
}

