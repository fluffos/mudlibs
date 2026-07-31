// Code of ShenZhou
// /d/huanghe/bangjob/bangjob1500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
         ([       "name"  :  "Ä½ÈÝ²©",
                "file"  :   "/clone/npc/murong",
                "where" :  "random",
                "area"  :   "¸½½ü×ß¶¯",
                "type"  :   "É±",
                "bonus" :  380,
                "score" :  34,

        ]),
        
        
        ([      "name"  :  "×óÀäìø",
                "file"  :   "/clone/npc/zuo",
                "where" :  "random",
                "area"  :   "¸½½ü×ß¶¯",
                "type"  :   "É±",
                "bonus" :    380,
                "score" :  30,
               
         ]),

	       ([      "name" : "ÈË²Î¹û" ,
		"file" : "/clone/wiz/renshen_guo2", 
		"type" : "Ñ°" ,
		"bonus" :  360,
                "score" :  50,
		]),
	


                  ([      "name" : "òþÉßµ¨" ,  
                            "file" : "/clone/drug/mangshe-dan",   
                            "type" : "Ñ°" ,  
                            "bonus" :  360,
               	            "score" :  32,
                    ]),  


	
	([      "type"  :  "ËÍÀñ",
        ]),

        ([      "type"  :  "ËÍÀñ",
        ]),
        
        ([      "type"  :  "ËÍÀñ",
        ]),
        
        ([      "type"  :  "ËÍÀñ",
        ]),
        
        ([      "type"  :  "ËÍÀñ",

        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
       	([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
       
        ]),
        
        ([      "type"  :  "ÂòÂô",
        ]),
        
        
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
