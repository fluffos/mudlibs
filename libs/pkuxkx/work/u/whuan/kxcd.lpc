string get_question(object me)
{
       int i;
       string file,str,*quest_list,*quests,answer;
       file = read_file("/d/wizard/npc/QRdata");
       quest_list =  explode(file,"\n");
       i = random(sizeof(quest_list));
       quests =  explode(quest_list[i],"@@@@");
       while(sizeof(quests)<2)  
            quests =  explode(quest_list[random(sizeof(quest_list))],"@@@@");
       str = replace_string(quests[0]," ","");
       answer = replace_string(quests[1]," ","");
       me->set_temp("answer_kxcd",answer);
       return str;    
}
