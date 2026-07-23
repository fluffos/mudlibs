//建筑组名单
//Lara 2001/11/09
string *member = ({
"组长，安排各成员工作和控制工程进度，主攻job", "jiuer", 
"负责描述和细节规划，主攻room", "lara",
"目前尚未归队，无任务", "piao",
"高级编程，主攻skill、quest", "mariner",
"收集资料和编程，主攻npc、obj", "fywen",
"客人","buwu",
"高级参谋","hongyan",
"高级参谋","naihe",
"客人","xbuwu",
});

int is_member(object me)
{
        int i;

        for(i=0; i<sizeof(member); i++)
                if ( me->query("id") == member[i] )     return 1;

        return 0;
}

