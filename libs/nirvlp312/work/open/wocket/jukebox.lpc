string *song;
int max,i;
id(str){ return str == "jukebox"; }
short(){ return "A jukebox"; }
long(){ write("Don't look at me!\n");
}


reset(){
  song = ({ "I love you\n",
 "oh yes i do",
 "oh i love you",
 "wont you love me too?",
  "oh baby",
  "oh baby",
  });
  max = sizeof(song);

  call_out("playsong",3);
}

playsong(){
  if(i == max) i = 0;
  tell_room(environment(this_object()),song[i]+"\n");
  i++;
  call_out("playsong",3);
}
