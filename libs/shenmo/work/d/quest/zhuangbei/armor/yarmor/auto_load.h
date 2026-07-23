int query_autoload()  
{
object me; 
if ( !environment() )  return 0;
me = environment();
if( me->query("level") >= this_object()->query("level_quest") ) 
       return 1;
return 0;
}
