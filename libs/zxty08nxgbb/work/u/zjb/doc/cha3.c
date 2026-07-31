#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "│ї╤з╒з┴╖" NOR,
        BLU "▓╗╓к╦∙╥╘" NOR,
        HIB "┤╓═и╞д├л" NOR,
        HIB "╜е╙╨╦∙╬Є" NOR,
        YEL "░ы╔·▓╗╩ь" NOR,
        YEL "┬э┬э╗в╗в" NOR,
        HIY "╞╜╡н╬▐╞ц" NOR,
        HIY "┤е└р┼╘═и" NOR,
        HIG "╨─┴ь╔ё╗с" NOR,
        HIG "╗╙╚ў╫╘╚ч" NOR,
        HIC "╝▌╟с╛═╩ь" NOR,
        HIC "│Ў└р░╬▌═" NOR,
        CYN "│ї╚ы╝╤╛│" NOR,
        CYN "╔ё║ї╞ф╝╝" NOR,
        MAG "═■▓╗┐╔╡▒" NOR,
        MAG "│Ў╔ё╚ы╗п" NOR,
        HIW "╗э╚╗╣с═и" NOR,
        HIW "│м╚║╛°┬╫" NOR,
        RED "╡╟╖х╘ь╝л" NOR,
        HIM "╥╗┤·╫┌╩ж" NOR,
        HIM "╢└▓╜╠ь╧┬" NOR,
        HIR "┐╒╟░╛°║є" NOR,
        HIR "┐ї╣┼╛°┬╫" NOR,
        WHT "╡╟╠├╚ы╩╥" NOR,
        WHT "│м╖▓╚ы╩е" NOR,
       HIW "╔ю▓╗┐╔▓т" NOR,
        NOR "╖╡ш▒╣щ╒ц" NOR,
        NOR "╖╡ш▒╣щ╒ц" NOR,
      HBRED "╟░╬▐╣┼╚╦" NOR,
      HBRED "╟░╬▐╣┼╚╦" NOR,
          HBCYN "║є╬▐└┤╒▀" NOR,
          HBCYN "║є╬▐└┤╒▀" NOR,
        HBMAG "╛к╠ь╢п╡╪" NOR,
        HBMAG "╛к╠ь╢п╡╪" NOR,
       HBYEL "╣э┐▐└╟║┐" NOR,
       HBYEL "╣э┐▐└╟║┐" NOR,
       HBBLU "╠ь╛к╡╪▒ф" NOR,
       HBBLU "╠ь╛к╡╪▒ф" NOR,
       HBWHT HIC"╠ь╧┬╬▐╡╨" NOR, 
});


string *knowledge_level_desc = ({
        BLU "╨┬╤з╒з╙├" NOR,
        BLU "▓╗╔ї┴╦┴╦" NOR,
        HIB "▓╗╓к╢╦─▀" NOR,
        HIB "╞╜╡н╬▐╞ц" NOR,
        YEL "╦╛┐╒╝√╣▀" NOR,
        YEL "│ї┐·├┼╛╢" NOR,
        HIY "┬╘╓к╥╗╢■" NOR,
        HIY "├й╚√╢┘┐к" NOR,
        CYN "┬╘╩╢╓о╬▐" NOR,
        CYN "╣Ў╣╧└├╩ь" NOR,
        MAG "┬э┬э╗в╗в" NOR,
        MAG "╟с│╡╩ь┬╖" NOR,
        HIW "╘╦╙├╫╘╚ч" NOR,
        HIW "┤е└р┼╘═и" NOR,
        HIM "╔ю╚ы╟││Ў" NOR,
        HIM "╥╤╙╨╨б│╔" NOR,
        HIM "╨─┴ь╔ё╗с" NOR,
        RED "┴╦╚╗ь╢╨╪" NOR,
        RED "╝√╢р╩╢╣у" NOR,
        HIR "╬▐╦∙▓╗═и" NOR,
        HIR "╫┐╢√▓╗╚║" NOR,
        HIR "┬·╕╣╛н┬┌" NOR,
        WHT "╗э╚╗╣с═и" NOR,
        WHT "▓й╣┼═и╜ё" NOR,
        WHT "▓й┤є╛л╔ю" NOR,
        WHT "│м╚║╛°┬╫" NOR,
        WHT "╛┘╩└╬▐╦л" NOR,
        WHT "╢└▓╜╠ь╧┬" NOR,
        HIW "╒Ё╣┼юх╜ё" NOR,
        HIW "│м╖▓╚ы╩е" NOR,
        HIW "╔ю▓╗┐╔▓т" NOR,
       HIW "╔ю▓╗┐╔▓т" NOR,
        NOR "╖╡ш▒╣щ╒ц" NOR,
        NOR "╖╡ш▒╣щ╒ц" NOR,
     HBRED "╟░╬▐╣┼╚╦" NOR,
     HBRED "╟░╬▐╣┼╚╦" NOR,
         HBCYN "║є╬▐└┤╒▀" NOR,
         HBCYN "║є╬▐└┤╒▀" NOR,
       HBMAG "╛к╠ь╢п╡╪" NOR,
       HBMAG "╛к╠ь╢п╡╪" NOR,
    HBYEL "╣э┐▐└╟║┐" NOR,
    HBYEL "╣э┐▐└╟║┐" NOR,
     HBBLU "╠ь╛к╡╪▒ф" NOR,
     HBBLU "╠ь╛к╡╪▒ф" NOR,
      HBWHT HIC"╠ь╧┬╬▐╡╨" NOR, 
      HBWHT HIC"╠ь╧┬╬▐╡╨" NOR, 

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

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) ob = LOGIN_D->find_body(arg);
                if (!ob || !me->visible(ob))
                return notify_fail("─у╥к▓ь┐┤╦н╡─╝╝─▄г┐\n");
        }

        target = (string) me->query("couple/couple_id");        
        if(stringp(target)) couple_ob = find_player(target);
        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) && ob!=couple_ob
        && !ob->query("skill_public")
        && !ob->query("pubmaster") )
                return notify_fail("╓╗╙╨╣▄└э╗Є╙╨╩ж═╜╣╪╧╡╡─╚╦─▄▓ь┐┤╦√╚╦╡─╝╝─▄бг\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "─у" : ob->name()) + "─┐╟░▓в├╗╙╨╤з╗с╚╬║╬╝╝─▄бг\n");
                return 1;
        }
