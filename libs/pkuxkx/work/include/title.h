//title.h
#ifndef __TITLE_H__
#define __TITLE_H__

#define TITLE_RANK     "rank"         //和门派身份、百姓身份等和社会阶层相关的Title
#define TITLE_MASTER   "master"       //和门派大弟子相关的Title
#define TITLE_GROUP    "group"        //导师流派阶层的Title
#define TITLE_GRANDM   "grandmaster"  //武学大宗师的Title
#define TITLE_MJOB1    "masterjob1"   //主流任务的Title
#define TITLE_MJOB2    "masterjob2"   //主流任务的Title
#define TITLE_MJOB3    "masterjob3"   //主流任务的Title
#define TITLE_QUEST1   "quest1"       //普通任务的title
#define TITLE_QUEST2   "quest2"       //普通任务的title
#define TITLE_QUEST3   "quest3"       //普通任务的title
#define TITLE_QUEST4   "quest4"       //普通任务的title
#define TITLE_QUEST5   "quest5"       //普通任务的title
#define TITLE_QUEST6   "quest6"       //普通任务的title
#define TITLE_QUEST7   "quest7"       //普通任务的title
#define TITLE_QUEST8   "quest8"       //普通任务的title
#define TITLE_QUEST9   "quest9"       //普通任务的title
#define TITLE_QUEST10  "quest10"      //普通任务的title
#define TITLE_TOP1     "top1"         //排行榜相关的Title
#define TITLE_TOP2     "top2"         //排行榜相关的Title
#define TITLE_TOP3     "top3"         //排行榜相关的Title
#define TITLE_TOP4     "top4"         //排行榜相关的Title
#define TITLE_TOP5     "top5"         //排行榜相关的Title
#define TITLE_TOP6     "top6"         //排行榜相关的Title
#define TITLE_TOP7     "top7"         //排行榜相关的Title
#define TITLE_TOP8     "top8"         //排行榜相关的Title
#define TITLE_TOP9     "top9"         //排行榜相关的Title
#define TITLE_TOP10    "top10"        //排行榜相关的Title
#define TITLE_COMP     "compete"      //和比武相关的Title
#define TITLE_USER     "user"         //玩家自定义的Title
#define TITLE_HONOR    "honor"        //玩家荣誉任务相关的Title
#define TITLE_OTHER    "others"       //其他Title
#define TITLE_BANG     "bang" 		  //榜单头衔",
#define TITLE_SONG1    "song1"       //大宋差遣头衔
#define TITLE_SONG2    "song2"       //大宋资阶头衔
#define TITLE_SONG3    "song3"       //大宋加官头衔
#define TITLE_SONG4    "song4"       //大宋特殊头衔
#define TITLE_SONG5    "song5"       //大宋爵位头衔
#define FACE_ORIGIN    "ORIGIN"       //原始脸谱信息，创建用户的时候写入，和LOGIN_OB里面信息一致
#define FACE_FACT      "FACT"         //实际脸谱信息，当前用户的实际脸谱信息
#define FACE_MASK      "MASK"         //虚假脸谱信息，当前用户的最外层虚假脸谱信息
#define TITLE_FAMILY   "family"       //纯门派头衔

nomask varargs int set_title(mixed, string, mixed, int);
nomask string check_title(string);
nomask varargs string get_title(string);
nomask mapping list_title();
nomask string show_title();
nomask varargs int set_face(string, string, mixed, int, mapping);
protected int mask_act();
nomask void reset_face();
void restore_face(string);
void uncover_mask();
varargs int query_face_complex(string);
varargs mapping check_mask(int, int, string);
#endif
