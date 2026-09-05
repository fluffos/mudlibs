// sao.c
// kuer

inherit F_CLEAN_UP;

void sao(object me);

int main(object me)
{
    string short; 
    mapping quest;   
    short = environment(me)->query("short");
    if(!(quest=me->query("quest")) 
       || quest["quest_type"] != "扫"
       || quest["quest"] != short )
      return notify_fail("什么？\n");                           
    if(me->query("qi")<80)return notify_fail("你的身体状况不太适合扫地。\n");
    if(me->is_busy())return notify_fail("你正忙着呢，怎能扫地？\n");
    message_vision("$N从角落里找了一把笤帚，开始打扫这里。\n",me);             
    me->add("qi",-50);      
    me->start_busy(15);
    call_out("sao",20,me);
    return 1;
}                 

void sao(object me)
{
  message_vision("$N深吸了一口气，直起身来，终于扫完地了！\n",me);
  me->set_temp("quest_finish",1);
}
