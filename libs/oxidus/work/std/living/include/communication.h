#ifndef __COMMUNICATION_H__
#define __COMMUNICATION_H__

void add_say(string text) ;

void add_tell(string text) ;
void set_tell_reply(string name) ;
string query_tell_reply() ;

void add_whisper(string text) ;
void set_whisper_reply(string name) ;
string query_whisper_reply() ;

string *query_says() ;
string *query_tells() ;
string *query_whispers() ;

#endif // __COMMUNICATION_H__
