//这个头文件里面放的是段府书房里面的书阅读的限制条件
//条件是：你的领悟级别的三次方乘以该门功夫的级别除以灵性的二分之三
//这样在学三级功夫的一般灵性为二十的人学到一百级要经验
//100x100x100x3/(20*3/2) = 100000（十万）

int invalid_study( object me )
{
    object ob = this_object();
    string this_skill;
    int dengji, exp, jibie, need_exp, spi;
    
    this_skill = ob->query("skill/name");
    dengji = me->query_lingwu( this_skill );
    exp = me->query( "combat_exp" );
    spi = me->query_spi()*3/2;
    jibie = SKILL_D( this_skill )->query_dengji()
          + SKILL_D( this_skill )->query_level();
    need_exp = dengji*dengji*dengji*jibie/spi;

    if( exp<need_exp && dengji<query("skill/max_lingwu") ) 
    {
        write("你经验不足，对书上的东西无法领会。\n");
        return 1;
    }
    return 0;
}            
   

