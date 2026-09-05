// enforce.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int pts,max_enforce;
    int count = 0; //额外的加力，might特技能多30%
	int enh, enf_enh = 0;
    max_enforce =(int)me->query_skill("force")/2;
	enh = (int)me->query_temp("apply/enforce_enhance");
	if (enh!=0)
	{
		if (enh>200) enh=200; // 最多额外提高2倍
		if (enh<-200) enh=-200; // 最多额外减少2倍
		if (enh>0)
			enf_enh = max_enforce * enh / 100;
		else
			enf_enh = max_enforce * enh / (100-enh);
	}
    if(me->query("special_skill/might") && me->query("age")>=18)
        {       count = max_enforce * 3 / 10;                
        }
    max_enforce += count;
	max_enforce += enf_enh;
        if( arg == "max" || arg == "half" || arg == "little" )
        {
                if( arg =="max" )
                        pts = max_enforce;
                if( arg =="half" )
                        pts = max_enforce/2;
                if( arg =="little")
                        pts = max_enforce/4;
        }
        else
        {
    if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
        return notify_fail("指令格式：enforce|jiali <数量>|none\n");
  }
    if( !me->query_skill_mapped("force") )
        return notify_fail("你必须先 enable 一种内功。\n");

    if( arg=="none" )
    {
        me->delete("jiali");
        write("现在你加力为零。\n");
        return 1;
    }

    if( pts < 0 || (pts-count-enf_enh) > (int)me->query_skill("force") / 2 )
        return notify_fail("none 表示不运内力，数字表示每一击用几点内力，加力不能大于有效内功等级的 1/2。\n");
    me->set("jiali", pts);
    printf("你设定每一击用 %d 点内力。\n", pts);
    return 1;
}

int help (object me)
{
    write(@HELP
指令格式: enforce|jiali <使出几点内力伤敌>|none
这个指令让你指定每次击中敌人时，要发出几点内力伤敌。 enforce none
则表示你不使用内力。 加力不能大于有效内功等级的 1/2。
See Also: enable
HELP
         );
    return 1;
}
