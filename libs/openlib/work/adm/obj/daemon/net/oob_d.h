/*  -*- LPC -*-  */
//
// oob_d.h: header file for oob_d OOB server
// written by Tim
//
#include <element.h>

/*
 * Full path to the savefile (without .o extension)
 */
#define SAVE_OOB_D "/adm/data/oob_d"

/*
 * used by log_file()
 */
#define OOB_D_LOG "oob_d"

/*
 * Time in seconds to wait between queue advances
 */
#define TIME_TO_ADVANCE 180

/*
 * Define this macro for debugging
 */
#define DEBUG(x) log_file("oob_d.debug", x)
//#undef DEBUG

// The only things you should call externally
void OOBQueuePacket(string target_mudname, mixed *packet);  // for requests
void OOBSendPacket(string mud, mixed* packet);  // for sending replies
void OOBBegin(string mud, int auto, function on_fail);  // begin oob connect
void OOBEnd(string mud); // end oob connect (only when auto == 0 in Begin())

void create();
void open_oob_port();  // called by auth service
void close_oob_port(); // called by authd when no more connections are pending
private void eventRead(int fd, mixed *packet);
private void eventWrite(int fd, mixed *packet);
private void eventSocketClosed(int fd);
private void eventReceiveOOBEnd(int fd, string mudname);
private void eventSendPackets(int fd, string target_mudname);
private int PacketsInQueue(string mud);
private int IsConnected(string mud);
private element GetMudFromQueue(string mud);
private void eventFlushQueue();
private void ClientConnect(string mud, string address, int port,
			   function on_fail, int waiting);

class conn {
  string mudname;
  int auth;
}
