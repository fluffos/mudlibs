// give.c
//fixed by lum 7/11/1996 because 之前有人用中文加符号。
inherit F_CLEAN_UP;
int do_give(object me,object obj,object who,int force);
 
void create() { seteuid(getuid()); }
 
int main(object me,string arg)
{
        string target,item,force;
        object obj, who,*inv,obj2;
        int i,amount,do_force;
 
        if (!NATURE_D->vision(me))
          return notify_fail("四周乌漆妈黑的，什么也看不到.\n");
 
        if(!arg) return notify_fail("你要给谁什么东西？\n");
        arg = lower_case(arg);
 
        if (sscanf (arg,"%s %s",force,item) == 2)
          if (force == "-f") {
            if (!wizardp(me)) force = 0;
          }
          else force = 0;
 
        if (force && force == "-f") do_force = 1;
 
        if( sscanf(arg,"%s to %s",item,target)==2
        || sscanf(arg,"%s %s",target,item)==2 );
        else return notify_fail("你要给谁什么东西？\n");
 
        if(!objectp(who = present(target,environment(me))) || !living(who))
                return notify_fail("这里没有这个人。\n");
 
        if (wizardp(me) && !wizardp(who) &&
          wizhood(me)!="(manager)" && wizhood(me) != "(admin)" && wizhood(me) != "(arch)")
        {
          return notify_fail("巫师不能给玩家东西\n");
        }
        if(sscanf(item,"%d %s",amount,item)==2) {
                if( !objectp(obj = present(item,me)) )
                        return notify_fail("你身上没有这样东西。\n");
                if( obj->query("no_drop") )
                        return notify_fail("这样东西不能随便给人。\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "不能被分开给人。\n");
 
                if( amount < 1 )
                        return notify_fail("东西的数量至少是一个。\n");
                if( amount > obj->query_amount() )
                        return notify_fail("你没有那么多的" + obj->name() + "。\n");
                else if( amount == (int)obj->query_amount() )
                        return do_give(me,obj,who,do_force);
                else {
                  obj->set_amount( (int)obj->query_amount() - amount );
                  obj2 = new(base_name(obj));
                  obj2->set_amount(amount);
                  return do_give(me,obj2,who,do_force);
                }
        }
 
        if (item=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        do_give(me,inv[i],who,do_force);
                }
                write("好了.\n");
                if (userp(me)) me->save();
                if (userp(who)) who->save();
                return 1;
        }
 
        if(!objectp(obj = present(item,me)))
                return notify_fail("你身上没有这样东西。\n");
        return do_give(me,obj,who,do_force);
}
 
int do_give(object me,object obj,object who,int force)
{
  object        *light;
 
  if( !force && (obj->query("no_drop") || obj->query_temp("secured")) )
    return notify_fail ("这东西不能给人.\n");
 
  if( userp(who) && !interactive(who) )
    return notify_fail("你只能把东西送给其他玩家操纵的人物。\n");
 
  if( obj->move(who) ) {
    // 火把
    if (obj->query("had_light")) {
        obj->delete("had_light");
        obj->delete("short");
        write (sprintf ("当你把%s给人的时候，这%s%s也渐渐暗淡下来。\n",
          obj->name(),obj->query("unit"),obj->name()));
    }
 
    if (me->is_fighting()) me->start_busy(1);
    printf("你给%s一%s%s。\n",who->name(),obj->query("unit"),
    obj->name());
    message("vision",sprintf("%s给你一%s%s。\n",me->name(),
    obj->query("unit"),obj->name()),who );
    message("vision",sprintf("%s给%s一%s%s。\n",me->name(),who->name(),
    obj->query("unit"),obj->name()),environment(me),({me,who}) );
    if (!userp(who)) {
      who->accept_object(me,obj);
      return 1;
    }
    else {
      me->save();
      who->save();
      return 1;
    }
  }
  else return 0;
}
 
int help(object me)
{
write(@HELP
指令格式 : give <物品名称> to <某人>
      或 : give <某人> <物品名称>
指令说明 :
           这个指令可以让你将某样物品给别人，
         当然，首先你要拥有这样物品。
其他参考 :
           get，drop
HELP
    );
    return 1;
}
