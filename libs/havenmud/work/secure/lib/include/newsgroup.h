/*
 * Newsgroup object header file
 *
 * Created by Zaxan@Haven
 *
 * 26-Jul-2004
 */

#ifndef H_LIB_NEWSGROUP
#define H_LIB_NEWSGROUP

private void save_newsgroup();
nomask int eventDestruct();
private string print_previous_objects();
private int check_security();
private int check_master_access();
nomask int check_post_access();
nomask int check_read_access();
string GetGroupId();
string SetRaceRestriction(string race);
string GetRaceRestriction();
string SetTownRestriction(string town);
string GetTownRestriction();
string SetGuildRestriction(string guild);
string GetGuildRestriction();
string SetClassRestriction(string cl);
string GetClassRestriction();
string SetReligionRestriction(string religion);
string GetReligionRestriction();
string SetFriendlyName(string name);
string GetFriendlyName();
int SetPostRankRestriction(int rank);
int GetPostRankRestriction();
int SetReadRankRestriction(int rank);
int GetReadRankRestriction();
int AddPost(string author, string subject, string post);
string GetPostText(string reader, int postnum);
mapping GetPost(int postnum);
mapping *GetPosts();
int RemovePost(int postnum);
int UserHasUnreadPosts(string username);
int CleanPosts();

#endif // H_LIB_NEWSGROUP
