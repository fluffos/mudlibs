/**
 * A library for objects to use which wish to communicate with the game's
 * external request portal, Rodney. All communication with Rodney is
 * asynchronous, and state will be maintained across request and responses
 * with the global variables in this lib. It you wish to share the same
 * TCP connection across different inheriting objects, you may inherit this
 * library virtually. This library also includes functions that are applied
 * externally by the ERQ, so they must not be inherited privately.
 *
 * @alias RodneyClientLib
 */
#pragma no_clone
#include <sys/erq.h>
#include <sys/tls.h>
#include <sys/config.h>
#include <rodney_client.h>

#ifdef EOTL
#include <acme.h>
#define LoggerFactory AcmeLoggerFactory
#endif

#ifdef EOTL
private variables private functions inherit "json";
#else
private inherit JSONLib;
#endif

// TODO better error recovery

protected void open();
void open_callback(int *data, int size);
protected void send(string str);
void flush_queue();
void send_callback(int *data, int size);
private string get_transaction_id();
private void handle_response(string msg);
protected void rodney_query(string query, closure callback, mixed *args);

private int *erq_ticket, sending;
private int in_size;
private string incoming, in_md5, erq_ticket_str;
private mixed *queue, *last_transaction_id;
private mapping callbacks;

/**
 * Initialize state variables for processing messages and sending queries.
 */
void create() {
  queue = ({ });
  sending = 0;
  incoming = 0;
  last_transaction_id = ({ 0, 0, 0 });
  callbacks = ([ ]);
#ifdef EOTL
  seteuid(getuid());
#endif
}

/**
 * Asynchronously open a new connection to Rodney.
 */
