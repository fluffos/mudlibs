// An overlay for /std/room.c to allow chats to work in rooms without
// monsters.
// (10-19-95) Written by Chronos.
inherit "/std/room";

void create() {
  ::create();
  if (!query("chat_delay") || (int)query("chat_delay") == 0) 
    set("chat_delay", 30);
  if (!query("chat_random") || (int)query("chat_random") == 0) 
    set("chat_random", 30);
  call_out("chat_loop", ((int)query("chat_delay") + 
      random((int)query("chat_random"))) );
}

void chat_loop() {
  if (!query("room_chats")) return ;
  message("say", 
    query("room_chats")[random(sizeof(query("room_chats")))],
   this_object()) ;
  call_out("chat_loop", ((int)query("chat_delay") + 
      random((int)query("chat_random"))) );
}
