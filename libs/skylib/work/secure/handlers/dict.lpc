// fudged together by Zrutu, 
// based hugely on the /net/obj/dict.c object

#include <network.h>
inherit CLIENT;
#define DEBUG !
#include <dict.h>

mapping _connections = ([ ]);
mapping _dictServers = ([ ]);

/** @ignore yes */
void callback(string address, string resolved, int key){
class server_details dictServer;
 dictServer = new(class server_details, address:address, resolved:resolved, 
             key:key);
#ifdef DEBUG
 event( users(), "inform","Resolved and adding "+address+" to DICT_H:"+
           dictServer->resolved+"",
          "debug");
#endif
  _dictServers[address] = dictServer;
}


/** @ignore yes */
void create() {

  client::create();
  SetSocketType(STREAM);
  
  foreach(string str in DICT_SERVERS){
   resolve(str,"callback");
  }
} /* create() */

void close_socket( int fd, object who ) {
  if ( _connections[ who ] ) {
    eventWrite(fd, "QUIT\r\n" );
    eventAbortCallback( fd );
    eventSocketClose( fd );
    map_delete( _connections, who );
  }
} /* close_socket() */


void open_socket() {
  class server_details dServer;
  class connection_data dict;
  int new_fd;
    
  if ( _connections[ this_player() ] ) {
    tell_object(TP,"You already have a session open, to protect system "
      "resources you are limited to one session at a time.\n");
    return ;
  }
    

// Clean up _dictServers

  foreach(string str in keys(_dictServers)){
    if (!_dictServers[str]->resolved)
     map_delete(_dictServers,str);
   }
  
   if(!sizeof(_dictServers)){
#ifdef DEBUG
 event( users(), "inform","No .DICT servers have been resolved, please "
    "verify dict.h.",
          "debug");
#endif
 tell_object(TP,"There has been an error with determining a dictionary server "
    "this command is currently offline please contact a creator.\n");
  return;
  }

dServer = _dictServers[keys(_dictServers)[0]];
  new_fd = eventCreateSocket(dServer->resolved, 2628);

  if (new_fd < 0) {
#ifdef DEBUG
 event( users(), "inform","Error connecting to "+
     dServer->address+"("+dServer->resolved+").",
          "debug");
#endif
  map_delete(_dictServers,dServer->address);
  tell_object(TP,"There has been an error connecting to the "
     "dictionary server, please try again later.\n");
    return ;
  }
    
  dict = new(class connection_data, fd : new_fd, owner : this_player(),
             status : WAITING_FOR_CONNECT, count : -1, definitions : ({ }) );

  _connections[ this_player() ] = dict;
  _connections[this_player() ]->host_name = dServer->address;
  
#ifdef DEBUG
 event( users(), "inform","Connection to "+
     dServer->address+"("+dServer->resolved+") successful! WooHOO!",
          "debug");
#endif
  call_out( "close_socket", 120, new_fd, this_player() );
  return ;
} /* open_socket() */


int do_define(mixed *args) {
  class connection_data dict;
       
  if ( !( dict = _connections[ this_player() ] ) ) {
#ifdef DEBUG
 event( users(), "inform","ERROR! open a connection before you try and "
     "communicate!",
          "debug");
#endif
    return 0;
  }
    
  dict->current_word = args[0];        

  if (sizeof(args) > 1)
    dict->search_mode = SEARCH_MODE_ALL;
  else
    dict->search_mode = DEFAULT_SEARCH_MODE;    

 
  dict->status = SENDING_DEFINE;
  dict->action = DEFINE;
  eventWrite(dict->fd, sprintf("DEFINE %s %s\r\n", dict->search_mode, 
                               dict->current_word));
#ifdef DEBUG
 event( users(), "inform","Searching for "+dict->current_word+" on "+ 
                       dict-> host_name,"debug");
#endif

  tell_object(TP,"Searching Dictionary... (please be patient)\n");
  return 1;
} /* do_define() */

int do_spell(mixed *args) {
  class connection_data dict;
       
  if ( !( dict = _connections[ this_player() ] ) ) {
#ifdef DEBUG
 event( users(), "inform","ERROR! open a connection before you try and "
     "communicate!",
          "debug");
#endif
    return 0;
  }

  dict->current_word = args[0];
  if(sizeof(args) > 1)
    dict->search_mode = SEARCH_MODE_ALL;
  else
    dict->search_mode = DEFAULT_SEARCH_MODE;

  dict->status = SENDING_MATCH;
  dict->action = MATCH;
 
  eventWrite(dict->fd, sprintf("MATCH %s . %s\r\n", dict->search_mode, 
                               dict->current_word));
#ifdef DEBUG
 event( users(), "inform","Searching SPELLING on "+dict->current_word+" on "+ 
                       dict-> host_name,"debug");
#endif

  tell_object(TP,"Searching Dictionary... (please be patient)\n");
  return 1;
}


