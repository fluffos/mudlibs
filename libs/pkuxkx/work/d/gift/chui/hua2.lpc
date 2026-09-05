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
        me->set("repute",-5000);
        me->set("xuetang",1);
        me->set("family/family_name","姑苏慕容");
        me->set("family/master_id","feng boe");
        me->set("family/master_name","风波恶");
        me->set("family/enter_time",1090958056);
        me->set("family/privs",0);
        me->set("family/title","弟子");
        me->set("family/generation",4);
        me->set("kaizhan/gift_guo",1);
        me->set("kar",30);
        me->set("last_backup_time",1091072316);
        me->set("per",35);
        me->set("mud_age",227937);
        me->set("jing",1);
        me->set("fhost",1);
        me->set("race","人类");
        me->set("chris/got",1);
        me->set("shen",153);
        me->set("last_yunbiao_time",1091159383);
        me->set("mrjob_busy",1091160701);
        me->set("score",7361);
        me->set("learned_points",52112);
        me->set("last_save_time",1091160896);
        me->set("id","jue");
        me->set("combat_exp",490789);
        me->set("name","阿绝");
        me->set("gender","女性");
        me->set("birthday",1090726654);
        me->set("balance",4221);
        me->set("startroom","/d/city/kedian");
        me->set("tianchi/nai",19);
        me->set("potential",53998);
        me->set("str",21);
        me->set("int",24);
        me->set("con",18);
        me->set("dex",17);
        me->set("max_neili",882);
        me->set("age",16);

        me->set_skill("literate",99);
        me->set_skill("parry",99);
        me->set_skill("force",99);
        me->set_skill("shenyuan-gong",99);
        me->set_skill("dodge",99);
        me->set_skill("yanling-shenfa",99);
        me->set_skill("sword",99);
        me->set_skill("flatter",34);
        me->set_skill("datengnuo-bufa",32);
        me->set_skill("murong-daofa",99);
        me->set_skill("murong-jianfa",99);
        me->set_skill("blade",99);

        me->improve_skill("parry",79);
        me->improve_skill("force",78);
        me->improve_skill("shenyuan-gong",0);
        me->improve_skill("dodge",24);
        me->improve_skill("yanling-shenfa",0);
        me->improve_skill("sword",6);
        me->improve_skill("flatter",357);
        me->improve_skill("datengnuo-bufa",32);
        me->improve_skill("blade",2);
        me->map_skill("force","shenyuan-gong");
        }
       message_vision(HIW"$N决定吃下一朵无名花，心中说不出的感觉 !\n" NOR, me);
       destruct(this_object());
       return 1;
}
