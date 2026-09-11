// modified by fire on Jan 3 1998
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit VERB_OB;
mixed can_follow_liv(object who)  
{
         return 1;
}
mixed can_follow()
{
	return 1;
}         
void do_follow()
{
         if( this_body()->query("leader") ) 
         {
             this_body()->delete("leader"); 
             this_body()->simple_action("$N现在放弃跟随目标。\n");
             return;
         } 
         else 
         {
             write("你现在并没有跟随任何人。\n");
             return;
         }
}
void do_follow_liv(object ob)
{
  
      if( ob == this_body() )
      {       
            write("跟随自己？\n");
            return;
      }
      this_body()->set("leader",ob);
      this_body()->targetted_action("$N决定开始跟随$T一起行动。\n",ob);
      return; 
}
mixed * query_verb_info() {
    return ({ ({ "LIV","" }) });
}
