mapping menpai1=([
"玄慈大师":   "少林派",
"宋远桥":     "武当派",
"灭绝师太":   "峨嵋派",
"洪七公":     "丐帮",
"岳不群":     "华山派",
"段正淳":     "镇南王府",
"本因":       "天龙寺", 
"张无忌":     "明教",
"小龙女":     "古墓派",
"丘处机":     "全真教",
"陈近南":     "云龙门",
"陈家洛":     "红花会",
"萧西楼":     "浣花剑派",
]);

mapping menpai2=([
"丁春秋":     "星宿派",
"洪安通":     "神龙教",
"何铁手":     "五毒教",
"血刀老祖":   "血刀门",
"欧阳峰":     "白驼山",
"慕容复":     "姑苏慕容",
"邀月宫主":   "移花宫",  
"东方不败":   "日月神教",
"苏星河":     "逍遥派",
"天山童姥":   "灵鹫宫",
"刀锋冷":     "杀手楼",
"黄药师":     "桃花岛",   
"裘千仞":     "铁掌帮",
]);

string *master1=({
"玄慈大师",
"宋远桥",
"灭绝师太",
"洪七公",
"岳不群",
"段正淳",
"本因", 
"张无忌",
"小龙女",
"丘处机",
"陈近南",
"陈家洛",
"萧西楼",
});

string *master2=({
"丁春秋",
"洪安通",
"何铁手",
"血刀老祖",
"欧阳峰",
"慕容复",
"邀月宫主", 
"东方不败",
"苏星河",
"天山童姥",
"刀锋冷",
"黄药师",   
"裘千仞",
});

private static string fam1;
private static string fam2;

int chousha_begin()
{
   int i,j,k;
   object *ulist;


   i=random(sizeof(master1));
   j=random(sizeof(master2));
   ulist=users();
   k=sizeof(ulist);

   fam1=menpai1[master1[i]];
   fam2=menpai2[master2[j]];

   message("channel:chat", HIB"【江湖仇杀】"+master1[i]+
   "："+fam1+"门下弟子听令，命你们在一个时辰内将\n"
   +fam2+"彻底击溃，以匡武林正义！\n"NOR,users());

   message("channel:chat", HIB"【江湖仇杀】"+master2[j]+
   "："+fam2+"弟子听令，命你们在一个时辰内将\n"
   +fam1+"彻底荡平，让他们尝尝我们的厉害！\n"NOR,users());

   while (k-- )
   {
   if ( !environment(ulist[k]) ) continue;

   if (ulist[k]->query("family/family_name") == fam1)
      ulist[k]->set_temp("chousha/fam",fam2);
   else
   if (ulist[k]->query("family/family_name") == fam2)
      ulist[k]->set_temp("chousha/fam",fam1);
   else
   continue;
   }
   this_object()->set_temp("chousha/fam1",fam1); 
   this_object()->set_temp("chousha/fam2",fam2);
   write_file("/quest/chousha/fam1",fam1,1);
   write_file("/quest/chousha/fam2",fam2,1); 

   call_out("chousha_close",1800);
   return 1;
}

void chousha_close()
{
   object *ulist;
   int k;

   ulist=users();
   k=sizeof(ulist);

   while (k--)
   {
    if ( !environment(ulist[k]) ) continue;
    if (ulist[k]->query_temp("chousha"))
    {
    ulist[k]->delete_temp("chousha");
    tell_object(ulist[k], BLK"忽然你心中生起一股厌倦的感觉，"
    +"开始疑惑的这样的江湖仇杀有何意义，\n"
    +"你看着自己沾满鲜血的手，开始不断地问自己为什么？为什么？.....\n"NOR);
    } else
    continue;
   }

   message("channel:rumor", HIB"【江湖仇杀】历时半月的"+fam1+"与"+fam2
   +"之间的仇杀终于结束了，双方皆死伤无数！\n"NOR,users());
   this_object()->delete("chousha");
   this_object()->delete_temp("chousha");

   return;
}

