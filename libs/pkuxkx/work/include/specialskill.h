string *specialsk=({
    "corporeity","ironskin","health","energy","chainless","sociability","greedy","agile",
    "might","spirituality","athanasy","intellect","constitution","perceive","lucky",   
    });      
    
string *specialsk_cn=({
    "固本培元","铜皮铁骨","气息悠长","聚精会神","金蝉脱壳","长袖善舞","饕餮之力","身轻如燕",
    "力大无穷","灵气逼人","凤凰涅磐","聪明睿智","镇蕴七星","传音搜魂","洪福齐天",   
    });      
        

string random_special(object who)
{
        string msg="";
		int i=0;
        while(1)
        {
		 if(i++ > 100) break;
         msg=specialsk[random(sizeof(specialsk))];
         if(who->query("special_skill/"+msg)) continue;
         break;
        } 
        return msg;    
}
