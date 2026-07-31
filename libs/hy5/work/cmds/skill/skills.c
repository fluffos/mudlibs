//Cracked by Roath
// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "³õÑ§Õ§Á·" NOR,		BLU "³õ¿úÃÅ¾¶" NOR,        BLU "´ÖÍ¨Æ¤Ã«" NOR,
        HIB "ÂÔÖªÒ»¶ş" NOR,     HIB "°ëÉú²»Êì" NOR,        HIB "ÂíÂí»¢»¢" NOR,
        YEL "ÂÔÓĞĞ¡³É" NOR,     YEL "ÒÑÓĞĞ¡³É" NOR,        YEL "½¥Èë¼Ñ¾³" NOR,
        YEL "¼İÇá¾ÍÊì" NOR,     YEL "ÁËÈ»ÓÚĞØ" NOR,        YEL "³öÀà°ÎİÍ" NOR,
        CYN "ÂÔÓĞ´ó³É" NOR,     CYN "ÒÑÓĞ´ó³É" NOR,        CYN "ĞÄÁìÉñ»á" NOR,
        CYN "ÎŞ¿ÉÆ¥µĞ" NOR,		CYN "ÉñºõÆä¼¼" NOR,        HIC "³öÉñÈë»¯" NOR,
        HIC "»íÈ»¹áÍ¨" NOR,     HIC "µÇ·åÔì¼«" NOR,        HIC "¼¼¹ÚÈºĞÛ" NOR,
        HIC "¾ÙÊÀÎŞË«" NOR,     HIC "Ò»´ú×ÚÊ¦" NOR,        HIC "Õğ¹Åîå½ñ" NOR,
        HIC "°ÁÊÓÈºĞÛ" NOR,     HIC "ËùÏòÅûÃÒ" NOR,        HIC "¾ªÊÀº§Ë×" NOR,
        HIY "¶À²½ÌìÏÂ" NOR,     HIY "Éî²»¿É²â" NOR,        HIY "·µÆÓ¹éÕæ" NOR, 
        HIY "ÌìÏÂÎŞµĞ" NOR
});

string *knowledge_level_desc = ({
        BLU "ĞÂÑ§Õ§ÓÃ" NOR,        BLU "²»ÉõÁËÁË" NOR,        BLU "²»Öª¶ËÄß" NOR,
        HIB "Æ½µ­ÎŞÆæ" NOR,        HIB "Ë¾¿Õ¼û¹ß" NOR,        HIB "³õ¿úÃÅ¾¶" NOR,
        MAG "ÂÔÖªÒ»¶ş" NOR,        MAG "Ã©Èû¶Ù¿ª" NOR,        MAG "ÂÔÊ¶Ö®ÎŞ" NOR,
        YEL "¹ö¹ÏÀÃÊì" NOR,        YEL "ÂíÂí»¢»¢" NOR,        YEL "Çá³µÊìÂ·" NOR,
        HIM "ÔËÓÃ×ÔÈç" NOR,        HIM "´¥ÀàÅÔÍ¨" NOR,        HIM "ÉîÈëÇ³³ö" NOR,
        CYN "ÒÑÓĞĞ¡³É" NOR,        CYN "ĞÄÁìÉñ»á" NOR,        CYN "ÁËÈ»ì¶ĞØ" NOR,
        CYN "¼û¶àÊ¶¹ã" NOR,        CYN "ÎŞËù²»Í¨" NOR,        CYN "×¿¶û²»Èº" NOR,
        HIC "Âú¸¹¾­ÂÚ" NOR,        HIC "»íÈ»¹áÍ¨" NOR,        HIC "²©¹ÅÍ¨½ñ" NOR,
        HIC "²©´ó¾«Éî" NOR,        HIC "³¬Èº¾øÂ×" NOR,        HIC "¾ÙÊÀÎŞË«" NOR,
        HIY "¶À²½ÌìÏÂ" NOR,        HIY "Õğ¹Åîå½ñ" NOR,        HIY "³¬·²ÈëÊ¥" NOR,
        HIY "Éî²»¿É²â" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob,*list, couple_ob;
        mapping skl, lrn, map;
	string *sname, *mapped,target,cardname;
        string *sk;
        int i,j,marry_flag;;
        seteuid(getuid());
if (me->query_temp("nbjob2",1) < 3 || !me->query_temp("nbjob2")) me->add_temp("nbjob2",1);
if (me->query_temp("nbjob2",1)>3) me->set_temp("nbjob2",3);
        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
if (wizardp(me))
	{
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
                if (!ob) ob = LOGIN_D->find_body(arg);
  }
                if (!ob || !me->visible(ob))
                return notify_fail("ÄãÒª²ì¿´Ë­µÄ¼¼ÄÜ£¿\n");
        }

	target = (string) me->query("couple/couple_id");	
	if(stringp(target)) couple_ob = find_player(target);
	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
	&& !me->is_apprentice_of(ob) && ob!=couple_ob
	&& !ob->query("skill_public")
	&& !ob->query("pubmaster") )
{
if (!me->query_temp("xmud")) return notify_fail("Ö»ÓĞ¹ÜÀí»òÓĞÊ¦Í½¹ØÏµµÄÈËÄÜ²ì¿´ËûÈËµÄ¼¼ÄÜ¡£\n");
if (me->query_temp("xmud")) return notify_fail("");
}
        //if (me->is_busy())
         //    return notify_fail("ÄãÕıÃ¦×ÅÄØ£¡\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "Äã" : ob->name()) + "Ä¿Ç°²¢Ã»ÓĞÑ§»áÈÎºÎ¼¼ÄÜ¡£\n");
                return 1;
        }
