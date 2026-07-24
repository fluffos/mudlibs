int block_tell(object me)
{
  int time;

  if( wizardp(me) )
    return 1;
  if (!userp(me))
    return 1;

//temporary block tell flooding.
  time=time();
  if(me->query("channel/tell_block") &&
    (time-me->query("channel/tell_block"))<0 )
  {
    write("你的交谈指令被暂时关闭了。\n");
    return 0;
  }

  return 1;
}

