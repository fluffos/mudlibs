// 给闭关的人到闭关室用的指令! By zjb
int get_object(object ob);
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
     object *obj;
     object *inv = deep_inventory(this_player());  
     obj = filter_array(inv,(:get_object:));
     if(sizeof(obj)){
     write (HIB"你刚想偷偷背个人进去，结果还是被发现了。\n"NOR);
     return 1;
}

    if ( (int)me->query_condition("killer")) {
    write (HIR"杀人犯也敢来闭关室，找死!\n"NOR);
    return 1;
} 

   if (!me->query("doing"))
         return notify_fail("你没闭关去闭关室干什么?\n");

 me->move("/d/zjb/biguanshi");
write(HIR"你现在正在闭关，如果你想断线闭关的话，直接断线(#con)就可以闭关了\n"NOR);
return 1;
}

int get_object(object ob)
{
     if(userp(ob))
        return 1;
        return 0;
}

