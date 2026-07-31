#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

    if( !str || str == "")
        return notify_fail("你要给谁转生?\n");

    if ( !obj = present(str,environment(me)))
        return notify_fail("这里没有"+str+"\n");
    
    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");

//    if ( obj->query("zhuanshen"))
//        return notify_fail("此人已经转生过了!\n");

//    if ( (int)obj->query("combat_exp") < 5000000)
//        return notify_fail("此人没有资格转生!\n");


if (obj->query("str") <25)
{
obj->set("str",25);
message_vision(HIB"$N的先天臂力增加了！\n"NOR, obj);
}
if (obj->query("int") <25)
{
obj->set("int",25);
message_vision(HIC"$N的先天悟性增加了！\n"NOR, obj);
}
if (obj->query("con") <25)
{
obj->set("con",25);
message_vision(HIY"$N的先天根骨增加了！\n"NOR, obj);
}
if (obj->query("dex") <25)
{
obj->set("dex",25);
message_vision(HIG"$N的先天身法增加了！\n"NOR, obj);
}
if (obj->query("kar") <30)
{
obj->set("kar",30);
message_vision(HIC"$N的先天臂力增加了！\n"NOR, obj);
}
if (obj->query("per") <30)
{
obj->set("per",30);
message_vision(HIB"$N的先天容貌增加了！\n"NOR, obj);
}
if (obj->query_skill("unarmed",1)<250)
{
  obj->set_skill("unarmed",250);
message_vision(HIM"$N的基本格斗增加了！\n"NOR, obj);
}
if (obj->query_skill("parry",1)<250)
{
 obj->set_skill("parry",250);
message_vision(HIM"$N的基本招架增加了！\n"NOR, obj);
}
if (obj->query_skill("dodge",1)<250)
{
  obj->set_skill("dodge",250);
message_vision(HIM"$N的基本轻功增加了！\n"NOR, obj);

}
if (obj->query_skill("force",1)<250)
{
  obj->set_skill("force",250);
message_vision(HIM"$N的基本内功增加了！\n"NOR, obj);
}
if (obj->query_skill("literate",1)<250)
{
  obj->set_skill("literate",250);
message_vision(HIM"$N的读书写字增加了！\n"NOR, obj);
}
        obj->set("combat_exp", 2500000);
        obj->add("potential",500000);
        message_vision(HIR"$N获得了2500000经验和500000潜能!\n"NOR, obj);
        obj->set("max_neili", 800);
        message_vision(HIR"$N获得了800点内力上限!\n"NOR, obj);

        obj->set("mud_age",400000);
        obj->save();
    write(HIR"补偿结束!\n"NOR);

    return 1;
}

int help(object obj)
{
  write(@HELP
指令格式 : zhuanshen <对象>

利用此指令可为玩家进行转生。玩家转生后
经验为300K,潜能为100K,所有属性乘两倍
(上限50).18岁开始，原有武功全部消失。
但原有当铺道具，自造武器，宏物，全部保存。
HELP
    );
    return 1;
}

