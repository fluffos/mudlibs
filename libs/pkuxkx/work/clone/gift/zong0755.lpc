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
        set("value",0);
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
        if(me->query("combat_exp")<50000) return 0;
        if(arg!="zong zi"&&arg!="zong") return 0;
        if (me->query("gift/200755") > 1)
                return notify_fail("粽子吃多了对身体也不好！\n");
        message_vision(HIC"过端午了，$N高高兴兴地拿出端午节礼物－" + this_object()->name() + HIC"，一口吃进嘴里，好香啊～～\n"NOR,me);
        switch (random(50))
        {
        case 0:
        shout(HIR + me->name() + "吃到了" + BNK + HIG + "极品粽子"+ NOR + HIR + "，人品增加两点！\n"NOR);
        me->add("kar",2);
        me->add("xiantian/kar/200755",2);
        break;
        case 1:
        shout(HIR + me->name() + "吃到了" + BNK + HIG + "极品粽子"+ NOR + HIR + "，灵性增加两点！\n"NOR);
        me->add("spi",2);
        me->add("xiantian/spi/200755",2);
        break;
        case 2:
        shout(HIR + me->name() + "吃到了" + BNK + HIG + "极品粽子"+ NOR + HIR + "，悟性增加两点！\n"NOR);
        me->add("int",2);
        me->add("xiantian/int/200755",2);
        break;
        case 3:
        me->add("balance",2000000);
        tell_object(me,HIY"你的存款增加了2000两黄金。\n"NOR);
        break;
        default:
        me->add("combat_exp",20000+random(5000));
        me->add("potential",10000+random(1000));
        tell_object(me,HIW"你的经验增加了！\n"HIM"你的潜能增加了！\n"NOR);
        }
        me->add("gift/200755",1);
        me->save();
        destruct(this_object());
        return 1;
}
