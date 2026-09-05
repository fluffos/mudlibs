inherit ITEM;

#include <ansi.h>
string *names = ({
        HIW"糯米粽子"NOR,
        HIY"小米粽子"NOR,
        HIR"高梁粽子"NOR,
        HIM"大枣粽子"NOR,
        HIB"精品粽子"NOR,
        HIG"八宝粽子"NOR,
});
void create()
{
        set_name(names[random(sizeof(names))] ,({"zong zi","gift"}));
        set("long","一只端午节吃的粽子，上面缠着红红绿绿的丝线，很是好看！\n"
        );
        set("value",10);
        set_weight(10);
        set("no_store",1);
        set("no_sell",1);
        set("unit","只");
        setup();
}

void init()
{
                if(environment(this_object())==this_player())
                add_action("do_eat","eat");
}

int do_eat(string arg)
{
        object me=this_player();
        int i,oldlevel,addlevel;
        string *sname;
        mapping skill_status;
        
        if(!arg) return 0;
        if(arg!="zong zi"&&arg!="gift") return 0;
        if (me->query("gift/201061") > 1)
                return notify_fail("你已经吃过了粽子了，也不怕撑得慌！\n");
        message_vision(HIC"过端午了，$N高高兴兴地拿出端午节礼物－" 
        + this_object()->name() + HIC"，一口吃进嘴里，好香啊～～\n"NOR,me);
        switch(random(50))
        {
        case 1:
        case 2:
                {
                shout(HIR + me->name() + "吃到了" + BNK + HIG + "极品粽子"+ NOR + HIR + "，人品增加两点！\n");
                me->add("kar",2);
                me->add("xiantian/kar/201061",2);
                break;
                }
        case 3:
               {
               if (me->query("age")>18)
                 {
                 shout(HIR + me->name() + "吃到了" + BNK + HIG + "极品粽子"+ NOR + HIR + "，年轻了一岁。\n");
                 me->add("mud_age",-86400);
                 }
               break;
               }
        case 4:
               {
               shout(HIR + me->name() + "吃到了" + BNK + HIG + "极品粽子"+ NOR + HIR + "，内力和精力修为提升。\n");
               me->add("max_neili",1000+random(500));
               me->add("max_jingli",1000+random(500));
               break;               
               }
        case 5:
               {
               if (me->query("combat_exp")>=10000000){
               shout(HIR + me->name() + "吃到了" + BNK + HIG + "极品粽子"+ NOR + HIR + "，获得了大量的金币。\n");
               me->add("balance",10000000);
               tell_object(me,"请检查你的帐户，增加了1000两黄金。\n");
               }
               else
               {
               me->add("combat_exp",2000+random(500));
               me->add("potential",200+random(100));
               me->add("repute",5000+random(5000));
               }                
               break;                
               }
        case 6:
               {
               if (me->query("class")!="officer"){
               shout(HIR + me->name() + "吃到了" + BNK + HIG + "极品粽子"+ NOR + HIR + "，门派忠诚度提高一倍。\n");
               me->add("score",me->query("score"));
               }
               else
               {
               me->add("combat_exp",2000+random(500));
               me->add("potential",200+random(100));
               me->add("repute",5000+random(5000));
               }               
               break;                   
               }                             
        default:
               {        
               me->add("combat_exp",2000+random(500));
               me->add("potential",200+random(100));
               me->add("repute",5000+random(5000));
               break;
               }
        }
        me->add("combat_exp",2000+random(500));
        me->add("potential",200+random(100));        
        tell_object(me,HIW"你的经验增加了！\n"HIM"你的潜能增加了！\n"NOR);
        me->add("gift/201061",1);
        me->save();
        destruct(this_object());
        return 1;
}
