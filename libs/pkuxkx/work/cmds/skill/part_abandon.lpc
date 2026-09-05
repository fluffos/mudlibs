// part_abandon.c
// moidified by jpei for abandon 05162008

inherit F_CLEAN_UP;

int main(object me, string arg)
{

        string skill_name;
        int times, skill_num;
        
        if(!arg || (sscanf(arg, "%s %d",skill_name,times) < 1 ))
                return notify_fail("指令格式：part_abandon <技能名> <级别数>\n");
        //if( !arg || arg=="" ) 
               //return notify_fail("你要放弃哪一项技能？\n");
        if ( times <= 0 ) 
               return notify_fail("你这是什么意思，想耍花招啊？哼！\n");        
        if ( ! ( skill_num = me->query_skill(skill_name,1) ) )
                return notify_fail("你并没有学过这项技能。\n");
        
        if ( (skill_num > times ) ) {
                me->set_skill(skill_name,skill_num-times); 
                write("你废掉了自己一部份"+ to_chinese(skill_name) +"("+skill_name+")，可惜啊！！!\n\n");
        } else { 
                write("你还不直接放弃算了！！！\n\n");
        }
        return 1;
}

int help()
{
        write(@TEXT
指令格式：part_abandon <技能名称> <要废除的级别数>

废掉一部份自己武功。战斗方式升级时可以用此调整自己的战斗参数。

TEXT
        );
        return 1;
}

