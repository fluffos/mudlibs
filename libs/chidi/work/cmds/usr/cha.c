// By jh@ty  2002.5.15
// ÒÔº£ÑóIIµÄcha.cÎª»ù´¡¸Ä±àµÄ
#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "³õÑ§Õ§Á·" NOR,
        BLU "²»ÖªËùÒÔ" NOR,//100
         HIB "´ÖÍ¨Æ¤Ã«" NOR,//200
        YEL "½¥ÓĞËùÎò" NOR,//300
        YEL "°ëÉú²»Êì" NOR,//400
        YEL "ÂíÂí»¢»¢" NOR,//500
        HIY "Æ½µ­ÎŞÆæ" NOR,//600
       HIY "Æ½µ­ÎŞÆæ" NOR,//700
       HIY "Æ½µ­ÎŞÆæ" NOR,//800
       HIY "Æ½µ­ÎŞÆæ" NOR,//900
        HIY "Æ½µ­ÎŞÆæ" NOR,//1000
         HIY "Æ½µ­ÎŞÆæ" NOR,//1100
         HIY "Æ½µ­ÎŞÆæ" NOR,//1200
        HIY "´¥ÀàÅÔÍ¨" NOR,//1300
        HIY "´¥ÀàÅÔÍ¨" NOR,//1400
        HIY "´¥ÀàÅÔÍ¨" NOR,//1500
       HIY "´¥ÀàÅÔÍ¨" NOR,//1600
        HIY "´¥ÀàÅÔÍ¨" NOR,//1700
        HIY "´¥ÀàÅÔÍ¨" NOR,//1800
        HIY "´¥ÀàÅÔÍ¨" NOR,//1900
       HIG "ĞÄÁìÉñ»á" NOR,//2000
       HIG "ĞÄÁìÉñ»á" NOR,//2100
       HIG "ĞÄÁìÉñ»á" NOR,//2200
      HIG "ĞÄÁìÉñ»á" NOR,//2300
       HIG "ĞÄÁìÉñ»á" NOR,//2400
       HIG "»ÓÈ÷×ÔÈç" NOR,//2500
       HIG "»ÓÈ÷×ÔÈç" NOR,//2600
      HIG "»ÓÈ÷×ÔÈç" NOR,//2700
      HIG "»ÓÈ÷×ÔÈç" NOR,//2800
       HIG "»ÓÈ÷×ÔÈç" NOR,//2900
       HIC "¼İÇá¾ÍÊì" NOR,//3000
       HIC "¼İÇá¾ÍÊì" NOR,//3100
       HIC "¼İÇá¾ÍÊì" NOR,//3200
       HIC "¼İÇá¾ÍÊì" NOR,//3300
         HIC "¼İÇá¾ÍÊì" NOR,//3400
          HIC "³öÀà°ÎİÍ" NOR,//3700
        HIC "³öÀà°ÎİÍ" NOR,//3700
      HIC "³öÀà°ÎİÍ" NOR,//3700
       HIC "³öÀà°ÎİÍ" NOR,//3800
      HIC "³öÀà°ÎİÍ" NOR,//3900
   
      CYN "³õÈë¼Ñ¾³" NOR,//4000
       CYN "³õÈë¼Ñ¾³" NOR,//4100
        CYN "³õÈë¼Ñ¾³" NOR,//4200
      CYN "³õÈë¼Ñ¾³" NOR,//43
       CYN "³õÈë¼Ñ¾³" NOR,//44

      CYN "ÉñºõÆä¼¼" NOR,//45
       CYN "ÉñºõÆä¼¼" NOR,//46
      CYN "ÉñºõÆä¼¼" NOR,//47
      CYN "ÉñºõÆä¼¼" NOR,//48
       CYN "ÉñºõÆä¼¼" NOR,//49

      MAG "Íş²»¿Éµ±" NOR,//50
      MAG "Íş²»¿Éµ±" NOR,//51
      MAG "Íş²»¿Éµ±" NOR,//52
      MAG "Íş²»¿Éµ±" NOR,//53
        MAG "Íş²»¿Éµ±" NOR,//54
        
       MAG "³öÉñÈë»¯" NOR,//55
       MAG "³öÉñÈë»¯" NOR,//56
      MAG "³öÉñÈë»¯" NOR,//57
       MAG "³öÉñÈë»¯" NOR,//58
         MAG "³öÉñÈë»¯" NOR,//59
                
        HIW "»íÈ»¹áÍ¨" NOR,//60
        HIW "»íÈ»¹áÍ¨" NOR,//61
        HIW "»íÈ»¹áÍ¨" NOR,//62
         HIW "»íÈ»¹áÍ¨" NOR,//63
          HIW "»íÈ»¹áÍ¨" NOR,//64
        
        HIW "³¬Èº¾øÂ×" NOR,//65
         HIW "³¬Èº¾øÂ×" NOR,//66
       HIW "³¬Èº¾øÂ×" NOR,//67
        HIW "³¬Èº¾øÂ×" NOR,//68
         HIW "³¬Èº¾øÂ×" NOR,//69
    
       RED "µÇ·åÔì¼«" NOR,//70
       RED "µÇ·åÔì¼«" NOR,//71
       RED "µÇ·åÔì¼«" NOR,//72
       RED "µÇ·åÔì¼«" NOR,//73
         RED "µÇ·åÔì¼«" NOR,//74
           RED "µÇ·åÔì¼«" NOR,//75
             RED "µÇ·åÔì¼«" NOR,//76
               RED "µÇ·åÔì¼«" NOR,//77
                 RED "µÇ·åÔì¼«" NOR,//78
                   RED "µÇ·åÔì¼«" NOR,//79
                   
        HIM "Ò»´ú×ÚÊ¦" NOR,//80
        HIM "Ò»´ú×ÚÊ¦" NOR,//81
         HIM "Ò»´ú×ÚÊ¦" NOR,//82
          HIM "Ò»´ú×ÚÊ¦" NOR,//83
           HIM "Ò»´ú×ÚÊ¦" NOR,//84
            HIM "Ò»´ú×ÚÊ¦" NOR,//85
             HIM "Ò»´ú×ÚÊ¦" NOR,//86
              HIM "Ò»´ú×ÚÊ¦" NOR,//87
        HIM "Ò»´ú×ÚÊ¦" NOR,//88
        HIM "Ò»´ú×ÚÊ¦" NOR,//89
     
        HIM "¶À²½ÌìÏÂ" NOR,//90
        HIM "¶À²½ÌìÏÂ" NOR,//91
        HIM "¶À²½ÌìÏÂ" NOR,//92
        HIM "¶À²½ÌìÏÂ" NOR,//93
        HIM "¶À²½ÌìÏÂ" NOR,//94
        HIM "¶À²½ÌìÏÂ" NOR,//95
        HIM "¶À²½ÌìÏÂ" NOR,//96
        HIM "¶À²½ÌìÏÂ" NOR,//97
        HIM "¶À²½ÌìÏÂ" NOR,//98
        HIM "¶À²½ÌìÏÂ" NOR,//99
        
         HIR "¿ÕÇ°¾øºó" NOR,//100
          HIR "¿ÕÇ°¾øºó" NOR,//101
           HIR "¿ÕÇ°¾øºó" NOR,//102
            HIR "¿ÕÇ°¾øºó" NOR,//103
             HIR "¿ÕÇ°¾øºó" NOR,//104
         
         HIR "¿õ¹Å¾øÂ×" NOR,//105
         HIR "¿õ¹Å¾øÂ×" NOR,//106
         HIR "¿õ¹Å¾øÂ×" NOR,//107
         HIR "¿õ¹Å¾øÂ×" NOR,//108
         HIR "¿õ¹Å¾øÂ×" NOR,//109
        
       //HIR "µÇÌÃÈëÊÒ" NOR,
      // HIR "³¬·²ÈëÊ¥" NOR,//105
 
      HIR "Éî²»¿É²â" NOR,//110
      HIR "Éî²»¿É²â" NOR,//111
      HIR "Éî²»¿É²â" NOR,//112
      HIR "Éî²»¿É²â" NOR,//113
      HIR "Éî²»¿É²â" NOR,//114
      
          NOR "·µè±¹éÕæ" NOR,//115
            NOR "·µè±¹éÕæ" NOR,//116
              NOR "·µè±¹éÕæ" NOR,//117
                NOR "·µè±¹éÕæ" NOR,//118
                  NOR "·µè±¹éÕæ" NOR,//119
                  
      RED "Ç°ÎŞ¹ÅÈË" NOR,//120
      RED "Ç°ÎŞ¹ÅÈË" NOR,//121
      RED "Ç°ÎŞ¹ÅÈË" NOR,//122
      RED "Ç°ÎŞ¹ÅÈË" NOR,//123
      RED "Ç°ÎŞ¹ÅÈË" NOR,//124
      
        CYN "ºóÎŞÀ´Õß" NOR,//125
       CYN "ºóÎŞÀ´Õß" NOR,//126
       CYN "ºóÎŞÀ´Õß" NOR,//127
       CYN "ºóÎŞÀ´Õß" NOR,//128
         CYN "ºóÎŞÀ´Õß" NOR,//129
         
        MAG "¾ªÌì¶¯µØ" NOR,//130
        MAG "¾ªÌì¶¯µØ" NOR,//131
       MAG "¾ªÌì¶¯µØ" NOR,//132
       MAG "¾ªÌì¶¯µØ" NOR,//133
       MAG "¾ªÌì¶¯µØ" NOR,//134
      YEL "¹í¿ŞÀÇº¿" NOR,//135
       YEL "¹í¿ŞÀÇº¿" NOR,//136
      YEL "¹í¿ŞÀÇº¿" NOR,//137
       YEL "¹í¿ŞÀÇº¿" NOR,//138
      YEL "¹í¿ŞÀÇº¿" NOR,//139
         BLU "Ìì¾ªµØ±ä" NOR,//140
       BLU "Ìì¾ªµØ±ä" NOR,//141
      BLU "Ìì¾ªµØ±ä" NOR,//142
      BLU "Ìì¾ªµØ±ä" NOR,//143
      BLU "Ìì¾ªµØ±ä" NOR,//144
       WHT HIC"ÌìÏÂÎŞµĞ" NOR, //14500
});


