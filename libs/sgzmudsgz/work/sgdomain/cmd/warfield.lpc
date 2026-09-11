// warfield.c 
// by fire on Sep 4, 1998
// used for player char to risign a position
inherit M_ANSI;
void start(string arg)
{
        string ret;
        if(arg=="")
        {
                write("用法错误！");
                write("用 cmd help warfield 查看详细帮助。\n");
                return;
        }
        if(arg=="here")
        {
                object env;
                mixed tmp;
                env=environment(this_body());
                arg=env->get_area();
                tmp=AREA_D->check_area("area",arg);
                if(sizeof(tmp)==0)
                {
                        write("没有此处的地图，用map查阅目前已有的地图。\n");
                            return;
                }
                arg=tmp[0];
        }
        this_body()->move(AREA_D->get_area(arg,"path")+"warroom/0/0");
        write("hehe\n");
}
