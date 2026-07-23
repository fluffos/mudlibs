//added by huarong  2004/8
void greeting(object me)
{
     if( !me ) return;  // hiei add. 2012/3/15
     if( !userp(me) )
     me->move("/d/kaifeng/wanshou"); 
}

