//  MySQL System

#define HOST "localhost"
#define MYSQL_OK 1
#define MYSQL_ERROR 0
#define MYSQL_NOT_CONNECTED -1
#define MYSQL_INVALID_CONNECTION -2
#define MYSQL_ALREADY_CONNECTED -3
#define MYSQL_EXEC_ERROR -4
#define MYSQL_FETCH_ERROR -5

mapping db=([]);

varargs int connect(string s) {
   int x;
   if(!s || s=="") s="pd";
   x=db_connect(HOST, s, "pd");
   if(stringp(x)) {
     write(x);
     return MYSQL_ERROR;
   }
   if(db[s]) return MYSQL_ALREADY_CONNECTED;
   switch(x) {
     case 1: db[s]=x; return MYSQL_OK; break;
     case 0: return MYSQL_INVALID_CONNECTION;
   }
}

varargs int disconnect(string s) {
   int x;
   if(!s || s=="") s="pd";
   x=db_close(db[s]);
   switch(x) {
     case 1: return MYSQL_OK; break;
     case 0: return MYSQL_INVALID_CONNECTION;
   }
}

varargs int query(string a, string b) {
   string syntax;
   int x;
   if(!b || b=="") { b="pd"; syntax=a; } else { b=a; syntax=b; }
   x=db_exec(db[b], syntax);
   return x;
}

varargs mixed fetch(mixed a, mixed b) {
   string d;
   mixed syntax;
   mixed x;
   if(!b || b=="") { d="pd"; syntax=a; } else { d=a; syntax=b; }
   x=db_fetch(db[d], syntax);
   if(!x) return MYSQL_FETCH_ERROR;
   return x;
}

string m_error() {
}

