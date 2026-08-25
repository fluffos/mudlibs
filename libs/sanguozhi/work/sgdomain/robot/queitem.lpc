// queitem.c by fire@lima in Nov 1998
// this is used to test if this is a robot by item test
private mapping m_class;
int init_class();
string q1(string p_id)
{
   string p_c;
   string p_s,p_ss,ret,question;
   string *c_id;
   int classes;
   ret="";
   c_id=keys(m_class);
   classes=sizeof(c_id);
   p_c=c_id[random(classes)];
   p_s=m_class[p_c][random(sizeof(m_class[p_c]))];
   question=HZK2ASC_D->hzk2asc(p_s)+"属于:\n";
   p_ss=c_id[random(classes)];
   if(p_c==p_ss) ret="1";
   question+="1. "+p_ss+"\n";
   c_id-=({p_ss});classes--;
   p_ss=c_id[random(classes)];
   if(p_c==p_ss) ret="2";
   question+="2. "+p_ss+"\n";
   c_id-=({p_ss});classes--;
    
   p_ss=c_id[random(classes)];
   if(p_c==p_ss) ret="3";
   question+="3. "+p_ss+"\n";
   c_id-=({p_ss});classes--;
        
   if(ret=="") ret="4";
   question+="4. 以上选择都不对.\n";
   tell_user(p_id,question);
   return ret;
}
string q2(string p_id)
{
   string p_c;
   string p_s,p_ss,ret,question;
   string *c_id;
   string *m_c;
   string s1,s2,s3,o;
   int classes;
   ret="";
   c_id=keys(m_class);
   
   classes=sizeof(c_id);
   p_c=c_id[random(classes)];
   c_id-=({p_c});
   m_c=m_class[p_c];
   s1=m_c[random(sizeof(m_c))];
   m_c-=({s1});
   s2=m_c[random(sizeof(m_c))];
   m_c-=({s2});
      
   s3=m_c[random(sizeof(m_c))];
   m_c-=({s3});
   p_c=c_id[random(classes-1)];
   o=m_class[p_c][random(sizeof(m_class[p_c]))];
   s1=HZK2ASC_D->hzk2asc(s1);
   o=HZK2ASC_D->hzk2asc(o);
   switch(random(4))
   {  case 0:
        question=o+s1+s2+s3+"\n";
        ret="1";
        break;
      case 1:
        question=s1+o+s2+s3+"\n";
        ret="2";
     break;
      case 2:
        question=s1+s2+o+s3+"\n";
        ret="3";
       break;
      case 3:
        question=s1+s2+s3+o+"\n";
        ret="4";
   }
   question+="上面四种东西中,与其他都不属于一类的是:\n";
   question+="1. 第一个东西\n";
   question+="2. 第二个东西\n";
   question+="3. 第三个东西\n";
   question+="4. 第四个东西\n";
   tell_user(p_id,question);
   return ret;
}
string test(string p_id)
{
   int classes;
   string ret;
   init_class();
   switch(random(2))
   {
      case 0:  // 哪一类
        ret=q1(p_id);
        return ret;
      case 1: 
        ret=q2(p_id);
        return ret;
   }
}
int init_class()
{
   m_class=([]);
   m_class["脯乳动物"]=({"猫","狗","山羊","老虎","狮子","骆驼","羊",
"野猫","大象","猎豹","狼","鹿","老鼠","犀牛","牛","马","长颈鹿",
"熊猫","棕熊","猴子","猩猩","蝙蝠","河马","狐狸","松鼠","兔子",
"刺猬"});
   m_class["昆虫"]=({"蝉","苍蝇","蜜蜂","马蜂","蚂蚁","蜻蜓","螳螂",
"蚊子","蝴蝶","蚂蚱","蛾","甲虫","放屁虫","萤火虫","蝗虫","果蝇",
"毛毛虫","牛虻","跳蚤","瓢虫","蟋蟀","臭虫","蟑螂"});
   m_class["鸟类"]=({"海鸥","燕子","驼鸟","麻雀","啄木鸟","信天翁",
"海燕","大雁","鸡","鸭子","鹅","天鹅","老鹰","猫头鹰","鸸鹋","金丝雀",
"鹈鹕","鸽子","鹦鹉","乌鸦","喜鹊","夜莺","八哥","画眉","云雀","蜂鸟",
"企鹅"});
   m_class["水果"]=({"苹果","梨","香蕉","桔子","柑子","樱桃","无花果",
"葡萄","石榴","柠檬","芒果","西瓜","哈蜜瓜","甜瓜","香瓜","柿子","菠萝",
"草莓","杏"});
   m_class["蔬菜"]=({"茄子","菠菜","土豆","西红柿","洋葱","韭菜","苦瓜",
"胡萝卜","芹菜","辣椒","葱","蒜","大蒜","黄瓜","蘑菇","西葫芦","番茄",
"茴香"});
   return sizeof(m_class);
}
