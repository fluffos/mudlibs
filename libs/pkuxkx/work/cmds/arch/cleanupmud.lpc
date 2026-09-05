// cleanupmud.c

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object ob, where, *ob_list;
        int old_size, i;

        ob_list = objects();
        old_size = sizeof(ob_list);
        for(i=0; i<old_size; i++)
if( ob_list[i] &&( inherits(ITEM, ob_list[i])||inherits(NPC, ob_list[i])) && clonep(ob_list[i]) && !environment(ob_list[i]) )
                        destruct(ob_list[i]);
        ob_list -= ({ 0 });
        printf("清除 %d 个物件 of %d。\n", old_size - sizeof(ob_list), old_size);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：cleanupmud

清除 Mud 中所有被复制出来的，但是又没有被放在另一个物件中的
散失物件。
HELP
        );
        return 1;
}

