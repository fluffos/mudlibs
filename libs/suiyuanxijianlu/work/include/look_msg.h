
//modified by tlang for /cmds/std/look.c
//this is for descripe a person's bellicosit for look.c
nosave string *all_exits = ({
    "east",
    "south",
    "west",
    "north",
    "eastup",
    "southup",
    "westup",
    "northup",
    "eastdown",
    "southdown",
    "westdown",
    "northdown",
    "northeast",
    "northwest",
    "southeast",
    "southwest",
    "up",
    "down",
    "enter",
    "out",
});

string *bel_msg_male1 = ({
        "脸上露出凛冽的杀机。",
        "昂着头，冷冷地让人不敢亲近。",
});

string *bel_msg_male2 = ({
        "眉头紧锁，似乎有些心事。",
        "脸上浮现出一股虐气。",
});

string *bel_msg_male3 = ({
        "脸上露出灿烂的笑容。",
        "脸上露出愉快的微笑。",
});

string *bel_msg_female1 = ({
        "冷冰冰地让人不敢亲近。",
        "粉脸中透出一些杀气。",
});

string *bel_msg_female2 = ({
        "眉头轻蹙，似乎有些心事。",
        "有些不大高兴。",
});

string *bel_msg_female3 = ({
        "天真地笑着。",
        "愉快地笑着。",
        "看上去天真无邪。",
});

string *bel_msg_nomale1 = ({
        "似乎有什么心事。",
        "眼光到处搜索，不知道是在搜寻什么。",
});

string *bel_msg_nomale2 = ({
        "轻声叹息，眼光中有种莫名的忧伤。",
        "目光奇特，也不知道是中什么邪了。",
});

string *bel_msg_nomale3 = ({
        "露出一种莫名其妙的奇异表情。",
        "兴奋莫名，也不知道为什么。",
        "露出一种不正常的表情。",
});

string bel_status_msg(int shen,string gender)
{
        if ( gender == "男性" ) {
                if ( shen < -500 )
                return ( bel_msg_male1[random(sizeof(bel_msg_male1))]);
                else if ( shen < 0 )
                return ( bel_msg_male2[random(sizeof(bel_msg_male2))]);
                else if ( shen>=0 )
                return ( bel_msg_male3[random(sizeof(bel_msg_male3))]);
        }
        if ( gender == "女性" ) {
                if ( shen>=-500 )
                return ( bel_msg_female1[random(sizeof(bel_msg_female1))]);
                else if ( shen< 0)
                     return ( bel_msg_female2[random(sizeof(bel_msg_female2))]);
                else if ( shen>=0 )
                return ( bel_msg_female3[random(sizeof(bel_msg_female3))]);
        }
       else {
                if ( shen>=-500 )
                return ( bel_msg_nomale1[random(sizeof(bel_msg_nomale1))]);
                else if ( shen< 0 )
                        return ( bel_msg_nomale2[random(sizeof(bel_msg_nomale2))]);
                else if ( shen>=0 )
                return ( bel_msg_nomale3[random(sizeof(bel_msg_nomale3))]);
        }
}

//this is for descripe a person's per.
string *per_msg_male1 = ({
        "英俊潇洒,风度翩翩，气死潘安，羞死宋玉。" ,
        "相貌出众,面目俊朗，星目含情，剑眉露威。" ,
});

string *per_msg_male2 = ({
        "英俊潇洒,风度翩翩。",
        "相貌出众,面目俊朗。",
});
string *per_msg_male3 = ({
        "相貌平平，没什麽好看的。",
        "长得蔫蔫的，一副无精打采的模样。",
        "相貌凶恶，满脸横肉。",
});
string *per_msg_female1 = ({
        "容色秀丽，风姿绰约，有一段说不出的风流体态。",
        "长发如云，肌肤胜雪，不知倾倒了多少英雄豪杰。 ",
        "俏脸生春，妙目含情，轻轻一笑，不觉让人怦然心动。",
        "风情万种，楚楚动人，当真是我见犹怜。 ",
});

string *per_msg_female2 = ({
        "容色秀丽，风姿绰约，有一段说不出的风流体态。" ,
        "长发如云，肌肤胜雪，不知倾倒了多少英雄豪杰。 ",
        "俏脸生春，妙目含情，轻轻一笑，不觉让人怦然心动。",
        "风情万种，楚楚动人，当真是我见犹怜。 ",
});

string *per_msg_female3 = ({
        "虽算不上绝世佳人，也颇有几份姿色。 ",
        "长得还不错，颇有几份姿色。  ",
});

string *per_msg_nomale1 = ({
        "长发披肩，肌肤动人，也看不出是男是女。" ,
        "眉清目秀，有三分象宋玉，却有七分象飞燕。 ",
});
string *per_msg_nomale2 = ({
        "面目清秀，只是隐隐露出一中女儿的脂粉气。",
        "看上去也不知道长的怎样，但嘴角的笑却让男人和女人都有些心动。 ",
});

string *per_msg_nomale3 = ({
        "长得还可以，只是既没有男人的粗犷，又缺少女子的温柔。 ",
        "本来还有点粗犷美，但现在却有些扭捏作态，不男不女。",
});


