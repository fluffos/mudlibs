// whistle.c
//
// by meteor

int main(object me, string arg)
{
        object pet, env;

        if( !objectp(pet = me->query_temp("created_pet")) )
                return notify_fail("你吹了一声口哨。\n");
        
        if( arg && (arg != pet->query("id")) )
                return notify_fail("你想诱拐别人的宠物吗？羞不羞啊？\n");
        
        if( present(pet, me) )
                return notify_fail("你的宠物就在这里啊！\n");
        
        env = environment(pet);
        
        if( !pet->move(environment(me)) )
                return notify_fail("好象出了什么问题，你的宠物不听你的召唤了！\n");
        
        tell_room(env, "远处传来一声口哨响，" + pet->name() + "象发现了亲人似的，飞快地冲了过去。\n");
        message_vision("$N吹了一声口哨，不一会儿" + pet->name() + "就冲了过来，欢快地扑到$N身上。\n", me);
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式: whistle
 
这个指令可以让你召唤自己的宠物到身边。
 
HELP
    );
    return 1;
}