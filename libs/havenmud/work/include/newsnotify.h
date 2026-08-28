/*
 * Contains the different newsgroup
 * notification types
 *
 * Created by Zaxan@Haven
 */

#ifndef H_NEWSGROUP_NOTIFY
#define H_NEWSGROUP_NOTIFY

#define NEWS_NOTIFY_NONE    0
#define NEWS_NOTIFY_LOGON   (1<<0)
#define NEWS_NOTIFY_ONLINE  (1<<1)

#define NEWS_NOTIFY_ALL	    NEWS_NOTIFY_LOGON | NEWS_NOTIFY_ONLINE

#endif // H_NEWSGROUP_NOTIFY
