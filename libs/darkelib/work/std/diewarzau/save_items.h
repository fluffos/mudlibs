/*

 * Header file for save items daemon.

 */



class uil {

  string bitlist;

  string key;

}



class locker {

  int id;

  string key;

  string base_file;

}



class locker_room {

  string file_name;

  class locker *all_lockers;

}





