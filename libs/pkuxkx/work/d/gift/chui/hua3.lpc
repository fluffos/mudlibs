// 恢复死前武功用。
#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("无名花", ({"hua", "wuming"}));
        set("unit", "朵");
                set("value", 30);
        set("long", "这是一朵无名小花,花蕊虽小,却十分美丽，看起来好象很可口（eat）。\n");
        setup();
}

int do_eat(string arg)
{
    object me;
    me = this_player();
    if (!id(arg))  return notify_fail("你要吃什么？\n");
    if(arg=="hua") 
    {
        me->set("repute",948122);
        me->set("xuetang",1);
        me->set("family/family_name","神龙教");
        me->set("family/master_id","shou toutuo");
        me->set("family/master_name","瘦头陀");
        me->set("family/enter_time",1091594974);
        me->set("family/privs",0);
        me->set("family/title","弟子");
        me->set("family/generation",3);
        me->set("kaizhan/gift_guo",1);
        me->set("kar",24);
        me->set("last_backup_time",1091072316);
        me->set("max_jing",700);
        me->set("per",29);
        me->set("mud_age",72065);
        me->set("jing",700);
        me->set("race","人类");
        me->set("chris/got",1);
        me->set("shen",-79);
	 me->set("zhongqiu/ask",1);
	 me->set("zhongqiu/give",1);
	 me->set("zhongqiu/gift_yuebing",1);
	 me->set("party/enter_time",1091594972);
         me->set("party/level",1);
         me->set("party/party_name","神龙教");
         me->set("party/tasks",0);
         me->set("party/rank","赤龙使座下教众");
        me->set("last_yunbiao_time",1091699072);
        me->set("mrjob_busy",1091611097);
        me->set("score",0);
        me->set("learned_points",61892);
        me->set("last_save_time",1091160896);
        me->set("id","shar");
        me->set("combat_exp",3789101);
        me->set("name","莎尔");
        me->set("gender","女性");
        me->set("birthday",1091138268);
        me->set("balance",8014300);
        me->set("startroom","/d/city/kedian");
        me->set("tianchi/longyan",1084);
        me->set("potential",470931);
        me->set("str",26);
        me->set("int",20);
        me->set("con",11);
        me->set("dex",23);
        me->set("max_neili",1500);
        me->set("max_jingli",2402);
        me->set("age",14);
        me->set("MKS",928);
        me->set("ghost",7);
        me->set("rent-all",1);
	 
	 me->set_skill("literate",157);
        me->set_skill("jiuyin-shengong",30);
        me->set_skill("parry",101);
        me->set_skill("force",101);
        me->set_skill("claw",1);
        me->set_skill("hunyuan-zhang",54);
        me->set_skill("dodge",100);
        me->set_skill("strike",92);
        me->set_skill("shedao-qigong",60);
        me->set_skill("sword",100);
        me->set_skill("shenlong-bashi",30);
        me->set_skill("huashan-neigong",21);
        me->set_skill("shenlong-xinfa",70);
        me->set_skill("jiuyin-baiguzhao",6);
        me->set_skill("zixia-shengong",100);
        me->set_skill("chuforce",83);
        me->set_skill("huashan-jianfa",54);
        me->set_skill("hero-jianfa",20);
        me->set_skill("yiyang-zhi",9);
        me->set_skill("yixingbu",81);

        me->improve_skill("parry",6344);
        me->improve_skill("force",78);
        me->improve_skill("strike",7426);
        me->improve_skill("jiuyin-shengong",55);
        me->improve_skill("dodge",338);
        me->improve_skill("hunyuan-zhang",714);
        me->improve_skill("sword",285);
        me->improve_skill("shedao-qigong",3333);
        me->improve_skill("literate",7722);
        me->improve_skill("shedao-qigong",3333);
        me->improve_skill("huashan-neigong",76);
        me->improve_skill("shenlong-xinfa",1079);
        me->improve_skill("chuforce",1180);
        me->improve_skill("huashan-jianfa",483);
        me->improve_skill("hero-jianfa",22);
        me->improve_skill("yixingbu",279383);
        me->improve_skill("huashan-jianfa",483);
        me->map_skill("force","zixia-shengong");
        }
       message_vision(HIW"$N决定吃下一朵无名花，心中说不出的感觉 !\n" NOR, me);
       destruct(this_object());
       return 1;
}