string *zhongji_level_desc = ({
       BLU "³õÑ§Õ§Á·" NOR,
       MAG "µÚÒ»µÈ¼¶" NOR,
       BLU "µÚ¶şµÈ¼¶" NOR,
    YEL "µÚÈıµÈ¼¶" NOR,
    CYN "µÚËÄµÈ¼¶" NOR,
    RED "µÚÎåµÈ¼¶" NOR,
      WHT HIC"×î¸ßµÈ¼¶" NOR, 
});
string *knowledge_level_desc = ({
        BLU "ĞÂÑ§Õ§ÓÃ" NOR,

        HIB "²»Öª¶ËÄß" NOR,
 
        YEL "Ë¾¿Õ¼û¹ß" NOR,

        YEL "³õ¿úÃÅ¾¶" NOR,

        HIY "ÂÔÖªÒ»¶ş" NOR,
   HIY "ÂÔÖªÒ»¶ş" NOR,

        HIY "Ã©Èû¶Ù¿ª" NOR,
  HIY "Ã©Èû¶Ù¿ª" NOR,
  HIY "Ã©Èû¶Ù¿ª" NOR,

        CYN "ÂÔÊ¶Ö®ÎŞ" NOR,
  CYN "ÂÔÊ¶Ö®ÎŞ" NOR,
  CYN "ÂÔÊ¶Ö®ÎŞ" NOR,

        CYN "¹ö¹ÏÀÃÊì" NOR,
   CYN "¹ö¹ÏÀÃÊì" NOR,
   CYN "¹ö¹ÏÀÃÊì" NOR,
 
        MAG "ÂíÂí»¢»¢" NOR,
 MAG "ÂíÂí»¢»¢" NOR,
 MAG "ÂíÂí»¢»¢" NOR,
 MAG "ÂíÂí»¢»¢" NOR,
 MAG "ÂíÂí»¢»¢" NOR,
 MAG "ÂíÂí»¢»¢" NOR,

        MAG "Çá³µÊìÂ·" NOR,
 MAG "Çá³µÊìÂ·" NOR,
 MAG "Çá³µÊìÂ·" NOR,
 MAG "Çá³µÊìÂ·" NOR,
 MAG "Çá³µÊìÂ·" NOR,
 
        HIW "ÔËÓÃ×ÔÈç" NOR,
         HIW "ÔËÓÃ×ÔÈç" NOR,
          HIW "ÔËÓÃ×ÔÈç" NOR,
           HIW "ÔËÓÃ×ÔÈç" NOR,
           HIW "ÔËÓÃ×ÔÈç" NOR,
     
        HIW "´¥ÀàÅÔÍ¨" NOR,
 HIW "´¥ÀàÅÔÍ¨" NOR,
 HIW "´¥ÀàÅÔÍ¨" NOR,
 HIW "´¥ÀàÅÔÍ¨" NOR,
 HIW "´¥ÀàÅÔÍ¨" NOR,
 
        HIM "ÉîÈëÇ³³ö" NOR,
           HIM "ÉîÈëÇ³³ö" NOR,
              HIM "ÉîÈëÇ³³ö" NOR,
                 HIM "ÉîÈëÇ³³ö" NOR,
                    HIM "ÉîÈëÇ³³ö" NOR,
      
        HIM "ÒÑÓĞĞ¡³É" NOR,
          HIM "ÒÑÓĞĞ¡³É" NOR,
            HIM "ÒÑÓĞĞ¡³É" NOR,
              HIM "ÒÑÓĞĞ¡³É" NOR,
              HIM "ÒÑÓĞĞ¡³É" NOR,
          HIM "ÒÑÓĞĞ¡³É" NOR,
            HIM "ÒÑÓĞĞ¡³É" NOR,
              HIM "ÒÑÓĞĞ¡³É" NOR,
                HIM "ÒÑÓĞĞ¡³É" NOR,
                HIM "ÒÑÓĞĞ¡³É" NOR,
      
        HIM "ĞÄÁìÉñ»á" NOR,
          HIM "ĞÄÁìÉñ»á" NOR,
            HIM "ĞÄÁìÉñ»á" NOR,
              HIM "ĞÄÁìÉñ»á" NOR,
                HIM "ĞÄÁìÉñ»á" NOR,
                HIM "ĞÄÁìÉñ»á" NOR,
          HIM "ĞÄÁìÉñ»á" NOR,
            HIM "ĞÄÁìÉñ»á" NOR,
              HIM "ĞÄÁìÉñ»á" NOR,
                HIM "ĞÄÁìÉñ»á" NOR,
    
        RED "ÁËÈ»ì¶ĞØ" NOR,
        RED "ÁËÈ»ì¶ĞØ" NOR,
        RED "ÁËÈ»ì¶ĞØ" NOR,
        RED "ÁËÈ»ì¶ĞØ" NOR,
        RED "ÁËÈ»ì¶ĞØ" NOR,
          RED "ÁËÈ»ì¶ĞØ" NOR,
        RED "ÁËÈ»ì¶ĞØ" NOR,
        RED "ÁËÈ»ì¶ĞØ" NOR,
        RED "ÁËÈ»ì¶ĞØ" NOR,
        RED "ÁËÈ»ì¶ĞØ" NOR,
    
        RED "¼û¶àÊ¶¹ã" NOR,
RED "¼û¶àÊ¶¹ã" NOR,
RED "¼û¶àÊ¶¹ã" NOR,
RED "¼û¶àÊ¶¹ã" NOR,
RED "¼û¶àÊ¶¹ã" NOR,   
RED "¼û¶àÊ¶¹ã" NOR,   
RED "¼û¶àÊ¶¹ã" NOR,   
RED "¼û¶àÊ¶¹ã" NOR,   
RED "¼û¶àÊ¶¹ã" NOR,   
RED "¼û¶àÊ¶¹ã" NOR,   
       
        HIR "ÎŞËù²»Í¨" NOR,
  HIR "ÎŞËù²»Í¨" NOR,
  HIR "ÎŞËù²»Í¨" NOR, 
  HIR "ÎŞËù²»Í¨" NOR, 
  HIR "ÎŞËù²»Í¨" NOR, 
  HIR "ÎŞËù²»Í¨" NOR,
  HIR "ÎŞËù²»Í¨" NOR,
  HIR "ÎŞËù²»Í¨" NOR,  
  HIR "ÎŞËù²»Í¨" NOR, 
  HIR "ÎŞËù²»Í¨" NOR,       
  
        HIR "×¿¶û²»Èº" NOR,
        HIR "×¿¶û²»Èº" NOR,
        HIR "×¿¶û²»Èº" NOR,
        HIR "×¿¶û²»Èº" NOR,
        HIR "×¿¶û²»Èº" NOR,
        HIR "×¿¶û²»Èº" NOR,
        HIR "×¿¶û²»Èº" NOR,
        HIR "×¿¶û²»Èº" NOR,
        HIR "×¿¶û²»Èº" NOR,
        HIR "×¿¶û²»Èº" NOR,
        HIR "×¿¶û²»Èº" NOR,
        HIR "×¿¶û²»Èº" NOR,
        HIR "×¿¶û²»Èº" NOR,
     
        HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
      HIR "Âú¸¹¾­ÂÚ" NOR,
    
        WHT "»íÈ»¹áÍ¨" NOR,
  WHT "»íÈ»¹áÍ¨" NOR,
  WHT "»íÈ»¹áÍ¨" NOR,
  WHT "»íÈ»¹áÍ¨" NOR,
  WHT "»íÈ»¹áÍ¨" NOR,
  WHT "»íÈ»¹áÍ¨" NOR,
  WHT "»íÈ»¹áÍ¨" NOR,
  WHT "»íÈ»¹áÍ¨" NOR,
  WHT "»íÈ»¹áÍ¨" NOR,
  WHT "»íÈ»¹áÍ¨" NOR,
   WHT "»íÈ»¹áÍ¨" NOR,
  WHT "»íÈ»¹áÍ¨" NOR,
  WHT "»íÈ»¹áÍ¨" NOR,
  
        WHT "²©¹ÅÍ¨½ñ" NOR,
         WHT "²©¹ÅÍ¨½ñ" NOR,
          WHT "²©¹ÅÍ¨½ñ" NOR,
           WHT "²©¹ÅÍ¨½ñ" NOR,
            WHT "²©¹ÅÍ¨½ñ" NOR,
             WHT "²©¹ÅÍ¨½ñ" NOR,
              WHT "²©¹ÅÍ¨½ñ" NOR,
               WHT "²©¹ÅÍ¨½ñ" NOR,
                WHT "²©¹ÅÍ¨½ñ" NOR,
                 WHT "²©¹ÅÍ¨½ñ" NOR,
                 WHT "²©¹ÅÍ¨½ñ" NOR,
               WHT "²©¹ÅÍ¨½ñ" NOR,
                WHT "²©¹ÅÍ¨½ñ" NOR,
                 WHT "²©¹ÅÍ¨½ñ" NOR,
     
        WHT "²©´ó¾«Éî" NOR,
          WHT "²©´ó¾«Éî" NOR,
      WHT "²©´ó¾«Éî" NOR,
       WHT "²©´ó¾«Éî" NOR,
       WHT "²©´ó¾«Éî" NOR,
       WHT "²©´ó¾«Éî" NOR,
       WHT "²©´ó¾«Éî" NOR,
       WHT "²©´ó¾«Éî" NOR,
       WHT "²©´ó¾«Éî" NOR,
       WHT "²©´ó¾«Éî" NOR,
       WHT "²©´ó¾«Éî" NOR,
       WHT "²©´ó¾«Éî" NOR,
       WHT "²©´ó¾«Éî" NOR,
     
        WHT "³¬Èº¾øÂ×" NOR,
         WHT "³¬Èº¾øÂ×" NOR,
          WHT "³¬Èº¾øÂ×" NOR,
           WHT "³¬Èº¾øÂ×" NOR,
            WHT "³¬Èº¾øÂ×" NOR,
             WHT "³¬Èº¾øÂ×" NOR,
              WHT "³¬Èº¾øÂ×" NOR,
               WHT "³¬Èº¾øÂ×" NOR,
                WHT "³¬Èº¾øÂ×" NOR,
                 WHT "³¬Èº¾øÂ×" NOR,
                 WHT "³¬Èº¾øÂ×" NOR,
                WHT "³¬Èº¾øÂ×" NOR,
                 WHT "³¬Èº¾øÂ×" NOR,
                 
     
        WHT "¾ÙÊÀÎŞË«" NOR,
         WHT "¾ÙÊÀÎŞË«" NOR,
          WHT "¾ÙÊÀÎŞË«" NOR,
           WHT "¾ÙÊÀÎŞË«" NOR,
            WHT "¾ÙÊÀÎŞË«" NOR,
             WHT "¾ÙÊÀÎŞË«" NOR,
              WHT "¾ÙÊÀÎŞË«" NOR,
               WHT "¾ÙÊÀÎŞË«" NOR,
                WHT "¾ÙÊÀÎŞË«" NOR,
                 WHT "¾ÙÊÀÎŞË«" NOR,
       
       
        HIW "Õğ¹Åîå½ñ" NOR, 
          HIW "Õğ¹Åîå½ñ" NOR, 
            HIW "Õğ¹Åîå½ñ" NOR, 
              HIW "Õğ¹Åîå½ñ" NOR, 
                HIW "Õğ¹Åîå½ñ" NOR, 
                  HIW "Õğ¹Åîå½ñ" NOR, 
                    HIW "Õğ¹Åîå½ñ" NOR, 
                      HIW "Õğ¹Åîå½ñ" NOR, 
                        HIW "Õğ¹Åîå½ñ" NOR, 
                          HIW "Õğ¹Åîå½ñ" NOR, 
    
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
     
       
     RED "Ç°ÎŞ¹ÅÈË" NOR,
      RED "Ç°ÎŞ¹ÅÈË" NOR,
       RED "Ç°ÎŞ¹ÅÈË" NOR,
        RED "Ç°ÎŞ¹ÅÈË" NOR,
         RED "Ç°ÎŞ¹ÅÈË" NOR,
          RED "Ç°ÎŞ¹ÅÈË" NOR,
           RED "Ç°ÎŞ¹ÅÈË" NOR,
            RED "Ç°ÎŞ¹ÅÈË" NOR,
             RED "Ç°ÎŞ¹ÅÈË" NOR,
              RED "Ç°ÎŞ¹ÅÈË" NOR,
              RED "Ç°ÎŞ¹ÅÈË" NOR,
           RED "Ç°ÎŞ¹ÅÈË" NOR,
            RED "Ç°ÎŞ¹ÅÈË" NOR,
             RED "Ç°ÎŞ¹ÅÈË" NOR,
              RED "Ç°ÎŞ¹ÅÈË" NOR
   
         CYN "ºóÎŞÀ´Õß" NOR,
          CYN "ºóÎŞÀ´Õß" NOR,
           CYN "ºóÎŞÀ´Õß" NOR,
            CYN "ºóÎŞÀ´Õß" NOR,
             CYN "ºóÎŞÀ´Õß" NOR,
              CYN "ºóÎŞÀ´Õß" NOR,
               CYN "ºóÎŞÀ´Õß" NOR,
                CYN "ºóÎŞÀ´Õß" NOR,
                 CYN "ºóÎŞÀ´Õß" NOR,
                  CYN "ºóÎŞÀ´Õß" NOR,
                  CYN "ºóÎŞÀ´Õß" NOR,
               CYN "ºóÎŞÀ´Õß" NOR,
                CYN "ºóÎŞÀ´Õß" NOR,
                 CYN "ºóÎŞÀ´Õß" NOR,
                  CYN "ºóÎŞÀ´Õß" NOR,
     
       MAG "¾ªÌì¶¯µØ" NOR,
       MAG "¾ªÌì¶¯µØ" NOR,
       MAG "¾ªÌì¶¯µØ" NOR,
       MAG "¾ªÌì¶¯µØ" NOR,
       MAG "¾ªÌì¶¯µØ" NOR,
       MAG "¾ªÌì¶¯µØ" NOR,
       MAG "¾ªÌì¶¯µØ" NOR,
       MAG "¾ªÌì¶¯µØ" NOR,
       MAG "¾ªÌì¶¯µØ" NOR,
       MAG "¾ªÌì¶¯µØ" NOR,
       
    YEL "¹í¿ŞÀÇº¿" NOR,
    YEL "¹í¿ŞÀÇº¿" NOR,
     YEL "¹í¿ŞÀÇº¿" NOR,
    YEL "¹í¿ŞÀÇº¿" NOR,
     YEL "¹í¿ŞÀÇº¿" NOR,
    YEL "¹í¿ŞÀÇº¿" NOR,
     YEL "¹í¿ŞÀÇº¿" NOR,
    YEL "¹í¿ŞÀÇº¿" NOR,
     YEL "¹í¿ŞÀÇº¿" NOR,
    YEL "¹í¿ŞÀÇº¿" NOR,
     
    
     BLU "Ìì¾ªµØ±ä" NOR,
      BLU "Ìì¾ªµØ±ä" NOR,
       BLU "Ìì¾ªµØ±ä" NOR,
        BLU "Ìì¾ªµØ±ä" NOR,
         BLU "Ìì¾ªµØ±ä" NOR,
          BLU "Ìì¾ªµØ±ä" NOR,
           BLU "Ìì¾ªµØ±ä" NOR,
            BLU "Ìì¾ªµØ±ä" NOR,
             BLU "Ìì¾ªµØ±ä" NOR,
              BLU "Ìì¾ªµØ±ä" NOR,
               BLU "Ìì¾ªµØ±ä" NOR,
                 BLU "Ìì¾ªµØ±ä" NOR,
    
      WHT HIC"ÌìÏÂÎŞµĞ" NOR, 

});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob,*list, couple_ob;
        mapping skl, lrn, map;
        string *sname, *mapped,target,cardname,str;
        string *sk;
        int i,j,marry_flag;;
        seteuid(getuid());
        str = "";
        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) ob = LOGIN_D->find_body(arg);
                if (!ob || !me->visible(ob))
                return notify_fail("ÄãÒª²ì¿´Ë­µÄ¼¼ÄÜ£¿\n");
        }

        target = (string) me->query("couple/couple_id");        
        if(stringp(target)) couple_ob = find_player(target);
        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) && ob!=couple_ob
        && !ob->query("skill_public")
        && !ob->query("pubmaster") )
                 return notify_fail("ÄãÒª²ì¿´Ë­µÄ¼¼ÄÜ£¿\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "Äã" : ob->name()) + "Ä¿Ç°²¢Ã»ÓĞÑ§»áÈÎºÎ¼¼ÄÜ¡£\n");
                return 1;
        }
