// by fire on Dec 11, 97
// list.c used to list the matter can be bought
#include <mudlib.h>
#include <move.h>
#include <setbit.h>
inherit VERB_OB;
void do_list()
{
  mixed s = environment(this_body())->list();
  if(stringp(s))
    {
      write(s);
      return;
    }
  else if(!s)
    {
		object room;
		int i,sum;
		object *livs;
		room=this_body()->query_room();
		livs=all_inventory(room);
		sum=sizeof(livs);
		for(i=0;i<sum;++i) {
			if(livs[i]->is_maker())
			{
				string p_id;
				p_id=livs[i]->query_id()[0];
				this_body()->responda("ask "+p_id+" about list");
				return;
			}
		}
      
	  
	  write("你看这儿象是能买东西的地方吗？\n");
      return;
    }
}
int direct_list_obj(object ob)
{
  return 1;
}
mixed * query_verb_info()
{
    return ({ ({ "", })});
}
