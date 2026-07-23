// by smile 2000/03/08 检查掌门的特殊技能是否够格
//"门派名" : 需要达到的武功技能
nosave mapping zhangmen_skills = ([
"月宫"        : ({ "moonshentong","moonforce","snowsword"}),
"五庄观"      : ({ "taiyi","zhenyuan-force" }),
"南海普陀山"  : ({ "buddhism","lotusforce" }),
"东海龙宫"    : ({ "seashentong","dragonforce" }),
"将军府"      : ({ "lengquan-force" }),
"阎罗地府"    : ({ "gouhunshu","tonsillit","hellfire-whip" }),
"陷空山无底洞": ({ "kugu-blade","huntian-qigong" }),
"天魔宫"      : ({ "tianmo-dafa","tianmo-force" }),
"方寸山三星洞": ({ "dao","qianjun-bang","wuxiangforce" }),
"大雪山"      : ({ "dengxian-dafa","ningxie-force" }),
]);

nosave mapping skills_limit = ([
"moonshentong":150,
"moonforce"   :150,
"snowsword"   :160,
"taiyi"       :150,
"zhenyuan-force" :150,
"buddhism"    :150,
"lotusforce"  :150,
"seashentong" :150,
"dragonforce" :150,
"lengquan-force":150,
"gouhunshu"   :150,
"tonsillit" :130,
"hellfire-whip":150,
"kugu-blade"  :180,
"huntian-qigong":130,
"tianmo-dafa"  :150,
"tianmo-force" :150,
"dao"          :150,
"qianjun-bang" :160,
"wuxiangforce"  :150,
"dengxian-dafa":150,
"ningxie-force":150,
]);

#define DEBUG 1

int can_zhangmen(object ob)
{
 string family_name,skillname;
 string* fname;
 int myskill,limitskill;
 int i,j;
 
 family_name=ob->query("family/family_name");
 if(!family_name) return 0;
 
 fname=keys(zhangmen_skills);
 if(!fname) return 0;
 
 for(i=0;i<sizeof(fname);i++)
  if(fname[i]==family_name) break;
 if(i>=sizeof(fname)) return 0;
 
 fname=zhangmen_skills[family_name];
 if(!fname) return 0;
 
 j=0;
 for(i=0;i<sizeof(fname);i++)
  {
   skillname=fname[i];
   //这里少了检查是否有该项技能，我懒了，hehe! by smile
   limitskill=skills_limit[skillname];
   if(limitskill) {
      myskill=ob->query_skill(skillname,1);
      if(myskill>=limitskill) j++;//好，该项技能够了
    }
  }
 if(j==sizeof(fname)) return 1;//ok,这个人够资格当掌门
 return 0;
}