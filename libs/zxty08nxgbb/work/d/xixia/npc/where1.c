#include <ansi.h>
mapping *quest = ({
     (["short":                "丐帮 树洞下",
       "place" :              "/d/gaibang/undertre",]),   
     (["short":                "丐帮 树洞下",
        "place" :              "/d/gaibang/undertre",]),   
     (["short":                "丐帮 树洞下",
        "place" :              "/d/gaibang/undertre",]),   
     (["short":                "丐帮 树洞下",
        "place" :              "/d/gaibang/undertre",]),   
      (["short":                "少林寺 东碑林",
       "place" :              "/d/shaolin/beilin1",]), 
      (["short":                "少林寺 天王殿",
       "place" :              "/d/shaolin/twdian",]),
          });
mapping query_quest()
 {
 return quest[random(sizeof(quest))];
}
