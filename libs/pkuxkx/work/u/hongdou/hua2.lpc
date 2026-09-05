inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name("无名花", ({"hua", "wuming"}));
        set("unit", "朵");
	set("long", "这是一朵无名小花,花蕊虽小,却十分美丽。\n");
        setup();
}

int do_eat(string arg)
{
    object me;
    me = this_player();
if (!id(arg))  return notify_fail("你要吃什么？\n");
if(arg=="hua") 
{
        me->set_skill("blade",58);
         me->set_skill("buddhism",81);

      me->set_skill("cibei-dao",57);
       me->set_skill("dodge",0);
       me->set_skill("finger",82);
        me->set_skill("force",51);
        me->set_skill("fumo-jian",49);
        me->set_skill("hunyuan-yiqi",77);
        me->set_skill("literate",101);
        me->set_skill("nianhua-zhi",51);
        me->set_skill("parry",68);
        me->set_skill("sanhua-zhang",10);
        me->set_skill("shaolin-shenfa",36);
        me->set_skill("strike",16);
        me->set_skill("sword",65);
        me->set("combat_exp",69088);
         me->add("potential",50);
            destruct(this_object());
}
return 1;
}
