// By zjb@ty  2002.5.15
// ÒÔº£ÑóIIµÄcha.cÎª»ù´¡¸Ä±àµÄ
#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "³õÑ§Õ§Á·" NOR,
        BLU "²»ÖªËùÒÔ" NOR,
        HIB "´ÖÍ¨Æ¤Ã«" NOR,
        HIB "½¥ÓĞËùÎò" NOR,
        YEL "°ëÉú²»Êì" NOR,
        YEL "ÂíÂí»¢»¢" NOR,
        HIY "Æ½µ­ÎŞÆæ" NOR,
        HIY "´¥ÀàÅÔÍ¨" NOR,
        HIG "ĞÄÁìÉñ»á" NOR,
        HIG "»ÓÈ÷×ÔÈç" NOR,
        HIC "¼İÇá¾ÍÊì" NOR,
        HIC "³öÀà°ÎİÍ" NOR,
        CYN "³õÈë¼Ñ¾³" NOR,
        CYN "ÉñºõÆä¼¼" NOR,
        MAG "Íş²»¿Éµ±" NOR,
        MAG "³öÉñÈë»¯" NOR,
        HIW "»íÈ»¹áÍ¨" NOR,
        HIW "³¬Èº¾øÂ×" NOR,
        RED "µÇ·åÔì¼«" NOR,
        HIM "Ò»´ú×ÚÊ¦" NOR,
        HIM "¶À²½ÌìÏÂ" NOR,
        HIR "¿ÕÇ°¾øºó" NOR,
        HIR "¿õ¹Å¾øÂ×" NOR,
        WHT "µÇÌÃÈëÊÒ" NOR,
        WHT "³¬·²ÈëÊ¥" NOR,
       HIW "Éî²»¿É²â" NOR,
        NOR "·µè±¹éÕæ" NOR,
        NOR "·µè±¹éÕæ" NOR,
      HBRED "Ç°ÎŞ¹ÅÈË" NOR,
      HBRED "Ç°ÎŞ¹ÅÈË" NOR,
          HBCYN "ºóÎŞÀ´Õß" NOR,
          HBCYN "ºóÎŞÀ´Õß" NOR,
        HBMAG "¾ªÌì¶¯µØ" NOR,
        HBMAG "¾ªÌì¶¯µØ" NOR,
       HBYEL "¹í¿ŞÀÇº¿" NOR,
       HBYEL "¹í¿ŞÀÇº¿" NOR,
       HBBLU "Ìì¾ªµØ±ä" NOR,
       HBBLU "Ìì¾ªµØ±ä" NOR,
       HBWHT HIC"ÌìÏÂÎŞµĞ" NOR, 
});


string *zhongji_level_desc = ({
       BLU "³õÑ§Õ§Á·" NOR,
       HBMAG "µÚÒ»µÈ¼¶" NOR,
       HBBLU "µÚ¶şµÈ¼¶" NOR,
    HBYEL "µÚÈıµÈ¼¶" NOR,
    HBCYN "µÚËÄµÈ¼¶" NOR,
    HBRED "µÚÎåµÈ¼¶" NOR,
      HBWHT HIC"×î¸ßµÈ¼¶" NOR, 
});
string *knowledge_level_desc = ({
        BLU "ĞÂÑ§Õ§ÓÃ" NOR,
        BLU "²»ÉõÁËÁË" NOR,
        HIB "²»Öª¶ËÄß" NOR,
        HIB "Æ½µ­ÎŞÆæ" NOR,
        YEL "Ë¾¿Õ¼û¹ß" NOR,
        YEL "³õ¿úÃÅ¾¶" NOR,
        HIY "ÂÔÖªÒ»¶ş" NOR,
        HIY "Ã©Èû¶Ù¿ª" NOR,
        CYN "ÂÔÊ¶Ö®ÎŞ" NOR,
        CYN "¹ö¹ÏÀÃÊì" NOR,
        MAG "ÂíÂí»¢»¢" NOR,
        MAG "Çá³µÊìÂ·" NOR,
        HIW "ÔËÓÃ×ÔÈç" NOR,
        HIW "´¥ÀàÅÔÍ¨" NOR,
        HIM "ÉîÈëÇ³³ö" NOR,
        HIM "ÒÑÓĞĞ¡³É" NOR,
        HIM "ĞÄÁìÉñ»á" NOR,
        RED "ÁËÈ»ì¶ĞØ" NOR,
        RED "¼û¶àÊ¶¹ã" NOR,
        HIR "ÎŞËù²»Í¨" NOR,
        HIR "×¿¶û²»Èº" NOR,
        HIR "Âú¸¹¾­ÂÚ" NOR,
        WHT "»íÈ»¹áÍ¨" NOR,
        WHT "²©¹ÅÍ¨½ñ" NOR,
        WHT "²©´ó¾«Éî" NOR,
        WHT "³¬Èº¾øÂ×" NOR,
        WHT "¾ÙÊÀÎŞË«" NOR,
        WHT "¶À²½ÌìÏÂ" NOR,
        HIW "Õğ¹Åîå½ñ" NOR,
        HIW "³¬·²ÈëÊ¥" NOR,
        HIW "Éî²»¿É²â" NOR,
       HIW "Éî²»¿É²â" NOR,
        NOR "·µè±¹éÕæ" NOR,
        NOR "·µè±¹éÕæ" NOR,
     HBRED "Ç°ÎŞ¹ÅÈË" NOR,
     HBRED "Ç°ÎŞ¹ÅÈË" NOR,
         HBCYN "ºóÎŞÀ´Õß" NOR,
         HBCYN "ºóÎŞÀ´Õß" NOR,
       HBMAG "¾ªÌì¶¯µØ" NOR,
       HBMAG "¾ªÌì¶¯µØ" NOR,
    HBYEL "¹í¿ŞÀÇº¿" NOR,
    HBYEL "¹í¿ŞÀÇº¿" NOR,
     HBBLU "Ìì¾ªµØ±ä" NOR,
     HBBLU "Ìì¾ªµØ±ä" NOR,
      HBWHT HIC"ÌìÏÂÎŞµĞ" NOR, 
      HBWHT HIC"ÌìÏÂÎŞµĞ" NOR, 

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
        this_player()->start_more(str);



        return 1;
}

string skill_level(string type, int level)
{
      int grade,zhongji1,zhongji2;
        object me = this_player();
    if (level>4000)
      zhongji1 = 6;
   if (level>3000&&level<4001)
      zhongji1 = 5;
   if (level>2000&&level<3001)
      zhongji1 = 4;
   if (level>1000&&level<2001)
      zhongji1 = 3;
   if (me->query("zjb_dj/dj")<5&&level>1000)
         zhongji1 = 2;

   if (level>400&&level<1001)
         zhongji1 = 2;

   if (level<401)
         zhongji1 = 1;

   switch(type) {
             case "zhongji":
                   return zhongji_level_desc[zhongji1];
}

   grade = level / 80;

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

