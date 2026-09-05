inherit NPC;
#include <ansi.h>
int find_npc(string arg);
void create()
{
set_name("千里眼", ({ "qianli yan", "eyes" }));
set("str", 30);
set("gender", "男性");
set("age", 25);
set("long",
"他就是千里眼，无所不知！\n");
set("combat_exp", 50000);
set("attitude", "friendly");
set("inquiry", ([
"找人":"找人不要钱啊，给我100gold我就给你找！\n",
"find":"找人不要钱啊，给我100gold我就给你找！\n",
]));

setup();
}
void init()
{
add_action("find_npc","find"); 
add_action("find_npc","findnpc"); 
}


int find_npc(string arg)
{
object *chn,env;
int i,j,count=0,num=0;
string enstr;

mapping mm;
mapping mtemp;

mm = ([]);

if (!arg)
return notify_fail("你必须输入想查找的人物名!\n"); 

chn = livings();
/* 
if(sscanf(arg,"%d",num)==1 && num>0) //find numbers>num的NPC数目
{

if (num<10)
return notify_fail("你查找的人物数目必须>=10!\n"); 

chn = objects("checkroom");

for(i=0;i<sizeof(chn);i++)
{
object* inv;
int number=0;
inv = all_inventory(chn[i]);
for(int k=0;k<sizeof(inv);k++)
{ 
if (living(inv[k]))
number++;
}

if (number>=num)
printf("%d -- 场景 ：%s(%s) %d位生物\n",++count,chn[i]->query("short"),base_name(chn[i]),number); 
} 
printf(HIW"\n共找到数目超过%d生物的场景%d个!!\n\n"NOR,num,count); 
return 1;

} 
*/
for(i=0;i<sizeof(chn);i++)
{
if(clonep(chn[i]) && (member_array(arg,chn[i]->parse_command_id_list())!=-1 || 
strsrch(chn[i]->query("name"),arg)!=-1))
{

count++;
if ( objectp(env=environment(chn[i])) )
enstr = sprintf("%s(%s)\n",env->query("short"),base_name(env));
else 
enstr = sprintf("不详！\n"); 

for(j=0;j<sizeof(mm);j++)
{ 
mtemp = mm [j] ;
if (mapp(mtemp)) 
{
if (mtemp["file_name"] == base_name(chn[i]) && mtemp["env"] == enstr )
{
mtemp["count"]++;
break;
} 
}
}

if (j>=sizeof(mm))
{
mtemp = ([]);
mtemp["file_name"] = base_name(chn[i]); 
mtemp["name"] = chn[i]->query("name")+"("+
chn[i]->query("id")+")";
mtemp["count"]=1;
mtemp["env"] = enstr ;
mm[j] = mtemp;
} 
} 

} 

if (count==0)
return notify_fail("好像没有这个人吧？!\n"); 

// printf(HIW"\n共找到%s %d次:\n\n"NOR,arg,count);
/*
for ( i = 0 ; i <sizeof(mm);i++)
{
mtemp = mm[i];
printf("%3d -- 人物 ：%s 自 %s %d位 \n",i+1,mtemp["name"],mtemp["file_name"],mtemp["count"]);
printf(" -- 场景 ：%s\n",mtemp["env"]);
} 
*/
i=random(sizeof(mm));
mtemp = mm[i];
printf("似乎有个叫做%s的家伙在%s",mtemp["name"],mtemp["env"]->query("short"));
printf("不知道是不是你要找的那个家伙？\n");
return 1;
} 

