string hsname(object me,int num);

string *hs1 = ({
  "茂司(鼠)",
});
string *hs2 = ({
  "凯特(猫)",
  "提帕(貘)",
  "齐肯(鸡)"
});
string *hs3 = ({
  "匹格(猪)",
  "多格(狗)",
});
string *hs4 = ({
  "施奈克(蛇)",
  "莫奇(猴)",
  "伊格(鹰)",
});
string *hs5 = ({
  "考特(牛)",
  "赫斯(马)",
  "格利欧(羊)",
  "谛尔(鹿)",
});
string *hs6 = ({
  "艾勒(象)",
});
string *hs7 = ({
  "沃夫(狼)",
  "佛格司(狐)"
});
string *hs8 = ({
  "雷普(豹)",
  "泰格(虎)",
  "赖尔(狮)",
  "比尔(熊)",
});
string *hs9 = ({
  "光之虎",
  "烈火雄狮",
  "碧水蓝鹰",
  "大地之熊",
  "疾风之狐",
  "邪狼",
});

string hsname(object me,int num)
{ 
  string name;

  if (num==1) name=hs1[1];
  if (num==2) name=hs2[random(2)+1];
  if (num==3) name=hs3[random(1)+1];
  if (num==4) name=hs4[random(2)+1];
  if (num==5) name=hs5[random(3)+1];
  if (num==6) name=hs6[1];
  if (num==7) name=hs7[random(1)+1];
  if (num==8) name=hs8[random(3)+1];
  if (num==9) name=hs9[random(5)+1];
  return name;
}