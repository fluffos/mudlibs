// Code of ShenZhou
// /d/huanghe/bangjob/bangjob1000000.c
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

        ([      "name"  : "ÀîÄª³î",
                "file"  :   "/kungfu/class/gumu/limochou",
                "where" :  "/d/jiaxing/nanhu",
                "area"  :   "¼ÎÐË",
                "type"  :   "É±",
                "bonus" :	330,
                "score" :  30,
         ]),
         
         ([     "name"  :   "ÓñÕæ×Ó",
                "file"  :   "/d/changbai/npc/yu",
                "where" :  "/d/changbai/muqiao",
                "area"  :   "³¤°×",
                "type"  :   "É±",
                "bonus" :	330,
                "score" :  30,
         ]),   
         
         ([     "name"  :   "ÏôÔ¶É½",
                "file"  :   "/d/changbai/npc/xiao",
                "where" :  "/d/changbai/guandao1",
                "area"  :   "³¤°×",
                "type"  :   "É±",
                "bonus" :	330,
                "score" :  30,
         ]),   

        ([      "name"  :  "ÐþÄÑ´óÊ¦",
                "file"  :   "/kungfu/class/shaolin/xuan-nan",
                "where" :  "/d/shaolin/banruo5",
                "area"  :   "ÉÙÁÖ",
                "type"  :   "É±",
                "bonus" :	330,
                "score" :  30,
        ]),   


             ([      "name" : "òþÉßµ¨" , 
                      "file" : "/clone/drug/mangshe-dan",  
                      "type" : "Ñ°" , 
                      "bonus": 230, 
                      "score" :  30,
              ]), 

	
	([	"name" : "öùÎ²±Þ" ,
		"file" : "/d/xixia/obj/eweibian.c", 
		"type" : "Ñ°" ,
		"bonus": 215,
		"score" :  24,
	]),

	([      "name"  :  "Ê×ÎÚ¾«",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" : 215,
                "score" :  24,
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
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        

        ([      "type"  :  "ÂòÂô",
        ]),

});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
