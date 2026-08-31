/* Queue system, created by Pyro789x October 2008
 *
 *Within this program, keep in mind that all refrences to time
 * are based off of the time as given by the time() function. For example,
 * "time elapsed" would refer to time() - thatTime, where thatTime was
 * equal to time() at the time at which thatTime was set to its value
 */
#include <std.h>

inherit DAEMON;

#define DEBUG(x) message("info", "%^BOLD%^%^RED%^QUEUE DEBUG:%^RESET%^ " + x, find_player("pytest"))

/***Valid QUEUE statuses****/
//The queue's data (short circuit function, etc) can be edited,
//and new items can be queued under this queue ID
#define QUEUE_OPEN      1
//The queue's data cannot be edited, but new
//items can still be queued under this queue ID
#define QUEUE_SET       2
//This queue's data cannot be edited and new items
//cannot be queued under this queue ID, but items
//already queued will still be executed
#define QUEUE_CLOSED    3
//This queue's data cannot be edited and new items
//cannot be queued under this queue ID, and any
//item that attempts to be executed with this
//queue ID will fail
#define QUEUE_CONDEMNED 4


//The conversation IDs are used to link each of the items
//in the queue array below with a unifying set of information
//to allow them to have access to information about their
//calling object and the parameters that were set for it without
//redundantly reproducing that same information for each line

//When I outline the structure of each array element within convoIDs,
//keep in mind that the convo ID may not even exist within the mapping,
//which is to be considered a valid condition, and should be accounted for.
//As such, you should always check that the element within the mapping is
//actually there before refrencing the individual elements
//inside of a convo ID.

//the structure of each mapping element within convoIDs:
// A single mixed array with the following elements:
// [0] : status (int)
// [1] : Time when this queue was started (int)
// [2] : Number of lines that were executed with this queue ID (int)
// [3] : Time when the most recent line was executed (int) (equal to [1] if [2] == 0)
// [4] : Calling object  (object)
// [5] : Short Circuit function (string)  (called when exiting unexpectedly/early)
// [6] : Conditional function (string) (Must return 0 for execution to continue as normal)
mapping convoIDs;


//Instead of iterating through the data for every one
//of the objects that has called this daemon to search
//for whether or not they have any queue items that need
//to be executed, we can save a lot of processing power
//by instead having the daemon store all of the functions
//that need to be executed in order of the time that they need
//to be executed in.

//There are two ways I can see doing this that could
//yield the best results. The first way would be to use a
//mapping, where the items are stored in the mapping
//with an ID relevant to their time, so that the mapping
//can be accessed on each heart_beat to only recieve those
//items which are relevant and ready to be executed at this
//time. The difficulty with this is that, if one of the mappings
//is skipped over for any reason, there will be virtually
//no way for the system to know that there are these elements
//there, and they will most likely never get executed.
//Furthermore, I have no idea how efficient the mapping itself is.
//Surely, it would take less time to input data into it than
//through method number 2, which I will outline below, but it
//may take a long time to access, which defeats the entire point of
//doing things this way in the first place.

//The second concievable method, which I currently have below,
//would be to simply store the lines as an array. In this form,
//Whenever a new conversation is created, its time values will be
//reformatted so that they instead show exactly at what mud time they
//should be executed, and then they will be put into the array in order
//from earliest time to latest. The downfall of this is that the queue will
//not start out empty, and it must be shuffled through to find the
//correct positions to place the items in. The upside of this is that it
//makes everything else extremely easy and efficient -- the heart_beat
//merely has to iterate through the array until it finds one with
//the time to be executed that is larger than the current time, which will
//prevent any items from being skipped over

//This will make actually initializing each conversation
//more expensive, but will make the heart beat much more efficient,
//which will save us more time in the long run, even though
//its initialization may lag slightly.

//A notable exception to the array structure below is
//that, although negative conversation IDs are not allowed
//to be created by external files, they may exist within
//the queue, and are meant to be interpreted as an internal
//queued item, a delayed call to a function in this very object

//the structure of each array element within queue is as follows:
// [0] : Time to be executed (int)
// [1] : Conversation ID (int)
// [2] : Function to be called (string)
// [3] : Function parameters (mixed)
mixed* queue;

void create() {
  ::create();
  set_heart_beat(1);
}


//required to ensure that queue information that is still
//waiting to be processed is not deleted

int clean_up() {
  //okay to clean up
  return ::clean_up();

  //not okay to clean up
  if(0)
    return 1;
}

//Takes an element from the queue array and attempts
//to execute it.

void execute_queue_elem(mixed* elem) {
  //TODO: actually do as expected
  //TODO: print an error message (and do something)? If conversation ID invalid
  //TODO: print an error message (and do something)? If call_out to function fails
  DEBUG("Queue element executed.");
  DEBUG(" Execute time: "+elem[0]+" ("+(((int)elem[0])-time())+")");
  DEBUG(" Conversation ID: "+elem[1]);
  DEBUG(" Function: "+elem[2]);
  DEBUG(" Parameters: "+ identify(elem[3]));
}


void heart_beat() {
  int queueItor;

  //Iterate through the queue array executing all commands
  //that are to be executed right now or which were already
  //due to be executed by now
  //Note that a check to see if 'queue' actually exists
  //is already covered by the sizeof() check

  for(queueItor=0;
    queueItor < sizeof(queue) && queue[queueItor][0] <= time();
    queueItor++) {
      execute_queue_elem(queue[queueItor]);
  }

  //At the point where the above loop exited,
  //queueItor will be pointing to an element which
  //would have caused the loop to exit, which
  //means that the element was never executed and
  //should remain in the queue

  //As such, queueItor marks what should be the first element
  //in the new queue array.

  //skip this step if the array will be the same.
  if(queueItor != 0) {
    if(queueItor >= sizeof(queue)) {
      //The new queue should be empty
      mixed* newQueue;
      queue = newQueue;
    }
    else {
      queue = queue[queueItor..<1];
    }
  }
}
