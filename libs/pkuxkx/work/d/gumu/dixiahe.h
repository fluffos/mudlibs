inherit ROOM;
int valid_leave(object me, string dir)
{
        int current_qi;

        current_qi = me->query("qi");
        if (current_qi<50) {
          write("你已经感到不行了，冥冥中你觉得被水冲出暗河。\n");
          me->move(__DIR__"xidi");
          me->unconcious();
        }
				//这里需要判断一下me是否还存在，如果是任务npc可能unconcious之后已经消失了
				//by icer
				if (!objectp(me))
					return 0;
				
        if (current_qi>0 && current_qi<=100) {
            write("你已经游得精疲力尽了。\n");
            me->set("water",0);
        }

        if (current_qi>50) {
            me->set("qi",current_qi-50);
        }
    //    if (dir=="east" || dir=="south" || dir=="west" || dir=="north") 
      //     return notify_fail("你向那边走去，结果发现那是沙漠中的海市蜃楼。\n");
        return ::valid_leave(me, dir);
}
