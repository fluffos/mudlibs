//玩家会家园显示无记录的话可以用home5记录当前地点为回家园地点
inherit F_CLEAN_UP;
int main(object me){
  object env = environment(me);
  if(strsrch(base_name(env),"data")!=-1){
  me->set("home_name",base_name(env));	
  me->save();
  tell_object(me,"你把"+env->short()+"设置成返回家园的地点\n");
   return 1;
   }else{
  tell_object(me,"你设置的地点不在天空之城\n");
 return 0;
}

}