string per_status_msg(int per, string gender)
{
        if ( gender == "男性" ) {
                if ( per>=25 )
                return ( per_msg_male1[random(sizeof(per_msg_male1))]);
                else if ( per>=20 )
                return ( per_msg_male2[random(sizeof(per_msg_male2))]);
                else if ( per<20 )
                return ( per_msg_male3[random(sizeof(per_msg_male3))]);
    }
        if ( gender == "女性" ) {
                if ( per>=25 )
                return ( per_msg_female1[random(sizeof(per_msg_female1))]);
                else if ( per>=20 )
                        return ( per_msg_female2[random(sizeof(per_msg_female2))]);
                else if ( per<20 )
                return ( per_msg_female3[random(sizeof(per_msg_female3))]);

    }
        else {
                if ( per>=25 )
                return ( per_msg_nomale1[random(sizeof(per_msg_nomale1))]);
                else if ( per>=20 )
                return ( per_msg_nomale2[random(sizeof(per_msg_nomale2))]);
                else if ( per<20 )
                return ( per_msg_nomale3[random(sizeof(per_msg_nomale3))]);
    }
}
string *look_level_boy = ({
 BLU "眉歪眼斜，瘌头癣脚，不象人样" NOR,
 BLU "呲牙咧嘴，黑如锅底，奇丑无比" NOR,
 BLU "面如桔皮，头肿如猪，让人不想再看第二眼" NOR,
 HIB "贼眉鼠眼，身高三尺，宛若猴状" NOR,
 HIB "肥头大耳，腹圆如鼓，手脚短粗，令人发笑" NOR,
 NOR "面颊凹陷，瘦骨伶仃，可怜可叹" NOR,
 NOR "傻头傻脑，痴痴憨憨，看来倒也老实" NOR,
 NOR "相貌平平，不会给人留下什么印象" NOR,
 YEL "膀大腰圆，满脸横肉，恶形恶相" NOR,
 YEL "腰圆背厚，面阔口方，骨格不凡" NOR,
 RED "眉目清秀，端正大方，一表人才" NOR,
 RED "双眼光华莹润，透出摄人心魄的光芒" NOR,
 HIY "举动如行云游水，独蕴风情，吸引所有异性目光" NOR,
 HIY "双目如星，眉梢传情，所见者无不为之心动" NOR,
 HIR "粉面朱唇，身姿俊俏，举止风流无限" NOR,
 HIR "丰神如玉，目似朗星，令人过目难忘" NOR,
 MAG "面如美玉，粉妆玉琢，俊美不凡" NOR,
 MAG "飘逸出尘，潇洒绝伦" NOR,
 MAG "丰神俊朗，长身玉立，宛如玉树临风" NOR,
 HIM "神清气爽，骨格清奇，宛若仙人" NOR,
 HIM "一派神人气度，仙风道骨，举止出尘" NOR,
});

string *look_level_girl = ({
  BLU "丑如无盐，状如夜叉" NOR,
  BLU "歪鼻斜眼，脸色灰败，直如鬼怪一般" NOR,
  BLU "八字眉，三角眼，鸡皮黄发，让人一见就想吐" NOR,
  HIB "眼小如豆，眉毛稀疏，手如猴爪，不成人样" NOR,
  HIB "一嘴大暴牙，让人一看就没好感" NOR,
  NOR "满脸疙瘩，皮色粗黑，丑陋不堪" NOR,
  NOR "干黄枯瘦，脸色腊黄，毫无女人味" NOR,
  YEL "身材瘦小，肌肤无光，两眼无神" NOR,
  YEL "虽不标致，倒也白净，有些动人之处" NOR,
  RED "肌肤微丰，雅淡温宛，清新可人" NOR,
  RED "鲜艳妍媚，肌肤莹透，引人遐思" NOR,
  HIR "娇小玲珑，宛如飞燕再世，楚楚动人" NOR,
  HIR "腮凝新荔，肌肤胜雪，目若秋水" NOR,
  HIW "粉嫩白至，如芍药笼烟，雾里看花" NOR,
  HIW "丰胸细腰，妖娆多姿，让人一看就心跳不已" NOR,
  MAG "娇若春花，媚如秋月，真的能沉鱼落雁" NOR,
  MAG "眉目如画，肌肤胜雪，真可谓闭月羞花" NOR,
  MAG "气质美如兰，才华馥比山，令人见之忘俗" NOR,
  HIM "灿若明霞，宝润如玉，恍如神妃仙子" NOR,
  HIM "美若天仙，不沾一丝烟尘" NOR,
  HIM "宛如"+HIW+"玉雕冰塑"+HIM+"，似梦似幻，已不再是凡间人物" NOR,
});
  
 string *tough_level_desc = ({
        BLU "不堪一击" NOR,
        BLU "毫不足虑" NOR,
        BLU "不足挂齿" NOR,
        BLU "初学乍练" NOR,
        HIB "初窥门径" NOR,
        HIB "略知一二" NOR,
        HIB "普普通通" NOR,
        HIB "平平淡淡" NOR,
        HIB "平淡无奇" NOR,
        HIB "粗通皮毛" NOR,
        HIB "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        HIB "略有小成" NOR,
        HIB "已有小成" NOR,
        HIB "驾轻就熟" NOR,
        CYN "心领神会" NOR,
        CYN "了然於胸" NOR,
        CYN "略有大成" NOR,
        CYN "已有大成" NOR,
        CYN "豁然贯通" NOR,
        CYN "出类拔萃" NOR,
        CYN "无可匹敌" NOR,
        CYN "技冠群雄" NOR,
        CYN "神乎其技" NOR,
        CYN "出神入化" NOR,
        CYN "傲视群雄" NOR,
        HIC "登峰造极" NOR,
        HIC "所向披靡" NOR,
        HIC "一代宗师" NOR,
        HIC "神功盖世" NOR,
        HIC "举世无双" NOR,
        HIC "惊世骇俗" NOR,
        HIC "震古铄今" NOR,
        HIC "深藏不露" NOR,
        HIR "深不可测" NOR
});
string *heavy_level_desc= ({
        "极轻",
        "很轻",
        "不重",
        "不轻",
        "很重",
        "极重"
}); 