protected void open() {
  send_erq(ERQ_OPEN_TCP,
           HOST + ({ PORT / 0x100, PORT & 0xFF }),
           #'open_callback); // '
  return;
}

/**
 * Called open a successful open(), or when new messages are received from
 * the server. On opens, it will attempt to flush the queue. On new messages,
 * the response will be deserialized and dispatched to the proper transaction
 * callback.
 *
 * @param data incoming data
 * @param size length of incoming packet
 */
void open_callback(int *data, int size) {
  // only the ERQ should be calling us
  if (previous_object()) {
    return;
  }

  object logger = LoggerFactory->get_logger(THISO);
  logger->trace("got open callback: %d, %O", size, data);

  if (sizeof(data) != size) {
    logger->error("packet failed size check: %d/%d", sizeof(data), size);
  }
  if (size >= 2) {
    switch (data[0]) {
      case ERQ_OK:
        erq_ticket = data[1..];
        erq_ticket_str = to_string(erq_ticket);
        logger->debug("open succeeded, got ticket: %O", erq_ticket_str);
        // TODO sanity check queue
        flush_queue();
        break;
      case ERQ_STDOUT:
        // read size and checksum and create a new buffer
        if (!incoming) {
          incoming = "";
          in_size = 0;
          in_size += (data[1] & 0xFF) * 0x1000000;
          in_size += (data[2] & 0xFF) * 0x10000;
          in_size += (data[3] & 0xFF) * 0x100;
          in_size += (data[4] & 0xFF);
          in_md5 = to_string(data[(SIZE_WIDTH + 1)..
                                  (SIZE_WIDTH + MD5_WIDTH)]);
          incoming += to_string(data[(SIZE_WIDTH + MD5_WIDTH + 1)..]);
        } else {
          incoming += to_string(data[1..]);
        }

        // TODO log a warning if extra data comes in
        if (strlen(incoming) >= in_size) {
          logger->debug("got message: %O", incoming);
#ifdef EOTL
          string md5 = md5(incoming);
#else
          string md5 = hash(TLS_HASH_MD5, incoming);
#endif
          if (in_md5 != md5) {
            logger->info("msg checksums differ: %O %O",
                         in_md5, md5, incoming);
          } else {
            string msg = incoming;
            // ensure incoming gets reset even if response handler evals out
            incoming = 0;
            handle_response(msg);
          }
        }
        break;
      case ERQ_E_ARGLENGTH:
      case ERQ_E_NSLOTS:
      case ERQ_E_UNKNOWN:
      default:
        logger->debug("open failed: %O, %O", data[0], data[1]);
        break;
    }
  }
  return;
}

/**
 * Asynchronously send a new query to Rodney. This will automatically attempt
 * to flush the request queue.
 *
 * @param query the query to send, which should usually be in the form of
 *              serialized JSON and include a transaction id
 */
protected void send(string query) {
  // TODO add overflow check
#ifdef EOTL
  queue += ({ ({ strlen(query), md5(query), query, -1, 0 }) });
#else
  queue += ({ ({ strlen(query), hash(TLS_HASH_MD5, query), query, -1, 0 }) });
#endif
  flush_queue();
  return;
}

/**
 * Attempt to flush the queue. Only one request will be sent at a time,
 * the send callback must be invoked before the next message will be sent.
 * This function will set the value of the <code>sending</code> variable to
 * the length of the message currently being sent, but the cursor won't move
 * until the callback is invoked.
 */
void flush_queue() {
  object logger = LoggerFactory->get_logger(THISO);
  if (find_call_out("flush_queue") != -1) {
    logger->debug("unable to flush buffer, flush call_out pending");
    return;
  }

  if (!erq_ticket) {
    logger->info("unable to flush buffer, no erq_ticket");
    return;
  }

  if (sending) {
    logger->debug("unable to flush buffer, awaiting ERQ_SEND response");
  }

  if (!sizeof(queue)) {
    return;
  }

  int *data = ({ });
  mixed *out = queue[0];
  int cursor = out[OUT_CURSOR];
  if (cursor < 0) {
    // new message, send size and checksum
    data += ({ (out[OUT_SIZE] & 0xFFFFFFFF) / 0x1000000,
               (out[OUT_SIZE] & 0xFFFFFF) / 0x10000,
               (out[OUT_SIZE] & 0xFFFF) / 0x100,
               (out[OUT_SIZE] & 0xFF)
            });
    data += to_array(out[OUT_MD5])[0..(MD5_WIDTH - 1)];
    sending = ERQ_MAX_SEND - sizeof(erq_ticket) - SIZE_WIDTH - MD5_WIDTH;
  } else {
    sending = ERQ_MAX_SEND - sizeof(erq_ticket);
  }

  int len = strlen(out[OUT_BUFFER]);
  if ((cursor + sending) > len) {
    sending = len - cursor;
  }
  data += to_array(out[OUT_BUFFER][(cursor + 1)..(cursor + sending)]);
  logger->trace("sending ticket: %O, data: %O", erq_ticket_str, data);
  send_erq(ERQ_SEND, erq_ticket + data, #'send_callback); //'
  return;
}

/**
 * Called open a successful send(). Upon success, it will attempt to the
 * flush the next message in the queue.
 *
 * @param data incoming data
 * @param size length of incoming packet
 */
void send_callback(int *data, int size) {
  // only the ERQ should be calling us
  if (previous_object()) {
    return;
  }

  object logger = LoggerFactory->get_logger(THISO);
  logger->trace("got send callback: %d, %O", size, data);
  if (sizeof(data) != size) {
    logger->error("packet failed size check: %d/%d", sizeof(data), size);
  }
  if (!sizeof(queue)) {
    logger->info("queue vanished while awaiting response");
    return;
  }

  mixed *out = queue[0];
  switch (data[0]) {
    case ERQ_OK:
      out[OUT_CURSOR] += sending;
      break;
    case ERQ_E_WOULDBLOCK:
      sending = 0; // resend
      logger->debug("got E_WOULDBLOCK, resending data");
      call_out("flush_queue", 1);
      return;
    case ERQ_E_INCOMPLETE:
      out[OUT_CURSOR] += data[1];
      break;
    case ERQ_E_TICKET:
      out[OUT_CURSOR] = -1;
      logger->debug("ticket invalid: %O, reset cursor and opening new socket",
                    erq_ticket_str);
      open();
      return;
    case ERQ_E_PIPE:
    case ERQ_E_UNKNOWN:
    default:
      logger->debug("send failed: %O, %O", data[0], data[1]);
      break;
  }
  sending = 0;
  if (out[OUT_CURSOR] >= (out[OUT_SIZE] - 1)) {
    logger->debug("finished sending message, length: %d", out[OUT_SIZE]);
    queue = queue[1..];
  }
  flush_queue();
  return;
}

/**
 * Send Rodney at query. This will initiate a single transaction that may
 * span several request and response loops. When the entire transaction is
 * complete, the reponse will be passed to the provided callback.
 *
 * @param query    the query to send
 * @param callback callback closure to pass response
 * @param args     optional extra args to the callback
 */
protected void rodney_query(string query, closure callback, mixed *args) {
  string transaction_id = get_transaction_id();
  mapping req = ([
    "transactionId" : transaction_id,
            "query" : query,
  ]);
  callbacks[transaction_id] = ({ callback, args });
  if (!erq_ticket) {
    open();
  }
  send(json_encode(req));
  return;
}

/**
 * Get a new unique transaction id.
 *
 * @return the transaction id
 */
private string get_transaction_id() {
  int *utime = utime();
  if ((utime[0] != last_transaction_id[0])
      || (utime[1] != last_transaction_id[1])) {
    last_transaction_id = utime + ({ 0 });
  } else {
    last_transaction_id[2]++;
  }
  return sprintf("%d.%d.%d",
                 last_transaction_id[0],
                 last_transaction_id[1],
                 last_transaction_id[2]
                );
}

/**
 * Handle reponse when a transaction has completed in its entirety. This
 * will execute the callback that was provided when the transaction was
 * created.
 *
 * @param msg the message received, which should be a serialized JSON object
 *            including a transaction id
 */
private void handle_response(string msg) {
  mixed resp = json_decode(msg);
  string transaction_id = resp["transactionId"];
  mixed *callback = callbacks[transaction_id];
  m_delete(callbacks, transaction_id);
  apply(callback[0], resp["body"], callback[1]);
  return;
}
