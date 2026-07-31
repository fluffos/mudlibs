inherit F_CLEAN_UP;

int filter(object ob);

int main(object me, string arg)
{

                write(sprintf("Total %d objects has been cleaned.\n",
                              reclaim_objects()));
                return 1;


}
int help()
{
        write(@TEXT
指令格式: reclaim

查阅所有的对象，清除那些不应继续保存在内存中的对象。
TEXT );
        return 1;
}

