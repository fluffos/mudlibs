inherit F_CLEAN_UP;
int main(object me, string arg)
{

  if(arg){
  me->set("beast/beast_id",arg);	
  me->save();
  tell_object(me,"你使用幻兽哨时会自动召唤id为"+arg+"的幻魔兽\n");
   return 1;
   }else{
  tell_object(me,"你要记录什么id\n");
 return 0;
}

}