// qqllyu.c 七窍玲珑玉
// kxkxkx 2004年3月
// Modified by Ciwei@SJ

#include <ansi.h>
#include <command.h>

inherit ITEM;

private nomask int lingwu_hook(string arg);
private nomask void lingwu_hook_completion(object user,string str);

void create()
{
   set_name(HIG"七窍玲珑玉"NOR, ({"qiqiaolinglong yu", "yu"}));
   set_weight(100);
   if(clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "块");
      set("long",
      	"『"HIG"一方美玉，亦是顽石\n"
      	"  无为是神，自在是仙"NOR"』\n"
      	"\n"
      	"一方玲珑的美玉，暗含鬼斧神工造化雕琢之妙。\n"
      	"似乎能令人有所领悟（"HIY"lingwu <技能> with yu"NOR"）。\n"
         );
      //set("no_get", 1);
      set("no_steal", 1);
   }
   setup();
}

void init()
{
   add_action("lingwu_hook", "lingwu ", 2);
}

private nomask int lingwu_hook(string arg)
{
   string* l_skills = ({ // 加更多的可领悟技能
      "duanzao",
      "zhizao",
      "nongsang",
      "caikuang"
   });
	object user, room;
	string str,id;
	int lvl;

   user = this_user();
	if(!arg || sscanf(arg, "%s with %s", str,id) != 2 )
		return notify_fail("格式： lingwu <技能> with qiqiaolinglong yu\n");
		//如果这里return 1 将无法带着yu 去别的地方lingwu so fixed it ciwei@SJ
	if(!objectp(present(id, user)) || present(id, user)!=this_object() ) return 0;	
	if(!str){
		tell_object(user,"格式： lingwu <技能> with qiqiaolinglong yu\n");
		tell_object(user,"你要领悟什么？\n");
		return 1;
	}
	if(member_array(str, l_skills) == -1){
		tell_object(user,"这种技能无法用七窍玲珑玉领悟。\n");
		return 1;
		}
	lvl = user->query_skill(str, 1);
	if(!lvl){
		tell_object(user,"你不会这种技能\n");
		return 1;
	}
			
   user->start_busy(10);
   room = environment(user);
   tell_room(room, user->query("name") + "看着美玉，喃喃自语："
      "「顽石就是美玉，美玉就是顽石……」\n", ({user}));
   tell_object(user, "你看着美玉，喃喃自语："
      "「顽石就是美玉，美玉就是顽石……」\n");
   call_out("lingwu_hook_completion", 4,user, str);
   return 1;
}

private nomask void lingwu_hook_completion(object user,string str)
{   
   int level;
      
   if(!user ||!objectp(present(this_object(), user)) || !str ) return;
   
   level = user->query_skill(str, 1);
   if(!level || level<220 || level%10!=0 || (user->query_learned()[str])<((level+1)*(level+1)-1) )
   	tell_object(user,"大概是因为你的"+to_chinese(str)+"修为不到家，你什么也没有领悟到。\n");
   else{
   	message_vision("$N仔细领悟$n恍然大悟，原来美玉就是顽石，$N的"+to_chinese(str)+"修为百尺杆头又进一步。\n",user,this_object());   	
   	user->improve_skill(str, 2);  // 加1，刚好升级 只加1是进步不了滴
   }
   user->start_busy(-1);
   user->interrupt_me();
   destruct(this_object());
}