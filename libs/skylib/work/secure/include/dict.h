#define DISCONNECTED 0
#define WAITING_FOR_CONNECT 1
#define READY 2
#define RECEIVING 3
#define SENDING_DEFINE 4
#define SENDING_MATCH 5

#define INACTIVE 0
#define DEFINE 1
#define MATCH 2

#define SEARCH_MODE_ALL "*"
#define DEFAULT_SEARCH_MODE "web1913"

//#define DEBUGGER "ceres"
#define DEBUGGER ""

string *DICT_SERVERS = ({"dict.org","dict.tugraz.at","dict.rucus.ru.ac.za",
                        "dict.trit.org"});

class server_details{
 string address;
 string resolved;
 int key;
}

class connection_data {
  int fd;
  string host_name;
  string protocol;
  string msg_id;
  string *dictionaries;
  string *capabilities;
    
  string current_word;
  string message;
  mixed definitions;
  mixed *working;
    
  int status;
  int action;
  int count;
  string search_mode;
    
  object owner;
}
