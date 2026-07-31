string *typew=({
"sword",
"blade",
"hammer",
"whip",
"club",
"staff",
"throwing",
"dagger",
"axe",
});
string *typea=({
"hands",
"cloth",
"armor",
"boots",
"head",
"neck",
"surcoat",
"shield",
"waist",
"wrists",
});
public varargs void killer_rewardboss(object killer, object victim, mapping award_rate)
{
        object award_ob, *reward, *obs,ob,obtz;
        string*  award_key;
        string ob_file, ob_quality,  ob_typ;
        int i, real_rate, level, team_size,rn,ob_num,p;
string file;
string *roomlines;
string location;
int mi,yi,yai,lv,lb,money;
    string *ob_list = ({
                "/clone/family/jinkuai",
                "/clone/family/jintiao",
                "/clone/family/xiaoyuanbao",
                "/clone/family/dayuanbao",
                "/clone/family/jinding",
        });
        if ( !mapp(award_rate) || !sizeof(award_rate) )
                return;

	obs = pointerp(killer->query_team()) ? killer->query_team() : ({ killer });
	team_size = sizeof(filter_array(obs, (: objectp($1) && environment($1) == environment($(killer)) :)));

        reward = ({ });
        award_key = keys(award_rate);
        for (i = 0; i < sizeof(award_key); i++)
        {
                real_rate = award_rate[award_key[i]];
                if (team_size >= 5)
                        real_rate = real_rate * 220 / 100;
                else if (team_size == 4)
                        real_rate = real_rate * 182 / 100;
                else if (team_size == 3)
                        real_rate = real_rate * 152 / 100;
                else if (team_size == 2)
                        real_rate = real_rate * 121 / 100;
                /*
                else
                        real_rate = real_rate * 89 / 100;
                */

                if (killer->query("hyvip")>=1) real_rate *= 2;
                //MEMBER_D->is_valid_member(killer))
                        

                if (random(10000) < real_rate)
                {
                        // 掉落阵列关键字以 F I 起头表示为掉落某个特定物品
                        if (award_key[i][0..1] == "FI")
                                if ( sscanf(award_key[i], "FI&%s", ob_file) )
                                        if (objectp(award_ob = new(ob_file)))
                                                reward += ({ award_ob });



                       // 掉落阵列关键字以 R I  起头表示为掉落某个戒指 %d为等级(10-60)
                        if (award_key[i][0..1] == "RI")
                                if ( sscanf(award_key[i], "RI&%d", ob_num) )
                                        if (objectp(award_ob = new("/clone/gem/ring"+random(ob_num))))
                                                reward += ({ award_ob });

                       // 掉落阵列关键字以 G E 起头表示为掉落某个宝石 %d为等级(1-8)
                        if (award_key[i][0..1] == "GE")
                                if ( sscanf(award_key[i], "GE&%d", ob_num) )
                                        if (objectp(award_ob = new("/clone/gem/gem")))
{
	p=(random(ob_num)+1);
	if (p<(ob_num-2)) p=ob_num-2;
	award_ob->set_level(random(17),p);
                                                reward += ({ award_ob });
}
                        // 掉落阵列关键字以 J D 起头表示为掉落某个打造用升级宝石 %d为等级(1-8)
                       if (award_key[i][0..1] == "JD")
                                if ( sscanf(award_key[i], "JD&%d", ob_num) )
{
lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);
	p=(random(ob_num)+1);
	if (p<(ob_num-2)) p=ob_num-2;
ob_num=p;
if (ob_num==1) lv=100;
if (ob_num==2) lv=200;
if (ob_num==3) lv=300;
if (ob_num==4) lv=400;
if (ob_num==5) lv=500;	
if (ob_num==6) lv=600;
if (ob_num==7) lv=700;
if (ob_num>=8) lv=800;
lb=lb+lv;
                                       if (objectp(award_ob = new("/p/newweapon/weaponobj/jade"+lb)))
                                                reward += ({ award_ob });
}
                        // 掉落阵列关键字以 Y C 起头表示为掉落药材 %d为无效参数("随机等级无效)
                       if (award_key[i][0..1] == "YC")
                                if ( sscanf(award_key[i], "YC&%d", ob_num) )
{
file = read_file("/clone/medicine/ycgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
                                        if (objectp(award_ob = new(location)))
                                                reward += ({ award_ob });
}
                        // 掉落阵列关键字以 WG 起头表示为掉落宝物装备 %d为无效参数
                       if (award_key[i][0..1] == "WG")
                                if ( sscanf(award_key[i], "WG&%d", ob_num) )
{
	file = read_file("/clone/medicine/wgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
                                        if (objectp(award_ob = new(location)))
                                                reward += ({ award_ob });
}
                        // 掉落阵列关键字以 KS 起头表示为掉落打造用矿石 %d为等级(1-10)
                       if (award_key[i][0..1] == "KS")
                                if ( sscanf(award_key[i], "KS&%d", ob_num) )
{
mi=1;
	p=(random(ob_num)+1);
	if (p<(ob_num-2)) p=ob_num-2;
ob_num=p;	
if (ob_num==2) mi=2;
if (ob_num==3) mi=3;
if (ob_num==4) mi=4;
if (ob_num==5) mi=5;
if (ob_num==6) mi=6;	
if (ob_num==7) mi=7;
if (ob_num==8) mi=8;
if (ob_num==9) mi=9;
if (ob_num>=10) mi=10;		
                                        if (objectp(award_ob = new("/p/newweapon/weaponobj/kuangshi"+mi)))
                                                reward += ({ award_ob });
}
                        // 掉落阵列关键字以 BL 起头表示为掉落打造用布料 %d为等级(1-10)
                       if (award_key[i][0..1] == "BL")
                                if ( sscanf(award_key[i], "BL&%d", ob_num) )
{
mi=1;
	p=(random(ob_num)+1);
	if (p<(ob_num-2)) p=ob_num-2;
ob_num=p;
if (ob_num==2) mi=2;
if (ob_num==3) mi=3;
if (ob_num==4) mi=4;
if (ob_num==5) mi=5;
if (ob_num==6) mi=6;	
if (ob_num==7) mi=7;
if (ob_num==8) mi=8;
if (ob_num==9) mi=9;
if (ob_num==10) mi=10;		
                                        if (objectp(award_ob = new("/p/newweapon/weaponobj/buliao"+mi)))
                                                reward += ({ award_ob });
 }
                        // 掉落阵列关键字以 YW 起头表示为掉落打造武器用玉石 %d为等级(1-6)
                       if (award_key[i][0..1] == "YW")
                                if ( sscanf(award_key[i], "YW&%d", ob_num) )
{
yi=1;
	p=(random(ob_num)+1);
	if (p<(ob_num-2)) p=ob_num-2;
ob_num=p;
if (ob_num==2) yi=2;
if (ob_num==3) yi=3;
if (ob_num==4) yi=4;
if (ob_num==5) yi=5;
if (ob_num==6) yi=6;	
                                        if (objectp(award_ob = new("/p/newweapon/weaponobj/material"+yi)))
                                                reward += ({ award_ob });
}
                        // 掉落阵列关键字以 YA 起头表示为掉落打造防具用玉石 %d为等级(1-6)
                       if (award_key[i][0..1] == "YA")
                                if ( sscanf(award_key[i], "YA&%d", ob_num) )
{
yai=7;
	p=(random(ob_num)+1);
	if (p<(ob_num-2)) p=ob_num-2;
ob_num=p;
if (ob_num==2) yai=8;
if (ob_num==3) yai=9;
if (ob_num==4) yai=10;
if (ob_num==5) yai=11;
if (ob_num==6) yai=12;		
                                        if (objectp(award_ob = new("/p/newweapon/weaponobj/material"+yai)))
                                                reward += ({ award_ob });
}
 
                        // 掉落阵列关键字以 TW 起头表示为掉落打造武器 %d为等级 (0-480)
                        if (award_key[i][0..1] == "TW")
                                if ( sscanf(award_key[i], "TW&%d", ob_num) )
{
yai=random(ob_num);
if (yai> 400 && random(2)==1) yai=random(400);
if (yai> 300 && random(2)==1) yai=random(300);
if (yai> 200 && random(2)==0) yai=random(200);
                                        if (objectp(award_ob = new("/p/item/ritemw/W"+typew[random(9)]+yai)))
                                                reward += ({ award_ob }); 
}
                        // 掉落阵列关键字以 TA 起头表示为掉落打造防具 %d为等级(0-480)
                        if (award_key[i][0..1] == "TA")
                                if ( sscanf(award_key[i], "TA&%d", ob_num) )
{
yai=random(ob_num);
if (yai> 400 && random(2)==1) yai=random(400);
if (yai> 300 && random(2)==1) yai=random(300);
if (yai> 200 && random(2)==0) yai=random(200);
                                        if (objectp(award_ob = new("/p/item/ritema/A"+typea[random(10)]+yai)))
                                                reward += ({ award_ob }); 
}      

// 掉落阵列关键字以 TZ 起头表示为掉落打造武器 %d为等级 (0-2)
                        if (award_key[i][0..1] == "TZ")
                                if ( sscanf(award_key[i], "TZ&%d", ob_num) )
{
if (ob_num==0)
{
if (random(2)==1)
obtz = new("/p/item/ritemtz3/W"+typew[random(9)]+random(89));	
else	
obtz = new("/p/item/ritemtz3/A"+typea[random(10)]+random(89));	
if (objectp(award_ob = obtz))
reward += ({ award_ob }); 
}

if (ob_num==1)
{
if (random(2)==1)
obtz = new("/p/item/ritemtz2/W"+typew[random(9)]+random(14));	
else	
obtz = new("/p/item/ritemtz2/A"+typea[random(10)]+random(14));	
if (objectp(award_ob = obtz))
reward += ({ award_ob }); 
}

if (ob_num==2)
{
if (random(2)==1)
obtz = new("/p/item/ritemtz1/W"+typew[random(9)]+random(10));	
else	
obtz = new("/p/item/ritemtz1/A"+typea[random(10)]+random(10));	
if (objectp(award_ob = obtz))
reward += ({ award_ob }); 
}


}

                }
        }

        if (!arrayp(reward) || !sizeof(reward))
                return ;

//钱财必掉
        ob = new(ob_list[random(sizeof(ob_list))]);
        ob->move(environment(killer));
        ob = new(ob_list[random(sizeof(ob_list))]);
        ob->move(environment(killer));
        for (i = 0; i < sizeof(reward); i++)
{
 if (reward[i]->query("systemmake"))
{
                reward[i]->set("no_drop",0);
                reward[i]->set("no_get",0);
}
                reward[i]->move(environment(killer));
}
//随机类必掉
	file = read_file("/clone/medicine/yb");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];	
           ob = new(location);
if (ob)
{
           ob->move(environment(killer));

}

  log_file("boss", ctime(time())+sprintf("%s BOSS战杀死 %s 在 %s \n",killer->query("name"),victim->query("name"),environment(killer)->query("short")));
        return;
}