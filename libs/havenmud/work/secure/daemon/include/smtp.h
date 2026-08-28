/*
 * SMTP daemon header file
 *
 * Created by Zaxan@Haven
 *
 * 24-Feb-2006
 */

#ifndef H_DAEMON_SMTP
#define H_DAEMON_SMTP

// Different states
#define SMTP_STATE_NOTSENT      1
#define SMTP_STATE_HELO         2
#define SMTP_STATE_MAILFROM     3
#define SMTP_STATE_RCPTTO       4
#define SMTP_STATE_DATA         5
#define SMTP_STATE_SENDING      6
#define SMTP_STATE_FINISHED     7

class EmailMessage {
  int State;
  int CanWrite;
  string ToList;
  string *Recipients;
  string Subject;
  string Body;
};

mapping GetMessageQueue();
int eventCreateOutgoingMessage(string *recipients, string txt...);
private nomask void eventSendOutgoingMessage(class EmailMessage Message);

private nomask int check_security();
private nomask string print_previous_objects();

private nomask string fix_body(string input_body);

private nomask void eventSocketError(class EmailMessage msg, string str, int x);
private nomask void eventReportEmailError(class EmailMessage msg, string reason);
private nomask void eventReportEmailSuccess(class EmailMessage msg);

private nomask void eventWriteData(int fd, string data);
void eventReadData(int fd, string data);
void eventCanWriteData(int fd);
void eventCloseSocket(int fd);

private nomask void eventProcessInitialResponse(int fd, string response);
private nomask void eventProcessHELOResponse(int fd, string response);
private nomask void eventProcessMAILFROMResponse(int fd, string response);
private nomask void eventProcessRCPTTOResponse(int fd, string response);
private nomask void eventProcessDATAResponse(int fd, string response);
private nomask void eventProcessDataSentResponse(int fd, string response);
private nomask void eventProcessQUITResponse(int fd, string response);

private nomask void eventSendHELOCommand(int fd);
private nomask void eventSendMAILFROMCommand(int fd);
private nomask void eventSendRCPTTOCommand(int fd);
private nomask void eventSendDATACommand(int fd);
private nomask void eventSendDataContents(int fd);
private nomask void eventSendQUITCommand(int fd);

#endif // H_DAEMON_SMTP