void eventRead(int fd, string message) {
  class connection_data dict;
  mapping destination;
  object who;
  string *bits, *lines, line, word, extra, dictionary_name, text;
  mixed *bing;
  int i;

#ifdef DEBUG
 
 event( users(), "inform","Receiving Message: "+message+" on fd"+ 
                       fd,"debug");
#endif 
  /* Check to see if the message is valid. */       
  if ( !stringp( message ) )
    return;
  
  /* Find the user for this connection */
  destination = filter( _connections, (: $(fd) == $2->fd :) );
  
  if ( !sizeof( destination ) )
    return;        
  
  who = keys( destination )[ 0 ];
  dict = destination[ who ];
  lines = explode( message, "\r\n" );
  
  foreach ( line in lines ) {
    if ( !sizeof( line ) )
      line = "\n";
    if ( line == "." ) {
      dict->definitions += ({ dict->working });
      dict->count = -1;
      continue;
    }
        
    bits = explode( line, " " );
    if ( !sizeof( bits ) )
      continue;

    switch ( bits[ 0 ] ) {
    case "150":
      dict->count++;
      dict->working = ({ });
      dict->status = RECEIVING;
      word = 0;
      extra = 0;
      dictionary_name = 0;
      break;
      
    case "151":                             
      if ( dict->status == RECEIVING && 
           ( sscanf( line, "151 \"%s\" %s \"%s\"", word, extra, 
                     dictionary_name ) == 3 ) )
        dict->working += ({ ({ word, dictionary_name, "" }) });
      else
        tell_creator( DEBUGGER, "Invalid 151 error code, %s, %s, %s.\n",
                      word, extra, dictionary_name );
      break;
      
    case "152":
      dict->count++;
      dict->working = ({ });
      dict->status = RECEIVING;
      word = 0;
      extra = 0;
      dictionary_name = 0;
      break;

    case "220":
      dict->status = READY;                
      dict->capabilities = explode( bits[ <2 ][1..<2], "." );
      break;
            
    case "250":
      text = "";
      switch(dict->action) {
      case DEFINE:
        for ( i = 0; i < sizeof( dict->definitions ); i++ ) {
          foreach( bing in dict->definitions[ i ] ) {
            bing[ 2 ] = replace( bing[ 2 ], 
                                 ({ "   ", " ", "\t", " " }) );
            text += who->fix_string( bing[ 2 ], 
                                     who->query_cols() - 5, 0 );
          }
          text += "\n";
        }
        tell_object( who, sprintf( "$P$Definition of %s$P$\n"
                                   "%s\n", dict->current_word, text ) );
        break;
      case MATCH:
        text = "";
        for(i=0; i<sizeof(dict->definitions); i++) {
          foreach(line in dict->definitions[i]) {
            if(sscanf(line, "%s \"%s\"", extra, word) == 2)
              text += word + "\n";
          }
        }
        tell_object(who, sprintf("$P$Spellings for %s$P$"
                                 "\n%-#*s", dict->current_word,
                                 who->query_cols(), text) + "\n");
      }
      dict->definitions = ({ });
      return;
      break;
      
    case "530":
      tell_object( who, sprintf( "The dictionary reports: %s\n"
                                 "Please contact a creator.\n", line ) );
      close_socket( fd, who );
      return;
      break;
      
    case "552":
      tell_object( who, "No definitions for " + 
                   dict->current_word + ".\n" );
      return;
      break;
      
    default:
      if ( dict->status == RECEIVING ) {
        switch(dict->action) {
        case DEFINE:
          dict->working[<1][<1] += line;
          break;
        case MATCH:
          dict->working += ({ line });
        }
      } else
      break;
    }
  }
  
#ifdef DEBUG
 event( users(), "inform","Read Code ("+bits[ 0 ]+")","debug");
#endif
  
   call_out( "close_socket", 1, fd, this_player() );
} /* eventRead() */


void dest_me() {
  class connection_data dict;
  object ob;
  foreach ( ob, dict in _connections ) {
    close_socket( dict->fd, ob );
  }
  client::dest_me();
} /* dest_me() */

mapping query_connections(){
  return _connections;       
}



mapping query_dictservers(){
  return _dictServers;
}

class connection_data query_connection_data(object player){
   if(!mappingp(_connections))
      return 0;
   if(!_connections[player])
       return 0;
   
   return _connections[player];
         
}