write( "[37m [45;1m"+(ob==me ? "─у" : ob->name()) +"─┐╟░╦∙╤з╣¤╡─╝╝─▄г║ги╣▓"+chinese_number(sizeof(skl))+"╧ю╝╝─▄гй                                \n\n"NOR);
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
return notify_fail(HIR"─у╡─╬ф╣ж╙╨╬╩╠т!╟ы╓╪╨┬enable╦∙╙╨╬ф╣ж\n"NOR);
}
}
 j=0;
        for(i=0; i<sizeof(skl); i++) {
if(SKILL_D(sname[i])->type() != "knowledge" && SKILL_D(sname[i])->type() != "zhongji" &&(sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" || sname[i] == "array" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "leg" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "unarmed" )){
                j=j+1;
                }
        }
if(j>0) { printf("й░[42;1m%21s    [2;37;0mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤\n", "[37m"+chinese_number(j)+"╧ю╗∙▒╛╣ж╖Є");}
        for(i=0; i<sizeof(skl); i++) {
if(SKILL_D(sname[i])->type() != "knowledge" &&SKILL_D(sname[i])->type() != "zhongji"&& (sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" || sname[i] == "array" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "leg" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "unarmed" )){
  printf("йж%s%s%-40s" NOR " - %-10s %4d/%9dйж\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "бї"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
         if(j>0) { write("й╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝\n");}

        j=0;
        for(i=0; i<sizeof(skl); i++) {
if(SKILL_D(sname[i])->type() != "knowledge" && SKILL_D(sname[i])->type() != "zhongji" &&SKILL_D(sname[i])->type() != "fuji" &&(sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming" && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe" && sname[i] != "unarmed" )){
                j=j+1;
                }
        }
if(j>0) { printf("й░[42;1m%21s    [2;37;0mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤\n", "[37m"+chinese_number(j)+"╧ю╠╪╩т╣ж╖Є");}
        for(i=0; i<sizeof(skl); i++) {
if(SKILL_D(sname[i])->type() != "zhongji" && SKILL_D(sname[i])->type() != "fuji" &&SKILL_D(sname[i])->type() != "knowledge" &&(sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming"  && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe" && sname[i] != "unarmed"
                && sname[i] != "leg" )){
  printf("йж%s%s%-40s" NOR " - %-10s %4d/%9dйж\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "[1;32mбї[2;37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
  if(j>0) { write("й╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝\n");}

j=0;
        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="knowledge"){
                j=j+1;
                }
        }

 if(j>0) { printf("й░$HBGRN$%21s    $NOR$йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤\n", "$WHT$"+chinese_number(j)+"╧ю╬─╤з╓к╩╢");}
        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="knowledge"){
  printf("йж%s%s%-40s" NOR " - %-10s %4d/%9dйж\n", 
                         (member_array(sname[i], mapped)==-1? "  ": "$HIM$бї$NOR$"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
     if(j>0) { write("й╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝\n");}
    
    
       j=0;       for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="zhongji"){
                j=j+1;
                }
        }
if(j>0) { printf("й░[42;1m%21s    [2;37;0mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤\n", "[37m"+chinese_number(j)+"╧ю╓╒╝л╬ф╣ж");}
        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="zhongji"){
  printf("йж%s%s%-40s" NOR " - %-10s %4d/%9dйж\n", 
    (member_array(sname[i], mapped)==-1? "  ": HIC"бї"NOR),
    ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIC : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
     if(j>0) { write("й╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝\n");}


       j=0;       for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="fuji"){
                j=j+1;
                }
        }
if(j>0) { printf("й░[42;1m%21s    [2;37;0mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤\n", "[37m"+chinese_number(j)+"╧ю╕▀╝л╬ф╣ж");}
        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="fuji"){
  printf("йж%s%s%-40s" NOR " - %-10s %4d/%9dйж\n", 
                         (member_array(sname[i], mapped)==-1? "  ": "[1;37mбї[2;37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIW : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
     if(j>0) { write("й╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝\n");}



        return 1;
}

string skill_level(string type, int level)
{
        int grade;

     grade = level / 50;

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
                desc =  ob->name() + "─┐╟░▓в├╗╙╨╤з╗с╚╬║╬╝╝─▄бг\n";
                return desc;
        }
                desc =  ob->name() +"─┐╟░╦∙╤з╣¤╡─╝╝─▄г║\n\n";
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
              desc +=  sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "гк"),
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
╓╕┴ю╕ё╩╜ : skills|cha [<─│╚╦>]

╒т╕Ў╓╕┴ю┐╔╥╘╚├─у(─у)▓щ╤п╦∙╤з╣¤╡─╝╝─▄бг

─у╥▓┐╔╥╘╓╕╢и╥╗╕Ў║═─у╙╨╩ж═╜╣╪╧╡╡─╢╘╧єгм╙├ skills ┐╔╥╘▓щ╓к╢╘╖╜╡─╝╝─▄╫┤┐Ўбг

╬╫╩ж┐╔╥╘▓щ╤п╚╬║╬╚╦╗Є NPC ╡─╝╝─▄╫┤┐Ўбг

HELP
    );
    return 1;
}