write( "[37m [45;1m"+(ob==me ? "Äã" : ob->name()) +"Ä¿Ç°ËùÑ§¹ıµÄ¼¼ÄÜ£º£¨¹²"+chinese_number(sizeof(skl))+"Ïî¼¼ÄÜ£©                                \n\n"NOR);
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        j=0;

/*
 sk = keys(skl);
        for(i=0; i<sizeof(skl); i++) {
        if( skl[sk[i]]<=0 ) 
{
        map_delete(skl, sk[i]);
                me->map_skill("unarmed");
                me->map_skill("hammer");
                me->map_skill("blade");
                me->map_skill("sword");
                me->map_skill("staff");
                me->map_skill("club");
                me->map_skill("throwing");
                me->map_skill("parry");
                me->map_skill("dodge");
                me->map_skill("magic");
                me->map_skill("axe");
                me->map_skill("array");
                me->map_skill("whip");  
                me->map_skill("finger");
                me->map_skill("hand");  
                me->map_skill("cuff");  
                me->map_skill("claw");  
                me->map_skill("strike");        
                me->map_skill("force"); 
                
                me->prepare_skill("unarmed");
                me->prepare_skill("hammer");
                me->prepare_skill("blade");
                me->prepare_skill("sword");
                me->prepare_skill("staff");
                me->prepare_skill("club");
                me->prepare_skill("throwing");
                me->prepare_skill("parry");
                me->prepare_skill("dodge");
                me->prepare_skill("magic");
//           me->prepare_skill("spells");
                me->prepare_skill("axe");
                me->prepare_skill("array");
                me->prepare_skill("whip");      
                me->prepare_skill("finger");
                me->prepare_skill("hand");      
                me->prepare_skill("cuff");      
                me->prepare_skill("claw");      
                me->prepare_skill("strike");    
                me->reset_action();
return notify_fail(HIR"ÄãµÄÎä¹¦ÓĞÎÊÌâ!ÇëÖØĞÂenableËùÓĞÎä¹¦\n"NOR);
}
}
*/
 j=0;
        for(i=0; i<sizeof(skl); i++) {
if(SKILL_D(sname[i])->type() != "knowledge" && SKILL_D(sname[i])->type() != "zhongji" &&(sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" || sname[i] == "array" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "leg" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "unarmed" )){
                j=j+1;
                }
        }
if(j>0) {str = sprintf("©°[42;1m%21s    [2;37;0m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´\n", "[37m"+chinese_number(j)+"Ïî»ù±¾¹¦·ò");}
        for(i=0; i<sizeof(skl); i++) {
if(SKILL_D(sname[i])->type() != "knowledge" &&SKILL_D(sname[i])->type() != "zhongji"&& (sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" || sname[i] == "array" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "leg" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "unarmed" )){
str += sprintf("©¦%s%s%-40s" NOR " - %-10s %4d/%9d©¦\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "¡õ"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
         if(j>0) { str += "©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼\n";}
         
         j=0;
        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="knowledge"){
                j=j+1;
                }
        }

 if(j>0) {str += sprintf("©°[42;1m%21s    [2;37;0m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´\n", "[37m"+chinese_number(j)+"ÏîÎÄÑ§ÖªÊ¶");}
        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="knowledge"){
  str += sprintf("©¦%s%s%-40s" NOR " - %-10s %4d/%9d©¦\n", 
                         (member_array(sname[i], mapped)==-1? "  ": "[1;35m¡õ[2;37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
         if(j>0) { str += "©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼\n";}

        j=0;
        for(i=0; i<sizeof(skl); i++) {
if(SKILL_D(sname[i])->type() != "knowledge" && SKILL_D(sname[i])->type() != "zhongji" &&SKILL_D(sname[i])->type() != "fuji" &&(sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming" && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe" && sname[i] != "unarmed" )){
                j=j+1;
                }
        }
if(j>0) {str += sprintf("©°[42;1m%21s    [2;37;0m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´\n", "[37m"+chinese_number(j)+"ÏîÌØÊâ¹¦·ò");}
        for(i=0; i<sizeof(skl); i++) {
if(SKILL_D(sname[i])->type() != "zhongji" && SKILL_D(sname[i])->type() != "fuji" &&SKILL_D(sname[i])->type() != "knowledge" &&(sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming"  && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe" && sname[i] != "unarmed"
                && sname[i] != "leg" )){
str += sprintf("©¦%s%s%-40s" NOR " - %-10s %4d/%9d©¦\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "[1;32m¡õ[2;37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
         if(j>0) { str += "©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼\n";}

 j=0;       for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="fuji"){
                j=j+1;
                }
        }
if(j>0) { str += sprintf("©°[42;1m%21s    [2;37;0m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´\n", "[37m"+chinese_number(j)+"Ïî¸ß¼¶Îä¹¦");}
        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="fuji"){
  str += sprintf("©¦%s%s%-40s" NOR " - %-10s %4d/%9d©¦\n", 
                         (member_array(sname[i], mapped)==-1? "  ": "[1;37m¡õ[2;37;0m"),
   ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
         if(j>0) { str += "©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼\n";}
         
         
    
    
       j=0;       for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="zhongji"){
                j=j+1;
                }
        }
if(j>0) { str += sprintf("©°[42;1m%21s    [2;37;0m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´\n", "[37m"+chinese_number(j)+"ÏîÖÕ¼¶Îä¹¦");}
        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="zhongji"){
  str += sprintf("©¦%s%s%-40s" NOR " - %-10s %4d/%9d©¦\n", 
    (member_array(sname[i], mapped)==-1? "  ": HIC"¡õ"NOR),
    ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
         if(j>0) { str += "©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼\n";}


      
        this_player()->start_more(str);



        return 1;
}

string skill_level(string type, int level)
{
      int grade,zhongji1,zhongji2;
        object me = this_player();
    if (level>5000)
      zhongji1 = 6;
   if (level>4000&&level<5001)
      zhongji1 = 5;
   if (level>3000&&level<4001)
      zhongji1 = 4;
   if (level>2000&&level<3001)
      zhongji1 = 3;
   if (me->query("jh_dj/dj")<5&&level>2000)
         zhongji1 = 2;

   if (level>1000&&level<2001)
         zhongji1 = 2;

   if (level<1001)
         zhongji1 = 1;

   switch(type) {
             case "zhongji":
                   return zhongji_level_desc[zhongji1];
}

   grade = level / 100;

       switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}
string pet_skill(object ob)
{
        string desc;
        object  *list, couple_ob;
        mapping skl, lrn, map;
        string *sname, *mapped,target,cardname;
        int i, marry_flag;
        skl = ob->query_skills();
        if(!sizeof(skl)) {
                desc =  ob->name() + "Ä¿Ç°²¢Ã»ÓĞÑ§»áÈÎºÎ¼¼ÄÜ¡£\n";
                return desc;
        }
                desc =  ob->name() +"Ä¿Ç°ËùÑ§¹ıµÄ¼¼ÄÜ£º\n\n";
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
              desc +=  sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "£ª"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
        return desc +"\n";
}
int help(object me)
{
        write(@HELP
Ö¸Áî¸ñÊ½ : skills|cha [<Ä³ÈË>]

Õâ¸öÖ¸Áî¿ÉÒÔÈÃÄã(Äã)²éÑ¯ËùÑ§¹ıµÄ¼¼ÄÜ¡£

ÄãÒ²¿ÉÒÔÖ¸¶¨Ò»¸öºÍÄãÓĞÊ¦Í½¹ØÏµµÄ¶ÔÏó£¬ÓÃ skills ¿ÉÒÔ²éÖª¶Ô·½µÄ¼¼ÄÜ×´¿ö¡£

Î×Ê¦¿ÉÒÔ²éÑ¯ÈÎºÎÈË»ò NPC µÄ¼¼ÄÜ×´¿ö¡£

HELP
    );
    return 1;
}

