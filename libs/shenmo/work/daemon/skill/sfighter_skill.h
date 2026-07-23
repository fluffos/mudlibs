
int stage(int level)
{
        if( level <100 ) return 1; 
        else if ( level < 200 ) return 2; 
        else if ( level < 300 ) return 3; 
        else if ( level < 400 ) return 4; 
        else if ( level < 500 ) return 5; 
        else if ( level < 600 ) return 6; 
        else if ( level < 700 ) return 7; 
        else if ( level < 800 ) return 8; 
        else if ( level < 900 ) return 9; 
        else return 10; 
}

string level_description(int level) 
{
        if ( stage(level) == 1 ) 
                return HIC "X 级力量" NOR; 
        else if ( stage(level) == 2 ) 
                return HIC "Z 级力量" NOR; 
        else if ( stage(level) == 3) 
                return HIC "V 级力量" NOR; 
        else if ( stage(level) == 4) 
                return HIW "白 鬭 气" NOR; 
        else if ( stage(level) == 5) 
                return HIY "黄 鬭 气" NOR; 
        else if ( stage(level) == 6) 
                return HIG "绿 鬭 气" NOR; 
        else if ( stage(level) == 7) 
                return HIR "红 鬭 气" NOR; 
        else if ( stage(level) == 8) 
                return HIB "蓝 鬭 气" NOR; 
        else if ( stage(level) == 9) 
                return HIM "紫 鬭 气" NOR; 
        else    return BLK "黑 鬭 气" NOR; 
}