//me->start_	 (1);
if (me->query_temp("xmud")) write ("$skills");
        write( "[44;1m[1;33m"+(ob==me ? "Äã" : ob->name()) +"[44;1m[1;33mÄ¿Ç°ËùÑ§¹ıµÄ¼¼ÄÜ£º£¨¹²"+chinese_number(sizeof(skl))+"Ïî¼¼ÄÜ£©                               [37;0m\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        j=0;

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
		me->map_skill("spells");
		me->map_skill("leg");
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
		me->prepare_skill("spells");
		me->prepare_skill("leg");
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
        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="knowledge"){
                j=j+1;
                }
        }
        if(j>0) { printf("[32m©°[42m%21s    [40m[32m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´[37;0m\n", "[37m"+chinese_number(j)+"ÏîÖªÊ¶");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type()=="knowledge"){
                printf("[32m©¦[37;0m%s%s%-40s" NOR " - %-10s %3d/%6d[32m©¦[37;0m\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "[1;32m¡õ[37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("[32m©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼[37;0m\n");}

	j=0;
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" || sname[i] == "array" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "leg" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "unarmed"  || sname[i] == "dagger" )){
        	j=j+1;
                }
        }
        if(j>0) { printf("[32m©°[42m%21s    [40m[32m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´[37;0m\n", "[37m"+chinese_number(j)+"Ïî»ù±¾¹¦·ò");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" || sname[i] == "array" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "leg" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "unarmed" || sname[i] == "dagger"  )){
                printf("[32m©¦[37;0m%s%s%-40s" NOR " - %-10s %3d/%6d[32m©¦[37;0m\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "[1;32m¡õ[37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("[32m©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼[37;0m\n");}

	j=0;
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming" && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe" && sname[i] != "unarmed"   && sname[i] != "dagger")){
        	j=j+1;
                }
        }
        if(j>0) { printf("[32m©°[42m%21s    [40m[32m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´[37;0m\n", "[37m"+chinese_number(j)+"ÏîÌØÊâ¹¦·ò");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming"  && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe" && sname[i] != "unarmed" 
        	&& sname[i] != "leg" && sname[i] != "dagger")){
                printf("[32m©¦[37;0m%s%s%-40s" NOR " - %-10s %3d/%6d[32m©¦[37;0m\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "[1;32m¡õ[37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("[32m©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼[37;0m\n");}

if (me->query_temp("xmud")) write ("$#\n");
        return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 20;
//if (userp(this_object()) grade = level / 30;
	
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
