//clearmem.c
inherit F_CLEAN_UP;

int main(object me, string arg)
{
if ( reclaim_objects() )
        write("清除成功。\n");
else    write("清除失败。\n");
return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : clearmem

这个函式重复检查每一个载入的物件, 并尽力把残留在记忆体
中的物件清除掉. 这样可以清出一些记忆体, 清理的数量多寡
要看  mud 本身的程式是如何写的. 如果一个物件被其他物件
里面的全域变数 (global variable)指标 (pointer)  指向到
, 就会残留在记忆体中, 然後再被摧毁掉. 这个超越函式
(efun)  会传回变数遇到的被摧毁的物件数目.
HELP
);
return 1;
}

