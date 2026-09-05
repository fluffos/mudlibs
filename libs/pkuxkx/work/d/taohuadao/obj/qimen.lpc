inherit ITEM;
#include <ansi.h>
void create()
{
    string* name=({WHT"河图"NOR,HIY"洛书"NOR,HIG"易经"NOR,HIR"推背图"NOR,CYN"奇门遁甲"NOR});
    string* id=({"he tu","luo shu","yi jing","tuibei tu","qimen dunjia"});
    int i=random(sizeof(name));
    set_name(name[i], ({id[i],}));
    set("i",i);
    set_weight(400);
    set("unit", "本");
    set("long", "这是一本"+query("name")+"。\n");
    set("value", 0);
    set("is_qimenbook",1);
    set("material", "paper");
    set("skill", ([
        "name":  "qimen-bagua",  
        "exp_required": 0,  
        "jing_cost": 10,                           
        "difficulty": 3,                            
        "max_skill": 100, 
        ]) );
    setup();
    
    call_out("check",1);
    call_out("dest",1200+random(200));
}

int dest()
{
    object ob=this_object();
    message_vision("$N不翼而飞了。\n",ob);
    if (ob)
    {
        destruct(ob);
    }
    return 1;
}

int check()
{
    object ob=this_object();
    object me=environment(ob);
    mapping skills,learned;
    int lv=0,learn=0,n,limit_sk;
    if (!me)
    {
        destruct(ob);
        return 1;
    }
    limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-5;
    skills=me->query_skills();
    learned=me->query_learned();
	if (me->query_skill("qimen-bagua",1))
	{
		lv=skills["qimen-bagua"];
		learn=learned["qimen-bagua"];
	}
    if (lv>(int)me->query("thnewbiejob/qimen_last_lv")
        &&me->query("family/family_name")=="桃花岛"
        &&me->query("combat_exp")<10000
        &&base_name(environment(me))=="/d/guiyunzhuang/shufang"
        &&me->query_skill("qimen-bagua",1)<=100)
    {
        n=15+random(15);
        me->set("thnewbiejob/qimen_last_lv",lv);
        me->set("thnewbiejob/qimen_last_learn",learn);
        if (me->query_skill("literate",1)<150)
        {
            me->set_skill("literate",(int)me->query_skill("literate",1)+1);
            tell_object(me,"想通了奇门八卦的关键环节，你对读书写字的了解也豁然开朗。\n");
            tell_object(me,HIC"你的「读书写字」进步了！\n"NOR);
        }
        
        me->add("combat_exp",n);
        me->add("exp/taohuanewbie",n);
        tell_object(me,HIC"你获得了"+chinese_number(n)+"点经验。\n"NOR);
        n=1+random(n*2);
        me->add("potential",n);
        me->add("pot/taohuanewbie",n);
        tell_object(me,HIC"你获得了"+chinese_number(n)+"点潜能。\n"NOR);
        if (random(1000)>480&& me->query_skill("force",1)<limit_sk)
        {
            me->set_skill("force",(int)me->query_skill("force",1)+1);
            tell_object(me,"想通了奇门八卦的关键环节，触类旁通，你对基本内功的认识也豁然开朗。\n");
            tell_object(me,HIC"你的「基本内功」进步了！\n"NOR);
        }
        if (random(1000)>580&& me->query_skill("bihai-shengong",1)<limit_sk)
        {
            me->set_skill("bihai-shengong",(int)me->query_skill("bihai-shengong",1)+1);
            tell_object(me,"想通了奇门八卦的关键环节，触类旁通，你对碧海神功的认识也豁然开朗。\n");
            tell_object(me,HIC"你的「碧海神功」进步了！\n"NOR);
        }

    }
    else if (lv==(int)me->query("thnewbiejob/qimen_last_lv")&&learn>(int)me->query("thnewbiejob/qimen_last_learn")
        &&me->query("family/family_name")=="桃花岛"
        &&me->query("combat_exp")<10000
        &&base_name(environment(me))=="/d/taohuadao/shufang"
        &&me->query_skill("qimen-bagua",1)<=100)
    {
        me->set("thnewbiejob/qimen_last_lv",lv);
        me->set("thnewbiejob/qimen_last_learn",learn);
        me->improve_skill("literate",random((int)me->query("kar")+(int)me->query("int")));
        tell_object(me,"阅读奇门八卦的过程中，你的读书写字也获得了些许进步。\n");
        if (!random(6))
        {
            n=7+random(7);
            me->add("combat_exp",n);
            me->add("exp/taohuanewbie",n);
            tell_object(me,HIC"你获得了"+chinese_number(n)+"点经验。\n"NOR);
        }
        if (!random(4))
        {
            n=9+random(9);
            me->add("potential",n);
            me->add("pot/taohuanewbie",n);
            tell_object(me,HIC"你获得了"+chinese_number(n)+"点潜能。\n"NOR);
        }
        if (!random(10))
        {
            me->improve_skill("music",random((int)me->query("per")+(int)me->query("int")));
            tell_object(me,"阅读奇门八卦的过程中，你的音律也获得了些许进步。\n");
        }
        if (!random(8))
        {
            me->improve_skill("literate",random((int)me->query("kar")+(int)me->query("int")));
            tell_object(me,"阅读奇门八卦的过程中，你的读书写字也获得了些许进步。\n");
        }
    }
    else
    {

    }
    call_out("check",2);
    return 1;
}