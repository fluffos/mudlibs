#include "skills_pfm_set2.h"

void copy_menpai2() {
  switch (u_menpai) {
    case "wd":           //设定武当的武功
      set("family/family_name", "武当派");
      set_skill("yinyun-ziqi", 500);     //武当内功：氤氲紫气
      set_skill("tiyunzong", 500);      //武当轻功: 踢云纵
      set_skill("taoism", 200);                        //武当杂项：道学心法
      map_skill("force", "yinyun-ziqi");
      map_skill("dodge", "tiyunzong");
      u_f_pfm = u_f_pfm + ({ (: exert_function, "yinyun" :) });             //氤氲紫气pfm:氤氲内聚
      u_f_pfm = u_f_pfm + ({ (: exert_function, "taiji" :) });             //太极
      u_f_pfm = u_f_pfm + ({ (: perform_action, "dodge.zong" :) });         //踢云纵pfm:纵   
      switch (in_level) {
        case 0:
          switch (random(3)) {
            case 0:
              set_skill("wudang-quan", 500);                 //武当低级空手：武当长拳
              map_skill("cuff", "wudang-quan");
              nw_parry = "wudang-quan";
              prepare_skill("cuff", "wudang-quan");
              set("f_skill", "wudang-quan");
              break;
            case 1:
              set_skill("zhenshan-mianzhang", 500);          //武当低级空手：震山绵掌 
              map_skill("strike", "zhenshan-mianzhang");
              nw_parry = "zhenshan-mianzhang";
              prepare_skill("strike", "zhenshan-mianzhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.bingdi" :) });  //震山绵掌pfm:花开并蒂
              set("f_skill", "zhenshan-mianzhang");
              break;
            case 2:
              set_skill("juehu-shou", 500);
              map_skill("hand", "juehu-shou");
              nw_parry = "juehu-shou";
              prepare_skill("hand", "juehu-shou");
              u_pfm = u_pfm + ({ (: perform_action, "hand.juehu" :) });  //武当绝户手pfm:绝户
              set("f_skill", "juehu-shou");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("xuanxu-daofa", 500);                          //武当低级兵器：玄虚刀法
              map_skill("blade", "xuanxu-daofa");
              w_parry = "xuanxu-daofa";
              set("f_w_skill", "xuanxu-daofa");
              u_weapon = "blade";
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("taiji-quan", 500);                                    //武当高级空手：太极拳
              map_skill("cuff", "taiji-quan");
              nw_parry = "taiji-quan";
              prepare_skill("cuff", "taiji-quan");
              u_pfm = u_pfm + ({ (: perform_action, "cuff.ji" :) });    //太极拳pfm:挤
              u_pfm = u_pfm + ({ (: perform_action, "cuff.zhannian" :) });   //粘黏
              u_pfm = u_pfm + ({ (: perform_action, "cuff.zhen" :) });    //震
              u_pfm = u_pfm + ({ (: perform_action, "cuff.luanhuan" :) });   //乱还决
              u_pfm = u_pfm + ({ (: perform_action, "cuff.yinyang" :) });   //阴阳决
              u_pfm = u_pfm + ({ (: perform_action, "cuff.gangrou" :) });   //刚柔决
              u_pfm = u_pfm + ({ (: perform_action, "cuff.dongjing" :) });   //动静决
              u_pfm = u_pfm + ({ (: perform_action, "cuff.an" :) });    //按
              set("f_skill", "taiji-quan");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("taiji-jian", 500);          //武当高级兵器：太极剑
              map_skill("sword", "taiji-jian");
              w_parry = "taiji-jian";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.chan" :) });    //太极剑pfm：缠
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.sanhuan" :) });   //三环套月
              //u_w_pfm = u_w_pfm + ({(: perform_action, "sword.lian" :)});				//连
              set("raozhi", 1);
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.raozhi" :) });   //绕指柔剑
              //							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.tongshou" :)});			//天地同寿
              u_weapon = "sword";
              set("f_w_skill", "taiji-jian");
              break;
          }
          break;
      }
      break;  //end case wd
    case "ss":            //设定嵩山武功
      set("family/family_name", "嵩山派");
      set_skill("hanbing-zhenqi", 500);     //嵩山内功：寒冰真气			
      set_skill("zhongyuefeng", 500);      //嵩山轻功：中岳风
      map_skill("force", "hanbing-zhenqi");
      map_skill("dodge", "zhongyuefeng");
      u_f_pfm = u_f_pfm + ({ (: exert_function, "hanbing" :) });   //寒冰真气pfm：寒冰
      u_f_pfm = u_f_pfm + ({ (: exert_function, "juhan" :) });     //聚寒
      u_f_pfm = u_f_pfm + ({ (: exert_function, "huti" :) });     //护提决
      switch (in_level) {
        case 0:
          switch (random(1)) {

            case 0:
              set_skill("hanbing-shenzhang", 500);        //嵩山低级空手：寒冰神掌		
              map_skill("strike", "hanbing-shenzhang");
              nw_parry = "hanbing-shenzhang";
              prepare_skill("strike", "hanbing-shenzhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.hanbing" :) });     //寒冰神掌pfm：寒冰
              set("f_skill", "hanbing-shenzhang");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("songyang-bian", 500);                               //嵩山低级武器：嵩阳鞭
              map_skill("whip", "songyang-bian");
              w_parry = "songyang-bian";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "whip.luan" :) });          //嵩阳鞭pfm：乱
              u_weapon = "whip";
              set("f_w_skill", "songyang-bian");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("songyang-shou", 500);                             //嵩山高级空手：嵩阳手
              map_skill("hand", "songyang-shou");
              nw_parry = "songyang-shou";
              prepare_skill("hand", "songyang-shou");
              u_pfm = u_pfm + ({ (: perform_action, "hand.junji" :) });        //嵩阳手pfm：竣极
              u_pfm = u_pfm + ({ (: perform_action, "hand.yinyang" :) });      //阴阳
              set("f_skill", "songyang-shou");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("songshan-jian", 500);          //嵩山高级兵器：嵩山剑法
              map_skill("sword", "songshan-jian");
              w_parry = "songshan-jian";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.feiwu" :) });         //嵩山剑法pfm：飞舞
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.leiting" :) });   //雷霆万钧
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.longfeng" :) });   //龙吟凤翔	
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.songyang" :) });   //嵩阳诀
              u_weapon = "sword";
              set("f_w_skill", "songshan-jian");
              break;
          }
          break;
      }
      break;  //end case ss			
    case "gb":                                                      //设定丐帮武功
      set("family/family_name", "丐帮");
      set_skill("huntian-qigong", 500);       //丐帮内功：混天一气功
      set_skill("xiaoyaoyou", 500);        //丐帮轻功：逍遥游	
      set_skill("begging", 200);
      set("death_times", 50);
      set_skill("bangjue", 200);
      set_skill("stealing", 200);
      set_skill("checking", 200);         //丐帮杂项：begging，bangjue，stealing，checking		
      map_skill("force", "huntian-qigong");
      map_skill("dodge", "xiaoyaoyou");
      u_f_pfm = u_f_pfm + ({ (: exert_function, "huntian" :) });          //混天气功:混天
      u_f_pfm = u_f_pfm + ({ (: exert_function, "shougong" :) });   //收功
      u_f_pfm = u_f_pfm + ({ (: exert_function, "shentong" :) });   //神通
      switch (in_level) {
        case 0:
          switch (random(2)) {
            case 0:
              set_skill("lianhua-zhang", 500);    //丐帮低级空手：莲花掌
              map_skill("strike", "lianhua-zhang");
              nw_parry = "lianhua-zhang";
              prepare_skill("strike", "lianhua-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.bingdi" :) });   //并蒂莲花
              u_pfm = u_pfm + ({ (: perform_action, "strike.cailian" :) });   //彩莲
              set("f_skill", "lianhua-zhang");
              break;
            case 1:
              set_skill("suohou-shou", 500);              //丐帮低级空手：锁喉手
              map_skill("hand", "suohou-shou");
              nw_parry = "suohou-shou";
              prepare_skill("hand", "suohou-shou");
              set("f_skill", "suohou-shou");
              break;


          }
          switch (random(3)) {
            case 0:
              set_skill("huifeng-bian", 500);                                //丐帮低级兵器：回风鞭
              map_skill("whip", "huifeng-bian");
              w_parry = "huifeng-bian";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "whip.huixuan" :) });       //回风鞭pfm：回风
              u_weapon = "whip";
              set("f_w_skill", "huifeng-bian");
              break;
            case 1:
              set_skill("liuhe-daofa", 500);          //丐帮低级兵器：莲花刀法				
              map_skill("blade", "liuhe-daofa");
              w_parry = "liuhe-daofa";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "blade.sancai" :) });       //莲花刀法pfm：奇门三才	
              u_weapon = "blade";
              set("f_w_skill", "liuhe-daofa");
              break;
            case 2:
              set_skill("fengmo-zhang", 500);          //丐帮低级兵器：疯魔杖
              set("shen", -2000);
              map_skill("staff", "fengmo-zhang");
              w_parry = "fengmo-zhang";
              u_weapon = "staff";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "staff.feizhang" :) });       //螺旋飞杖
              set("f_w_skill", "fengmo-zhang");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("xianglong-zhang", 500);        //丐帮高级空手：降龙掌
              map_skill("strike", "xianglong-zhang");
              nw_parry = "xianglong-zhang";
              prepare_skill("strike", "xianglong-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.paiyun" :) });         //降龙掌pfm：排云双掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.xiao" :) });  //啸
              u_pfm = u_pfm + ({ (: perform_action, "strike.kanglong" :) });  //亢龙无悔
              set("xlz/hang", 1);                      //出亢龙的条件
              set("f_skill", "xianglong-zhang");

              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("dagou-bang", 500);         //丐帮高级兵器：打狗棒法
              set_skill("dagou-bang", 500);
              map_skill("stick", "dagou-bang");
              w_parry = "dagou-bang";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "stick.chan" :) });        //打狗棒法pfm：缠
              //u_w_pfm = u_w_pfm + ({(: perform_action, "stick.chuo" :)});			//戳
              u_w_pfm = u_w_pfm + ({ (: perform_action, "stick.shuangjue" :) });  //棒掌双绝
              u_w_pfm = u_w_pfm + ({ (: perform_action, "stick.tiao" :) });   //挑
              //u_w_pfm = u_w_pfm + ({(: perform_action, "stick.zhuan" :)});		//转
              u_w_pfm = u_w_pfm + ({ (: perform_action, "stick.wugou" :) });  //天下无狗
              u_w_pfm = u_w_pfm + ({ (: perform_action, "stick.yin" :) });  //绊
              //u_w_pfm = u_w_pfm + ({(: perform_action, "stick.ban" :)});		//引 取消几个特别bt的
              u_w_pfm = u_w_pfm + ({ (: perform_action, "stick.pi" :) });
              u_weapon = "stick";
              set("f_w_skill", "dagou-bang");
              break;
          }
          break;
      }
      break;  //end case gb		
    case "hs":                                                      //设定华山武功
      set("family/family_name", "华山派");
      set_skill("zixia-gong", 500);        //华山内功：紫霞功
      set_skill("huashan-shenfa", 500);       //华山轻功：华山身法	
      set_skill("zhengqi-jue", 200);        //华山杂项：正气决			
      map_skill("force", "zixia-gong");
      map_skill("dodge", "huashan-shenfa");
      u_f_pfm = u_f_pfm + ({ (: exert_function, "zixia" :) });            //紫霞功pfm：zixia    
      u_f_pfm = u_f_pfm + ({ (: exert_function, "jianqi" :) });            //紫霞功pfm：jianqi  
      u_f_pfm = u_f_pfm + ({ (: exert_function, "jianyi" :) });            //紫霞功pfm：jianyi
      switch (in_level) {
        case 0:
          switch (random(1)) {
            case 0:
              set_skill("poyu-quan", 500);    //华山低级空手：破玉拳
              map_skill("cuff", "poyu-quan");
              nw_parry = "poyu-quan";
              prepare_skill("cuff", "poyu-quan");
              u_pfm = u_pfm + ({ (: perform_action, "cuff.leidong" :) });       //雷动九天
              set("f_skill", "poyu-quan");
              break;
          }
          switch (random(2)) {
            case 0:
              set_skill("fanliangyi-dao", 500);                              //华山低级兵器：反两仪刀法
              map_skill("blade", "fanliangyi-dao");
              w_parry = "fanliangyi-dao";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "blade.sanshenfeng" :) });       //反两仪刀法pfm：华岳三神峰
              u_weapon = "blade";
              set("f_w_skill", "fanliangyi-dao");
              break;
            case 1:
              set_skill("chongling-jian", 500);                              //华山低级兵器：冲灵剑法
              map_skill("sword", "chongling-jian");
              w_parry = "chongling-jian";
              //							u_w_pfm=u_w_pfm + ({(: perform_action, "sword.hebi" :)});       //冲灵剑法pfm：合壁
              u_weapon = "sword";
              set("f_w_skill", "chongling-jian");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("hunyuan-zhang", 500);    //华山低级空手：混元掌
              map_skill("strike", "hunyuan-zhang");
              nw_parry = "hunyuan-zhang";
              prepare_skill("strike", "hunyuan-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.wuji" :) });       //混元掌pfm：混元无极
              set("f_skill", "hunyuan-zhang");
              break;
          }
          switch (random(2)) {
            case 0:
              set_skill("huashan-jianfa", 500);        //华山高级兵器：华山剑法
              map_skill("sword", "huashan-jianfa");
              w_parry = "huashan-jianfa";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.fengyi" :) });      //有凤来仪
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.luomu" :) });  //无边落木
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.kuaijian" :) });  //快剑
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.lianhuan" :) });  //连环
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.cangsong" :) });  //苍松迎客
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.shijiushi" :) });  //十九式
              //							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.shunv" :)});		//淑女
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.wushuang" :) });  //无双
              //							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.xiyi" :)});			//希夷
              //							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.yangwu" :)});		//仰吾
              u_weapon = "sword";
              set("f_w_skill", "huashan-jianfa");
              break;
            case 1:
              set_skill("dugu-jiujian", 500);        //华山高级兵器：独孤九剑
              map_skill("dodge", "dugu-jiujian");
              map_skill("sword", "dugu-jiujian");
              w_parry = "dugu-jiujian";
              //							u_w_pfm = u_w_pfm + ({(: perform_action, "sword.kuangfeng" :)});    //独孤九剑pfm：狂风
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.poqi" :) });
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.pozhao" :) });
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.zongjue" :) });  //总决
              u_weapon = "sword";
              set("f_w_skill", "dugu-jiujian");
              break;
          }
          break;
      }
      break;  //end case hs
    case "tz":            //设定铁掌武功
      set("family/family_name", "铁掌帮");
      set_skill("guiyuan-tunafa", 500);     //铁掌内功：归元吐纳法			
      set_skill("shuishangpiao", 500);      //铁掌轻功：水上漂
      set_skill("tiezhang-xinfa", 200);     //铁掌杂项：铁掌心法
      map_skill("force", "guiyuan-tunafa");
      map_skill("dodge", "shuishangpiao");
      u_f_pfm = u_f_pfm + ({ (: exert_function, "guiyuan" :) });          //铁掌气功pfm：聚力
      u_f_pfm = u_f_pfm + ({ (: perform_action, "dodge.piao" :) });     //水上漂pfm:漂
      switch (in_level) {
        case 0:
          switch (random(1)) {
            case 0:
              set_skill("tiezhang-zhangfa", 500);        //铁掌高级空手：铁掌掌法		
              map_skill("strike", "tiezhang-zhangfa");       //tz 无低级空手，所以低级空手也是铁掌掌法
              nw_parry = "tiezhang-zhangfa";
              prepare_skill("strike", "tiezhang-zhangfa");
              u_pfm = u_pfm + ({ (: perform_action, "strike.duoming" :) });     //铁掌掌法pfm：夺命铁爪
              u_pfm = u_pfm + ({ (: perform_action, "strike.heisha" :) });     //铁掌掌法pfm：黑 砂 掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.heyi" :) });     //铁掌掌法pfm：阴阳合一
              u_pfm = u_pfm + ({ (: perform_action, "strike.honglei" :) });     //铁掌掌法pfm：轰雷双掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.judu" :) });     //铁掌掌法pfm：聚    毒
              u_pfm = u_pfm + ({ (: perform_action, "strike.pangen" :) });     //铁掌掌法pfm：枯树盘根
              u_pfm = u_pfm + ({ (: perform_action, "strike.pushan" :) });     //铁掌掌法pfm：铁蒲扇掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.qinna" :) });     //铁掌掌法pfm：铁掌擒拿
              u_pfm = u_pfm + ({ (: perform_action, "strike.rubairen" :) });     //铁掌掌法pfm：入 白 刃
              u_pfm = u_pfm + ({ (: perform_action, "strike.tianlei" :) });     //铁掌掌法pfm：天 雷 气
              u_pfm = u_pfm + ({ (: perform_action, "strike.xuanfeng" :) });     //铁掌掌法pfm：旋风快掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.zhangdao" :) });     //铁掌掌法pfm：铁掌掌刀
              u_pfm = u_pfm + ({ (: perform_action, "strike.tiezhang" :) });     //铁掌掌法pfm：铁掌
              set("f_skill", "tiezhang-zhangfa");
              break;
          }
          switch (random(2)) {
            case 0:
              set_skill("liuye-daofa", 500);                               //铁掌低级武器：柳叶刀法
              map_skill("blade", "liuye-daofa");
              w_parry = "liuye-daofa";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "blade.daozhang" :) });   //柳叶刀法pfm：刀掌
              u_weapon = "blade";           //需要铁掌掌法为招架，并且prepare
              set("f_w_skill", "liuye-daofa");
              break;
            case 1:
              set_skill("yingou-bifa", 500);                               //铁掌低级武器：银钩笔法
              map_skill("brush", "yingou-bifa");
              w_parry = "yingou-bifa";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "brush.caoshu" :) });   //银钩笔法pfm：草书
              u_w_pfm = u_w_pfm + ({ (: perform_action, "brush.kaishu" :) });   //银钩笔法pfm：草书
              u_w_pfm = u_w_pfm + ({ (: perform_action, "brush.shigu" :) });   //银钩笔法pfm：草书
              u_weapon = "brush";
              set("f_w_skill", "yingou-bifa");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("tiezhang-zhangfa", 500);        //铁掌高级空手：铁掌掌法		
              map_skill("strike", "tiezhang-zhangfa");
              nw_parry = "tiezhang-zhangfa";
              prepare_skill("strike", "tiezhang-zhangfa");
              u_pfm = u_pfm + ({ (: perform_action, "strike.duoming" :) });     //铁掌掌法pfm：夺命铁爪
              u_pfm = u_pfm + ({ (: perform_action, "strike.heisha" :) });     //铁掌掌法pfm：黑 砂 掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.heyi" :) });     //铁掌掌法pfm：阴阳合一
              u_pfm = u_pfm + ({ (: perform_action, "strike.honglei" :) });     //铁掌掌法pfm：轰雷双掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.judu" :) });     //铁掌掌法pfm：聚    毒
              u_pfm = u_pfm + ({ (: perform_action, "strike.pangen" :) });     //铁掌掌法pfm：枯树盘根
              u_pfm = u_pfm + ({ (: perform_action, "strike.pushan" :) });     //铁掌掌法pfm：铁蒲扇掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.qinna" :) });     //铁掌掌法pfm：铁掌擒拿
              u_pfm = u_pfm + ({ (: perform_action, "strike.rubairen" :) });     //铁掌掌法pfm：入 白 刃
              u_pfm = u_pfm + ({ (: perform_action, "strike.tianlei" :) });     //铁掌掌法pfm：天 雷 气
              u_pfm = u_pfm + ({ (: perform_action, "strike.xuanfeng" :) });     //铁掌掌法pfm：旋风快掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.zhangdao" :) });     //铁掌掌法pfm：铁掌掌刀
              u_pfm = u_pfm + ({ (: perform_action, "strike.tiezhang" :) });     //铁掌掌法pfm：铁掌
              set("f_skill", "tiezhang-zhangfa");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("lietian-fu", 500);                               //铁掌高级武器：裂天斧
              map_skill("axe", "lietian-fu");
              w_parry = "lietian-fu";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "axe.lihun" :) });    //裂天斧pfm：离魂
              u_weapon = "axe";
              set("f_w_skill", "lietian-fu");
              break;
          }
          break;
      }
      break;  //end case tz

    case "dls":            //设定大轮寺武功
      set("family/family_name", "大轮寺");
      set_skill("longxiang-boruo", 500);     //大轮寺内功：龙象般若功			
      set_skill("yuxue-dunxing", 500);      //大轮寺轻功：御雪遁形
      set_skill("huanxi-chan", 200);      //大轮寺杂项：欢喜禅
      map_skill("force", "longxiang-boruo");
      map_skill("dodge", "yuxue-dunxing");
      u_f_pfm = u_f_pfm + ({ (: exert_function, "longxiang" :) });   //龙象般若功pfm：龙象
      u_f_pfm = u_f_pfm + ({ (: exert_function, "shield" :) });      //气盾
      switch (in_level) {
        case 0:
          switch (random(2)) {
            case 0:
              set_skill("dashou-yin", 500);                             //大轮寺低级空手：大手印
              map_skill("hand", "dashou-yin");
              nw_parry = "dashou-yin";
              prepare_skill("hand", "dashou-yin");
              u_pfm = u_pfm + ({ (: perform_action, "hand.tianyin" :) });  //大手印pfm：阿修罗天印
              set("f_skill", "dashou-yin");
              break;
            case 1:
              set_skill("tianwang-zhua", 500);                             //大轮寺低级空手：大手印
              map_skill("claw", "tianwang-zhua");
              nw_parry = "tianwang-zhua";
              prepare_skill("claw", "tianwang-zhua");
              set("f_skill", "tianwang-zhua");
              break;

          }
          switch (random(1)) {
            case 0:
              set_skill("wushang-dali", 500);                               //大轮寺低级武器：无上大力杵
              map_skill("staff", "wushang-dali");
              w_parry = "wushang-dali";
              u_weapon = "staff";
              set("f_w_skill", "wushang-dali");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("huoyan-dao", 500);        //大轮寺高级空手：火焰刀		
              map_skill("strike", "huoyan-dao");
              nw_parry = "huoyan-dao";
              prepare_skill("strike", "huoyan-dao");
              u_pfm = u_pfm + ({ (: perform_action, "strike.fen" :) });     //火焰刀pfm：棼
              u_pfm = u_pfm + ({ (: perform_action, "strike.daoqi" :) });
              u_pfm = u_pfm + ({ (: perform_action, "strike.ran" :) });
              set("f_skill", "huoyan-dao");
              break;
          }
          switch (random(2)) {
            case 0:
              set_skill("xuedao-jing", 500);          //大轮寺高级兵器：血刀经
              map_skill("blade", "xuedao-jing");
              w_parry = "xuedao-jing";
              set("env/jixue", random(5) + 1);                                       //pfm 祭血设置条件
              u_w_pfm = u_w_pfm + ({ (: perform_action, "blade.jixue" :) });         //pfm 祭血
              u_w_pfm = u_w_pfm + ({ (: perform_action, "blade.shendao" :) });   //神刀穿心
              u_weapon = "blade";
              set("f_w_skill", "xuedao-jing");
              break;
            case 1:
              set_skill("xiangfu-lun", 500);          //大轮寺高级兵器：降服轮
              map_skill("hammer", "xiangfu-lun");
              w_parry = "xiangfu-lun";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "hammer.wushuai" :) });         //天人五衰
              u_w_pfm = u_w_pfm + ({ (: perform_action, "hammer.dazhuan" :) });   //大转
              u_weapon = "hammer";
              set("f_w_skill", "xiangfu-lun");
              break;
          }
          break;
      }
      break;  //end case dls				
    case "gm":            //设定古墓武功
      set("family/family_name", "古墓派");
      set_skill("yunu-xinjing", 500);      //古墓内功：玉女心经			
      set_skill("yunu-shenfa", 500);      //古墓轻功：玉女身法
      map_skill("force", "yunu-xinjing");
      map_skill("dodge", "yunu-shenfa");
      u_ub_pfm = u_ub_pfm + ({ (: exert_function, "xinjing" :) });  //玉女心经pfm：xinjing
      switch (in_level) {
        case 0:
          switch (random(2)) {
            case 0:
              set_skill("tianluo-diwang", 500);                             //古墓低级空手：天罗地网式
              map_skill("strike", "tianluo-diwang");
              nw_parry = "tianluo-diwang";
              prepare_skill("strike", "tianluo-diwang");
              set("f_skill", "tianluo-diwang");
              break;
            case 1:
              set_skill("meinu-quanfa", 500);                             //古墓低级空手：美女拳法
              map_skill("cuff", "meinu-quanfa");
              nw_parry = "meinu-quanfa";
              prepare_skill("cuff", "meinu-quanfa");
              u_pfm = u_pfm + ({ (: perform_action, "cuff.shexin" :) });  //美女拳法pfm:摄心
              set("f_skill", "meinu-quanfa");
              break;

          }
          switch (random(2)) {
            case 0:
              set_skill("yunu-jianfa", 500);                               //古墓低级武器：玉女素心剑
              map_skill("sword", "yunu-jianfa");
              w_parry = "yunu-jianfa";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.suxin" :) });      //玉女素心剑pfm：素心
              u_weapon = "sword";
              set("f_w_skill", "yunu-jianfa");
              break;
            case 1:
              set_skill("quanzhen-jianfa", 500);                               //古墓低级武器：全真剑法
              map_skill("sword", "quanzhen-jianfa");
              w_parry = "quanzhen-jianfa";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.qixing" :) });      //全真剑法pfm：七星聚顶
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.sanqing" :) });        //三清风
              u_weapon = "sword";
              set("f_w_skill", "quanzhen-jianfa");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("anran-zhang", 500);        //古墓高级空手：黯然销魂掌		
              map_skill("strike", "anran-zhang");
              nw_parry = "anran-zhang";
              prepare_skill("strike", "anran-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.anran" :) });     //黯然销魂掌pfm：黯然
              u_pfm = u_pfm + ({ (: perform_action, "strike.jishi" :) });     //黯然销魂掌pfm：嫉世
              u_pfm = u_pfm + ({ (: perform_action, "strike.xiaohun" :) });     //黯然销魂掌pfm：销魂
              set("f_skill", "anran-zhang");
              break;
          }
          switch (random(2)) {
            case 0:
              set_skill("xuantie-jianfa", 500);         //古墓高级兵器：玄铁剑法
              map_skill("sword", "xuantie-jianfa");
              w_parry = "xuantie-jianfa";
              set("env/玄铁剑法", random(2) ? "海潮" : "汹涌");      //pfm 海潮的随机设定
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.haichao" :) });         //玄铁pfm：海潮
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.wujian" :) });   //无剑
              u_weapon = "sword";
              set("f_w_skill", "xuantie-jianfa");
              break;
            case 1:
              set_skill("yinsuo-jinling", 500);         //古墓高级兵器：银索金铃
              if (in_weapon) {
                pmap = query_skill_prepare();
                if (sizeof(pmap)) {
                  skill = keys(pmap);
                  foreach (string item in skill)
                    prepare_skill(item);
                }
                set_skill("meinu-quanfa", 500);          //pfm sanwu的条件之一
                map_skill("cuff", "meinu-quanfa");
                prepare_skill("cuff", "meinu-quanfa");
                set("f_skill", "meinu-quanfa");
              }
              map_skill("whip", "yinsuo-jinling");
              set("gmsanwu", 1);
              w_parry = "yinsuo-jinling";
              //u_w_pfm = u_w_pfm + ({(: perform_action, "whip.sanwu" :)});        	//银索金铃pfm：三无三不手
              u_w_pfm = u_w_pfm + ({ (: perform_action, "whip.yueyin" :) });   //yueyin
              u_weapon = "whip";
              set("f_w_skill", "yinsuo-jinling");
              break;
          }
          break;
      }
      break;  //end case gm	

    case "mr":            //设定慕容武功
      set("family/family_name", "姑苏慕容");
      set_skill("shenyuan-gong", 500);     //慕容内功：神元功			
      set_skill("yanling-shenfa", 500);      //慕容轻功：燕灵身法
      set_skill("douzhuan-xingyi", 500);      //斗转星移
      map_skill("force", "shenyuan-gong");
      map_skill("dodge", "yanling-shenfa");
      u_f_pfm = u_f_pfm + ({ (: exert_function, "shenyuan" :) });     //神元功pfm：神元
      u_f_pfm = u_f_pfm + ({ (: perform_action, "parry.xingyi" :) });     //斗转星移pfm：星移
      u_f_pfm = u_f_pfm + ({ (: perform_action, "parry.bishen" :) });  //以彼之道 还施彼身

      switch (in_level) {
        case 0:
          switch (random(1)) {
            case 0:
              set_skill("xingyi-zhang", 500);                             //慕容低级空手：星移掌
              map_skill("strike", "xingyi-zhang");
              nw_parry = "xingyi-zhang";
              prepare_skill("strike", "xingyi-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.riyue" :) });        //星移掌pfm：日月同辉
              set("f_skill", "xingyi-zhang");
              break;

          }
          switch (random(1)) {
            case 0:
              set_skill("murong-daofa", 500);                               //慕容低级武器：慕容刀法
              map_skill("blade", "murong-daofa");
              w_parry = "murong-daofa";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "blade.daoying" :) });     //慕容刀法pfm：刀影掌
              u_w_pfm = u_w_pfm + ({ (: perform_action, "blade.luandao" :) });
              u_weapon = "blade";
              set("f_w_skill", "murong-daofa");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("canhe-zhi", 500);        //慕容高级空手：参合指
              map_skill("finger", "canhe-zhi");
              nw_parry = "douzhuan-xingyi";                             //只有在参合指的情况下，才能设定douzhuan-xingyi为parry并且发pfm 
              prepare_skill("finger", "canhe-zhi");
              u_pfm = u_pfm + ({ (: perform_action, "finger.ci" :) });     //参合指pfm：刺
              set("f_skill", "canhe-zhi");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("murong-jianfa", 500);          //慕容高级兵器：慕容剑法
              map_skill("sword", "murong-jianfa");
              w_parry = "murong-jianfa";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.lianhuan" :) });         //慕容剑法pfm：连环
              u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.sanhua" :) });   //散花
              u_weapon = "sword";
              set("f_w_skill", "murong-jianfa");
              break;
          }
          break;
      }
      break;  //end case mr				

    case "sld":            //设定神龙岛武功
      set("family/family_name", "神龙教");
      set("family/master_id", "hong antong");
      set_skill("dulong-dafa", 500);      //神龙岛内功：毒龙大法 			
      set_skill("youlong-shenfa", 500);     //神龙岛轻功：游龙身法
      set_skill("shenlong-yaoli", 200);     //神龙岛杂项：神龙药理学
      map_skill("force", "dulong-dafa");
      map_skill("dodge", "youlong-shenfa");
      u_f_pfm = u_f_pfm + ({ (: exert_function, "wudi" :) });     //毒龙大法pfm：无敌	
      switch (in_level) {
        case 0:
          switch (random(2)) {
            case 0:
              set_skill("hansha-sheying", 500);                             //神龙岛低级空手：含沙射影
              map_skill("throwing", "hansha-sheying");
              nw_parry = "hansha-sheying";
              prepare_skill("throwing", "hansha-sheying");
              set("f_skill", "hansha-sheying");
              break;
            case 1:
              set_skill("shenlong-tuifa", 500);                             //神龙岛低级空手：神龙腿法
              map_skill("leg", "shenlong-tuifa");
              nw_parry = "shenlong-tuifa";
              prepare_skill("leg", "shenlong-tuifa");
              set("env/zhuiming", random(60) + 1);
              u_pfm = u_pfm + ({ (: perform_action, "leg.zhuiming" :) });          //神龙腿法pfm：追命
              set("f_skill", "shenlong-tuifa");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("lingshe-bianfa", 500);                               //神龙岛低级武器：灵蛇鞭法
              map_skill("whip", "lingshe-bianfa");
              w_parry = "lingshe-bianfa";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "whip.chan" :) });          //灵蛇鞭法pfm：缠绕
              u_w_pfm = u_w_pfm + ({ (: perform_action, "whip.sandou" :) });        //灵蛇鞭法pfm：缠绕
              u_weapon = "whip";
              set("f_w_skill", "lingshe-bianfa");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("huagu-mianzhang", 500);        //神龙岛高级空手：化骨绵掌
              map_skill("strike", "huagu-mianzhang");
              nw_parry = "huagu-mianzhang";
              prepare_skill("strike", "huagu-mianzhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.bujue" :) });     //化骨绵掌pfm：不绝
              u_pfm = u_pfm + ({ (: perform_action, "strike.huagu" :) });     //化骨绵掌pfm：化骨
              //							u_pfm = u_pfm + ({(: perform_action, "strike.puhuo" :)});     //化骨绵掌pfm：飞蛾扑火
              set("f_skill", "huagu-mianzhang");

              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("tenglong-bifa", 500);          //神龙岛高级兵器：腾龙匕法
              map_skill("dagger", "tenglong-bifa");
              w_parry = "tenglong-bifa";
              //u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.diqing" :)});        	//腾龙匕法pfm：狄青降龙 取消
              u_w_pfm = u_w_pfm + ({ (: perform_action, "dagger.feiyan" :) });   //飞燕回翔
              u_w_pfm = u_w_pfm + ({ (: perform_action, "dagger.guifei" :) });   //贵妃回眸	
              //u_w_pfm = u_w_pfm + ({(: perform_action, "dagger.luda" :)});			//鲁达拔柳
              u_w_pfm = u_w_pfm + ({ (: perform_action, "dagger.xiaolian" :) });  //小怜横陈
              u_w_pfm = u_w_pfm + ({ (: perform_action, "dagger.zixu" :) });   //子胥举鼎
              u_weapon = "dagger";
              set("f_w_skill", "tenglong-bifa");
              break;
          }
          break;
      }
      break;  //end case sld		

    case "xx":            //设定星宿武功
      set("family/family_name", "星宿派");
      set_skill("huagong-dafa", 500);      //星宿内功：化功大法			
      set_skill("zhaixingshu", 500);      //星宿轻功：摘星术 
      map_skill("force", "huagong-dafa");
      map_skill("dodge", "zhaixingshu");
      //			u_f_pfm=u_f_pfm + ({(: exert_function, "duwu" :)});   //化功大法pfm：毒雾
      set_skill("poison", 200);        // judu need poison >150							
      u_f_pfm = u_f_pfm + ({ (: exert_function, "judu" :) });   //聚毒
      switch (in_level) {
        case 0:
          switch (random(1)) {
            case 0:
              set_skill("sanyin-zhua", 500);                             //星宿低级空手：三阴蜈蚣爪
              map_skill("claw", "sanyin-zhua");
              nw_parry = "sanyin-zhua";
              prepare_skill("claw", "sanyin-zhua");
              u_pfm = u_pfm + ({ (: perform_action, "claw.sanyin" :) });
              set("f_skill", "sanyin-zhua");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("tianshan-zhang", 500);          //星宿高级兵器：天山杖法
              map_skill("staff", "tianshan-zhang");
              w_parry = "tianshan-zhang";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "staff.feizhi" :) });         //天山杖法pfm：飞掷
              u_weapon = "staff";
              set("f_w_skill", "tianshan-zhang");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("chousui-zhang", 500);        //星宿高级空手：抽髓掌		
              map_skill("strike", "chousui-zhang");
              nw_parry = "chousui-zhang";
              prepare_skill("strike", "chousui-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.biyan" :) });     //抽髓掌pfm：碧焰
              //							u_pfm = u_pfm + ({(: perform_action, "strike.fushidu" :)});     //抽髓掌pfm：腐尸毒
              u_pfm = u_pfm + ({ (: perform_action, "strike.huoqiang" :) });     //抽髓掌pfm：火墙
              u_pfm = u_pfm + ({ (: perform_action, "strike.huoqiu" :) });     //抽髓掌pfm：火球
              u_pfm = u_pfm + ({ (: perform_action, "strike.yinhuo" :) });     //抽髓掌pfm：银火
              set("f_skill", "chousui-zhang");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("tianshan-zhang", 500);          //星宿高级兵器：天山杖法
              map_skill("staff", "tianshan-zhang");
              w_parry = "tianshan-zhang";
              u_w_pfm = u_w_pfm + ({ (: perform_action, "staff.feizhi" :) });         //天山杖法pfm：飞掷
              u_weapon = "staff";
              set("f_w_skill", "tianshan-zhang");
              break;
          }
          break;
      }
      break;  //end case xx

    case "em":            //设定娥眉武功
      set("family/family_name", "峨嵋派");
      set_skill("linji-zhuang", 500);      //娥眉内功：临济十二庄			
      set_skill("anying-fuxiang", 500);     //娥眉轻功：暗影浮香
      set_skill("dacheng-fofa", 500);      //娥眉杂项：大乘佛法
      set("class", "bonze");
      map_skill("force", "linji-zhuang");
      map_skill("dodge", "anying-fuxiang");
      u_f_pfm = u_f_pfm + ({ (: exert_function, "fengyun" :) });   //临济十二庄pfm：风云
      u_f_pfm = u_f_pfm + ({ (: exert_function, "riyue" :) });  //日月
      u_f_pfm = u_f_pfm + ({ (: exert_function, "tiandi" :) });    //天地 
      u_f_pfm = u_f_pfm + ({ (: exert_function, "wuwo" :) });      //无我
      u_f_pfm = u_f_pfm + ({ (: exert_function, "yinyang" :) });   //阴阳  
      if (random(5) == 1)
        u_f_pfm = u_f_pfm + ({ (: exert_function, "youming" :) });   //幽冥  
        u_f_pfm = u_f_pfm + ({ (: exert_function, "zhixin" :) });    //之心 
        u_f_pfm = u_f_pfm + ({ (: perform_action, "dodge.huashen" :) });   //诸天化身步


        switch (in_level) {
          case 0:
            switch (random(1)) {
              case 0:
                set_skill("sixiang-zhang", 500);                             //娥眉低级空手：四象掌
                map_skill("strike", "sixiang-zhang");
                nw_parry = "sixiang-zhang";
                prepare_skill("strike", "sixiang-zhang");
                set("f_skill", "sixiang-zhang");
                break;

            }
            switch (random(1)) {
              case 0:
                set_skill("yanxing-daofa", 500);                               //娥眉低级武器：雁行刀法
                map_skill("blade", "yanxing-daofa");
                w_parry = "yanxing-daofa";
                u_w_pfm = u_w_pfm + ({ (: perform_action, "blade.feiyang" :) });          //雁行刀法pfm：飞扬
                u_w_pfm = u_w_pfm + ({ (: perform_action, "blade.huanying" :) });         //雁行刀法pfm：幻影
                u_w_pfm = u_w_pfm + ({ (: perform_action, "blade.chuanliu" :) });    // 雁行穿柳刀
                u_weapon = "blade";
                set("f_w_skill", "yanxing-daofa");
                break;
            }
            break;
          case 1:
            switch (random(1)) {
              case 0:
                set_skill("jieshou-jiushi", 500);        //娥眉高级空手：截手九式		
                map_skill("hand", "jieshou-jiushi");
                nw_parry = "jieshou-jiushi";
                prepare_skill("hand", "jieshou-jiushi");
                u_pfm = u_pfm + ({ (: perform_action, "hand.foguang" :) });     //截手九式pfm：寒冰
                set("f_skill", "jieshou-jiushi");
                break;
            }
            switch (random(1)) {
              case 0:
                set_skill("huifeng-jian", 500);          //娥眉高级兵器：回风拂柳剑
                map_skill("sword", "huifeng-jian");
                w_parry = "huifeng-jian";
                u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.jue" :) });          //回风拂柳剑pfm：绝
                u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.liaoyuan" :) });   //燎原
                u_w_pfm = u_w_pfm + ({ (: perform_action, "sword.miejue" :) });    //灭绝
                u_weapon = "sword";
                set("f_w_skill", "huifeng-jian");
                break;
            }
            break;
        }
      break;  //end case em
  }
  /////////
  copy_menpai3();
}
