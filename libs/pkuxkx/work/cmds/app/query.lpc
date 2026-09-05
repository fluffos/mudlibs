#include <ansi.h>

int help(object me);

int main(object me, string arg)
{
   string tar, data, text;
   object target;
   mapping ddata;
   int tmp = 0, room = 0;

   seteuid(geteuid(me));

   if (arg) {
	 if (sscanf(arg, "-t %s", arg) == 1)
		 tmp = 1;
	 if (sscanf(arg, "here %s", data) == 1)
	 {
		 target = environment(me);
		 room = 1;
	 }
     else if (sscanf(arg, "%s %s", tar, data) == 2)
	 {
		 target = present(tar, me);
		 if (!objectp(target))
			 target = present(tar, environment(me));
		 if (!objectp(target))
			 target = find_player(tar);
		if (!objectp(target))
			return notify_fail("没有找到 "+tar+" 。\n");
	 } 
	 if (!stringp(data))
		 return notify_fail("指令格式：query <id> <指定属性>。查看全部属性请用 data 指令。\n");
	 if (tmp>0) ddata = target->query_temp(data);
	 else ddata = target->query(data);
	 if (!ddata)
		 return notify_fail(""+target->query("name")+NOR+"没有 "+data+" 这个"+(tmp?"临时":"")+"属性。\n");
	 if (room>0)
		 text = ""+target->query("short")+NOR + "的"+(tmp?"临时":"")+"属性：";
	 else
		text = ""+target->query("name")+NOR+"("+target->query("id")+") 的"+(tmp?"临时":"")+"属性：";
	 text += data + " = " + sprintf("%O \n", ddata);
	 me->start_more( text );
	 return 1;
   }
   return notify_fail("指令格式：query <id> <指定属性>。查看全部属性请用 data 指令。\n");
}
 
//  This function is used to sort the key array.
 
nosave int sort_keys(string one, string two) {
   return strcmp(one, two);  }
 
//  This function strips out the secured props from the data array.
 
nosave int filter_props(string prop, object target) {
 
//   if(member_array((int)target->query_permission(prop),
//	({ MASTER_ONLY, PRIVATE, OWNER_ONLY })) != -1)   return 0;
 
return 1; }

int help(object me)
{
  write( @LONG
指令格式: query (-t) [玩家|物件|here] [属性]
指令说明:
	此命令让你可以观看某物件的某项指定资料。
	使用 -t 参数查看临时属性。
	查看全部属性请用 data 指令。
LONG);
 
  return 1;
}
 
